#include "Map.h"
#include <iostream>
using namespace std;


Map::Map(std::string startingLocationName)
{
	CurrentLocation = new Location(startingLocationName, 0, 0);
	_locationsVisited.push(CurrentLocation);
	_HowDidIGetHere.push(CurrentLocation);
	std::string hash = "(0,0)";
	_mapLookup[hash] = CurrentLocation;
	defaultPointer = CurrentLocation;
}



Map::~Map()
{
}



void Map::Move(Location *newLocation)
{
	_locationsVisited.push(newLocation);
	_HowDidIGetHere.push(newLocation);
	CurrentLocation = newLocation;
}



Location * Map::LookupLocationOnMap(int x, int y)
{
	std::string hash = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
	return _mapLookup[hash];
}



//Extra credit HowDidIGetHere queue
std::string Map::HowDidIGetHere()
{
	std::string result = "How you got here:\n";
	while (_HowDidIGetHere.size() != 0)
	{
		result += _HowDidIGetHere.front()->DisplayLocationInfo();
		_HowDidIGetHere.pop();
		_locationsVisited.pop();
	}


	CurrentLocation = defaultPointer;

	return result;
}



//Path to home stack
std::string Map::PathToHome()
{
	std::string result = "Path to home: \n";

	while (_locationsVisited.size() != 0)
	{
		result += _locationsVisited.top()->DisplayLocationInfo();
		_locationsVisited.pop();
		_HowDidIGetHere.pop();
	}

	CurrentLocation = defaultPointer;

	return result;

}