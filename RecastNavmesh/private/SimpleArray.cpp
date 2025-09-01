
#if !RECAST_UNREAL_ENGINE

#include "SimpleArray.h"

template <typename InElementType, typename InAllocatorType>
TSimpleTArray<InElementType, InAllocatorType>::TSimpleTArray()
{
}

template <typename InElementType, typename InAllocatorType>
TSimpleTArray<InElementType, InAllocatorType>::~TSimpleTArray()
{
}

template <typename InElementType, typename InAllocatorType>
int TSimpleTArray<InElementType, InAllocatorType>::Num() const
{
	return Data.size();
}

template <typename InElementType, typename InAllocatorType>
bool TSimpleTArray<InElementType, InAllocatorType>::IsEmpty() const
{
	return Data.empty();
}

template <typename InElementType, typename InAllocatorType>
void TSimpleTArray<InElementType, InAllocatorType>::Reserve(int NewCapacity)
{
	Data.reserve(NewCapacity);
}

template <typename InElementType, typename InAllocatorType>
InElementType& TSimpleTArray<InElementType, InAllocatorType>::Emplace_GetRef()
{
	Data.emplace_back();

	return Data.back();
}

template <typename InElementType, typename InAllocatorType>
void TSimpleTArray<InElementType, InAllocatorType>::Add(const InElementType& Item)
{
	Data.push_back(Item);
}



template <typename InElementType, typename InAllocatorType>
InElementType& TSimpleTArray<InElementType, InAllocatorType>::operator[](int Index)
{
	return Data[Index];
}

template <typename InElementType, typename InAllocatorType>
const InElementType& TSimpleTArray<InElementType, InAllocatorType>::operator[](int Index) const
{
	return Data[Index];
}
#endif