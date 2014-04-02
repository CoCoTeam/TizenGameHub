/*
 * Lanking.h
 *
 *  Created on: Mar 12, 2014
 *      Author: hursujung
 */

#ifndef LANKING_H_
#define LANKING_H_

#include <FBase.h>
#include <FUi.h>
#include <FGraphics.h>


using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Base::Collection;

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::App;


class Lanking : public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public Tizen::Ui::Controls::IListViewItemProvider
	, public Tizen::Ui::Controls::IFormBackEventListener
{
public:
	Lanking();
	virtual ~Lanking();
	bool Initialize(void);

	  void setList_boolean(bool isSetList)
	  { __isSetList = isSetList;}
	  bool getList_boolean()
	  { return __isSetList;}

private:

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);



	Tizen::Ui::Controls::ListView* __pLankingListView;
	Tizen::Base::Collection::ArrayList* __pRankingTextList;


	//IListViewItemProvider
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase *pItem, int itemWidth);
	virtual int GetItemCount(void);


	void InsertItem(void);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	String resultMessage;

	bool __isSetList;





};
#endif /* LANKING_H_ */
