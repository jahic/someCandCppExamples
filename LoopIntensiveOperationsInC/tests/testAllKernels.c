#include "../computationKernels.h"
#include "../kernels/kernelConfiguration.h"
#include "minunit/minunit.h"

/**
 * Test for all computing kernels.
 */

MU_TEST(test_computationKernelPolybenchCholesky_assert) {
	mu_assert_long_eq(2200000000, poly_cholesky_result.initArraySum);
	mu_assert_long_eq(200010000, poly_cholesky_result.modifiedArraySum);
}
MU_TEST(test_computationKernelPolybenchCholesky_d_assert) {
	mu_assert_long_eq(2200200000, poly_cholesky_d_result.initArraySum);
	mu_assert_long_eq(200010000, poly_cholesky_d_result.modifiedArraySum);
}

MU_TEST(test_computationKernelPolybenchLu_assert) {
	mu_assert_long_eq(22020000.000000, poly_lu_result.initArraySum);
	mu_assert_long_eq(-1624395.785872, poly_lu_result.modifiedArraySum);
}


MU_TEST(test_computationKernelPolybench2mm_assert) {
	mu_assert_long_eq(6061000.000000, poly_2mm_result.initArray1Sum);
	mu_assert_long_eq(6612000.000000, poly_2mm_result.initArray2Sum);
	mu_assert_long_eq(6610000.000000, poly_2mm_result.initArray3Sum);
	mu_assert_long_eq(7163000.000000, poly_2mm_result.initArray4Sum);
	mu_assert_long_eq(7163000.000000, poly_2mm_result.initArray5Sum);

	mu_assert_long_eq(84758363.323402, poly_2mm_result.modifiedArray1Sum);
	mu_assert_long_eq(14594042.809105, poly_2mm_result.modifiedArray2Sum);
	mu_assert_long_eq(6616300.000000, poly_2mm_result.modifiedArray3Sum);
	mu_assert_long_eq(7163000.000000, poly_2mm_result.modifiedArray4Sum);
	mu_assert_long_eq(18685234.259558, poly_2mm_result.modifiedArray5Sum);
}

MU_TEST(test_computationKernelPolybench3mm_assert) {
	mu_assert_long_eq(11550000, poly_3mm_result.initArray1Sum);
	mu_assert_long_eq(13200000, poly_3mm_result.initArray2Sum);
	mu_assert_long_eq(15840000, poly_3mm_result.initArray3Sum);
	mu_assert_long_eq(16830000, poly_3mm_result.initArray4Sum);
	mu_assert_long_eq(11550000, poly_3mm_result.initArray5Sum);
	mu_assert_long_eq(13200000, poly_3mm_result.initArray6Sum);

	mu_assert_long_eq(10823600, poly_3mm_result.modifiedArray1Sum);
	mu_assert_long_eq(13179000, poly_3mm_result.modifiedArray2Sum);
	mu_assert_long_eq(15806000, poly_3mm_result.modifiedArray3Sum);
	mu_assert_long_eq(16803000, poly_3mm_result.modifiedArray4Sum);
	mu_assert_long_eq(707400, poly_3mm_result.modifiedArray5Sum);
	mu_assert_long_eq(2400000, poly_3mm_result.modifiedArray6Sum);
}


MU_TEST(test_computationKernelPolybenchDoitgen_assert) {
	mu_assert_long_eq(1770.000000, poly_doitgen_result.initSumSum);
	mu_assert_long_eq(566400, poly_doitgen_result.initC4Sum);
	mu_assert_long_eq(121856000, poly_doitgen_result.initASum);

	mu_assert_long_eq(5097600, poly_doitgen_result.modifiedSumSum);
	mu_assert_long_eq(566800, poly_doitgen_result.modifiedC4Sum);
	mu_assert_long_eq(215685120000, poly_doitgen_result.modifiedASum);
}

MU_TEST(test_computationKernelPolybenchGramschmidt_assert) {
	mu_assert_long_eq(12320000, poly_gramschmidt_result.initArray1Sum);
	mu_assert_long_eq(14080000, poly_gramschmidt_result.initArray2Sum);
	mu_assert_long_eq(12320000, poly_gramschmidt_result.initArray3Sum);

	mu_assert_long_eq(7700, poly_gramschmidt_result.modifiedArray1Sum);
	mu_assert_long_eq(7057606, poly_gramschmidt_result.modifiedArray2Sum);
	mu_assert_long_eq(560, poly_gramschmidt_result.modifiedArray3Sum);
}

MU_TEST(test_computationKernelPolybenchGramschmidt_d_assert) {
	mu_assert_long_eq(12336000, poly_gramschmidt_d_result.initArray1Sum);
	mu_assert_long_eq(14096000, poly_gramschmidt_d_result.initArray2Sum);
	mu_assert_long_eq(12336000, poly_gramschmidt_d_result.initArray3Sum);

	mu_assert_long_eq(2246310, poly_gramschmidt_d_result.modifiedArray1Sum);
	mu_assert_long_eq(7057716, poly_gramschmidt_d_result.modifiedArray2Sum);
	mu_assert_long_eq(221761, poly_gramschmidt_d_result.modifiedArray3Sum);
}

MU_TEST(test_computationKernelPolybenchTislov_assert) {
	mu_assert_long_eq(31510, poly_tislov_result.initBSum);
	mu_assert_long_eq(31510, poly_tislov_result.initXSum);
	mu_assert_long_eq(269500000, poly_tislov_result.initLSum);

	mu_assert_long_eq(1004500, poly_tislov_result.modifiedBSum);
	mu_assert_long_eq(18446744073708178216, poly_tislov_result.modifiedXSum);
	mu_assert_long_eq(266302052, poly_tislov_result.modifiedLSum);
}

MU_TEST(test_computationKernelGenericLoop1D2A_assert) {
	mu_assert_long_eq(460, genericLoop1D2A_result.initArray1Sum);
	mu_assert_long_eq(460, genericLoop1D2A_result.initArray2Sum);

	mu_assert_long_eq(115811.793678, genericLoop1D2A_result.modifiedArray1Sum);
	mu_assert_long_eq(3410, genericLoop1D2A_result.modifiedArray2Sum);
}

MU_TEST(test_computationKernelGenericLoop1D2AD_assert) {
	mu_assert_long_eq(560, genericLoop1D2AD_result.initArray1Sum);
	mu_assert_long_eq(560, genericLoop1D2AD_result.initArray2Sum);

	mu_assert_long_eq(154995, genericLoop1D2AD_result.modifiedArray1Sum);
	mu_assert_long_eq(4530, genericLoop1D2AD_result.modifiedArray2Sum);
}

MU_TEST(test_computationKernelGenericLoop2D2A_assert) {
	mu_assert_long_eq(55000, genericLoop2D2A_result.initArray1Sum);
	mu_assert_long_eq(55000, genericLoop2D2A_result.initArray2Sum);

	mu_assert_long_eq(440000, genericLoop2D2A_result.modifiedArray1Sum);
	mu_assert_long_eq(33221406, genericLoop2D2A_result.modifiedArray2Sum);
}

MU_TEST(test_computationKernelGenericLoop2D2AD_mu_assert) {
	mu_assert_long_eq(5510000, genericLoop2D2AD_result.initArray1Sum);
	mu_assert_long_eq(56000, genericLoop2D2AD_result.initArray2Sum);

	mu_assert_long_eq(44130000, genericLoop2D2AD_result.modifiedArray1Sum);
	mu_assert_long_eq(326098732, genericLoop2D2AD_result.modifiedArray2Sum);
}

MU_TEST(test_computationKernelGenericLoop3D2A_assert) {
	mu_assert_long_eq(4600000, genericLoop3D2A_result.initArray1Sum);
	mu_assert_long_eq(4600000, genericLoop3D2A_result.initArray2Sum);

	mu_assert_long_eq(29500000, genericLoop3D2A_result.modifiedArray1Sum);
	mu_assert_long_eq(484000000, genericLoop3D2A_result.modifiedArray2Sum);
}

MU_TEST_SUITE(test_suite) {

	// Test commented below have issues with Janus parallelizer.
	MU_SUITE_CONFIGURE(&computationKernelPolybenchCholesky, NULL);
	MU_RUN_TEST(test_computationKernelPolybenchCholesky_assert);

	//MU_SUITE_CONFIGURE(&computationKernelPolybench2mm, NULL);
	//MU_RUN_TEST(test_computationKernelPolybench2mm_assert);

	MU_SUITE_CONFIGURE(&computationKernelPolybenchGramschmidt, NULL);
    MU_RUN_TEST(test_computationKernelPolybenchGramschmidt_assert);
	// - Regardless if the array is allocated on heap or on stack, it should be the same.
	//MU_SUITE_CONFIGURE(&computationKernelPolybenchGramschmidtD, NULL);
	//MU_RUN_TEST(test_computationKernelPolybenchGramschmidt_d_assert);

	MU_SUITE_CONFIGURE(&computationKernelGenericLoop1D2A, NULL);
	MU_RUN_TEST(test_computationKernelGenericLoop1D2A_assert);
	// - Regardless if the array is allocated on heap or on stack, it should be the same.
	MU_SUITE_CONFIGURE(&computationKernelGenericLoop1D2AD, NULL);
	MU_RUN_TEST(test_computationKernelGenericLoop1D2AD_assert);

	MU_SUITE_CONFIGURE(&computationKernelGenericLoop2D2A, NULL);
	MU_RUN_TEST(test_computationKernelGenericLoop2D2A_assert);

	//MU_SUITE_CONFIGURE(&computationKernelGenericLoop3D2A, NULL);
	//MU_RUN_TEST(test_computationKernelGenericLoop3D2A_assert);

	// ------------------------------------------------------------------------------------
	// TODO:
	// Tests that seem to be unstable:
	// ------------------------------------------------------------------------------------
	// - Regardless if the array is allocated on heap or on stack, it should be the same.
	MU_SUITE_CONFIGURE(&computationKernelGenericLoop2D2AD, NULL);
	MU_RUN_TEST(test_computationKernelGenericLoop2D2AD_mu_assert);

	MU_SUITE_CONFIGURE(&computationKernelPolybenchTislov, NULL);
	MU_RUN_TEST(test_computationKernelPolybenchTislov_assert);

	MU_SUITE_CONFIGURE(&computationKernelPolybench3mm, NULL);
	MU_RUN_TEST(test_computationKernelPolybench3mm_assert);

	//MU_SUITE_CONFIGURE(&computationKernelPolybenchDoitgen, NULL);
	//MU_RUN_TEST(test_computationKernelPolybenchDoitgen_assert);

	// - Regardles if the array is allocated on heap or on stack, it should be the same.
	MU_SUITE_CONFIGURE(&computationKernelPolybenchCholeskyD, NULL);
	MU_RUN_TEST(test_computationKernelPolybenchCholesky_d_assert);

	//MU_SUITE_CONFIGURE(&computationKernelPolybenchLu, NULL);
	//MU_RUN_TEST(test_computationKernelPolybenchLu_assert);
	// ------------------------------------------------------------------------------------
	/*
	// ------------------------------------------------------------------------------------
	// Examples of tests:
	// ------------------------------------------------------------------------------------
	MU_RUN_TEST(test_assert);
	MU_RUN_TEST(test_assert_int_eq);
	MU_RUN_TEST(test_mu_assert);

	MU_RUN_TEST(test_check_fail);
	MU_RUN_TEST(test_assert_fail);
	MU_RUN_TEST(test_assert_int_eq_fail);
	MU_RUN_TEST(test_mu_assert_fail);

	MU_RUN_TEST(test_fail);
	// ------------------------------------------------------------------------------------
	*/
}

int main(int argc, char *argv[]) {

	#ifdef LOG_RESULTS
	// Restart the file
	logFile = fopen("log.txt", "w+");
	fclose(logFile);
	#endif /* MACRO */

	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
