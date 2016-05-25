cmake_minimum_required(VERSION 3.0)

project(stdc_tests)

add_definitions(-Wall -Werror -Wextra -std=c++14)

set(STDC_INCLUDE_DIR ../include)
set(Boost_INCLUDE_DIR /usr/local/boost-1.60.0/include)
set(Boost_LIBRARY_DIR /usr/local/boost-1.60.0/lib)
find_package(Boost COMPONENTS timer chrono system unit_test_framework REQUIRED)

include_directories (${Boost_INCLUDE_DIR} ${STDC_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(stdc_algorithm_unit_tests test_stdc_algorithm.cpp)
add_executable(stdc_iterator_unit_tests test_stdc_iterator.cpp)
target_link_libraries(stdc_algorithm_unit_tests ${Boost_LIBRARIES})
target_link_libraries(stdc_iterator_unit_tests ${Boost_LIBRARIES})
