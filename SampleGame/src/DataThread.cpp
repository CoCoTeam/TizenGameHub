#include "DataThread.h"

DataThread::DataThread() {
	// TODO Auto-generated constructor stub

}

DataThread::~DataThread() {
	// TODO Auto-generated destructor stub
	__pTimer->Cancel();
	delete __pTimer;
}


//Create Thread
result
DataThread::Construct(Form* pForm,int threadid)
{
	__pForm = pForm;
	__threadid = threadid;
	//__percent = 0;
	setlive(true);

   return Thread::Construct(THREAD_TYPE_EVENT_DRIVEN);

}

/*result
DataThread::Construct(Form* pForm)
{
	__pForm = pForm;
	setlive(true);

   return Thread::Construct(THREAD_TYPE_EVENT_DRIVEN);

}*/

//Start()  => OnStart()
bool
DataThread::OnStart(void)
{
	AppLog("OnStart");
	__pTimer = new Timer();
	__pTimer->Construct(*this);
	__pTimer->Start(1000);
   return true;
}

//Stop() => OnStop()
void
DataThread::OnStop(void)
{
	AppLog("OnStop");
	__pTimer->Cancel();

/*	ArrayList* pList = new ArrayList();

	DATAINFO* pInfo = new DATAINFO();
	pList->Add(*pInfo);
	if(pInfo)
	{
		pInfo->threadid = __threadid;
		pInfo->percent = 0;

	}
	if(__pForm)
	{
		__pForm->SendUserEvent(200,pList);
	}*/

	//delete this;
}


//This Thread's action
void
DataThread::Work()
{
	AppLog("Work");

	if(getlive() == false)
	{
		AppLog("Stop because 20");
		this->Stop();
		return;
	}

	//ArrayList* pList = new ArrayList();

	//DATAINFO* pInfo = new DATAINFO();
	//pList->Add(*pInfo);
	/*if(pInfo)
	{
		__percent++;

		pInfo->threadid = __threadid;
		pInfo->percent = __percent;

		if(__percent > 20)
		{
			AppLog("Stop because 100");
			this->Stop();
			return;
		}
	}*/


/*	if(__islive == false)
	{
		AppLog("Stop because 20");
		this->Stop();
		return;
	}*/

	//Send Data to Form1
	if(__pForm)
	{
		__pForm->SendUserEvent(100,NULL);
	}
}

//repeatedly called function
void
DataThread::OnTimerExpired (Timer &timer)
{
	AppLog("OnTimerExpired");

	Work();

	timer.Start(1000);
}


