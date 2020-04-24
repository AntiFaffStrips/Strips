#pragma once
#include <string>
#include "CBox.h"
#include <list>
#include <unordered_map>

//TODO: Add commentary for overall class
class CPosition
{
public:
	//class constructor
	CPosition(std::string ICAO, std::list<CBox> boxes, std::list<std::string> adjacentControllers, char atis, int runway, std::unordered_map<std::string, bool> sids, int qnh, std::string callsignSelected); //needs issue update

	//get methods
	std::string getICAO();
	std::list<CBox> getBoxes();
	std::list<std::string> getAdjacentControllers();
	char getAtis();
	int getRunway();
	std::unordered_map<std::string, bool> getQNH();
	std::string getCallsignSelected();

	//update methods
	void updateAdjacentControllers(std::unordered_map < std::list<std::string>, std::list<std::string>> updateInfo); //needs issue update
	void updateAtis(char newAtis);
	void updateAtis(int change);
	void updateRunway(int newRunway);
	void updateQNH(int newQNH);//needs issue iupdate
	void updateCallsignSelected(std::string newCallsign);

	//other instance methods - (non at the moment but leaving space to add if needed)

	//static methods - (non at the moment but leaving space to add if needed)
};