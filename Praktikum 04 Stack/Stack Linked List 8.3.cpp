#include <iostream>
using namespace std;

class Node {
public:
    int nilai;
    Node* next;

    Node(int nil, Node* n = nullptr) {
        nilai = nil;
        next = n;
    }
};

class ListStack {
private:
    Node* head;
    int count;

public:
    ListStack() {
        head = nullptr;
        count = 0;
    }

    int size() {
        return count;
    }

    bool empty() {
        return count == 0;
    }

    int peek() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        return head->nilai;
    }

    void push(int nil) {
        head = new Node(nil, head);
        count++;
    }

    int pop() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        int nil = head->nilai;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return nil;
    }
};

int main() {
    ListStack stack;
    stack.push(1);
    stack.push(2);
   

    cout << "Top element: " << stack.peek() << endl;
    cout << "Size of stack: " << stack.size() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}
