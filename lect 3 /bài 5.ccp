#include <iostream>
using namespace std;

class Stack{

    private:
    int* arr = new int[1000];       
    int top = -1;        
    int length = 0;

    public:
    Stack(int size) {
        length = size;
        arr = new int[length];
        top = -1;
    }
    
    void push(int x) {
        if (top == length - 1) {
            return;
        }
        arr[top] = x;
        top++;
    }

    int pop(){
        if (top == -1) {
            return -1;
        }
        return arr[top];
        top--;
    }

    void print() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /*
        push(x) 
        if(top == size - 1)
        return

        top++
        stack[top] = value -> O(1)

        pop:
        if top == -1;
            return;

        value = stack[top];
        top --
        return value -> o(1)

        print:
    if top == -1;
        RETURN
    for i = top  TO 0:
        print stack[i]

        O(n)
    */
    
    
     
};
