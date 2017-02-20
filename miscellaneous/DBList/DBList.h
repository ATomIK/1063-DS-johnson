#include <iostream>

struct Node {
	int Data;
	Node *Prev;
	Node *Next;
};

class DBList {
private:
	Node *Head;
	Node *Tail;
	Node* _CreateNode(int);
public:
	DBList();
	bool InsertFront(int);
	bool InsertRear(int);
	bool InsertInOrder(int);
	bool Delete(int);   //Removes item from list
	Node* Find(int);     //Locate and see if exists
	bool Update(int, int);   //Change existing value
	void Print();
};
