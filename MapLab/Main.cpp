/*	Arturo Rivera
*	Project 2 - Map
*	C++ Project 
*/

#include "Map.h"
#include <iostream>
#include <string>
using namespace std;


void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);


int main()
{
	Map map = Map("Home");

	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "1) Display Current Location" << endl;
		cout << "2) Go North" << endl;
		cout << "3) Go East" << endl;
		cout << "4) Go South" << endl;
		cout << "5) Go West" << endl;
		cout << "6) Path To Home" << endl;
		cout << "7) How Did I Get Here?" << endl;
		cout << "0) Exit" << endl;
		cin >> choice;


		switch (choice)
		{
		case 1: cout << "Current Location: " << map.CurrentLocation->DisplayLocationInfo() << endl; break;
		case 2: GoNorth(map); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		case 6: system("cls"); cout << map.PathToHome(); break;
		case 7: system("cls"); cout << map.HowDidIGetHere(); break;
		default: cout << "Inalid Entry, Please try again."; break;
		}

		system("pause");

	}

	system("pause");
	return 0;
}


void GoNorth(Map &map)
{
	auto newLocation = map.CurrentLocation->North;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();

	if (newLocation == nullptr)
	{
		int newX = currentX;
		int newY = currentY + 1;
		auto existing = map.LookupLocationOnMap(newX, newY);


		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before. Enter a name: ";
			string newName;
			cin >> newName;

			newLocation = new Location(newName, newX, newY);
			cout << "This place is now called: " + newName << endl;
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
		}
	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->South = map.CurrentLocation;
	map.Move(newLocation);
	return;
}


void GoSouth(Map &map)
{
	auto newLocation = map.CurrentLocation->South;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();

	if (newLocation == nullptr)
	{
		int newX = currentX;
		int newY = currentY - 1;
		auto existing = map.LookupLocationOnMap(newX, newY);


		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before. Enter a name: ";
			string newName;
			cin >> newName;
			newLocation = new Location(newName, newX, newY);
			cout << "This place is now called: " + newName << endl;
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
		}
	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->North = map.CurrentLocation;
	map.Move(newLocation);
	return;
}


void GoEast(Map &map)
{
	auto newLocation = map.CurrentLocation->East;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();

	if (newLocation == nullptr)
	{
		int newX = currentX + 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);


		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before. Enter a name: ";
			string newName;
			cin >> newName;

			newLocation = new Location(newName, newX, newY);
			cout << "This place is now called: " + newName << endl;
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
		}
	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->West = map.CurrentLocation;
	map.Move(newLocation);
	return;
}


void GoWest(Map &map)
{
	auto newLocation = map.CurrentLocation->West;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();

	if (newLocation == nullptr)
	{
		int newX = currentX - 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);


		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before. Enter a name: ";
			string newName;
			cin >> newName;

			newLocation = new Location(newName, newX, newY);
			cout << "This place is now called: " + newName << endl;
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
		}
	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->East = map.CurrentLocation;
	map.Move(newLocation);
	return;
}
