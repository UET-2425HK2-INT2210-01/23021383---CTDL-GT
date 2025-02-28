#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int n) {
        data = n;
        next = NULL;
    }
};

class Stack {
public:
    Node* top;
    
    Stack() : top(NULL) {}
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void print(Node* node) {
        if (!node) return;
        print(node->next);
        cout << node->data << " ";
    }
    
    void print() {
        print(top);
    }
};

int main() {
    int n;
    cin >> n;
    
    Stack s;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (operation == "pop") {
            s.pop();
        }
    }
    
    s.print();
    
    return 0;
}
