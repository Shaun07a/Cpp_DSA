#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back= nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size();i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;

}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    prev->next = nullptr;
    tail->next = nullptr;
    delete tail;
    return head;
}

Node* removeKthElement(Node* head, int k){
    if(head == NULL){
        return NULL;
    }

    Node* kNode = head;
    int cnt = 0;
    while(kNode != NULL){
        cnt++;
        if(cnt == k){
            break;
        }

        kNode = kNode->next;

    }

    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }
    else{
        prev->next = front;
        front->back = prev;
        kNode->back = nullptr;
        kNode->next = nullptr;
        delete kNode;
        return head;
    }
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    head = removeKthElement(head, 4);
    print(head);
    return 0;
}