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
		// traverse through to insert in order

	}
	return true;
}

bool DBList::Delete(int x) {
	if(Head == Tail && Head->Data==x){
		delete Head;
		Head = NULL;
		Tail = NULL;
		return true;
	} else if(Head->Data == x){
		Head = Head->Next;
		delete Head->Prev;
		Head->Prev = NULL;
		return true;
	} else if($Tail->Data == x){
		Tail = Tail->Prev;
		delete Tail->Next;
		Tail->Next = NULL;
		return true;
	} else {
		Node* Location = DBList::Find(x);
		if(!Location)
			return false;
		Location->Prev->Next = Location->Next;
		Location->Next->Prev = Location->Prev;
		delete Location;
	}
}

Node* DBList::Find(int x) {
	//recurse through our current list
	Node* CurPtr = Head;
	while (CurPtr) {
		if (CurPtr->Data == x)
			return CurPtr;
		else
			return false;

		CurPtr = CurPtr->Next;
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


