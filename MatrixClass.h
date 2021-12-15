#pragma once
#include <iostream>
#include "Randomer.h"
#include <Windows.h>

class Matrix
{
private:
	int cols = 0, rows = 0;
	std::vector<float> arr;
	float sum = 0;

	int* storageRows = 0, * storageCols = 0;
	float** MatrixArray2;
	bool alreadyWas = false;



public:


	template<class T>   // prototyp sablony
	Matrix(T rows1, T cols1)
	{
		rows = rows1;
		cols = cols1;
		MatrixArray2 = new float* [rows];

		// for loop nacte hodnoty na zacatku na hodnotu 0 
		for (auto i = 0; i < rows; ++i) {
			MatrixArray2[i] = new float[cols];
		}

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] = 0;
			}
		}

		alreadyWas = true;

	}

	Matrix()
	{

	}

	~Matrix()
	{

	}

	void setRandomValue(float min, float max)
	{
		// funkce ktera po zavolani nastavi konkretni matici na nahodnou hodnotu
		if (alreadyWas == true)
		{
			//std::cout << "random hodnoty!!" << std::endl;
			Randomer random{ min, max }; // random funkce ktera podle zadanych definic vybira nahodne hodnoty

			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j) {
					MatrixArray2[i][j] = random();
					//	std::cout << MatrixArray2[i][j] << std::endl;
				}
			}

		}

		else {
			//std::cout << "nemuzete nahodne definovat neexistujici matici!!" << std::endl;
		}
	}

	template<class T>
	void addWithSingleNumber(T allPlusNumber)
	{
		//	std::cout << "scitani jednim celim cislem!!: " << std::endl;
		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] += allPlusNumber;

			}
		} // tato funkce secte kazdy prvek v matici jednim stejnym cislem
		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				//		std::cout << MatrixArray2[i][j] << std::endl;

			}
			//	std::cout << std::endl;
		}
		// a pak vse vypise do konzole
	}

	template<class T>
	void addTwoMatrix(T matrix1)
	{
		/*
		if (alreadyWas != true)
		{
			rows = matrix1.rows;
			cols = matrix1.cols;
			MatrixArray2 = new float* [rows];

			// for loop nacte hodnoty na zacatku na hodnotu 0
			for (auto i = 0; i < rows; ++i) {
				MatrixArray2[i] = new float[cols];
			}

			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j) {

				//	MatrixArray2[i][j] = 0;

					if (i == rows - 1 && j == cols - 1)
						alreadyWas = true;
				}
			}

		}*/
		// tato funkce secte cele dve matice pomoci jednoho for loopu
		if (rows == matrix1.rows && cols == matrix1.cols) {

			// podminky ktere rozhoduji jestli jsou radky stejne
			// protoze pri scitani dvou matic musi byt obe stejne velke
		//	std::cout << "scitani matic!!: " << std::endl;
			for (auto i = 0; i < matrix1.rows; ++i) {
				for (auto j = 0; j < matrix1.cols; ++j) {
					MatrixArray2[i][j] = matrix1.MatrixArray2[i][j] + MatrixArray2[i][j];
				}
			}

			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j) {
					//		std::cout << MatrixArray2[i][j] << " ";

				}
				//	std::cout << std::endl;
			}
		}  // vypis do konzoje 
		else {
			std::cout << "Neni mozno scitat matici o ruznych rozmerech!! " << std::endl;
		}
	}

	template<class T>
	void multiplyWithSingleNumber(T allPlusNumber)
	{
		// tato funkce vynasobi kazde prvek v matici celim cislem
	//	std::cout << "nasobeni celim cislem!!: " << std::endl;
		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] *= allPlusNumber;

			}
		}

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				//		std::cout << MatrixArray2[i][j] << " ";

			}
			//	std::cout << std::endl;

		}
		// a zase vypise do konzole
	}

	template<class T>
	void multiplyTwoMatrix(T matrix1, T matrix2)
	{

		if (alreadyWas != true)
		{
			rows = matrix1.rows;
			cols = matrix2.cols;

			MatrixArray2 = new float* [rows];

			// for loop nacte hodnoty na zacatku na hodnotu 0 
			for (auto i = 0; i < rows; ++i) {
				MatrixArray2[i] = new float[cols];
			}

			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j) {

					MatrixArray2[i][j] = 0;

					if (i == rows - 1 && j == cols - 1) {
						alreadyWas = true;
					}
				}
			}

		}



		if (matrix1.cols == matrix2.rows) {

			//std::cout << "Nasobeni matic: " << std::endl;

			for (auto i = 0; i < matrix1.rows; ++i) {
				for (auto j = 0; j < matrix2.cols; ++j) {
					float sum = 0;
					for (auto k = 0; k < matrix1.cols; ++k)
					{
						sum += matrix1.MatrixArray2[i][k] * matrix2.MatrixArray2[k][j];
						//			std::cout << matrix1.MatrixArray2[i][k] << "  a  " << matrix2.MatrixArray2[k][j] << std::endl;
					}
					MatrixArray2[i][j] = sum;
				}
				//	std::cout << std::endl;
			}
			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j)
				{
					//			std::cout << MatrixArray2[i][j] << " ";

				}
				//	std::cout << std::endl;
			}


		}
		else {
			std::cout << "pri nasobeni matice matici se musi pocet radku prvni matice rovnat poctu sloupcu druhe matice!! " << std::endl;
		}

	}

	template<class T>
	void multiplyTwoMatrixWithOneOther(T matrix)
	{
		if (rows == matrix.rows && cols == matrix.cols) {
			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j) {
					MatrixArray2[i][j] *= matrix.MatrixArray2[i][j];
				}
			}

		}
	}
	void showValues()
	{
		//	std::cout << "Hodnoty matice: " << std::endl;
		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				//		std::cout << MatrixArray2[i][j] << "   ";
			}
			//	std::cout << std::endl;
		}
	}

	template<class T>
	void transpose(T matrixForTranspose)
	{

		cols = matrixForTranspose.rows;
		rows = matrixForTranspose.cols;   // 2x1

		//if (alreadyWas != true) {

		MatrixArray2 = new float* [rows];

		for (auto i = 0; i < rows; ++i) {
			MatrixArray2[i] = new float[cols];
		}

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] = 0;
			}
		}
		//}
		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] = matrixForTranspose.MatrixArray2[j][i];
			}
		}

		//	std::cout << "Transpose funkce: " << std::endl;

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				//		std::cout << "z puvodni matice: ";

				//		std::cout << matrixForTranspose.MatrixArray2[j][i] << " ";
			}
			//	std::cout << std::endl;
		}

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				//	std::cout << "na pretvorenou: ";

				//	std::cout << MatrixArray2[i][j] << " ";
			}
			//std::cout << std::endl;
		}

	}

	template<class T>
	void fromArray(std::vector<float> array1, T inSize)
	{
		if (alreadyWas != true)
		{
			rows = inSize;
			cols = 1;
			MatrixArray2 = new float* [rows];

			// for loop nacte hodnoty na zacatku na hodnotu 0 
			for (auto i = 0; i < rows; ++i) {
				MatrixArray2[i] = new float[cols];
			}

			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j) {

					MatrixArray2[i][j] = 0;

					if (i == rows - 1 && j == cols - 1)
						alreadyWas = true;

				}
			}

		}

		for (auto i = 0; i < inSize; ++i)
		{
			MatrixArray2[i][0] = array1[i];
		}
		//std::cout << "function 'fromArray': " << std::endl;
		for (auto i = 0; i < inSize; ++i)  // sizeof(arr)/sizeof(arr[0]);
		{
			//	std::cout << MatrixArray2[i][0] <<  std::endl;
		}
	}


	std::vector<float> toArray()
	{

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				arr.push_back(MatrixArray2[i][j]);
			}
		}
		return arr;

	}


	template<class T >
	void map(T activationFunction)
	{

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				float val = MatrixArray2[i][j];
				//	std::cout << "val is: " << val << std::endl;
				MatrixArray2[i][j] = activationFunction(val);
				//	std::cout << "sum is: " << MatrixArray2[i][j] << std::endl;
			}
		}
	}

	template<class T>
	void map(Matrix mat1, T activationFunction)
	{
		if (alreadyWas != true)
		{
			rows = mat1.rows;
			cols = mat1.cols;

			MatrixArray2 = new float* [rows];

			// for loop nacte hodnoty na zacatku na hodnotu 0 
			for (auto i = 0; i < rows; ++i) {
				MatrixArray2[i] = new float[cols];
			}

			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j) {

					//	MatrixArray2[i][j] = 0;

					if (i == rows - 1 && j == cols - 1) {
						alreadyWas = true;
					}
				}
			}

		}

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				float val = mat1.MatrixArray2[i][j];
				MatrixArray2[i][j] = activationFunction(val);
			}
		}
		//return sum;
	}


	template<class T>
	void subtract(T firstMatrix, T secondMatrix)
	{
		if (firstMatrix.rows == secondMatrix.rows && firstMatrix.cols == secondMatrix.cols) {
			rows = firstMatrix.rows;
			cols = firstMatrix.cols;

			if (alreadyWas != true)
			{



				MatrixArray2 = new float* [rows];

				// for loop nacte hodnoty na zacatku na hodnotu 0 
				for (auto i = 0; i < rows; ++i) {
					MatrixArray2[i] = new float[cols];
				}

				for (auto i = 0; i < rows; ++i) {
					for (auto j = 0; j < cols; ++j) {

						MatrixArray2[i][j] = 0;

						if (i == rows - 1 && j == cols - 1)
							alreadyWas = true;
					}
				}

			}
			// tato funkce odecte cele dve matice pomoci jednoho for loopu

				// podminky ktere rozhoduji jestli jsou radky stejne
				// protoze pri scitani dvou matic musi byt obe stejne velke
				//std::cout << "odcitani matic!!: " << std::endl;
			for (auto i = 0; i < firstMatrix.rows; ++i) {
				for (auto j = 0; j < secondMatrix.cols; ++j) {
					MatrixArray2[i][j] = firstMatrix.MatrixArray2[i][j] - secondMatrix.MatrixArray2[i][j];
				}
			}

			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j) {
					//		std::cout << MatrixArray2[i][j] << " ";

				}
				//	std::cout << std::endl;
			}

		}

		else {
			//std::cout << "neni stejny pocet radku a sloupcu obu matic!!!" << std::endl;
		}

	}
};
