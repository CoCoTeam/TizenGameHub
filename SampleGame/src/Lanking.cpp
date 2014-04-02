/*
 * Lanking.cpp
 *
 *  Created on: Mar 12, 2014
 *      Author: hursujung
 */

#include "Lanking.h"
#include "AppResourceId.h"
#include <FApp.h>
#include <FGraphics.h>


Lanking::Lanking(void)
: __pLankingListView(null),__pRankingTextList(null){
	// TODO Auto-generated constructor stub
}
Lanking::~Lanking() {
	// TODO Auto-generated destructor stub
}

bool
Lanking::Initialize()
{
	// Construct an XML form
	Construct(L"Ranking");

	return true;
}
result
Lanking::OnInitializing(void)
{
	result r = E_SUCCESS;

	SetFormBackEventListener(this);

	// TODO: Add your initialization code here
	__pLankingListView = static_cast<ListView *>(GetControl(L"RANKING_LISTVIEW1"));
	__pLankingListView->SetTextOfEmptyList("No Item");
	__pLankingListView->SetItemProvider(*this);

	__pRankingTextList = new (std::nothrow) ArrayList();
	__pRankingTextList->Construct();

	setList_boolean(false);

	return r;
}

result
Lanking::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
Lanking::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId, const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	if (pArgs != null)
	{
		for(int i = 0; i < pArgs->GetCount(); i++)
		{
			//AppLog("--------------------------1");

			String* pStr = dynamic_cast<String*>(pArgs->GetAt(i));

			//AppLog("--------------------------2");

			if (pStr != null)
			{
					resultMessage = *pStr;
			}


			InsertItem();

		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}


void
Lanking::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId, const Tizen::Ui::Scenes::SceneId& nextSceneId)
{

}

void
Lanking::InsertItem(void)
{
	if (__pRankingTextList)
	{
		__pRankingTextList->InsertAt(*(new (std::nothrow) String(resultMessage)), 0);
		/*if (__pWatchTextList->GetCount() > 10)
		{
			__pWatchTextList->RemoveAt(10, true);
		}
		*/
	}
	__pLankingListView->ScrollToItem(0, LIST_SCROLL_ITEM_ALIGNMENT_TOP);

	__pLankingListView->UpdateList();
}

Tizen::Ui::Controls::ListItemBase*
Lanking::CreateItem(int index, int itemWidth)
{
	String* pItemText = null;
	pItemText = static_cast<String *>(__pRankingTextList->GetAt(index));

	CustomItem* pItem = new (std::nothrow) CustomItem();
	pItem->Construct(Tizen::Graphics::Dimension(itemWidth,74), LIST_ANNEX_STYLE_NORMAL);
	pItem->AddElement(Rectangle(10, 10, 460, 74), 300, *pItemText, true);

	return pItem;
}

bool
Lanking::DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}

int
Lanking::GetItemCount(void)
{
	if (__pRankingTextList)
	{
		return __pRankingTextList->GetCount();
	}
	else
	{
		return 0;
	}
}


//BackButton
void
Lanking::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
}

