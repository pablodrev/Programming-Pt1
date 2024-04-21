#include <iostream>

#pragma once
struct ListNode
{
	ListNode* next;
	int value;
	ListNode(int num);
};

class List
{
public:
	List(int n);
	void Insert(int index, int num);
	void Print();
	ListNode* getHead();
	~List();

private:
	ListNode* head = nullptr;
	ListNode* tail = nullptr;
	int len = 0;
};