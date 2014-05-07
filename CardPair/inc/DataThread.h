#ifndef DATATHREAD_H_
#define DATATHREAD_H_
#include <FBase.h>
#include <FUi.h>

using namespace Tizen::Base;
using namespace Tizen::Base::Runtime;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Base::Collection;

typedef struct __DATAINFO : public Object
{
	int threadid;
	int percent;
}DATAINFO;

class DataThread
:public Thread,
 public Tizen::Base::Runtime::ITimerEventListener
{
public:
	DataThread();
	virtual ~DataThread();

public:
//result Construct(Form* pForm,int threadid);
result Construct(Form* pForm, int threadid);

public:
  bool OnStart(void);
  void OnStop(void);

public:
  void Work();

private:
  Form* __pForm;
  int __threadid;
  int __percent;
  bool __islive;

public:
  int GetThreadID(){return __threadid;}
  void StopEventDrivenThreadSample();
  void setlive(bool islive) { __islive = islive;}
  bool getlive() { return __islive;}

private:
  Timer* __pTimer;

public:
  virtual void  OnTimerExpired (Timer &timer);
};

#endif /* DATATHREAD_H_ */
