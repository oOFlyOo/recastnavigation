#pragma once

#if !RECAST_UNREAL_ENGINE

#include <vector>

/**
 * todo
 * @tparam NumInlineElements 
 */
template <int NumInlineElements>
class TFakeInlineAllocator
{
};

#define TArray TSimpleTArray
template <int NumInlineElements>
using TInlineAllocator = TFakeInlineAllocator<NumInlineElements>;


template <typename ElementType, typename AllocatorType = TInlineAllocator<16>>
class TSimpleTArray
{
	std::vector<ElementType> Data;
	int ArraySize = 0;
	int ArrayCapacity = 0;

public:
	TSimpleTArray()
	{
	}

	~TSimpleTArray()
	{
	}

	int Num() const
	{
		return Data.size();
	}

	bool IsEmpty() const
	{
		return Data.empty();
	}

	void Reserve(int NewCapacity)
	{
		Data.reserve(NewCapacity);
	}

	ElementType& Emplace_GetRef()
	{
		Data.emplace_back();

		return Data.back();
	}

	void Add(const ElementType& Item)
	{
		Data.push_back(Item);
	}

	auto begin() noexcept { return Data.begin(); }
	auto end() noexcept { return Data.end(); }
	auto begin() const noexcept { return Data.begin(); }
	auto end() const noexcept { return Data.end(); }

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
