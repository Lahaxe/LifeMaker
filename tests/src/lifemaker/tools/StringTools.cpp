/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#define BOOST_TEST_MODULE ModuleStringTools
#include <boost/test/unit_test.hpp>

#include "lifemaker/tools/StringTools.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: function Replace
 */
BOOST_AUTO_TEST_CASE(ReplaceFunction)
{
    std::string const text = "abc123abc123";
    std::string text2 = lifemaker::tools::string::replace(text, "abc", "DEF");

    BOOST_CHECK_EQUAL(text, "abc123abc123");
    BOOST_CHECK_EQUAL(text2, "DEF123DEF123");

    lifemaker::tools::string::replace(text2, "123", "-");

    BOOST_CHECK_EQUAL(text2, "DEF-DEF-");
}
