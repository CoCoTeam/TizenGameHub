#ifndef _CARD_PAIR_FRAME_H_
#define _CARD_PAIR_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

extern const wchar_t* SCENE_MAIN;
extern const wchar_t* SCENE_MODESELECT;
extern const wchar_t* SCENE_SOCIAL;
extern const wchar_t* SCENE_GAME_TIMETRIAL;
extern const wchar_t* SCENE_GAME_SECONDS;
extern const wchar_t* SCENE_GAME_MULTI;

class CardPairFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	CardPairFrame(void);
	virtual ~CardPairFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_CARD_PAIR_FRAME_H_
