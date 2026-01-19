#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Reverse the linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Add 1 to the number represented by linked list
Node* addOne(Node* head) {
    // Reverse list
    head = reverse(head);

    Node* curr = head;
    int carry = 1;

    while (curr && carry) {
        int sum = curr->data + carry;
        curr->data = sum % 10;
        carry = sum / 10;

        if (!curr->next && carry) {
            curr->next = new Node(carry);
            carry = 0;
        }
        curr = curr->next;
    }

    // Reverse back
    return reverse(head);
}

// Append node at end
void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new Node(data);
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Example: 4 -> 5 -> 6 (represents 456)
    append(head, 4);
    append(head, 5);
    append(head, 6);

    cout << "Original Linked List: ";
    printList(head);

    head = addOne(head);

    cout << "After Adding 1:       ";
    printList(head);

    return 0;
}
