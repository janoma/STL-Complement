#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN STDC Functional Test Suite

#include <boost/test/unit_test.hpp>

#include <stdc/functional.h>

BOOST_AUTO_TEST_SUITE( STDC_Functional_Test_Suite )

BOOST_AUTO_TEST_CASE( Less_Test_Cases )
{
    static_assert(stdc::less<int>()(0, 1), "");

    auto less = stdc::less<int>();

    BOOST_CHECK(less(0, 1));
    BOOST_CHECK(less(-1, 1));
    BOOST_CHECK(! less(1, 0));
    BOOST_CHECK(! less(1, -1));
}

BOOST_AUTO_TEST_CASE( Greater_Test_Cases )
{
    static_assert(stdc::greater<int>()(1, 0), "");

    auto greater = stdc::greater<int>();

    BOOST_CHECK(greater(1, 0));
    BOOST_CHECK(greater(1, -1));
    BOOST_CHECK(! greater(0, 1));
    BOOST_CHECK(! greater(-1, 1));
}

BOOST_AUTO_TEST_SUITE_END( /* STDC_Functional_Test_Suite */ )
