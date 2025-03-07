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

/*
    enqueue:
    create newNode data = value and next = null
    if queue is empty:
        head = tail =newnode
    
    else tail.next = newNode 
    tail = newNode 

    length ++

    Complexity: O(1)


    dequeue:
    IF queue is empty:
        return
    temp = head
    head = head.next
    if head is NULL:
        tail = NULL   
    DELETE temp
    length --

    complexity: O(1)

    print:
    emp = head
    while temp is not null:
        print temp.data
        temp = temp.next

    complexity:  O(n)
*/

class Queue{
    LinkedList list;
    public:

    void dequeue() {
        list.deleteBeginning();
    }

    void enqueue(int x) {
        list.insertEnd(x);
    }

    void print() {
        list.print();
    }

    
};
