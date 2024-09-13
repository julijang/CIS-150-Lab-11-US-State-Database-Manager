#include "State.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Declare each prototype
void callMenu();
int readFile(ifstream&, string, vector<State>&);
void searchByAbbrv(string, vector<State>&);
void searchByYear(int, vector<State>&);
string getAbbreviation(State&);
int getStatehood(State&);

int main() {
	// Declare user-input variables, filename constant, and vector list of states
	int menuoption, yearinput;
	string abrvinput;
	const string filename = "usstates.txt";
	ifstream ifs;
	vector<State> statesList;

	// Read the usstates.txt file and compile to vector list
	readFile(ifs, filename, statesList);

	// Display the options menu to the user and recieve user input
	callMenu();
	cin >> menuoption;

	// Switch statement corresponding with each user choice from the menu
	switch (menuoption){
	case 1:
		cout << "Enter state abbreviation: ";
		cin >> abrvinput;
		searchByAbbrv(abrvinput, statesList);
		break;
	case 2:
		cout << "Enter year of statehood: ";
		cin >> yearinput;
		searchByYear(yearinput, statesList);
		break;
	case 3:
		break;
	}

	return 0;
}

// callMenu function which displays user input options
void callMenu() {
	cout << "1. Search by state abbreviation (e.g. MI)." << endl;
	cout << "2. Search by year of statehood (e.g. 1837)." << endl;
	cout << "3. Exit program." << endl;
	cout << endl;
	cout << " Please enter your choice (1-3): ";
}

// readFile function which collects each file line, and parses between commas into the State class vector list
int readFile(ifstream& ifs, string filename, vector<State>& statesList) {

	ifs.open(filename);

	if (!ifs.is_open()) {
		cerr << "Unable to open file " << filename << endl;
		return 0;
	}

	string fileline;
	while (getline(ifs, fileline)) {
		istringstream iss(fileline);

		string abrv, name, capital, population, year, congress;

		getline(iss, abrv, ',');
		getline(iss, name, ',');
		getline(iss, capital, ',');
		getline(iss, population, ',');
		getline(iss, year, ',');
		getline(iss, congress, ',');

		statesList.push_back(State(abrv, name, capital, stoi(population), stoi(year), stoi(congress)));
	}

	ifs.close();

	return 0;
}

// searchByAbbrv function will loop through each element of the stateList vector list and output each line containing the
// inputted abbreviation.
void searchByAbbrv(string abrvinput, vector<State>& statesList) {
	bool queryexists = false;

	for (int i = 0; i < statesList.size(); i++) {
		if (statesList.at(i).getAbrv() == abrvinput) {
			queryexists = true;
			break;
		}
	}

	if (queryexists) {
		cout << "State Abr. | Name | Capital | Population | Year | #Congress" << endl;
	}

	for (int i = 0; i < statesList.size(); i++) {
		if (statesList.at(i).getAbrv() == abrvinput) {
			cout << statesList.at(i).getAbrv() << "         | " 
				<< statesList.at(i).getName() << " | " 
				<< statesList.at(i).getCapital() << " | " 
				<< statesList.at(i).getPopulation() << " | " 
				<< statesList.at(i).getYear() << " | "
				<< statesList.at(i).getCongress() << endl;
		}
	}

	if (!queryexists) {
		cout << "No state exists with this information" << endl;
	}
}

// searchByAbbrv function will loop through each element of the stateList vector list and output each line containing the
// inputted year it became a state.
void searchByYear(int yearinput, vector<State>& statesList) {
	bool queryexists = false;

	for (int i = 0; i < statesList.size(); i++) {
		if (statesList.at(i).getYear() == yearinput) {
			queryexists = true;
			break;
		}
	}

	if (queryexists) {
		cout << "State Abr. | Name | Capital | Population | Year | #Congress" << endl;
	}

	for (int i = 0; i < statesList.size(); i++) {
		if (statesList.at(i).getYear() == yearinput) {
			cout << statesList.at(i).getAbrv() << "         | "
				<< statesList.at(i).getName() << " | " 
				<< statesList.at(i).getCapital() << " | " 
				<< statesList.at(i).getPopulation() << " | " 
				<< statesList.at(i).getYear() << " | "
				<< statesList.at(i).getCongress() << endl;
		}
	}

	if (!queryexists) {
		cout << "No state exists with this information" << endl;
	}
} 