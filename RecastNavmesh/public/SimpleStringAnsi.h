#pragma once

#if !RECAST_UNREAL_ENGINE
#include <cstdarg>

#define FCStringAnsi SimpleStringAnsi

class SimpleStringAnsi
{
public:
	static int GetVarArgs(char* Dest, size_t DestSize, const char*& Fmt, va_list ArgPtr);
};

#endif