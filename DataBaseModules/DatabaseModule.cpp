#include "DatabaseModule.h"


DatabaseModule::DatabaseModule()
{
}


DatabaseModule::~DatabaseModule()
{
}

void DatabaseModule::Loop()
{
	bool Done = false;
	while (!Done)
	{
		char Choice;
		cout << "1. Look Up a Book\n";
		cout << "2. Add a Book\n";
		cout << "3. Edit a Book's Record\n";
		cout << "4. Delete a Book\n";
		cout << "5. Return to the Main Menu\n";
		cin >> Choice;
		cin.ignore();
		switch (Choice)
		{
			case '1':
				DisplayBook(SearchForBook());
				break;
			case '2':
				AddBook();
				break;
			case '3':
				EditBook();
				break;
			case '4':
				deleteBook();
				break;
			case '5':
				Done = true;
				break;
			default:
				cout << "Bad input\n";
				break;
		}
	}
}

double DatabaseModule::PurchaseBook(Book BK, unsigned int Quant)
{
	if (BK.QuantityOnHand >= Quant)
	{
		BK.QuantityOnHand -= Quant;
		return Quant * BK.RetailPrice;
	}
	else
		return 0;
}



Book DatabaseModule::SearchForBook()
{
	char choice = '0';
	Book BK;
	BK.ISBN = "0";
	while (choice == '0') //loop until valid choice
	{
		cout << "1. ISBN \n2. Title" << endl;
		cin >> choice;
		cin.ignore();
	}
	switch (choice)
	{
	case '1':
		//search for book using isbn
		while (BK.ISBN == "0")
		{
			string ISBN;
			cout << "Enter ISBN";
			getline(cin,ISBN);
			if (BK.ISBN == "0")
			{

				cout << "Sorry this book could not be found\n";
			}
		}
		break;
	case '2':
		//search for book using title
		while (BK.ISBN == "0")
		{
			string Title;
			cout << "Enter Title";
			getline(cin,Title);
			BK=searchWithString(Title);
			if (BK.ISBN == "0")
			{
				cout << "Sorry this book could not be found\n";
			}
		}
	}
	return BK;
}

void DatabaseModule::EditBook()
{
	char choice;
	bool Done = false;
	cout << "Which Book\n";
	Book BK = SearchForBook();

	while (!Done)
	{
		cout << "What would you like to edit\n";
		cout << "1. ISBN \n	2. Title \n	3. Author \n 4. Publisher \n	5. DateAdded \n 6. Quantity \n 7. Wholsale Cost \n	8. Retail Price \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			getline(cin, BK.ISBN);
			break;
		case 2:
			getline(cin, BK.Title);
			break;
		case 3:
			getline(cin, BK.Author);
			break;
		case 4:
			getline(cin, BK.Publisher);
			break;
		case 5:
			BK.DateAdded.InputDay();
			break;
		case 6:
			cin >> BK.QuantityOnHand;
			cin.ignore();
			break;
		case 7:
			cin >> BK.WholesaleCost;
			cin.ignore();
			break;
		case 8:
			cin >> BK.RetailPrice;
			cin.ignore();
			break;
		default:
			cout << "Please enter a valid choice\n";
		}

		cout << "Press q to stop editing\n";
		cin >> choice;
		if (choice == 'q')
			Done = true;
	}
}


Book DatabaseModule::AddBook()
{
	Book BK;

	cout << "Enter ISBN:";
	cin >> BK.ISBN;
	cin.ignore();

	cout << "Enter Title:";
	getline(cin, BK.Title);

	cout << "Enter Author:";
	getline(cin, BK.Author);

	cout << "Enter Publisher:";
	getline(cin, BK.Publisher);

	cout << "Enter Date Added:";
	BK.DateAdded.InputDay();

	cout << "Enter Quantity On Hand:";
	cin >> BK.QuantityOnHand;
	cin.ignore();

	cout << "Wholesale Cost:";
	cin >> BK.WholesaleCost;
	cin.ignore();

	cout << "RetailPrice:";
	cin >> BK.RetailPrice;
	cin.ignore();

    addBookToList(BK);
    composeHashTable();

	return BK;
}

void DatabaseModule::deleteBook()
{
	Book BK = SearchForBook(); //find book
	deleteBookUsingISBN(BK.ISBN); //delete book
	composeHashTable();
}


void DatabaseModule::DisplayBook(Book BK)
{
	cout << "ISBN:" << BK.ISBN << endl;
	cout << "Title:" << BK.Title << endl;
	cout << "Author:" << BK.Author << endl;
	cout << "Publisher:" << BK.Publisher << endl;
	cout << "Date Added:"; BK.DateAdded.PrintDate();//add ostream for date
	cout << "Quantity On Hand:" << BK.QuantityOnHand << endl;
	cout << "Wholesale Cost:" << BK.WholesaleCost << endl;
	cout << "Retail Price:" << BK.RetailPrice << endl;
}


int main()
{
	DatabaseModule DB;
	DB.Loop();
}
