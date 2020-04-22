#include "pch.h"
#include "CController.h"

/*******************************************************************************
* Class constructor
*
* Input Callsign of the controllers position
*
* Throws string descriptions of errors if the callsign does not contain an underscore, does not have a valid extension and if it is not a uk callsign(starting with "EG")
*/
CController::CController(string callsign) {
	//checking inputs
	//checking contains underscore
	if (callsign.find_first_of("_") == -1) {
		throw "The callsign entered in the CController constructor was invalid(didn't contain an underscore";
	}
	else {
		int extensionStart = callsign.find_last_of("_") + 1;
		string positionExtension = callsign.substr(extensionStart, 3);
		bool invalidPosition = positionExtension != "DEL" || positionExtension != "GND" || positionExtension != "TWR" || positionExtension != "APP" || positionExtension != "CTR";
		bool unsuportedExtension = positionExtension == "APP" || positionExtension == "CTR";
		if (invalidPosition) {
			throw "The position entered in the CController constructor was invalid(The extension was invalid)";
		}
	}

	//checking uk
	string firstTwoChar = callsign.substr(0, 2);
	if (firstTwoChar != "EG") {
		throw "The callsign entered was not a uk callsign. Unfortunetly this plugin is only usable for uk positions at the moment";
	}

	//Assigning instance variables
	CPosition position = positionFromCallsign(callsign);
	m_position = position;
	m_callsign = callsign;
}

/**************************************************************************
* Method to get the position of the controller object
*
* Returns position member variable of the object used to call the method
*/
CPosition CController::getPosition() {
	return m_position;
}

/**************************************************************************
* Method to get the callsign of the controller object
*
* Returns callsign member variable of the object used to call the method
*/
string CController::getCallsign() {
	return m_callsign;
}

/**************************************************************************
* Method to update the position of the contorller object
*/
bool CController::updatePosition(CPosition newPosition) {
	//check inputs
	

	//assigning position
	m_position = newPosition;
}

//Static methods

CPosition CController::positionFromCallsign(string callsign) {
	//If unsuported position and with topdown ask if they want to use the tower position, if no topdown then say position not supported and no topdown
	//find what adjacent controllers are online
	//work out position based on that
	//If airport has specific position and not generic then use that
}
