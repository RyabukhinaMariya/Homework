
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct List {
    int data;
    int len;
    struct List* next;
} List;

List* create_node(int data) {
    List* node = (List*)malloc(sizeof(List));
    node->data = data;
    node->next = NULL;
    return node;
}

List* cons(List* head, int data) {
    List* node = create_node(data);
    node->next = head;
    return node;
}

List* reverse(List* head) {
    List* prev = NULL;
    List* curr = head;
    
    while (curr != NULL) {
        List* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

int length(List* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

typedef struct Queue {
    List* f;
    List* r; 
} Queue;


Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->f = NULL;
    q->r = NULL;
    return q;
}

int is_empty(Queue* q) {
    return q->f == NULL && q->r == NULL;
}

Queue*norm(Queue* q) {
    if (q->f == NULL && q->r != NULL) {
        q->f = reverse(q->r);
        q->r = NULL;
    }
    return q;
}

Queue* enqueue(Queue* q, int data) {
    Queue* new_q = create_queue();
    
    new_q->f = q->f;
    new_q->r = cons(q->r, data);  
   norm(new_q);
    
    return new_q;
}

Queue* dequeue(Queue* q, int* value) {
    if (is_empty(q)) {
        *value = -1;  
        return q;
    }
    
    if (q->f == NULL && q->r != NULL) {
       norm(q);
    }
    
    *value = q->f->data;
    
    Queue* new_q = create_queue();
    new_q->f = q->f->next;
    new_q->r = q->r;
    
    free(q->f);
    
   norm(new_q);
    
    return new_q;
}


int main() {
    
    Queue* q = create_queue();

    Queue* q1 = enqueue(q, 1);
    Queue* q2 = enqueue(q1, 2);
    Queue* q3 = enqueue(q2, 3); 

    int val;
    Queue* d1 = dequeue(q3, &val);
    
    return 0;
}
