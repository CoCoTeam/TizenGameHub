#ifndef DATATHREADMANAGER_H_
#define DATATHREADMANAGER_H_
#include <FBase.h>
#include <FIo.h>
#include "DataThread.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Base::Collection;

class DataThreadManager {
public:
	DataThreadManager();
	virtual ~DataThreadManager();

private:
	LinkedList* __pList;


public:
	bool AddThread(DataThread* pThread);
	void DeleteThread(int threadid);
	void DeleteAll();
};

#endif  DATATHREADMANAGER_H_
