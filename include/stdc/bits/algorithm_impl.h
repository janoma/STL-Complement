#ifndef __STD_COMPLEMENT_ALGORITHM_IMPL
#define __STD_COMPLEMENT_ALGORITHM_IMPL

namespace stdc
{

template <typename T, typename Compare = std::less<T>>
constexpr bool
is_sorted(T const&)
{
    return true;
}

template <typename T, typename Compare, typename... Rest>
constexpr bool
is_sorted(T first, T second, Rest... rest)
{
    return Compare()(first, second) and is_sorted<T, Compare>(second, rest...);
}

} /* namespace stdc */

#endif /* __STD_COMPLEMENT_ALGORITHM_IMPL */
