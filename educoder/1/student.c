#include <string.h>
#include <stdlib.h>
#include "student.h"
#include <stdio.h>

void intersection(int* A, int* B, int lenA, int lenB, int** C, int* lenC)
{
	/*
	
    A表示数组A，B表示数组B，lenA表示数组A的长度，lenB表示数组
	B的长度，C表示结果，lenC表示结果的长度
	需要将交集存放在数组C中。
	*/

	/*********Begin********/
	printf("!!!\n");
	int D[100000] = {0};
	for(int i = 0; i < lenA; i++)
		if(D[A[i]] == 0) D[A[i]]++;
	int length = 0;
	printf("!!!\n");
	for(int i = 0; i < lenB; i++)
		if(D[B[i]] == 1) length++;
	*C = (int*)malloc(sizeof(int) * length);
	*lenC = length;
	printf("%d\n", length);
	length = 0;
	for(int i = 0; i < lenB; i++)
		if(D[B[i]] == 1) 
			*C[length++] = B[i];
	/*********End*********/
}