/* mẫu */
#include <iostream>
#include <stack>

#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int num;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(int x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->num = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node * p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node *p = l.head;
    while (p != NULL) {
        cout << p->num << ' ';
        p = p->next;
    }
}
void Sum(List, List, List &);

int main()
{
    List a, b, c;
    CreateList(a);
    CreateList(b);
    CreateList(c);
    int m, n, k;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        AddTail(a, k);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        AddTail(b, k);
    }

    Sum(a, b, c);
    PrintList(c);
    return 0;
}

void Sum(List a, List b, List &c) {
/* !mẫu */
	Node *prev = NULL;
	Node *cur = a.head;
	Node *next = NULL;

	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	Node *ptrA = prev;

	prev = NULL;
	cur = b.head;
	next = NULL;

	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	Node *ptrB = prev;

	int nho = 0, tmp;

	while (ptrA != NULL || ptrB != NULL || nho != 0) {
		tmp = (ptrA ? ptrA->num : 0) + (ptrB ? ptrB-> num : 0) + nho;
		AddHead(c, tmp % 10);
		nho = tmp / 10;

		if (ptrA != NULL)
			ptrA = ptrA->next;
		if (ptrB != NULL)
			ptrB = ptrB->next;
	}
/* mẫu */
}
/* !mẫu */
