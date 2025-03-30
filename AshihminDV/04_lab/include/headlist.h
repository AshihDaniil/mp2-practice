#pragma once
#include "list.h"

template <typename T>
class HeadList : public TList<T>
{
private:
	ListNode<T>* pHead;
public:
	HeadList();
	HeadList(const T& x);
	HeadList(const HeadList<T>& list);
	~HeadList();

	ListNode<T>* get_head() {
		return pHead;
	}

	const ListNode<T>* get_head() const {
		return pHead;
	}


	void insert_Front(ListNode<T>* node);
	//void insert_Back(ListNode<T>* node);
	void insert_Before(ListNode<T>* node, T key);

	void remove_First();

	const HeadList& operator=(const HeadList& other);
	bool operator==(const HeadList<T>& s) const;
	bool operator!=(const HeadList<T>& s) const;
};

template <typename T>
HeadList<T>::HeadList() :TList<T>()
{
	pHead = new ListNode<T>(T(), pFirst);
}

template <typename T>
HeadList<T>::HeadList(const T& x) : TList<T>(x)
{
	pHead = new ListNode<T>(T(), pFirst);
}

template <typename T>
HeadList<T>::HeadList(const HeadList<T>& list) : TList<T>(list)
{
	pHead = new ListNode<T>(T(), pFirst);
}

template <typename T>
HeadList<T>::~HeadList()
{
	delete pHead;
}

template <typename T>
void HeadList<T>::insert_Front(ListNode<T>* node)
{
	TList<T>::insert_Front(node);
	pHead->next = this->pFirst;
}

template <typename T>
void HeadList<T>::insert_Before(ListNode<T>* node, T key)
{
	TList<T>::insert_Before(node, key);
	if (pFirst == node)
	{
		pHead->next = this->pFirst;
	}
}

template <typename T>
void HeadList<T>::remove_First()
{
	TList<T>::remove_First();
	pHead->next = this->pFirst;
}

template <typename T>
const HeadList<T>& HeadList<T>::operator=(const HeadList& other)
{
	if (this != &other) {
		TList<T>::operator=(other);
		delete pHead;
		pHead = new ListNode<T>(T(), pFirst);
	}
	return *this;
}

template <typename T>
bool HeadList<T>::operator==(const HeadList<T>& s) const
{
	return TList<T>::operator==(s);
}

template <typename T>
bool HeadList<T>::operator!=(const HeadList<T>& s) const
{
	return !(*this == s);
}