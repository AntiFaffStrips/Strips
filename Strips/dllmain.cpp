// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "EuroScopePlugIn.h"
#include "CEuroScopeUtils.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

CEuroScopeUtils* pMyPlugIn = NULL;
    
void __declspec (dllexport) EuroScopePlugInInit(EuroScopePlugIn::CPlugIn** ppPlugInInstance)
{
    // allocate 
    *ppPlugInInstance = pMyPlugIn =
        new CEuroScopeUtils;
}

void __declspec (dllexport) EuroScopePlugInExit(void)
{
    delete pMyPlugIn;
}