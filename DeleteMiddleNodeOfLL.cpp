#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

Node* delMiddle(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}


int main(){
    vector<int> arr ={1, 2, 3, 4, 5};
    Node* head = convertArr2DLL(arr);
    Node* middle = delMiddle(head);
    print(head);
    
}