#include<iostream>
using namespace std;

struct Node{
    char data;
    Node* prev;
    Node(char c){
        data = c;
        prev= nullptr;
    }
};

class Stack{
public:
    Node* head = nullptr;
    int n = 0;

    void insert(char c){
        Node* newNode = new Node(c);
        if(head == nullptr){
            head = newNode;
            n++;
        }else{
            newNode->prev = head;
            head = newNode;
            n++;
        }
    }

    void isValid(){
        if(n > 1){
            Node* tmp = head;
            if( (tmp->data == ')' && (tmp->prev)->data == '(') || (tmp->data == '}' && (tmp->prev)->data == '{') || (tmp->data == ']' && (tmp->prev)->data == '[') ){
            head = (tmp->prev)->prev;
            delete tmp->prev;
            delete tmp;
            n -= 2;
            }
        }

    }
};

int main(){
    char c;
    Stack myStack;
    while( (c = getchar()) != '\n'){
        myStack.insert(c);
        myStack.isValid();
    }

    if( myStack.head == nullptr ){
        cout << "Valid";
    }else{
        cout << "Invalid";
    }

    return 0;
}
