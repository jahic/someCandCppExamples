/**
 * Kernel configuration
 */
// - Polybench, cholesky
// - POLY_CHOLESKY_ARRAY_001_LENGTH_D2 must be higher than POLY_CHOLESKY_ARRAY_001_LENGTH_D1
// - The dimensions should be equal.
#define POLY_CHOLESKY_ARRAY_001_LENGTH_D1 20000
#define POLY_CHOLESKY_ARRAY_001_LENGTH_D2 20000

// - Polybench, lu
// Stack arrays.
#define POLY_LU_ARRAY_001_LENGTH_D1 2000
#define POLY_LU_ARRAY_001_LENGTH_D2 2000

// - Polybench, 2mm
#define POLY_2MM_ARRAY_001_LENGTH_D1 1400
#define POLY_2MM_ARRAY_001_LENGTH_D2 1500

#define POLY_2MM_ARRAY_002_LENGTH_D1 1400
#define POLY_2MM_ARRAY_002_LENGTH_D2 1600

#define POLY_2MM_ARRAY_003_LENGTH_D1 1600
#define POLY_2MM_ARRAY_003_LENGTH_D2 1400

#define POLY_2MM_ARRAY_004_LENGTH_D1 1400
#define POLY_2MM_ARRAY_004_LENGTH_D2 1700

#define POLY_2MM_ARRAY_005_LENGTH_D1 1400
#define POLY_2MM_ARRAY_005_LENGTH_D2 1700

// - Polybench, 3mm
#define POLY_3MM_ARRAY_001_LENGTH_D1 1800
#define POLY_3MM_ARRAY_001_LENGTH_D2 1900

#define POLY_3MM_ARRAY_002_LENGTH_D1 2000
#define POLY_3MM_ARRAY_002_LENGTH_D2 1900

#define POLY_3MM_ARRAY_003_LENGTH_D1 1900
#define POLY_3MM_ARRAY_003_LENGTH_D2 2200

#define POLY_3MM_ARRAY_004_LENGTH_D1 2200
#define POLY_3MM_ARRAY_004_LENGTH_D2 2100

#define POLY_3MM_ARRAY_005_LENGTH_D1 1800
#define POLY_3MM_ARRAY_005_LENGTH_D2 1900

#define POLY_3MM_ARRAY_006_LENGTH_D1 1900
#define POLY_3MM_ARRAY_006_LENGTH_D2 2100

// - Polybench, doitgen
#define POLY_DOITGEN_ARRAY_001_LENGTH_D1 320

#define POLY_DOITGEN_ARRAY_002_LENGTH_D1 320
#define POLY_DOITGEN_ARRAY_002_LENGTH_D2 320

#define POLY_DOITGEN_ARRAY_003_LENGTH_D1 300
#define POLY_DOITGEN_ARRAY_003_LENGTH_D2 280
#define POLY_DOITGEN_ARRAY_003_LENGTH_D3 320

// - Polybench, gramschmidt
#define POLY_GRAMSCHMIDT_ARRAY_001_LENGTH_D1 1400
#define POLY_GRAMSCHMIDT_ARRAY_001_LENGTH_D2 1600

#define POLY_GRAMSCHMIDT_ARRAY_002_LENGTH_D1 1600
#define POLY_GRAMSCHMIDT_ARRAY_002_LENGTH_D2 1600

#define POLY_GRAMSCHMIDT_ARRAY_003_LENGTH_D1 1400
#define POLY_GRAMSCHMIDT_ARRAY_003_LENGTH_D2 1600

// - Polybench, tislov
#define POLY_TISLOV_ARRAY_001_LENGTH_D1 7000

#define POLY_TISLOV_ARRAY_002_LENGTH_D1 7000

#define POLY_TISLOV_ARRAY_003_LENGTH_D1 7000
#define POLY_TISLOV_ARRAY_003_LENGTH_D2 7000

// - Generic arrays
#define GENERIC_ARRAY_001_D1 100
#define GENERIC_ARRAY_001_D2 100
#define GENERIC_ARRAY_001_D3 100

#define GENERIC_ARRAY_002_D1 100
#define GENERIC_ARRAY_002_D2 100
#define GENERIC_ARRAY_002_D3 100