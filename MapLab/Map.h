#pragma once
#include "Location.h"
#include <stack>

class Map
{

private:


public:
	Map(std::string startingLocationName);
	~Map();

	Location * CurrentLocation = nullptr;
	std::string PathToHome();
	std::stack<Location *> Path;
};

