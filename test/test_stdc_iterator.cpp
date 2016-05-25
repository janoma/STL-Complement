#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN STDC Iterator Test Suite

#include <boost/test/unit_test.hpp>

#include <deque>
#include <string>
#include <vector>

#include <stdc/iterator.h>

class Emplaceable
{
public:
    explicit
    Emplaceable(int n, std::string str, bool val)
        : mNumber(n), mString(str), mValue(val)
    {
    }

    int mNumber;
    std::string mString;
    bool mValue;
};

BOOST_AUTO_TEST_SUITE( STDC_Iterator_Test_Suite )

BOOST_AUTO_TEST_CASE( BackEmplacer )
{
    std::vector<Emplaceable> elements;
    auto emplacer = stdc::back_emplacer(elements);

    emplacer(10, "hello", true);

    BOOST_REQUIRE_EQUAL(elements.size(), 1u);
    BOOST_CHECK_EQUAL(elements.back().mNumber, 10);
    BOOST_CHECK_EQUAL(elements.back().mString, "hello");
    BOOST_CHECK_EQUAL(elements.back().mValue, true);

    emplacer(20, "goodbye", false);

    BOOST_REQUIRE_EQUAL(elements.size(), 2u);
    BOOST_CHECK_EQUAL(elements.back().mNumber, 20);
    BOOST_CHECK_EQUAL(elements.back().mString, "goodbye");
    BOOST_CHECK_EQUAL(elements.back().mValue, false);
}

BOOST_AUTO_TEST_CASE( FrontEmplacer )
{
    std::deque<Emplaceable> elements;
    auto emplacer = stdc::front_emplacer(elements);

    emplacer(10, "hello", true);

    BOOST_REQUIRE_EQUAL(elements.size(), 1u);
    BOOST_CHECK_EQUAL(elements.front().mNumber, 10);
    BOOST_CHECK_EQUAL(elements.front().mString, "hello");
    BOOST_CHECK_EQUAL(elements.front().mValue, true);

    emplacer(20, "goodbye", false);

    BOOST_REQUIRE_EQUAL(elements.size(), 2u);
    BOOST_CHECK_EQUAL(elements.front().mNumber, 20);
    BOOST_CHECK_EQUAL(elements.front().mString, "goodbye");
    BOOST_CHECK_EQUAL(elements.front().mValue, false);
}

BOOST_AUTO_TEST_SUITE_END( /* STDC_Iterator_Test_Suite */ )
