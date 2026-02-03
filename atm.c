/*atm simulation system*/
#include<stdio.h>
#include<stdlib.h>
void deposit() //deposit function
{	
	int balance;
	FILE *fp;
	int amount;
	char choice;
	int oldbalance=0;

	printf("\nEnter the amount:");
	scanf(" %d", &amount);
	if(amount<100)
	{
		printf("\nAmount can't be deposited\n");
		exit(0);
	}

	printf("\nConfirm by entering Yes(Y) or No(N)\n");
	scanf(" %c", &choice);

       if(choice=='Y'||choice=='y')
       {
	        fp=fopen("balance.txt", "r");
		if(fp!=NULL)
		{
			fscanf(fp,"%d",&oldbalance);
			fclose(fp);
		}
		balance=oldbalance+amount;
		fp=fopen("balance.txt", "w");
		fprintf(fp,"%d", balance);
		fclose(fp);
		printf("\nAmount deposited successfully\n");
		
       }
       else
       {
		printf("\nYou choosed No transaction cancelled\n");
	}
}
void withdraw()
{
        FILE *fp;
       	int amount;
        char choice;
	int balance;
        printf("\nEnter the amount:");
        scanf(" %d", &amount);
        if(amount<100)
        {
                printf("\nAmount cant be withdrawn");
                exit(0);
        }
        printf("\nConfirm to withdraw %d rs? Yes(Y) or No(N):", amount);
        scanf(" %c", &choice);
        if(choice=='Y'||choice=='y')
        {
                fp=fopen("balance.txt","r");
		fscanf(fp,"%d", &balance);
		fclose(fp);
		if(amount>balance)
		{
			printf("\nInsufficient Balance\n");
			exit(1);
		}
		else if(amount<=balance)
		{
		fp=fopen("balance.txt", "w");
		balance=balance-amount;
		fprintf(fp,"%d",balance);
		fclose(fp);
		printf("\nprocessing...\n");
                printf("\nAmount withdrawn succesfully\n");
        }
}
        else
        {
                printf("\nYou choose No(N) transaction cancelled");
        }
}
void check_balance()
{
	int balance;
	FILE *fp;
	fp=fopen("balance.txt","r");
	fscanf(fp,"%d",&balance);
	printf("\nYour balance is %d\n", balance);
	fclose(fp);
}
int main()
{	
	int choice;
	int n;
	printf("--Welcome to SBI ATM--\n");
	printf("Please enter your card PIN\n");
	scanf(" %d",&n);
	if(n!=1234)
	{
		printf("Sorry Invalid PIN\n");
		exit(1);
	}
	do{
		printf("\n--Welcome to SBI ATM--\n");
		printf("1.Deposit Money\n");
		printf("2.Withdraw money\n");
		printf("3.Check Balance\n");
		printf("4.Exit\n");
		printf("Enter choice:");
		scanf(" %d", &choice);

		switch(choice)
		{
			case 1:deposit();
			       break;
			case 2:withdraw();
			       break;
			case 3:check_balance();
			       break;
			case 4:printf("Thank you for banking with SBI..\n");
			       exit(1);
			default:printf("Invalid choice!\n");
		}
	}while(choice!=4);
}

