# C++ STL Complement [![Build Status](https://travis-ci.org/janoma/STL-Complement.svg?branch=master)](https://travis-ci.org/janoma/STL-Complement) [![Documentation Status](https://readthedocs.org/projects/stl-complement/badge/?version=latest)](http://stl-complement.readthedocs.io/en/latest/?badge=latest)
A few **small** goodies I wish were part of the Standard Template Library. It is not
intended to contain complex algorithms that would be candidates for
[Boost](http://www.boost.org/) or other libraries, just small variations, adaptations
and idioms constructed over what's already available.

The namespace used for all utilities here is `stdc`, which keeps it short and
reminds of the _complement_ nature to the `std` namespace.

## Example: `constexpr is_sorted`
Although C++14 introduced a `constexpr` version of the `operator()` in
[`std::less`](http://en.cppreference.com/w/cpp/utility/functional/less), the
[`is_sorted`](http://en.cppreference.com/w/cpp/algorithm/is_sorted) algorithm
cannot be used at compile time. In this library, an extension is provided that
works at compile time, provided that the compare object is `constexpr` as well.

```cpp
#include <stdc/algorithm.h>

/*! A toy example. */
static_assert(stdc::is_sorted(1, 2, 3, 4), "");
static_assert(! stdc::is_sorted(1, 3, 2, 4), "");
```

For C++11 users, a `constexpr` version of `less` is provided as part of this
library.

```cpp
#include <stdc/functional.h>

constexpr bool smaller = stdc::less<int>()(10, 20); /*! true */
```

## Example: the `erase_remove` idiom
If you have ever used `std::remove` or `std::remove_if` in some `Container`
followed by `Container::resize` and wished you could do it in one line, here
is an alternative.

```cpp
#include <stdc/algorithm.h>

std::vector<int> numbers {0, 1, 2, 3, 2, 4, 2, 5};
stdc::erase_remove(numbers, 2);
/*! numbers is now {0, 1, 3, 4, 5} */
```

Following the names used in the STL, `stdc::remove` receives a `const&` to
an element, while `stdc::remove_if` receives a unary predicate.

```cpp
#include <stdc/algorithm.h>

std::vector<int> numbers {0, 1, 2, 3, 2, 4, 2, 5};
stdc::erase_remove_if(numbers, [](int const& i){ return i % 2 == 0; });
/*! numbers is now {1, 3, 5} */
```

## Installation
This is a header-only library, so just copy or link the `include` directory to
an appropriate location, and remember to add it to your `-I` options when
compiling.

You can run the unit tests by creating the Makefiles with CMake first. This
requires the [Boost Unit Test Framework](http://www.boost.org/doc/libs/1_56_0/libs/test/doc/html/utf.html).

```
$ git clone https://github.com/janoma/STL-Complement.git
$ cd STL-Complement
$ cmake .
$ make
$ make test
```

## License
MIT License, if only in the hope that somebody will actually use this.

[//]: # ( vim: set nofoldenable: )
