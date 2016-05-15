/********************************************************************************
 * LifeMaker - Copyright (C) Lahaxe Romain
 *******************************************************************************/

#ifndef _9071d3df_4874_4fa1_b68e_21ead3eb915d
#define _9071d3df_4874_4fa1_b68e_21ead3eb915d

#include <QPoint>
#include <QRect>

namespace lifemaker
{

namespace gui
{

namespace tools
{

double compute_distance(QRect const & point_a, QRect const & point_b);

double compute_distance(QPoint const & point_a, QPoint const & point_b);

double compute_distance(int point_a_x, int point_a_y,
                        int point_b_x, int point_b_y);

} // namespace tools

} // namespace gui

} // namespace lifemaker

#endif // _9071d3df_4874_4fa1_b68e_21ead3eb915d

