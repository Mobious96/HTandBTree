#pragma once
template <typename key, typename value>
class pair
{
private:
	key k;
	value v;
public:
	key GetKey()
	{
		return k;
	}
	value GetValue()
	{
		return v;
	}

	pair(key _key, value _value)
	{
		k = _key;
		v = _value;
	}
};