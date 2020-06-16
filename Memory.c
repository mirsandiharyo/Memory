/*
 * Memory.c
 *
 *  Created on: Jun 16, 2020
 *      Author: mirsandiharyo
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Memory.h"

/**
 * \brief Contains functions to declare and free memory for contiguously-allocated arrays
 */

/* \brief Create an 1D array with size [m] of type integer
 */
int *int_1D_array(long int m)
{
	int *array;
    array = (int *) calloc(m, sizeof(int));
    return array;
}

/* \brief Create a 2D array with size [m, n] of type integer
 */
int **int_2D_array(long int m, long int n)
{
	int **array;
	int i;
	long int x;
	x = m * n;
	array = (int**)calloc(m, sizeof(int *));    // allocate first dimension
	array[0] = (int*)calloc(x, sizeof(int));    // allocate contiguous memory block for all elements

	for(i = 0; i < m; ++i)
		array[i]  = array[0] + i * n;

	return array;
}

/* \brief Create a 3D array with size [m, n, o] of type integer
 */
int ***int_3D_array(long int m, long int n, long int o)
{
	int ***array;
	int i, j;
	long int x, y;
	x = m * n;
	y = x * o;
	array = (int***)calloc(m, sizeof(int **));	// allocate first dimension
	array[0] =  (int**)calloc(x, sizeof(int *));// allocate contiguous memory block for all elements
	array[0][0] = (int*)calloc(y, sizeof(int));


	for(j = 1; j < n; ++j){						// fill first row
		array[0][j] = array[0][j-1] + o;		// pointer to array[0][j][0], thus first element of array[0][j][o]
	}

	for(i = 1; i < m; ++i){
		array[i] = array[i-1] + n;				// pointer to position of  to array[i][0]
		array[i][0] = array[i-1][n-1] + o;		// pointer to  array[i][j][0];
		for(j = 1; j < n; ++j){
			array[i][j] = array[i][j-1] + o;
		}
	}
	return array;
}

/* \brief Create a 4D array with size [m, n, o, p] of type integer
 */
int ****int_4D_array(long int m, long int n, long int o, long int p)
{
	int ****array;
	int i, j, k;
	long int x, y, z;
	x = m * n;
	y = x * o;
	z = y * p;
	array = (int****)calloc(m, sizeof(int ***));	// allocate first dimension
	array[0] = (int***)calloc(x, sizeof(int **));	// allocate contiguous memory block for all elements
	array[0][0] = (int**)calloc(y, sizeof(int *));
	array[0][0][0] = (int*)calloc(z, sizeof(int));

	for(k = 1; k < o; ++k)
		array[0][0][k] = array[0][0][k-1] + p;

	for(j = 1; j < n; ++j){
		array[0][j] = array[0][j-1] + o;
		array[0][j][0] = array[0][j-1][o-1]+p;
		for(k = 1; k < o; ++k)
			array[0][j][k] = array[0][j][k-1] + p;
	}

	for(i = 1; i < m; ++i){
		array[i] = array[i-1] + n;
		array[i][0] = array[i-1][n-1] + o;
		array[i][0][0] = array[i-1][n-1][o-1] + p;
		for(k = 1; k < o; ++k)
			array[i][0][k] = array[i][0][k-1] + p;
		for(j = 1; j < n; ++j){
			array[i][j] = array[i][j-1] + o;
			array[i][j][0] = array[i][j-1][o-1]+p;
			for(k = 1; k < o; ++k)
				array[i][j][k] = array[i][j][k-1] + p;
		}
	}
	return array;
}

/* \brief Create an 1D array with size [m] of type double
 */
double *double_1D_array(long int m)
{
	double *array;
    array = (double *) malloc(m * sizeof(double));
    return array;
}

/* \brief Create an 2D array with size [m, n] of type double
 */
double **double_2D_array(long int m, long int n)
{
	double **array;
	int i;
	long int x;
	x = m * n;
	array =  (double**)malloc(m * sizeof(double *));    // allocate first dimension
	array[0] =  (double*)malloc(x * sizeof(double));    // allocate contiguous memory block for all elements

	for(i = 0; i < m; ++i)
		array[i]  = array[0] + i * n;

	return array;
}

/* \brief Create a 3D array with size [m, n, o] of type double
 */
double ***double_3D_array(long int m, long int n, long int o)
{
	double ***array;
	int i, j;
	long int x, y;
	x = m * n;
	y = x * o;
	array =  (double***)calloc(m, sizeof(double **));	// allocate first dimension
	array[0] =  (double**)calloc(x, sizeof(double *));	// allocate contiguous memory block for all elements
	array[0][0] = (double*)calloc(y, sizeof(double));


	for(j = 1; j < n; ++j){								// fill first row
		array[0][j] = array[0][j-1] + o;				// pointer to array[0][j][0], thus first element of array[0][j][o]
	}

	for(i = 1; i < m; ++i){
		array[i] = array[i-1] + n;						// pointer to position of  to array[i][0]
		array[i][0] = array[i-1][n-1] + o;				// pointer to  array[i][j][0];
		for(j = 1; j < n; ++j){
			array[i][j] = array[i][j-1] + o;
		}
	}
	return array;
}

/* create a 4D array with size [m, n, o, p] of type double */
double  ****double_4D_array(long int m, long int n, long int o, long int p)
{
	double ****array;
	int i, j, k;
	long int x, y, z;
	x = m * n;
	y = x * o;
	z = y * p;
	array = (double****)calloc(m , sizeof(double ***));	// allocate first dimension
	array[0] = (double***)calloc(x, sizeof(double **));	// allocate contiguous memory block for all elements
	array[0][0] = (double**)calloc(y, sizeof(double *));
	array[0][0][0] = (double*)calloc(z, sizeof(double));

	for(k = 1; k < o; ++k)
		array[0][0][k] = array[0][0][k-1] + p;

	for(j = 1; j < n; ++j){
		array[0][j] = array[0][j-1] + o;
		array[0][j][0] = array[0][j-1][o-1]+p;
		for(k = 1; k < o; ++k)
			array[0][j][k] = array[0][j][k-1] + p;
	}

	for(i = 1; i < m; ++i){
		array[i] = array[i-1] + n;
		array[i][0] = array[i-1][n-1] + o;
		array[i][0][0] = array[i-1][n-1][o-1] + p;
		for(k = 1; k < o; ++k)
			array[i][0][k] = array[i][0][k-1] + p;

		for(j = 1; j < n; ++j){
			array[i][j] = array[i][j-1] + o;
			array[i][j][0] = array[i][j-1][o-1]+p;
			for(k = 1; k < o; ++k)
				array[i][j][k] = array[i][j][k-1] + p;
		}
	}
	return array;
}

void free_1D_array(void *array)
{
	free(array);
	array = NULL;
}

void free_2D_array(void **array)
{
	free(array[0]);
	free(array);
	array = NULL;
}

void free_3D_array(void ***array)
{
	free(array[0][0]);
	free(array[0]);
	free(array);
	array = NULL;
}

void free_4D_array(void ****array)
{
	free(array[0][0][0]);
	free(array[0][0]);
	free(array[0]);
	free(array);
	array = NULL;
}
