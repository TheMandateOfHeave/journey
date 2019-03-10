#ifndef QUEUE_H
#define QUEUE_H

typedef int ElemType;

#define TRUE 1
#define FALSE 0

typedef class Node
{
public:
	Node();
	~Node();
private: 
	ElemType _data;
	Node *_next;

	friend class queue;
	friend void showDate(const Node &_data);
}Node;


typedef class queue
{
public:
	queue();
	~queue();
	Node* queue::BuyNode();

	bool InsertElemToQueue(ElemType val);
	bool PopQueue();
	int getSize();
	bool IsFull();
	bool IsEmpty();

	void Show();
private:
	Node _head;
	Node *_tail;
	int _count;
}Queue,*Pqueue;

#endif