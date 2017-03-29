#pragma once
#include "Location.h"
#include <stack>
#include <queue>
#include <unordered_map>

class Map
{

private:
	std::stack<Location *> _locationsVisited;
	std::unordered_map<std::string, Location*> _mapLookup;
	std::queue<Location *> _HowDidIGetHere;
	Location * defaultPointer = nullptr;

public:
	Map(std::string startingLocationName);
	~Map();

	Location * CurrentLocation = nullptr;
	std::string PathToHome();
	void Move(Location *newLocation);
	Location * LookupLocationOnMap(int x, int y);
	std::string HowDidIGetHere();
};

