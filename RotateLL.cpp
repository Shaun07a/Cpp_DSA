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

Node* findNthNode(Node* temp, int k){
    int cnt = 1;
    while(temp != NULL){
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }

    return temp;
}

Node* Rotate(Node* head, int k){
    if(head == NULL || k == 0) return head;
    Node* tail = head;
    int len = 1;
    while(tail->next != NULL){
        tail = tail->next;
        len += 1;
    }

    if(k % len == 0) return head;
    k = k % len;
    tail->next = head;
    Node* newLastNode = findNthNode(head, len-k);
    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}

int main(){
    vector<int> arr ={1, 2, 3, 4, 5};
    Node* head = convertArr2DLL(arr);
    Node* rotateLL = Rotate(head, 2);
    print(rotateLL);
    
}