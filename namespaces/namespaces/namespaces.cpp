#include <iostream>

namespace Book_namespace
{
	class Book
	{
	private:
		std::string title, author;
		int publicationDate;
		static int counter;
	public:
		Book(std::string title = "title", std::string author = "author", int publicationDate = 2020);
		bool XXcentury();
		void show();
		int getPublicationDate();
		int getcounter();
	};

	Book::Book(std::string title, std::string author, int publicationDate)
	{
		this->title = title;
		this->author = author;
		this->publicationDate = publicationDate;
		std::cout << "created book nr: " << ++this->counter << "\n";
	}

	bool Book::XXcentury()
	{
		return (publicationDate > 1900 && publicationDate <= 2000);
	}

	void Book::show() {
		std::cout << "title: " << this->title << " author: " << this->author << " publication date: " << this->publicationDate << "\n";
	}

	int Book::getPublicationDate()
	{
		return this->publicationDate;
	}

	int Book::getcounter()
	{
		return this->counter;
	}


	int Book::counter = 0;

	void Sort(Book tablica[])
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j < 4 - i; j++)
				if (tablica[j - 1].getPublicationDate() < tablica[j].getPublicationDate())
					std::swap(tablica[j - 1], tablica[j]);
		}
	}
}


int main()
{
	Book_namespace::Book pierwsza;

	Book_namespace::Book tablica[4] = {
		Book_namespace::Book("Pan Tadeusz", "Adam Mickiewicz", 1980),
		Book_namespace::Book("Wiedzmin", "Andrzej Sapkowski", 2020),
		Book_namespace::Book("Pan Twardowski", "Jozef Ignacy Kraszewski", 2005),
		Book_namespace::Book("Kleks", "Kolanowski", 2001)
	};


	std::cout << "\t1)\n";
	pierwsza.show();

	for (int i = 0; i < 4; i++)
		tablica[i].show();

	std::cout << "\t2)\n";
	for (int i = 0; i < 4; i++)
		std::cout << "Book nr." << i << " is it from the 20th century?: " << tablica[i].XXcentury() << "\n";

	std::cout << "\t3)\n";
	Book_namespace::Sort(tablica);

	for (int i = 0; i < 4; i++)
		tablica[i].show();

	std::cout << "\t4)\n";
	std::cout << "counter of books: " << pierwsza.getcounter();

	return 0;

}