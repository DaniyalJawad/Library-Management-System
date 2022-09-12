#define NO_WARNING
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;

int option;
class library
{
private:
	struct node
	{
		int id;
		string name, author, publisher;
		node* next;
	};
public:
	node* head = NULL;
	void title_page();
	void menu();
	void insert();
	void update_record();
	void search_record();
};
void library::title_page()
{
	system("cls");
	cout << "\n\t\t\t\t\t----------------------------------------" << endl
		<< "\n\t\t\t\t\t-      Library Managment System        -" << endl
		<< "\n\t\t\t\t\t----------------------------------------" << endl;
	cout << endl << endl;

	cout << "\t\t\t\t\t Data Structures and Algorithms Project" << endl
		<< "\t\t\t\t\t --------------------------------------" << endl;
	cout << endl;
	cout << "\tGroup Members: " << endl << endl;
	cout << "\t\t 2- Daniyal Jawad (F2020266323)" << endl;

	cout << "\n\n\n\n\n\t\t\t\t\t Press Enter to Continue...." << endl;
	_getch();
}
void library::menu()
{
L:
	system("cls");
	cout << "\n\t\t\t\t\t----------------------------------------" << endl
		<< "\n\t\t\t\t\t-      Library Managment System        -" << endl
		<< "\n\t\t\t\t\t----------------------------------------" << endl;
	cout << endl << endl;
	cout << "1- Add Books Record\n" << endl
		<< "2- Update Book Record\n" << endl
		<< "3- Search a book\n" << endl
		<< "4- Delete book record\n" << endl
		<< "5- Display all records\n" << endl
		<< "6- Exit\n" << endl;
	cout << "\n Select your choice: ";
	cin >> option;
	switch (option)
	{
	case 1:
		insert();
		break;

	case 2:
		update_record();
		break;

	case 3:
		search_record();
		break;
	case 6:
		exit(0);
	default:
		break;
	}
	_getch();
	goto L;
}
void library::insert()
{
	system("cls");
	cout << "\n\t\t\t\t\t----------------------------------------" << endl
		<< "\n\t\t\t\t\t|      Library Managment System        |" << endl
		<< "\n\t\t\t\t\t----------------------------------------" << endl;
	cout << endl << endl;
	node* ptr = new node();
	ofstream fout;
	fout.open("book_records.txt");
	cout << "Enter Book ID: ";
	cin >> ptr->id;
	cout << "---------------------------------" << endl;
	cout << "Enter Book Name: ";
	cin >> ptr->name;
	cout << "---------------------------------" << endl;
	cout << "Enter Publisher Name: ";
	cin >> ptr->publisher;
	cout << "---------------------------------" << endl;
	cout << "Enter Author Name: ";
	cin >> ptr->author;

	fout << ptr->id << endl << ptr->name << endl << ptr->publisher << endl
		<< ptr->author << endl;
	ptr->next = NULL;
	if (head == NULL)
	{
		head = ptr;
	}
	else
	{
		node* p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p = new node();
	}
	fout.close();
	cout << "\n\n\n\t\t\t\t\t    Book Record Added Successfully " << endl;
}
void library::update_record()
{
	system("cls");
	cout << "\n\t\t\t\t\t----------------------------------------" << endl
		<< "\n\t\t\t\t\t|      Library Managment System        |" << endl
		<< "\n\t\t\t\t\t----------------------------------------" << endl;
	cout << endl << endl;
	int temp_id, count = 0;
	node* ptr = head;
	if (head == NULL)
	{
		cout << "\t\t\t\t\t No record Entered" << endl;
	}
	else
	{
		cout << "Enter Book ID: ";
		cin >> temp_id;
		while (ptr != NULL)
		{
			if (temp_id == ptr->id)
			{
				system("cls");
				cout << "Book ID: ";
				cin >> ptr->id;
				cout << "Book Name: ";
				cin >> ptr->name;
				cout << "Publisher Name: ";
				cin >> ptr->publisher;
				cout << "Author Name: ";
				cin >> ptr->author;
				count++;
				cout << "\n\n\t\t\t\t\t Record Updated Successfully" << endl;
			}
			ptr = ptr->next;
		}
	}
	if (count == 0)
	{
		cout << "\n\n\t\t\t\t\t No Record Found " << endl;
	}
}
void library::search_record()
{
	system("cls");
	cout << "\n\t\t\t\t\t----------------------------------------" << endl
		<< "\n\t\t\t\t\t|      Library Managment System        |" << endl
		<< "\n\t\t\t\t\t----------------------------------------" << endl;
	cout << endl << endl;
	int temp_id, count = 0;
	if (head == NULL)
	{
		cout << "\t\t\t\t\t Please Entered Any Record" << endl;
	}
	else
	{
		cout << "Enter Book ID: ";
		cin >> temp_id;
		node* ptr = head;
		while (ptr != NULL)
		{
			if (temp_id == ptr->id)
			{
				system("cls");
				cout << "Book ID: " << ptr->id << endl;
				cout << "Book Name: " << ptr->name << endl;
				cout << "Author Name: " << ptr->author << endl;
				cout << "Publisher Name: " << ptr->publisher << endl;
				count++;
			}
			ptr = ptr->next;
		}
	}
	if (count == 0)
	{
		cout << "\n\n\t\t\t\t\t No Record Found " << endl;
	}
}
int main()
{
	library obj;
	obj.title_page();
	obj.menu();
}