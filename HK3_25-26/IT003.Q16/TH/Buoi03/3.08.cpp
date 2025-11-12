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
bool  IsEqual(const Point3D &, const Point3D &);
void  RemoveList(LinkedList &);
int   Search(const LinkedList &, Point3D);

void
run(void)
{
	LinkedList List;
	Node *p;
	Point3D tmp;
	int m, n, Pos;

	cin >> n;

	CreateList(List);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp.XPos >> tmp.YPos >> tmp.ZPos;
		p = CreateNode(tmp);
		AddTail(List, p);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp.XPos >> tmp.YPos >> tmp.ZPos;
		Pos = Search(List, tmp);
		if (Pos == -1)
			cout << "KHONG\n";
		else
			cout << Pos << "\n";
	}
	RemoveList(List);
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

void
AddTail(LinkedList &List, Node *p)
{
	if (List.pHead == NULL)
		List.pHead = p;
	else
		List.pTail->pNext = p;
	List.pTail = p;
}

bool
IsEqual(const Point3D& A, const Point3D& B)
{
	return (A.XPos == B.XPos && A.YPos == B.YPos && A.ZPos == B.ZPos);
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

int
Search(const LinkedList &List, Point3D Target)
{
	Node *p = List.pHead;
	for (int i = 0; p != NULL; i++)
	{
		if (IsEqual(p->Info, Target))
			return i;
		p = p->pNext;
	}
	return -1;
}

int
main(void)
{
	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}
