/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#define BOOST_TEST_MODULE ModuleRelations
#include <boost/test/unit_test.hpp>

#include "lifemaker/core/Exception.h"
#include "lifemaker/objects/Relations.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Constructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    // Constructor
    auto relations = lifemaker::Relations::New();
    BOOST_REQUIRE(relations != nullptr);

    // Default values
    BOOST_CHECK(relations->get_relations().empty());
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Insert relation
 */
BOOST_AUTO_TEST_CASE(InsertRelation)
{
    // Constructor
    auto relations = lifemaker::Relations::New();

    BOOST_CHECK(!relations->contains_relation(lifemaker::Relation(1)));

    relations->insert_relation(lifemaker::Relation(1));
    BOOST_CHECK(!relations->get_relations().empty());

    BOOST_CHECK(relations->contains_relation(lifemaker::Relation(1)));
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Contains relation
 */
BOOST_AUTO_TEST_CASE(ContainsRelation)
{
    // Constructor
    auto relations = lifemaker::Relations::New();

    BOOST_CHECK(!relations->contains_relation(lifemaker::Relation(1)));
    BOOST_CHECK(!relations->contains_relation(1));

    relations->insert_relation(lifemaker::Relation(1));
    BOOST_CHECK(!relations->get_relations().empty());

    BOOST_CHECK(relations->contains_relation(lifemaker::Relation(1)));
    BOOST_CHECK(relations->contains_relation(1));
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Retrieve relations
 */
BOOST_AUTO_TEST_CASE(GetRelations)
{
    // Constructor
    auto relations = lifemaker::Relations::New();
    relations->insert_relation(lifemaker::Relation(1));

    auto all_relations = relations->get_relations();
    BOOST_CHECK_EQUAL(all_relations.size(), 1);
    BOOST_CHECK_EQUAL(all_relations.at(0).get_id(), 1);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Initialize
 */
BOOST_AUTO_TEST_CASE(Initialize)
{
    // Constructor
    auto relations = lifemaker::Relations::New();
    relations->initialize();
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Get Relation From Parents
 */
BOOST_AUTO_TEST_CASE(GetFromParents)
{
    // Constructor
    auto relations = lifemaker::Relations::New();
    relations->insert_relation(lifemaker::Relation(1, {2, 3}, {4, 5}));

    lifemaker::Relation* relation = relations->get_relation_from_parents({2, 3});
    BOOST_CHECK(relation != nullptr);
    BOOST_CHECK_EQUAL(relation->get_children().size(), 2);
    BOOST_CHECK_EQUAL(relation->get_children().at(0), 4);
    BOOST_CHECK_EQUAL(relation->get_children().at(1), 5);
}

/******************************* TEST Error ************************************/
/**
 * Error test case: Relation already exist
 */
BOOST_AUTO_TEST_CASE(RelationAlreadyInserted)
{
    // Constructor
    auto relations = lifemaker::Relations::New();
    relations->insert_relation(lifemaker::Relation(1));

    BOOST_REQUIRE_THROW(relations->insert_relation(lifemaker::Relation(1)),
                        lifemaker::Exception);
}

/******************************* TEST Error ************************************/
/**
 * Error test case: Get Unknown Relation
 */
BOOST_AUTO_TEST_CASE(GetUnknownRelation)
{
    // Constructor
    auto relations = lifemaker::Relations::New();
    relations->insert_relation(lifemaker::Relation(1, {1}, {2}));

    BOOST_REQUIRE_THROW(relations->get_relation_from_parents({2}),
                        lifemaker::Exception);
}
