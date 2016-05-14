#ifndef _7eeac273_56b7_4a6b_9052_49a69de14927
#define _7eeac273_56b7_4a6b_9052_49a69de14927

#include <string>

namespace lifemaker
{

namespace tools
{

namespace string
{

std::string replace(std::string const & source, std::string const & from,
                    std::string const & to);

void replace(std::string & text, std::string const & from,
             std::string const & to);

} // namespace string

} // namespace tools

} // namespace lifemaker

#endif // _7eeac273_56b7_4a6b_9052_49a69de14927
