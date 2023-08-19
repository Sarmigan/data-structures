#include <stdio.h>
#include <stdlib.h>

int size(int *arr);
int* at(int *arr, int index);
int* push(int *arr, int val);
int* insert(int *arr, int index, int val);
int* pop(int* arr);

int main(int argc, char *argv[]) {
    int *arr;
    arr = (int*) malloc(sizeof(int));
    *arr = 0;

    push(arr, 100);
    push(arr, 101);
    push(arr, 102);

    insert(arr, 2, 200);

    for(int i=0; i<4; i++){
        int *pos = at(arr, i);
        if(pos == NULL){
            printf("Error!\n");
        } else{
            printf("%d\n", *pos);
        }
    }

    pop(arr);
}

int size(int *arr){
    return *arr;
}

int* at(int *arr, int index){
    if(index+1>*arr){
        printf("Out of bounds!\n");
        return NULL;
    }

    return arr+=index+1;
}

int* push(int *arr, int val){
    int len = *arr;
    arr = realloc(arr, sizeof(int)*(*arr+1));
    if(arr == NULL){
        printf("REALLOC ERROR!");
        return NULL;
    }

    *arr = len+1;
    int *temp = arr;
    temp += len+1;
    *temp = val;
    return arr;
}

int* insert(int *arr, int index, int val){
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

    return arr;
}

int* pop(int *arr){
    int len = *arr;
    int *temp = arr;
    temp += len;
    int val = *temp;

    arr = realloc(arr, sizeof(int)*(*arr-1));
    if(arr == NULL){
        printf("REALLOC ERROR!");
        return NULL;
    }

    *arr = len-1;

    return arr;
}