#include<iostream>
#include<string>
using namespace std;

     struct node{
	     int data;
	    struct node *next;
      };
     typedef struct node NODE;
     struct list{
     	NODE *pHead;
     	NODE *pTail;
	
      };
      typedef struct list LIST;
      void Init(LIST &l){
      	l.pHead = NULL;
      	l.pTail = NULL;
	  }
	  NODE *InitNODE(int x)
	  {
	  	
	  	NODE *p = new NODE;
	  	if(p == NULL)
	  	{
	  		cout <<"khong du bo nho cap phat.";
		  }
	  	p->next = NULL;
	  	p->data = x;
	  	return p;
	  }
	  void addHeadNode(LIST &l , NODE *p )
      {
      	if(l.pHead == NULL)
      	{
      		l.pHead = l.pTail = p;
		  }
      	else
      	{
      		p->next = l.pHead;
      		l.pHead = p;
		  }
	
	  }	  	
	  void addTailNode(LIST &l , NODE *p)
	  {
	  	if(l.pHead  == NULL)
	  	{
	  		l.pHead = l.pTail = p;
		  }
		  else 
		  {
		  	l.pTail->next = p;
		  	l.pTail = p;
		  }
	  }
	  void Xuat(LIST l)
	     
	  {
	  	 cout<<"\n\n\t LINK LIST \n\n ";
	  	for(NODE *k = l.pHead ; k != NULL ; k = k->next )
	  	{
	  		
	  		cout << k->data << "\t";
	  		
		  }
		  cout<<"\n";
	  }
	  
int main(){
	LIST l ;
	Init(l);
	int n ;
	int sw;
	cout <<" Nhap so luong NODE can them : ";
	cin >> n;
	for(int i = 0; i < n ; i++)
	{
		int x ;
		cout <<"Nhap gia tri so nguyen : ";
		cin >> x;
		NODE *p  = InitNODE(x);
		addTailNode(l,p);
		
	}
	
	do{
		system("cls");
		cout<<"1.Them NODE vao dau"<<"\n";
		cout<<"2.Them NODE vao cuoi"<<"\n";
		cout<<"3.Xuat LinkList"<<"\n";
		cout<<"4.Thoat"<<"\n";
		cout<<"\n";
		cout<<"chon phuong thuc can su dung"<<"\n";
		cin >> sw;
		switch(sw){
			case 1: {
					int x ;
		cout <<"Nhap gia tri so nguyen : ";
		cin >> x;
		NODE *p  = InitNODE(x);
		addHeadNode(l,p);
		
				break;
			}
			case 2:{
					int x ;
		cout <<"Nhap gia tri so nguyen : ";
		cin >> x;
		NODE *p  = InitNODE(x);
		addTailNode(l,p);
		
				break;
			}
			case 3: {
				Xuat(l);
				system("pause");
				break;
			}
		}
	}while(sw != 4);
	

system("pause");
	
return 0;
}

