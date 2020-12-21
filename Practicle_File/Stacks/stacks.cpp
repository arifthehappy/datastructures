#include <iostream>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

// A structure to represent a stack
typedef struct stacktype
{
    int top;
    unsigned capacity;
    int *array;
} Stack;

Stack *createStack(unsigned capacity);
int isEmpty(Stack *stack);
//1. Insert elements in stack
void push(Stack *, int);
//2. delete from stack
int pop(Stack *stack);
//3. Delete from start in stack
int peek(Stack *stack);

/*
*****************Main Driver*****************
*/
int main(int argc, char *argv[])
{
    int option = 0;
    Stack *stack = createStack(100);
    char exp[] = " a + b * (c ^ d - e) ^ (f + g * h) - i ";
    while (option != 4)
    {
        cout << "\n******************\nChoose an option:\n---------------\n 1. Insert elements in stack\n 2. delete element in stack\n 3. show top of stack\n 4. Exit\n";
        cin >> option;
        int val = 0;
        switch (option)
        {
        case 1:
            //1. Insert element in stack
            int item;
            cout << "Enter item to push ";
            cin >> item;
            push(stack, item);
            break;
        case 2:
            //2. Delete element in satck
            pop(stack);
            break;
        case 3:
            //3. Insert at end in array
            val = peek(stack);
            cout << "Top contains " << val << endl;
            break;
        case 4:
            //exit
            free(stack);
            return 0;
            break;
        default:
            cout << "Choose from given option";
            break;
        }
    }
}

// function to create a stack of given capacity
Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    cout << "\n stack created \n";
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("\n%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pop(Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    cout << "popped item " << stack->array[stack->top] << endl;
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}