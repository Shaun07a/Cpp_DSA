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

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int LengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }

    return cnt;
}

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }

    return 0;

}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    // Node y = Node(arr[0], nullptr);
    // cout << y.data;

    // Node* y = new Node(arr[0], nullptr);
    // cout << y;

    // Node* y = new Node(arr[0]);
    // cout << y->data;
    Node* head = convertArr2LL(arr);
    // cout << head->data;
    Node* temp = head;
    // cout << LengthOfLL(head);
    cout << checkIfPresent(head, 5);
}