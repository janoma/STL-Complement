# C++ STL Complement
A few goodies I wish were part of the Standard Template Library. It is not
intended to contain complex algorithms that would be candidates for
[Boost](http://www.boost.org/), just small variations of what's already
available.

The namespace used for all utilities here is `stdc`, which keeps it short and
reminds of the complement nature to the `std` namespace.

## Example
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
