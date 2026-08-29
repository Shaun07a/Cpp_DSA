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

Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<pair<int, Node*>,
    vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    for(int i =0; i < listArray.size(); i++){
        if(listArray[i]){
            pq.push({listArray[i]->data, listArray[i]});
        }
    }

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.second->next)
            pq.push({it.second->next->data, it.second->next});
        temp->next = it.second;
        temp = temp->next;
    }

    return dummyNode->next;
}



int main() {
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};

    Node* head1 = convertArr2DLL(arr1);
    Node* head2 = convertArr2DLL(arr2);
    Node* head3 = convertArr2DLL(arr3);

    vector<Node*> listArray = {head1, head2, head3};

    Node* head = mergeKLists(listArray);

    Node* temp = head;

    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}