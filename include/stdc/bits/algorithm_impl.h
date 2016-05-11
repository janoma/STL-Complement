// MIT License
//
// Copyright (c) 2016 Alejandro Mallea
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __STD_COMPLEMENT_ALGORITHM_IMPL
#define __STD_COMPLEMENT_ALGORITHM_IMPL

#include <algorithm>
#include <iterator>

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

template <typename Container>
inline auto
erase_remove(Container& container, typename Container::value_type const& value) -> typename Container::iterator
{
    container.resize(std::distance(std::begin(container), std::remove(std::begin(container), std::end(container), value)));

    return std::end(container);
}

template <typename Container, typename UnaryPredicate>
inline auto
erase_remove_if(Container& container, UnaryPredicate pred) -> typename Container::iterator
{
    container.resize(std::distance(std::begin(container), std::remove_if(std::begin(container), std::end(container), pred)));

    return std::end(container);
}

} /* namespace stdc */

#endif /* __STD_COMPLEMENT_ALGORITHM_IMPL */
