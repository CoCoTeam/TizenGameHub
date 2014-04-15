#ifndef STRUCT_H_
#define STRUCT_H_

#include <FBase.h>
using namespace Tizen::Base;

typedef struct __DATAINFO : public Object
{
	int threadid;
	int percent;
}DATAINFO;

#endif /* STRUCT_H_ */
