

#if !RECAST_UNREAL_ENGINE

#include "SimpleSet.h"

template <typename ElementType>
int TSimpleSet<ElementType>::Num() const
{
    return Data.size();
}

template <typename ElementType>
void TSimpleSet<ElementType>::Reserve(int Number)
{
	Data.reserve(Number);
}

template <typename ElementType>
void TSimpleSet<ElementType>::Add(const ElementType& InElement)
{
	Data.insert(InElement);
}

template <typename ElementType>
bool TSimpleSet<ElementType>::Contains(ElementType Key) const
{
	return Data.find(Key) != Data.end();
}


#endif