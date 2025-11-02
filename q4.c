#include <stdio.h>

#define MAXSIZE 15

void push(int stack[], int *top, int maxSize);
void pop(int stack[], int *top);
void peek(int stack[], int *top);
void display(int stack[], int *top);

int main(){
	int stack[MAXSIZE] = {0};
	int  top = -1; //Top Of Stack
	int choice;
	
	printf("----------------------------------------------------------STACK---------------------------------------------------------\n");
	do{
		
	printf("\n\t\t\t\t\t\t________Main Menu_________\n");
	printf("\nEnter a choice\n");
	printf("1: PUSH\n");
	printf("2: POP\n");
	printf("3: PEEK\n");
	printf("4: DISPLAY\n");
	printf("5: EXIT\n");
	scanf("%d", & choice);
	
	switch(choice){
		case 1: push(stack, &top, MAXSIZE); break;
		case 2: pop(stack, &top); break;
		case 3: peek(stack, &top); break;
		case 4: display(stack, &top); break;
		case 5: printf("Exiting Program\n"); break;
		default: printf("Invalid Choice\n");
	}
	
	}while(choice != 5);
}

void push(int stack[], int *top, int maxSize){
	int value;
	if(*top == maxSize - 1){
		printf("\nStack Is Full\n");
		return;
	}
	else{
		printf("Enter A Value To Be Pushed\n");
		scanf("%d", &value);
	    ++*top;
		stack[*top] = value;
		printf("Element Pushed Successfully\n");
	}
}

void pop(int stack[], int *top){
	if(*top == -1){
		printf("Stack is Empty\n");
	}
	else{
	    printf("Element %d Popped Succeddfully\n", stack[*top]);
		stack[*top] = 0;
		--*top;	
	}
}

void peek(int stack[], int *top){
	if(*top != -1){
		printf("Your top element is %d\n", stack[*top]);
	}
	else{
		printf("Nothing to peek :D since stack is empty\n");
	}
}

void display(int stack[], int *top){
	int i = *top;
	if (i == -1){
	    printf("Stack is Empty, No elements to show\n");
		return;
	}
	printf("\nDisplay of Elements in Stack\n");
	while( i!= -1){
		printf("%d\n", stack[i]);
		--i;
	}
}