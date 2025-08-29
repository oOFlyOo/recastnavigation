#pragma once

#if !RECAST_UNREAL_ENGINE
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


template <typename InElementType, typename InAllocatorType>
class TSimpleTArray
{
	InElementType* Data = nullptr;
	int ArraySize = 0;
	int ArrayCapacity = 0;

public:
	TSimpleTArray();

	~TSimpleTArray();

	int Num() const;
	bool IsEmpty() const;

	void Reserve(int NewCapacity);

	InElementType& Emplace_GetRef();

	void Add(const InElementType& Item);

	InElementType& operator[](int Index);
	const InElementType& operator[](int Index) const;
};
#endif
