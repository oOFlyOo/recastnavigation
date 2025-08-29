
#if !RECAST_UNREAL_ENGINE

#include "SimpleArray.h"
#include <utility>

template <typename InElementType, typename InAllocatorType>
TSimpleTArray<InElementType, InAllocatorType>::TSimpleTArray()
{
}

template <typename InElementType, typename InAllocatorType>
TSimpleTArray<InElementType, InAllocatorType>::~TSimpleTArray()
{
	delete[] Data;
}

template <typename InElementType, typename InAllocatorType>
int TSimpleTArray<InElementType, InAllocatorType>::Num() const
{
	return ArraySize;
}

template <typename InElementType, typename InAllocatorType>
bool TSimpleTArray<InElementType, InAllocatorType>::IsEmpty() const
{
	return ArraySize == 0;
}

template <typename InElementType, typename InAllocatorType>
void TSimpleTArray<InElementType, InAllocatorType>::Reserve(int NewCapacity)
{
	if (NewCapacity > ArrayCapacity)
	{
		InElementType* NewData = new InElementType[NewCapacity];
		for (int i = 0; i < ArraySize; ++i)
		{
			NewData[i] = std::move(Data[i]);
		}
		delete[] Data;
		Data = NewData;
		ArrayCapacity = NewCapacity;
	}
}

template <typename InElementType, typename InAllocatorType>
InElementType& TSimpleTArray<InElementType, InAllocatorType>::Emplace_GetRef()
{
	if (ArraySize >= ArrayCapacity)
	{
		Reserve(ArrayCapacity == 0 ? 4 : ArrayCapacity * 2);
	}
	return Data[ArraySize++];
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