#pragma once
#include <iostream>

template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(const T& x) : val(x), next(nullptr) {}

};


template<typename T>
class TList
{
private:
    ListNode<T>* pFirst;
    ListNode<T>* pLast;
    ListNode<T>* pCurr;
    ListNode<T>* pPrev;
    ListNode<T>* pStop;
public:
    TList() {
        pFirst = nullptr;
        pLast = nullptr;
        pCurr = nullptr;
        pStop = nullptr;
    }
    TList(const T& x) {
        pStop = nullptr;
        pFirst = new ListNode<T>(x, pStop);
        pLast = pFirst;
        pCurr = pFirst;
    }
    TList(const TList<T>& list) {
            pFirst = pLast = pCurr = nullptr;
            ListNode<T>* current = list.pFirst;
            while (current != nullptr) {
                insert_Back(new ListNode<T>(current->val));
                current = current->next;
            }
    }

    ~TList() {

        if (pFirst == nullptr) {
            return;
        }

        while (pFirst->next != pStop) {
            ListNode<T>* curr = pFirst;
            pFirst = pFirst->next;
            delete curr;
        }
        pFirst = nullptr;
        pLast = nullptr;
        pCurr = nullptr;
    }


    ListNode<T>* get_head() const {  // TODO: удалить
        return pFirst;
    }
    ListNode<T>* get_end() const {  // TODO: удалить
        return pLast;
    }
    ListNode<T>* get_curr() const {
        return pCurr;
    }

    T getCurr() const  // TODO: удалить
    {
        return pCurr->val;
    }

    void set_curr() { // TODO: удалить
        pCurr = pFirst;
    }

    void set_curr_value(const T& value) { // TODO: удалить
        if (pCurr != nullptr) {
            pCurr->val = value;
        }
    }

    void remove_current() {  // TODO: удалить
        if (pCurr == nullptr) return;

        if (pCurr == pFirst) {
            Remove_First();
            pCurr = pFirst;
        }
        else {
            ListNode<T>* prev = pFirst;
            while (prev->next != pCurr) {
                prev = prev->next;
            }
            prev->next = pCurr->next;
            pCurr = prev->next;
            if (!prev->next) pLast = prev;
        }
    }

    bool is_end() const
    {
        if (pCurr == pStop)
        {
            return 1;
        }
        return 0;
    }

    void Next() {
        if (pCurr != pStop)
        {
            pCurr = pCurr->next;
        }
    }


    ListNode<T>* search(T key) { // TODO:  pPrev и pCurr
        ListNode<T>* curr = pFirst;
        while (curr != nullptr) {
            if (curr->val == key) {
                return curr;
            }
            curr = curr->next;
        }
        if (curr == nullptr) {
            throw "this key does not exist";
        }
        return curr;
    };

    void insert_Front(ListNode<T>* node) {
        if (pFirst == pStop) {
            pFirst = node;
            return;
        }
        if (node == nullptr) {
            throw "cant push null node in front";
        }
        node->next = pFirst;
        pFirst = node;
    };

    void insert_Back(ListNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        if (pFirst == nullptr) {
            insert_Front(node);
        }
        else {
            pLast->next = node;
            pLast = node;
            pLast->next = pStop;
            //pLast->pNext = pStop; RingList pStop=pFirst, DefaultList pStop=nullptr Все циклы делаем до pStop'a 
        }
    }

    void insert_After(ListNode<T>* node, T key) {
        ListNode<T>* curr = search(key);
        if (curr == nullptr) {
            throw "this key does not exist";
        }
        node->next = curr->next;
        curr->next = node;
    };


    void insert_Before(ListNode<T>* node, T key) {
        ListNode<T>* prev = nullptr, * curr = pFirst; // TODO: search
        while ((curr != nullptr) && (curr->val != key)) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            throw "this key does not exist";
        }

        if (prev == nullptr) {
            insert_Front(node);
            return;
        }

        node->next = curr;
        prev->next = node;
    };

    void remove(T key) {
        ListNode<T>* prev = nullptr, * curr = pFirst;
        while ((curr != nullptr) && (curr->val != key)) { // TODO: search
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            throw "this key does not exist";
        }

        if (prev == nullptr) {
            pFirst = pFirst->next;
            delete curr;
            return;
        }
        prev->next = curr->next;
        delete curr;
    };

    void Remove_First() {
        if (pFirst == nullptr) {
            throw "List is empty";
        }
        ListNode<T>* temp = pFirst;
        pFirst = pFirst->next;
        if (pFirst == pStop) {
            pLast = nullptr;
        }
        delete temp;
    }

    size_t size() const {
        ListNode<T>* curr = pFirst;
        size_t size = 0;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }
        return size;
    };

    bool operator==(const TList<T>& s) const {

        ListNode<T>* curr1 = this->pFirst, * curr2 = s.pFirst;

        while (curr1 != nullptr && curr2 != nullptr) {

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

    bool operator!=(const TList<T>& s) const { // TODO: operator==
        ListNode<T>* curr1 = pFirst, * curr2 = s.pFirst;
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val != curr2->val) {
                return 1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        if (curr1 == nullptr && curr2 == nullptr) {
            return 0;
        }
        return 1;
    }

    const TList& operator=(const TList& other) {
        if (this != &other) {
            while (pFirst != nullptr) { // TODO: clear и вызвать здесь и в деструкторе
                Remove_First();
            }

            ListNode<T>* current = other.pFirst;
            while (current != nullptr) {
                insert_Back(new ListNode<T>(current->val));
                current = current->next;
            }
        }

        return *this;
    }
};