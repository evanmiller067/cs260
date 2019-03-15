#include "datalogger.h"
#include <iostream>
#include <iomanip>

using namespace std;

//constant declared for range functions
const int RANGES_MAX = 10;

//add data to linkedlist 
void datalogger::addData(int timestamp, int temperature, int windspeed)
{
	list.addData(timestamp, temperature, windspeed);
}

//remove duplicate data, send to new report
void datalogger::removeData(int timestamp)
{
	list.removeData(timestamp);
}

//print reports
void datalogger::printReport(const char* label)
{
	list.mostCommon();

	cout << "\t\t\t\t -- Data Report (" << label << ") --" << endl;
	cout << " Time range: " <<  setw(6) << right << list.getTimeHead() << " - " << list.getTimeTail() << endl;
	cout << " Number of entries " <<  setw(6) << right <<  list.getListLength() << endl;
	cout << " Number of entries with < -50C temperature " << setw(6) << right << list.temperatureRange(list.getTemperatureHead(), -501) << endl;
	cout << " Number of entries with > 0C temperature " << setw(6) << right << list.temperatureRange( 1, list.getTemperatureTail()) << endl;
	cout << " Most common temperature " << setw(6) << right << static_cast<float>(list.getTemperatureMC() / 10) << endl;
	cout << " Number of entries with 0 windspeed " << setw(6) << right <<list.windRange( 0, 0) << endl;
	cout << " Number of entries with > 25 m/s windspeed " << setw(6) << right << list.windRange( 2501, list.getWindTail()) << endl;
	cout << " Most common windspeed " << setw(6) << right << list.getWindMC() << endl;
	cout << endl;
	cout << " Average temperature over ranges " << endl;
	int groupCount = list.getListLength() / RANGES_MAX;
	for (int i = 0; i < RANGES_MAX; i++)
	{
		cout << i * groupCount << " through " << (i+1) * groupCount - 1;
		cout << setw(6) << right << fixed << setprecision(1);
		cout << list.averageTemperatureRange( i * groupCount, (i + 1) * groupCount - 1) / 10 << endl;
	}
	cout << " Average windspeed over ranges " << endl;
	for (int i = 0; i < RANGES_MAX; i++)
	{
		cout << i * groupCount << " through " << (i+1) * groupCount - 1;
		cout << setw(6) << right << fixed << setprecision(1);
		cout << list.averageWindRange( i * groupCount, (i + 1) * groupCount - 1) / 100 << endl;
	}
}

//check if file already has timestamp
bool datalogger::containsTimestamp(int timestamp)
{
	return list.containsTimestamp(timestamp);
}

