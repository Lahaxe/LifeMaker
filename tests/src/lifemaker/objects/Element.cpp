/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#define BOOST_TEST_MODULE ModuleElement
#include <boost/test/unit_test.hpp>

#include "lifemaker/objects/Element.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Constructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    {
    // Constructor
    lifemaker::Element * element = new lifemaker::Element();
    BOOST_REQUIRE(element != nullptr);

    // Default values:
    BOOST_CHECK_EQUAL(element->get_id(), 0);
    BOOST_CHECK_EQUAL(element->get_name(), "");
    BOOST_CHECK_EQUAL(element->get_image(), "");
    BOOST_CHECK_EQUAL(element->get_information(), "");
    BOOST_CHECK_EQUAL(element->is_discovered(), false);

    // Destructor
    delete element;
    }

    {
    // Constructor
    lifemaker::Element * element = new lifemaker::Element(1);
    BOOST_REQUIRE(element != nullptr);

    // Default values:
    BOOST_CHECK_EQUAL(element->get_id(), 1);
    BOOST_CHECK_EQUAL(element->get_name(), "");
    BOOST_CHECK_EQUAL(element->get_image(), "");
    BOOST_CHECK_EQUAL(element->get_information(), "");
    BOOST_CHECK_EQUAL(element->is_discovered(), false);

    // Destructor
    delete element;
    }

    {
    // Constructor
    lifemaker::Element * element = new lifemaker::Element(1, "a", "b", "c", true);
    BOOST_REQUIRE(element != nullptr);

    // Check values:
    BOOST_CHECK_EQUAL(element->get_id(), 1);
    BOOST_CHECK_EQUAL(element->get_name(), "a");
    BOOST_CHECK_EQUAL(element->get_image(), "b");
    BOOST_CHECK_EQUAL(element->get_information(), "c");
    BOOST_CHECK_EQUAL(element->is_discovered(), true);

    // Destructor
    delete element;
    }
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Copy constructor
 */
BOOST_AUTO_TEST_CASE(CopyConstructor)
{
    // Element to copy
    lifemaker::Element element(1, "a", "b", "c", true);

    // Copy Constructor
    lifemaker::Element * copyelement = new lifemaker::Element(element);
    BOOST_REQUIRE(copyelement != nullptr);

    // Check values:
    BOOST_CHECK_EQUAL(copyelement->get_id(), 1);
    BOOST_CHECK_EQUAL(copyelement->get_name(), "a");
    BOOST_CHECK_EQUAL(copyelement->get_image(), "b");
    BOOST_CHECK_EQUAL(copyelement->get_information(), "c");
    BOOST_CHECK_EQUAL(copyelement->is_discovered(), true);

    // Destructor
    delete copyelement;
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: operator == and !=
 */
BOOST_AUTO_TEST_CASE(OperatorEqual)
{
    lifemaker::Element element1(1, "a", "b", "c", true);
    lifemaker::Element element2(1, "a", "b", "c", true);
    lifemaker::Element element3(2, "a", "b", "c", true);
    lifemaker::Element element4(1, "d", "b", "c", true);

    BOOST_CHECK(element1 == element2);
    BOOST_CHECK(element2 != element3);
    BOOST_CHECK(element1 == element4);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Accessors
 */
BOOST_AUTO_TEST_CASE(Accessors)
{
    lifemaker::Element element(1);

    element.set_name("a");
    element.set_image("b");
    element.set_information("c");
    element.set_discovered(true);

    // Check values
    BOOST_CHECK_EQUAL(element.get_id(), 1);
    BOOST_CHECK_EQUAL(element.get_name(), "a");
    BOOST_CHECK_EQUAL(element.get_image(), "b");
    BOOST_CHECK_EQUAL(element.get_information(), "c");
    BOOST_CHECK_EQUAL(element.is_discovered(), true);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Print function
 */
BOOST_AUTO_TEST_CASE(PrintFunction)
{
    lifemaker::Element element(1, "a", "b", "c", true);
    BOOST_CHECK_EQUAL(element.print(), "Element ID:1 Name:a");
}
