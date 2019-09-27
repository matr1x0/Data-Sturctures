/* Program to implement a Linked List and basic functions using "triple ref"
technique. 
Created By - Kumar Aditya (matr1x0)
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    private : char item;
        Node *next;
    public: 
        static Node *newNode(char item) {
            Node *node = new Node();
            node->item = item;
            node->next = NULL;
            return node;
        }

        static void insert(Node **head, Node *node) {
            Node **tracer = head;
            while (*tracer && (*tracer)->item < node->item)
                tracer = &(*tracer)->next;
            node->next = *tracer;
            *tracer = node;
        }

        static void deleteNode(Node **head, char item) {
            Node **tracer = head;
            while ((*tracer)->item != item)
                tracer = &(*tracer)->next;

            *tracer = (*tracer)->next;
        }
        
        static void print(Node **head) {
            Node **tracer = head;
            while (*tracer) {
                cout << (*tracer)->item << " ";
                tracer = &(*tracer)->next;
            }
            cout << endl;
        }
};

int main() {
    Node *head = Node::newNode('-');
    Node::insert(&head, Node::newNode('a'));
    Node::insert(&head, Node::newNode('c'));
    Node::insert(&head, Node::newNode('d'));
    Node::insert(&head, Node::newNode('b'));

    printf("\nINITIAL LIST: ");
    Node::print(&head);

    printf("\nALTERED LIST: ");
    Node::deleteNode(&head, 'e');
    Node::deleteNode(&head, 'd');
    Node::print(&head);

    return 0;
}