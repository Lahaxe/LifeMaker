#include <cstdlib>
#include <sstream>

#include "lifemaker/core/LMController.h"
#include "lifemaker/core/Logger.h"

int main(int argc, char *argv[])
{
#ifdef USE_LOG4CPP
    lifemaker::initialize_logger("DEBUG");
#else
    qSetMessagePattern("%{file}(%{line}): %{message}");
#endif

    LOGGER_INFO << "***** Start merge_element *****";

    auto controller = lifemaker::LMController::get_instance();

    std::vector<int> parents;
    for (int i = 1; i < argc; ++i)
    {
        parents.push_back(stoi(std::string(argv[i])));
    }

    auto relation = new lifemaker::Relation(0, parents, {});

    LOGGER_INFO << "Try to merge " << relation->print();

    if (controller.merge_elements(relation))
    {
        std::stringstream stream;
        stream << "create children: ";
        for (auto child : relation->get_children())
        {
            stream << controller.get_dictionary()->get_element(child).print()
                   << " ";
        }

        LOGGER_INFO << stream.str();
    }
    else
    {
        LOGGER_ERROR << "Cannot merge elements";
    }

    LOGGER_INFO << "***** Stop merge_element *****";
    return EXIT_SUCCESS;
}
