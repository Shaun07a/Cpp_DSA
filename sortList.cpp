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

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* mergeTwoLists(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }

    if(list1) temp->next = list1;
    if(list2) temp->next = list2;

    return dummyNode->next;
}

Node* sortLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* middle = findMiddle(head);
    Node* right = middle->next;
    middle->next = NULL;
    Node* left = head;

    left = sortLL(left);
    right = sortLL(right);
    return mergeTwoLists(left, right);
}

int main(){
    vector<int> arr ={3, 4, 2, 1, 5};
    Node* head = convertArr2DLL(arr);
    Node* sortLinkedList = sortLL(head);
    print(sortLinkedList);
}