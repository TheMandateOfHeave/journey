#ifndef MODEL_H
#define MODEL_H

#include <iostream>
using namespace std;


typedef void (*Fun) ();


class ModelNode
{
public:
	ModelNode()
	{
		_next = NULL;
	}
	ModelNode * BuyNode(char key);
private:
	char _key;
	Fun _fun_val;
	ModelNode* _next;
	friend class ModelList;
};



class ModelList
{
public:
	ModelList();
	ModelList(ModelList &src);
	ModelList &operator=(ModelList &src);
	Fun search( char c);
private:
	ModelNode _head;
	int _count;
};

#endif