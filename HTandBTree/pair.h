#pragma once
template <typename Tkey, typename Tvalue>
struct TPair
{
	Tkey key;
	Tvalue value;

	TPair<Tkey, Tvalue>& operator=(TPair<Tkey, Tvalue> obj);
	TPair()
	{}
	TPair(Tkey _key, Tvalue _value)
	{
		key = _key;
		value = _value;
	}
	TPair(TPair<Tkey,Tvalue> &obj)
	{
		key = obj.key;
		value = obj.value;
	}
};
template<typename Tkey, typename Tvalue>
TPair<Tkey, Tvalue>& TPair<Tkey, Tvalue>::operator=(TPair<Tkey, Tvalue> obj)
{
	key = obj.key;
	value = obj.value;
	return *this;
}
