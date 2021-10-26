#include<iostream>
using namespace std;

class NODE{
public:
	int Data;
	NODE *pNext;
};
class LIST{
private:
	NODE *pHead;
public:
	LIST(){
		pHead = NULL;
	}
	NODE* InitNODE(int x)
	{

		NODE *p = new NODE;
		if (p == NULL)
		{
			cout << "khong du bo nho cap phat.";
		}
		p->pNext = NULL;
		p->Data = x;
		return p;
	}
	void swap(int &a, int &b){

		int tmp = a;
		a = b;
		b = tmp;
	}
	void addNode(NODE *p){
		if (pHead == NULL){
			pHead = p;
			pHead->pNext = pHead;
		}
		else{
			if (pHead->pNext == pHead){
				pHead->pNext = p;
				p->pNext = pHead;
			} else{
				NODE *k = pHead;
				while (k->pNext != pHead){
					k = k->pNext;
				}
				p->pNext = k->pNext;
				k->pNext = p;
			}
		}
	}
	void addHead(NODE *p){
		if (pHead == NULL){
			pHead = p;
			p->pNext = pHead;
		}
		NODE *k = pHead;
		while (k->pNext != pHead){
			k = k->pNext;
		}
		p->pNext = k->pNext;
		k->pNext = p;
		pHead = p;
	}	
	void Nhap(){
		int n;
		cout << "nhap so phan tu:";
		cin >> n;
		for (int i = 0; i < n; i++){
			int x;
			cout << "phan tu " << i + 1 << ":";
			cin >> x;
			NODE *p = InitNODE(x);
			addNode(p);
		}
	}
	void ChenDau(){
		int n;
		cout << "nhap so phan tu:";
		cin >> n;
		NODE *p = InitNODE(n);
		addHead(p);
	}
	void ChenViTri(NODE *p){
		int pos;
		int count = 2;
		cout << "Nhap vi tri can chen:";
		cin >> pos;
		if (pHead == NULL || pos == 1){
			addHead(p);
		}
		else{
			NODE *k = pHead;
			while (k->pNext != pHead && count != pos){
				k = k->pNext;
				count++;
			}
			if (count != pos)
				addNode(p);
			else{
				p->pNext = k->pNext;
				k->pNext = p;
			}
		}
	}
	void Chen_sau_NODE(NODE *p){
		int x;
		cout << "Nhap gia tri NODE X:";
		cin >> x;
		NODE *k = pHead;
		do{
			if (k->Data == x){
				NODE *h = InitNODE(p->Data);
				NODE *g = k->pNext;
				h->pNext = g;
				k->pNext = h;
			}
			k = k->pNext;
		} while (k != pHead);
	}
	void Xuat(){
		NODE *p;
		p = pHead;
		while (1){
			cout << p->Data << "\t";
			if (p->pNext == pHead){
				break;
			}
			p = p->pNext;
		}
		cout << "\n\n";
		system("pause");
	}
	void  InterchangeSort(){
		for (NODE *temp = pHead; temp->pNext != pHead; temp = temp->pNext){
			for (NODE *temp1 = temp->pNext; temp1 != pHead; temp1 = temp1->pNext){
				if (temp->Data > temp1->Data){
					swap(temp->Data, temp1->Data);
				}
			}
		}

	}
	void BubbleSort(){
		NODE *pTemp = pHead, *pi, *pj;
		for (pi = pHead; pi->pNext != pHead; pi = pi->pNext){
			for (pj = pHead; pj->pNext != pTemp; pj = pj->pNext)
			if (pj->Data > pj->pNext->Data){
				swap(pj->Data, pj->pNext->Data);
			}
			pTemp = pj;
		}
	}
	void SelectionSort(){
		for (NODE* pi = pHead; pi->pNext != pHead; pi = pi->pNext){
			NODE* pMin = pi;
			for (NODE* pj = pi->pNext; pj != pHead; pj = pj->pNext){
				if (pMin->Data > pj->Data){
					pMin = pj;
				}
			}
			swap(pi->Data, pMin->Data);
		}
	}


	void quickSort()
	{
		if (pHead == NULL) return;
		if (pHead->pNext == pHead) return;
		NODE* pivot = pHead;
		LIST l1, l2;
		const NODE* oldHead = pHead;
		pHead = pHead->pNext;
		do
		{
			NODE* current = pHead;
			pHead = pHead->pNext;
			if (current->Data < pivot->Data) l1.addHead(current);
			else l2.addHead(current);

		} while (pHead != oldHead);

		l1.quickSort();
		l2.quickSort();

		if (l1.pHead != NULL)
		{
			pHead = l1.pHead;
			l1.pTail()->pNext = pivot;
		}
		else pHead = pivot;

		if (l2.pHead != NULL)
		{
			pivot->pNext = l2.pHead;
			l2.pTail()->pNext = pHead;
		}
		else pivot->pNext = pHead;
	}
	NODE* pTail()
	{
		if (pHead != NULL)
		{
			NODE* temp = pHead;
			while (temp->pNext != pHead) temp = temp->pNext;
			return temp;
		}
		return NULL;
	}
	void XoaDau(){
		NODE *k = pHead;
		while (k->pNext != pHead){
			k = k->pNext;
		}
		k->pNext = pHead->pNext;
		pHead = pHead->pNext;
	}
	void XoaNode_Vitri(){
		int pos, count;
		count = 1;
		cout << "Nhap vi tri can xoa : ";
		cin >> pos;
		for (NODE *k = pHead; k->pNext != pHead; k = k->pNext){
			count++;
			if (pos == count){
				k->pNext = k->pNext->pNext;
			}
		}
	}
	void XoaNode_Giatri(){
		int x;
		cout << "nhap gia tri can xoa:";
		cin >> x;
		while (pHead->Data == x){
			XoaDau();
		}
		NODE *g = new NODE();
		NODE *k = pHead;
		do{
			if (k->Data == x){
				g->pNext = k->pNext;
				delete k;
				k = g;
			}
			g = k;
			k = k->pNext;
		} while (k != pHead);
	}

	void TimMax(){
		int  pos ,count= 1;
		int max = pHead->Data;
		NODE *k = pHead;
		do{
			count++;
			k = k->pNext;
			if (k->Data > max){
				max = k->Data;
				pos = count;
			}
		} while (k != pHead);
		cout << "Gia tri lon nhat la:" << max << " tai vi tri thu " << pos;
		cout << "\n";
		system("pause");
	}

	void TimMin(){
		int  pos=1, count = 1;
		int min = pHead->Data;
		NODE *k = pHead;
		do{
			count++;
			k = k->pNext;
			if (k->Data < min){
				min = k->Data;
				pos = count;
			}
		} while (k != pHead);
		cout << "Gia tri nho nhat la:" << min << " tai vi tri thu " << pos;
		cout << "\n";
		system("pause");
	}

	int TongNODE(){
		int sum = 0;
		NODE *k = pHead;
		do{
			sum++;
			k = k->pNext;
		} while (k != pHead);
		return sum;
	}
	void XoaDS(){
		NODE *p = new NODE();
		NODE *k = pHead;
		while (k->pNext != pHead)
			k = k->pNext;

		while (pHead->pNext!=pHead){
			p = pHead;
			pHead = pHead->pNext;
			k->pNext = pHead;
			delete p;
		}
		pHead = NULL;
	}

	void menu(){
		int chon;
		do{
			system("cls");
			cout << "1.Nhap danh sach\n";
			cout << "2.Xuat danh sach\n";
			cout << "3.Them vao dau danh sach\n";
			cout << "4.Them NODE vao vi tri bat ki\n";
			cout << "5.Xoa NODE vi tri bat ki\n";
			cout << "6.Xoa NODE dau danh sach\n";
			cout << "7.Interchange_Sort\n";
			cout << "8.Quick_Sort\n";
			cout << "9.Tim Max\n";
			cout << "10.Tim Min\n";
			cout << "11.Tong NODE\n";
			cout << "12.Them NODE vao sau NODE X\n";
			cout << "13.Xoa NODE gia tri bat ki\n";
			cout << "14.Xoa danh sach\n";
			cout << "20.Thoat\n";
			cout << "Nhap lua chon:";
			cin >> chon;
			switch (chon){
			case 1:
				Nhap();
				break;
			case 2:
				Xuat();
				break;
			case 3:
				ChenDau();
				break;
			case 4:{
					   int x;
					   cout << "Nhap gia tri can chen: ";
					   cin >> x;
					   NODE *p = InitNODE(x);
					   ChenViTri(p);
					   break;
			}
			case 5:
				XoaNode_Vitri();
				break;
			case 6:
				XoaDau();
				break;
			case 7:
				InterchangeSort();
				break;
			case 8:
				quickSort();
				break;
			case 9:
				TimMax();
				break;
			case 10:
				TimMin();
				break;
			case 11:
				cout << "Tong so NODE trong danh sach:" << TongNODE();
				system("pause");
				break;
			case 12:{
						int x;
						cout << "Nhap gia tri can chen: ";
						cin >> x;
						NODE *p = InitNODE(x);
						Chen_sau_NODE(p);
						break;
			}
			case 13:
				XoaNode_Giatri();
				break;
			case 14:
				XoaDS();
				break;
			case 15:
				BubbleSort();
				break;
			}
		} while (chon != 20);
	}
};

void main(){
	LIST dslk;
	dslk.menu();
}



