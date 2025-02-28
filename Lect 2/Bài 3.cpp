#include <iostream>

 using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int n) {
        data = n;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList(){
    	head = NULL;
    	tail = NULL;
	}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int count_triplets() {
        if (!head || !head->next || !head->next->next) return 0; 

        int count = 0;
        Node* curr = head->next; 

        while (curr->next) {
            if (curr->prev->data + curr->data + curr->next->data == 0) {
                count++;
            }
            curr = curr->next;
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList list;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.insert(num);
    }

    cout << list.count_triplets() << endl;

    return 0;
}
