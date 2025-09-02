#if !RECAST_UNREAL_ENGINE

#include "SimpleStringAnsi.h"

#include "Navmesh.h"


int SimpleStringAnsi::GetVarArgs(char* Dest, size_t DestSize, const char*& Fmt, va_list ArgPtr)
{
	int32 Result = vsnprintf(Dest, DestSize, Fmt, ArgPtr);

	return (Result != -1 && Result < static_cast<int32>(DestSize)) ? Result : -1;
}
#endif
