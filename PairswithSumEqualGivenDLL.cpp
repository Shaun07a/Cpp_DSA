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

Node* findTail(Node* head){
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    return tail;
}

vector<pair<int, int>> findPairs(Node* head, int sum){
    Node* left = head;
    Node* right = findTail(head);
    vector<pair<int, int>> ans;
    if(head==NULL) return ans;
    while(left->data < right->data){
        if(left->data + right->data == sum){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        }else if(left->data + right->data < sum){
            left = left->next;
        }else{
            right = right->back;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 9};

    Node* head = convertArr2DLL(arr);

    int sum = 5;

    vector<pair<int, int>> ans = findPairs(head, sum);

    for(auto it : ans){
        cout << "(" << it.first << ", " << it.second << ")" << endl;
    }

    return 0;
}