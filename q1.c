#include <stdio.h>
#include <string.h>
void addBook(long int isbns[], char titles[][50], float prices[], int quantities[], int *i);
void processSale(long int isbns[], int quantities[], int *i);
void lowStock(long int isbns[], char titles[][50], float prices[], int quantities[], int *i);
int main(){
    long int isbns[100];
    char titles[100][50];
    float prices[100]; 	
	int quantities[100], i=0, menu;
	    do
    {
        printf("\n\t\t\t\t\t---Liberty Books Inventory System---\n");
        printf("1: Add New Book\n");
        printf("2: Process a Sale\n");
        printf("3: Generate Low-Stock Report\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", & menu);
        fflush(stdin);

        switch (menu) {
            case 1:
                addBook(isbns, titles, prices, quantities, &i);
                break;
            case 2:
                processSale(isbns, quantities, &i);
                break;
            case 3:
                lowStock(isbns, titles, prices, quantities, &i);
                break;
            case 4:
                printf("End Program\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (menu != 4 && i < 100);
    
    return 0;
}

void addBook(long int isbns[], char titles[][50], float prices[], int quantities[], int *i){
	long int newIsbn;
	printf("Enter Isbn Number: ");
	scanf("%ld", & newIsbn);
	fflush(stdin);
	for(int j = 0; j < *i; j++){
		if(isbns[j] == newIsbn){
			printf("Error! This isbn number already exists");
			return;
		}
	}
	isbns[*i]= newIsbn;
	printf("Enter title: ");
	getchar();
	fgets(titles[*i], 50, stdin);
	titles[*i][strcspn(titles[*i],"\n")] = '\0';
	printf("Enter book price: ");
    scanf("%f", &prices[*i]);
    fflush(stdin);
    printf("Enter stock quantity: ");
    scanf("%d", &quantities[*i]);
    fflush(stdin);
    (*i)++;
    printf("Book Added Successfully\n");
}
void processSale(long int isbns[], int quantities[], int *i){
	long int checkIsbn;
	int sold, j=0, flag = 0;
	if (*i == 0){
		printf("No Book Data available\n");
	}
	else{
		printf("Enter Isbn Number: ");
		scanf("%ld", & checkIsbn);
		fflush(stdin);
		do{
			if(isbns[j] == checkIsbn){
				printf("Enter Number of copies sold: ");
				scanf("%d",& sold);
				if (sold > quantities[j]) {
                    printf("Not enough stock!\n");
                } 
				else{
                    quantities[j] -= sold;
                    printf("Sale processed successfully!\n");
					flag = 1;
                }
					
			}
			++j;
		}while(j < (*i) && flag != 1 );	
	}
}
void lowStock(long int isbns[], char titles[][50], float prices[], int quantities[], int *i){
	if(*i > 0){
       printf("Details of all books where the quantity has fallen below 5\n");
	   for(int j = 0; j < *i; j++ ){
	     	if( quantities[j] <= 5){
	     		printf("Isbn: %ld\n", isbns[j]);
	     		printf("Title: %s\n", titles[j]);
	     		printf("Price: %.2f\n", prices[j]);
	     		printf("Quantitiy: %d\n", quantities[j]);
			 }
	    }
    }  
}