#pragma once

#include <iostream>
#include "Randomer.h"


class Matrix
{
private: 
	int cols = 0, rows = 0;
	Randomer random{ 0, 9 }; // random funkce ktera podle zadanych definic vybira nahodne hodnoty
	
	int* storageRows = 0, *storageCols = 0;
	int** MatrixArray2;
	

public:
	
	template<class T>   // prototyp sablony
	Matrix(T rows1, T cols1)
	{
		rows = rows1;
		cols = cols1;
		MatrixArray2 = new int* [rows];
		
		// for loop nacte hodnoty na zacatku na hodnotu 0 
		for (auto i = 0; i < rows; ++i) {
			MatrixArray2[i] = new int[cols];
		}

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] = 0;
			}
		}

	
	}
	~Matrix()
	{

	}
	void setRandomValue()
	{ 
		// funkce ktera po zavolani nastavi konkretni matici na nahodnou hodnotu
		std::cout << "random hodnoty!!" << std::endl;
		
		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] = random();
				std::cout << MatrixArray2[i][j] << std::endl;
			}
		}
	}

	template<class T>
	void addWithSingleNumber(T allPlusNumber)
	{
		std::cout << "scitani jednim celim cislem!!: " << std::endl;
		for (auto i = 0; i < rows; ++i)  {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] += allPlusNumber;

			}
		} // tato funkce secte kazdy prvek v matici jednim stejnym cislem
		for (auto i = 0; i < rows; ++i)  {
			for (auto j = 0; j < cols; ++j) {
				std::cout << MatrixArray2[i][j] << std::endl;

			}
			std::cout << std::endl;
		}
		// a pak vse vypise do konzole
	}

	template<class T>
	void addTwoMatrix(T matrix1, T matrix2)
	{
		// tato funkce secte cele dve matice pomoci jednoho for loopu
		if (matrix2.rows == matrix1.rows && matrix2.cols == matrix1.cols) {

			// podminky ktere rozhoduji jestli jsou radky stejne
			// protoze pri scitani dvou matic musi byt obe stejne velke
			std::cout << "scitani matic!!: " << std::endl;
			for (auto i = 0; i < matrix1.rows; ++i) {
				for (auto j = 0; j < matrix1.cols; ++j) {
					MatrixArray2[i][j] = matrix1.MatrixArray2[i][j] + matrix2.MatrixArray2[i][j];
			    }
			}

			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j) {
					std::cout << MatrixArray2[i][j] << " ";

				}
				std::cout << std::endl;
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
		std::cout << "nasobeni celim cislem!!: " << std::endl;
		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] *= allPlusNumber;

			}
		}

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				std::cout << MatrixArray2[i][j] << " ";

			}
			std::cout << std::endl;

		}
		// a zase vypise do konzole
	}

	template<class T>
	void multiplyTwoMatrix(T matrix1, T matrix2)
	{
	
		
		if (matrix1.rows == matrix2.cols) {
			
			std::cout << "Nasobeni matic: " << std::endl;

			for (auto i = 0; i < matrix1.rows; ++i) {
				for (auto j = 0; j < matrix2.cols; ++j) {
					for (auto k = 0; k < matrix1.cols; ++k)
					{
						MatrixArray2[i][j] += matrix1.MatrixArray2[i][k] * matrix2.MatrixArray2[k][j];
					}
				}
			}
			for (auto i = 0; i < rows; ++i) {
				for (auto j = 0; j < cols; ++j)
				{			
					std::cout << MatrixArray2[i][j] << " ";
					
				}
				std::cout << std::endl;
			}

			for (auto i = 0; i < rows; ++i) {
				delete[] MatrixArray2[i];
			}
			delete[] MatrixArray2;
		}
		else {
			std::cout << "pri nasobeni matice matici se musi pocet radku prvni matice rovnat poctu sloupcu druhe matice!! " << std::endl;
		}
		
	}

	template<class T>
	void transpose(T matrixForTranspose)
	{
		
		cols = matrixForTranspose.rows;
	    rows = matrixForTranspose.cols;

		

		MatrixArray2 = new int* [rows];

		for (auto i = 0; i < rows; ++i) {
			MatrixArray2[i] = new int[cols];
		}

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] = 0;
			}
		}

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				MatrixArray2[i][j] = matrixForTranspose.MatrixArray2[j][i];
			}
		}

		for (auto i = 0; i < rows; ++i) {
			for (auto j = 0; j < cols; ++j) {
				std::cout << MatrixArray2[i][j] << " ";
			}
			std::cout << std::endl;
		}

	}
};
