#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN STDC Test Suite

#include <boost/test/unit_test.hpp>

#include <cstdlib>
#include <deque>
#include <limits>
#include <vector>

#include <stdc/algorithm.h>

BOOST_AUTO_TEST_SUITE( STDC_Test_Suite )

BOOST_AUTO_TEST_SUITE( Algorithm_Test_Suite )

BOOST_AUTO_TEST_CASE( Is_Sorted_Unary_Test_Cases )
{
    /*! Note that all these is_sorted cases can be asserted at compile time
     * instead. I'll just leave one as example. */
    static_assert(stdc::is_sorted(-1), "");

    BOOST_CHECK(stdc::is_sorted(-1));
    BOOST_CHECK(stdc::is_sorted(0));
    BOOST_CHECK(stdc::is_sorted<std::uint32_t>(0));

    /*! Most vexing parse. Need two parentheses. */
    BOOST_CHECK((stdc::is_sorted<int, std::greater<int>>(0)));

    BOOST_CHECK(stdc::is_sorted(0L));
}

BOOST_AUTO_TEST_CASE( Is_Sorted_Nary_Test_Cases )
{
    BOOST_CHECK(stdc::is_sorted(0, 1));
    BOOST_CHECK(stdc::is_sorted(-100, 0, 1, 2, 1000));
    BOOST_CHECK(stdc::is_sorted(0L, 1L));
    BOOST_CHECK(stdc::is_sorted(0U, 1U));
    BOOST_CHECK(stdc::is_sorted(0, 1, 2, 10, 100));
    BOOST_CHECK(stdc::is_sorted<std::uint32_t>(0, 1, 2, 10, 100));
    BOOST_CHECK(stdc::is_sorted<char>('A', 'H', 'I', 'J', 'U', 'n'));

    /*! Most vexing parse. Need two parentheses. */
    BOOST_CHECK((stdc::is_sorted<std::uint32_t, std::greater<std::uint32_t>>(100, 10, 2, 1, 0)));

    BOOST_CHECK((stdc::is_sorted<double>(0L, std::numeric_limits<double>::min(), 1L, std::numeric_limits<double>::max())));
}

BOOST_AUTO_TEST_CASE( Erase_Remove )
{
    std::vector<int> numbers {1, 2, 5, 5, 4, 5, 9, 8, 13, 5, 20, 5};
    auto end = stdc::erase_remove(numbers, 5);
    BOOST_CHECK_EQUAL(numbers.size(), 7U);
    BOOST_CHECK(end == std::end(numbers));
}

BOOST_AUTO_TEST_CASE( Erase_Remove_If )
{
    std::vector<int> numbers {1, 2, 5, 5, 4, 5, 9, 8, 13, 5, 20, 5};
    auto end = stdc::erase_remove_if(numbers, [](auto const& val){ return val % 2 == 0; });
    BOOST_CHECK_EQUAL(numbers.size(), 8U);
    BOOST_REQUIRE(end == std::end(numbers));

    std::vector<int> const expected {1, 5, 5, 5, 9, 13, 5, 5};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(numbers), end, std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_SUITE_END( /* Algorithm_Test_Suite */ )

BOOST_AUTO_TEST_SUITE_END( /* STDC_Test_Suite */ )
