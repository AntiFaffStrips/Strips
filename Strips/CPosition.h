#pragma once
#include <string>
#include "CBox.h"
#include <list>
#include <unordered_map>

/**
* Class for a position.
*
* This class contains information on the position that someone is controlling. This will change over time and is depending on what other ATC is online
*
* As of now it only contains functionality to get the members of the class and to update the member variables, This may change with further devleopment of the project
*/
class CPosition
{
public:
	/**
	* Class constructor
	*
	* @param string with the ICAO of the airport the being controlled - Must start with "EG" (be in the uk)
	* @param list of CBox objects with the boxes that are required for this position - The list must not be null and must not be empty.
	* @param list of adjacent controllers that are currently online - each callsign in the list must be valid(callsign must contain at least 1 underscore, start with "EG" and have an extension after the last underscore of any of the following: "DEL", "GND", "TWR", "APP", "CTR") and the list must not be null or emtpy.
	* @param character with the current atis information - character must be uppercase and be in the range A-Z inclusive. and cannot be null
	* @param integer with the current runway in use - integer must not be null and must be in the range 1-36 inclusive
	* @param unordered map which maps a string with the sid to a boolean which is true if freeflow and false otherwise - each sid must be a valid sid for that aiport(should be achieved by only loading sids from the approved .xml files and an incorrect sid will not throw and exception), map cannot be null nor can any sid in the map or the mapped booolean value.
	* @param integer with the current QNH - Must not be null and vlaue must be in the range 931-1067
	* @param string with the callsign selected - must not be null and must have an associated CStrip object
	* 
	* @throws exception if any of the inputs are invalid. Details on what is valid above
	*/
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

	//public static methods - (non at the moment but leaving space to add if needed)

private:
	//member variables
	std::string ICAO;
	std::list<CBox> boxes;
	std::list<std::string> adjacentControllers;
	char atis;
	int runway;
	std::unordered_map<std::string, bool> sids;
	int qnh;
	std::string callsignSelected;
};