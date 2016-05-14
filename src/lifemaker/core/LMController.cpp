/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#include "LMController.h"

#include "Logger.h"

namespace lifemaker
{

LMController * LMController::_instance = NULL;

LMController &
LMController
::get_instance()
{
    if(LMController::_instance == NULL)
    {
        LMController::_instance = new LMController();
    }
    return *LMController::_instance;
}

void LMController
::delete_instance()
{
    if(LMController::_instance != NULL)
    {
        delete LMController::_instance;
    }
    LMController::_instance = NULL;
}

LMController
::LMController() :
    _dictionary(Dictionary::New()), _relations(Relations::New())
{
    _dictionary->initialize();
    _relations->initialize();
}

LMController
::~LMController()
{
    // Nothing to do
}

Dictionary::Pointer
LMController
::get_dictionary() const
{
    return this->_dictionary;
}

Relations::Pointer
LMController
::get_relations() const
{
    return this->_relations;
}

bool
LMController
::merge_elements(Relation * relation) const
{
    // Clear Children
    relation->set_children({});

    // Get relation (if existed)
    try
    {
        auto findedrelation = this->_relations->get_relation_from_parents(
                    relation->get_parents());

        relation->set_children(findedrelation->get_children());

        delete findedrelation;
    }
    catch (Exception const & exc)
    {
        LOGGER_ERROR << exc.what();
        // Not merged
        return false;
    }

    return true;
}

} // namespace lifemaker

