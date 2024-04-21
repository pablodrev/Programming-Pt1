#include "rectangle_v2.h"

RectangleV2::RectangleV2(int x, int y, int w, int h) : Rectangle::Rectangle(x, y, w, h)
{
	center_saved.x = x;
	center_saved.y = y;
	width_saved = w;
	height_saved = h;
}
RectangleV2::RectangleV2(Point center_point, int w, int h) : Rectangle::Rectangle(center_point, w, h)
{
	center_saved = center_point;
	width_saved = w;
	height_saved = h;
}
void RectangleV2::UpdateCenter(int new_x, int new_y)
{
	center.x = new_x;
	center.y = new_y;
}
void RectangleV2::UpdateCenter(Point center_point)
{
	center = center_point;
}
void RectangleV2::ShiftCenter(int delta_x, int delta_y)
{
	center.x += delta_x;
	center.y += delta_y;
}

void RectangleV2::ResetPosition()
{
	center = center_saved;
}
