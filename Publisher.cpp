#include <iostream>
#include <string.h>

using namespace std;

class publication
{
	string title;
	float prices;

public:
	publication()
	{
		title = "";
		prices = 0.0;
	}
	void get_data()
	{
		cout << "\n enter the title";
		cin >> title;
		cout << "\n enter the price";
		cin >> prices;
	}
	void put_data()
	{
		cout << "\n information";
		cout << "\n title=" << title;
		cout << "\n price=" << prices;
	}
};

class book : public publication
{
	int pages;

public:
	book()
	{
		pages = 0;
	}
	void get_data()
	{
		publication::get_data();
		cout << endl;
		cout << "enter page cout=";
		cin >> pages;
	}
	void put_data()
	{
		publication::put_data();
		cout << endl;
		try
		{
			if (pages < 0)
				throw pages;
		}
		catch (int f)
		{
			cout << "\n error:pages not valid" << f;
			pages = 0;
		}
		cout << "\n pages are=" << pages;
	}
};
class tape : public publication
{
	float playtime;

public:
	tape()
	{
		playtime = 0.0;
	}
	void get_data()
	{
		publication::get_data();
		cout << "enter the play time of casset";
		cin >> playtime;
	}
	void put_data()
	{
		publication::put_data();
		try
		{
			if (playtime < 0.0)
				throw playtime;
		}
		catch (int r)
		{
			cout << "\n error:playtime not valid" << r;
			playtime = 0.0;
		}
		cout << "playtime=" << playtime;
	}
};
int main()
{
	book b[10];
	tape t[10];
	int choice = 0, bookcount = 0, tapecount = 0;
	cout << "---------------------------";
	do
	{
		cout << "\n 1. add book";
		cout << "\n 2. add tape ";
		cout << "\n 3.display book";
		cout << "\n 4. display tape";
		cout << "\n 5. exit";
		cout << "\n enter choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "\n*******\n ";
			cout << "add book";
			b[bookcount].get_data();
			bookcount++;
			break;
		}
		case 2:
		{
			cout << "\n******\n ";
			cout << "add tape";
			t[tapecount].get_data();
			tapecount++;
			break;
		}
		case 3:
		{
			cout << "\n(book)";
			for (int j = 0; j < bookcount; j++)
			{
				b[j].put_data();
			}
			break;
		}
		case 4:
		{
			cout << "\n(tape)";
			for (int j = 0; j < tapecount; j++)
			{
				t[j].put_data();
			}
			break;
		}
		case 5:
		{
			cout << "************************pragram exited successfully*****************" << endl;
		}
		default:
		{
			cout << "\n invalid";
		}
		}
	} while (choice != 5);
	return 0;
}
