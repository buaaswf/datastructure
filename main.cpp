//
#include "LinkList.h"
int main()
{
	LinkList l = CREAT(4);
	ElementType item;
	std::cin >> item ; 
	INSERTLINKI(l,item,2);
	DELLIST(l);
	printlist(l);
	system("pause");
	return 0;
}