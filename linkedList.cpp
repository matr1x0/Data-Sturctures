/* Program to implement a Linked List and basic functions using "triple ref" 
technique. 
*/ 

#include <iostream> 
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

        static void insertNode(Node **head, Node *node) { 
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
        
        static void printList(Node **head) { 
            Node **tracer = head; 
            while (*tracer) { 
                cout << (*tracer)->item << " "; 
                tracer = &(*tracer)->next; 
            } 
            cout << endl; 
        } 
}; 

int main() { 
    Node *head = NULL;
    Node::insertNode(&head, Node::newNode('a')); 
    Node::insertNode(&head, Node::newNode('c')); 
    Node::insertNode(&head, Node::newNode('e')); 
    Node::insertNode(&head, Node::newNode('d')); 
    Node::insertNode(&head, Node::newNode('b')); 

    printf("\nINITIAL LIST: "); 
    Node::printList(&head); 

    printf("\nALTERED LIST: "); 
    Node::deleteNode(&head, 'e'); 
    Node::deleteNode(&head, 'd'); 
    Node::printList(&head); 

    return 0; 
} 
