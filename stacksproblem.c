#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int mainStack[MAX], minStack[MAX];
int topMain = -1, topMin = -1;


void push(int x) {
    if (topMain == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    mainStack[++topMain] = x;

   
    if (topMin == -1 || x <= minStack[topMin]) {
        minStack[++topMin] = x;
    }

    printf("Pushed %d\n", x);
}


void pop() {
    if (topMain == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    int removed = mainStack[topMain--];

    
    if (removed == minStack[topMin]) {
        topMin--;
    }

    printf("Popped %d\n", removed);
}


int top() {
    if (topMain == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return mainStack[topMain];
}


int getMin() {
    if (topMin == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return minStack[topMin];
}

int main() {
    push(-2);
    push(0);
    push(-3);

    printf("Current Minimum: %d\n", getMin()); 
    pop();
    printf("Top Element: %d\n", top());        
    printf("Current Minimum: %d\n", getMin()); 

    return 0;
}
\