#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* findIntersection(Node* head1, Node* head2) {
    if (head1 == NULL || head2 == NULL) {
        return NULL;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != temp2) {

        if (temp1 == NULL)
            temp1 = head2;
        else
            temp1 = temp1->next;

        if (temp2 == NULL)
            temp2 = head1;
        else
            temp2 = temp2->next;
    }

    return temp1;
}

int main() {

    // Common part
    Node* common = new Node(4);
    common->next = new Node(6);
    common->next->next = new Node(2);

    // First list
    Node* head1 = new Node(3);
    head1->next = new Node(1);
    head1->next->next = common;

    // Second list
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(5);
    head2->next->next->next = common;

    Node* intersect = findIntersection(head1, head2);

    if (intersect != NULL) {
        cout << "Intersection at node: " << intersect->data << endl;
    }
    else {
        cout << "No intersection" << endl;
    }

    return 0;
}