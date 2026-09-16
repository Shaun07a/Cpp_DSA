#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> postOrder(Node* root) {
    vector<int> postorder;
    stack<Node*> st;
    Node* node = root;
    Node* lastVisited = NULL;

    while (node != NULL || !st.empty()) {
        if (node != NULL) {
            st.push(node);
            node = node->left;
        }
        else {
            Node* temp = st.top();

            if (temp->right != NULL && lastVisited != temp->right) {
                node = temp->right;
            }
            else {
                postorder.push_back(temp->data);
                lastVisited = temp;
                st.pop();
            }
        }
    }

    return postorder;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);

    cout << "Postorder Traversal: ";

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}