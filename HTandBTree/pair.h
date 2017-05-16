#pragma once
template <typename Tkey, typename Tvalue>
struct pair
{
	Tkey key;
	Tvalue value;

	pair(Tkey _key, Tvalue _value)
	{
		key = _key;
		value = _value;
	}
};