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

class Queue{
    private:
    Node* front = nullptr;
    Node* rear = nullptr;

    public:
    void enqueue(int x){

        Node* node = new Node(x);

        if(front==nullptr && rear==nullptr){
            front = node;
            rear = node;
            return;
        } 

        rear->next = node;
        rear = node;

    }
    int dequeue(){
        int dat = front->data;

        if(front==nullptr && rear==nullptr){
            cout << "List is Empty" << endl;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        return dat;
    }

    void traverse(){
        Node* temp = front;
        while(temp != nullptr){
            cout << temp->data << "->" ;
            temp = temp->next;
        }
        cout << "NULL" <<endl;
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.traverse();
    q.dequeue();
    q.dequeue();
    q.traverse();
    return 0;
}