#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"student.h"

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
			(*C)[length++] = B[i];
	/*********End*********/
}

int main()
{
	int len_A = 0;
	scanf("%d", &len_A);
	int* A = (int*)malloc(len_A*sizeof(int));
	for(int i = 0; i < len_A; ++i)
	{
		int temp;
		scanf("%d", &temp);
		A[i] = temp;
	}
	int len_B = 0;
	scanf("%d", &len_B);
	int* B = (int*)malloc(len_B*sizeof(int));
	for(int i = 0; i < len_B; ++i)
	{
		int temp;
		scanf("%d", &temp);
		B[i] = temp;
	}
	int* result = NULL;
	int len_C = 0;
	intersection(A, B, len_A, len_B, &result, &len_C); 

	//排序
	for(int i = 0; i < len_C; ++i)
		for(int j = i+1; j < len_C; ++j)
			if(result[i] < result[j])
			{
				int tmp = result[i];
				result[i] = result[j];
				result[j] = tmp;
			}

	for(int i = 0; i < len_C; ++i)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
}