#include <iostream>
#include "Date.h"
#include "Crud.h"

using namespace std;

void InfoReturn(int *op, int *result)
{
	if (*result == 1)
	{
		if (*op == 1)
		{
			cout << "Successful physical person registration.";
		}
		
		if (*op == 2)
		{
			cout << "Successful physical person record editing.";
		}

		if (*op == 3)
		{
			cout << "Success to delete.";
		}
	}
	else
	{
		if (*op == 1)
		{
			cout << "Error registering Physical Person.";
		}

		if (*op == 2)
		{
			cout << "Error editing physical person record.";
		}

		if (*op == 3)
		{
			cout << "Error deleting physical person record.";
		}

		if (*op == 4)
		{
			cout << "Error when performing search by Physical Person.";
		}

		if (*op == 5)
		{
			cout << "Error when performing search by Physical Person.";
		}
	}
}

int main()
{
	int i = 1;
	int op = 0;
	int l;
	int result = 0;


	cout << "Registration's System" << "\n";

	while (i != 0)
	{
		for (l = 0; l<35; l++)
		{
			cout << "-";
		}
		cout << "\n1 - Insert Physical Person" << "\n";
		cout << "\n2 - Edit Physical Person" << "\n";
		cout << "\n3 - Delete Physical Person" << "\n";
		cout << "\n4 - Get Physical Person By ID" << "\n";
		cout << "\n5 - Get Physical Person By Name\n" << "\n";

		for (l = 0; l<35; l++)
		{
			printf("-");
		}

		cout << "\nOption's number.: ";
		cin >> op;

		switch (op)
		{
		case 1:
			cout << "\nInserting...\n";
			result = Crud::Insert_Customer("John", "john@test.xxx", 3333.77, Date(1981, 11, 12), "M");
			InfoReturn(&op, &result);
			break;

		case 2:
			cout << "\nEditing...\n";
			result = Crud::Edit_Customer(123, "Jeniffer", "jenny@test.xxx", 7777.33, Date(1991, 12, 11), "F");
			InfoReturn(&op, &result);
			break;
		
		case 3:
			cout << "\nDeleting...\n";
			result = Crud::Delete_Customer(123);
			InfoReturn(&op, &result);
			break;

		case 4:
			cout << "\nSearching by id...\n";
			result = Crud::GetPhysicalPersonByID(123);
			InfoReturn(&op, &result);
			break;

		case 5:
			cout << "\nSearching by name...\n";
			result = Crud::GetPhysicalPersonByName("J");
			InfoReturn(&op, &result);
			break;

		default:
			cout << "\nInvalid's Option.";
			break;
		}

		cout << "\n\nContinue?";
		cin >> i;
		cout <<"\n\n";
	}

	cout << "\n\nFinished.\n\n";

	system("PAUSE");
	return 0;
}
