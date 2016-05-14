/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#include "Dictionary.h"
#include "lifemaker/core/Exception.h"
 
namespace lifemaker
{

Dictionary::Pointer
Dictionary
::New()
{
    return Pointer(new Self());
}

Dictionary
::Dictionary():
    _elements({})
{
    // Nothing else.
}

Dictionary
::~Dictionary()
{
    // Nothing to do.
}

std::map<int, Element> const &
Dictionary
::get_elements() const
{
    return this->_elements;
}

bool 
Dictionary
::contains_element(int element_id) const
{
    return this->_elements.find(element_id) != this->_elements.end();
}

void 
Dictionary
::insert_element(Element const & element)
{
    if (this->contains_element(element.get_id()))
    {
        throw Exception("Element ID already exists");
    }

    this->_elements.insert(std::pair<int, Element>(element.get_id(), element));
}

Element const &
Dictionary
::get_element(int element_id)
{
    if (!this->contains_element(element_id))
    {
        throw Exception("Unknown element");
    }

    return this->_elements[element_id];
}

void 
Dictionary
::initialize()
{
    this->insert_element(Element(1, "air", "", "", true));
    this->insert_element(Element(2, "eau", "", "", true));
    this->insert_element(Element(3, "feu", "", "", true));
    this->insert_element(Element(4, "terre", "", "", true));

    this->insert_element(Element(1001, "lave", "", "", false));
}

} // namespace lifemaker
