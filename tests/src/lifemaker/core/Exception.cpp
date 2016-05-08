/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#define BOOST_TEST_MODULE ModuleException
#include <boost/test/unit_test.hpp>

#include "lifemaker/core/Exception.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Constructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    lifemaker::Exception * exception = new lifemaker::Exception();

    BOOST_REQUIRE(exception != nullptr);

    delete exception;
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Throw exception
 */
BOOST_AUTO_TEST_CASE(ThrowException)
{
    bool isthrow = false;

    try
    {
        throw lifemaker::Exception("MyText");
    }
    catch (lifemaker::Exception& exception)
    {
        BOOST_CHECK_EQUAL(exception.what(), "MyText");
        isthrow = true;
    }

    BOOST_REQUIRE(isthrow);
}
