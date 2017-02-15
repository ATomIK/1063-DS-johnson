/**
* @ProgramName: Homework 1 - Tail Insertion
* @Author: Thomas Johnson
* @Description:
*     This program inserts data to the end of a list.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 08 02 2017
*/

#include <iostream>

struct Node {
	int Data;
	Node *Next;
};

using namespace std;

class List {
private:
	Node *Head;
	Node *Tail;
public:
	List() {
		Head = NULL;
	}

	void FrontSert(int x) {
		Node *Temp = new Node;
		Temp->Data = x;
		Temp->Next = NULL;

		if (Head) {
			Temp->Next = Head;
		}

		Head = Temp;

	}

	/**
	* @FunctionName: TailSert
	* @Description:
	*     Inserts x at the end of the list.
	* @Params:
	*    int x - integer value
	* @Returns:
	*    void
	*/
	void TailSert(int x) {
		Node *Temp = Head;

		while (Temp != NULL) {
			cout << Temp->Data << "->";
			Temp = Temp->Next;
		}
	}

	void PrintList() {
		if (!Head) {
			cout << "Empty" << endl;
			return;
		}
		else {
			Node *Temp = Head;
			while (Temp != NULL) {
				cout << Temp->Data << "->";
				Temp = Temp->Next;
			}
			cout << Temp2->Data << endl;
		}
	}

};


int main() {
	srand(97097807);
	List L;
	for (int i = 0; i<10; i++) {
		L.FrontSert(rand() % 100);
	}
	L.PrintList();


	return 0;
}
