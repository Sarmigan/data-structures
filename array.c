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
    if(arr == NULL){
        printf("MALLOC ERROR!");
        return -1;
    }
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

//REMOVE TMP AND REPLACE WITH PTR
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

    int *tmp = *ptr+1;
    tmp += index;
    for(int i=index; i<len; i++){
        val = prev;
        prev = *tmp;
        *tmp = val;
        tmp++;
    }

    **ptr = len;

    return *ptr;
}

int* delete(int **ptr, int index){
    int len = **ptr;
    int *tmp = *ptr;
    int prev;
    int curr;

    if(len<1){
        printf("ARRAY EMPTY!\n");
        return NULL;
    }

    tmp += len;
    prev = *tmp;
    tmp--;
    for(int i=len-index-1; i>0; i--){
        curr = *tmp;
        *tmp = prev;
        prev = curr;
        tmp--;
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
    int *tmp = *ptr + 1;

    if(len<1){
        printf("ARRAY EMPTY!\n");
        return NULL;
    }

    for(int i=0; i<len; i++){
        if(*tmp == val){
            delete(ptr, i);
            i--;
            len = **ptr;
            tmp = *ptr + i + 2;
        } else{
            tmp++;
        }
    }

    return *ptr;
}