#include <iostream>
#include <vector>

struct Point
{
	float x;
	float y;
	Point();
	Point(float x, float y);
};

class Rectangle
{
public:
	Rectangle(int x, int y, int w, int h);
	Rectangle(Point center, int w, int h);
	~Rectangle();
	void Print();
	int Perimeter();
	Point* VertexCoordinates();
	bool Contains(int x, int y);
	bool Contains(Point p);
	bool IntersectAxis(char axis);

protected:
	Point center;
	int width, height;
	Point* coordinates = new Point[4];
};