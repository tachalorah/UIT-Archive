/* mẫu */
#include <iostream>

using namespace std;
/* !mẫu */

struct Node {
	int pos;
	int num;
	Node *next;
};

struct List {
	Node *head;
	Node *tail;
};

void CreateList(List &);
Node *CreateNode(int, int);
void AddTail(List &, int, int);

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
		if (tmp % 2 == 0) {
			AddTail(a, i, tmp);
			count++;
		}
	}

	if (count == 0)
		return 0;

	int mid = (count - 1) / 2;
	Node *p = a.head;

	for (int k = 0; k < mid; k++)
		p = p->next;

	cout << p->pos + 1 << "\n";
	return 0;
}

void
CreateList(List &a)
{
	a.head = NULL;
	a.tail = NULL;
}

Node
*CreateNode(int pos, int n)
{
	Node *p = new Node;
	p->pos = pos;
	p->num = n;
	p->next = NULL;
	return p;
}

void
AddTail(List &l, int pos, int n)
{
	Node *p = CreateNode(pos, n);
	if (l.tail == NULL)
		l.head = p;
	else
		l.tail->next = p;
	l.tail = p;
}
