#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct Node {
    int val;
    struct Node *ptr;
} Node;

int size(Node *head);
bool empty( Node *head);
Node* push_front(Node *head, int val);
int at(Node *head, int index);
int pop_front(Node *head);
Node* push_back(Node *head, int val);
int front(Node *head);
int back(Node *head);
Node* insert(Node *head, int index, int val);
int erase(Node *head, int index);

int main(int argc, char *argv[]) {
    Node *head = malloc(sizeof(Node));
    if(head == NULL){
        printf("MALLOC ERROR!\n");
        return -1;
    }

    Node *tail = malloc(sizeof(Node));
    if(tail == NULL){
        printf("MALLOC ERROR!\n");
        return -1;
    }

    head->ptr = tail;
    tail->ptr = NULL;

    push_front(head, 100);
    push_front(head, 101);
    push_front(head, 102);
    push_front(head, 103);
    push_front(head, 104);
    push_front(head, 105);

    return 0;
}

int size(Node *head) {
    int count = 0;

    while(head->ptr->ptr != NULL){
        count++;
        head = head->ptr;
    }

    return count;
}

bool empty(Node *head) {
    if(head->ptr->ptr == NULL){
        return true;
    } else{
        return false;
    }
}

int at(Node *head, int index) {
    for(int i=0; i<index+1; i++){
        if(head->ptr == NULL){
            printf("OUT OF BOUNDS!\n");
            return -1;
        }
        head = head->ptr;
    }

    return head->val;
}

Node* push_front(Node *head, int val) {
    Node *tmp = malloc(sizeof(Node));
    if(tmp == NULL){
        printf("MALLOC ERROR!\n");
        return NULL;
    }

    tmp->ptr = head->ptr;
    tmp->val = val;
    head->ptr = tmp;

    return tmp;
}

int pop_front(Node *head) {
    if(empty(head)){
        printf("LIST EMPTY!\n");
        return -1;
    }

    Node *tmp = head->ptr->ptr;
    int val = head->ptr->val;
    free(head->ptr);
    head->ptr = tmp;

    return val;
}

Node* push_back(Node *head, int val) {
    Node *tmp = malloc(sizeof(Node));
    if(tmp == NULL){
        printf("MALLOC ERROR!\n");
        return NULL;
    }
    
    while(head->ptr->ptr != NULL){
        head = head->ptr;
    }

    tmp->ptr = head->ptr;
    tmp->val = val;
    head->ptr = tmp;

    return tmp;
}

int front(Node *head) {
    if(empty(head)){
        printf("LIST EMPTY!\n");
        return -1;
    }

    return head->ptr->val;
}

int back(Node *head) {
    if(empty(head)){
        printf("LIST EMPTY!\n");
        return -1;
    }

    while(head->ptr->ptr != NULL){
        head = head->ptr;
    }

    return head->val;
}

Node* insert(Node *head, int index, int val) {
    if(empty(head)){
        printf("LIST EMPTY!\n");
        return NULL;
    }

    for(int i=0; i<index; i++){
        if(head->ptr->ptr == NULL){
            printf("OUT OF BOUNDS!\n");
            return NULL;
        }
        head = head->ptr;
    }

    Node *tmp = malloc(sizeof(Node));
    if(tmp == NULL){
        printf("MALLOC ERROR!\n");
        return NULL;
    }

    tmp->ptr = head->ptr;
    tmp->val = val;
    head->ptr = tmp;

    return tmp;
}

int erase(Node *head, int index) {
    if(empty(head)){
        printf("LIST EMPTY!\n");
        return -1;
    }

    for(int i=0; i<index; i++){
        if(head->ptr->ptr == NULL){
            printf("OUT OF BOUNDS!\n");
            return -1;
        }
        head = head->ptr;
    }

    Node *tmp = head->ptr->ptr;
    int val = head->ptr->val;
    free(head->ptr);
    head->ptr = tmp;

    return val;
}