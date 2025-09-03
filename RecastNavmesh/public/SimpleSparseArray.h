#pragma once

#if !RECAST_UNREAL_ENGINE

#include <unordered_set>

#define TSparseArray TSimpleSparseArray

template <typename ElementType>
class TSimpleSparseArray
{
	std::vector<ElementType> Data;
	std::vector<bool> AllocatedIndices;

public:
	std::vector<ElementType> GetData() const
	{
		return Data;
	}

	int Num() const
	{
		return std::count(AllocatedIndices.begin(), AllocatedIndices.end(), true);
	}

	int Add(const ElementType& InElement)
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

	void RemoveAt(int Index)
	{
		if (Index >= 0 && Index < AllocatedIndices.size() && AllocatedIndices[Index])
		{
			AllocatedIndices[Index] = false; // 标记为未分配
		}
	}

	int GetMaxIndex() const
	{
		return Data.size();
	}

	bool IsAllocated(int Index) const
	{
		return (Index >= 0) && (Index < AllocatedIndices.size()) && AllocatedIndices[Index];
	}

	bool Contains(ElementType Key) const
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

	ElementType& operator[](int Index)
	{
		return Data[Index];
	}

	const ElementType& operator[](int Index) const
	{
		return Data[Index];
	}
};

#endif
