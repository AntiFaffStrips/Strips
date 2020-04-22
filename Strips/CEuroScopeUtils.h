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
	void OnFlightPlanFlightPlanDataUpdate(EuroScopePlugIn::CFlightPlan FlightPlan);
	void OnFlightPlanControllerAssignedDataUpdate(EuroScopePlugIn::CFlightPlan FlightPlan,
		int DataType);
	void OnFlightPlanDisconnect(EuroScopePlugIn::CFlightPlan FlightPlan);
};

