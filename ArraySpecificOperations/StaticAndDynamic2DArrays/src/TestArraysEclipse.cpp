//============================================================================
// Name        : TestArraysEclipse.cpp
// Author      : Jasmin Jahic
// Version     :
// Copyright   : Feel free to use as you please, spread the word (STWO).
// Description : Hello World in C++, Ansi-style.
//				 Static vs dynamic multidimensional arrays.
//============================================================================

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand, malloc */


#define ARRAY_LENGTH 50
#define ARRAY_WIDTH 15

void allocateArray(int*** array);


// When array-to-pointer decay is applied, a multidimensional array is
// converted to a pointer to its first element (e.g., a pointer to its
// first row or to its first plane): array-to-pointer decay is applied only once.
// int b[2][3];         // array of 2 arrays of 3 int
// int** p2 = b;     // error: b does not decay to int**
// Sources:
// - https://en.cppreference.com/w/cpp/language/array#Array-to-pointer_decay
// - https://stackoverflow.com/questions/8203700/conversion-of-2d-array-to-pointer-to-pointer
void populateArrayD(int*** array);
void populateArrayS(int array[ARRAY_LENGTH][ARRAY_WIDTH]);

void printArray(int** array);
void printArray(int array[ARRAY_LENGTH][ARRAY_WIDTH]);

long sumArray(int** array);
long sumArray(int array[ARRAY_LENGTH][ARRAY_WIDTH]);

int main()
{
	int staticArray[ARRAY_LENGTH][ARRAY_WIDTH];
	int** dynamicArray;

	printf("Start.\n");

	printf("	- Dynamic...\n");
	allocateArray(&dynamicArray);
	printf("Array allocated.\n");

    printf("	- Dynamic...\n");
    populateArrayD(&dynamicArray);
    printf("	- Static...\n");
    populateArrayS(staticArray);
    printf("Array populated.\n");

    printf("	- Dynamic...\n");
    printArray(dynamicArray);
    printf("	- Static...\n");
    printArray(staticArray);
    printf("Array populated.\n");

    printf("Sum dynamic = %lu.\n", sumArray(dynamicArray));
    printf("Sum static = %lu.\n", sumArray(staticArray));

    // Free the memory, avoid memory leak.
    for(int i=0; i<ARRAY_LENGTH; i++)
    	free(dynamicArray[i]);

    free(dynamicArray);

    return 0;
}

void allocateArray(int*** array)
{
    // Allocate pointers for rows.
	*array  = (int**) malloc(ARRAY_LENGTH*sizeof(int*));

    for(int i=0; i< ARRAY_LENGTH;i++)
    {
		(*array)[i] = (int*) malloc(ARRAY_WIDTH*sizeof(int));

		/*int*** ptr3 =array;
		int** ptr2 =*array;
		int* ptr1 =**array;
		int ptr =***array;

		int** index3 =array[i];
		int* index2 =(*array)[i];
		int index1 =(*array)[i][0];

		printf("ptr2 = %p; ptr1 = %p; ptr = %d;\n",ptr2, ptr1, ptr);
		printf("index3 = %p; index2 = %p; index1 = %d;\n",index3, index2, index1);
		printf("\n");*/
    }
}

void populateArrayS(int array[ARRAY_LENGTH][ARRAY_WIDTH])
{
	for(int i=0; i< ARRAY_LENGTH;i++)
	{
		for(int j=0; j<ARRAY_WIDTH; j++)
		{
			if(i>10)
				array[i][j]=i%10;
			else
				array[i][j]=i;
		}
	}
}

void populateArrayD(int*** array)
{
	for(int i=0; i< ARRAY_LENGTH;i++)
	{
		for(int j=0; j<ARRAY_WIDTH; j++)
		{
			if(i>10)
				(*array)[i][j]=i%10;
			else
				(*array)[i][j]=i;
		}
	}
}

void printArray(int** array)
{
	for(int i=0; i< ARRAY_LENGTH;i++)
	{
		for(int j=0; j<ARRAY_WIDTH; j++)
		{
			printf("array[%d][%d]=%d.\n", i, j, array[i][j]);
		}
	}
}

void printArray(int array[ARRAY_LENGTH][ARRAY_WIDTH])
{
	for(int i=0; i< ARRAY_LENGTH;i++)
	{
		for(int j=0; j<ARRAY_WIDTH; j++)
		{
			printf("array[%d][%d]=%d.\n", i, j, array[i][j]);
		}
	}
}

long sumArray(int** array)
{
	long sum = 0;

	for(int i=0; i< ARRAY_LENGTH;i++)
	{
		for(int j=0; j<ARRAY_WIDTH; j++)
			sum = sum+array[i][j];
	}

    return sum;
}

long sumArray(int array[ARRAY_LENGTH][ARRAY_WIDTH])
{
	long sum = 0;

	for(int i=0; i< ARRAY_LENGTH;i++)
	{
		for(int j=0; j<ARRAY_WIDTH; j++)
			sum = sum+array[i][j];
	}

    return sum;
}
