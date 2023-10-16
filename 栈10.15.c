#include <stdio.h>
#include <stdlib.h>
#define maxSize 10
#define True 1
#define False -1

struct Stack {
    int data[maxSize];
    int top;
};

// ��ʼ��ջ
void initStack(struct Stack *s) {
    s->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int stackEmpty(struct Stack * s){
	return (s->top == -1);
} 

// ��ջ
int push(struct Stack *s, int e) {
    if (s->top == maxSize - 1) {
		printf("ջ����"); 
		exit(1);	
    }

    s->top++;
    s->data[s->top] = e;

    return True;
}

// ��ӡջ����
void printStack(struct Stack *s) {
    int cnt = s->top;
    while (cnt > -1) {
        printf("%d-->", s->data[cnt]);
        cnt--;
    }
    printf("NULL\n");
}

// ��ջ
int pop(struct Stack * s){
	// sΪ�ս����ж���� 
	if(stackEmpty(s)){
		printf("ջΪ�գ�"); 
		exit(1);
	}
	return s->data[s->top--]; 
} 

// ȡջ��Ԫ��
int getTop(struct Stack * s){
	// ջΪ�� ������ж���� 
	if(stackEmpty(s)){
		printf("ջΪ�գ�"); 
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
