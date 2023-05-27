#include<iostream>

#define SIZE 4

class Animal {
	friend void Sorting(Animal** tab);
protected:
	std::string name;
	int weight;
	int amount_of_legs;
public:
	Animal(std::string name0 = "Animal", int weight0 = 10, int amount_of_legs0 = 4) : name(name0), weight(weight0), amount_of_legs(amount_of_legs0) {};

	virtual void show() {
		std::cout << "Imie: " << name << "\nweight:" << weight << " \namount of legs:" << amount_of_legs << "\n\n";
	}
};

class Dog : public Animal {
private:
	std::string race;
	std::string fur_color;
public:
	Dog(std::string race0 = "dog", std::string fur_color0 = "black") : race(race0), fur_color(fur_color0), Animal("dog", 5, 4) {};

	void show() override {
		std::cout << "Imie: " << name << "\nweight:" << weight << " \namount of legs:" << amount_of_legs << "\nrace:" << race << "\ncolor siersci:" << fur_color << "\n\n";
	}
};

class Parrot : public Animal {
private:
	std::string color;
public:
	Parrot(std::string color0 = "red") : color(color0), Animal("Parrot", 2, 2) {};
	Parrot(const Parrot& p1, std::string name0, int weight0) :color(p1.color), Animal(name0, weight0, p1.amount_of_legs) {};

	void show() override {
		std::cout << "Imie: " << name << "\nweight:" << weight << " \namount of legs:" << amount_of_legs << "\ncolor: " << color << "\n\n";
	}
};

void Sorting(Animal** tab) {
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - i - 1; j++) {
			if ((*tab[j]).weight > (*tab[j + 1]).weight)
				std::swap(tab[j], tab[j + 1]);
		}
	}
}

int main() {
	std::cout << "a)\n";
	Animal z1;
	z1.show();

	std::cout << "\n\nb)\n";
	Dog* p1 = new Dog("Jork", "white");
	p1->show();

	Parrot papuga1("blue");
	Parrot papuga2(papuga1, "Basia", 3);
	std::cout << "\n\nc)\n";
	papuga1.show();
	papuga2.show();

	Animal** array = new Animal * [SIZE];
	array[0] = &z1;
	array[1] = p1;
	array[2] = &papuga1;
	array[3] = &papuga2;

	std::cout << "\n\nd)\n";
	for (int i = 0; i < SIZE; i++)
		array[i]->show();

	std::cout << "\n\ne)\n";
	Sorting(array);
	for (int i = 0; i < SIZE; i++)
		array[i]->show();

	delete p1;
	delete[] array;

	return 0;
}