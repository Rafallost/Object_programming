#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

#define SIZE 20
#define M_PI 3.14159265358979323846

class Vector
{
	friend std::ostream& operator<<(std::ostream& os, const Vector& w);
private:
	int x, y;

public:
	Vector(int x1 = 0, int y1 = 0) : x(x1), y(y1) {};

	Vector operator+(const Vector& w) const {
		return Vector(x + w.x, y + w.y);
	}

	int operator*(const Vector& w) const {
		return x * w.x + y * w.y;
	}

	double length() const {
		return std::sqrt(x * x + y * y);
	}
};

std::ostream& operator<<(std::ostream& os, const Vector& w) {
	os << "[" << w.x << ", " << w.y << "]";
	return os;
}

bool compare(const std::pair<double, Vector>& a, const std::pair<double, Vector>& b) {
	return a.first < b.first;
}

Vector nearest(const std::vector<std::pair<double, Vector>>& vectors, const Vector& w) {

	double length = w.length();
	double min = INT_MAX;
	Vector minWek;

	for (const auto& vec : vectors) {
		if (std::abs(vec.first - length) < min) {
			min = std::abs(vec.first - length);
			minWek = vec.second;
		}
	}

	return minWek;
}

double angle(const Vector& w1, const Vector& w2) {
	double dotProduct = w1 * w2;
	double lengthProduct = w1.length() * w2.length();

	if (lengthProduct == 0) {
		std::cout << "product of the length is 0, the angle cannot be calculated.\n";
		return -1.0;
	}

	double cosinus_alfa = dotProduct / lengthProduct;
	double alpha_radians = std::acos(cosinus_alfa);
	double alpha_degrees = alpha_radians * (180.0 / M_PI);
	return alpha_degrees;
}

int main()
{
	std::srand(std::time(NULL));

	Vector w1(3, 5);
	Vector w2(-2, 7);

	std::cout << "1)\n";
	std::cout << "w1 = " << w1 << "\nw2 = " << w2 << "\n\n";

	std::cout << "2)\n";
	std::cout << "w1 + w2 = " << w1 + w2 << "\n\n";

	std::cout << "3)\n";
	std::cout << "w1 * w2 = " << w1 * w2 << "\n\n";

	Vector tab[SIZE];
	std::vector<std::pair<double, Vector>> vectors;

	for (int i = 0; i < SIZE; i++) {
		tab[i] = Vector(std::rand() % 31 - 15, std::rand() % 31 - 15);
		vectors.push_back(std::make_pair(tab[i].length(), tab[i]));
	}

	std::sort(vectors.begin(), vectors.end(), compare);

	std::cout << "4)\n";
	for (const auto& vec : vectors)
		std::cout << vec.second << " (length: " << vec.first << ")\n";

	Vector temp = nearest(vectors, w1);

	std::cout << "\n5)\n";
	std::cout << "to vector: " << w1 << " of length: " << w1.length() << "\n";
	std::cout << "The nearest is: "<<temp<< " of length: "<< temp.length()<<"\n\n";

	std::cout << "6)\n";
	std::cout << "Angel between w1 and w2 is: " << angle(w1, w2) << " degrees" << std::endl;

	return 0;
}