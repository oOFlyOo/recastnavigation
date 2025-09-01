#if !RECAST_UNREAL_ENGINE
#include "SimpleSparseArray.h"


template <typename ElementType>
int TSimpleSparseArray<ElementType>::Num() const
{
	return std::count(AllocatedIndices.begin(), AllocatedIndices.end(), true);
}

template <typename ElementType>
int TSimpleSparseArray<ElementType>::Add(const ElementType& InElement)
{
	// 查找第一个未分配的索引
	for (int Idx = 0; Idx < AllocatedIndices.size(); ++Idx)
	{
		if (!AllocatedIndices[Idx])
		{
			Data[Idx] = InElement;
			AllocatedIndices[Idx] = true;
			return Idx;
		}
	}

	// 如果没有空闲索引，添加到末尾
	Data.push_back(InElement);
	AllocatedIndices.push_back(true);
	return Data.size() - 1;
}

template <typename ElementType>
void TSimpleSparseArray<ElementType>::RemoveAt(int Index)
{
	if (Index >= 0 && Index < AllocatedIndices.size() && AllocatedIndices[Index])
	{
		AllocatedIndices[Index] = false; // 标记为未分配
	}
}

template <typename ElementType>
int TSimpleSparseArray<ElementType>::GetMaxIndex() const
{
	return Data.size();
}

template <typename ElementType>
bool TSimpleSparseArray<ElementType>::IsAllocated(int Index) const
{
	return (Index >= 0) && (Index < AllocatedIndices.size()) && AllocatedIndices[Index];
}

template <typename ElementType>
bool TSimpleSparseArray<ElementType>::Contains(ElementType Key) const
{
	for (int Idx = 0; Idx < Data.size(); ++Idx)
	{
		if (AllocatedIndices[Idx] && Data[Idx] == Key)
		{
			return true;
		}
	}
	return false;
}

template <typename ElementType>
ElementType& TSimpleSparseArray<ElementType>::operator[](int Index)
{
	return Data[Index];
}

template <typename ElementType>
const ElementType& TSimpleSparseArray<ElementType>::operator[](int Index) const
{
	return Data[Index];
}

#endif
