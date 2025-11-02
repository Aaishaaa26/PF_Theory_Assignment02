#include <stdio.h>
#include <string.h>
void reverse(char message[]);
void toggle(char message[]);
void encodeMessage(char message[]);
void decodeMessage(char message[]);

int main(){
	char message[50];
	int choice;
	printf("-----------------------------------------------Encrypt & Decrypt Program------------------------------------------------\n");
	do{
		printf("\n\t\t\t\t\t_________Main Menu________\n");
		printf("1: Encode Message\n");
		printf("2: Decode Message\n");
		printf("3: Exit Program\n");
		scanf(" %d", & choice);
		getchar();
		switch(choice){
			case 1: encodeMessage(message); break;
			case 2: decodeMessage(message); break;
			case 3 : printf("\nExiting Program\n"); break;
			default: printf("\nInvalid Choice");
		}
	}while(choice!=3);
}

void toggle(char message[]){
	int length = strlen(message);
	for(int i = 0; i < length ; i++){
		message[i] = message[i] ^ 36;
	}
}

void reverse(char message[]){
	int length = strlen(message);
	int j = 0;
	char temp[50];
	--length;
	for(int i = length; i >= 0; i--){
		temp[j] = message[i];
		j++;
	}

	temp[j] ='\0';
	strcpy(message,temp);
}

void encodeMessage(char message[]){
	printf("\nEnter Message To Be Encoded: ");
	fgets(message, 50, stdin);
    message[strcspn(message, "\n")] = '\0';
	reverse(message);
	toggle(message);
	printf("Your Encoded Message is: %s", message);
}

void decodeMessage(char message[]){
	printf("\nEnter Message To Be Decoded: ");
	fgets(message, 50, stdin);
    message[strcspn(message, "\n")] = '\0';
	toggle(message);
	reverse(message);
	printf("Your Decoded Message is: %s", message);
}