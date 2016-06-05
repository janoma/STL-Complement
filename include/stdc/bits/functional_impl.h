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

#ifndef __STD_COMPLEMENT_FUNCTIONAL_IMPL
#define __STD_COMPLEMENT_FUNCTIONAL_IMPL


namespace stdc
{

template <typename T>
inline constexpr bool
less<T>::operator()(T const& lhs, T const& rhs) const
{
    return lhs < rhs;
}

template <typename T>
inline constexpr bool
less_equal<T>::operator()(T const& lhs, T const& rhs) const
{
    return lhs <= rhs;
}

template <typename T>
inline constexpr bool
greater<T>::operator()(T const& lhs, T const& rhs) const
{
    return lhs > rhs;
}

template <typename T>
inline constexpr bool
greater_equal<T>::operator()(T const& lhs, T const& rhs) const
{
    return lhs >= rhs;
}

template <typename T, typename Compare>
inline
less_than<T, Compare>::less_than(T const& pivot, Compare compare)
    : m_pivot(pivot), m_compare(compare)
{
}

template <typename T, typename Compare>
inline bool
less_than<T, Compare>::operator()(T const& value) const
{
    return m_compare(value, m_pivot);
}

template <typename T, typename Compare>
inline
greater_than<T, Compare>::greater_than(T const& pivot, Compare compare)
    : m_pivot(pivot), m_compare(compare)
{
}

template <typename T, typename Compare>
inline bool
greater_than<T, Compare>::operator()(T const& value) const
{
    return m_compare(value, m_pivot);
}

template <typename T>
inline
equal_to<T>::equal_to(T const& pivot)
    : m_pivot(pivot)
{
}

template <typename T>
template <typename U>
inline bool
equal_to<T>::operator()(U const& value) const
{
    return std::equal_to<T>()(value, m_pivot);
}

} /* namespace stdc */

#endif /* __STD_COMPLEMENT_FUNCTIONAL_IMPL */
