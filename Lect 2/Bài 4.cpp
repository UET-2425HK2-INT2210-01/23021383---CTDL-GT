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

class Queue {
    Node* front;
    Node* rear;

public:
    Queue(){
    	front = NULL;
    	rear = NULL;
	}

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (!front) rear = NULL;
    }

    void printQueue() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Queue q;
    
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (op == "dequeue") {
            q.dequeue();
        }
    }
    q.printQueue();
    return 0;
}
