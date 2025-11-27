/* mẫu */
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(int x) {
    Node *p = new Node;
    if (p == NULL) exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}
/* !mẫu */

void
PrintList(const List &l)
{
	Node *p = l.head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int
main(void)
{
	List l;
	int n, tmp;
	cin >> n;

	CreateList(l);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp % 2 == 0)
			AddHead(l, tmp);
	}
	PrintList(l);
	return 0;
}
