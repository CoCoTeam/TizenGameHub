#ifndef _CARD_PAIR_FORM_FACTORY_H_
#define _CARD_PAIR_FORM_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class CardPairFormFactory
	: public Tizen::Ui::Scenes::IFormFactory
{
public:
	CardPairFormFactory(void);
	virtual ~CardPairFormFactory(void);

	virtual Tizen::Ui::Controls::Form* CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _CARD_PAIR_FORM_FACTORY_H_
