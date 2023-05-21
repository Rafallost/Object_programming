#include <iostream>

class Passenger
{
	
	std::string name, surname;
	int yearOfBirth;

public:

	Passenger(std::string name = "Maciej", std::string surname = "Borek", int yearOfBirth = 2023)
	{
		this->name = name;
		this->yearOfBirth = yearOfBirth;
		this->surname = surname;
	}

	Passenger(Passenger& Passenger)  
	{ 
		this->name = Passenger.name;
		this->surname = Passenger.surname;
		this->yearOfBirth = Passenger.yearOfBirth;
 
		std::cout <<"The data it copies name:" << this->name << ", surname: "<< this->surname << ", yearOfBirth: "<< this->yearOfBirth << "\n";
	}  

	void show()
	{
		std::cout << "name:" << this->name << ", surname: " << this->surname << ", yearOfBirth: " << this->yearOfBirth << "\n";
	}

	
};

class Autokar
{
	std::string point;
	int maxVelocity;
	static const int maxAmountOfSeats = 8;
	Passenger* Passengerowie[maxAmountOfSeats] = { nullptr };
	int AmountOfPassengers = 0;

public:
	
	Autokar(std::string point = "Gdansk", int maxVelocity = 100)
	{
			this->point = point;
			this->maxVelocity = maxVelocity;
	}
	


	Autokar(Autokar& autokar,int max)
	{
		this->point = autokar.point;
		this->maxVelocity = max;

		for (int i = 0; i < this->maxAmountOfSeats; i++)  
			this->Passengerowie[i] = autokar.Passengerowie[i];
	}


	void addPassenger(Passenger& Passenger)
	{
		int temp = this->AmountOfPassengers;
			temp++;

		if (temp>8)
		{
			std::cout << "limit miejsc zostal osiagniety;\n";
			
		}
		else
		{
			Passengerowie[temp-1] = &Passenger;
			this->AmountOfPassengers++;
		}
			
	

	}

	void showInfo()
	{
		std::cout << "point:" << this->point << ", maxVelocity: " << this->maxVelocity << ", maxAmountOfSeats: " << this->maxAmountOfSeats << "\n";
	}

	void show()
	{
		std::cout << "W autokarze sa Passengerowie:\n";
		for (int i = 0; i < this->AmountOfPassengers; i++)
		{
			Passengerowie[i]->show();
		}
	}

};

int main()
{
	Passenger Passenger1;
	Passenger Passenger2("Janusz","Pakleza",1986);
	Passenger Passenger3(Passenger2);

	std::cout << "\n1:\n\n";

	Passenger1.show();
	Passenger2.show();
	Passenger3.show();

	Passenger* passengersArray[50] = {nullptr}; 

	for (int i = 0; i < 50; i++)
		passengersArray[i] = &Passenger1;

	Autokar autokar1;

	autokar1.addPassenger(Passenger1);
	autokar1.addPassenger(Passenger2);
	autokar1.addPassenger(Passenger3);

	autokar1.addPassenger(*passengersArray[0]);
	autokar1.addPassenger(*passengersArray[1]);
	autokar1.addPassenger(*passengersArray[2]);
	autokar1.addPassenger(*passengersArray[3]);
	autokar1.addPassenger(*passengersArray[4]);
	autokar1.addPassenger(*passengersArray[5]);
	autokar1.addPassenger(*passengersArray[6]);


	std::cout << "\n2:\n\n";
	autokar1.showInfo();
	autokar1.show();


	std::cout << "\n2:\n\n";

	Autokar autokar2(autokar1,200);

	autokar2.showInfo();

	return 0;
}


