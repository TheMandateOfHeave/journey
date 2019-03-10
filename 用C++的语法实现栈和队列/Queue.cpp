#include"Queue.h"
#include<iostream>
using namespace std;


Node::Node()
{
	_next = NULL;
}

queue::queue()
{
	this->_head._next = _tail =NULL;
	this->_count = 0;
	this->_head._data = 0;
}

queue::~queue()
{
	Node *p = _head._next;
	while ( NULL != p )
	{
		delete this->_head._next;
		this->_head._next = p;
		p = p->_next;
	}
	this->_tail = NULL;
	this->_count = 0;
}

Node* queue::BuyNode()
{
	Node *s = new Node;
	if( NULL == s)
	{
		printf("BuyNode error\n");
		return NULL;
	}

	memset(s,0,sizeof(Node));

	return s;
}

int queue::getSize()
{
	return this->_count;
}

bool queue::IsEmpty()
{
	if( getSize() == 0 )
	{
		printf("true\n");
		return TRUE;
	}
	printf("false\n");
	return FALSE;
}

bool  queue::InsertElemToQueue(ElemType val)
{
	Node *p = this->BuyNode();
	if( NULL == p )
	{
		printf("insert error\n");
		return FALSE;
	}

	p->_data = val;

	if( this->IsEmpty() )
	{
		this->_head._next = p;
		this->_tail = p;
	}
	else
	{
		this->_tail->_next = p;
		this->_tail = p;
	}

	this->_count++;
	printf("insert success\n");
	return TRUE;

}

bool queue::PopQueue()
{
	if( IsEmpty())
	{
		printf("have no data\n");
		return FALSE;
	}

	Node *p = _head._next;
	if( p->_next == NULL )
	{
		this->_tail = NULL;
	}

	this->_head._next = p->_next;
	delete p;
	this->_count--;
	return TRUE;
}


void queue::Show()
{
	Node *p = _head._next;
	while ( p!= NULL)
	{
		cout<<p->_data<<endl;
		p = p->_next;
	}

	cout<<endl;
}