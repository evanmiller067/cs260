#include "linkedlist.h"

//constructors
linkedList::linkedList()
{
	timeHead = nullptr;
	timeTail = nullptr;
	
	temperatureHead = nullptr;
	temperatureTail = nullptr;

	windHead = nullptr;
	windTail = nullptr;

	//most common data counters
	timeMC = 0;
	timeMCCount = 0;
	
	temperatureMC = 0;
	temperatureMCCount = 0;

	windMC = 0;
	windMCCount = 0;

	listLength = 0;
}
//Destructors
linkedList::~linkedList()
{
	if (timeHead)
	{
		for(weatherData* current = timeHead->timeNext; current != nullptr; current = current->timeNext)
	{
		delete current->timePrev;
	}
	delete timeTail;
	}
	//set ptrs back to null
	timeHead = nullptr;
	timeTail = nullptr;
	
	temperatureHead = nullptr;
	temperatureTail = nullptr;
	
	windHead = nullptr;
	windTail = nullptr;
}
//manipulators
void linkedList::addData(int time, int temperature, int wind)
{
	weatherData* newData = new weatherData;
	newData->timeData = time;
	newData->temperatureData = temperature;
	newData->windData = wind;
	
	//theres got to be a better way to write this
	newData->timeNext = nullptr;
        newData->temperatureNext = nullptr;
        newData->windNext = nullptr;

	newData->timePrev = nullptr;
	newData->temperaturePrev = nullptr;
	newData->windPrev = nullptr;

	//create first new object
	if(!timeHead)
	{
		timeHead = newData;
		temperatureHead = newData;
		windHead = newData;

		timeTail = newData;		
		temperatureTail = newData;
		windTail = newData;

		timeMC = time;
		timeMCCount = 1;
		
		temperatureMC = temperature;
		temperatureMCCount = 1;

		windMC = wind;
		windMCCount = 1;
		
		listLength = 1;
	}
	else
	{
		weatherData* current;
		bool location;

		listLength++;

		//create the three threads of the linked list
		
		//time
		current = timeHead;
		location = false;

		while(!location && current != nullptr)
		{
			if(time <= current->timeData)
			{
				location = true;
				newData->timeNext = current;
				newData->timePrev = current->timePrev;
				current->timePrev = newData;
				
				if(current != timeHead)
				{
					newData->timePrev->timeNext = newData; 
				}
			}
			else
			{
				current = current->timeNext;
			}
		}
		if(!current)
		{
			timeTail->timeNext= newData;
			newData->timePrev = timeTail;
			timeTail = newData;
		}
		
		//temperature
				
		current = temperatureHead;
                location = false;

                while(!location && current != nullptr)
                {
                        if(temperature <= current->temperatureData)
                        {
                                location = true;
                                newData->temperatureNext = current;
                                newData->temperaturePrev = current->temperaturePrev;
                                current->temperaturePrev = newData;

                                if(current != temperatureHead)
                                {
                                        newData->temperaturePrev->temperatureNext = newData;
                                }
                        }
                        else
                        {
                                current = current->temperatureNext;
                        }
                }
                if(!current)
                {
                        temperatureTail->temperatureNext= newData;
                        newData->temperaturePrev = temperatureTail;
                        temperatureTail = newData;
                }

		//windspeed

		current = windHead;
                location = false;

                while(!location && current != nullptr)
                {
                        if(wind <= current->windData)
                        {
                                location = true;
                                newData->windNext = current;
                                newData->windPrev = current->windPrev;
                                current->windPrev = newData;

                                if(current != windHead)
                                {
                                        newData->windPrev->windNext = newData;
                                }
                        }
                        else
                        {
                                current = current->windNext;
                        }
                }
                if(!current)
                {
                        windTail->windNext= newData;
                        newData->windPrev = windTail;
                        windTail = newData;
                }
	}	 
}
void linkedList::removeData(int timestamp)
{
	weatherData* rnt = nullptr; //removed node tracker 

	//check for duplicate data
	bool dupFound = false;

	weatherData* current = timeHead;
	
	while(!dupFound && current != nullptr)
	{
		if(current->timeData == timestamp)
		{
			dupFound = true;
			do
			{
				rnt = current;
				current = current->timeNext;
			
				//time	
				if(rnt == timeHead)
				{
					timeHead = rnt->timeNext;
				}
				else
				{
					rnt->timePrev->timeNext = rnt->timeNext;
				}
				if(rnt == timeTail)
				{
					timeTail = rnt->timePrev;
				}
				else
				{
					rnt->timeNext->timePrev = rnt->timePrev;
				}

				//temperature
                                if(rnt == temperatureHead)
                                {
                                        temperatureHead = rnt->temperatureNext;
                                }
                                else
                                {
                                        rnt->temperaturePrev->temperatureNext = rnt->temperatureNext;
                                }
                                if(rnt == temperatureTail)
                                {
                                        temperatureTail = rnt->temperaturePrev;
                                }
                                else
                                {
                                        rnt->temperatureNext->temperaturePrev = rnt->temperaturePrev;
                                }

				//windspeed
				if(rnt == windHead)
                                {
                                        windHead = rnt->windNext;
                                }
                                else
                                {
                                        rnt->windPrev->windNext = rnt->windNext;
                                }
                                if(rnt == windTail)
                                {
                                        windTail = rnt->windPrev;
                                }
                                else
                                {
                                        rnt->windNext->windPrev = rnt->windPrev;
                                }

				delete rnt;
				rnt = nullptr;
				listLength--;
			}
			while(current && current->timeData == timestamp);//end of do-while loop
		}
		else
		{
			current = current->timeNext;
		}
	}
}

void linkedList::mostCommon()
{
//find most common data point in each thread 
//this function is why I've been spelling out temperature instead of temp

	int tempCommon = 0, tempCCount = 0;
	//time
	for(weatherData* current = timeHead; current != nullptr; current = current->timeNext)
	{
		if(tempCommon != current->timeData)
		{
			tempCommon = current->timeData;
			tempCCount = 1;
		}
		else
		{
			tempCCount++;
			if(tempCCount > timeMCCount)
			{
				timeMC = tempCommon;
				timeMCCount = tempCCount;
			}
		}
	}
	//temperature
        for(weatherData* current = temperatureHead; current != nullptr; current = current->temperatureNext)
        {
                if(tempCommon != current->temperatureData)
                {
                        tempCommon = current->temperatureData;
                        tempCCount = 1;
                }
                else
                {
                        tempCCount++;
                        if(tempCCount > temperatureMCCount)
                        {
                                temperatureMC = tempCommon;
                                temperatureMCCount = tempCCount;
                        }
                }
        }
	//windspeed
        for(weatherData* current = windHead; current != nullptr; current = current->windNext)
        {
                if(tempCommon != current->windData)
                {
                        tempCommon = current->windData;
                        tempCCount = 1;
                }
                else
                {
                        tempCCount++;
                        if(tempCCount > windMCCount)
                        {
                                windMC = tempCommon;
                                windMCCount = tempCCount;
                        }
                }
        }
}

bool linkedList::containsTimestamp(int timestamp)
{
	bool contains = false;
	for(weatherData* current = timeHead; current != nullptr; current = current->timeNext)
	{
		if(current->timeData == timestamp)
		{
			contains = true;
		}
	}
	return contains;
}

float linkedList::averageTimeRange(int start, int end)
{
	int sum = 0, i = 0;
	weatherData* current;
	for(current = timeHead, i = 0; current != nullptr && i <= end; current = current->timeNext, i++)
	{
		if( i >= start)
		{
			sum += current->timeData;
		}
	}
	return static_cast<float>(sum) / static_cast<float>(end - start + 1);
}

float linkedList::averageTemperatureRange(int start, int end)
{
        int sum = 0, i = 0;
        weatherData* current;
        for(current = temperatureHead, i = 0; current != nullptr && i <= end; current = current->temperatureNext, i++)
        {
                if( i >= start)
                {
                        sum += current->temperatureData;
                }
        }
        return static_cast<float>(sum) / static_cast<float>(end - start + 1);

}

float linkedList::averageWindRange(int start, int end)
{
        int sum = 0, i = 0;
        weatherData* current;
        for(current = windHead, i = 0; current != nullptr && i <= end; current = current->windNext, i++)
        {
                if(i >= start)
                {
                        sum += current->windData;
                }
        }
        return static_cast<float>(sum) / static_cast<float>(end - start + 1);

}

int linkedList::timeRange(int start, int end)
{
	int sum = 0;
	weatherData* current = timeHead;
	bool outOfRange = false;
	while(!outOfRange && current != nullptr)
	{
		if(current->timeData >= start)
		{ 
			if(current->timeData <= end)
			{
				sum++;
			}
		}
		else
		{
			outOfRange = true;//break while loop
		}
	current = current->timeNext;
	}
	return sum;
}

int linkedList::temperatureRange(int start, int end)
{
        int sum = 0;
        weatherData* current = temperatureHead;
        bool outOfRange = false;
        while(!outOfRange && current != nullptr)
        {
                if(current->temperatureData >= start) 
		{	
			if(current->temperatureData <= end)
                	{
                       		sum++;
                	}
		}
                else
                {
                        outOfRange = true;//break while loop
                }
	current = current->temperatureNext;
        }
        return sum;
}

int linkedList::windRange(int start, int end)
{
        int sum = 0;
        weatherData* current = windHead;
        bool outOfRange = false;
        while(!outOfRange && current != nullptr)
        {
                if(current->windData >= start)
		{
			if(current->windData <= end)
                	{
                        	sum++;
                	}
		}
                else
                {
                        outOfRange = true;//break while loop
                }
	current = current->windNext;
        }
        return sum;
}

//class get functions
int linkedList::getTimeHead()
{
	int val = 0;
	if(timeHead)
	{
		val = timeHead->timeData;
	}
	return val;
}

int linkedList::getTimeTail()
{
        int val = 0;
        if(timeTail)
        {
                val = timeTail->timeData;
        }
        return val;
}

int linkedList::getTemperatureHead()
{
        int val = 0;
        if(temperatureHead)
        {
                val = temperatureHead->temperatureData;
        }
        return val;
}

int linkedList::getTemperatureTail()
{
        int val = 0;
        if(temperatureTail)
        {
                val = temperatureTail->temperatureData;
        }
        return val;
}

int linkedList::getWindHead()
{
        int val = 0;
        if(windHead)
        {
                val = windHead->windData;
        }
        return val;
}

int linkedList::getWindTail()
{
        int val = 0;
        if(windTail)
        {
                val = windTail->windData;
        }
        return val;
}

int linkedList::getTimeMC()
{
	return timeMC;
}

int linkedList::getTemperatureMC()
{
        return temperatureMC;
}

int linkedList::getWindMC()
{
        return windMC;
}

int linkedList::getTimeMCCount()
{
        return timeMCCount;
}

int linkedList::getTemperatureMCCount()
{
        return temperatureMCCount;
}

int linkedList::getWindMCCount()
{
        return windMCCount;
}

int linkedList::getListLength()
{
        return listLength;
}
