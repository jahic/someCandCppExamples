//============================================================================
// Name        : LoopIntensiveOperationsInC.c
// Author      : Jasmin Jahic
// Version     :
// Copyright   : Feel free to use as you please, spread the word (STWO).
// Description : Loops with computing intensive operations.
//				 C.
//============================================================================

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand, malloc */
#include "computationKernels.h"

int main(int argc, char **argv)
{
	printf("Start.\n");

	// Polybench, cholesky
	computationKernelPolybenchCholesky();
	printf("	- computationKernelPolybenchCholesky...COMPLETE.\n");
	computationKernelPolybenchCholeskyD();
	printf("	- computationKernelPolybenchCholeskyD...COMPLETE.\n");

	// Polybench, lu
	computationKernelPolybenchLu();
	printf("	- computationKernelPolybenchLu...COMPLETE.\n");

	// Polybench, 2mm
	computationKernelPolybench2mm();
	printf("	- computationKernelPolybench2mm...COMPLETE.\n");

	// Polybench, 3mm
	computationKernelPolybench3mm();
	printf("	- computationKernelPolybench3mm...COMPLETE.\n");

	// Polybench, doitgen
	computationKernelPolybenchDoitgen();
	printf("	- computationKernelPolybenchDoitgen...COMPLETE.\n");

	// Polybench, gramschmidt
	computationKernelPolybenchGramschmidt();
	printf("	- computationKernelPolybenchGramschmidt---COMPLETE.\n");
	computationKernelPolybenchGramschmidtD();
	printf("	- computationKernelPolybenchGramschmidtD---COMPLETE.\n");

	// Polybench, tislov
	computationKernelPolybenchTislov();
	printf("	- computationKernelPolybenchTislov---COMPLETE.\n");
/*
	// Generic 1D loop, 2 arrays.
	computationKernelGenericLoop1D2A();
	printf("	- computationKernelGenericLoop1D2A---COMPLETE.\n");
	computationKernelGenericLoop1D2AD();

	// Generic 2D loop, 2 arrays.
	computationKernelGenericLoop2D2A();
	printf("	- computationKernelGenericLoop2D2A---COMPLETE.\n");
	computationKernelGenericLoop2D2AD();
	printf("	- computationKernelGenericLoop2D2AD---COMPLETE.\n");

	// Generic 3D loop, 2 arrays.
	computationKernelGenericLoop3D2A();
*/
	printf("Exit.\n");

	return 0;
}
