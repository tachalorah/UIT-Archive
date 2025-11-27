#include <iostream>

using namespace std;

struct Node {
	int num;
	Node *next;
};

struct List {
	Node *head;
	Node *tail;
};

void CreateList(List &);
Node *CreateNode(int);
void AddHead(List &, int);
void PrintList(const List &);

int
main(void)
{
	List a;
	int n, tmp, count = 0;
	cin >> n;
	CreateList(a);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp >= 90 && count < 10)
		{
			AddHead(a, tmp);
			count++;
		}
	}

	PrintList(a);
	cout << "END\n";
	return 0;
}

void
CreateList(List &a)
{
	a.head = NULL;
	a.tail = NULL;
}

Node
*CreateNode(int n)
{
	Node *p = new Node;
	p->num = n;
	p->next = NULL;
	return p;
}

void
AddHead(List &l, int n)
{
	Node *p = CreateNode(n);
	if (l.head == NULL)
		l.tail = p;
	else
		p->next = l.head;
	l.head = p;
}

void
PrintList(const List &l)
{
	Node *p = l.head;
	while (p != NULL) {
		cout << p->num << " ";
		p = p->next;
	}
}
