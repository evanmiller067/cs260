#include "plant.h"
#include <cstring>

plant::plant(): myID(nullptr), myGrowthRate(0), myNutritionalValue(0), myWaterRequirement(0){}

plant::plant(const char* ID, const int growthRate, const int nutritionalValue, const int waterRequirement): myGrowthRate(growthRate), myNutritionalValue(nutritionalValue), myWaterRequirement(waterRequirement)
{
	myID = new char[std::strlen(ID)+1];
	std::strncpy(myID, ID, std::strlen(ID)+1);
}
plant::~plant()
{
	delete [] myID;
}
plant::plant(const plant& p): myGrowthRate(p.getGrowth()), myNutritionalValue(p.getNutrition()), myWaterRequirement(p.getWater())
{
	if(p.getID() != nullptr)
	{
		myID = new char[std::strlen(p.getID())+1];
		std::strncpy(myID, p.getID(), std::strlen(p.getID())+1);
	}
	else
	{
		myID = nullptr;
	}
}
plant& plant::operator=(const plant& p)
{
	if (this != &p)
	{
		if (myID != nullptr)
		{
			delete[] myID;
		}
		if (p.getID() != nullptr)
		{
			myID = new char[std::strlen(p.getID())+1];
			std::strncpy(myID, p.getID(), std::strlen(p.getID())+1);
		}
		else
		{
			myID = nullptr;
		}
		myGrowthRate = p.getGrowth();
		myNutritionalValue = p.getNutrition();
		myWaterRequirement = p.getWater();
	}
	return *this;
}
char* plant::getID() const
{
    return myID;
}

int plant::getGrowth() const
{
    return myGrowthRate;
}
int plant::getNutrition() const
{
	return myNutritionalValue;
}
int plant::getWater() const
{
	return myWaterRequirement;
}
