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

#ifndef __STD_COMPLEMENT_ITERATOR_H
#define __STD_COMPLEMENT_ITERATOR_H

namespace stdc
{

/*!
 * \brief Function object that calls emplace_back() on the container for which
 * it was constructed, std::forward'ing the arguments to the container.
 *
 * \details The motivation is the usage of std::back_inserter in algorithms that
 * call push_back on an unncessary copy of an element. For example, if the
 * algorithm instantiates T t(args...), and then calls a back_inserter with t,
 * then the copy can be avoided by calling stdc::back_emplacer with args..., in
 * which case the element will be constructed in-place.
 *
 * \note This is not a replacement for std::back_inserter, as it is not even an
 * iterator.
 */
template <typename Container>
class back_emplacer
{
public:
    explicit back_emplacer(Container& container);

    template <typename... Args>
    back_emplacer<Container>& operator()(Args&&...);

private:
    Container* mContainer;
};

/*!
 * \brief Function object that calls emplace_front() on the container for which
 * it was constructed, std::forward'ing the arguments to the container.
 *
 * \details The motivation is the usage of std::front_inserter in algorithms that
 * call push_front on an unncessary copy of an element. For example, if the
 * algorithm instantiates T t(args...), and then calls a front_inserter with t,
 * then the copy can be avoided by calling stdc::front_emplacer with args..., in
 * which case the element will be constructed in-place.
 *
 * \note This is not a replacement for std::front_inserter, as it is not even an
 * iterator.
 */
template <typename Container>
class front_emplacer
{
public:
    explicit front_emplacer(Container& container);

    template <typename... Args>
    front_emplacer<Container>& operator()(Args&&...);

private:
    Container* mContainer;
};

} /* namespace stdc */

#include "bits/iterator_impl.h"

#endif /* __STD_COMPLEMENT_ITERATOR_H */
