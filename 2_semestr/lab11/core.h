#ifndef _MYINCL1_H
#define _MYINCL1_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h> 

void printMenu();
int getVariant(int count);

int CheckCondition();
void RowSum(int row1, int row2, float coeff, const int columnsCount);
void ShowMatrix(const int rows, const int columns, float matrix[rows][columns]);
void SimpleIterationMethod();
int CheckResult();
int IterrationMethod();

#endif // _MYINCL1_H
