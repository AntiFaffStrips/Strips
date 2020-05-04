#include "pch.h"
#include "CPosition.h"

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


//Helper functions
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
	if (boxes == NULL || boxes.size == 0) {
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
CPosition::isAdjacentControllersValid(std::list<std::string> adjacentControllers) {
	if (adjacentControllers == NULL || adjacentControllers.size == 0) {
		return false;
	}

	for (std::string controller : adjacentControllers) {
		std::string countryPrefix = ICAO.substr(0, 2);
		if (countryPrefix != "EG") {
			return false;
		}

		int indexOfUnderscore = controller.find_last_of("_");
		if (indexOfUnderscore == -1) {
			return false;
		}

		std::string extension = controller.substr(indexOfUnderscore, 3);
		if (extension != "DEL" && extension != "GND" && extension != "TWR" && extension != "APP" && extension != "CTR") {
			return false;
		}
	}

	return true;
}

/**
* Method to check if the ATIS parameter is valid as per constrictions in CPosition.h constructor commentary
*
* @param char with the current ATIS information
*
* @return true if ATIS is valid and false otherwise
*/
CPosition::isAtisValid(char ATIS) {
	int atisAscii = (int)ATIS;
	if (atisAscii < 65 || atisAscii > 91) {
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
CPosition::isRunwayValid(std::string runway) {
	int runwayNums = std::stoi(runway.substr(0.2))
	if (runwayNums < 1 || runwayNums > 36) {
		return false;
	}

	if (runway.substr(2, 1) != -1) {
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
CPosition::isSIDsValid(std::unordered_map<std::string, bool> SIDs) {
	if (SIDs == NULL) {
		return false;
	}

	return true;
}

/**
* Method to check if the QNH parameter is valid as per constrictions in CPosition.h constructor commentary
*
* @param int with the current QNH
*
* @return true if ATIS is valid and false otherwise
*/
CPosition::isQNHValid(int qnh) {
	if (qnh == null || qnh < 931 || qnh > 1067) {
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
CPosition::isCallsignSelectedValid(std::string callsignSelected) {
	if (callsignSelected == NULL) {
		return false;
	}

	return true;
}