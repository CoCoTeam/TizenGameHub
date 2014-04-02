/**
 * This file contains the exported symbol.
 */
#include "TizenGameHubLibrary.h"

// This is the constructor of a class that has been exported.
// See TizenGameHubLibrary.h for the class declaration.
OspcTizenGameHubLibrary::OspcTizenGameHubLibrary(void)
{
	return;
}

// This is an example of an exported method.
int
OspfTizenGameHubLibrary(void)
{
	result r = E_SUCCESS;
	return static_cast<int>(r);
}
