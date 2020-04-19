#pragma once
#include <string>
#include "CPosition.h"
using namespace std;
class CController
{
public:
	CController(string callsign);
	CPosition getPosition();
	string getCallsign();
	bool updatePosition(CPosition newPosition);
	static CPosition positionFromCallsign(string callsign);
private:
	CPosition m_position;
	string m_callsign;
};
