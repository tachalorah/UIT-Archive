#include <iostream>
#include <cmath>

using namespace std;

struct Point3D
{
	float XPos;
	float YPos;
	float ZPos;
};

typedef struct tagNode
{
	Point3D Info;
	struct tagNode *pNext;
} Node;

struct LinkedList
{
	Node *pHead;
	Node *pTail;
};

void  AddTail(LinkedList &, Node *);
void  CreateList(LinkedList &);
Node *CreateNode(const Point3D &);
float KhoangCach(const Point3D &);
void  PrintList(const LinkedList &);
void  RemoveList(LinkedList &);

int
main(void)
{
	LinkedList L1, L2;
	Node *p, *q;
	Point3D x;
	float tmp, Begin, End;
	int n;

	cin >> n;

	CreateList(L1);

	for (int i = 0; i < n; i++)
	{
		cin >> x.XPos >> x.YPos >> x.ZPos;
		p = CreateNode(x);
		AddTail(L1, p);
	}

	cin >> Begin >> End;

	CreateList(L2);
	p = L1.pHead;

	while (p != NULL)
	{
		tmp = KhoangCach(p->Info);
		if (tmp <= End && tmp >= Begin)
		{
			q = CreateNode(p->Info);
			AddTail(L2, q);
		}
		p = p->pNext;
	}

	if (L2.pHead != NULL)
		PrintList(L2);
	else
		cout << "KHONG\n";
	RemoveList(L1);
	RemoveList(L2);
	return 0;
}

void
CreateList(LinkedList &List)
{
	List.pHead = NULL;
	List.pTail = NULL;
}

Node
*CreateNode(const Point3D &Point)
{
	Node *p = new Node;
	p->Info = Point;
	p->pNext = NULL;
	return p;
}

float
KhoangCach(const Point3D &Point)
{
	return sqrtf(Point.XPos * Point.XPos + Point.YPos * Point.YPos +
		     Point.ZPos * Point.ZPos);
}

void
PrintList(const LinkedList &List)
{
	Node *p = List.pHead;
	while (p != NULL)
	{
		cout << p->Info.XPos << " " << p->Info.YPos << " " <<
		        p->Info.ZPos << "\n";
		p = p->pNext;
	}
}

void
AddTail(LinkedList &List, Node *p)
{
	if (List.pHead == NULL)
		List.pHead = p;
	else
		List.pTail->pNext = p;
	List.pTail = p;
}

void
RemoveList(LinkedList &List)
{
	Node *p;
	while (List.pHead != NULL)
	{
		p = List.pHead;
		List.pHead = p->pNext;
		delete p;
	}
}

