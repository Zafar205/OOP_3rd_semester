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

class LinkedList{
    Node* head;
    public:
    LinkedList(): head(nullptr) {}



    void insertAt(int index, int dat){

        if(index < 0 ){
            cout << "Invalid Index" << endl;
            return;
        }

        Node* node = new Node(dat);

        if(head == nullptr){
            head = node;
            return;
        }

        if(index == 0){
            Node* temp = head;
            head = node;
            head->next = temp;  
            return;
        }

        int i = 0;
        Node* current = head;
        Node* previous = nullptr;

        while(current != nullptr){
            if (i == index){
                previous->next = node;
                node->next = current;
                return;
            }
            
            previous = current;
            current = current->next;
            i++;
        }

        cout <<"Element not found"<<endl;
    }

    void deleteAt(int index){
        if(head == nullptr){
            cout << "List is empty";
            return;
        }

        if(index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        int i = 0;
        Node* current = head;
        Node* previous = nullptr;

        while(current != nullptr){
            if (i == index){
                previous->next = current->next;
                delete current;
                return;
            }
            i++;
            previous = current;
            current = current->next;
        }
    }

    void traverse(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " " ;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList L;
    L.insertAt(0, 5);
    L.insertAt(0, 6);
    L.insertAt(0, 7);
    L.traverse();
    L.insertAt(1, 1);
    L.insertAt(2, 2);
    L.traverse();
    L.insertAt(4, 99);
    L.traverse();
    L.deleteAt(0);
    L.traverse();
    L.deleteAt(2);
    L.traverse();
    L.deleteAt(3);
    L.traverse();
    return 0;
}