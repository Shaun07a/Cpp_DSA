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

int findLength(Node* slow, Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow != fast){
        cnt++;
        fast = fast->next;
    }

    return cnt;
}

int detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return findLength(slow, fast);
    }

    return 0;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Node* head = convertArr2DLL(arr);

    // Find node 3
    Node* node3 = head;
    for(int i = 1; i < 3; i++){
        node3 = node3->next;
    }

    // Find node 9 (last node)
    Node* last = head;
    while(last->next != NULL){
        last = last->next;
    }

    // Create cycle: 9 -> 3
    last->next = node3;

    if(detectCycle(head)){
        cout << "Cycle detected" << endl;
    }
    else{
        cout << "No cycle" << endl;
    }

    cout << detectCycle(head);

    return 0;
}