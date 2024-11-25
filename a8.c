#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct Block {
    char label;
    int width;
    int height;
    struct Block *left;
    struct Block *right;
};

struct array_stack {
    int* arr;
    int size;
    int top; // initial value = -1
};


int count; 
int c;
struct Block* arr;
int i;
char* buffer[20];

void push(struct array_stack* stack, int value)
{
    if ((stack->top + 1) == stack->size)
    {
        int new_size = stack->size * 2; //why not increasing by a fixed size?
        int* new_arr = (int*)realloc(stack->arr, new_size * sizeof(int));
        assert(new_arr != NULL);
        stack->arr = new_arr;
        stack->size = new_size;
    }
    stack->arr[++stack->top] = value;
} 

int pop(struct list_stack* stack)
{
    assert(!is_empty(*(stack->list)));
    int value = stack->list->head->value;
    delete_head(stack->list);
    return value;
}



buildTree() {
    FILE* fp;
    fp = fopen(argv[1], "r");

    if(fp == NULL){
        printf("Error Opening File\n");
        return 0;
    }

    i = 0;
    char* delim = "(,)";
    char* token;

    struct array_stack stack;
    stack.top = -1;
    stack.size = 8;
    stack.arr = (int *)malloc(8 * sizeof(int));

    while(i <= count){
        
        fgets(buffer, 20, fp);
        token = strtok(buffer, delim);
        if(token != 'H' && token != 'V'){
            struct Block* new = malloc(sizeof(struct Block));
            new -> label = token;
            token = strtok(buffer, delim);
            new -> width = token;
            token = strtok(buffer, delim);
            new -> height = token;
            push(&stack, new);
        }
        else{}
        
    }
}

preOrder() {

}

int main(int argc, char* argv[]) {

    FILE* fp;
    fp = fopen(argv[1], "r");

    if(fp == NULL){
        printf("Error Opening File\n");
        return 0;
    }
    count = 0;
    for (c = fgetc(fp); c != EOF; c = fgetc(fp)){
        if(c =='\n'){
            count = count + 1;
        }
    }
    fclose(fp);

    buildTree
    //arr = malloc(sizeof(struct Block)*count);
}