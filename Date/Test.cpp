#include "Date.h"

int main()
{
	  
	Date d2(2021,2,3);
	d2.Print();
	Date d3(2021, 8, 1);
	d3.Print();
	cout << (d3 - d2) << endl;
	
	return 0;
}