/* Type your code here, or load an example. */
#include<stdio.h>
#include<stdlib.h>

//node structure
struct Node{
    int data;
    struct Node* next;
};

//structure for linked list
struct LinkedList{
    Node* head;
};

//initialize an empty linked list
struct LinkedList* createLinkedList(){
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    return list;
}
//insert a new node at the beginning of the list
void insertAtBeginning(LinkedList* list, int data){
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
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
void deleteNode(LinkedList* list, int data){
    struct Node* temp = list->head;
    struct Node* prev = NULL;
    if(temp != NULL && temp->data == data){
        list->head = temp->next;
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
struct Node* searchNode(LinkedList* list, int searchData){
    struct Node* temp = list->head;
    while(temp != NULL){
        if(temp->data == searchData){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
//reverse the list
void reverseList(LinkedList* list){
    struct Node* prev = NULL;
    struct Node* current = list->head;
    struct Node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}
//get the length of the list
int getLength(LinkedList* list){
    struct Node* temp = list->head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}
//write a function to detect a loop in the linked list and return the node at which the loop starts
struct Node* detectLoop(LinkedList* list){
    struct Node* slow = list->head;
    struct Node* fast = list->head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = list->head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
    }
    return NULL;
}

#include<gtest/gtest.h>
TEST(LinkedListTest, InsertAtBeginningTest){
    struct LinkedList* list = createLinkedList();

    insertAtBeginning(list,3);
    insertAtBeginning(list,2);
    insertAtBeginning(list,1);

    ASSERT_EQ(list->head->data,1);
    ASSERT_EQ(list->head->next->data,2);
    ASSERT_EQ(list->head->next->next->data,3);
}
TEST(LinkedListTest, InsertAfterNodeTest){
    struct LinkedList* list = createLinkedList();

    insertAtBeginning(list,3);
    insertAtBeginning(list,2);
    insertAtBeginning(list,1);
    struct Node* node = list->head->next->next;
    insertAfterNode(node, 5);
    ASSERT_EQ(list->head->data,1);
    ASSERT_EQ(list->head->next->data,2);
    ASSERT_EQ(list->head->next->next->data,3);
    ASSERT_EQ(list->head->next->next->next->data,5);
}
//testing the delete node
TEST(LinkedListTest, DeleteNodeTest){
    struct LinkedList* list = createLinkedList();

    insertAtBeginning(list,3);
    insertAtBeginning(list,2);
    insertAtBeginning(list,1);
    deleteNode(list, 2);
    ASSERT_FALSE(searchNode(list,2));
}
//search for specific node
TEST(LinkedListTest, SearchNodeTest){
    struct LinkedList* list = createLinkedList();

    insertAtBeginning(list,3);
    insertAtBeginning(list,2);
    insertAtBeginning(list,1);

    ASSERT_TRUE(searchNode(list,2));
    ASSERT_FALSE(searchNode(list,5));
}
//reverse
TEST(LinkedListTest, ReverseListTest){
    struct LinkedList* list = createLinkedList();

    insertAtBeginning(list,3);
    insertAtBeginning(list,2);
    insertAtBeginning(list,1);
    reverseList(list);

    ASSERT_EQ(list->head->data,3);
    ASSERT_EQ(list->head->next->data,2);
    ASSERT_EQ(list->head->next->next->data,1);
}
//length
TEST(LinkedListTest, GetLengthTest){
    struct LinkedList* list = createLinkedList();

    insertAtBeginning(list,3);
    insertAtBeginning(list,2);
    insertAtBeginning(list,1);
    ASSERT_EQ(getLength(list),3);
    ASSERT_NE(getLength(list),4);
}
//testing the detect loop
TEST(LinkedListTest, DetectLoop){
    struct LinkedList* list = createLinkedList();
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));
    node1->data = 10;
    node1->next = node2;
    node2->data = 20;
    node2->next = node3;
    node3->data = 30;
    node3->next = node2;      //creating a loop
    
    list->head = node1;
    ASSERT_TRUE(detectLoop(list));
}
//main function
int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    
}
