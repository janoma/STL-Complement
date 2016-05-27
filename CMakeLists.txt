project(stdc_tests)

add_subdirectory(test)

enable_testing()

add_test(NAME <algorithm.h> COMMAND stdc_algorithm_unit_tests)
add_test(NAME <iterator.h> COMMAND stdc_iterator_unit_tests)
