#include <iostream>
using namespace std;

class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string url1) {
        url = url1;
        prev = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
public:
    Node* current;

    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        Node* temp = current->next;

        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        current->next = nullptr;

        Node* newNode = new Node(url);

        current->next = newNode;
        newNode->prev = current;

        current = newNode;
    }

    void back(int steps) {
        while (steps > 0 && current->prev != nullptr) {
            current = current->prev;
            steps--;
        }
    }

    void forward(int steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next;
            steps--;
        }
    }

    void getCurrentPage() {
        cout << "Current Page: " << current->url << endl;
    }
};

int main() {
    BrowserHistory browser("homepage.com");

    browser.visit("google.com");
    browser.visit("youtube.com");
    browser.visit("github.com");

    browser.getCurrentPage();

    browser.back(1);
    browser.getCurrentPage();

    browser.back(1);
    browser.getCurrentPage();

    browser.forward(1);
    browser.getCurrentPage();

    browser.visit("facebook.com");
    browser.getCurrentPage();

    return 0;
}