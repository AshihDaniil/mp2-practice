#pragma once

#include "table_node.h"

template <typename TKey, typename TData>
class Table
{
protected:
    int mSize;
    int pCurr;
    int Count;
public:
    Table(int mSize2);
    virtual ~Table();
    virtual void Reset();
    virtual bool IsEnd() const { return pCurr == mSize; };
    virtual void Next();

    bool IsEmpty() const { return Count == 0; };
    bool IsFull() const { return Count == mSize; };

    virtual void Insert(const TabNode<TKey, TData>* tn) = 0;
    virtual void Remove(const TKey& key) = 0;
    virtual TabNode<TKey, TData>* Find(const TKey& key) = 0;
};

template <typename TKey, typename TData>
Table<TKey, TData>::Table(int mSize2): pCurr(0), Count(0), mSize(mSize2)
{
    if (mSize2 <= 0)
    {
        throw "Size must be > 0";
    }
}

template <typename TKey, typename TData>
void Table<TKey, TData>::Reset()
{
    pCurr = 0;
}
template <typename TKey, typename TData>
void Table<TKey, TData>::Next()
{
    if (IsEnd)
    {
        throw "end rached";
    }
    pCurr++;
}