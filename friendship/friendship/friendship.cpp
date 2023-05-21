#include <iostream>
#include <cmath>
#include <ctime>

const int tab1_size = 100;
const int tab2_size = 50;

class Circle;
class Rectangle;
int global_function(Circle*, Circle*);

class Point {
	friend class Circle;
	friend class Rectangle;
	friend int global_function(Circle* tablica1, Circle* tablica2);
private:
	int x, y;
public:
	Point(int x0 = 0, int y0 = 0) :x(x0), y(y0) {};
};

class Rectangle {
private:
	Point lowerLeftVertex;
	int width;
	int hight;
public:
	Rectangle(Point lowerLeftVertex0 = (0, 0), int width0 = 0, int hight0 = 0) :lowerLeftVertex(lowerLeftVertex0), width(width0), hight(hight0) {};
	bool inCommon(Point Point);
};

bool Rectangle::inCommon(Point Point)
{
	if (Point.x >= -8 && Point.x <= 5)
		if (Point.y >= -1 && Point.y <= 4)
			return true;

	return false;
}

class Circle {
	friend int global_function(Circle* tablica1, Circle* tablica2);
	friend class Point;
private:
	Point circleCenter;
	int r;
public:
	Circle(Point srodek = (0, 0), int r0 = 0) :circleCenter(srodek), r(r0) {};

};

int global_function(Circle* tablica1, Circle* tablica2)
{
	int licznik = 0;

	for (int i = 0; i < tab1_size; i++)
	{
		for (int y = 0; y < tab2_size; y++)
		{

			float distance = std::sqrt(std::pow(tablica1[i].circleCenter.x, 2) + std::pow(tablica2[y].circleCenter.y, 2));

			if (std::abs(tablica1[i].r - tablica2[y].r) < distance < tablica1[i].r + tablica2[y].r)
				licznik++;

		}
	}
	return licznik;
}

int main()
{
	srand(time(NULL));

	Point pointsArray[3] = { (5,2),(-9,-9),(2,3) };
	Rectangle Rectangle((-8, -6), 13, 10);

	for (int i = 0; i < 3; i++)
	{
		if (Rectangle.inCommon(pointsArray[i]))
			std::cout << "Point nr " << i + 1 << " is in a rectangle\n";
		else
			std::cout << "Point nr " << i + 1 << " is NOT in the rectangle\n";
	}

	Circle circlesArray[100];

	for (int i = 0; i < 100; i++)
		circlesArray[i] = { Point((std::rand() % 6),(std::rand() % 6 - 5)),(std::rand() % 11 + 1) };

	Circle* circlesArrayDynamic = new Circle[50];

	for (int i = 0; i < 50; i++)
		circlesArray[i] = { Point((std::rand() % 16 - 5),(std::rand() % 16 - 10)),(std::rand() % 16 + 1) };

	std::cout << "number of overlapping points: " << global_function(circlesArray, circlesArrayDynamic);

	return 0;

}