#pragma once

#if !RECAST_UNREAL_ENGINE

#include <unordered_set>

#define TSet TSimpleSet

template <typename ElementType>
class TSimpleSet
{
	std::unordered_set<ElementType> Data;

public:
	std::unordered_set<ElementType> GetData() const
	{
		return Data;
	}

	int Num() const
	{
		return Data.size();
	}

	void Reserve(int Number)
	{
		Data.reserve(Number);
	}

	void Add(const ElementType& InElement)
	{
		Data.insert(InElement);
	}

	bool Contains(ElementType Key) const
	{
		return Data.find(Key) != Data.end();
	}
};

#endif
