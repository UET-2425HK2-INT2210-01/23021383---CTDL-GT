#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

class singleLinkedList{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void print(){
        Node* tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void append(int x){
        Node* newNode = new Node(x);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void search(int x){
        Node* tmp = head;
        int n = 0;
        while(tmp != nullptr){
            if(tmp->data == x){
                cout << n << endl;
                return;
            }
            tmp = tmp->next;
            n++;
        }
        cout << "No" << endl;
    }

    void reverse(){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main(){
    int n;
    cin >> n;
    string operat;
    int x;
    singleLinkedList List;
    for(int i = 0; i < n; i++){
        cin >> operat;
        if(operat == "append"){
            cin >> x;
            List.append(x);
        }
        if(operat == "search"){
            cin >> x;
            List.search(x);
        }
        if(operat == "reverse"){
            List.reverse();
            List.print();
        }
    }
    return 0;
}
