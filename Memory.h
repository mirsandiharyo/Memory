/*
 * Memory.h
 *
 *  Created on: Jun 16, 2020
 *      Author: mirsandiharyo
 */

#ifndef MEMORY_H_
#define MEMORY_H_

int     *int_1D_array(long int m);
int     **int_2D_array(long int m, long int n);
int     ***int_3D_array(long int m, long int n, long int o);
int     ****int_4D_array(long int m, long int n, long int o, long int p);
double	*double_1D_array(long int m);
double	**double_2D_array(long int m, long int n);
double	***double_3D_array(long int m, long int n, long int o);
double 	****double_4D_array(long int m, long int n, long int o, long int p);
void    free_1D_array(void *array);
void    free_2D_array(void **array);
void    free_3D_array(void ***array);
void    free_4D_array(void ****array);

#endif /* MEMORY_H_ */
