#include <iostream>
#include <sstream>
using namespace std;

class Node
{
private:
  Node *head;
  Node *next;
  int data;

public:
  Node(){
    data = -1;
  }

  Node(int d)
  {
    next = nullptr;
    head = nullptr;
    data = d;
  }

  bool isEmpty(){
    return data == -1;
  }

  void print(){
    cout << "(";
    cout << "name: " << getNodeName() << " ";
    cout << "data: " << data << " ";
    if (next != nullptr)
      cout << "next: " << next->getNodeName() << " ";
    if (head != nullptr)
      cout << "head: " << head->getNodeName() << " ";
    cout << ")" <<endl;
  }

  Node* getHeadNode() {
    if (head == nullptr) {
      head = this;
    }
    return head;
  }

  Node* getNextNode() {
    return next;
  }

  string getNodeName(){
    ostringstream oss;
    oss << "Node " << data ;
    return oss.str();
  }

  void appendToTail(Node *n)
  {
    if (n->isEmpty()) {
      cout << "empty" << endl;
      return;
    }

    if (getNextNode() != nullptr) {
      cout << "move " << getNodeName() << " to " << next->getNodeName() << endl;
      next->appendToTail(n);
    } else {
      next = n;
      next->head = getHeadNode();
      cout << next->getNodeName() << " appending to " << getNodeName() << endl;
    }

    return;
  }

  int getData(){
    return this->data;
  }

};

Node node;

void input()
{
  int n = 0;

  cin >> n;

  for (int i = 0 ; i < n ; i++) {
    int val = i + 1;
    Node* newNode = new Node(val);

    if (i == 0)
      node = *newNode;
    else
      node.appendToTail(newNode);

    cout << "newNode ";
    newNode->print();
  }
}

void output()
{
  Node* currentNode = node.getHeadNode();
  while (currentNode != nullptr){
    currentNode->print();
    Node* nextNode = currentNode->getNextNode();
    currentNode = nextNode;
  }
}

int main()
{
  input();
  cout << "Finished appending" << endl;

  output();
  return 0;
}
