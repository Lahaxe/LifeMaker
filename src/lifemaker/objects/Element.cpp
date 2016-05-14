/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#include <sstream>

#include "Element.h"
 
namespace lifemaker
{

Element
::Element() :
    _id(0), _name(""), _image(""), _information(""), _discovered(false)
{
    // Nothing else.
}

Element
::Element(int id, std::string const & name, std::string const & image, 
          std::string const & information, bool discovered) :
    _id(id), _name(name), _image(image), _information(information),
    _discovered(discovered)
{
    // Nothing else.
}

Element
::Element(Element const& other) :
    _id(other.get_id()), _name(other.get_name()), _image(other.get_image()),
    _information(other.get_information()), _discovered(other.is_discovered())
{
    // Nothing else.
}

Element
::~Element()
{
    // Nothing to do.
}

bool 
Element
::operator==(Element const & other) const
{
    return (this->_id == other.get_id());
}

bool 
Element
::operator!=(Element const & other) const
{
    return (this->_id != other.get_id());
}

int 
Element
::get_id() const
{
    return this->_id;
}

std::string 
Element
::get_name() const
{
    return this->_name;
}

void 
Element
::set_name(std::string const & name)
{
    this->_name = name;
}

std::string 
Element
::get_image() const
{
    return this->_image;
}

void 
Element
::set_image(std::string const & image)
{
    this->_image = image;
}

std::string 
Element
::get_information() const
{
    return this->_information;
}

void 
Element
::set_information(std::string const & information)
{
	this->_information = information;
}

bool 
Element
::is_discovered() const
{
	return this->_discovered;
}

void 
Element
::set_discovered(bool discovered)
{
    this->_discovered = discovered;
}

std::string
Element
::print() const
{
    std::stringstream stream;
    stream << "Element ID:" << this->_id << " Name:" << this->_name;
    return stream.str();
}
	
} // namespace lifemaker
