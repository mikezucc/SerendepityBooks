#include <iostream>
#include <iomanip>
#include <string> 
#include "CashierModuleFunctions.h"

using namespace std;

void CategorySetup()		//Set up Categories
{
	
	cout << "\t\tSerendipity Book Sellers:" << endl;														// Book Store name
	cout << "\t\t-------------------------" << endl;														
	cout << "Date: June 10" << endl;																		// Date of the Transaction
	cout << "-------------" << endl;
	cout << "Qty \tISBN \t\t\tTitle \t\t\tPrice \t\tTotal" << endl;											// Set up Columns
	cout << "--------------------------------------------------------------------------------" << endl;


}																	

void ListBook(int Qty, string ISBN, string Title, double Price, double Total) // Display books on screen.
{

	double PriceLen = 1;		// Variables for Lenght of Price
	double price = Price;

	for (PriceLen = 0; price > 9; PriceLen++)		// Get length of price
	{
		price = price / 10;

	}
	PriceLen = PriceLen + 3;		// modify lenght of price for cents
	

	cout << setprecision(2) << fixed;  // set two decimals for cents
	cout << Qty << "\t" << ISBN << "\t" << Title << setw(29 - Title.size()) << Price << setw(19 - PriceLen) << Total << endl; // Display Book information relevant to Receit
	


}

string InputBookInformationISBN()
{

	string ISBN;
	cout << "Please enter ISBN of the book you wish to find: ";
	cin >> ISBN;
	return ISBN;
	

}

string InputBookInformationTitle()
{
	string Title;
	cout << "Please enter Title of the book you wish to find: ";
	cin >> Title;
	return Title;

}

int TitleorISBN()
{
	int choice;

	do
	{
		cout << "Do you wish to adda book through Title or ISBN?" << endl;
		cout << "1. Title \t2. ISBN: ";
		cin >> choice;
		cout << endl;

		if (choice > 3 || choice < 0)
		{
			cout << "invalid Choise, enter a number between 1 - 2!" << endl;
		}



	} while (choice > 3 || choice < 0);

		return choice;

}

