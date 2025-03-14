#include<iostream>
using namespace std;

struct Node{
    int data1, data2;
    Node* next;
    Node* prev;
    Node(int x, int p){
        data1 = x;
        data2 = p;
        next = nullptr;
        prev = nullptr;
    }
};

class doubleLinkedList{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void print(){
        Node* tmp = head;

        while(tmp != nullptr){
            cout << "(" << tmp->data1 << ", " << tmp->data2 << ")";
            tmp = tmp->next;
            if(tmp != nullptr){
                cout << "; ";
            }
        }
        cout << endl;
    }

    void enqueue(int x, int p){
        Node* newNode = new Node(x, p);

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else if(newNode->data2 > head->data2){
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }else if(newNode->data2 < tail->data2){
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }else{
            Node* tmp = head;
            while( !(newNode->data2 < tmp->data2 && newNode->data2 > (tmp->next)->data2) ){
                tmp = tmp->next;
            }
            tmp->next = newNode;
            (tmp->next)->prev = newNode;
            newNode->prev = tmp;
            newNode->next = tmp->next;
        }
    }

    void dequeue(){
        if(head != nullptr){

            Node* tmp = head;
            head = head->next;

            if(head != nullptr){
                head->prev = nullptr;
            }else{
                tail = nullptr;
            }
            delete tmp;
        }
    }

};

int main(){
    int n;
    cin >> n;
    string operat;
    int x, p;
    doubleLinkedList List;
    for(int i = 0; i < n; i++){
        cin >> operat;
        if(operat == "enqueue"){
            cin >> x >> p;
            List.enqueue(x, p);
        }else if(operat == "dequeue"){
            List.dequeue();
        }else{
            cout << "invalid";
        }
    }
    List.print();
    return 0;
}
