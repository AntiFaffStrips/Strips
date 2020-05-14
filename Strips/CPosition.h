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
	* @param list of adjacent controllers that are currently online - each callsign in the list must be valid (callsign must contain at least 1 underscore and have an extension after the last underscore of any of the following: "DEL", "GND", "TWR", "APP", "CTR") and the list must not be null or emtpy.
	* @param character with the current atis information - character must be uppercase and be in the range A-Z inclusive. and cannot be null
	* @param string with the current departure runway - Must be in the range 1-36 with an optional "L" or "R" appended
	* @param string with the current arrival runway - Must be in the range 1-36 with an optional "L" or "R" appended
	* @param unordered map which maps a string with the sid to a boolean which is true if freeflow and false otherwise - each sid must be a valid sid for that aiport(should be achieved by only loading sids from the approved .xml files and an incorrect sid will not throw and exception), map cannot be null nor can any sid in the map or the mapped booolean value.
	* @param integer with the current QNH - Must not be null and value must be in the range 931-1067
	* @param string with the callsign selected - must not be null and must have an associated CStrip object
	* 
	* @throws exception if any of the inputs are invalid. Details on what is valid above
	*/
	CPosition(std::string ICAO, std::list<CBox> boxes, std::list<std::string> adjacentControllers, char atis, std::string depRunway, std::string arrRunway, std::unordered_map<std::string, bool> SIDs, int qnh, std::string callsignSelected);

	//get methods
	/**
	* Method to get the ICAO of the current position instance
	* 
	* @return String with the ICAO of the position being controlled
	*/
	std::string getICAO();
	/**
	*  Method to get a list of the boxes that is boxes for the current position instance
	*
	* @return list of CBox instances with the boxes required for the current position
	*/
	std::list<CBox> getBoxes();
	/**
	* Method to get a list of the adjacent controllers that are relevant to the current position instance
	*
	* @return list of Strings holding the current adjacent controllers
	*/
	std::list<std::string> getAdjacentControllers();
	/**
	* Method to get the current ATIS info for the current position instance
	*
	* @return char with the current ATIS info stored the position
	*/
	char getAtis();
	/**
	* Method to get the current runway in use for the current positon instance
	*
	* @return int between 1-36 with an optional "L" or "R" to show the current departure runway
	*/
	std::string getDepRunway();
	/**
	* Method to get the current departure runway for the current positon instance
	*
	* @return int between 1-36 with an optional "L" or "R" to show the current arrival runway
	*/
	std::string getArrRunway();
	/**
	* Method to get the sids which are freeflow on the current position instance
	*
	* @return unordered map which maps a string to a boolean where the string is the SID and the bool is whether the sid is freeflow or not where true = freeflow
	*/
	std::unordered_map<std::string, bool> getSIDs();
	/**
	* Method to get the sids for the airfield and whether they are currently free flow or not from the current position instance
	*
	* @return int holding the current QNH
	*/
	 int getQNH();
	/**
	* Method to get the current selected callsign for the current position instance
	*
	* @return string with the callsign of the strip that is currently selected. If there is no selected position then the empty string is returned
	*/
	std::string getCallsignSelected();

	//update methods
	/**
	* Method to update the current adjacent contorllers in the current position instance
	*
	* @param list of strings with the callsigns of the controllers online from euroscope - must not be null or empty
	* 
	* @throws exception with error message if the input is invalid. Details on what is valid is found above
	*/
	void updateAdjacentControllers(std::list<std::string> fullAdjacentControllers);
	/**
	* Method to update the current ATIS information in the current position instance with a character to change to(from euroscope)
	*
	* @param char with the new ATIS info - Must not be null and must be in the range A-Z uppercase
	*
	* @throws exception with error message if the perameter is invalid. Details on what is valid can be found above
	*/
	void updateAtis(char newAtis);
	/**
	* Method to update the current ATIS information in the current position instance with an integer(from UI)
	*
	* @param int which is 1 if info is to be increased by 1 and -1 if it info is to be decreased by 1 - Must be either the number 1 or -1
	*
	* @throws exception with error message if the perameter is invalid. Details on what is valid can be found above
	*/
	void updateAtis(int change);
	/**
	* Method to update the current departure runway for the current position instance.
	*
	* @param string with the runway to update to - Must not be null and must be in the range 1-36 with an optional "R" or "L" appended
	*
	* @throws exception with error message if the perameter is invalid. Details on what is valid can be found above
	*/
	void updateDepRunway(int newRunway);
	/**
	* Method to update the current arrival runway for the current position instance.
	*
	* @param string with the runway to update to - Must not be null and must be in the range 1-36 with an optional "R" or "L" appended
	*
	* @throws exception with error message if the perameter is invalid. Details on what is valid can be found above
	*/
	void updateArrRunway(int newRunway);
	/**
	* Method to update which sids are freeflow in the current position index
	*
	* @param string with the sid to toggle - should be a valid sid and exception will not be thrown as the SID is passed from the front end and will be assumed to be valid as the data is given to front end from this class.
	*/
	void updateSIDs(std::string SID);
	/**
	* Method to update the current QNH in the current position instance
	*
	* @param int with the new QNH to change to - Must not be null and value must be in the range 931-1067
	*
	* @throws exception with error message if the perameter is invalid. Details on what is valid can be found above
	*/
	void updateQNH(int newQNH);
	/**
	* Method to update the current selected callsign in the current position instance
	*
	* @param string with the new callsign to be selected (if empty string then there is no selected position) - Must not be null and must be a valid callsign (callsign must contain at least 1 underscore, start with "EG" and have an extension after the last underscore of any of the following: "DEL", "GND", "TWR", "APP", "CTR")
	*
	* @throws exception with error message if the perameter is invalid. Details on what is valid can be found above
	*/
	void updateCallsignSelected(std::string newCallsign);

	//other instance methods - (non at the moment but leaving space to add if needed)

	//public static methods - (non at the moment but leaving space to add if needed)

private:
	//member variables
	/**
	* string holding the ICAO of the current position being controlled - Must start with "EG"
	*/
	std::string m_ICAO;
	/**
	* List of CBox instances holding the boxes required for this position - The list must not be empty. 
	*/
	std::list<CBox> m_boxes;
	/**
	* list of strings each holding the callsign of an adjacent controller - each callsign in the list must be valid  and the list must not be null or emtpy
	*/
	std::list<std::string> m_adjacentControllers;
	/**
	* char holding the current atis information - character must be uppercase and be in the range A-Z inclusive
	*/
	char m_ATIS;
	/**
	* string holding the current departure runway - Must be in the range 1-36 inclusive with an optional "L" or "R" or appended to the end of the number
	*/
	std::string m_depRunway;
	/**
	* string holding the current arrival runway - Must be in the range 1-36 inclusive with an optional "L" or "R" or appended to the end of the number
	*/
	std::string m_arrRunway;
	/**
	* unordered map which maps a string with the sid to a boolean which is true if freeflow and false otherwise - each sid must be a valid sid for that aiport(should be achieved by only loading sids from the approved .xml files and an incorrect sid will not throw and exception)
	*/
	std::unordered_map<std::string, bool> m_SIDs; //needs issue update
	/**
	* int holding the current QNH - Must be in the range 931-1067
	*/
	int m_QNH;
	/**
	* with the callsign selected - Must have an associated CStrip object
	*/
	std::string m_callsignSelected;
};