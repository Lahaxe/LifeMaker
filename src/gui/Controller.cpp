#include "Controller.h"

#include "lifemaker/core/Logger.h"
#include "tools/Tools.h"

namespace lifemaker
{

namespace gui
{

bool check_proximity(const QWidget *container, ElementUI const * element, QVector<ElementUI *> &objects)
{
    bool return_ = false;

    for (auto item : container->children())
    {
        ElementUI* currentelement = dynamic_cast<ElementUI*>(item);

        if (currentelement != nullptr && currentelement != element)
        {
            double distance = tools::compute_distance(currentelement->pos(),
                                                      element->pos());

#ifdef ANDROID
            if (distance < 250)
#else
            if (distance < 80)
#endif
            {
                objects.push_back(currentelement);
                return_ = true;
            }
        }
    }

    return return_;
}

} // namespace gui

} // namespace lifemaker
