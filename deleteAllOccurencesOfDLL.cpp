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

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
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

Node* deleteAllOccurences(Node* head, int k){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == k){
            if(temp == head){
                head = temp->next;
            }

            Node* nextNode = temp->next;
            Node* prevNode = temp->back;
            if(nextNode != NULL) nextNode->back = prevNode;
            if(prevNode != NULL) prevNode->next = nextNode;

            free(temp);
            temp = nextNode;
        }else{
            temp = temp->next;
        }
    }

    return head;
}

int main(){
    vector<int> arr = {10, 4, 10, 10, 6, 10};
    Node* head = convertArr2DLL(arr);
    Node* del = deleteAllOccurences(head, 10);
    print(del);
}