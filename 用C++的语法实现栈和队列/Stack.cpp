#include"Stack.h"
#include<iostream>
using namespace std;


Node::Node()
{
	_next = NULL;
}

stack::stack()
{
	_count = 20;
	_top = NULL;
	_buttom = NULL;
}


bool stack::IsFull()
{
	if( _top == _count )
	{
		return TRUE;
	}

	return FALSE;
}

bool stack::IsEmpty()
{
	if( _top == _buttom )
	{
		return TRUE;
	}

	return FALSE;
}
stack::~stack()
{
	
	Node *p = this->_head;

	while( _head )
	{
		p = _head;
		_head = _head->_next;
		delete(p);
	}
}


int stack::FindTheValue(int pos)
{
	Node *p;
	p = _head;
	while( pos > 1)
	{
		p = p->_next;
		pos--;
	}
	return p->_data;
}

bool stack::FindTheValuePos(int value)
{
	Node *p;
	p = _head;
	int pos =0;
	while( p != NULL)
	{
		if( p->_data == value)
		{
			printf("%d\n",pos);
			return TRUE;
		}
		pos++;
	}

	return FALSE;
}

Node* stack::BuyNode()
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

bool stack::InsertElemToStack(ElemType value)
{
	Node *p = this->BuyNode();
	if( NULL == p )
	{
		printf("insert error\n");
		return FALSE;
	}
	Node* s = _head;
	p->_next = s->_next;
	p->_data = value;
	s->_next = p;
	_top++;
	return TRUE;
}

Node* stack::getHead()
{
	Node *p = _head;
	return p;
}

void stack::PopStack()
{
	Node* p = _head;
	while( p ->_next->_next != NULL )
	{
		p = p->_next;
	}
	Node* s = p;
	p = p->_next;
	delete p;
	s->_next = NULL;
	_top--;
}


void stack::Show()
{
	Node* p = _head;
	while( p != NULL )
	{
		cout<<p->_data<<endl;
		p = p->_next;
	}
}