#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
#include "solution.h"


void ChangeToQueue(stack<int> &stack1,stack<int> &stack2,int val)
{
	stack1.push(val);
	cout<<stack1.top()<<"    ";
	cout<<endl;
}

void ChangeToQueue2(stack<int> &stack1,stack<int> &stack2,int val)
{
	int len = stack1.size();
	if(stack2.empty())
	{
		for(int i=0;i <len ;i++)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	cout<<stack2.top()<<endl;;
	
	stack2.pop();
}

void ChangeToStack(queue<int> &queue1,queue<int> &queue2,int val)
{
	queue1.push(val);
}

void ChangeToStack2(queue<int> &queue1,queue<int> &queue2,int val)
{
	while(!queue1.empty())
	{
		queue2.push(queue1.front());
		queue1.pop();
	}
	cout<<queue2.front()<<endl;
	queue2.pop();
	while(!queue2.empty())
	{
		queue1.push(queue2.front());
		queue2.pop();
	}
}

template<typename T>
void Swap(T a,T b)
{
	T tmp; 
	tmp = *a;
	*a = *b;
	*b = tmp;
}

template <typename T>
int Compare(T a,T b)
{
	return a>b?1:0;
}



template <typename T>
void Busort(T arr[],int len)
{
	T tmp;
	int i=0;
	for(i=0;i<len-1;i++)
	{
		for(int j=0;j<len-i-1;j++)
		{
			if(Compare(arr[j],arr[j+1]))
			{
				tmp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}

	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<"     ";
	}
	cout<<endl;
}


int main()
{
	/*
	int arr[8]={1,3,5,4,7,6,8,1};
	int len=sizeof(arr)/sizeof(arr[0]);
	adjust(arr,len);
	for(int i=0;i<len;i++)
	{
		printf("%d   ",arr[i]);
	}
	printf("\n");
	int arr2[18]={1,3,5,4,7,6,8,1,15,4,9,8,6,5,1,3,7,6};
	int len2=sizeof(arr2)/sizeof(arr2[0]);
	adjust(arr2,len2);
	for(int i=0;i<len2;i++)
	{
		printf("%d   ",arr2[i]);
	}
	printf("\n");
	

	
	int n=4;
	int num=0;
	num=fibonacci(n);
	printf("%d\n",num);

	num=fibonacci(n+3);
	printf("%d\n",num);
	


	
	double a = 5.0;
	n=2;
	double result=0.000;
	
	/*double result = 0;
	result = mypow(a,n);
	printf("%f\n",result);


	a = 0.5;
	result = mypow(a,n);
	printf("%f\n",result);
	
	result = mypow(34.00515,-3);
	printf("%f\n",result);

	result = mypow(2.000000,-2);
	printf("%f\n",result);

	result = mypow(a,2);
	printf("%f\n",result);
	

	result = mypow(a,-2);
	printf("%f\n",result);*/

	/*
	stack<int> stack1;
	stack<int> stack2;
	for(int i=0;i<10;i++)
	{
		ChangeToQueue(stack1,stack2,i);
	}
	cout<<endl;
	for(int i=0;i<10;i++)
	{
		ChangeToQueue2(stack1,stack2,i);
	}
	*/

	/*
	queue<int> s1;
	queue<int> s2;
	for(int i=0;i<10;i++)
	{
		ChangeToStack(s1,s2,i);
	}
	for(int i=0;i<10;i++)
	{
		ChangeToStack2(s1,s2,i);
	}*/

	/*
	find(5);
	find(15);
	find(115);*/
	
	/*
	int arr[9]={9,8,6,4,2,5,3,1,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	Busort(arr,n);

	double arr2[9]={9.3,8.5,6.7,4.2,1.2,5.6,7.3,2.1,9.5};
	n=sizeof(arr)/sizeof(arr[0]);
	Busort(arr2,n);
	*/

	/*
	char s[20] = "sadlsd asd sad";
	ChangeString(s);
	cout<<s<<endl;
	*/

	/*
	char* s ="23.5.1.6";
	char* s2 = "269.948.3.1";
	char* s3 = "1..5.7.8";
	char* s4 = "a5.9.8.4";
	Check(s);
	Check(s2);
	Check(s3);
	Check(s4);
	*/

	//printf("%x\n",Htonl(0x12345678));


	/*int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	Search_7_5(arr,7);
	Search_7_5(arr,5);
	Search_7_5(arr,20);*/

}
