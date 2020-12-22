/**
 * Computation intensive functionalities.
 * Patterns of high-computing applications.
 *
 */

#include <stdio.h>

//#define LOG_RESULTS
//#define LOG_RESULTS_BINARY
//#define LOG_RESULTS_JPAR

#ifdef LOG_RESULTS
FILE *logFile;
#endif /* MACRO */

// Polybench, cholesky
// - Arrays on stack.
void computationKernelPolybenchCholesky();
// - Dynamic allocation of memory for the arrays.
void computationKernelPolybenchCholeskyD();

// Polybench, lu
void computationKernelPolybenchLu();

// Polybench, 2mm
void computationKernelPolybench2mm();

// Polybench, 3mm
void computationKernelPolybench3mm();

// Polybench, doitgen
void computationKernelPolybenchDoitgen();

// Polybench, gramschmidt
// - Arrays on stack.
void computationKernelPolybenchGramschmidt();
// - Dynamically allocated arrays.
void computationKernelPolybenchGramschmidtD();

// Polybench, tislov
void computationKernelPolybenchTislov();

// Generic 1D loop, 2 arrays.
// - Arrays on stack.
void computationKernelGenericLoop1D2A();
// - Dynamic allocation of arrays.
void computationKernelGenericLoop1D2AD();

// Generic 2D loop, 2 arrays.
// - Arrays on stack.
void computationKernelGenericLoop2D2A();
// - Dynamic allocation of arrays.
void computationKernelGenericLoop2D2AD();

// Generic 3D loop, 2 arrays.
// - Arrays on stack.
void computationKernelGenericLoop3D2A();
