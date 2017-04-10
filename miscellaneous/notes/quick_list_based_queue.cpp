#include<iostream>

using namespace std;

struct Node {
  int Data;
  Node* Next;
};

class Queue {
  private:
  Node *Head;
  Node* Tail;
  public:
  Queue(){
    Head = Tail = NULL;
  }
  
  void Push(int val){
    Node* Temp = new Node;
    Temp->Data = val;
    Temp->Next = NULL;
    
    if(Empty())
      Head = Tail = Temp;
    else {
      Tail->Next = Temp;
      Tail = Temp;
    }
  }
  
  bool Empty() {
    return Head == NULL;
  }
  
  int Pop(){
    int Temp = Head->Data;
    Node* TempNode = Head;
    Head = Head->Next;
    delete TempNode;
    return Temp;
  }
  
  void Print(){
    Node * Temp = Head;
    while(Temp){
      cout << Temp->Data << "->";
      Temp = Temp->Next;
    }
    cout << endl;
  }
  
};

int main(){
  
  Queue Q;
  
  Q.Push(5);
  Q.Push(9);
  Q.Push(5);
  Q.Push(9);
  
  Q.Print();
  
  cout << Q.Pop() << endl;
  
  Q.Print();
  
  return 0;
}