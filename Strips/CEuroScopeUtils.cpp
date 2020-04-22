#include "pch.h"
#include "CEuroScopeUtils.h"
#include "stdio.h"
#include "string"
#include "sstream"

#define MY_PLUGIN_NAME      "Anti-Faff Strips :P"
#define MY_PLUGIN_VERSION   "0.1"
#define MY_PLUGIN_DEVELOPER "AF, JF, KT"
#define MY_PLUGIN_COPYRIGHT "Free to be distributed as source code"

#define DEL "DEL"
#define GND "GND"
#define TWR "TWR"
#define APP "APP"
#define CTR "CTR"
#define FSS "FSS"


CEuroScopeUtils::CEuroScopeUtils(void)
    : CPlugIn(EuroScopePlugIn::COMPATIBILITY_CODE,
        MY_PLUGIN_NAME,
        MY_PLUGIN_VERSION,
        MY_PLUGIN_DEVELOPER,
        MY_PLUGIN_COPYRIGHT)
{
    // message on startup
    DisplayUserMessage("Anti-Faff Strips", "Version", MY_PLUGIN_VERSION, true, true, true, true, false);

    // gets the callsign of the user, converts from c_str to string
    std::string UserCallsign(this->ControllerMyself().GetCallsign());
    // extracts the first 4 chars for the ICAO code
    std::string UserICAO = UserCallsign.substr(0, 4);
    // get the facility (numbers defined in the EuroScopePlugIn.h)
    UserFacilityInt = GetUserFacilityInt();
    // convert to string for outputting
    std::string UserFacilityStr = UserFacilityConvert(UserFacilityInt);

    DisplayUserMessage("Anti-Faff Strips", "Callsign", UserICAO.c_str(), true, true, true, true, false);
    DisplayUserMessage("Anti-Faff Strips", "Position", UserFacilityStr.c_str(), true, true, true, true, false);
}

int CEuroScopeUtils::GetUserFacilityInt() {
    //Function to get the facility integer, as defined in "EuroScopePlugIn.h"
    int UserFacilityInt = this->ControllerMyself().GetFacility();
    return UserFacilityInt;
}

std::string CEuroScopeUtils::UserFacilityConvert(int UserFacility) {
    //Convert the integer to the #defined strings
    std::string UserFacilityStr = "Not Found";
    if (UserFacility == 1) {
        UserFacilityStr = FSS;
    }
    else if (UserFacility == 2) {
        UserFacilityStr = DEL;
    }
    else if (UserFacility == 3) {
        UserFacilityStr = GND;
    }
    else if (UserFacility == 4) {
        UserFacilityStr = TWR;
    }
    else if (UserFacility == 5) {
        UserFacilityStr = APP;
    }
    else if (UserFacility == 6) {
        UserFacilityStr = CTR;
    }
    return UserFacilityStr;
}

void CEuroScopeUtils::OnFlightPlanFlightPlanDataUpdate(EuroScopePlugIn::CFlightPlan FlightPlan) {
    // get all relevent flight plan info
    //gets callsign
    const char* FPCallsign = FlightPlan.GetCallsign();
    //origin
    const char* FPOrigin = FlightPlan.GetFlightPlanData().GetOrigin();
    //dest
    const char* FPDest = FlightPlan.GetFlightPlanData().GetDestination();
    //rules
    const char* FPType = FlightPlan.GetFlightPlanData().GetAircraftFPType();
    //actype
    const char* FPACType = FlightPlan.GetFlightPlanData().GetAircraftInfo();
    //FL
    int FPAltitude = FlightPlan.GetFlightPlanData().GetFinalAltitude();
    //route - this could be looooong
    const char* FPRouteFull = FlightPlan.GetFlightPlanData().GetRoute();
    //speed
    int FPAirspeed = FlightPlan.GetFlightPlanData().GetTrueAirspeed();
    //sq
    const char* FPAllocSq = FlightPlan.GetControllerAssignedData().GetSquawk();
    //voice
    char FPVoice = FlightPlan.GetFlightPlanData().GetCommunicationType();
    //edt
    const char* FPEtd = FlightPlan.GetFlightPlanData().GetEstimatedDepartureTime();
    //capabilities
    char FPCapabilities = FlightPlan.GetFlightPlanData().GetCapibilities();
    //alternate
    const char* FPAlternate = FlightPlan.GetFlightPlanData().GetAlternate();
    //arrival runway
    const char* FPArrRwy = FlightPlan.GetFlightPlanData().GetArrivalRwy();
    //departure runway
    const char* FPDepRwy = FlightPlan.GetFlightPlanData().GetDepartureRwy();
    //remarks
    const char* FPRmks = FlightPlan.GetFlightPlanData().GetRemarks();
    //SID
    const char* FPSid = FlightPlan.GetFlightPlanData().GetSidName();
    //STAR
    const char* FPStar = FlightPlan.GetFlightPlanData().GetStarName();
    
    // send as message (for the moment)
    //set up message buffer
    char buffer[500];
    int msg;
    msg = snprintf(buffer, 200, "%s, origin %s, dest %s, rules %s, EDT %s, altitude %d ft, type %s, speed %d kts, route %s, destination %s, squawk %s, voice %c, capabilities %s, alternate %s, arrRwy %s, deprwy %s, rmks %s, SID %s, STAR %s .",
        FPCallsign, FPOrigin, FPDest, FPType, FPEtd, FPAltitude, FPACType, FPAirspeed,
        FPRouteFull, FPDest, FPAllocSq, FPVoice, FPCapabilities, FPAlternate, FPArrRwy, FPDepRwy, FPRmks, FPSid, FPStar);
    //makes controller message
    DisplayUserMessage("Anti-Faff Strips", "New Flight Plan", buffer, true, true, true, true, true);
}

void CEuroScopeUtils::OnFlightPlanControllerAssignedDataUpdate(EuroScopePlugIn::CFlightPlan FlightPlan,
    int DataType) {

}

void CEuroScopeUtils::OnFlightPlanDisconnect(EuroScopePlugIn::CFlightPlan FlightPlan) {

}