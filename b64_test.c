#include "shortener.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdlib.h>
#include <string.h>

void assert_b64enc(char *s, char *expected) {
  int err;
  char *r = b64enc_str(s, &err);
  CU_ASSERT_EQUAL(0, err);
  CU_ASSERT_STRING_EQUAL(expected, r);
  free(r);
}

void assert_b64dec(char *s, char *expected) {
  int err;
  char *r = b64dec_str(s, &err);
  CU_ASSERT_EQUAL(0, err);
  CU_ASSERT_STRING_EQUAL(expected, r);
  free(r);
}

void test_b64enc_empty(void) {
  assert_b64enc("", "");
}

void test_b64enc_a(void) {
  assert_b64enc("a", "YQ==");
}

void test_b64enc_hello(void) {
  assert_b64enc("hello", "aGVsbG8=");
}

void test_b64enc_hw(void) {
  assert_b64enc("hello world", "aGVsbG8gd29ybGQ=");
}

void test_b64dec_empty(void) {
  int err;
  char *r = b64dec_str("", &err);
  CU_ASSERT_STRING_EQUAL("", r);
  free(r);
}

void test_b64dec_a(void) {
  assert_b64dec("YQ==", "a");
}

void test_b64dec_newyork(void) {
  assert_b64dec("bmV3eW9yaw==", "newyork");
}

void test_b64_identity(void) {
  char *r = "hello world";
  int err;
  char *enc = b64enc_str(r, &err);
  if (err != 0) {
    CU_FAIL("Failed to encode");
  }
  char *dec = b64dec_str(enc, &err);
  if (err !=0) {
    CU_FAIL("Failed to decode");
  }
  CU_ASSERT_STRING_EQUAL(r, dec);
  free(enc);
  free(dec);
}

int main() {
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  CU_TestInfo b64enc_tests[] = {
    {"test_b64enc_empty", test_b64enc_empty},
    {"test_b64enc_a", test_b64enc_a},
    {"test_b64enc_hello", test_b64enc_hello},
    {"test_b64enc_hw", test_b64enc_hw},
    CU_TEST_INFO_NULL
  };

  CU_TestInfo b64dec_tests[] = {
    // For completeness - if we decode a null or
    // an empty string, it is natural to return
    // a null or an empty string. How to handle it
    //{"test_b64dec_empty", test_b64dec_empty},
    {"test_b64dec_a", test_b64dec_a},
    {"test_b64dec_newyork", test_b64dec_newyork},
    CU_TEST_INFO_NULL
  };

  CU_TestInfo b64_identity_tests[] = {
    {"test_b64_identity", test_b64_identity},
    CU_TEST_INFO_NULL
  };

  CU_SuiteInfo b64_suites[] = {
    {"b64enc_suite", NULL, NULL, b64enc_tests},
    {"b64dec_suite", NULL, NULL, b64dec_tests},
    {"b64_identity_suite", NULL, NULL, b64_identity_tests},
    CU_SUITE_INFO_NULL
  };
  if (CUE_SUCCESS != CU_register_suites(b64_suites)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  //CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
