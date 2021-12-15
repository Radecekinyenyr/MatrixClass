#pragma once

#include <iostream>
#include "MatrixLibrary.h"
#include <math.h>

/////////////////////////////////////////////////////////////////////////////////////////
///                                  Radek Zach                                       ///
/////////////////////////////////////////////////////////////////////////////////////////


template<typename Base, typename T>
inline bool instanceof(const T*) {
	return std::is_base_of<Base, T>::value;
}

float sigmoidFunction(float x)
{
	return 1 / (1 + exp(-x));
}

float dSigmoidFunction(float y)
{
	return y * (1 - y);
}

float hyperbolicTanhgens(float x)
{
	return tanh(x);
}

float dHyperbolicTanhgens(float y)
{
	return 1 - (y * y);
}

class NeuralNetwork
{
private:
	int numberOfImputLayer;
	int numberOfHiddenLayer;
	int numberOfOutputLayer;

	using ActivationFunction = float(*)(float);
	ActivationFunction func;

	using ActivationFunction = float(*)(float);
	ActivationFunction dFunc;

	float learningRate = 0.1;
	Matrix* weights_ih;
	Matrix* weights_ho;
	Matrix* bias_h;
	Matrix* bias_o;
	

public:

	template<class T>
	NeuralNetwork(T nOfI, T nOfH, T nOfO)
	{
		numberOfImputLayer = nOfI;
		numberOfHiddenLayer = nOfH;
		numberOfOutputLayer = nOfO;

		weights_ih = new Matrix(numberOfHiddenLayer, numberOfImputLayer); // 2x2
		weights_ho = new Matrix(numberOfOutputLayer, numberOfHiddenLayer);
		bias_h = new Matrix(numberOfHiddenLayer, 1);
		bias_o = new Matrix(numberOfOutputLayer, 1);

		bias_h->setRandomValue(-1, 1);
		bias_o->setRandomValue(-1, 1);
		weights_ih->setRandomValue(-1, 1);
		weights_ho->setRandomValue(-1, 1);
	}

	void setLearningRate(float x = 0.1)
	{
		learningRate = x;
	}

	template<class T>
	void setActivationFunction(T function, T dFunction)
	{
		if (function == sigmoidFunction && dFunction == dSigmoidFunction) {
			func = sigmoidFunction;
			dFunc = dSigmoidFunction;
		}

		else if (function == hyperbolicTanhgens && dFunction == dHyperbolicTanhgens) {
			func = hyperbolicTanhgens;
			dFunc = dHyperbolicTanhgens;
		}

	}


	std::vector<float> feedForward(std::vector<float> inputs, int inSize)
	{

		Matrix hidden;
		Matrix inputsMatrix;
		inputsMatrix.fromArray(inputs, inSize);  //2x1
		hidden.multiplyTwoMatrix(*weights_ih, inputsMatrix); //2x2, 2x1 
		hidden.addTwoMatrix(*bias_h);
		hidden.map(func);


		Matrix output;
		output.multiplyTwoMatrix(*weights_ho, hidden);
		output.addTwoMatrix(*bias_o);
		output.map(func);
		return output.toArray();


	}

	void train(std::vector<float> inputs, int inSize, std::vector<float> targets, int inSize2)
	{

		Matrix hidden;
		Matrix inputsMatrix;
		inputsMatrix.fromArray(inputs, inSize);  //2x1
		hidden.multiplyTwoMatrix(*weights_ih, inputsMatrix); //2x2, 2x1 
		hidden.addTwoMatrix(*bias_h);
		hidden.map(func);

		Matrix output;
		output.multiplyTwoMatrix(*weights_ho, hidden);//2x1
		output.addTwoMatrix(*bias_o);
		output.map(func);

		Matrix target;
		target.fromArray(targets, inSize2);
		Matrix error;
		error.subtract(target, output);

		Matrix output_gradient;
		output_gradient.map(output, dFunc);

		output_gradient.multiplyTwoMatrixWithOneOther(error);
		output_gradient.multiplyWithSingleNumber(learningRate);

		Matrix hidden_for_transpose;
		hidden_for_transpose.transpose(hidden);

		Matrix delta_weights_ho;
		delta_weights_ho.multiplyTwoMatrix(output_gradient, hidden_for_transpose);
		weights_ho->addTwoMatrix(delta_weights_ho);
		bias_o->addTwoMatrix(output_gradient);

		// pricte k vaham vypocitany rozdil vah
		Matrix weights_ho_for_transpose;
		weights_ho_for_transpose.transpose(*weights_ho);
		Matrix hidden_errors;
		hidden_errors.multiplyTwoMatrix(weights_ho_for_transpose, error); // vynasobi vahy s chybou 

		// vypocita gradient
		Matrix hidden_gradient;
		hidden_gradient.map(hidden, dFunc);  // projede hodnoty aktivacni funkci
		hidden_gradient.multiplyTwoMatrixWithOneOther(hidden_errors);
		// vynasobi obe matice
		hidden_gradient.multiplyWithSingleNumber(learningRate); // pricte konstantni hodnotu jako rozdil zmeny vah

		Matrix inputs_for_transpose;

		inputs_for_transpose.transpose(inputsMatrix);
		Matrix delta_weights_ih;
		delta_weights_ih.multiplyTwoMatrix(hidden_gradient, inputs_for_transpose);
		weights_ih->addTwoMatrix(delta_weights_ih);
		bias_h->addTwoMatrix(hidden_gradient);


	}

	template<class T> 
	void mutate(T func)
	{
		weights_ih->map(func);
		weights_ho->map(func);
		bias_h->map(func);
		bias_o->map(func);
	}
};
