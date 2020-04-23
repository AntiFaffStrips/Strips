#pragma once
#include <string>
#include "CBox.h"
#include <list>
#include <unordered_map>

//TODO: Add commentary for overall class
class CPosition
{
public:
	//get methods
	CPosition(std::string ICAO, std::list<CBox> boxes, std::list<std::string> adjacentControllers, char atis, int runway, std::unordered_map<std::string, bool> sids, int qnh, std::string callsignSelected);
	std::string getICAO();
	std::list<CBox> getBoxes();
	std::list<std::string> getAdjacentControllers();
	char getAtis();
	int getRunway();
	std::unordered_map<std::string, bool> getQNH();
	std::string getCallsignSelected();

	//update methods

};