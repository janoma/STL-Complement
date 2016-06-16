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

#ifndef __STD_COMPLEMENT_DYNAMIC_ARRAY_IMPL
#define __STD_COMPLEMENT_DYNAMIC_ARRAY_IMPL

#include <stdexcept>

#include "../dynamic_array.h"

namespace stdc
{

template <typename T>
inline auto
dynamic_array<T>::operator[](size_type pos) -> reference
{
    if (m_container.size() < pos)
    {
        m_container.resize(next_size(pos));
    }

    return m_container[pos];
}

template <typename T>
inline auto
dynamic_array<T>::operator[](size_type pos) const -> const_reference
{
    if (not (pos < m_container.size()))
    {
        throw std::out_of_range("Out-of-range access in dynamic_array");
    }

    return m_container[pos];
}

template <typename T>
inline auto
dynamic_array<T>::size() const -> size_type
{
    return m_container.size();
}

template <typename T>
inline T*
dynamic_array<T>::data()
{
    return m_container.data();
}

template <typename T>
inline T const*
dynamic_array<T>::data() const
{
    return m_container.data();
}

template <typename T>
inline auto
dynamic_array<T>::next_size(size_type expected_pos) -> size_type
{
    return 2 * (expected_pos + 1);
}

} /* namespace stdc */

#endif /* __STD_COMPLEMENT_DYNAMIC_ARRAY_IMPL */
