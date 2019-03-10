#include <iostream>
using namespace std;




template<typename T>
class Carry//ÈÝÆ÷
{
public:
	Carry(int resize = 2)
	{
		//cout << "Carry(int resize = 0)" << endl;
		_arr = new T[resize];
		_len = resize;
		_sizeVal = 0;
	}

	 template<typename U>
	Carry<T>(const Carry<U> &src)
 {
	 _arr = new T[src._len];
	 _len = src._len;
	 _sizeVal = src._sizeVal;
	 for(int i=0;i<_sizeVal;i++)
	 {
		 _arr[i] = src._arr[i];
	 }

 }




    Carry operator=(const Carry& src);

	~Carry()
	{
		//cout << "~Carry()" << endl;
		delete[]_arr;
	}

	Carry(const Carry &src)
	{
		//cout << "Carry(const Carry &src)" << endl;
		_arr = new T[src._len];
		_len = sr._len;
		_sizeVal = src._sizeVal;
		copyFrom(src);
	}

	void copyFrom(const Carry &src)
	{
		//cout << "void copyFrom(const Carry &src)" << endl;
		for (int i = 0; i < src._sizeVal; i++)
		{
			_arr[i] = src._arr[i];
		}
	}

	Carry &operator=(const Carry& src)
	{
		//cout << "Carrty &operator=(const Carry& src)" << endl;
		if (&src == this)
		{
			return *this;
		}

		delete []_arr;

		_arr = new T[src._len];
		_len = sr._len;
		_sizeVal = src._sizeVal;
		copyFrom(src);
	}

	void pushBack(T val)
	{
		//cout << "void pushBack(T val)" << endl;
		if (isFull())
		{
			reSize();
		}
		_arr[_sizeVal++] = val;
		cout<<_arr[_sizeVal-1]<<endl;
	}
	//void insert(int sit, T val);
	bool popBack()
	{
		//cout << "bool popBack()" << endl;
		if (isEmpty())
		{
			return false;
		}
		
		_sizeVal--;	
		return true;
	}
	//bool deleteSit(int sit);
	T getBack()
	{
		//cout << "T getBack()" << endl;
		if (isEmpty())
		{
			return T();
		}
		return _arr[_sizeVal - 1];
	}
	bool isFull()
	{
		//cout << "bool isFull()" << endl;
		return _sizeVal == _len;
	}
	bool isEmpty()
	{
		//cout << "bool isEmpty()" << endl;
		return _sizeVal == 0;
	}

	void reSize()
	{
		//cout << "void reSize()" << endl;
		T* tmp = new T[_len + (_len >> 1)];
		for (int i = 0; i < _len; i++)
		{
			tmp[i] = _arr[i];
		}

		delete []_arr;
		_arr = tmp;
		_len = _len + (_len >> 1);
	}

	void show()
	{
		for (int i = 0; i < _sizeVal; i++)
		{
			cout << _arr[i] << "  ";
		}
		cout << endl;
	}
	
	int find(T val)
	{	
		//cout <<"int find(T val)" << endl;
		for (int i = 0; i < _sizeVal; i++)
		{
			if (_arr[i] == val)
			{
				return i;
			}
		}
		return -1;
	}

	template<typename U>
	int find(U val)
	{
		//cout << "template<typename U> int find(U val)" << endl;
		for (int i = 0; i < _sizeVal; i++)
		{
			if (_arr[i] == val)
			{
				return i;
			}
		}
		return -1;
	}

	template<>
	int find<char*>(char * val)
	{
		//cout << "template<> int find<char*>(char * val)" << endl;
		for (int i = 0; i < _sizeVal; i++)
		{
			if (strcmp(_arr[i],val) == 0)
			{
				return i;
			}
		}
		return -1;
	}

	template<typename T>
	void sort(T* arr,int len)
	{
		int i=0;
		int j=0;
		for(i=0;i<_len;i++)
		{
			for(j=i+1;j<_len;j++)
			{
				if(arr[i]<arr[j])
				{
					T tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}


private:
	T *_arr;
	int _len;
	int _sizeVal;

};


   


template<typename T,typename Container = Carry<T> >
class Stack
{
public:
	Stack(int size=2)
		:_con(size=2)
	{

	}

	void copyFrom(Carry<T> &carry)
	{
		carry.copyFrom(carry);
	}
	

	void stackpushBack(Carry<T> &carry,T val)
	{
		carry.pushBack(val);
	}

	bool stackPopback(Carry<T> &carry)
	{
		carry.popBack();
		return 1;
	}

	T stackgetBack(Carry<T> &carry)
	{
		carry.getBack();
	}

	bool stackisFull(Carry<T> &carry)
	{
		carry.isFull();
		return 1;
	}
	
	bool stackisEmpty(Carry<T> &carry)
	{
		carry.isEmpty();
		return 1;
	}

	void stackreSize(Carry<T> &carry)
	{
		carry.reSize();
	}

	void stackshow(Carry<T> &carry)
	{
		carry.show();
	}

	int stackfind(Carry<T> &carry,T val)
	{
		carry.find(val);
		return val;
	}

private:
	Container _con;
};


int main()
{
	Carry<int> arr1;
	Stack<int> arr2;
	int i=0;
	for(i=0;i<10;i++)
	{
	  arr2.stackpushBack(arr1,i);
	}
}