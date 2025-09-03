#pragma once

#if !RECAST_UNREAL_ENGINE

#include <unordered_map>

#define TMap TSimpleMap

template <typename KeyType, typename ValueType>
class TSimpleMap
{
	std::unordered_map<ValueType, ValueType> Data;

public:
	void Reset()
	{
		Data.clear();
	}

	ValueType FindRef(KeyType Key) const
	{
		return Data.find(Key);
	}
};

#endif
