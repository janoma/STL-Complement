# C++ STL Complement
A few goodies I wish were part of the Standard Template Library. It is not
intended to contain complex algorithms that would be candidates for
[Boost](http://www.boost.org/), just small variations of what's already
available.

The namespace used for all utilities here is `stdc`, which keeps it short and
reminds of the complement nature to the `std` namespace.

## Example: `constexpr is_sorted`
Although C++14 introduced a `constexpr` version of the `operator()` in
[`std::less`](http://en.cppreference.com/w/cpp/utility/functional/less), the
[`is_sorted`](http://en.cppreference.com/w/cpp/algorithm/is_sorted) algorithm
cannot be used at compile time. In this library, an extension is provided that
works at compile time, provided that the compare object is `constexpr` as well.

```
#include <stdc/algorithm.h>

/*! A toy example. */
static_assert(stdc::is_sorted(1, 2, 3, 4), "");
static_assert(! stdc::is_sorted(1, 3, 2, 4), "");
```

## Example: the `erase_remove` idiom
If you have ever used `std::remove` or `std::remove_if` in some `Container` followed by `Container::resize` and wished you could do it in one line, here is an alternative.

```
#include <stdc/algorithm.h>

std::vector<int> numbers {0, 1, 2, 3, 2, 4, 2, 5};
stdc::erase_remove(numbers, 2);
/*! numbers is now {0, 1, 3, 4, 5} */
```

Following the names used in the STL, `remove` receives a `const&` to an element, while `remove_if` receives a unary predicate.

```
#include <stdc/algorithm.h>

std::vector<int> numbers {0, 1, 2, 3, 2, 4, 2, 5};
stdc::erase_remove_if(numbers, [](int const& i){ return i % 2 == 0; });
/*! numbers is now {1, 3, 5} */
```

## Installation
This is a header-only library, so just copy or link the `include` directory to
an appropriate location, and remember to add it to your `-I` options when
compiling.

Most utilities work with C++11, though a few things might require C++14, which
is why I use it by default in the unit tests.

There are some unit tests and a `CMakeLists` settings file. Still, I had to
tweak my settings a lot and I'm a newbie in `cmake`, which means you will
probably have to tweak the settings too until somebody with more experience
helps me make the settings more generic.

## License
MIT License, if only in the hope that somebody will actually use this.
