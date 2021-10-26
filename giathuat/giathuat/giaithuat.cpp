#include <iostream>

using namespace std;



class NODE
{
public:
	int data;
	NODE* pLeft;
	NODE* pRight;
};

class TREE
{
public:
	NODE* pRoot;

	TREE()
	{
		pRoot = NULL;
	}
	void addNode(int x)
	{/*
44 18 88 13 37 59 108 15 23 40 55 71
*/
		TREE t;
		if (pRoot == NULL) // cay chua co node nao -> cay rong
		{
			NODE* p = new NODE;
			p->pLeft = NULL;
			p->pRight = NULL;
			p->data = x;
			pRoot = p;
		}
		else  // cay da co nut
		{
			if (x < pRoot->data) //them vao cay con trai
			{
				t.pRoot = pRoot->pLeft; // = NULL
				t.addNode(x);
				pRoot->pLeft = t.pRoot;
			}
			else if (x > pRoot->data) // them vao cay con phai
			{
				t.pRoot = pRoot->pRight; // = NULL
				t.addNode(x);
				pRoot->pRight = t.pRoot;
			}
		}
	}
	void nhap() {
		int n;
		cout << "So phan tu = ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cout << "Phan tu " << i << " = ";
			cin >> x;
			addNode(x);
		}
	}
	void xuatNLR() {
		TREE t1, t2;
		if (pRoot != NULL) {
			cout << pRoot->data << "\t"; //node

			t1.pRoot = pRoot->pLeft; //left
			t1.xuatNLR();

			t2.pRoot = pRoot->pRight; //right
			t2.xuatNLR();
		}
	}
	void xuatLNR() { //duyet cay tu nho den lon
		TREE t1, t2;
		if (pRoot != NULL) {
			t1.pRoot = pRoot->pLeft; //left
			t1.xuatLNR();

			cout << pRoot->data << "\t"; //node		

			t2.pRoot = pRoot->pRight; // right
			t2.xuatLNR();
		}
		
	}
	void xuatRNL() { // duyet cay tu lon den nho
		TREE t1, t2;
		if (pRoot != NULL) {
			t2.pRoot = pRoot->pRight; // right
			t2.xuatRNL();

			cout << pRoot->data << "\t"; //node

			t1.pRoot = pRoot->pLeft; //left
			t1.xuatRNL();
		}
	}
	NODE* timKiemX(int x) {
		TREE t;
		if (pRoot != NULL) {
			if (x == pRoot->data) return pRoot;
			
			if (x < pRoot->data) {
				t.pRoot = pRoot->pLeft;
				return t.timKiemX(x);
			}
			else {
				t.pRoot = pRoot->pRight;
				return t.timKiemX(x);
			}
		}
		return NULL;
	}
	void timKiem() {
		int x;
		cout << "\n\nNhap gia tri can tim: ";
		cin >> x;
		NODE* p = timKiemX(x);
		if (p == NULL) cout << "\n\n\nTim khong thay \n\n\n";
		else cout << "\n\n\nTim thay gia tri x: " << p->data;
		cout << "\n\n\n";
		system("pause");
	}
	void xoaCay() {
		TREE t1, t2;
		if (pRoot != NULL) {
			t1.pRoot = pRoot->pLeft;
			t1.xoaCay();

			t2.pRoot = pRoot->pRight;
			t2.xoaCay();

			delete pRoot;
			pRoot = NULL; 
		}
	}
	void timMin() {
		TREE t;
		if (pRoot == NULL) cout << "\n\nCay rong\n\n";
		else {
			if (pRoot->pLeft == NULL)
				cout << "\n\nGia tri min: " << pRoot->data;
			else {
				t.pRoot = pRoot->pLeft; // de quy
				t.timMin();
			}
		}
	}
	void timMax() {
		TREE t;
		if (pRoot == NULL) cout << "\n\nCay rong\n\n";
		else {
			if (pRoot->pRight == NULL)
				cout << "\n\nGia tri max: " << pRoot->data;
			else {
				t.pRoot = pRoot->pRight; // de quy
				t.timMax();
			}
		}
	}
	void timNodeLa() {
		TREE t1, t2;
		if ((pRoot->pLeft == NULL) && (pRoot->pRight == NULL)) { //NODE
			cout << pRoot->data << "\t";
		}
		if (pRoot->pLeft != NULL)
		{
			t1.pRoot = pRoot->pLeft; // LEFT
			t1.timNodeLa();
		}
		if (pRoot->pRight != NULL)
		{
			t2.pRoot = pRoot->pRight; //RIGHT
			t2.timNodeLa();
		}
	}
	void timNode1CayCon() {
		TREE t1, t2;
		if (((pRoot->pLeft == NULL) && (pRoot->pRight != NULL)) || ((pRoot->pLeft!=NULL)&&(pRoot->pRight==NULL))) { //NODE
			cout << pRoot->data << "\t";
		}
		if (pRoot->pLeft != NULL)
		{
			t1.pRoot = pRoot->pLeft; // LEFT
			t1.timNode1CayCon();
		}
		if (pRoot->pRight != NULL)
		{
			t2.pRoot = pRoot->pRight; //RIGHT
			t2.timNode1CayCon();
		}
	}
	void timNode2CayCon() {
		TREE t1, t2;
		if ((pRoot->pLeft != NULL) && (pRoot->pRight != NULL)) { //NODE
			cout << pRoot->data << "\t";
		}
		if (pRoot->pLeft != NULL)
		{
			t1.pRoot = pRoot->pLeft; // LEFT
			t1.timNode2CayCon();
		}
		if (pRoot->pRight != NULL)
		{
			t2.pRoot = pRoot->pRight; //RIGHT
			t2.timNode2CayCon();
		}
	}
	void xoaNode(int x) { // Xét TH nút lá và nút có 1 cây con
		TREE t1, t2;
		if (pRoot != NULL) {
			if (x < pRoot->data) {
				t1.pRoot = pRoot->pLeft; //LEFT	
				t1.xoaNode(x);
				pRoot->pLeft = t1.pRoot; // n?i cây l?i (cho th thay d?i c?u trúc cây)
			}
			else if (x > pRoot->data) {
				t2.pRoot = pRoot->pRight; //RIGHT
				t2.xoaNode(x);
				pRoot->pRight = t2.pRoot;
			}
			else {
				NODE* temp = pRoot;
				if (pRoot->pLeft == NULL)
					pRoot = pRoot->pRight;
				else if (pRoot->pRight == NULL)
					pRoot = pRoot->pLeft;
				else {
					timNodeThe (temp, pRoot->pRight);
				}
				delete temp;
			}
		}
	}
	void timNodeThe(NODE *& x, NODE *&y){
		if (y->pLeft != NULL)
		{
			timNodeThe(x, y->pLeft);
		}
		else 
		{
			x->data = y->data; 
			x = y; 
			y = y->pRight; 
		}
	}

	void xoa() {
		int x;
		cout << "\n\nNhap gia tri can xoa: ";
		cin >> x;
		xoaNode(x);
	}
	void inmenu()
    {
        int chon;
        do
        {
            system("cls");
			cout << "\t\t ============== MENU =============\n\n";
            cout << "\t1- Nhap cay nhi phan\n";
            cout << "\t2- Xuat LNR\n";
            cout << "\t3- Xuat RNL\n";
            cout << "\t4- Xuat NLR\n";
			cout << "\t5- Tim max\n";
            cout << "\t6- Tim min\n";
			cout << "\t7- Tim node LA\n";
			cout << "\t8- Tim node 1 cay con\n";
			cout << "\t9- Tim node 2 cay con\n";
			cout << "\t10- Xoa node bat ki\n";
			cout << "\t11- Xoa cay\n";
			cout << "\t12- Thoat chuong trinh\n\n";
			cout << "\t\t =================================\n";
            cout << "\n\t> Lua chon chuc nang thuc hien: ";
            cin >> chon;
       
            switch (chon)
            {
                case 1: nhap(); break;
                case 2: xuatLNR(); cout << "\n\n\n";
		system("pause"); break;
                case 3: xuatRNL(); cout << "\n\n\n";
		system("pause"); break;
                case 4: xuatNLR(); cout << "\n\n\n";
		system("pause"); break;
				case 5: timMax(); cout << "\n\n\n";
		system("pause"); break;
				case 6: timMin(); cout << "\n\n\n";
		system("pause"); break;
				case 7: timNodeLa(); cout << "\n\n\n";
		system("pause"); break;
				case 8: timNode1CayCon(); cout << "\n\n\n";
		system("pause"); break;
				case 9: timNode2CayCon(); cout << "\n\n\n";
		system("pause"); break;
				case 10: xoa(); break;
				case 11: xoaCay(); break;
            }
        } while (chon != 12);
    }

};
int main() {
	TREE t;
	t.inmenu();
	return 0;
}

