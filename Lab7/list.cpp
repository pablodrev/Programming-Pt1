#include "list.h"

ListNode::ListNode(int num)
{
	value = num;
	next = nullptr;
}

// ������� ��������
void List::Insert(int index, int num)
{
	// ������������ � ��������, ����� �������� ����� ������� �������
	ListNode* current = head;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}
	// ������� ����� ������� � ����������� ���������
	ListNode* tmp = new ListNode(num);
	tmp->next = current->next;
	current->next = tmp;
	len++;
}

// ����� ������ �� �����
void List::Print()
{
	ListNode* current = head;
	/*do 
	{
		std::cout << current->value << " ";
		current = current->next;
	} while (current != tail);*/
	for (int i = 0; i < len; i++)
	{
		std::cout << current->value << " ";
		current = current->next;
	}
	
	std::cout << std::endl;
}

ListNode* List::getHead()
{
	return head;
}

List::List(int n)
{
	int value;
	std::cout << "�������� �������� ��������: ";
	std::cin >> value;

	head = new ListNode(value);
	ListNode* current = head;
	len++;
	for (int i = 0; i < n-1; i++)
	{
		std::cout << "�������� �������� ��������: ";
		std::cin >> value;
		current->next = new ListNode(value);
		current = current->next;
		len++;
	}
	tail = current;
	tail->next = head;
}

List::~List()
{
	ListNode* current;
	while (head)
	{
		current = head;
		head = head->next;
		delete current;
	}
}