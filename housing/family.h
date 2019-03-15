#ifndef FAMILY_H
#define FAMILY_H

#include <cstddef> //for size_t use
#include <iostream>
using namespace std;

class family 
{
	public:
		const int MAX_FRIENDS = 3;
		family();
		//constructor and copy constructor
		family(const char* id, const char* name, const int numberOfMembers);
		family(const family& copy);
		//destructor
		~family();
		//getters/setters
		char* getID() const;
		char* getName() const;
		int getNumberOfMembers() const;
		char** getFriends() const;
		int getNumberOfFriends() const;		
		void setID(const char* id);
		void setName(const char* name);
		bool addFriend(const char* name);
		family& operator = (const family& f);
		//overloading io operator and using friend function
		//info pulled from:
		// https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/
		//half way down page
		friend ostream& operator<<(ostream& os, family& f);

	private:
		char* f_id;
		char* f_name; // f_ indicates family class private member
		char** f_friends;
		int f_numberOfMembers;
		int f_numberOfFriends;
};

//iostream overload
inline ostream& operator<<(ostream& os, family& f)
{
	os << "Family ID: " << f.getID() << endl;
	os << "  Name: " << f.getName() << endl;
	os << "  Members: " << f.getNumberOfMembers() << endl;
	char** friends = f.getFriends();
	if(f.getNumberOfFriends() > 0)
	{
		os << "  Friends:";
		for(int i = 0; i < f.getNumberOfFriends(); i++)
		{
			os << " " << friends[i];
		}
		os << endl;
	}
}
#endif
