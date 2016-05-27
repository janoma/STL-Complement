cmake_minimum_required(VERSION 3.1)

project(stdc_tests)

add_subdirectory(test)

enable_testing()

add_test(NAME Algorithm COMMAND stdc_algorithm_unit_tests)
add_test(NAME Functional COMMAND stdc_functional_unit_tests)
add_test(NAME Iterator COMMAND stdc_iterator_unit_tests)
