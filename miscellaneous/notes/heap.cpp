#include<iostream>

using namespace std;

class Heap {
private:
	int *H;
	int Next;
	int MaxSize;
	int CurrSize;

	int Parent(int);
	int Left(int);
	int Right(int);
	void Swap(int, int);

	int PickChild(int);
public:
	Heap(int);
	void Insert(int);
	int Remove();
	void BubbleUp(int);
	void BubbleDown(int);
	void PrintHeap();
};

Heap::Heap(int size) {

	H = new int[size];
	Next = 1;
	MaxSize = size;
	CurrSize = 0;

}

void Heap::Insert(int x) {
	H[Next] = x;
	//BubbleUp(Next);
	BubbleDown(Next);
	Next++;
	CurrSize++;
}

void Heap::Swap(int i, int p) {
	int temp = H[i];
	H[i] = H[p];
	H[p] = temp;
}

void Heap::BubbleUp(int i) {
	unsigned p = Parent(i);
	while (H[i] < H[p]) {
		Swap(i, p);
		i = p;
		p = Parent(i);
	}
}

void Heap::BubbleDown(int i) {
	while (1) {
		int larger = ( H[Left(i)] >= H[Right(i)] ? Left(i) : Right(i) );

		if (H[larger] > H[i]) {
			Swap(larger, i);
			i = larger;
		}
		break;
	}
}

// reutrns index to swap with or -1 for no swap
int Heap::PickChild(int i) {
	return 0;
}

int Heap::Parent(int i) {
	return int(i / 2);
}

int Heap::Left(int i) {
	return i * 2;
}

int Heap::Right(int i) {
	return i * 2 + 1;
}

int Heap::Remove() {
	int temp = H[1];
	H[1] = H[--Next];
	BubbleDown(1);
	return H[1];
}

void Heap::PrintHeap() {
	for (int i = 1; i < Next; i++) {
		cout << H[i] << " ";
	}
	cout << endl;
}


int main() {
	int a[] = {8,4,3,12,9,11,5,2,10};

	int size = sizeof(a) / 4;

	Heap myHeap(size);

	for (int i = 0; i < size; i++) {
		myHeap.Insert(a[i]);
	}

	myHeap.PrintHeap();
	return 0;
}