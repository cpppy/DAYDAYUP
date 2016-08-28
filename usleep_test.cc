#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
	int a=0;	
	for(int i=0;i<10;++i)
	{
		cout<<i<<endl;
		usleep(1000000);   // micro-second
		
	}
	
	return 0;

}
