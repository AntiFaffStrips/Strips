#include "pch.h"
#include "CEuroScopeUtils.h"

#define MY_PLUGIN_NAME      "Anti-Faff Strips :P"
#define MY_PLUGIN_VERSION   "0.1"
#define MY_PLUGIN_DEVELOPER "AF, JF, KT"
#define MY_PLUGIN_COPYRIGHT "Free to be distributed as source code"


CEuroScopeUtils::CEuroScopeUtils(void)
    : CPlugIn(EuroScopePlugIn::COMPATIBILITY_CODE,
        MY_PLUGIN_NAME,
        MY_PLUGIN_VERSION,
        MY_PLUGIN_DEVELOPER,
        MY_PLUGIN_COPYRIGHT)
{
    // add your initialization here 
}