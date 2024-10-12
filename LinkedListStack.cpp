#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x = 0){
        data = x;
        next = nullptr;
    }
};

class Stack{
    private:
    Node* top = nullptr;

    public:
    void push(int x){
        Node* node = new Node(x);

        if (top == nullptr){
            top = node;
        }
        else{
            node->next = top;
            top = node;
        }
    }

    int pop(){
        if (top == nullptr){
            cout << "Stack is Empty" << endl;
            return 0; // Return a sentinel value when stack is empty
        }

        int dat = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        return dat;
    }

    void traverse(){
        Node* temp = top;
        while(temp != nullptr){
            cout << temp->data << "->" ;
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.traverse();
    s.pop();
    s.pop();
    s.traverse();
    return 0;
}
