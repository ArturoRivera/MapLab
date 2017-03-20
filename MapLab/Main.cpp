#include "Map.h"
#include <iostream>
#include <string>
using namespace std;


void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);
void PathToHome(Map &map);

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
		cout << "0) Exit" << endl;
		cin >> choice;


		switch (choice)
		{
		case 1: cout << map.CurrentLocation->getName() << endl; break;
		case 2: GoNorth(map); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		case 6: PathToHome(map); break;
		default: break;
		}

		system("pause");

	}

	system("pause");
	return 0;
}


void GoNorth(Map &map)
{
	system("cls");
	if (map.CurrentLocation->North == nullptr)
	{
		cout << "You haven't been here before. Enter a Name: ";
		string newName;
		cin >> newName;

		map.CurrentLocation->North = new Location(newName);
		map.CurrentLocation->North->South = map.CurrentLocation;
	
	}
	map.CurrentLocation = map.CurrentLocation->North;
	cout << "You are now at " + map.CurrentLocation->getName() << endl;
	map.Path.push(map.CurrentLocation);

}


void GoSouth(Map &map) 
{
	system("cls");
	if (map.CurrentLocation->South == nullptr)
	{
		cout << "You haven't been here before. Enter a name for new location: ";
		string newName;
		cin >> newName;

		map.CurrentLocation->South = new Location(newName);
		map.CurrentLocation->South->North = map.CurrentLocation;

	}
	map.CurrentLocation = map.CurrentLocation->South;
	cout << "You are now at " + map.CurrentLocation->getName() << endl;
	map.Path.push(map.CurrentLocation);

}


void GoEast(Map &map)
{
	system("cls");
	if (map.CurrentLocation->East == nullptr)
	{
		cout << "You haven't been here before. Enter a name for new location:";
		string newName;
		cin >> newName;

		map.CurrentLocation->East = new Location(newName);
		map.CurrentLocation->East->West = map.CurrentLocation;
	}
	map.CurrentLocation = map.CurrentLocation->East;
	cout << "You are now at " + map.CurrentLocation->getName() << endl;
	map.Path.push(map.CurrentLocation);
}


void GoWest(Map &map)
{
	system("cls");
	if (map.CurrentLocation->West == nullptr)
	{
		cout << "You haven't been here before. Enter a name for the new location: ";
		string newName;
		cin >> newName;

		map.CurrentLocation->West = new Location(newName);
		map.CurrentLocation->West->East = map.CurrentLocation;
	}
	map.CurrentLocation = map.CurrentLocation->West;
	cout << "You are now at " + map.CurrentLocation->getName() << endl;
	map.Path.push(map.CurrentLocation);
}


void PathToHome(Map &map)
{
	//TODO Implement Path to Home Stack in reverse order
}