project(stdc_examples)

add_definitions(-Wall -Werror -Wextra -std=c++11)

set(STDC_INCLUDE_DIR ../include)

include_directories(${STDC_INCLUDE_DIR})
add_executable(example_quicksort quicksort/example.cpp)
