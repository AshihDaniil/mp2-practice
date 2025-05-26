#pragma once

#include "table.h"

template<typename TKey, typename TData>
class VTable : public Table<TKey, TData>
{
private:
	TabNode<TKey, TData>** Recs;
public:
	VTable(int mSize2);
	VTable(const VTable<TKey, TData>& vt2);
	~VTable();
	virtual TabNode<TKey, TData>* Find(const TKey& key);
	virtual void Insert(const TabNode<TKey, TData>* tn);
	virtual void Remove(const TKey& key);
	virtual TabNode<TKey, TData>* GetCurr() const { return Recs[pCurr]; };
	void Print() const;
};

template<typename TKey, typename TData>
VTable<TKey, TData>::VTable(int mSize2) : Table<TKey, TData>(mSize2)
{
	Recs = new TabNode<TKey, TData>* [mSize2];
	for (int i = 0; i < mSize2; i++)
		Recs[i] = nullptr;
}

template<typename TKey, typename TData>
VTable<TKey, TData>::VTable(const VTable<TKey, TData>& vt2) : Table<TKey, TData>(vt2.mSize)
{
	Recs = new TabNode<TKey, TData>* [vt2.mSize];
	for (int i = 0; i < vt2.Count; i++)
	{
		Recs[i] = new TabNode<TKey, TData>(*vt2.Recs[i]);
	}
	this->Count = vt2.Count;
	this->pCurr = vt2.pCurr;
}

template<typename TKey, typename TData>
VTable<TKey, TData>::~VTable()
{
	for (int i = 0; i < this->Count; i++)
		delete Recs[i];
	delete[] Recs;
}

template<typename TKey, typename TData>
void VTable<TKey, TData>::Insert(const TabNode<TKey, TData>* tn)
{
	if (this->IsFull())
		throw "Table is full";

	for (int i = 0; i < this->Count; i++)
	{
		if (Recs[i]->key == tn->key)
			throw "Key already exists";
	}

	Recs[this->Count++] = tn;
}

template<typename TKey, typename TData>
void VTable<TKey, TData>::Remove(const TKey& key)
{
	TabNode<TKey, TData>* fRec = Find(key);
	if (fRec == nullptr)
	{
		throw "Key not found";
	}
	delete fRec;
	Recs[pCurr] = Recs[--count];
}

template<typename TKey, typename TData>
TabNode<TKey, TData>* VTable<TKey, TData>::Find(const TKey& key)
{
	TabNode<Tkey, Tdata>* answ = nullptr;
	for (int i = 0; i < this->count; i++) {
		if (recs[i]->get_key() == k) {
			answ = Recs[i];
			pCurr = i;
			return answ;
		}
	}
	return answ;
}

template<typename TKey, typename TData>
void VTable<TKey, TData>::Print() const
{
	std::cout << "=== Viewable Table ===" << std::endl;
	std::cout << "Size: " << this->mSize << ", Count: " << this->Count << std::endl;
	std::cout << "----------------------" << std::endl;

	for (int i = 0; i < this->Count; i++)
	{
		std::cout << "[" << i << "] Key: " << Recs[i]->key
			<< ", Value: " << Recs[i]->data << std::endl;
	}

	std::cout << "======================" << std::endl;
}