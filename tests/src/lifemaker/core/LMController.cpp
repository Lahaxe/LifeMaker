/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#define BOOST_TEST_MODULE ModuleLMController
#include <boost/test/unit_test.hpp>

#include "lifemaker/core/LMController.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Constructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto controller = lifemaker::LMController::get_instance();
    lifemaker::LMController::delete_instance();
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Accessor
 */
BOOST_AUTO_TEST_CASE(Accessor)
{
    auto controller = lifemaker::LMController::get_instance();

    BOOST_REQUIRE(controller.get_dictionary() != nullptr);
    BOOST_REQUIRE(controller.get_relations() != nullptr);

    lifemaker::LMController::delete_instance();
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Merge elements
 */
BOOST_AUTO_TEST_CASE(MergeElements)
{
    auto controller = lifemaker::LMController::get_instance();

    lifemaker::Relation relation1(0, {3, 4});
    BOOST_CHECK(controller.merge_elements(&relation1));

    lifemaker::Relation relation2(0, {0, 1});
    BOOST_CHECK(!controller.merge_elements(&relation2));

    lifemaker::LMController::delete_instance();
}
