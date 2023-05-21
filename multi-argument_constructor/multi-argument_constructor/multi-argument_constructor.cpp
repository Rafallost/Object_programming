#include <iostream>
#include <string>
#include <ctime>
#include <vector>

const int AMOUNT_OF_ITEMS = 4;

class Item {
private:
	std::string name;
	int attack;
	int defense;
public:
	Item(std::string name = "buzdygan");
	void show();
	int getattack() { return this->attack; };
	int getdefense() { return this->defense; };
};

Item::Item(std::string name)
{
	this->name = name;
	this->attack = rand() % 100 + 101;
	this->defense = rand() % 101;
}

void Item::show()
{
	std::cout << "name: " << this->name << " attack: " << this->attack << " defense: " << this->defense << " \n";
}

class Bohater {
private:
	friend std::string duel(Bohater& bohater1, Bohater& bohater2);
	std::string pseudonym;
	std::string clas;
	int hp;
	Item eq[AMOUNT_OF_ITEMS];
	int amount_of_items;
public:
	Bohater(std::string pseudonym = "pseudonym", std::string clas = "helper", int hp = 1200, std::string name_Itemow = "Item ");
	void show();
	Item getItem(int numer);
	int gethp();
	std::string getpseudonym() { return this->pseudonym; };

};

Bohater::Bohater(std::string pseudonym, std::string clas, int hp, std::string name_Itemow)
{
	this->pseudonym = pseudonym;
	this->clas = clas;
	this->hp = hp;
	int h = 0;

	if (name_Itemow != "Item ")
	{
		this->eq[0] = name_Itemow;
		h = 1;
	}


	for (int i = 0 + h; i < AMOUNT_OF_ITEMS; i++)
		this->eq[i] = Item("Item " + std::to_string(i + 1));

	std::cout << "The hero has been created \n";
}

void Bohater::show()
{
	std::cout << this->pseudonym << ", " << this->clas << ", " << this->hp << " \n";
	this->eq[0].show();
	this->eq[1].show();
	this->eq[2].show();
	this->eq[3].show();
}

Item Bohater::getItem(int numer)
{
	return this->eq[numer];
}

int Bohater::gethp()
{
	return this->hp;
}

std::string duel(Bohater& bohater1, Bohater& bohater2)
{
	int sumaAtatkuBohater1 = 0, sumaattackuBohater2 = 0, sumaObronyBohater1 = 0, sumaObronyBohater2 = 0;

	for (int i = 0; i < AMOUNT_OF_ITEMS; i++)
	{
		sumaAtatkuBohater1 += bohater1.getItem(i).getattack();
		sumaattackuBohater2 += bohater2.getItem(i).getattack();

		sumaObronyBohater1 += bohater1.getItem(i).getdefense();
		sumaObronyBohater2 += bohater2.getItem(i).getdefense();
	}

	int hpBohater1 = 0, hpBohater2 = 0;

	bohater1.hp -= (sumaattackuBohater2 - sumaObronyBohater1);
	bohater2.hp = bohater2.hp - (sumaAtatkuBohater1 - sumaObronyBohater2);

	if (bohater1.hp > bohater2.hp)
		return "Bohater1";
	else
		return "Bohater2";
}

int main()
{
	srand(time(NULL));

	Bohater bohater1;
	Bohater bohater2("Maciej", "Czarodziej", 1000, "Miecz");
	std::cout << "\n";

	bohater1.show();
	std::cout << "\n";
	bohater2.show();


	if (duel(bohater1, bohater2) == "Bohater1")
		std::cout << "\Won: Bohater 1 : " << bohater1.getpseudonym() << " and left him: " << bohater1.gethp() << " hp\n";
	else
		std::cout << "\nWon: Bohater 2 : " << bohater2.getpseudonym() << " and left him: " << bohater2.gethp() << " hp\n";


	return 0;
}
