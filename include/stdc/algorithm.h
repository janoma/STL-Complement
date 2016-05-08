#ifndef __STD_COMPLEMENT_ALGORITHM_H
#define __STD_COMPLEMENT_ALGORITHM_H

#include <functional>

namespace stdc
{

/*!
 * \brief Checks if the elements [first,second,rest...] are sorted in
 * non-descending order according to the Compare criteria, which defaults to
 * std::less.
 */
template <typename T, typename Compare = std::less<T>, typename... Rest>
constexpr bool is_sorted(T first, T second, Rest... rest);

} /* namespace stdc */

#include "bits/algorithm_impl.h"

#endif /* __STD_COMPLEMENT_ALGORITHM_H */
