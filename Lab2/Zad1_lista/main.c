#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
}Node;


Node* create()
{
    Node * head = NULL;
    head = (Node *) malloc(sizeof(Node));
    if (head == NULL) {
        return NULL;
    }

    head->val = 0;
    head->next = NULL;

    return head;

}

void printList(Node * head) {
    Node * current = head;
    int index = 0;

    if(current == NULL)
    {
        printf("Empty!\n");
        return;
    }

    while (current != NULL) {
        printf("[(%d.) %d] -> ", index++, current->val);
        current = current->next;
    }
    printf("END\n");
}


void pushAtEnd(Node* head, int val) {

    Node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (Node*) malloc(sizeof(Node));
    current->next->val = val;
    current->next->next = NULL;
}

void pushAtBeg(Node** head, int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

int pop(Node** head) {
    int retval = -1;
    Node * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int removeLast(Node * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    Node * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;

}

int removeByValue(Node ** head, int x) {
    printf("remove_by_value: %d\n", x);
    int retval = -1;
    Node * current = *head;
    Node * temp_node = NULL;

    int foundIndex = -1;
    while (current != NULL) {
        foundIndex++;
        printf("foundIndex: %d\n", foundIndex);
        if(current->val == x)
        {
            printf("foundIndex: %d\n", foundIndex);
            temp_node = current->next;
            retval = temp_node->val;
            current->next = temp_node->next;
            free(temp_node);
            break;
        }
        else current = current->next;
    }

    return retval;

}


int main()
{
    printf("Zad1_lista!\n");


    Node* first = NULL; //struct node* first = NULL;
    Node* second = NULL; //struct node* second = NULL;
    Node* third = NULL; //struct node* third = NULL;

    // allocate 3 nodes in the heap
    first = (Node*)malloc(sizeof(Node));//(struct node*)malloc(sizeof(struct node));
    second = (Node*)malloc(sizeof(Node));//(struct node*)malloc(sizeof(struct node));
    third = (Node*)malloc(sizeof(Node));//(struct node*)malloc(sizeof(struct node));

     /*
       first           second           third
        |                |               |
        |                |               |
    +---+-----+     +----+----+     +----+----+
    | #  | #  |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+
    */

    first->val = 1; // assign data in first node
    first->next = second; // Link first node with
    /*
       first          second         third
        |              |              |
        |              |              |
    +---+---+     +----+----+     +-----+----+
    | 1  | o----->| #  | #  |     |  #  | #  |
    +---+---+     +----+----+     +-----+----+
  */
    second->val = 2;
    first->next->val = 2;

    second->next = third;
    first->next->next = third;
    /*
       first         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1  | o----->| 2 | o-----> |  # |  # |
    +---+---+     +---+---+     +----+----+      */
    third->val = 3; // assign data to third node
    third->next = NULL;
    /*
           first
             |
             |
        +---+---+     +---+---+       +----+------+
        | 1  | o----->|  2  | o-----> |  3 | NULL |
        +---+---+     +---+---+       +----+------+
     */

     printf("First: %d\n", first->val);
     printf("Second: %d\n", first->next->val);
     printf("Second:%d\n", second->val);
     printf("Third:%d\n", first->next->next->val);
     printf("Third:%d\n", second->next->val);
     printf("Third:%d\n", third->val);
     printf("After Third:%d\n", third->next);





    //Node* head = create();
    Node * head = NULL;
    printList(head);

    head = (Node *) malloc(sizeof(Node));
    if (head == NULL) {
        return -1;
    }
    head->val = 0;
    head->next = NULL;

    printList(head);
    pushAtEnd(head, 10);
    pushAtEnd(head, 20);
    pushAtEnd(head, 30);

    printList(head);
    pushAtBeg(&head, 80);
    pushAtBeg(&head, 70);
    printList(head);

    return 0;
}
