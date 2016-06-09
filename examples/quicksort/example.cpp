#include <iostream>
#include <vector>

#include "quicksort.h"

template <typename Numbers>
void print(Numbers const& numbers)
{
    for (auto n : numbers)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> numbers{18, 6, 8, 4, 9, 7, 1, 15, 5, 19};

    quicksort(numbers.begin(), numbers.end());

    print(numbers);

    quicksort(numbers.begin(), numbers.end(), std::greater<int>());

    print(numbers);
}
