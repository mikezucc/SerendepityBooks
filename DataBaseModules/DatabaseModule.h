#pragma once
#include <iostream>
#include <string>
#include "DataBaseMASTER.h"
using namespace std;


enum Type {ISBN, Title};

class DatabaseModule: public DataBaseMASTER
{
	public:
		DatabaseModule();
		virtual ~DatabaseModule();
		void Loop();
		void Initialize();
		double PurchaseBook(Book, unsigned int);
		Book SearchForBook();
		Book* GetBookForEdit(string, Type);
		void EditBook();
		Book AddBook();
		void deleteBook();
		void DisplayBook(Book);
	private:
};

