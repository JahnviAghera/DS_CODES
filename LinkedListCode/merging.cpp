#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
    void insert_at_end(int d,Node* head){
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
Node* mergeSortedLists(Node* l1, Node* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    if(l1 == nullptr && l2 == nullptr) return nullptr;
    
    Node* temp1 = l1;
    Node* temp2 = l2;
    Node* new_ll = new Node(0);
    while(temp1->next!=nullptr&&temp2->next){
        if(temp1->data <temp2->data){
            insert_at_end(temp1->data,new_ll);
            temp1 = temp1->next;
        }
        if(temp2->data <temp1->data){
            insert_at_end(temp2->data,new_ll);
            temp2 = temp2->next;
        }
    }
    if(temp1->next == nullptr){
        while(temp2->next){
            insert_at_end(temp2->data,new_ll);
            temp2 = temp2->next;
        }
    }
    if(temp2->next == nullptr){
        while(temp1->next){
            insert_at_end(temp1->data,new_ll);
            temp1 = temp1->next;
        }
    }
    Node* temp = new_ll;
    new_ll = new_ll->next;
    delete temp;
    return new_ll;
}

// void printList(Node* head) {
//     while (head) {
//         std::cout << head->data << " ";
//         head = head->next;
//     }
//     std::cout << std::endl;
// }
void display(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        std::cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    std::cout<< "NULL" << std::endl;
}


int main() {
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);
    l1->next->next->next = new Node(7);
    display(l1);

    Node* l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);
    display(l2);

    Node* mergedList = mergeSortedLists(l1, l2);
    display(mergedList);

    return 0;
}