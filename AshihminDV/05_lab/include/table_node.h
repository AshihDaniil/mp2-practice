#pragma once

#include <iostream>

template<typename TKey, typename TData>
class TabNode
{
public:
	TKey key;
	TData data;
	TabNode(const TKey& k, const TData& d) : key(k), data(d) {};
	TabNode(const TabNode<TKey, TData>& tn) : key(tn.key), data(tn.data) {};
};