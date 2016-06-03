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

#ifndef __STD_COMPLEMENT_ALGORITHM_H
#define __STD_COMPLEMENT_ALGORITHM_H

#include "functional.h"

namespace stdc
{

/*!
 * \brief Checks if the elements [first,second,rest...] are sorted in
 * non-descending order according to the Compare criteria, which defaults to
 * stdc::less<T>.
 */
template <typename T, typename Compare = stdc::less<T>, typename... Rest>
constexpr bool is_sorted(T first, T second, Rest... rest);

/*!
 * \brief Removes all elements from container that are equal to value.
 *
 * \post The size of the container is reduced by the number of elements that
 * were removed.
 *
 * \return Past-the-end iterator after the elements are removed.
 */
template <typename Container>
auto erase_remove(Container& container, typename Container::value_type const& value) -> typename Container::iterator;

/*!
 * \brief Removes all elements from container for which predicate pred
 * returns true.
 *
 * \post The size of the container is reduced by the number of elements that
 * were removed.
 *
 * \return Past-the-end iterator after the elements are removed.
 */
template <typename Container, typename UnaryPredicate>
auto erase_remove_if(Container& container, UnaryPredicate pred) -> typename Container::iterator;

} /* namespace stdc */

#include "bits/algorithm_impl.h"

#endif /* __STD_COMPLEMENT_ALGORITHM_H */
