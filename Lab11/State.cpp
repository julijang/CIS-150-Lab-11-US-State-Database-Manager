#include "State.h"
#include <iostream>
#include <iomanip>

using namespace std;

State::State() {
	stateAbrv = "MI";
	stateName = "Michigan";
	stateCapital = "Lansing";
	statePopulation = 0;
	stateYear = 0;
	stateCongress = 0;
}

State::State(string abrv, string name, string capital, int population, int year, int congress) {
	stateAbrv = abrv;
	stateName = name;
	stateCapital = capital;
	statePopulation = population;
	stateYear = year;
	stateCongress = congress;
}

string State::getAbrv() {
	return stateAbrv;
}

string State::getName() {
	return stateName;
}

string State::getCapital() {
	return stateCapital;
}

int State::getPopulation() {
	return statePopulation;
}

int State::getYear() {
	return stateYear;
}

int State::getCongress() {
	return stateCongress;
}

void State::setAbrv(string abrv) {
	stateAbrv = abrv;
}

void State::setName(string name) {
	stateName = name;
}

void State::setCapital(string capital) {
	stateCapital = capital;
}

void State::setPopulation(int population) {
	statePopulation = population;
}

void State::setYear(int year) {
	stateYear = year;
}

void State::setCongress(int congress) {
	stateCongress = congress;
}