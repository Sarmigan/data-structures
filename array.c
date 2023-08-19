#include <stdio.h>
#include <stdlib.h>

int size(int **ptr);
int at(int **ptr, int index);
int* push(int **ptr, int val);
int* insert(int **ptr, int index, int val);
int pop(int** ptr);

int main(int argc, char *argv[]) {
    int *arr = (int*) malloc(sizeof(int));
    *arr = 0;
    int **ptr = &arr;
}

int size(int **ptr){
    return **ptr;
}

int at(int **ptr, int index){
    int *arr = *ptr;

    if(index+1>*arr || index<0){
        return -1;
    }

    return *(arr+=index+1);
}

int* push(int **ptr, int val){
    int *arr = *ptr;
    int len = *arr;

    arr = realloc(arr, sizeof(int)*(*arr+1));
    if(arr == NULL){
        printf("REALLOC ERROR!");
        return NULL;
    }

    *arr = len+1;
    *(arr+len+1) = val;

    *ptr = arr;

    return *ptr;
}

int* insert(int **ptr, int index, int val){
    int *arr = *ptr;
    int len = *arr;
    int prev = val;
    
    arr = realloc(arr, sizeof(int)*(*arr+1));
    if(arr == NULL){
        printf("REALLOC ERROR!");
        return NULL;
    }

    len++;

    int *temp = arr;
    temp += index+1;
    for(int i=index; i<len; i++){
        val = prev;
        prev = *temp;
        *temp = val;
        temp++;
    }

    *arr = len;

    *ptr = arr;

    return *ptr;
}

int pop(int **ptr){
    int *arr = *ptr;
    int len = *arr;
    int *temp = arr;
    temp += len;
    int val = *temp;

    arr = realloc(arr, sizeof(int)*(*arr-1));
    if(arr == NULL){
        printf("REALLOC ERROR!");
        return -1;
    }

    *arr = len-1;

    *ptr = arr;

    return val;
}