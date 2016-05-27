add_definitions(-Wall -Werror -Wextra -std=c++11)

set(STDC_INCLUDE_DIR ../include)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${STDC_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

add_executable(stdc_algorithm_unit_tests test_stdc_algorithm.cpp)
add_executable(stdc_iterator_unit_tests test_stdc_iterator.cpp)

target_link_libraries(stdc_algorithm_unit_tests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(stdc_iterator_unit_tests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
