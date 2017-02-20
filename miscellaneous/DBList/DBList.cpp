#include <iostream>
#include "DBList.h"

using namespace std;

//Public 
////////////////////////////////////////////

DBList::DBList() {
	Head = NULL;
	Tail = NULL;
}


bool DBList::InsertFront(int Data) {
	Node* Temp = _CreateNode(Data);
	if (!Head) {
		Head = Temp;
		Tail = Temp;
	}
	else {
		Temp->Next = Head;
		Head->Prev = Temp;
		Head = Temp;
	}
	return true;
}

bool DBList::InsertRear(int Data) {
	if (!Head) {
		DBList::InsertFront(Data);
	}
	else {
		Node* Temp = _CreateNode(Data);
		Tail->Next = Temp;
		Temp->Prev = Tail;
		Tail = Temp;
	}
	return true;
}

bool DBList::InsertInOrder(int Data) {
	if (!Head) {
		DBList::InsertFront(Data);
	}
	else {
		Node* Temp = _CreateNode(Data);
		Node* Exists = DBList::Find(Data);

	}
	return true;
}

bool DBList::Delete(int x) {
	return true;
}

Node* DBList::Find(int x) {
	//recurse through our current list
	Node* CurPtr = Head;
	if (Head) {
		while (CurPtr->Next != NULL) {
			if (CurPtr->Data == x)
				return CurPtr;
			else
				return false;

			CurPtr = CurPtr->Next;
		}
	}
}

bool DBList::Update(int x, int y) {
	return true;
}

void DBList::Print() {
	Node *Temp = Head;
	while (Temp) {
		cout << Temp->Data << " ";
		Temp = Temp->Next;
	}
}

//Private 
////////////////////////////////////////////


Node* DBList::_CreateNode(int data) {
	Node *Temp = new Node;
	Temp->Data = data;
	Temp->Prev = NULL;
	Temp->Next = NULL;
	return Temp;
}


