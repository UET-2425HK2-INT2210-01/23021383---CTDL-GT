#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int _data, Node* _next){
        data = _data;
        next = _next;
    }
    
};

class LinkedList {
    public:
    Node* head;
    int length = 0;

    LinkedList() { 
        head = nullptr;
        length = 0;
    }

    void insertBeginning(int value){
        if(head == nullptr) {
            Node* newNode = new Node(value, nullptr);
            head= newNode;
            length++;
            return;
        }
        
        Node* newNode = new Node(value, head);
        head = newNode;
        length++;
        return;
    }

    void insertEnd(int value){
        if( head == nullptr) {
            Node* newNode = new Node(value, nullptr);
            head = newNode;
            length++;
            return;
        }

        Node * temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        Node* newNode = new Node(value, nullptr);
        temp -> next = newNode;
        length++;
        return;
    }

    void insert(int position, int value){
        if(position < 0 || position > length) return;
        if(position == 0) {
            insertBeginning(value);
            return;
        } 
        if(position == length) {
            insertEnd(value);
            return;
        }

        Node* temp = head;
        for(int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node(value, temp->next);
        temp->next = newNode;
        length++;
    }

    void deleteBeginning(){
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void deleteEnd(){
        if(head == nullptr) return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            length--;
            return;
        }
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        length--;
    }

    void deleteAt(int position){
        if(position < 0 || position >= length) return;
        if(position == 0) {
            deleteBeginning();
            return;
        }
        if(position == length - 1) {
            deleteEnd();
            return;
        }
        Node* temp = head;
        for(int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        length--;
    }

    void print(){
        Node * temp = head;
        while(temp != nullptr) {
            cout << temp -> data << " ";
            temp = temp->next;
        }
        return;
    }
};

class Stack{
    LinkedList list;
    public:

    void pop() {
        list.deleteBeginning();
    }

    void push(int x) {
        list.insertBeginning(x);
    }

    void print() {
        printReversed(list.head); // do thu tu cua stack nguoc voi linked list.
        cout << endl;
    }

    void printReversed(Node * node) {
        if (node == nullptr) return;
        printReversed(node->next);
        cout << node->data << " ";
    }

    
};

int main() {
    int n;
    cin >> n;

    Stack s;

    while( n-- ){
        string command;
        cin >> command;

        if(command =="push") {
            int p;
            cin >> p;
            s.push(p);
        }

        else if(command == "pop") {
            s.pop();
        }
        
    }


    s.print();
    return 0;


}

/*
    void push(value)
    create newNode(value)
    head <- newNode 
    size <- size + 1 o(1)


    void pop()
    if head = null 
    return

    temp = head
    head = head.next
    delete temp
    size += 1 o(1)

    print
     IF NODE = NULL THEN
                RETURN
            END IF
            PrintReversed(NODE.NEXT)
            PRINT NODE.DATA O(n) su dung de quy



*/
