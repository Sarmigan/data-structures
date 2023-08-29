#include <stdio.h>

struct Node
{
    int val;
    struct Node *ptr;
};

int main(int argc, char *argv[]) {

    struct Node tail = { 500, NULL};
    struct Node head = { 10, &tail };

    return 0;
}

int push_front(struct Node head, int val){
    struct Node *tmp = head.ptr;
}