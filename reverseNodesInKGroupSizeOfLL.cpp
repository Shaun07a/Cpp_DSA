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

Node* reverseLinkedList(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

Node* getKthNode(Node* temp, int k){
    k -= 1;
    while(temp != NULL && k > 0){
        k--;
        temp= temp->next;
    }

    return temp;
}

int main(){
    vector<int> arr = {1, 0 , 1, 2, 0, 2, 1};
    Node* head = convertArr2DLL(arr);
    
}