#pragma once
#include <iostream>

template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(const T& x, ListNode* next = nullptr) : val(x), next(next) {}

};


template<typename T>
class TList
{
protected:
    ListNode<T>* pFirst;
    ListNode<T>* pLast;
    ListNode<T>* pCurr;
    ListNode<T>* pPrev;
    ListNode<T>* pStop;
public:
    TList();
    TList(const T& x);
    TList(const TList<T>& list);
    ~TList();

    ListNode<T>* get_first() const { return pFirst; } //for tests
    ListNode<T>* get_curr() const { return pCurr; }
    bool is_end() const;
    void Next();
    void reset();

    ListNode<T>* search(T key);

    virtual void insert_Front(ListNode<T>* node);
    void insert_Back(ListNode<T>* node);

    void insert_After(ListNode<T>* node, T key);
    virtual void insert_Before(ListNode<T>* node, T key);

    void remove(T key);
    virtual void remove_First();

    size_t size() const;

    virtual bool operator==(const TList<T>& s) const;
    virtual bool operator!=(const TList<T>& s) const { return !(*this == s); }

    virtual const TList& operator=(const TList& other);
};

template<typename T>
TList<T>::TList()
{
    pFirst = nullptr;
    pLast = nullptr;
    pCurr = nullptr;
    pPrev = nullptr;
    pStop = nullptr;
}

template<typename T>
TList<T>::TList(const T& x) {
    pStop = nullptr;
    pFirst = new ListNode<T>(x, pStop);
    pLast = pFirst;
    pCurr = pFirst;
}

template<typename T>
TList<T>::TList(const TList<T>& list): TList() { // TODO: copy

    if (list.pFirst == nullptr) {
        return;
    }
    pFirst = new ListNode<T>(list.pFirst->val);
    pCurr = pFirst;
    pStop = nullptr;
    pPrev = nullptr;
    ListNode<T>* curr = list.pFirst->next;
    if (curr == pStop) {
        pLast = pFirst;
        return;
    }
    while (curr != list.pStop) {
        pCurr->next = new ListNode<T>(curr->val);
        pPrev = pCurr;
        pCurr = pCurr->next;
        curr = curr->next;
    }
    pPrev->next = pCurr;
    pLast = pCurr;
    pCurr = pFirst;
    pPrev = pStop;
}

template<typename T>
TList<T>::~TList() {

    if (pFirst == nullptr) { // TODO: clear
        return;
    }

    ListNode<T>* current = pFirst;
    while (current != pStop) {
        ListNode<T>* next = current->next;
        delete current;
        current = next;
    }
    pFirst = nullptr;
    pLast = nullptr;
    pCurr = nullptr;
    pPrev = nullptr;
    pStop = nullptr;
}

template<typename T>
bool TList<T>::is_end() const
{
    return (pCurr == pStop);
}

template<typename T>
void TList<T>::Next() {
    if (pCurr != pStop)
    {
        pPrev = pCurr;
        pCurr = pCurr->next;
    }
    else {
        pPrev = nullptr;
        pCurr = pFirst;
    }
}

template<typename T>
void TList<T>::reset()
{
    pPrev = nullptr;
    pCurr = pFirst;
}

template<typename T>
ListNode<T>* TList<T>::search(T key) {
    pCurr = pFirst;
    pPrev = nullptr;
    while (pCurr != pStop && pCurr->val != key)
    {
        pPrev = pCurr;
        pCurr = pCurr->next;
    }
    return pCurr;
};

template<typename T>
void TList<T>::insert_Front(ListNode<T>* node) {
    if (node == nullptr) {
        throw "cant push null node in front";
    }
    if (pFirst == nullptr) {
        pFirst = node;
        pLast = node;
        node->next = pStop;
        pCurr = pFirst;
        pPrev = nullptr;
        return;
    }
    node->next = pFirst;
    pFirst = node;
};

template<typename T>
void TList<T>::insert_Back(ListNode<T>* node) {
    if (node == nullptr) {
        throw "cant insert empty Node";
    }
    if (pFirst == nullptr) {
        insert_Front(node);
    }
    else {
        pLast->next = node;
        pLast = node;
        pLast->next = pStop;
    }
}

template<typename T>
void TList<T>::insert_After(ListNode<T>* node, T key) {
    if (node == nullptr)
    {
        throw "cant insert empy node after";
    }
    search(key);
    if (pCurr == nullptr) {
        throw "this key does not exist";
    }
    if (pCurr->next == pStop)
    {
        insert_Back(node);
        return;
    }
    node->next = pCurr->next;
    pCurr->next = node;
};

template<typename T>
void TList<T>::insert_Before(ListNode<T>* node, T key) {
    if (node == nullptr)
    {
        throw "cant insert empy node before";
    }
    search(key);
    if (pCurr == nullptr)
    {
        throw "this key does not exist";
    }
    if (pCurr == pFirst)
    {
        insert_Front(node);
        return;
    }
    node->next = pCurr;
    pPrev->next = node;
};

template<typename T>
void TList<T>::remove(T key) {
    search(key);
    if (pCurr == nullptr) {
        throw "this key does not exist";
    }

    if (pCurr == pFirst) {
        remove_First();
        return;
    }
    pPrev->next = pCurr->next;
    delete pCurr;
    pCurr = pFirst;
    pPrev = nullptr;
};

template<typename T>
void TList<T>::remove_First() {
    if (pFirst == nullptr) {
        throw "List is empty";
    }
    ListNode<T>* temp = pFirst;

    if (pFirst->next == nullptr)
    {
        delete pFirst;
        pFirst = nullptr;
        pCurr = nullptr;
        pLast = nullptr;
        return;
    }
    pFirst = pFirst->next;
    delete temp;
    pCurr = pFirst;
    pPrev = nullptr;
}

template<typename T>
size_t TList<T>::size() const {
    ListNode<T>* curr = pFirst;
    size_t size = 0;
    while (curr != pStop) {
        size++;
        curr = curr->next;
    }
    return size;
};

template<typename T>
bool TList<T>::operator==(const TList<T>& s) const {

    ListNode<T>* curr1 = this->pFirst, * curr2 = s.pFirst;

    while (curr1 != pStop && curr2 != s.pStop) {

        if (curr1->val != curr2->val) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    if (curr1 == nullptr && curr2 == nullptr) {
        return true;
    }
    return false;
}

template<typename T>
const TList<T>& TList<T>::operator=(const TList& other) {
    if (this == &other)
    {
        return *this;
    }

    if (pFirst)
    {
        pCurr = pFirst;
        while (pCurr != pStop) {
            pPrev = pCurr;
            pCurr = pCurr->next;
            delete pPrev;
        }
    }

    pStop = nullptr;
    if (other.pFirst == nullptr)
    {
        return *this;
    }

    pFirst = new ListNode<T>(other.pFirst->val);
    pCurr = pFirst;
    ListNode<T>* curr = other.pFirst->next;

    while (curr != pStop)
    {
        pCurr->next = new ListNode<T>(curr->val);
        pCurr = pCurr->next;
        curr = curr->next;
    }
    pLast = pCurr;

    pCurr = pFirst;
    pPrev = nullptr;

    return *this;
}