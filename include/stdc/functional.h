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

#ifndef __STD_COMPLEMENT_FUNCTIONAL_H
#define __STD_COMPLEMENT_FUNCTIONAL_H

#include <functional>

namespace stdc
{

/*!
 * \brief Function object for performing comparisons. Unless specialized,
 * invokes operator< on type T.
 */
template <typename T>
struct less
{
    using result_type = bool;
    using first_argument_type = T;
    using second_argument_type = T;

    constexpr bool operator()(T const& lhs, T const& rhs) const;
};

/*!
 * \brief Function object for performing comparisons. Unless specialized,
 * invokes operator<= on type T.
 */
template <typename T>
struct less_equal
{
    using result_type = bool;
    using first_argument_type = T;
    using second_argument_type = T;

    constexpr bool operator()(T const& lhs, T const& rhs) const;
};

/*!
 * \brief Function object for performing comparisons. Unless specialized,
 * invokes operator> on type T.
 */
template <typename T>
struct greater
{
    using result_type = bool;
    using first_argument_type = T;
    using second_argument_type = T;

    constexpr bool operator()(T const& lhs, T const& rhs) const;
};

/*!
 * \brief Function object for performing comparisons. Unless specialized,
 * invokes operator>= on type T.
 */
template <typename T>
struct greater_equal
{
    using result_type = bool;
    using first_argument_type = T;
    using second_argument_type = T;

    constexpr bool operator()(T const& lhs, T const& rhs) const;
};

template <typename T, typename Compare = std::less<T>>
struct less_than
{
    using result_type = bool;
    using argument_type = T;

    explicit less_than(T const& pivot, Compare compare = Compare());

    bool operator()(T const& value) const;

protected:
    const T m_pivot;
    const Compare m_compare;
};

template <typename T, typename Compare = std::greater<T>>
struct greater_than
{
    using result_type = bool;
    using argument_type = T;

    explicit greater_than(T const& pivot, Compare compare = Compare());

    bool operator()(T const& value) const;

protected:
    const T m_pivot;
    const Compare m_compare;
};

} /* namespace stdc */

#include "bits/functional_impl.h"

#endif /* __STD_COMPLEMENT_FUNCTIONAL_H */
