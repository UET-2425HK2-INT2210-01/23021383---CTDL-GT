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

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0) {  
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < p-1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) return; 

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove(int p) {
        if (head == NULL) return;

        if (p == 0) {
            head = head->next;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < p - 1 && temp->next != NULL; i++)
            temp = temp->next;

        if (temp->next == NULL) return;

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;
    for (int i = 0;i < n;i++) {
        string op;
        int p, x;
        cin >> op >> p;
        if (op == "insert") {
            cin >> x;
            list.insert(p, x);
        }
        else if (op == "delete") {
            list.remove(p);
        }
    }
    list.printList();
    return 0;
}
