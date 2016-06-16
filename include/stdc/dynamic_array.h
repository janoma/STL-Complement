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

#ifndef __STD_COMPLEMENT_DYNAMIC_ARRAY_H
#define __STD_COMPLEMENT_DYNAMIC_ARRAY_H

#include <vector>

namespace stdc
{

template <typename T>
class dynamic_array
{
    using Container = std::vector<T>;

public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = value_type const&;
    using size_type = typename Container::size_type;

    dynamic_array() = default;

    reference operator[](size_type pos);

    const_reference operator[](size_type pos) const;

    size_type size() const;

    T* data();

    T const* data() const;

private:
    size_type next_size(size_type expected_pos);

    Container m_container;
};

} /* namespace stdc */

#include "bits/dynamic_array_impl.h"

#endif /* __STD_COMPLEMENT_DYNAMIC_ARRAY_H */
