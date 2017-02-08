/**
* @ProgramName: Homework 1 - Tail Insertion
* @Author: Thomas Johnson
* @Description:
*     This program inserts data into a list from the
*	  beginning of the list and the end.
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

	/**
	* @FunctionName: FrontSert
	* @Description:
	*     Inserts x at the beginning of the list and
	*	  reassigns head to the first node.
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
	void FrontSert(int x) {
		Node *newData = new Node;
		newData->Data = x;
		newData->Next = NULL;

		

		if (Head) {
			newData->Next = Head;
		}

		Head = newData;
		
		// traverse through our data, if the next
		// is null, that's our end
		Node *Temp = Head;
		while (Temp != NULL) {
			if (Temp->Next == NULL) {
				Tail = Temp;
			}
			Temp = Temp->Next;
		}

	}

	/**
	* @FunctionName: EndSert
	* @Description:
	*     Inserts x at the end of the list and reassigns
	*	  tail to the last node.
	* @Params:
	*    int x - integer value
	* @Returns:
	*    void
	*/
	void EndSert(int x) {
		Node *newData = new Node;
		newData->Data = x;
		newData->Next = NULL;

		Tail->Next = newData;
		Tail = Tail->Next;
	}

	/**
	* @FunctionName: PrintList
	* @Description:
	*     Traverses through our list and cout's them.
	* @Params:
	*    none
	* @Returns:
	*    void
	*/
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
		}
	}

};


int main() {
	srand(97097807);
	List L;
	for (int i = 0; i<10; i++) {
		L.FrontSert(rand() % 100);
	}

	L.EndSert(50);
	L.EndSert(70);

	L.PrintList();


	return 0;
}
