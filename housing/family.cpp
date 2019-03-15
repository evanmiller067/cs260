#include "family.h"
#include <iostream>
#include <cstring>

//default constructor
family::family():
	f_id(nullptr),
	f_name(nullptr),
	f_friends(nullptr),
	f_numberOfMembers(0),
	f_numberOfFriends(0)
{}
//constructor
family::family(const char* id, const char* name, const int numberOfMembers): f_numberOfFriends(0), f_numberOfMembers(numberOfMembers),f_friends(nullptr)
{
	//copy id and name intp new char array
	f_id = new char[strlen(id)+1];
	strncpy(f_id, id, (strlen(id)+1));
	
	f_name = new char[strlen(name)+1];
	strncpy(f_name, name, (strlen(name)+1));
}

//copy constructor
family::family(const family& copy): f_numberOfFriends(copy.getNumberOfFriends()), f_numberOfMembers(copy.getNumberOfMembers())
{
	//id
	if(copy.getID() != nullptr)
	{
		f_id = new char[strlen(copy.getID())+1];
		strncpy(f_id, copy.getID(), strlen(copy.getID())+1);
	}
	else
	{
		f_id = nullptr;
	}
	//name
        if(copy.getName() != nullptr)
        {
                f_name = new char[strlen(copy.getName())+1];
                strncpy(f_name, copy.getName(), strlen(copy.getName())+1);
        }
        else
        {
                f_name = nullptr;
        }
	//friends
	if(copy.getFriends() != nullptr)
	{
		f_friends = new char*[MAX_FRIENDS];
		char** friends = copy.getFriends();
		for(int i = 0; i < MAX_FRIENDS; i++)
		{
			if(friends[i] != nullptr)
			{
				f_friends[i] = new char[strlen(friends[i])+1];
				strncpy(f_friends[i], friends[i], (strlen(friends[i])+1));
			}
			else
			{
				f_friends[i] = nullptr;
			}
		}
	}
	else
	{
		f_friends = nullptr;
	}
}
//Copy assignment operator
//https://en.cppreference.com/w/cpp/language/copy_assignment
family& family::operator=(const family& f)
{
	//dellocate memory
	if(this != &f)
	{
		if(f_id != nullptr)
		{
			delete[] f_id;
		}
		if(f_name != nullptr)
		{
			delete[] f_name;
		}
		if(f_friends != nullptr)
		{
			for(int i = 0; i < MAX_FRIENDS; i++)
			{
				if(f_friends[i] != nullptr)
				{
					delete[] f_friends[i];
				}
			}
		delete[] f_friends;
		}
	//allocate new memory w/values
	if(f.getID() != nullptr)
	{
		f_id = new char[strlen(f.getID())+1];
		strncpy(f_id, f.getID(), strlen(f.getID())+1);
	}
	else
	{
		f_id = nullptr;
	}
        if(f.getName() != nullptr)
        {
                f_name = new char[strlen(f.getName())+1];
                strncpy(f_name, f.getName(), strlen(f.getName())+1);
        }
        else
        {
                f_name = nullptr;
        }
	f_numberOfFriends = f.getNumberOfFriends();
	f_numberOfMembers = f.getNumberOfMembers();
	
	if(f.getFriends() != nullptr)
	{
		f_friends = new char*[MAX_FRIENDS];
		char** friends = f.getFriends();
		for(int i = 0; i < MAX_FRIENDS; i++)
		{
			if(friends[i] != nullptr)
			{
				f_friends[i] = new char[strlen(friends[i])+1];
				strncpy(f_friends[i], friends[i], strlen(friends[i])+1);
			}
			else
			{
				f_friends[i] = nullptr;
			}
		}	
	}
	else
	{
		f_friends = nullptr;
	}
	}
	return *this;
}
//destructor
family::~family()
{
	if(f_id != nullptr)
	{
		delete[] f_id;
	}
	if(f_name != nullptr)
	{
		delete[] f_name;
	}
	if(f_friends != nullptr)
	{
		for(int i = 0; i < MAX_FRIENDS; i++)
		{
			if(f_friends[i] != nullptr)
			{
				delete[] f_friends[i];
			}
		}
		delete[] f_friends;
	}
}
//getter and setter functions
char* family::getID() const
{
	return f_id;
}
char* family::getName() const 
{
	return f_name;
}
char** family::getFriends() const
{
	return f_friends;
}
int family::getNumberOfFriends() const
{
	return f_numberOfFriends;
}
int family::getNumberOfMembers() const
{
	return f_numberOfMembers;
}
bool family::addFriend(const char* name)
{
	if(getNumberOfFriends() >= MAX_FRIENDS)
	{
		return false;
	}
	if(f_friends == nullptr)
	{
		f_friends = new char*[MAX_FRIENDS];
		for(int i = 0; i < MAX_FRIENDS; i++)
		{
			f_friends[i] = nullptr;
		}
	}
	if(name[0] == '\0')
	{
		return false;
	}
	f_friends[f_numberOfFriends] = new char[strlen(name)+1];
	strncpy(f_friends[f_numberOfFriends], name, strlen(name)+1);
	f_numberOfFriends++;
	return true;
}
