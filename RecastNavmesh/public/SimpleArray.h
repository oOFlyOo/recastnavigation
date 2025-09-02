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
	TSimpleTArray();

	~TSimpleTArray();

	int Num() const;
	bool IsEmpty() const;

	void Reserve(int NewCapacity);

	ElementType& Emplace_GetRef();

	void Add(const ElementType& Item);

	auto begin() noexcept { return Data.begin(); }
    auto end() noexcept { return Data.end(); }
    auto begin() const noexcept { return Data.begin(); }
    auto end() const noexcept { return Data.end(); }

	ElementType& operator[](int Index);
	const ElementType& operator[](int Index) const;
};
#endif
