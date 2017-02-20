#include <iostream>
#include "DBList.h"

using namespace std;

int main() {
	srand(93487);
	DBList List;

	for (int i = 0; i<10; i++) {
		List.InsertFront(i);
	}

	List.Print();

	cout << endl;

	cout << List.Find(4)->Next->Data;

	cout << endl;

}
