#include <iostream>


using namespace std;

int main() 
{
	
	int X;
	float Y;
	cin>>X>>Y;
	

	
	if(X%5==0 && X+0.50<Y)
	{
	    Y=Y-X-0.50;
	    cout<<Y;
	}
	else
	{
	    cout<<Y;
	}
	return 0;
}
