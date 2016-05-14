/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#include <algorithm>
#include <sstream>

#include "Relations.h"
#include "lifemaker/core/Exception.h"
#include "lifemaker/core/Logger.h"

namespace lifemaker
{

Relations::Pointer
Relations
::New()
{
    return Pointer(new Self());
}

Relations
::Relations():
    _relations({})
{
    // Nothing to do.
}

Relations
::~Relations()
{
    // Nothing to do.
}

std::vector<Relation> const &
Relations
::get_relations() const
{
    return this->_relations;
}

bool
Relations
::contains_relation(int relation_id) const
{
    return this->contains_relation(Relation(relation_id));
}

bool
Relations
::contains_relation(Relation const & relation) const
{
    return std::find(this->_relations.begin(),
                     this->_relations.end(),
                     relation) != this->_relations.end();
}

void
Relations
::insert_relation(Relation const & relation)
{
    if (this->contains_relation(relation))
    {
        std::stringstream error;
        error << "Relation id " << relation.get_id() << " already exists";
        throw Exception(error.str());
    }

    this->_relations.push_back(relation);
}

void
Relations
::initialize()
{
    this->insert_relation(Relation(1, {3, 4}, {1001}));
}

Relation *
Relations
::get_relation_from_parents(std::vector<int> const & parents) const
{
    for (auto const relation : this->_relations)
    {
        if (relation.get_parents() == parents)
        {
            // find
            return new Relation(relation);
        }
    }

    // not find
    throw Exception("Unknown relation");
}

} // namespace lifemaker
