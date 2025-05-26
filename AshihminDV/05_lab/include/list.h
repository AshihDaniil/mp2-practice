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
    void clear();
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

    if (list.pFirst == nullptr) return;

    pFirst = new ListNode<T>(list.pFirst->val);
    ListNode<T>* src = list.pFirst->next;
    ListNode<T>* dest = pFirst;

    while (src != nullptr) {
        dest->next = new ListNode<T>(src->val);
        dest = dest->next;
        src = src->next;
    }

    pLast = dest;
    pCurr = pFirst;
}

template<typename T>
void TList<T>::clear() {
    ListNode<T>* curr = pFirst;
    while (curr != nullptr) {
        ListNode<T>* next = curr->next;
        delete curr;
        curr = next;
    }
    pFirst = pLast = pCurr = pPrev = nullptr;
}

template<typename T>
TList<T>::~TList() {
    clear();
}

template<typename T>
bool TList<T>::is_end() const
{
    return (pCurr == pStop);
}

template<typename T>
void TList<T>::Next() {
    if (pCurr != nullptr) {
        pPrev = pCurr;
        pCurr = pCurr->next;
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
    if (pCurr == pLast) pLast = pPrev;
    delete pCurr;
    reset();
};

template<typename T>
void TList<T>::remove_First() {
    if (pFirst == nullptr) {
        throw "List is empty";
    }

    ListNode<T>* temp = pFirst;
    pFirst = pFirst->next;

    if (temp == pLast) pLast = nullptr;

    delete temp;
    reset();
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

    ListNode<T>* curr1 = pFirst;
    ListNode<T>* curr2 = s.pFirst;

    while (curr1 != pStop && curr2 != s.pStop) {
        if (!(curr1->val == curr2->val)) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return (curr1 == pStop) && (curr2 == s.pStop);
}

template<typename T>
const TList<T>& TList<T>::operator=(const TList& other) {
    if (this == &other)
    {
        return *this;
    }

    clear();

    if (!other.pFirst) return *this;

    pFirst = new ListNode<T>(other.pFirst->val);
    ListNode<T>* curr = pFirst;
    ListNode<T>* src = other.pFirst->next;

    while (src) {
        curr->next = new ListNode<T>(src->val);
        curr = curr->next;
        src = src->next;
    }

    pLast = curr;
    reset();

    return *this;

}

//changed

//template <typename T>
//struct ListNode {
//    T val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(const T& x, ListNode* next = nullptr) : val(x), next(next) {}
//};
//
//template<typename T>
//class TList {
//protected:
//    ListNode<T>* pFirst;
//    ListNode<T>* pLast;
//    ListNode<T>* pCurr;
//    ListNode<T>* pPrev;
//    const ListNode<T>* pStop = nullptr;
//
//    void clear(); // new helper to avoid code duplication
//
//public:
//    TList();
//    TList(const T& x);
//    TList(const TList<T>& list);
//    ~TList();
//
//    ListNode<T>* get_first() const { return pFirst; }
//    ListNode<T>* get_curr() const { return pCurr; }
//    bool is_end() const;
//    void Next();
//    void reset();
//
//    ListNode<T>* search(T key);
//
//    virtual void insert_Front(ListNode<T>* node);
//    void insert_Back(ListNode<T>* node);
//
//    void insert_After(ListNode<T>* node, T key);
//    virtual void insert_Before(ListNode<T>* node, T key);
//
//    void remove(T key);
//    virtual void remove_First();
//
//    size_t size() const;
//
//    virtual bool operator==(const TList<T>& s) const;
//    virtual bool operator!=(const TList<T>& s) const { return !(*this == s); }
//
//    virtual const TList& operator=(const TList& other);
//};
//
//// Constructor & Destructor
//
//template<typename T>
//TList<T>::TList()
//    : pFirst(nullptr), pLast(nullptr), pCurr(nullptr), pPrev(nullptr) {
//}
//
//template<typename T>
//TList<T>::TList(const T& x) : TList() {
//    pFirst = new ListNode<T>(x);
//    pLast = pFirst;
//    pCurr = pFirst;
//}
//
//template<typename T>
//TList<T>::TList(const TList<T>& list) : TList() {
//    if (list.pFirst == nullptr) return;
//
//    pFirst = new ListNode<T>(list.pFirst->val);
//    ListNode<T>* src = list.pFirst->next;
//    ListNode<T>* dest = pFirst;
//
//    while (src != nullptr) {
//        dest->next = new ListNode<T>(src->val);
//        dest = dest->next;
//        src = src->next;
//    }
//
//    pLast = dest;
//    pCurr = pFirst;
//}
//
//template<typename T>
//void TList<T>::clear() {
//    ListNode<T>* curr = pFirst;
//    while (curr != nullptr) {
//        ListNode<T>* next = curr->next;
//        delete curr;
//        curr = next;
//    }
//    pFirst = pLast = pCurr = pPrev = nullptr;
//}
//
//template<typename T>
//TList<T>::~TList() {
//    clear();
//}
//
//// Navigation
//
//template<typename T>
//bool TList<T>::is_end() const {
//    return pCurr == nullptr;
//}
//
//template<typename T>
//void TList<T>::Next() {
//    if (pCurr != nullptr) {
//        pPrev = pCurr;
//        pCurr = pCurr->next;
//    }
//}
//
//template<typename T>
//void TList<T>::reset() {
//    pCurr = pFirst;
//    pPrev = nullptr;
//}
//
//// Search
//
//template<typename T>
//ListNode<T>* TList<T>::search(T key) {
//    pCurr = pFirst;
//    pPrev = nullptr;
//    while (pCurr != nullptr && pCurr->val != key) {
//        pPrev = pCurr;
//        pCurr = pCurr->next;
//    }
//    return pCurr;
//}
//
//// Insertion
//
//template<typename T>
//void TList<T>::insert_Front(ListNode<T>* node) {
//    if (!node) throw "Can't insert null node at front";
//
//    node->next = pFirst;
//    pFirst = node;
//    if (!pLast) pLast = node;
//    reset();
//}
//
//template<typename T>
//void TList<T>::insert_Back(ListNode<T>* node) {
//    if (!node) throw "Can't insert null node at back";
//
//    node->next = nullptr;
//    if (!pFirst) {
//        insert_Front(node);
//    }
//    else {
//        pLast->next = node;
//        pLast = node;
//    }
//}
//
//template<typename T>
//void TList<T>::insert_After(ListNode<T>* node, T key) {
//    if (!node) throw "Can't insert null node after";
//
//    if (!search(key)) throw "Key not found";
//
//    node->next = pCurr->next;
//    pCurr->next = node;
//    if (pCurr == pLast) pLast = node;
//}
//
//template<typename T>
//void TList<T>::insert_Before(ListNode<T>* node, T key) {
//    if (!node) throw "Can't insert null node before";
//
//    if (!search(key)) throw "Key not found";
//
//    if (pCurr == pFirst) {
//        insert_Front(node);
//    }
//    else {
//        node->next = pCurr;
//        pPrev->next = node;
//    }
//}
//
//// Deletion
//
//template<typename T>
//void TList<T>::remove(T key) {
//    if (!search(key)) throw "Key not found";
//
//    if (pCurr == pFirst) {
//        remove_First();
//        return;
//    }pPrev->next = pCurr->next;
//    if (pCurr == pLast) pLast = pPrev;
//    delete pCurr;
//    reset();
//}
//
//template<typename T>
//void TList<T>::remove_First() {
//    if (!pFirst) throw "List is empty";
//
//    ListNode<T>* temp = pFirst;
//    pFirst = pFirst->next;
//
//    if (temp == pLast) pLast = nullptr;
//
//    delete temp;
//    reset();
//}
//
//// Utilities
//
//template<typename T>
//size_t TList<T>::size() const {
//    size_t count = 0;
//    ListNode<T>* curr = pFirst;
//    while (curr) {
//        count++;
//        curr = curr->next;
//    }
//    return count;
//}
//
//template<typename T>
//bool TList<T>::operator==(const TList<T>& s) const {
//    ListNode<T>* a = pFirst;
//    ListNode<T>* b = s.pFirst;
//
//    while (a && b) {
//        if (a->val != b->val) return false;
//        a = a->next;
//        b = b->next;
//    }
//
//    return a == nullptr && b == nullptr;
//}
//
//template<typename T>
//const TList<T>& TList<T>::operator=(const TList<T>& other) {
//    if (this == &other) return *this;
//
//    clear();
//
//    if (!other.pFirst) return *this;
//
//    pFirst = new ListNode<T>(other.pFirst->val);
//    ListNode<T>* curr = pFirst;
//    ListNode<T>* src = other.pFirst->next;
//
//    while (src) {
//        curr->next = new ListNode<T>(src->val);
//        curr = curr->next;
//        src = src->next;
//    }
//
//    pLast = curr;
//    reset();
//
//    return *this;
//}