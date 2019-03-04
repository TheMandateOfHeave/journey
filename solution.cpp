#include  "solution.h"
#include <iostream>
using namespace std;
#include <list>


void adjust(int* arr,int len)
{
	int i=0;
	int j=len-1;
	int tmp=0;
	for(i=0;i<j;i++)
	{
		while(arr[j]%2 == 0 && j>i)
		{
			j--;
		}
		while(arr[i]%2 == 1 && j>i)
		{
			i++;
		}
		tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}
}


int fibonacci(int n)
{
	if(n<=1)
	{
		return 1;
	}

	int a=1;
	int b=1;
	int tmp=0;
	int result=0;
	while(n>2)
	{
		tmp=a;
		a=b;
		b += tmp;
		n--;
	}
	result = b;

	return result;
}


double mypow(double x,int n)
{
	    double result = x;
    if(x>0.999999 && x<1.000001)
    {
        result = 1.000000;
        return result;
    }
  
    int sign = n;
	if(n < 0)
	{
		sign *= -1;
	}    
    
	if(x > -0.000001 && x < 0.000001)
	{
        result = 0.000000;
		return result;
	}

	if( n == 0 )
	{
        result = 1.000000;
		return result;
	}

	if( n == 1)
	{
        result = x;
		return result;
	}
        

	while(sign>1)
	{
		result *= result;
		sign = sign/2;
		if((sign & 0x1) == 1 && (sign != 1))
	  {
		result *= x;
	  }
	}

	if(n < 0)
	{
		result = 1.0/result;
	}

	return result;
}

void find(int n)
{
	unsigned int sign = 1;
	int count=0;
	while(sign)
	{
		if(n & sign)
		{
			count++;
		}
		sign = sign<<1;
	}
	printf("%d\n",count);
}


void ChangeString(char* s)
{
	char* p = s;
	char* sign = s;
	int count=0;
	while( *s != '\0')
	{
		if(*s == ' ')
		{
			count++;
		}
		s++;
	}
	s--;
	p = s;
	s += count*2;
	while( p != sign)
	{
		if(*p == ' ')
		{
			*s-- = '0';
			*s-- = '2';
			*s-- = '%';
		}
		else
		{
			*s-- = *p;
		}
		p--;
	}
}

bool Check(char* str)
{
	int count = 0;
	int tmp=0;
	if(str == NULL)
	{
		cout<<"error1"<<endl;
		return false;
	}
	if(*str == '.')
	{
		cout<<"error2"<<endl;
		return false;
	}

	if(*str=='0')
	{
		cout<<"error3"<<endl;
		return false;
	}
	while(*str != '\0')
	{
		if(!isdigit(*str) && (*str != '.'))
		{
			cout<<"error4"<<endl;
			return false;
		}
		if(*str == '.' && *(str-1) == '.')
		{
			cout<<"error5"<<endl;
			return false;
		}
		if(*str == '.')
		{
			count++;
		}

		if(isdigit(*str))
		{
			tmp  = tmp*10+(*str - '0');
			if(tmp>255)
			{
				cout<<"error6"<<endl;
				return false;
			}
		}

		if(tmp>255)
		{
			cout<<"error7"<<endl;
			return false;
		}

		if(*str == '.')
		{
			tmp = 0;
		}
		str++;
	}
	if(*(str-1) == '.')
	{
		return false;
	}
	if(count != 3)
	{
		cout<<"error8"<<endl;
		return false;
	}

	cout<<"right"<<endl;
	return true;
}

bool IsLittle()
{
	short a = 0x0001;
	return *(char*)&a == 0x01;
}

long Htonl(long a)
{
	long b = 0;
	if(!IsLittle())
	{
		return a;
	}

	for(int i=0;i<sizeof(a);i++)
	{
		b = (b<<8) | (a & 0xff);
		a >>= 8;
	}

	return b;
}

int Search(int *arr,int len,int key)
{
	int low = 0;
	int high = len-1;
	int mid;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(arr[mid] == key)
		{
			return mid;
		}
		else if(arr[mid] < key)//ÔÚÓÒ±ßÕÒ
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return mid;
}

bool Search_7_5(int (*arr)[4],int val)
{
	int row = 4;
	int col = 4;
	int j ;
	for(int i=0;i<row;i++)
	{
		j = Search(arr[i],col,val);
		if(val == arr[i][j])
		{
			cout<<"find it"<<endl;
			return true;
		}
		else 
		{
			col = j+1;
		}
	}
	cout<<"not find it"<<endl;
	return false;
}
