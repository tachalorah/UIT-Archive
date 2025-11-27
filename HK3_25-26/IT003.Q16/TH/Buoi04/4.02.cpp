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

Node * CreateNode(Hocsinh x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node * p = l.head;
    while (p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

void Sort(List &);

int main()
{
    List l;
    int n;
    Hocsinh hs;

    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        AddTail(l, hs);
    }

    Sort(l);
    PrintList(l);
    return 0;
}
/* mẫu */

bool
Less(const Hocsinh &A, const Hocsinh &B)
{
	if (A.Ten != B.Ten)
		return A.Ten < B.Ten;
	if (A.Hodem != B.Hodem)
		return A.Hodem < B.Hodem;
	if (A.Nam != B.Nam)
		return A.Nam > B.Nam;
	if (A.Thang != B.Thang)
		return A.Thang > B.Thang;
	if (A.Ngay != B.Ngay)
		return A.Ngay > B.Ngay;
	return false;
}

Node
*Split(Node *head)
{
	Node *one = head, *two = head->next;

	while (two != NULL && two->next != NULL) {
		two = two->next->next;
		one = one->next;
	}

	Node *temp = one->next;
	one->next = NULL;
	return temp;
}

Node
*Merge(Node *one, Node *two)
{
	if (one == NULL)
		return two;
	if (two == NULL)
		return one;

	if (Less(one->data, two->data) == true) {
		one->next = Merge(one->next, two);
		return one;
	} else {
		two->next = Merge(one, two->next);
		return two;
	}
}

Node
*MergeSort(Node *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node *two = Split(head);
	head = MergeSort(head);
	two = MergeSort(two);
	return Merge(head, two);
}

void
Sort(List &list)
{
	list.head = MergeSort(list.head);

	Node *p = list.head;

	if (p == NULL) {
		list.tail = NULL;
		return;
	}

	while (p->next != NULL)
		p = p->next;
	list.tail = p;
}
