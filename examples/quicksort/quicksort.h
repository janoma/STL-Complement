#ifndef __QUICKSORT_EXAMPLE_H
#define __QUICKSORT_EXAMPLE_H

#include <algorithm>
#include <functional>
#include <iterator>

#include <stdc/functional.h>

template <typename BidirIt, typename Compare = std::less<typename std::iterator_traits<BidirIt>::value_type>>
inline void
quicksort(BidirIt begin, BidirIt end, Compare compare = Compare())
{
    using T = typename std::iterator_traits<BidirIt>::value_type;

    if (std::distance(begin, end) <= 1) { return; }

    auto const pivot = *begin;
    auto middle1 = std::partition(begin, end, stdc::less_than<T, Compare>(pivot, compare));
    auto middle2 = std::partition(middle1, end, stdc::equal_to<T>(pivot));
    quicksort(begin, middle1, compare);
    quicksort(middle2, end, compare);
}

#endif /* __QUICKSORT_EXAMPLE_H */
