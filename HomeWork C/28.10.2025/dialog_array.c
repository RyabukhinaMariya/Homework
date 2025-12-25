#include <stdio.h>
#include <stdlib.h>

#define END 0
#define APPEND 1
#define DELETE 2
#define SHOW_LIST 3

typedef struct Node{
    float el;
    struct Node *next;
}Node;

Node* create_node(float el){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL){
        printf("memory error \n");
        return NULL;
    }
    new_node -> el = el;
    new_node -> next = NULL;
    return new_node;
}

// ordered append
void append(Node** head, float el){
  Node* new_node = create_node(el);
    if (new_node == NULL) return;
    
    if (*head == NULL || (*head)->el >= el) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL && current->next->el < el) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
}

void delete(Node** head, float value){
    if (*head == NULL) {
        printf("list is empty, nothing to delete.\n");
        return;
    }

    if ((*head) -> el == value){
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("element %f is deleted\n", value);
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && current -> el != value){
        prev = current;
        current = current -> next;
    }

    if (current == NULL){
        printf("the value is missing\n");
        return;
    }

    prev ->next = current ->next;
    free(current);
    printf("element %f is deleted\n", value);
}

void show_op(){
    printf("avalible operations: \n 0 - exit \n 1 - add element \n 2 - delete last element \n 3 - show list of elements \n");
}

void print_list(Node* head){
    Node* current = head;

    if (current == NULL){
        printf("list is empty \n");
        return;
    }

    while (current != NULL){
        printf("%f ", current -> el);
        current = current -> next;
    }
    printf("\n");
}

void free_list(Node** head){
    Node* current = *head;
    Node* next;

    while (current != NULL){
        next = current -> next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main(){
    float el, value_to_delete;
    int op;
    Node* head = NULL;

    show_op();

    while(1){
        printf("enter operation: ");
        scanf("%d", &op);

        switch(op){
            case APPEND:
            printf("enter number: ");
                scanf("%f", &el);
                append(&head, el);
                break;

            case DELETE:
                printf("enter the element you want to dlete: ");
                scanf("%f", &value_to_delete);
                delete(&head, value_to_delete);
                break;

            case SHOW_LIST:
                printf("the list is: ");
                print_list(head);
                break;

            case END:
                free_list(&head);
                return 0;
                break;

            default:
                printf("invalid operation\n");
                break;
        }
    }
    return 0;
}
