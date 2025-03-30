#include "list.h"

//ListNode<T>* get_head() const {  // TODO: удалить
//    return pFirst;
//}
//ListNode<T>* get_end() const {  // TODO: удалить
//    return pLast;
//}

//T getCurr() const  // TODO: удалить
//{
//    return pCurr->val;
//}
//
//void set_curr() { // TODO: удалить
//    pCurr = pFirst;
//}
//
//void set_curr_value(const T& value) { // TODO: удалить
//    if (pCurr != nullptr) {
//        pCurr->val = value;
//    }
//}
//
//void remove_current() {  // TODO: удалить
//    if (pCurr == nullptr) return;
//
//    if (pCurr == pFirst) {
//        Remove_First();
//        pCurr = pFirst;
//    }
//    else {
//        ListNode<T>* prev = pFirst;
//        while (prev->next != pCurr) {
//            prev = prev->next;
//        }
//        prev->next = pCurr->next;
//        pCurr = prev->next;
//        if (!prev->next) pLast = prev;
//    }
//}