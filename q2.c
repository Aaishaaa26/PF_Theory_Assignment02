#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void customer_Info(char name[], long long *cnic);
void display(char productCode[][4], int quantityInStock[], float price[]);
void add_Item(char productCode[][4], int quantityInStock[], float price[], float *amount);
void displayBill(float *amount, float *newAmount);
void showInvoice(char name[], long long cnic, float newAmount, float amount);

int main(){
	char productCode[][4] = {"001", "002", "003", "004"};
    int quantityInStock[] = {50, 10, 20, 8,};
    float price[] = {100, 200, 300, 150 };
    int index ;
    float amount = 0, newAmount;
    char name[25];
    long long cnic;
    int menu;
    customer_Info(name, &cnic);
    printf("\n|------Supermarket Menu------|\n");
    do{
        printf("\n1: Display Inventory\n");
        printf("2: Add Item to Cart\n");
        printf("3: Display Total Bill\n");
        printf("4. Show Invoice\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
      scanf("%d", &menu);
        switch (menu){        
            case 1:
                display(productCode, quantityInStock, price);
                break;
            case 2:
                add_Item(productCode, quantityInStock, price, &amount);
                break;
            case 3:
                    displayBill(&amount, &newAmount);
                break;
            case 4:
                showInvoice(name, cnic, newAmount, amount);
                break;
            case 5:
                printf("Exiting!!\n");
                break;        
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (menu != 5);
}

void customer_Info(char name[], long long *cnic){
	char cnic_str[25];
	printf("\nEnter Customer Name: ");
	getchar();
	fgets(name,25,stdin);
	name[strcspn(name,"\n")] ='\0';
	    while (1) {
		printf("Enter a valid 13-digit CNIC number: ");
        fgets(cnic_str, 25 , stdin);
        cnic_str[strcspn(cnic_str, "\r\n")] = '\0';
		if (strlen(cnic_str) != 13){
            printf("CNIC must be exactly 13 digits.\n");
            continue;
        }
        int valid = 1;
        for (int i = 0; i < 13; i++) {
            if (!isdigit((unsigned char)cnic_str[i])) {
                valid = 0;
                break;
            }
        }
        if (!valid){
            printf("CNIC must contain digits only\n");
            continue;
        }
        *cnic = strtoll(cnic_str, NULL, 10);
        break;
    }
	printf("Customer information saved successfully\n");
}

void display(char productCode[][4], int quantityInStock[], float price[]){
	printf("%-15s %-20s %-10s\n","Product Code", "Quantity in stock", "Price per product");
	for(int j = 0; j < 4; j++){
		printf("%-15s %-20d %-10.2f\n",productCode[j], quantityInStock[j], price[j]);
	}
}
void add_Item(char productCode[][4], int quantityInStock[], float price[], float *amount){
	char code[5];
	int quantity;
	int codeCheck =0;
	printf("Enter product code: ");
        scanf("%3s", code);
        fflush(stdin);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        for(int i =0; i < 4; i++){
        	if(strcmp(code,productCode[i]) == 0 ){
        		codeCheck = 1;
        		if(quantityInStock[i] < quantity ){
        			printf("Not Enough in stock\n");
        			return;
				}
				else{
					quantityInStock[i] = quantityInStock[i] - quantity;
					*amount= *amount + price[i]*quantity;
					
				}
			}
		}
	    if(!codeCheck){
				printf("Invalid Code\n");
			}
}

void displayBill(float *amount, float *newAmount){
	*newAmount = *amount;
	char discountCode[9] = "Eid2025", promoCode[20];
	printf("Enter Promo Code: ");
	scanf("%s", promoCode);
	fflush(stdin);
	if(strcmp(discountCode,promoCode) == 0 ){
		printf("You have recieved 25%% discount\n");
		*newAmount = (*amount) * 0.75;
	}
	printf("Your total bill is %.2f\n", *newAmount);
}

void showInvoice(char name[], long long cnic, float newAmount, float amount){
	printf("______________________________Bill_________________________________\n");
	printf("Customer Name: %s\n",name);
	printf("Customer CNIC: %lld\n", cnic);
	printf("Original Amount: %.2f\n", amount);
	printf("Amount after discount (if any applied): %.2f\n",newAmount);
}