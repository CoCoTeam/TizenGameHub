#include "DataThreadManager.h"

DataThreadManager::DataThreadManager()
:__pList(null)
{
	// TODO Auto-generated constructor stub
	__pList = new LinkedList();

}

DataThreadManager::~DataThreadManager() {
	// TODO Auto-generated destructor stub

	if(__pList)
	{
		__pList->RemoveAll(true);
		delete __pList;
	}
}

//Add Thread at the LinkedList
bool
DataThreadManager::AddThread(DataThread* pThread)
{
	AppLog("1");
	result r = E_SUCCESS;
	if(__pList)
	{
		r = __pList->Add(*pThread);
	}
	else
		return false;

	return !IsFailed(r);
}

//Delete Thread by threadid
void
DataThreadManager::DeleteThread(int threadid)
{
	AppLog("1");
	IEnumerator* pEnum = __pList->GetEnumeratorN();
	DataThread* pCur = null;

	while(pEnum->MoveNext() == E_SUCCESS)
	{
		pCur = (DataThread*)pEnum->GetCurrent();
		if(pCur)
		{
			if(pCur->GetThreadID() == threadid)
			{
				__pList->Remove(*pCur,true);
				break;
			}
		}
	}
}

//Delete All Threads
void
DataThreadManager::DeleteAll()
{
	AppLog("1");
	IEnumerator* pEnum = __pList->GetEnumeratorN();
	DataThread* pCur = null;

	while(pEnum->MoveNext() == E_SUCCESS)
	{
		pCur = (DataThread*)pEnum->GetCurrent();
		if(pCur)pCur->Stop();
	}
	__pList->RemoveAll(true);
}
