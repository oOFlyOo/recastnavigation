
#pragma once

#if !RECAST_UNREAL_ENGINE

#include <unordered_set>

#define TSet TSimpleSet

template<typename ElementType>
class TSimpleSet
{
	std::unordered_set<ElementType> Data;

public:
	std::unordered_set<ElementType> GetData() const
	{
		return Data;
	}

	int Num() const;
	void Reserve(int Number);
	void Add(const ElementType&  InElement);
	bool Contains(ElementType Key) const;
};

#endif
