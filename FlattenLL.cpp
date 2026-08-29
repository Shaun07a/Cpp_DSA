// #include <bits/stdc++.h>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode *child;

//     ListNode() {
//         val = 0;
//         next = NULL;
//         child = NULL;
//     }

//     ListNode(int data1) {
//         val = data1;
//         next = NULL;
//         child = NULL;
//     }

//     ListNode(int data1, ListNode *next1, ListNode *next2) {
//         val = data1;
//         next = next1;
//         child = next1;
//     }
// };

// class Solution {
// private:
//     ListNode* merge(ListNode* list1, ListNode* list2) {
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* res = dummyNode;

//         while(list1 != NULL && list2 != NULL) {
//             if(list1->val < list2->val) {
//                 res->child = list1;
//                 res = list1;
//                 list1 = list1->child;
//             }
//             else {
//                 res->child = list2;
//                 res = list2;
//                 list2 = list2->child;
//             }
//             res->next = NULL;
//         }

//         if(list1) {
//             res->child = list1;
//         }
//         else {
//             res->child = list2;
//         }

//         if(dummyNode->child) {
//             dummyNode->child->next = NULL;
//         }

//         return dummyNode->child;
//     }

// public:
//     ListNode* flattenLinkedList(ListNode* head) {
//         if(head == NULL || head->next == NULL) {
//             return head;
//         }

//         ListNode* mergedHead = flattenLinkedList(head->next);

//         head = merge(head, mergedHead);

//         return head;
//     }
// };

// void printLinkedList(ListNode* head) {
//     while(head != nullptr) {
//         cout << head->val << " ";
//         head = head->child;
//     }
//     cout << endl;
// }

// void printOriginalLinkedList(ListNode* head, int depth) {
//     while(head != nullptr) {
//         cout << head->val;

//         if(head->child) {
//             cout << " -> ";
//             printOriginalLinkedList(head->child, depth + 1);
//         }

//         if(head->next) {
//             cout << endl;
//             for(int i = 0; i < depth; ++i) {
//                 cout << "| ";
//             }
//         }

//         head = head->next;
//     }
// }

// int main() {
//     ListNode* head = new ListNode(5);
//     head->child = new ListNode(14);

//     head->next = new ListNode(10);
//     head->next->child = new ListNode(4);

//     head->next->next = new ListNode(12);
//     head->next->next->child = new ListNode(20);
//     head->next->next->child->child = new ListNode(13);

//     head->next->next->next = new ListNode(7);
//     head->next->next->next->child = new ListNode(17);

//     cout << "Original linked list:" << endl;
//     printOriginalLinkedList(head, 0);

//     Solution sol;

//     ListNode* flattened = sol.flattenLinkedList(head);

//     cout << "\nFlattened linked list: ";
//     printLinkedList(flattened);

//     return 0;
// }


//Another code
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;

    ListNode(int data) {
        val = data;
        next = NULL;
        child = NULL;
    }
};

class Solution {
private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                temp->child = list1;
                list1 = list1->child;
            }
            else {
                temp->child = list2;
                list2 = list2->child;
            }

            temp = temp->child;
        }

        if (list1 != NULL) {
            temp->child = list1;
        }
        else {
            temp->child = list2;
        }

        return dummy->child;
    }

public:
    ListNode* flattenLinkedList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        head->next = flattenLinkedList(head->next);

        head = merge(head, head->next);

        return head;
    }
};

void printLinkedList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(10);
    head->next->child = new ListNode(4);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(20);
    head->next->next->child->child = new ListNode(13);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    Solution sol;

    ListNode* flattened = sol.flattenLinkedList(head);

    cout << "Flattened sorted linked list: ";
    printLinkedList(flattened);

    return 0;
}