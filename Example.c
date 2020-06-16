/*
 * Example.c
 *
 *  Created on: Jun 16, 2020
 *      Author: mirsandiharyo
 */

#include <stdio.h>
#include "Memory.h"

int main() {

	int *int_1d, **int_2d, ***int_3d;
	double *db_1d, **db_2d, ***db_3d;
	int col1, col2, col3, col4;
	col1 = 3;
	col2 = 4;
	col3 = 5;
	col4 = 6;

	/* One dimensional array */
	int_1d = int_1D_array(col1);
	db_1d = double_1D_array(col1);

	for(int i = 0; i < col1; ++i){
		int_1d[i] = i;
		db_1d[i] = i*2;
	}

	/* Check output */
	for(int i = 0; i < col1; ++i)
		printf("%d ", int_1d[i]);
	printf("\n");
	for(int i = 0; i < col1; ++i)
		printf("%f ", db_1d[i]);
	printf("\n");

	/* Deallocate */
	free_1D_array  ((void *)int_1d);
	free_1D_array  ((void *)db_1d);

	/* Two dimensional array */
	int_2d = int_2D_array(col1, col2);
	db_2d = double_2D_array(col1, col2);

	for(int i = 0; i < col1; ++i){
		for(int j = 0; j < col2; ++j){
			int_2d[i][j] = i+j;
			db_2d[i][j] = (i+j)*2;
		}
	}

	/* Check output */
	for(int i = 0; i < col1; ++i){
		for(int j = 0; j < col2; ++j){
			printf("%d ", int_2d[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(int i = 0; i < col1; ++i){
		for(int j = 0; j < col2; ++j){
			printf("%f ", db_2d[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	/* Deallocate */
	free_2D_array ((void **)int_2d);
	free_2D_array ((void **)db_2d);

	/* Three dimensional array */
	int_3d = int_3D_array(col1, col2, col3);
	db_3d = double_3D_array(col1, col2, col3);

	for(int i = 0; i < col1; ++i){
		for(int j = 0; j < col2; ++j){
			for(int k = 0; k < col3; ++k){
				int_3d[i][j][k] = i+j+k;
				db_3d[i][j][k] = (i+j+k)*2;
			}
		}
	}

	/* Check output */
	for(int i = 0; i < col1; ++i){
		for(int j = 0; j < col2; ++j){
			for(int k = 0; k < col3; ++k){
				printf("%d ", int_3d[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");

	for(int i = 0; i < col1; ++i){
		for(int j = 0; j < col2; ++j){
			for(int k = 0; k < col3; ++k){
				printf("%f ", db_3d[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");

	/* Deallocate */
	free_3D_array ((void ***)int_3d);
	free_3D_array ((void ***)db_3d);

	return 0;
}
