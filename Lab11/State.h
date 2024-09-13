#ifndef STATEH
#define STATEH

#include <iostream>
using namespace std;

class State {
	public:
		State();
		State(string, string, string, int, int, int);
		string getAbrv();
		string getName();
		string getCapital();
		int getPopulation();
		int getYear();
		int getCongress();
		void setAbrv(string);
		void setName(string);
		void setCapital(string);
		void setPopulation(int);
		void setYear(int);
		void setCongress(int);

	private:
		string stateAbrv, stateName, stateCapital;
		int statePopulation, stateYear, stateCongress;

};

#endif