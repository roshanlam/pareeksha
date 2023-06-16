# Pareeksha

A lightweight C library for writing and running unit tests. It basically provides a simple and flexible testing framework to do things like define and execute tests, perform assertions, and report test results.

## Current Features
* Easy test definition: 
    Define test functions and use assertion macros to verify expected behavior.
* Setup and teardown functions: 
    Execute setup and teardown operations before and after each test.
* Test result reporting: 
    Print test results with pass/fail status and error messages.

## Usage

1. Include the pareeksha.h header file in your test files.

```c
#include "pareeksha.h"
```

2. Write your test functions using the provided assertion macros EXPECT and ASSERT. For example

```c
void test_addition() {
    int result = 2 + 2;
    EXPECT(result == 4, "Addition test");
    EXPECT(result != 5, "Addition test - Result should not be 5");
}
```

3. Optionally, define setup and teardown functions to be executed before and after each test:

```c
void setup() {
    // Perform setup operations here
}

void teardown() {
    // Perform teardown operations here
}
```

3. Register your test functions, setup, and teardown functions using the add_test function:
```c
add_test("Addition", test_addition, setup, teardown);
```
4. Use the run_tests function to execute all the registered tests
```c
    int failures = run_tests();
```

5. Review the test results and the total number of failures.
```
printf("Total failures: %d\n", failures);
```

## Assertion Macros
The Testing Framework provides the following assertion macros to check conditions and report test failures:

```c 
EXPECT(condition, message)
```
  * Checks if the given condition is true. If the condition is false, the test will continue execution and report a failure.

```c 
ASSERT(condition, message)
```
* Checks if the given condition is true. If the condition is false, the test will immediately stop execution and report a failure.

## Example

Here's a simple example of how to use Pareeksha:

```c
#include "pareeksha.h"

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
    add_test("Addition", test_addition, NULL, NULL);
    add_test("Subtraction", test_subtraction, setup, teardown);

    int failures = run_tests();
    printf("Total failures: %d\n", failures);

    return failures > 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}

```

## License

This project is licensed under the MIT License.