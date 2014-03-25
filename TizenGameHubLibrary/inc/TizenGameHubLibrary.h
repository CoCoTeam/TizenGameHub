#ifndef _TIZEN_GAME_HUB_LIBRARY_H_
#define _TIZEN_GAME_HUB_LIBRARY_H_

/**
 * This header file is included to define _EXPORT_.
 */
#include <FBase.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// This class is exported from TizenGameHubLibrary.so
class _EXPORT_ OspcTizenGameHubLibrary {
public:
	OspcTizenGameHubLibrary(void);
	// TODO: Add your methods here
};

// This method is exported from TizenGameHubLibrary.so
_EXPORT_ int OspfTizenGameHubLibrary(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _TIZEN_GAME_HUB_LIBRARY_H_

