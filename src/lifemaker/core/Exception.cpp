/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#include "Exception.h"

namespace lifemaker
{

Exception
::Exception(std::string const & message) : 
	_message(message)
{
    // Nothing else.
}

Exception
::~Exception() throw()
{
    // Nothing to do.
}

char const *
Exception
::what() const throw()
{
    return this->_message.c_str();
}

} // namespace lifemaker
