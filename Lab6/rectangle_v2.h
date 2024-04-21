#include "rectangle.h"

class RectangleV2 : public Rectangle
{
public:
	RectangleV2(int x, int y, int w, int h);
	RectangleV2(Point center_point, int w, int h);
	void UpdateCenter(int new_x, int new_y);
	void UpdateCenter(Point center_point);
	void ShiftCenter(int delta_x, int delta_y);
	void ResetPosition();
private:
	Point center_saved;
	int width_saved, height_saved;
};