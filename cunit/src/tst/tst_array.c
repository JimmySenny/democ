#include "array.h"
#include "cu_tst.h"

/* gcc -o tst democunit.c -I...  -L...  -lcunit */

void tst_twoSum_case1(void){
    int nums[] = {2,7,11,15};
    int len = sizeof(nums)/sizeof(nums[0]);
    int target = 9;
    int retLen = 0;
    twoSum(nums, len, target, &retLen);

    printf("case1:retlen[%d]\n", retLen);
    
    CU_ASSERT_EQUAL(retLen, 2);
    //CU_ASSERT_EQUAL(nums[0], 2);
    //CU_ASSERT_EQUAL(nums[0], 7);
}

void tst_twoSum_case2(void){
    int nums[] = {};
    int len = sizeof(nums)/sizeof(nums[0]);
    int target = 9;
    int retLen = 0;
    twoSum(nums, len, target, &retLen);
    
    printf("case2:retlen[%d]\n", retLen);
    CU_ASSERT_EQUAL(retLen, 0);
}

int suite_succ_init(void){
    return 0;
}
int suite_succ_clean(void){
    return 0;
}

CU_TestInfo tst_array_twoSum[] = {
    {"tst_twoSum_case1", tst_twoSum_case1},
    {"tst_twoSum_case2", tst_twoSum_case2},
    CU_TEST_INFO_NULL
};
CU_TestInfo tst_case2[] = {
    CU_TEST_INFO_NULL
};

CU_SuiteInfo suites[] = {
    {"tst_array_twoSum:", suite_succ_init, suite_succ_clean, NULL, NULL, tst_array_twoSum},
    CU_SUITE_INFO_NULL
};

int addSuites( void ){
    assert( NULL != CU_get_registry());
    assert( !CU_is_test_running());
    if( CUE_SUCCESS != CU_register_suites(suites)){
        exit(EXIT_FAILURE);
    }
    return 0;
}

int runCUnit(void){
    if( CU_initialize_registry()){
        fprintf(stderr, "Initialization of Test Registry failed. ");
        exit(EXIT_FAILURE);
    }else{
        addSuites();
        /**
         * Mode
         */
        // Automated Mode
        CU_set_output_filename("test");
        CU_automated_run_tests();
        CU_list_tests_to_file();
        // Basic Mode
        /**
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
         */
        // Console
        /**
        CU_console_run_tests();
         */

        CU_cleanup_registry();
        return  CU_get_error();
    }

    return 0;
}

void tst_array(void){
    printf("tst_array\n");
    runCUnit();
}
