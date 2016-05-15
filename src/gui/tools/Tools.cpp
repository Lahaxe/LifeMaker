/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#include "Tools.h"

namespace lifemaker
{

namespace gui
{

namespace tools
{

double
compute_distance(QRect const & point_a, QRect const & point_b)
{
    return compute_distance(point_a.x(), point_a.y(), point_b.x(), point_b.y());
}

double
compute_distance(QPoint const & point_a, QPoint const & point_b)
{
    return compute_distance(point_a.x(), point_a.y(), point_b.x(), point_b.y());
}

double
compute_distance(int point_a_x, int point_a_y, int point_b_x, int point_b_y)
{
    double distance = (point_a_x - point_b_x) * (point_a_x - point_b_x) +
                      (point_a_y - point_b_y) * (point_a_y - point_b_y);
    distance = sqrt(distance);
    return distance;
}

} // namespace tools

} // namespace gui

} // namespace lifemaker
