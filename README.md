# C++ STL Complement
A few goodies I wish were part of the Standard Template Library. It is not
intended to contain complex algorithms that would be candidates for
[Boost](http://www.boost.org/), just small variations of what's already
available.

## Example
Although C++14 introduced a `constexpr` version of the `operator()` in
[`std::less`](http://en.cppreference.com/w/cpp/utility/functional/less), the
[`is_sorted`](http://en.cppreference.com/w/cpp/algorithm/is_sorted) algorithm
cannot be used at compile time. In this library, an extension is provided that
works at compile time, provided that the compare object is `constexpr` as well.

## Conventions
The namespace used for all utilities here is `stdc`, which keeps it short and
reminds of the complement nature to the `std` namespace.

## License
MIT License, if only in the hope that somebody will actually use this.
