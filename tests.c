#include "pareeksha.h"
#include <stdio.h>
#include <stdlib.h>

// Example test functions
void test_addition() {
  int result = 2 + 2;
  EXPECT(result == 4, "Addition test");
  EXPECT(result != 5, "Addition test - Result should not be 5");
}

void test_subtraction() {
  int result = 5 - 3;
  ASSERT(result == 2, "Subtraction test");
  ASSERT(result != 10, "Subtraction test - Result should not be 10");
}

// Example setup and teardown functions
void setup() {
  printf("Running setup...\n");
  // Perform setup operations here
}

void teardown() {
  printf("Running teardown...\n");
  // Perform teardown operations here
}

int main() {
  const char *log_file_path = "test_results.json";

  add_test("Addition", test_addition, NULL, NULL);
  add_test("Subtraction", test_subtraction, setup, teardown);

  int failures = run_tests(log_file_path);
  printf("Total failures: %d\n", failures);

  return failures > 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
