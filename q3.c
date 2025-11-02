#include <stdio.h>

void update(int grid[7][7]);
void query(int grid[7][7]);
void diagnostic(int grid[7][7]);

int main(){
	int grid[7][7]={0};
	int choice;
	printf("------------Power Grid Monitoring System------------");
	do{
		printf("\n---------Main Menu-----------\n");
		printf("1: Update Sector Status\n");
		printf("2: Query Sector Status\n");
		printf("3: Run System Diagnostic\n");
		printf("4: Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
			    update(grid);
			    break;
			case 2: 
			    query(grid);
			    break;
			case 3:    
			    diagnostic(grid);
			    break;
			case 4:    
			    printf("\n----Exiting Program-----\n");
			    break;
			default:    
				printf("\nInvalid Choice\n");       			
		}
	}while(choice != 4);
}

void update(int grid[7][7]){
	int col, row, status;
	printf("Enter Row  Number 0-7: ");
	scanf("%d", &row);
	if(row > 7 || row < 0){
		printf("Invalid Row Number\n");
		return;
	}
	printf("Enter Column  Number 0-7: ");
	scanf("%d", &col);
	if(col > 7 || col < 0){
		printf("Invalid Column Number\n");
		return;
	}
	printf("Enter Status Number 0-7 : ");
	scanf("%d",&status);
	if(status > 7 || status < 0){
		printf("Invalid Status Number\n");
		return;
	}
	else{
		grid[row][col]= status;
		printf("\nStatus Updated Successfully\n");
	}
}

void query(int grid[7][7]){
	int col, row, sector;
	printf("Enter Row  Number 0-7: ");
	scanf("%d", &row);
	if(row > 7 || row < 0){
		printf("Invalid Row Number\n");
		return;
	}
	printf("Enter Column  Number 0-7: ");
	scanf("%d", &col);
	if(col > 7 || col < 0){
		printf("Invalid Column Number\n");
		return;
	}
	sector = grid[row][col];
	printf("\nSector status\n");
	if(sector & 1){
		printf("Power Status: ON\n");
	}
	else{
			printf("Power Status: OFF\n");
	}
	if(sector & 2){
		printf("Overload Warning: Overloaded\n");
	}
	else{
		printf("Overload Warning: Normal\n");
	}
	if(sector & 4){
		printf("Maintenance Required: Yes\n");
	}
	else{
		printf("Maintenance Required: No\n");
	}
}

void diagnostic(int grid[7][7]){
	printf("\nDiagnostic Report\n");
	int sector, loaded = 0, maintenance = 0;
	for(int row = 0; row < 7; row++){
		for(int col = 0; col < 7; col++){
			sector = grid[row][col];
				if(sector & 2){
					++loaded;
				}
				if(sector & 4){
					++maintenance;
				}
		}
	}
	printf("Total %d sector(s) overloaded\n", loaded);
	printf("Total %d sector(s) require maintenace\n", maintenance);
}