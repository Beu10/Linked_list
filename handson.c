#include<stdio.h>
#include<stdlib.h>

//node structure
struct Node{
    int data;
    struct Node* next;
};

//insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
//insert a new node after a specified node
void insertAfterNode(struct Node* prevNode, int data){
    if(prevNode == NULL){
        printf("previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
//delete a node from the list
void deleteNode(struct Node** head, int data){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if(temp != NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Node not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
//search for a specific node in the list
struct Node* search(struct Node* head, int searchData){
    struct Node* temp = head;
    while(temp != NULL){
        if(temp->data == searchData){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
//reverse the list
void reverseList(struct Node** head){
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
//get the length of the list
int getLength(struct Node* head){
    struct Node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}
//write a function to detect a loop in the linked list and return the node at which the loop starts
struct Node* detectLoop(struct Node* head){
    struct Node* slow = head;
    struct Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
// void displayList(struct Node* head){
//     struct Node* temp = head;
//     while(temp != NULL){
//         printf("%d",temp->data);
//         temp = temp->next;
//     }
//     printf("/n");
// }
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//test the linkedlist
int main(){
    struct Node* head = NULL;
    insertAtBeginning(&head,3);
    insertAtBeginning(&head,2);
    insertAtBeginning(&head,1);

    printf("linked list: ");
    printList(head);
    
    struct Node* node2 = search(head,2);
    insertAfterNode(node2,4);
    printf("Linked list after insertion: ");
    printList(head);
    
    //delete node
    deleteNode(&head,3);
    printf("list after deleting the node with value 3: ");
    printList(head);
    
    //search for specific node
    int searchData = 2;
    struct Node*searchResult = search(head, searchData);
    if(searchResult != NULL){
        printf("Node %d found.\n",searchData);
    }
    else{
        printf("Node %d not found.\n",searchData);
    }
    
    //reverse
    reverseList(&head);
    printf("reversed linked list :");
    printList(head);
    
    //length
    int length = getLength(head);
    printf("length of the list: %d\n",length);
    
    //create a loop
    head->next->next->next = head->next; //creating a loop at node with data
    
    struct Node* loopStartNode = detectLoop(head);
    if(loopStartNode != NULL){
        printf("Loop starts at node with data: %d\n",loopStartNode->data);
    }
    else{
        printf("No loop detected");
    }
    return 0;
}