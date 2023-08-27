#include <stdio.h>
#include <stdlib.h>

int size(int **ptr);
int at(int **ptr, int index);
int* push(int **ptr, int val);
int* insert(int **ptr, int index, int val);
int pop(int** ptr);
int* delete(int **ptr, int index);
int* find_remove(int **ptr, int val);

int main(int argc, char *argv[]) {
    int *arr = (int*) malloc(sizeof(int));
    *arr = 0;
    int **ptr = &arr;

    free(*ptr);

    return 0;
}

int size(int **ptr){
    return **ptr;
}

int at(int **ptr, int index){
    int len = **ptr;

    if(index+1>len || index<0){
        return -1;
    }

    return *(*ptr+index+1);
}

int* push(int **ptr, int val){
    int *arr = *ptr;
    int len = *arr;

    len++;
    *ptr = realloc(*ptr, sizeof(int)*(len+1));
    if(*ptr == NULL){
        printf("REALLOC ERROR!\n");
        return NULL;
    }

    *(*ptr+len) = val;

    **ptr = len;

    return *ptr;
}

int pop(int **ptr){
    int len = **ptr;
    int val = *(*ptr + len);

    if(len<1){
        printf("ARRAY EMPTY!\n");
        return -1;
    }

    len--;
    *ptr = realloc(*ptr, sizeof(int)*(len+1));
    if(*ptr == NULL){
        printf("REALLOC ERROR!\n");
        return -1;
    }

    **ptr = len;

    return val;
}

int* insert(int **ptr, int index, int val){
    int len = **ptr;
    int prev = val;
    
    if(index>len || index<0){
        printf("OUT OF BOUNDS!\n");
        return NULL;
    }

    len++;
    *ptr = realloc(*ptr, sizeof(int)*(len+1));
    if(*ptr == NULL){
        printf("REALLOC ERROR!\n");
        return NULL;
    }

    int *temp = *ptr+1;
    temp += index;
    for(int i=index; i<len; i++){
        val = prev;
        prev = *temp;
        *temp = val;
        temp++;
    }

    **ptr = len;

    return *ptr;
}

int* delete(int **ptr, int index){
    int len = **ptr;
    int *temp = *ptr;
    int prev;
    int curr;

    if(len<1){
        printf("ARRAY EMPTY!\n");
        return NULL;
    }

    temp += len;
    prev = *temp;
    temp--;
    for(int i=len-index-1; i>0; i--){
        curr = *temp;
        *temp = prev;
        prev = curr;
        temp--;
    }

    len--;

    *ptr = realloc(*ptr, sizeof(int)*(len+1));
    if(*ptr == NULL){
        printf("REALLOC ERROR!\n");
        return NULL;
    }

    **ptr = len;

    return *ptr;
}

int* find_remove(int **ptr, int val){
    int len = **ptr;
    int *temp = *ptr + 1;

    if(len<1){
        printf("ARRAY EMPTY!\n");
        return NULL;
    }

    for(int i=0; i<len; i++){
        if(*temp == val){
            delete(ptr, i);
            i--;
            len = **ptr;
            temp = *ptr + i + 2;
        } else{
            temp++;
        }
    }

    return *ptr;
}