/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#define BOOST_TEST_MODULE ModuleRelation
#include <boost/test/unit_test.hpp>

#include "lifemaker/objects/Relation.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Constructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    {
    // Constructor
    lifemaker::Relation * relation = new lifemaker::Relation();
    BOOST_REQUIRE(relation != nullptr);

    // Default values:
    BOOST_CHECK_EQUAL(relation->get_id(), 0);
    BOOST_CHECK(relation->get_parents().empty());
    BOOST_CHECK(relation->get_children().empty());

    // Destructor
    delete relation;
    }

    {
    // Constructor
    lifemaker::Relation * relation = new lifemaker::Relation(1);
    BOOST_REQUIRE(relation != nullptr);

    // Default values:
    BOOST_CHECK_EQUAL(relation->get_id(), 1);
    BOOST_CHECK(relation->get_parents().empty());
    BOOST_CHECK(relation->get_children().empty());

    // Destructor
    delete relation;
    }

    {
    // Constructor
    lifemaker::Relation * relation = new lifemaker::Relation(1, {2}, {3});
    BOOST_REQUIRE(relation != nullptr);

    // Check values:
    BOOST_CHECK_EQUAL(relation->get_id(), 1);
    BOOST_CHECK_EQUAL(relation->get_parents().size(), 1);
    BOOST_CHECK_EQUAL(relation->get_children().size(), 1);
    BOOST_CHECK_EQUAL(relation->get_parents().at(0), 2);
    BOOST_CHECK_EQUAL(relation->get_children().at(0), 3);

    // Destructor
    delete relation;
    }
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Copy constructor
 */
BOOST_AUTO_TEST_CASE(CopyConstructor)
{
    // Element to copy
    lifemaker::Relation relation(1, {2}, {3});

    // Copy Constructor
    lifemaker::Relation * copyrelation = new lifemaker::Relation(relation);
    BOOST_REQUIRE(copyrelation != nullptr);

    // Check values:
    BOOST_CHECK_EQUAL(copyrelation->get_id(), 1);
    BOOST_CHECK_EQUAL(copyrelation->get_parents().size(), 1);
    BOOST_CHECK_EQUAL(copyrelation->get_children().size(), 1);
    BOOST_CHECK_EQUAL(copyrelation->get_parents().at(0), 2);
    BOOST_CHECK_EQUAL(copyrelation->get_children().at(0), 3);

    // Destructor
    delete copyrelation;
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: operator == and !=
 */
BOOST_AUTO_TEST_CASE(OperatorEqual)
{
    lifemaker::Relation relation1(1, {2}, {3});
    lifemaker::Relation relation2(1, {2}, {3});
    lifemaker::Relation relation3(2, {2}, {3});
    lifemaker::Relation relation4(1, {4}, {5});

    BOOST_CHECK(relation1 == relation2);
    BOOST_CHECK(relation2 != relation3);
    BOOST_CHECK(relation1 == relation4);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Accessors
 */
BOOST_AUTO_TEST_CASE(Accessors)
{
    lifemaker::Relation relation(1);

    relation.set_parents({2});
    relation.set_children({3});

    // Check values
    BOOST_CHECK_EQUAL(relation.get_id(), 1);
    BOOST_CHECK_EQUAL(relation.get_parents().size(), 1);
    BOOST_CHECK_EQUAL(relation.get_children().size(), 1);
    BOOST_CHECK_EQUAL(relation.get_parents().at(0), 2);
    BOOST_CHECK_EQUAL(relation.get_children().at(0), 3);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Print function
 */
BOOST_AUTO_TEST_CASE(PrintFunction)
{
    lifemaker::Relation relation(1, {2, 3}, {4, 5});
    BOOST_CHECK_EQUAL(relation.print(),
                      "Relation ID:1 Parents:{2, 3} Enfants:{4, 5}");
}
