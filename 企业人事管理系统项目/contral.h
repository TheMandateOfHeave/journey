#ifndef   CONTRAL_H
#define   CONTRAL_H

#include <iostream>
#include "Model.h"
#include "View.h"
using namespace std;

class contral
{
public:
	contral(){};
	void process()
	{
		while( 1 )
		{
			cout << "0.exit"  <<endl;
			cout << "1.insert" <<endl;
			cout << "2.delete" <<endl;
			cout << "3.check" <<endl;
			cout << "4.change" <<endl;
			char c;
			cin >> c;
			if( c == '0')
			{
				break;
			}
			_model.search(c)();
			view::Show();
		}
	}
private:
	ModelList _model;
};


#endif