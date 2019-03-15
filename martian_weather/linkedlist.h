#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class weatherData
{
	public:
        	int timeData;
        	weatherData* timeNext;
        	weatherData* timePrev;
        	int temperatureData;
        	weatherData* temperatureNext;
        	weatherData* temperaturePrev;
        	int windData;
        	weatherData* windNext;
        	weatherData* windPrev;
};

class linkedList
{
	private:
		weatherData* timeHead;
		weatherData* timeTail;
		weatherData* windHead; 
		weatherData* windTail;
		weatherData* temperatureHead; 
		weatherData* temperatureTail;
		int listLength;
	public:
                int timeMC, temperatureMC, windMC;
                int timeMCCount, temperatureMCCount, windMCCount;

		//constructor
		linkedList();

		//destructor
		~linkedList();
		linkedList & operator = (const linkedList&) = delete;
		linkedList(const linkedList&) = delete;

		//data manipulators
		void addData(int, int, int);
		void removeData(int);

		//return functions for clean data log
		void mostCommon();
		bool containsTimestamp(int);
		float averageTimeRange(int, int);
		float averageTemperatureRange(int, int);
		float averageWindRange(int, int);
		int timeRange(int, int);
		int temperatureRange(int, int);
		int windRange(int, int);
	
		//get functions
		int getTimeHead();
		int getTimeTail();
		int getTemperatureHead();
		int getTemperatureTail();
		int getWindHead();
		int getWindTail();
		int getTimeMC();
		int getTimeMCCount();
		int getTemperatureMC();
		int getTemperatureMCCount();
		int getWindMC();
		int getWindMCCount();
		int getListLength();
};

#endif
