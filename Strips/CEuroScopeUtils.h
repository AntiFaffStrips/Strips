#pragma once
#include "EuroScopePlugIn.h"
#include "string"
#include "vector"

class CEuroScopeUtils :
	public EuroScopePlugIn::CPlugIn
{
private:
	std::string UserICAO;
	int UserFacilityInt;
	std::string UserFacilityStr;
public:
	CEuroScopeUtils(void);
	std::string UserFacilityConvert(int UserFacilityInt);
	int GetUserFacilityInt();
};

