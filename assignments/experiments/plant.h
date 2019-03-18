#ifndef PLANT_H
#define PLANT_H
#include <iostream>

class plant
{
	private:
		char* myID;
		int myGrowthRate;
		int myNutritionalValue;
		int myWaterRequirements;
	public:
		plant();
		plant(const char*, const int, const int, const int);
		~plant();
		plant(const plant&);
		plant& operator=(const plant&);
		char* getID() const;
		int getGrowth() const;
		int getNutrition() const;
		int getWater() const;
		friend std::ostream& operator<<(std::ostream& os, const plant& p);
};
inline std::ostream& operator<<(std::ostream& os, const plant& p)
{
	os << "Plant ID: " << p.getId() << " (";
	os << "G: " << p.getGrowth() << " ";
	os << "N: " << p.getNutrition() << " ";
	os << "W: " << p.getWater() << ")";
}
#endif
