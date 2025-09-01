

#if !RECAST_UNREAL_ENGINE
#include "SimpleMap.h"

template <typename KeyType, typename ValueType>
void TSimpleMap<KeyType, ValueType>::Reset()
{
	Data.clear();
}

template <typename KeyType, typename ValueType>
ValueType TSimpleMap<KeyType, ValueType>::FindRef(KeyType Key) const
{
	return Data.find(Key);
}
#endif