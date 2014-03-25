#ifndef _TIZEN_GAME_HUB_FRAME_H_
#define _TIZEN_GAME_HUB_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class TizenGameHubFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	TizenGameHubFrame(void);
	virtual ~TizenGameHubFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_TIZEN_GAME_HUB_FRAME_H_
