/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#ifndef _1d7c1f1e_0aa1_4385_b1f3_0b7cd7a44789
#define _1d7c1f1e_0aa1_4385_b1f3_0b7cd7a44789

#include <exception>
#include <string>

namespace lifemaker
{

/// @brief Base class for lifemaker exceptions.
class Exception: public std::exception
{
public: 
    /// @brief Message string constructor.
    Exception(std::string const & message = "");

    /// @brief Destructor.
    virtual ~Exception() throw();
    
    /// @brief Return the reason for the exception.
    virtual const char* what() const throw();

protected:
    std::string _message;
	
};

} // namespace lifemaker

#endif // _1d7c1f1e_0aa1_4385_b1f3_0b7cd7a44789
