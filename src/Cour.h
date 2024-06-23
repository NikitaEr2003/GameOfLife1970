#pragma once
#include <iostream>
#include <fstream>
int** CreateArray(int rows, int cols);
void EditFirstArray(int** arr, int rows, int cols);
bool ArraysEqual(int** arr1, int** arr2, int rows, int cols);
int PrintArray(int** arr, int rows, int cols);
void Copy(int** arr, int** arr1, int rows, int cols);
int** NextStep(int** arr, int rows, int cols, bool& answer);
void DeleteArray(int** arr, int rows, int cols);
inline int Get_X(int num, int parametr);