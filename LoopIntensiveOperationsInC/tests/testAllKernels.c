#include "../computationKernels.h"
#include "../kernels/kernelConfiguration.h"
#include "minunit/minunit.h"

/**
 * Test for all computing kernels.
 */

/*
 * 		--- sum=2200200000.
		--- sum=200010000.
	- computationKernelPolybenchCholesky...COMPLETE.
		--- sum=2200200000.
		--- sum=200010000.
	- computationKernelPolybenchCholeskyD...COMPLETE.
		--- sum=22020000.000000.
		--- sum=-1624395.785872.
	- computationKernelPolybenchLu...COMPLETE.
		--- sum array1=11565000.000000.
		--- sum array2=12336000.000000.
		--- sum array3=12334000.000000.
		--- sum array4=13107000.000000.
		--- sum array5=13107000.000000.
		--- sum array1=629342482938.397217.
		--- sum array2=44574352400.000000.
		--- sum array3=12342900.000000.
		--- sum array4=13107000.000000.
		--- sum array5=5500782619657000.000000.
	- computationKernelPolybench2mm...COMPLETE.
		--- sum array1=18829000.000000.
		--- sum array2=20919000.000000.
		--- sum array3=23012000.000000.
		--- sum array4=25431000.000000.
		--- sum array5=18829000.000000.
		--- sum array6=21966000.000000.
		--- sum array1=753414045535400.000000.
		--- sum array2=20927000.000000.
		--- sum array3=22986000.000000.
		--- sum array4=25431000.000000.
		--- sum array5=476760574731000.000000.
		--- sum array6=266008260000.000000.
	- computationKernelPolybench3mm...COMPLETE.
		--- sum sum=1770.000000.
		--- sum C4=566400.000000.
		--- sum A=121856000.000000.
		--- sum sum=5097600.000000.
		--- sum C4=566800.000000.
		--- sum A=215685120000.000000.
	- computationKernelPolybenchDoitgen...COMPLETE.
		--- sum array1=12336000.000000.
		--- sum array2=14096000.000000.
		--- sum array3=12336000.000000.
		--- sum array1=6120759.428811.
		--- sum array2=5468526104633.609375.
		--- sum array3=-27212711.585962.
	- computationKernelPolybenchGramschmidt---COMPLETE.
		--- computationKernelPolybenchGramschmidtD.
		--- sum array1=12336000.000000.
		--- sum array2=14096000.000000.
		--- sum array3=12336000.000000.
		--- sum array1=6120759.428811.
		--- sum array2=5468526104633.609375.
		--- sum array3=-27212711.585962.
	- computationKernelPolybenchGramschmidtD---COMPLETE.
		--- sum sum=38510.000000.
		--- sum x_tislov=38510.000000.
		--- sum L_tislov=269570000.000000.
		--- sum b_tislov=1010100.000000.
		--- sum x_tislov=-1367800.000000.
		--- sum L_tislov=266371942.000000.
	- computationKernelPolybenchTislov---COMPLETE.
		--- sum array1_generic=560.000000.
		--- sum array2_generic=560.000000.
		--- computationKernelGenericLoop1D2A computing complete.
		--- sum array1_generic=155044.793678.
		--- sum array2_generic=4530.000000.
	- computationKernelGenericLoop1D2A---COMPLETE.
		--- sum sum=560.000000.
		--- sum sum=560.000000.
		--- sum array1_generic=155044.793678.
		--- sum array2_generic=4530.000000.
	- computationKernelGenericLoop1D2AD---COMPLETE.
		--- sum array1=56000.000000.
		--- sum array2=56000.000000.
		--- sum array1_generic=453000.000000.
		--- sum array2_generic=50833683.529556.
	- computationKernelGenericLoop2D2A---COMPLETE.
		--- sum array1=56000.000000.
		--- sum array2=56000.000000.
		--- sum array1_generic=453000.000000.
		--- sum array2_generic=50833683.529556.
	- computationKernelGenericLoop2D2AD---COMPLETE.
		--- sum A=4600000.000000.
		--- sum A=4600000.000000.
		--- sum array1_generic=29500000.000000.
		--- sum array2_generic=484000000.000000.
	- computationKernelGenericLoop3D2A---COMPLETE.
 *
 */

MU_TEST(test_computationKernelPolybenchCholesky_assert) {
	mu_assert_double_eq(2200200000, poly_cholesky_result.initArraySum);
	mu_assert_double_eq(200010000, poly_cholesky_result.modifiedArraySum);
}
MU_TEST(test_computationKernelPolybenchCholesky_d_assert) {
	mu_assert_double_eq(2200200000, poly_cholesky_d_result.initArraySum);
	mu_assert_double_eq(200010000, poly_cholesky_d_result.modifiedArraySum);
}

MU_TEST(test_computationKernelPolybenchLu_assert) {
	mu_assert_double_eq(22020000.000000, poly_lu_result.initArraySum);
	mu_assert_double_eq(-1624395.785872, poly_lu_result.modifiedArraySum);
}


MU_TEST(test_computationKernelPolybench2mm_assert) {
	mu_assert_double_eq(6061000.000000, poly_2mm_result.initArray1Sum);
	mu_assert_double_eq(6612000.000000, poly_2mm_result.initArray2Sum);
	mu_assert_double_eq(6610000.000000, poly_2mm_result.initArray3Sum);
	mu_assert_double_eq(7163000.000000, poly_2mm_result.initArray4Sum);
	mu_assert_double_eq(7163000.000000, poly_2mm_result.initArray5Sum);

	mu_assert_double_eq(84758363.323402, poly_2mm_result.modifiedArray1Sum);
	mu_assert_double_eq(14594042.809105, poly_2mm_result.modifiedArray2Sum);
	mu_assert_double_eq(6616300.000000, poly_2mm_result.modifiedArray3Sum);
	mu_assert_double_eq(7163000.000000, poly_2mm_result.modifiedArray4Sum);
	mu_assert_double_eq(18685234.259558, poly_2mm_result.modifiedArray5Sum);
}

MU_TEST(test_computationKernelPolybench3mm_assert) {
	mu_assert_double_eq(11565000, poly_3mm_result.initArray1Sum);
	mu_assert_double_eq(13215000, poly_3mm_result.initArray2Sum);
	mu_assert_double_eq(14868000, poly_3mm_result.initArray3Sum);
	mu_assert_double_eq(16847000, poly_3mm_result.initArray4Sum);
	mu_assert_double_eq(11565000, poly_3mm_result.initArray5Sum);
	mu_assert_double_eq(13216000, poly_3mm_result.initArray6Sum);

	mu_assert_double_eq(159745184.892273, poly_3mm_result.modifiedArray1Sum);
	mu_assert_double_eq(13207000, poly_3mm_result.modifiedArray2Sum);
	mu_assert_double_eq(15826000, poly_3mm_result.modifiedArray3Sum);
	mu_assert_double_eq(16821000, poly_3mm_result.modifiedArray4Sum);
	mu_assert_double_eq(60526556.772947, poly_3mm_result.modifiedArray5Sum);
	mu_assert_double_eq(87313855.841064, poly_3mm_result.modifiedArray6Sum);
}


MU_TEST(test_computationKernelPolybenchDoitgen_assert) {
	mu_assert_double_eq(1770.000000, poly_doitgen_result.initSumSum);
	mu_assert_double_eq(566400, poly_doitgen_result.initC4Sum);
	mu_assert_double_eq(121856000, poly_doitgen_result.initASum);

	mu_assert_double_eq(5097600, poly_doitgen_result.modifiedSumSum);
	mu_assert_double_eq(566800, poly_doitgen_result.modifiedC4Sum);
	mu_assert_double_eq(215685120000, poly_doitgen_result.modifiedASum);
}

MU_TEST(test_computationKernelPolybenchGramschmidt_assert) {
	mu_assert_double_eq(12336000, poly_gramschmidt_result.initArray1Sum);
	mu_assert_double_eq(14096000, poly_gramschmidt_result.initArray2Sum);
	mu_assert_double_eq(12336000, poly_gramschmidt_result.initArray3Sum);

	mu_assert_double_eq(7709.508900, poly_gramschmidt_result.modifiedArray1Sum);
	mu_assert_double_eq(7064573.124001, poly_gramschmidt_result.modifiedArray2Sum);
	mu_assert_double_eq(978.925500, poly_gramschmidt_result.modifiedArray3Sum);
}

MU_TEST(test_computationKernelPolybenchGramschmidt_d_assert) {
	mu_assert_double_eq(12336000, poly_gramschmidt_d_result.initArray1Sum);
	mu_assert_double_eq(14096000, poly_gramschmidt_d_result.initArray2Sum);
	mu_assert_double_eq(12336000, poly_gramschmidt_d_result.initArray3Sum);

	mu_assert_double_eq(7709.508900, poly_gramschmidt_d_result.modifiedArray1Sum);
	mu_assert_double_eq(7064573.124001, poly_gramschmidt_d_result.modifiedArray2Sum);
	mu_assert_double_eq(978.925500, poly_gramschmidt_d_result.modifiedArray3Sum);
}


MU_TEST(test_computationKernelPolybenchTislov_assert) {
	mu_assert_double_eq(38510, poly_tislov_result.initBSum);
	mu_assert_double_eq(38510, poly_tislov_result.initXSum);
	mu_assert_double_eq(269570000, poly_tislov_result.initLSum);

	mu_assert_double_eq(1010100, poly_tislov_result.modifiedBSum);
	mu_assert_double_eq(-1367800, poly_tislov_result.modifiedXSum);
	mu_assert_double_eq(266371942, poly_tislov_result.modifiedLSum);
}

MU_TEST(test_computationKernelGenericLoop1D2A_assert) {
	mu_assert_double_eq(560, genericLoop1D2A_result.initArray1Sum);
	mu_assert_double_eq(560, genericLoop1D2A_result.initArray2Sum);

	mu_assert_double_eq(155044.793678, genericLoop1D2A_result.modifiedArray1Sum);
	mu_assert_double_eq(4530, genericLoop1D2A_result.modifiedArray2Sum);
}

MU_TEST(test_computationKernelGenericLoop1D2AD_assert) {
	mu_assert_double_eq(560, genericLoop1D2AD_result.initArray1Sum);
	mu_assert_double_eq(560, genericLoop1D2AD_result.initArray2Sum);

	mu_assert_double_eq(155044.793678, genericLoop1D2AD_result.modifiedArray1Sum);
	mu_assert_double_eq(4530, genericLoop1D2AD_result.modifiedArray2Sum);
}

MU_TEST(test_computationKernelGenericLoop2D2A_assert) {
	mu_assert_double_eq(56000, genericLoop2D2A_result.initArray1Sum);
	mu_assert_double_eq(56000, genericLoop2D2A_result.initArray2Sum);

	mu_assert_double_eq(453000, genericLoop2D2A_result.modifiedArray1Sum);
	mu_assert_double_eq(50833683.529556, genericLoop2D2A_result.modifiedArray2Sum);
}

MU_TEST(test_computationKernelGenericLoop2D2AD_mu_assert_double_eq) {
	mu_assert_double_eq(5510000, genericLoop2D2AD_result.initArray1Sum);
	mu_assert_double_eq(56000, genericLoop2D2AD_result.initArray2Sum);

	mu_assert_double_eq(44130000, genericLoop2D2AD_result.modifiedArray1Sum);
	mu_assert_double_eq(533115515.577271, genericLoop2D2AD_result.modifiedArray2Sum);
}


MU_TEST(test_computationKernelGenericLoop3D2A_assert) {
	mu_assert_double_eq(4600000, genericLoop3D2A_result.initArray1Sum);
	mu_assert_double_eq(4600000, genericLoop3D2A_result.initArray2Sum);

	mu_assert_double_eq(29500000, genericLoop3D2A_result.modifiedArray1Sum);
	mu_assert_double_eq(484000000, genericLoop3D2A_result.modifiedArray2Sum);
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

	MU_SUITE_CONFIGURE(&computationKernelGenericLoop3D2A, NULL);
	MU_RUN_TEST(test_computationKernelGenericLoop3D2A_assert);

	// ------------------------------------------------------------------------------------
	// TODO:
	// Tests that seem to be unstable:
	// ------------------------------------------------------------------------------------
	// - Regardless if the array is allocated on heap or on stack, it should be the same.
	//MU_SUITE_CONFIGURE(&computationKernelGenericLoop2D2AD, NULL);
	//MU_RUN_TEST(test_computationKernelGenericLoop2D2AD_mu_assert_double_eq);

	//	MU_SUITE_CONFIGURE(&computationKernelPolybenchTislov, NULL);
	//	MU_RUN_TEST(test_computationKernelPolybenchTislov_assert);

	//MU_SUITE_CONFIGURE(&computationKernelPolybench3mm, NULL);
	//MU_RUN_TEST(test_computationKernelPolybench3mm_assert);

	//	MU_SUITE_CONFIGURE(&computationKernelPolybenchDoitgen, NULL);
	//	MU_RUN_TEST(test_computationKernelPolybenchDoitgen_assert);

	// - Regardles if the array is allocated on heap or on stack, it should be the same.
	//MU_SUITE_CONFIGURE(&computationKernelPolybenchCholeskyD, NULL);
	//MU_RUN_TEST(test_computationKernelPolybenchCholesky_d_assert);

	//MU_SUITE_CONFIGURE(&computationKernelPolybenchLu, NULL);
	//MU_RUN_TEST(test_computationKernelPolybenchLu_assert);
	// ------------------------------------------------------------------------------------
	/*
	// ------------------------------------------------------------------------------------
	// Examples of tests:
	// ------------------------------------------------------------------------------------
	MU_RUN_TEST(test_assert);
	MU_RUN_TEST(test_assert_int_eq);
	MU_RUN_TEST(test_mu_assert_double_eq);

	MU_RUN_TEST(test_check_fail);
	MU_RUN_TEST(test_assert_fail);
	MU_RUN_TEST(test_assert_int_eq_fail);
	MU_RUN_TEST(test_mu_assert_double_eq_fail);

	MU_RUN_TEST(test_fail);
	// ------------------------------------------------------------------------------------
	*/
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
