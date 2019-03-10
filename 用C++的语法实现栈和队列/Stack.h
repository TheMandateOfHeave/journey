#ifndef STACK_H
#define  STACK_H

typedef int ElemType;

#define TRUE 1
#define FALSE 0


typedef class Node
{
public:
	Node();
private:
	ElemType _data;
	Node *_next;

	friend class stack;
	friend void Show(const Node &_data);
}Node;



typedef class stack
{
public:
	stack();
	~stack();
	Node* stack::BuyNode();

	bool InsertElemToStack(ElemType val);
	void PopStack();
	int FindTheValue(int pos);
	bool FindTheValuePos(int value);
	Node* getHead();
	bool IsFull();
	bool IsEmpty();

	void Show();
private:
	Node *_head;
	int _count;
	int _top;
	int _buttom;
}Stack,*Pstack;
#endif