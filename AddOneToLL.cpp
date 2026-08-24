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

int addHelper(Node* temp){
    if(temp == NULL){
        return 1;
    }
    
    int carry = addHelper(temp->next);
    temp->data += carry;
    if(temp->data < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head){
    int carry = addHelper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

int main(){
    vector<int> arr ={1, 5, 9};
    Node* head = convertArr2DLL(arr);
    Node* one = addOne(head);
    print(one);
    
}