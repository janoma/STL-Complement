add_definitions(-Wall -Werror -Wextra)

set(STDC_INCLUDE_DIR ../include)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${STDC_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

add_executable(stdc_algorithm_unit_tests test_stdc_algorithm.cpp)
add_executable(stdc_functional_unit_tests test_stdc_functional.cpp)
add_executable(stdc_iterator_unit_tests test_stdc_iterator.cpp)

target_compile_features(stdc_algorithm_unit_tests PUBLIC
    cxx_variadic_templates cxx_constexpr cxx_auto_type)
target_compile_features(stdc_functional_unit_tests PUBLIC
    cxx_constexpr)
target_compile_features(stdc_iterator_unit_tests PUBLIC
    cxx_variadic_templates)

target_link_libraries(stdc_algorithm_unit_tests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(stdc_functional_unit_tests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(stdc_iterator_unit_tests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
