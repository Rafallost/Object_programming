#include <iostream>
#include <ctime>

const int size_1 = 3;

int nwd(int a, int b) {

	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

class Fraction {
	friend std::ostream& operator<<(std::ostream& Str, Fraction u);
	friend Fraction add(Fraction u1, Fraction u2);
	friend void GenerateFractions(int N);
	int numerator , denominator;
public:

	Fraction(int l, int m) :numerator (l), denominator(m) {};
	Fraction(int l) :numerator (l), denominator(1) {};
	Fraction() :numerator (0), denominator(1) {};

	void toShorten()
	{
		int dzielnik = nwd(numerator , denominator);
		numerator  /= dzielnik;
		denominator /= dzielnik;
	};

	operator double() {
		return static_cast<double>(numerator ) / denominator;
	};
	void show() { std::cout << numerator  << "/" << denominator << "\n"; };

};


Fraction add(Fraction u1, Fraction u2) {

	int l = u1.numerator  * u2.denominator + u2.numerator  * u1.denominator;
	int m = u1.denominator * u2.denominator;
	Fraction u3(l, m);
	return u3;
}

double SquareNumbers(double l) {
	return l * l;
}

std::ostream& operator<<(std::ostream& Str, Fraction u)
{
	Str << u.numerator  << "/" << u.denominator << "\n";
	return Str;
}

void GenerateFractions(int N) {
	Fraction* tab = new Fraction[N];
	Fraction max(-INT_MAX, 1);
	int m, l;
	for (int i = 0; i < N; i++) {

		l = std::rand() % 2001 - 1000;
		m = std::rand() % 2001 - 1000;

		while (!m)
			m = std::rand() % 2001 - 1000;

		tab[i] = Fraction(l, m);
		std::cout << "Fraction nr " << i + 1 << "= " << tab[i];

		if (static_cast<double>(tab[i].numerator ) / tab[i].denominator > static_cast<double>(max.numerator ) / max.denominator) {
			max = tab[i];
		}
	}

	std::cout << "\n\Max: " << max;

	delete[] tab;
}

int main()
{
	srand(time(NULL));

	Fraction array_u[3] = { Fraction(1,2), Fraction(5,8), Fraction(7,9) };

	std::cout << "1)\n";
	for (int i = 0; i < size_1; i++)
	{
		std::cout << "\t" << array_u[i];
	}

	std::cout << "2)\n\t" << add(array_u[0], array_u[1]);
	std::cout << "3)\n\t" << add(array_u[0], static_cast<Fraction>(7));
	std::cout << "4)\n\t" << SquareNumbers(array_u[2]) << "\n";

	Fraction shorten(88 / 22);
	shorten.toShorten();

	std::cout << "5)\n\t" << shorten;
	std::cout << "6)\n";
	GenerateFractions(3);

	return 0;
}


