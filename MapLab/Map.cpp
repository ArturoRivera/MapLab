#include "Map.h"



Map::Map(std::string startingLocationName)
{
	CurrentLocation = new Location(startingLocationName);
	Path.push(CurrentLocation);
}


Map::~Map()
{
}

std::string Map::PathToHome()
{
	return "TODO: Implement This";
}
