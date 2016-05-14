/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#include <algorithm>
#include <sstream>

#include "Relation.h"
#include "lifemaker/tools/StringTools.h"
 
namespace lifemaker
{

Relation
::Relation():
    _id(0), _parents({}), _children({})
{
    // Nothing else.
}

Relation
::Relation(int id, std::vector<int> const & parents,
           std::vector<int> const & children) :
    _id(id), _parents(parents), _children(children)
{
    // Nothing else.
}

Relation
::Relation(Relation const& other) :
    _id(other.get_id()), _parents(other._parents), _children(other._children)
{
    // Nothing else.
}

Relation
::~Relation()
{
    // Nothing to do.
}

bool 
Relation
::operator==(Relation const & other) const
{
    return (this->_id == other.get_id());
}

bool 
Relation
::operator!=(Relation const & other) const
{
    return (this->_id != other.get_id());
}

int 
Relation
::get_id() const
{
    return this->_id;
}

std::vector<int> const &
Relation
::get_parents() const
{
    return this->_parents;
}

void 
Relation
::set_parents(std::vector<int> const & parents)
{
    this->_parents = parents;
}

std::vector<int> const &
Relation
::get_children() const
{
    return this->_children;
}

void 
Relation
::set_children(std::vector<int> const & children)
{
    this->_children = children;
}

std::string
Relation
::print() const
{
    std::stringstream stream;
    stream << "Relation ID:" << this->_id << " Parents:{";

    for (auto parent : this->_parents)
    {
        stream << parent << ", ";
    }
    stream << "} Enfants:{";
    for (auto child : this->_children)
    {
        stream << child << ", ";
    }
    stream << "}";

    // remove ',' at the end
    std::string text = stream.str();
    tools::string::replace(text, ", }", "}");

    return text;
}

} // namespace lifemaker
