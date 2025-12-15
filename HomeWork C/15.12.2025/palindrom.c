#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int el;
    struct list* next;
}List;

List* create_List(int value){
    List* new_List = (List*)malloc(sizeof(List));
    if (new_List == NULL){
        printf("luck of memory");
        return NULL;
    }
    new_List -> el = value;
    new_List -> next = NULL;
    return new_List;
}

void append(List** last, int value) {
    List* new_List = create_List(value);
    
    if (*last == NULL) {
        *last = new_List;
        return;
    }
    List* current = *last;
    while (current -> next != NULL) {
        current = current -> next;
    }
    current->next = new_List;
}

void free_list(List* last) {
    List* current = last;
    List* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

List* reverse_list(List* head) {
    List* prev = NULL;
    List* current = head;
    List* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

int compare_lists(List* list1, List* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->el != list2->el) {
            return 0;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    
    return (list1 == NULL && list2 == NULL);
}

int is_symmetric(List* head) {
    if (head == NULL || head->next == NULL) {
        return 1; // нулевой или единичный список симметричен
    }
    
    // ищем середину списка методом двух указателей
    List* slow = head;
    List* fast = head;
    List* prev_slow = NULL;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }
    
    List* second_half;
    
    if (fast != NULL) { // нечетное количество элементов
        second_half = slow->next;
    } else { // четное количество элементов
        second_half = slow;
    }
    
    if (prev_slow != NULL) {
        prev_slow->next = NULL;
    }
    
    List* reversed_second_half = reverse_list(second_half);
    
    int result = compare_lists(head, reversed_second_half);
    
    second_half = reverse_list(reversed_second_half);
    if (prev_slow != NULL) {
        prev_slow->next = second_half;
    }
    
    return result;
}

int main(){
    List* last = NULL;
    int number;
    
    // ввод '0' оканчивает программу
    while (1) {
        if (scanf("%d", &number) != 1) {
            printf("invalid input\n");
            free_list(last);
            return 1;
        }

        if (number == 0) {
            break;
        }
        
        if (number < 1) {
            printf("invalid input");
            continue;
        }
        
        append(&last, number);
    }
    
    
    if (is_symmetric(last)) {
        printf("list is symmetric\n");
    } else {
        printf("list is not symmetric\n");
    }
    
    free_list(last);
    return 0;
}
