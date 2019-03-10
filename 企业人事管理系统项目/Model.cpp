#include "Model.h"
#include "View.h"


ModelList::ModelList()
{
	ModelNode *p = &_head;
	while(p->_next != NULL)
	{
		p = p->_next;
	}

	for(int i=4;i>0;i--)
	{
		ModelNode* s = new ModelNode;
		  if( i == 1 )
		  {
			  s->_key = '1';
			  Fun fun = view::Insert;
			  s->_fun_val = fun;
		  }

		  if( i == 2)
		  {
			  s->_key = '2';
			  Fun fun = view::Delete;
			  s->_fun_val = fun;
		  }

		  if( i == 3)
		  {
			  s->_key = '3';
			  Fun fun = view::Check;
			  s->_fun_val = fun;
		  }

		  if( i == 4)
		  {
			  s->_key = '4';
			  Fun fun = view::Change;
			  s->_fun_val = fun;
		  }
		  s->_next = p->_next;
		  p->_next = s;
	}
	_count = 4;
}

ModelList::ModelList(ModelList &src)
{
	ModelNode *p = src._head._next;

	for( int i=0;i<src._count;i++)
	{
		ModelNode *q = &_head;
		for(int j=0;j<_count;j++)
		{
			q = q->_next;
		}
		ModelNode *s = new ModelNode;
		s->_key = p->_key;
		s->_next = p->_next;
		q->_next = s;
		_count++;
		p = p->_next;
	}
}

ModelList & ModelList::operator=(ModelList &src)
{
	if( this == &src)
	{
		return *this;
	}

	if( NULL != _head._next)
	{
		delete _head._next;
	}

	ModelNode *p = src._head._next;
	return *this;
}


//ModelNode*  ModelNode::BuyNode(char key)
//{
//		  ModelNode *p = new ModelNode;
//		  p->_key = key;
//		  if( key == '1' )
//		  {
//			  Fun fun = view::Insert;
//			  *p->_fun_val = fun;
//		  }
//
//		  if( key == '2')
//		  {
//			  Fun fun = view::Delete;
//			  *p->_fun_val = fun;
//		  }
//
//		  if( key == '3')
//		  {
//			  Fun fun = view::Check;
//			  *p->_fun_val = fun;
//		  }
//
//		  if( key == '4')
//		  {
//			  Fun fun = view::Change;
//			  *p->_fun_val = fun;
//		  }
//	
//		  p->_next = NULL;
//		  return p;
//}

Fun ModelList::search(char c)
{
	ModelNode *p = &_head;
	while(  c != p->_key && p != NULL)
	{
		cout << c <<endl;
		p = p->_next;
	}
	
	return p->_fun_val;
}