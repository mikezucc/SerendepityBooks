#pragma once
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Date.h"
using namespace std;

struct Book
{
	string ISBN;
	string Title;
	string Author;
	string Publisher;
	Date DateAdded = Date(0, 0, 0);
	unsigned int QuantityOnHand;
	double WholesaleCost;
	double RetailPrice;
};


struct HashTable {
	vector <int> hashList;
	int hashTableSize;
};

class DataBaseMASTER
{
private:
	vector <Book> listOfBooks;
	vector <HashTable> DBHashTable;
public:
	void addBookToList(Book);
	void composeHashTable();
	void deleteBookUsingISBN(string);
	int getAdjustedChar(char);
	Book searchWithString(string);
	HashTable composeHashForCompare(string);
	vector <int> matchVectorMatrix;
};
