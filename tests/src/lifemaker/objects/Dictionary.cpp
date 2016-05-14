/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#define BOOST_TEST_MODULE ModuleDictionary
#include <boost/test/unit_test.hpp>

#include "lifemaker/core/Exception.h"
#include "lifemaker/objects/Dictionary.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Constructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    // Constructor
    auto dictionary = lifemaker::Dictionary::New();
    BOOST_REQUIRE(dictionary != nullptr);

    // Default values
    BOOST_CHECK(dictionary->get_elements().empty());
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Insert element
 */
BOOST_AUTO_TEST_CASE(InsertElement)
{
    // Constructor
    auto dictionary = lifemaker::Dictionary::New();

    BOOST_CHECK(!dictionary->contains_element(1));

    dictionary->insert_element(lifemaker::Element(1));
    BOOST_CHECK(!dictionary->get_elements().empty());

    BOOST_CHECK(dictionary->contains_element(1));
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Retrieve element
 */
BOOST_AUTO_TEST_CASE(GetElement)
{
    // Constructor
    auto dictionary = lifemaker::Dictionary::New();
    dictionary->insert_element(lifemaker::Element(1));

    auto element = dictionary->get_element(1);
    BOOST_CHECK_EQUAL(element.get_id(), 1);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Initialize
 */
BOOST_AUTO_TEST_CASE(Initialize)
{
    // Constructor
    auto dictionary = lifemaker::Dictionary::New();
    dictionary->initialize();
}

/******************************* TEST Error ************************************/
/**
 * Error test case: Element already exist
 */
BOOST_AUTO_TEST_CASE(ElementAlreadyInserted)
{
    // Constructor
    auto dictionary = lifemaker::Dictionary::New();
    dictionary->insert_element(lifemaker::Element(1));

    BOOST_REQUIRE_THROW(dictionary->insert_element(lifemaker::Element(1)),
                        lifemaker::Exception);
}

/******************************* TEST Error ************************************/
/**
 * Error test case: Get Unknown Element
 */
BOOST_AUTO_TEST_CASE(GetUnknownElement)
{
    // Constructor
    auto dictionary = lifemaker::Dictionary::New();

    BOOST_REQUIRE_THROW(dictionary->get_element(1), lifemaker::Exception);
}
