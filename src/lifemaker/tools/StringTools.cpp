#include "StringTools.h"

namespace lifemaker
{

namespace tools
{

namespace string
{

std::string
replace(std::string const & source, std::string const & from,
        std::string const & to)
{
    std::string text = source;
    replace(text, from, to);
    return text;
}

void
replace(std::string & text, std::string const & from, std::string const & to)
{
    auto pos = text.find(from);
    while (pos != std::string::npos)
    {
        text.replace(pos, from.size(), to);
        pos = text.find(from);
    }
}

} // namespace string

} // namespace tools

} // namespace lifemaker
