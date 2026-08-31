#include <bits/stdc++.h>
using namespace std;

class StackQueue {
public:
    stack<int> input, output;

    StackQueue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }

        return output.top();
    }

    bool isEmpty() {
        return input.empty() && output.empty();
    }
};

int main() {
    StackQueue q;

    q.push(3);
    q.push(4);

    cout << "The element popped is " << q.pop() << endl;

    q.push(5);

    cout << "The front of the queue is " << q.peek() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "The element popped is " << q.pop() << endl;
    cout << "The element popped is " << q.pop() << endl;

    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}