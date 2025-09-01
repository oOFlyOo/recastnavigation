
#pragma once

#if !RECAST_UNREAL_ENGINE

#include <unordered_set>

#define TSparseArray TSimpleSparseArray

template<typename ElementType>
class TSimpleSparseArray
{
	std::vector<ElementType> Data;
    std::vector<bool> AllocatedIndices;

public:
	std::vector<ElementType> GetData() const
	{
		return Data;
	}

	int Num() const;
	int Add(const ElementType&  InElement);
	void RemoveAt(int Index);
	int GetMaxIndex() const;
	bool IsAllocated(int Index) const;
	bool Contains(ElementType Key) const;

	ElementType& operator[](int Index);
	const ElementType& operator[](int Index) const;
};

#endif
