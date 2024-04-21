#include "rectangle.h"
#include <iostream>

void readInt(int& num) {
	std::cin >> num;
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "\t\tНеверно введено значение. Введите целое число: ";
		std::cin >> num;
	}
}
void readFloat(float& num) {
	std::cin >> num;
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "\t\tНеверно введено значение. Введите целое число: ";
		std::cin >> num;
	}
}

int menu(Rectangle& rect) { // меню 
	std::cout << "Доступные комманды:  \n \
	1.Вывод на экран параметров прямоугольника \n \
	2.Пересечение оси Х \n \
	3.Пересечение оси Y \n \
	4.Периметр\n \
	5.Координаты вершин\n \
	6.Принадлежит ли точка прямоугольнику\n \
	0.Выход\n";
	std::cout << "Введите номер комманды: ";
	int command;
	Point p;
	Point* coordinates;
	std::cin >> command;
	switch (command)
	{
	case 1: {
		rect.Print();
		break;
	}
	case 2: {
		// Пересекает ли оси X;
		if (rect.IntersectAxis('x'))
			std::cout << "Есть пересечение с осью X";
		else
			std::cout << "Нет пересечения с осью X";
		std::cout << std::endl;
		break;
	}
	case 3: {
		// Пересекает ли оси Y;
		if (rect.IntersectAxis('y'))
			std::cout << "Есть пересечение с осью Y";
		else
			std::cout << "Нет пересечения с осью Y";
		std::cout << std::endl;
		break;
	}
	case 4: {
		// Перимертр
		std::cout << "Периметр: " << rect.Perimeter() << std::endl;
		break;
	}
	case 5: {
		// Координаты вершин
		coordinates = rect.VertexCoordinates();
		std::cout << "Левая верхняя вершина: (" << coordinates[0].x << "," << coordinates[0].y << ")" << std::endl;
		std::cout << "Правая верхняя вершина: (" << coordinates[1].x << "," << coordinates[1].y << ")" << std::endl;
		std::cout << "Правая нижняя вершина: (" << coordinates[2].x << "," << coordinates[2].y << ")" << std::endl;
		std::cout << "Левая нижняя вершина: (" << coordinates[3].x << "," << coordinates[3].y << ")" << std::endl;
		break;
	}
	case 6: {
		// Содержит ли прямоугольник точку
		std::cout << "Введите координату X искомой точки: ";
		readFloat(p.x);
		std::cout << "Введите координату Y искомой точки: ";
		readFloat(p.y);

		if (rect.Contains(p))
			std::cout << "Прямоугольник содержит точку";
		else
			std::cout << "Прямоугольник не содержит точку";
		std::cout << std::endl;
		break;
	}
	case 0: {
		return 0;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	// Создание прямоугольника
	Point center;
	int w;
	int h;
	std::cout << "Введите координату X центра прямоугольника: ";
	readFloat(center.x);
	std::cout << "Введите координату Y центра прямоугольника: ";
	readFloat(center.y);
	std::cout << "Введите ширину прямоугольника: ";
	readInt(w);
	std::cout << "Введите высоту прямоугольника: ";
	readInt(h);
	Rectangle rect(center, w, h);

	// Выполнение команд
	while (true)
	{
		int output = menu(rect);
		if (output == 0)
		{
			break;
		}
	}
}
