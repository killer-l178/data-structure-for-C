#include <stdio.h>
#include <stdlib.h>
#define maxSize 10
#define True 1
#define False -1

struct Stack {
    int data[maxSize];
    int top;
};

// ³õÊ¼»¯Õ»
void initStack(struct Stack *s) {
    s->top = -1;
}

// ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
int stackEmpty(struct Stack * s){
	return (s->top == -1);
} 

// ½øÕ»
int push(struct Stack *s, int e) {
    if (s->top == maxSize - 1) {
		printf("Õ»Âú£¡"); 
		exit(1);	
    }

    s->top++;
    s->data[s->top] = e;

    return True;
}

// ´òÓ¡Õ»ÐòÁÐ
void printStack(struct Stack *s) {
    int cnt = s->top;
    while (cnt > -1) {
        printf("%d-->", s->data[cnt]);
        cnt--;
    }
    printf("NULL\n");
}

// ³öÕ»
int pop(struct Stack * s){
	// sÎª¿Õ½øÈëÅÐ¶ÏÓï¾ä 
	if(stackEmpty(s)){
		printf("Õ»Îª¿Õ£¡"); 
		exit(1);
	}
	return s->data[s->top--]; 
} 

// È¡Õ»¶¥ÔªËØ
int getTop(struct Stack * s){
	// Õ»Îª¿Õ ½øÈë¸ÃÅÐ¶ÏÓï¾ä 
	if(stackEmpty(s)){
		printf("Õ»Îª¿Õ£¡"); 
		exit(1);
	}
	return s->data[s->top]; 
}


int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
	
	int topData = getTop(&stack);
	printf("%d\n", topData);
	pop(&stack);
	
    printStack(&stack);

    return 0;
}
