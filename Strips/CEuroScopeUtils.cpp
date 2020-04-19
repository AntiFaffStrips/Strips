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