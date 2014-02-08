#ifndef SWF_DATA_STRUCTURE_H
#define SWF_DATA_STRUCTURE_H
#include<stdio.h>
#include <iostream>
typedef int status;
typedef int ElementType;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct Node * LinkList;
//single list init
//status InitList(linklist *l)
//{
//
//}
LinkList CREAT(int n)
{
	ElementType a; 
	LinkList r,p ,list = NULL;
	
	for(int i=0; i<n; i++)
	{
		std::cin >> a;
		p = (LinkList)malloc(sizeof(Node));
		p->data =a;
		p->next =NULL;
		if( list == NULL)
			list =p;
		else r->next = p; //new link node insert into the rear
		r = p;


	}
	return (list);
}
int LENGTH(LinkList list)
{
	if(list != NULL)
		return 1+LENGTH(list->next);
	else return 0;
}
int ISEMPTY(LinkList list)
{
	return list == NULL;
}
//head node
int ISEMPTYH(LinkList list)
{
	return list->next == NULL;
}
LinkList FIND( LinkList list,ElementType item)
{
	LinkList p = list;
	while(p!=NULL && p->data != item )
		p=p->next;
	return p;
}
//inset a node before the head 
void INSERTLINK(LinkList &list,ElementType data)
{
	LinkList p;
	p =(LinkList)malloc(sizeof (Node));
	p->data = data;
	p->next = list;
	list = p;
	

}
//insert a node in the rear
void INSERTLINKR(LinkList & list,ElementType item)
{

	LinkList p=list,r ;
	while(p !=NULL)
	{
		p = p->next;
	}
	r= (LinkList)malloc(sizeof(Node));
	r->data= item;
	r->next = NULL;


}
//insert a node after the q 
void INSERTLINKAQ(LinkList &list,LinkList q,ElementType item)
{
	LinkList r,p;
	r= list;
	while(r->next != q)
	{
		r = r->next;

	}
	p = (LinkList)malloc(sizeof(Node));
	p->data = item;
	r->next = p;
	p->next = q;


}
//insert a node after the num i node
void INSERTLINKI(LinkList &list ,ElementType item ,int pos)
{
	LinkList p,r,q;
	r = list;
	p = (LinkList)malloc(sizeof(Node));
	for(int i = 0; i < pos; i++ )
	{
		q = r;
		r = r->next;
	}
	p->data = item;
	q->next = p;
	p->next = r;

}

//insert an item in an ordered list
void INSERTLINKODR(LinkList &list,ElementType item)
{
	LinkList p,r = list;
	p =(LinkList)malloc(sizeof(Node));
	while( r->data > item)
	{
		r = r->next;
	}
	p->data = item;
	r->next = p;
	p->next = r->next->next;
	
}

//delete linklist q the prevoius node is known
void DELLINKLIST(LinkList &list,LinkList q)
{
	LinkList p,r=list;
	//while(*p q)
	if(p==list)
	list = p->next;
	else
	r->next = q->next;
	free(q);
	

}
//delete list
void DELLIST(LinkList &list)
{
	LinkList r=list;
	while(r!=NULL)
	{
		list = r ->next;
		free(r);
		r = list;
	}


}
//delete the data == item
void DELITEM(LinkList &list, ElementType data)
{
	LinkList r=list;
	LinkList p = list; 
	while(r->next != NULL)
	{
		p = r;
		r = r->next;
		if(r->data == data)
		{
			p->next = r->next;
			free(r);
		}
	}
	
}

//invert the list
void INVERT(LinkList &list)
{
	LinkList  
		p = list,
		q=NULL,
		r=NULL;
	while(p !=NULL)
	{
		//q = p->next;
		//r = q->next;
		//q->next = p;
		//p = p->next;
		//std::cout << q << std::endl;
		r = q;
		q = p;
		p = p ->next;
		q->next = r;
		//std::cout<<p->data<<std::endl;
	}
	list =q;
	LinkList x=list;
	while(x->next !=NULL)
	{
		std::cout << x->data << std::endl;
		x=x->next;
	}
}
//
LinkList  CONNECT(LinkList &lista,LinkList listb)
{
	LinkList r, p;
	p = lista;
	while(lista != NULL)
	{
		p = p->next;
	}
	p->next = listb;
	return lista;
}

//merge the two order list in order
LinkList MERGELIST(LinkList lista,LinkList listb)
{

	LinkList listc, p = lista, q = listb, r;
	if (lista->data <= listb->data)
	{
		listc =lista;
		r = lista;
		p =lista->next;
	} 
	else
	{
		listc = listb;
		r = listb;
		q= listb->next;

	}
	while (p != NULL && q !=NULL)
	{
		if ( p->data <= q->data)
		{
			r->next = p; // r next pointer to the p
			r = p;  //r moves next
			p = p->next;
		} 
		else
		{
			r->next = q; //r next pointer to the q
			r = q; // r move next
			q= q->next;
		}
		r->next = p? p:q;
	}
	
	return listc;
}
//copy the list recursive version
LinkList COPY(LinkList lista)
{
	LinkList listb;
	if ( lista == NULL)
	{
		return NULL;
	} 
	else
	{
		listb = (LinkList) malloc(sizeof(Node));
		listb->data = lista->data;
		listb->next= COPY(lista->next);
	}
	return listb;
}
// while version
LinkList COPY2(LinkList lista)
{
	LinkList listb;
	if ( lista == NULL)
	{
		return NULL;
	} 
	else
	{
		while (lista)
		{
			listb = (LinkList)malloc(sizeof(Node));
			listb->data =lista->data;
			lista = lista->next;
		}

	}
	return listb;
}
//
void LINKSORT(ElementType A[],int n)
{
	LinkList p,list = NULL;
	int i;
	for ( i=0; i < n; i++)
	{
		INSERTLINKODR(list,A[i]);
	}
	p = list;
	i =0;
	while(p !=NULL)
	{
		A[i++]=p->data;
		p = p->next;
	
	}
}

void printlist(LinkList list)
{
		LinkList x=list;
	
		do
		{
			std::cout << x->data << std::endl;
			x=x->next;
		}
		while(x !=NULL);
	
}
#endif