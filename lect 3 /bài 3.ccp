#include <iostream>
#define MAX 1000
using namespace std;

class Queue{
    int a[MAX];
    int length = 0;

    public:
    void enqueue(int x) {
        if(length == MAX) {
            return;
        }

        a[length] = x;
        length++;
    } 
    // DO phuc tap O(1);

    void dequeue() {
        if(length == 0) return;

        int x = a[0];

        for(int i = 0; i < length-1;i++){
			a[i] = a[i+1];
		}
		--length ;

    
    } // DO phuc tap O(1);
    void print() {
        for(int i = 0; i < length; i++) {
            cout << a[i] << ' '; 
        }
    }

    //Do phuc tap O(n)
};

/*
    enqueue: 
CREATE newNode with value and next = NULL
    IF queue is empty:
        head = newNode
    ELSE:
        temp = head
        WHILE temp.next is not NULL:
            temp = temp.next
        temp.next = newNode
    length ++


dequeue
 if queue = emty 
   return
temp = head
head=head.next
delete temp
length --

print:
temp = head
while temp  is not NULL:
    print = temp.data
    temp=temp.next
    

*/


int main() {
   

    Queue q;
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(1);
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << endl;


    q.print();

}
