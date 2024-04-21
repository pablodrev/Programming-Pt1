#include "rectangle.h"

Point::Point()
{
	x = 0;
	y = 0;
}
Point::Point(float point_x, float point_y)
{
	x = point_x;
	y = point_y;
}

Rectangle::Rectangle(int x, int y, int w, int h)
{
	center.x = x;
	center.y = y;
	width = w;
	height = h;
}

Rectangle::Rectangle(Point center_point, int w, int h)
{
	center = center_point;
	width = w;
	height = h;
}

Rectangle::~Rectangle()
{
	delete[] coordinates;
}

void Rectangle::Print()
{
	std::cout << "Координаты центра: (" << center.x << "," << center.y << ")" << std::endl;
	std::cout << "Ширина: " << width << std::endl;
	std::cout << "Длина: " << height << std::endl;
}
int Rectangle::Perimeter()
{
	return width * 2 + height * 2;
}
Point* Rectangle::VertexCoordinates()
{
	float w2 = width / 2.0;
	float h2 = height / 2.0;
	// Левая верхняя точка
	Point upper_left(center.x - w2, center.y + h2);
	coordinates[0] = upper_left;
	// Правая верхняя точка
	Point upper_right(center.x + w2, center.y + h2);
	coordinates[1] = upper_right;
	// Правая нижняя точка
	Point lower_right(center.x + w2, center.y - h2);
	coordinates[2] = lower_right;
	// Левая нижняя точка
	Point lower_left(center.x - w2, center.y - h2);
	coordinates[3] = lower_left;

	return coordinates;
}

bool Rectangle::Contains(int x, int y)
{
	if ((x >= center.x - width / 2 && x <= center.x + width / 2) && (y >= center.y - height / 2 && y <= center.y + height / 2))
	{
		return true;
	}
	return false;
}
bool Rectangle::Contains(Point p)
{
	if ((p.x >= center.x - width / 2 && p.x <= center.x + width / 2) && (p.y >= center.y - height / 2 && p.y <= center.y + height / 2))
	{
		return true;
	}
	return false;
}
bool Rectangle::IntersectAxis(char axis)
{
	if (axis == 'x')
	{
		if (height / 2 >= abs(center.y))
		{
			return true;
		}
		return false;
	}

	else if (axis == 'y')
	{
		if (width / 2 >= abs(center.x))
		{
			return true;
		}
		return false;
	}
}