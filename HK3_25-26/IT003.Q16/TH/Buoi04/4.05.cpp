/* mẫu */
#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

void Output(List ds) {
    Node *p = ds.head;
    if (p == NULL) {
        cout << "EMPTY";
    }
    while(p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}
/* !mẫu */

double DiemTrungBinh(Hocsinh);
Node *CreateNode(Hocsinh);
void CreateList(List &);
void AddTail(List &, Hocsinh);

int
main(void)
{
	List ds;
	Hocsinh tmp;
	int n;
	CreateList(ds);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		InputElement(tmp);
		if (DiemTrungBinh(tmp) >= 9.0f)
			AddTail(ds, tmp);
	}
	Output(ds);
	return 0;
}

double
DiemTrungBinh(Hocsinh hs)
{
	return (hs.Toan + hs.Ly + hs.Hoa + hs.Van + hs.Sinh + hs.Anh) / 6;
}

Node
*CreateNode(Hocsinh hs)
{
	Node *p = new Node;
	p->data = hs;
	p->next = NULL;
	return p;
}

void
CreateList(List &ds)
{
	ds.head = NULL;
	ds.tail = NULL;
}

void
AddTail(List &ds, Hocsinh hs)
{
	Node *p = CreateNode(hs);
	if (ds.head == NULL)
		ds.head = p;
	else
		ds.tail->next = p;
	ds.tail = p;
}
