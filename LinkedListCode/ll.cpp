#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = nullptr;
    }
};
class LinkedList {
    private:
    Node* head = nullptr;
    public:
    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<< "NULL" << endl;
    }
    void insert_at_beginning(int d){
        Node* newNode = new Node(d);
        head = newNode;
    }
    void insert_at_end(int d){
        Node* newNode = new Node(d);
        Node* temp = head;
        if(temp == nullptr){
            head = newNode;
            return;
        }
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insert_in_between(int d,int pos){
        if(pos < 0){
            cout<<"Invalid position"<<endl;
            return;
        }
        if(pos == 0){
            insert_at_beginning(d);
            return;
        }
         Node* temp = head;
         int count = 0;
        while(count<pos-1&&temp->next!=nullptr){
            temp = temp->next;
            count++;
        }
        if(temp->next == nullptr){
            insert_at_end(d);
            return;
        }
        Node* newNode = new Node(d);
        newNode->next = temp->next;
        temp->next = newNode;

    }
    bool search(int key){
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void delete_at_start(){
        Node* temp = head;
        if(temp == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        head = temp->next;
        delete temp;
    }
    void delete_at_end(){
        Node* temp = head;
        if(temp == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void delete_in_between(int d,int pos){
        if(pos < 0){
            cout<<"Invalid position"<<endl;
            return;
        }
        if(pos == 0){
            delete_at_start();
            return;
        }
         Node* temp = head;
         int count = 0;
        while(count<pos-1&&temp->next!=nullptr){
            temp = temp->next;
            count++;
        }
        if(temp->next == nullptr){
            delete_at_end();
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
};
int main (){
    LinkedList ll;
    ll.insert_at_beginning(10);
    ll.display();
    ll.insert_at_end(20);
    ll.display();
    ll.insert_in_between(15,1);
    ll.display();
    bool found = ll.search(20);
    if(found){
        cout<<"Element found"<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
    // ll.delete_at_start();
    // ll.display();
    // ll.delete_at_end();
    // ll.display();
    ll.delete_in_between(15,1);
    ll.display();
    return 0;
}