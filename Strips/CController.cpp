#include "pch.h"
#include "CController.h"

/*******************************************************************************
* Class constructor
*
* Accepts Callsign of the controllers position

* Throws (add what it throws)
*/
CController::CController(string callsign) {
	//checking inputs
	if (callsign.find_first_of("_") == -1) {
		throw "The callsign entered in the CController constructor was invalid(didn't contain an underscore";
	}

	//Think of more potential errors, maybe use machine

	//Assigning instance variables
	CPosition position = positionFromCallsign(callsign);
	m_position = position;
	m_callsign = callsign;
}

CPosition CController::getPosition() {
	return m_position;
}

string CController::getCallsign() {
	return m_callsign;
}

bool CController::updatePosition(CPosition newPosition) {
	//check inputs
	m_position = newPosition;
}

//Static methods

CPosition CController::positionFromCallsign(string callsign) {
	//find what adjacent controllers are online
	//work out position based on that
	//If airport has specific position and not generic then use that
}
