#include "pch.h"
#include "CPosition.h"
#include "pch.h"
#include "CPosition.h"

const int C_ASCII_A = 65;
const int C_ASCII_Z = 91;

//TODO: - Check if the callsign in callsign selected exists to a strip instance

/**
* Class Constructor
*
* More details in CPosition.hs
*/
CPosition::CPosition(std::string ICAO, std::list<CBox> boxes, std::list<std::string> adjacentControllers, char ATIS, std::string depRunway, std::string arrRunway, std::unordered_map<std::string, bool> SIDs, int QNH, std::string callsignSelected) {
	//Checking inputs
	bool areInputsValid = isICAOValid(ICAO) && isBoxesValid(boxes) && isAdjacentControllersValid(adjacentControllers) && isAtisValid(ATIS) && isRunwayValid(depRunway) && isRunwayValid(arrRunway) && isSIDsValid(SIDs) && isQNHValid(QNH) && isCallsignSelectedValid(callsignSelected);
	if (!areInputsValid) {
		throw "ERROR: One or more of your inputs passed to class constructor in CPosiiton were invalid";
	}

	//Assigning Memeber Variables
	m_ICAO = ICAO;
	m_boxes = boxes;
	m_adjacentControllers = adjacentControllers;
	m_ATIS = ATIS;
	m_depRunway = depRunway;
	m_arrRunway = arrRunway;
	m_SIDs = SIDs;
	m_QNH = QNH;
	m_callsignSelected = callsignSelected;
}

//Get methods------------------------------------------------------------------------------------------------
/**
* Method to get the ICAO of the current position index
*
* More details can be found in .h file
*/
std::string CPosition::getICAO() {
	return m_ICAO;
}

/**
* Method to get the bxoes required for the current position index
*
* More details can be found in .h file
*/
std::list<CBox> CPosition::getBoxes() {
	return m_boxes;
}

/**
* Method to get the adjacent controllers for the current position index
*
* More details can be found in .h file
*/
std::list<std::string> CPosition::getAdjacentControllers() {
	return m_adjacentControllers;
}

/**
* Method to get the ATIS info for the current position index
*
* More details can be found in .h file
*/
char CPosition::getAtis() {
	return m_ATIS;
}

/**
* Method to get the Departure runway for the current position index
*
* More details can be found in .h file
*/
std::string CPosition::getDepRunway() {
	return m_depRunway;
}

/**
* Method to get the arrival runway of the current position index
*
* More details can be found in .h file
*/
std::string CPosition::getArrRunway() {
	return m_arrRunway;
}

/**
* Method to get the SIDs the are freeflow for the current position index
*
* More details can be found in .h file
*/
std::unordered_map<std::string, bool> CPosition::getSIDs() {
	return m_SIDs;
}

/**
* Method to get the QNH for the current position index
*
* More details can be found in .h file
*/
int CPosition::getQNH() {
	return m_QNH;
}

/**
* Method to get the CallsignSelected for the current position index
*
* More details can be found in .h file
*/
std::string CPosition::getCallsignSelected() {
	return m_callsignSelected;
}

//Update Methods-------------------------------------------------------------------------------------------------
/**
* Method to update the adjacent controllers for the current position instance
*
* More details can be found in CPosition.h
*/
void CPosition::updateAdjacentControllers(std::list<std::string> AdjacentControllers) {
	if (!isAdjacentControllersValid(AdjacentControllers)) {
		throw "ERROR: There was an issue with one of the contorllers passed to updateAdjacentControllers in CPosition Class";
	}

	getRelevantAdjacentControllers(AdjacentControllers, m_ICAO);
	m_adjacentControllers = AdjacentControllers;
}

/**
* Method to update the ATIS information for the current position instance
*
* More details can be found in CPosition.h
*/
void CPosition::updateAtis(char newAtis) {
	if (!isAtisValid(newAtis)) {
		throw "ERROR: There was an issue with the newAtis passed to updateAtis(newAtis) in CPosiiton Class";
	}

	m_ATIS = newAtis;
}

/*
* Method to update the atis information in the current position instance by an increment of 1
*
* More details can be found in CPosition.h
*/
void CPosition::updateAtis(int change) {
	if (change != 1 && change != -1) {
		throw "ERROR: There was an issue with the change passed to updateAtis(change) in CPosition Class";
	}

	if (m_ATIS == C_ASCII_Z && change == 1) {
		m_ATIS = C_ASCII_A;
	}
	else if (m_ATIS == C_ASCII_A && change == -1) {
		m_ATIS = C_ASCII_Z;
	}
	else {
		m_ATIS += change;
	}
}

/**
* Method to update the departure runway for the current position instance
*
* More details in CPosition.h
*/
void CPosition::updateDepRunway(std::string newRunway) {
	if (!isRunwayValid(newRunway)) {
		throw "ERROR: There was an issue with the new runway passed to updateDepRunway in CPosition Class";
	}

	m_depRunway = newRunway;
}

/**
* Method to update the arrival runway for the current position instance
*
* More details can be found in CPosition.h
*/
void CPosition::updateArrRunway(std::string newRunway) {
	if (!isRunwayValid(newRunway)) {
		throw "ERROR: There was an issue with the new runway passed to updateDepRunway in CPosition Class";
	}

	m_arrRunway = newRunway;
}

/**
* Method to update the SIDs which are freeflow in the current position instance
*
* More details in CPosition.h
*/
void CPosition::updateSIDs(std::string SIDKey) {
	bool isSIDInvalid = m_SIDs.find == m_SIDs.end();
	if (isSIDInvalid) {
		throw "ERROR: There was an issue with the SID passed to updateSIDs in CPosition Class (the SID was not found in the map)";
	}

	bool currentValue = m_SIDs[SIDKey];
	m_SIDs.insert_or_assign(SIDKey, !currentValue);
}

/**
* Method to update the QNH in the current position instance
*
* More details can be found in CPosition.h
*/
void CPosition::updateQNH(int newQNH) {
	if (!isQNHValid(newQNH)) {
		throw "ERROR: There was an issue with the new QNH passed to updateQNH in CPOsition Class";
	}

	m_QNH = newQNH;
}

/**
* Method to update the callsign selected in the current position instace
*
* More details can be found in CPosition.h
*/
void CPosition::updateCallsignSelected(std::string newCallsign) {
	if (!isCallsignSelectedValid(newCallsign)) {
		throw "ERROR: There was an issue with the newCallsign passed to updateCallsignSelected in CPosition Class";
	}

	m_callsignSelected = newCallsign;
}

//Helper functions----------------------------------------------------------------------------------------------
/**
* Method to check if the extension of a callsign is valid
*
* Used throughout the class
*
* @param string holding the extension to be tested if valid
*
* @returns boolean which is true if the extension is valid and false otherwise
*/
bool isExtensionValid(std::string extension) {
	bool invalidExtension = extension != "DEL" && extension != "GND" && extension != "TWR" && extension != "APP" && extension != "CTR";
	if (invalidExtension) {
		return false;
	}

	return true;
}

/**
* Method to get the extension(TWR/APP) from a callsign
*
* @param string with the callsign to extract the extension from
*
* @throws error if there is no underscore in the callsign or if the extension is not 3 characters long
*
* @return string with the extension of the callsign
*/
std::string getExtensionFromCallsign(std::string callsign) {
	int indexOfUnderscore = callsign.find_last_of("_");
	int callsignLength = callsign.length();
	int expectedLength = indexOfUnderscore + 4;
	if (indexOfUnderscore == -1) {
		throw "ERROR: There was an issue finding an underscore in your callsign in getExtensionFromCallsign in CPosition class";
	}

	if (callsign.length != expectedLength) {
		throw "ERROR: There was an issue with the length of the extension in getExtensionFromCallsign in CPosition class";
	}

	std::string extension = callsign.substr(indexOfUnderscore, 3);
	return extension;
}

//For Constructor--------------------------------------------------------------------------------------------------------
/**
* Method to check if the ICAO perameter is valid as per constrictions in CPosition.h constructor commentary
*
* @param string holding the ICAO of the position
*
* @return true if the ICAO is valid and false otherwise
*/
bool isICAOValid(std::string ICAO) {
	std::string countryPrefix = ICAO.substr(0, 2);
	if (countryPrefix != "EG") {
		return false;
	}

	return true;
}

/**
* Method to check if the boxes perameter is valid as per constrictions in CPosition.h constructor commentary
*
* @param list of CBox instances holding the boxes required for this position
*
* @return true if boxes is valid and false otherwise
*/
bool isBoxesValid(std::list<CBox> boxes) {
	if (boxes.size == 0) {
		return false;
	}

	return true;
}

/**
* Method to check if the adjacentControllers perameter is valid as per constrictions in CPosition.h constructor commentary
*
* @param list of strings holding the boxes required for this position
*
* @return true if adjacentControllers is valid and false otherwise
*/
bool isAdjacentControllersValid(std::list<std::string> adjacentControllers) {
	bool valid = true;
	if (adjacentControllers.size == 0) {
		return false;
	}

	for (std::string controller : adjacentControllers) {
		std::string countryPrefix = controller.substr(0, 2);
		if (countryPrefix != "EG") {
			valid = false;
		}

		std::string extension = getExtensionFromCallsign(controller);
		valid = isExtensionValid(extension);
	}

	return valid;
}

/**
* Method to check if the ATIS parameter is valid as per constrictions in CPosition.h constructor commentary
*
* @param char with the current ATIS information
*
* @return true if ATIS is valid and false otherwise
*/
bool isAtisValid(char ATIS) {
	int atisAscii = (int)ATIS;
	if (atisAscii < C_ASCII_A || atisAscii > C_ASCII_Z) {
		return false;
	}

	return true;
}

/**
* Method to check if a runway parameter is valid as per constrictions in CPosition.h constructor commentary
*
* @param string with a runway
*
* @return boolean which is true if the runway is valid and false otherwise
*/
bool isRunwayValid(std::string runway) {
	int runwayNums = std::stoi(runway.substr(0.2));
	if (runwayNums < 1 || runwayNums > 36) {
		return false;
	}

	if (runway.length >= 4) {
		std::string suffix = runway.substr(2, 1);
		if (suffix != "L" && suffix != "R") {
			return false;
		}
	}

	return true;
}

/**
* Method to check if the SIDs parameter is valid as per constrictions in CPosition.h constructor commentary
*
* @param unordered_map mapping a string with the sid to a boolean which is true if the sid is freeflow and false otherwise
*
* @return true if SIDs is valid and false otherwise
*/
bool isSIDsValid(std::unordered_map<std::string, bool> SIDs) {
	return true;
}

/**
* Method to check if the QNH parameter is valid as per constrictions in CPosition.h constructor commentary
*
* @param int with the current QNH
*
* @return true if ATIS is valid and false otherwise
*/
bool isQNHValid(int qnh) {
	if (qnh == NULL || qnh < 931 || qnh > 1067) {
		return false;
	}

	return true;
}

/**
* Method to check if the callsignSelected perameter is valid as per constrictions in CPosition.h constructor commentary
*
* @param string with the currentCallsign selected
*
* @return true if callsignSelected is valid and false otherwise
*/
bool isCallsignSelectedValid(std::string callsignSelected) {
	if (callsignSelected == "") {
		return true;
	}

	//Go through each strip and check if the callsignSelected string matches a callsign String in the strip instance

	return false;
}

//Update Methods-------------------------------------------------------------------------------------------------------------------------------------
/**
* Method to get the relevant adjacent controllers from the current position
*
* Returns void because it updates the fullAdjacentControllers object in RAM therefore the pointer remains the same
*/
void getRelevantAdjacentControllers(std::list<std::string> fullAdjacentControllers, std::string positionICAO) {
	for (std::string controller : fullAdjacentControllers) {
		std::string ICAO = getICAOFromCallsign(controller);
		bool positionNotValid = ICAO != positionICAO && ICAO != "LON" && ICAO != "SCO" && ICAO != "LTC" && ICAO != "MAN" && ICAO != "STC";

		if (positionNotValid) {
			fullAdjacentControllers.remove(controller);
		}
		else {
			std::string extension = getExtensionFromCallsign(controller);
			if (!isExtensionValid(extension)) {
				fullAdjacentControllers.remove(controller);
			}
		}
	}
}

/**
* Method to get the ICAO of a position from the callsign
*
* @param string with a controller callsign
*
* @return string with the ICAO
*/
std::string getICAOFromCallsign(std::string controller) {
	int indexOfUnderscore = controller.find_first_of("_");
	if (indexOfUnderscore == -1) {
		throw "ERROR: couldn't find an underscore in getICAOFromCallsign in CPosition class";
	}
	int lengthOfICAO = indexOfUnderscore - 1;
	std::string ICAO = controller.substr(0, lengthOfICAO);
	return ICAO;
}