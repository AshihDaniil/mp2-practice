#include "list.h"
#include <gtest.h>

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> l);
}

TEST(TList, can_create_list_with_firs_elem)
{
	ASSERT_NO_THROW(TList<int> l(123));
}

TEST(TList, can_insert_back_elem_in_empty_list)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	ASSERT_NO_THROW(l.insert_Back(n1));
}

TEST(TList, can_insert_front_elem_in_empty_list)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	ASSERT_NO_THROW(l.insert_Front(n1));
}

TEST(TList, cant_insert_front_nullptr_in_not_empty_list)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	l.insert_Front(n1);
	ASSERT_ANY_THROW(l.insert_Front(nullptr));
}
TEST(TList, can_create_copied_lists)
{
	TList<int> l1(1);
	ASSERT_NO_THROW(TList<int> list(l1));
}

TEST(TList, copied_lists_are_equal)
{
	TList<int> l1(1);
	TList<int> l2(l1);
	EXPECT_TRUE(l1 == l2);
}

TEST(TList, assigned_lists_are_equal)
{
	TList<int> l1(1);
	TList<int> l2;
	l2 = l1;
	EXPECT_TRUE(l1 == l2);
}

TEST(TList, can_search_existing_elem)
{
	TList<int> list(1);
	ASSERT_NO_THROW(list.search(1));
}

TEST(TList, cant_search_not_existing_elem)
{
	TList<int> list(1);
	EXPECT_TRUE(list.search(7) == nullptr);
}
TEST(TList, search_work_correctly)
{
	TList<int> l(1);
	l.insert_Back(new ListNode<int>(2));
	l.insert_Back(new ListNode<int>(3));
	l.insert_Back(new ListNode<int>(4));
	EXPECT_TRUE(l.search(1)->val == 1);
	EXPECT_TRUE(l.search(3)->val == 3);
}

TEST(TList, search_an_not_existing_element_return_false)
{
	TList<int> l(123);
	EXPECT_FALSE(l.search(321));
}

TEST(TList, cant_insert_Front_nullptr_in_not_empty_list)
{
	TList<int> list(1);
	ASSERT_ANY_THROW(list.insert_Front(nullptr));
}

TEST(TList, insert_Front_work_correctly)
{
	TList<int> list(1);
	list.insert_Front(new ListNode<int>(2));
	EXPECT_TRUE(list.get_first()->val == 2);
}

TEST(TList, cant_insert_Back_nullptr_in_not_empty_list)
{
	TList<int> list(1);
	ASSERT_ANY_THROW(list.insert_Front(nullptr));
}

TEST(TList, insert_Back_work_correctly)
{
	TList<int> list(1);
	list.insert_Back(new ListNode<int>(2));
	list.insert_Back(new ListNode<int>(3));
	EXPECT_TRUE(list.get_first()->next->next->val == 3);
}

TEST(TList, cant_insert_After_nullptr_in_not_empty_list)
{
	TList<int> list(1);
	ASSERT_ANY_THROW(list.insert_After(nullptr, 1));
}

TEST(TList, insert_After_work_correctly)
{
	TList<int> list(1);
	list.insert_Back(new ListNode<int>(2));
	list.insert_Back(new ListNode<int>(3));
	list.insert_After(new ListNode<int>(4), 1);
	EXPECT_TRUE(list.get_first()->next->val == 4);
}

TEST(TList, cant_insert_Before_nullptr_in_not_empty_list)
{
	TList<int> list(1);
	ASSERT_ANY_THROW(list.insert_Before(nullptr, 1));
}

TEST(TList, insert_Before_work_correctly)
{
	TList<int> list(1);
	list.insert_Back(new ListNode<int>(2));
	list.insert_Back(new ListNode<int>(3));
	list.insert_Before(new ListNode<int>(4), 2);
	EXPECT_TRUE(list.get_first()->next->val == 4);
}

TEST(TList, can_remove_First)
{
	TList<int> list(1);
	ASSERT_NO_THROW(list.remove_First());
}

TEST(TList, cant_remove_First_in_empy_list)
{
	TList<int> list;
	ASSERT_ANY_THROW(list.remove_First());
}

TEST(TList, remove_First_work_correctly)
{
	TList<int> list(1);
	list.insert_Back(new ListNode<int>(2));
	list.insert_Back(new ListNode<int>(3));
	list.insert_Back(new ListNode<int>(4));
	list.remove_First();
	EXPECT_TRUE(list.get_first()->val == 2);
}

TEST(TList, can_remove)
{
	TList<int> list(1);
	ASSERT_NO_THROW(list.remove(1));
}

TEST(TList, remove_work_correctly1)
{
	TList<int> list(1);
	list.insert_Back(new ListNode<int>(2));
	list.remove(2);
	EXPECT_TRUE(list.get_first()->next == nullptr);
}

TEST(TList, remove_work_correctly2)
{
	TList<int> list(1);
	list.insert_Back(new ListNode<int>(2));
	list.insert_Back(new ListNode<int>(3));
	list.insert_Back(new ListNode<int>(4));
	list.remove(2);
	EXPECT_EQ(3, list.get_first()->next->val);
}

TEST(TList, list_operator_eq_work_correctly)
{
	TList<int> list1(1);
	list1.insert_Back(new ListNode<int>(2));
	list1.insert_Back(new ListNode<int>(3));
	list1.insert_Back(new ListNode<int>(4));
	TList<int> list2(1);
	list2.insert_Back(new ListNode<int>(2));
	list2.insert_Back(new ListNode<int>(3));
	list2.insert_Back(new ListNode<int>(4));

	EXPECT_TRUE(list1 == list2);
}

TEST(TList, list_operator_not_eq_work_correctly)
{
	TList<int> list1(1);
	list1.insert_Back(new ListNode<int>(2));
	list1.insert_Back(new ListNode<int>(3));
	list1.insert_Back(new ListNode<int>(4));
	TList<int> list2(1);
	list2.insert_Back(new ListNode<int>(2));

	EXPECT_TRUE(list1 != list2);
}