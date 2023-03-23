#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>

struct a{
	char usrname[20];
	char passwd[20];
}e;

struct b{
	float sale[31];
}s1, s2, s3;

void delay(float seconds) {  //delay function 
    int milliSeconds = 1000*seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milliSeconds);
}

float jam(){  //show current time
	time_t rawtime;
	struct tm *timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);

	printf ("\t\t\t\t\t\t\t\t\t\t\t\tTime : %d/%d/%d %02d:%02d", timeinfo->tm_mday, timeinfo->tm_mon+1, timeinfo->tm_year+1900, timeinfo->tm_hour, timeinfo->tm_min);
}

void cls(){
	system("cls");  // clear screen function
}

void load(){
	int i;
	float j=0.8;
	printf("\n\n\n\n\t\t\t\t\t\t\t\t Loading...");
	printf("\n\t\t\t\t\t\t\t  ");
	delay(1);
	for(i=0;i<24;i++){
		printf("%c",223); //ASCII code for loading...
		delay(j);
		if(i%4==0)
			j-=0.20;
	}
	delay(1);
	cls();
}

//function prototype
int admin();
int staff();
void view_stock();
void update_stock();
void salesstaff01();
void salesstaff02();
void salesstaff03();
void viewsalesadmin();
void updatesales();
void updatestock();
void worktime();
void counter();
void bill(char[],float,int);
void receipt(float);
void viewsalestaff();

//variable and array declaration 
int array_qitem[] = {
	0,50,50,50,50,50,50,50,50,50,50,
	50,50,50,50,50,50,50,50,50,50,0
	};

float array_pritem[] = {
	0,5,2,2,2,3,3,0.5,20,20,
	20,20,4,2,7,10,15,4,4,4,4,0
	};

char array_item[][20] ={
	{"0"},{"Hammer"},{"Box of screw"},{"Box of nail"},{"Roll of Duct Tape"},{"1m of copper wire"},
	{"Pack of AAA Battery"},{"A4 size sandpaper"},{"Can of blue paint"},{"Can of red paint"},
	{"Can of yellow paint"},{"Can of white paint"},{"Big brush"},{"Small brush"},{"Can of thinner"},
	{"Handsaw"},{"Electrical drill"},{"Flat screwdriver"},{"Phillip screwdriver"},{"Pack of sponge"},{"Plier"}
	};

int array_itemcall[21];
int array_quantity[21];
float array_staff[4];
float total_sales[4];
float array_time[4];
float array_salary[4];
float array_total[50];

int choice,quantitis,i,y;
int s_1=0;
int s_2=0;
int s_3=0;

char pass;
int ret=0;

time_t start, end;
float workingTime;

int main(){				//main function 
    int choices;
    if(ret==-1)
    	goto XX;

    system("color 3F");		//system color function-change color to aqua blue
    printf("\n\n\t\t\t\t\t\t\t\tPrepared by: \n\t\t\t\t\t\t1. Dzakirin\t2. Aniq Aqil\t3. Nuzul Irfan\n\t\t\t\t\t\t\t4. Harith\t5. Aiman Danial\n");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t     ------------------RYZEN HARDWARE-------------------\n\n\n\n\n");

    load();
    XX:		//mark for goto function
	printf("RYZEN HARDWARE\t\t");
    jam();
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLogin as:\n");
    printf("\t\t\t\t\t\t\t\t 1. Admin\n\t\t\t\t\t\t\t\t 2. Staff\n\t\t\t\t\t\t\t\t 3. Exit\n");
    printf("\t\t\t\t\t\t\t>>: ");
    scanf("%d", &choices);

    switch (choices){
    case 1:
        cls();
        login_admin();
        if(-1)
        	goto XX;
        break;
    case 2:
        cls();
        login_staff();
        if(-1)
        	goto XX;
        break;
    case 3:
    	cls();
 		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   *******  *     *   *****   **   *  *   *        *     *   ****   *    *\n");
  		printf("\t\t\t\t      *     *     *  *     *  * *  *  *  *          *   *   *    *  *    *\n");
  		printf("\t\t\t\t      *     *******  *******  *  * *  **              *     *    *  *    *\n");
  		printf("\t\t\t\t      *     *     *  *     *  *   **  *  *            *     *    *  *    *\n");
   		printf("\t\t\t\t      *     *     *  *     *  *    *  *   *           *      ****    **** \n\n\n");
   		printf("\n\n\n\n");
   		for(i=0;i<143;i++)
   			printf("-");
   		printf("\nExiting...");
   		delay(3);
   		exit(0);
        break;
    default:
    	cls();
		main();
    }
    return 0;
}

int login_admin(){		//admin login
	FILE *q;

	q = fopen("log.txt", "r");	//open username and password file

    char usrnm_admin_input[20], passwd_admin_input[20];
    int x=0, i, j=0, k;
	
	printf("RYZEN HARDWARE\t\t");
	jam();
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tADMIN :-\n");
    printf("\t\t\t\t\t\t\t\tUsername >>: ");
    scanf(" %s", &usrnm_admin_input);
    printf("\t\t\t\t\t\t\t\tPassword >>: ");
    for(i=0;;){		//show password as star(*)
        pass=getch();
        if((pass>='a' && pass<='z')||(pass>='A' && pass<='Z')||(pass>='0' && pass<='9')){
            passwd_admin_input[i]=pass;
            ++i;
            printf("*");
        }
        if(pass=='\b' && pass>=1){
            printf("\b \b");
            --i;
            if(i=0)
            	break;
        }
        if(pass=='\r'){
        	passwd_admin_input[i]='\0';
            break;
        }
    }

	while(j<3){
		k=j*46;
		fseek(q, k, SEEK_SET);	//seek line by line in txt file

		fscanf(q, "%s", e.usrname);
    	fscanf(q, "%s", e.passwd);

    	if(j==0){
			if(strcmp(usrnm_admin_input, e.usrname)==0 && strcmp(passwd_admin_input, e.passwd)==0){
    			cls();
        		admin(e.usrname);
        		break;
    		}
    	}
    	else{
    		printf("\n\t\t\t\t\t\t\tInvalid username or password!\n");
    		delay(2);
    		cls();
    		return -1;
    	}
    	j++;
    }
}

int login_staff(){		//staff login
	FILE *q;

	q = fopen("log.txt", "r");

    char usrnm_staff_input[20], passwd_staff_input[20];
    int x=0, i, j=1, k, y;

	printf("RYZEN HARDWARE\t\t");
	jam();
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSTAFF :-\n");
    printf("\t\t\t\t\t\t\t\tUsername >>: ");
    scanf(" %s", &usrnm_staff_input);
    printf("\t\t\t\t\t\t\t\tPassword >>: ");
    for(i=0;;){
        pass=getch();
        if((pass>='a' && pass<='z')||(pass>='A' && pass<='Z')||(pass>='0' && pass<='9')){
            passwd_staff_input[i]=pass;
            ++i;
            printf("*");
        }
        if(pass=='\b' && pass>=1){
            printf("\b \b");
            --i;
        }
        if(pass=='\r'){
        	passwd_staff_input[i]='\0';
            break;
        }
    }

    while(j<6){
		k=j*46;
		fseek(q, k, SEEK_SET);

		fscanf(q, "%s", e.usrname);
    	fscanf(q, "%s", e.passwd);

		if(j<5){
    		if(strcmp(usrnm_staff_input, e.usrname)==0 && strcmp(passwd_staff_input, e.passwd)==0){
    			cls();
    			if(strcmp(passwd_staff_input, "stafpertama")==0){
    				array_staff[1]=1;
				}
				if(strcmp(passwd_staff_input, "stafkedua")==0){
    				array_staff[2]=1;
				}
				if(strcmp(passwd_staff_input, "stafketiga")==0){
    				array_staff[3]=1;
				}
        		staff();
        		break;
    		}
    	}
    	else if(j==5){
    		printf("\n\t\t\t\t\t\t\tInvalid username or password!\n");
    		delay(2);
    		cls();
    		return -1;
    	}
    	j++;
    }
}

int admin(){			//admin menu 
	int choice;
	float workingTime;

	printf("RYZEN PRO CSC\t\t");
	jam();
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWelcome Admin!\n");
    printf("\t\t\t\t\t\t\t\t 1. View Stock\n\t\t\t\t\t\t\t\t 2. Update Stock\n\t\t\t\t\t\t\t\t 3. View Staff's Working Time\n\t\t\t\t\t\t\t\t");
	printf(" 4. View Sales\n\t\t\t\t\t\t\t\t 5. Update Sales\n\t\t\t\t\t\t\t\t 6. Log Out\n");
    printf("\t\t\t\t\t\t\t>>: ");
    scanf("%d", &choice);

    switch (choice){
    case 1:
        cls();
        view_stock();
        admin();
        break;
    case 2:
        cls();
        update_stock();
        break;
    case 3:
        cls();
        worktime();
        break;
    case 4:
        cls();
        viewsalesadmin();
        break;
    case 5:
        cls();
        updatesales();
        break;
    case 6:
        cls();
        ret=-1;
        main();
        break;
    default:
    	printf("\n\t\t\t\t\t\t\tInvalid Input! Re-enter");
    	delay(3);
    	cls();
    	admin();
    }
}

void view_stock(){		//view stock function
	int choice_viewstock;
	printf("RYZEN HARDWARE\t\t");
	jam();
	printf("\n\n\t\t\t\t\t\t\t\t   List of items\n\n");
	printf("\t\t\t\t\t\tName of item\t\t\tQuantity\tPrice\n\n");
	for(i=1;i<=20;i++){
		printf("\t\t\t\t\t\t%02d) %-25s\t%d\t\tRM%6.2f\n",i,array_item[i],array_qitem[i],array_pritem[i]);
	}
	printf("\n\n");
	for(i=0;i<143;i++)
		printf("-");
	printf("\nPress any key to return...");
	getch();
	cls();
}

void update_stock(){	//update stock function for admin
	int choice_updatestock,choose_item,addreduce,add,reduce;
	printf("RYZEN HARDWARE\t\t");
	jam();
	printf("\n\n\n\n\n\t\t\t\t\t\t\tList of items\n");	//print list of items
	for(i=1;i<=20;i++){
		printf("\t\t\t\t\t\t%02d) %-25s = %d\n",i,array_item[i],array_qitem[i]);
	}
	do{
	printf("\n\t\t\t\t\t\tChoose an item (1-20)(0 to return) >>:");	//asking user for an input
	scanf("%d",&choose_item);
	if(choose_item<0 || choose_item>20)
        printf("\t\t\t\t\t\t\tInvalid Input! Re-enter\n");
	}while(choose_item<0 || choose_item>20);	//loop if wrong input entered
	if(choose_item==0){
		cls();
		admin();
	}		
	printf("\t\t\t\t\t\t\t%s \n",array_item[choose_item]);	//
	do{
        printf("\t\t\t\t\t\tDo you want to add or reduce stock?\n\t\t\t\t\t\t\tADD(1)//REDUCE(0) >>:");
        scanf("%d",&addreduce);
        if(addreduce!=0 && addreduce!=1)
            printf("\t\t\t\t\t\t\tInvalid Input\n");
	}while(addreduce!=0 && addreduce!=1);

	if(addreduce==1){
		do{
			printf("\t\t\t\t\t\t   Enter amount to add by >>:");
			scanf("%d",&add);
			if(add<0){
				printf("\t\t\t\t\t\t\tInvalid input\n");
			}
		}while(add<0);
		array_qitem[choose_item]+=add;
	}
	else if(addreduce==0){
		do{
			printf("\t\t\t\t\t\t   Enter amount to reduce by >>:");
			scanf("%d",&reduce);
			if(reduce<0)
				printf("\t\t\t\t\t\t\tInvalid input! Re-enter\n");
			if(reduce>array_qitem[choose_item])
				printf("\t\t\t\t\t\t  Quantity entered exceed the quantity of item.\n");
		}while(reduce>array_qitem[choose_item] || reduce<0);
		array_qitem[choose_item]-=reduce;
	}
	cls();
	view_stock();
	admin();
}

void viewsalesadmin(){	//view sale function for admin
	int choose_staff;
	printf("RYZEN HARDWARE\t\t");
	jam();
	for(i=0;i<=3;i++){
		total_sales[i]=0;
	}
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t1)Sales for Staff 1\n\t\t\t\t\t\t\t\t2)Sales for Staff 2\n\t\t\t\t\t\t\t\t3)Sales for Staff 3\n\t\t\t\t\t\t\tChoose one option to view (1-3)(0 to return) >>:");
	scanf("%d",&choose_staff);
	switch (choose_staff){
    case 0: 
    	cls();
    	admin();
    	break;
	case 1:
        cls();
        salesstaff01();
		break;
    case 2:
        cls();
        salesstaff02();
        break;
    case 3:
        cls();
        salesstaff03();
        break;
    default:
    	printf("\n\t\t\t\t\t\t\tInvalid Input\n\t\t\t\t\t\t\tChoose number 1-3 only\n");
    	delay(3);
    	cls();
    	viewsalesadmin(); 	
	}
}

void salesstaff01(){	//sale for staff 01
	int choose_return;
	printf("RYZEN HARDWARE\t\t");
	jam();
	for(i=0;i<=3;i++){
		total_sales[i]=0;
	}
	printf("\n\n\n\n\n\n\n\n");
	for(i=0;i<=30;i++){
		if(s1.sale[i]!=0){
			printf("\t\t\t\t\t\t\t%d) RM%.2f \n",i+1,s1.sale[i]);
			total_sales[1]+=s1.sale[i];
		}
	}
	printf("\n\t\t\t\t\t\t\tTotal sales of Staff 1 is RM%.2f\n",total_sales[1]);
	printf("\t\t\t\t\t\t\tStaff 1 commission is RM%.2f (10%% of total sales)\n",total_sales[1]*0.1);
	for(i=0;i<143;i++)
		printf("-");
	printf("\nPress any key to return...");
	getch();
	cls();
	viewsalesadmin();
}

void salesstaff02(){	//sale for staff 02
	int choose_return;
	printf("RYZEN HARDWARE\t\t");
	jam();
	for(i=0;i<=3;i++){
		total_sales[i]=0;
	}
	printf("\n\n\n\n\n\n\n\n");
	for(i=0;i<=30;i++){
		if(s2.sale[i]!=0){
			printf("\t\t\t\t\t\t\t%d) RM%.2f \n",i+1,s2.sale[i]);
			total_sales[2]+=s2.sale[i];
		}
	}
	printf("\n\t\t\t\t\t\t\tTotal sales of Staff 2 is RM%.2f\n",total_sales[2]);
	printf("\t\t\t\t\t\t\tStaff 2 commission is RM%.2f (10%% of total sales)\n",total_sales[2]*0.1);
	for(i=0;i<143;i++)
		printf("-");
	printf("\nPress any key to return...");
	getch();
	cls();
	viewsalesadmin();
}

void salesstaff03(){	//sale for staff 03
	int choose_return;
	printf("RYZEN HARDWARE\t\t");
	jam();
	for(i=0;i<=3;i++){
		total_sales[i]=0;
	}
	printf("\n\n\n\n\n\n\n\n");
	for(i=0;i<=30;i++){
		if(s3.sale[i]!=0){
			printf("\t\t\t\t\t\t\t%d) RM%.2f \n",i+1,s3.sale[i]);
			total_sales[3]+=s3.sale[i];
		}
	}
	printf("\n\t\t\t\t\t\t\tTotal sales of Staff 3 is RM%.2f\n",total_sales[3]);
	printf("\t\t\t\t\t\t\tStaff 3 commission is RM%.2f (10%% of total sales)\n",total_sales[3]*0.1);
	for(i=0;i<143;i++)
		printf("-");
	printf("\nPress any key to return...");
	getch();
	cls();
	viewsalesadmin();
}

void updatesales(){		//update sales functon for admin
	int choose_staff,choose_return,choose_sale;
	float new_sale;
	printf("RYZEN HARDWARE\t\t");
	jam();
	for(i=0;i<=3;i++){
		total_sales[i]=0;
	}
	do{
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t1)Sales Staff 1\n\t\t\t\t\t\t\t\t2)Sales Staff 2\n\t\t\t\t\t\t\t\t3)Sales Staff 3\n\t\t\t\t\t\t\tChoose on option to view (1-3)(0 to return) >>:");
		scanf("%d",&choose_staff);
		if(choose_staff>3 || choose_staff<0){
			printf("\t\t\t\t\t\t\tInvalid Input! Re-enter\n");
			delay(3);
			cls();
		}	
	}while(choose_staff>3 || choose_staff<0);
	if(choose_staff==0){
		cls();
		admin();
	}
    if(choose_staff==1){
        cls();
        printf("\n\n\n\n\n\n");
        for(i=0;i<=30;i++){
			if(s1.sale[i]!=0){
				printf("\t\t\t\t\t\t\t%d) RM%.2f \n",i+1,s1.sale[i]);
				total_sales[1]+=s1.sale[i];
			}
		}
		printf("\n\t\t\t\t\t\t\tTotal sales of Staff 1 is RM%.2f\n",total_sales[1]);
		printf("\n\t\t\t\t\t\t\tChoose a sale to update value >>:");
		scanf("%d",&choose_sale);
		printf("\t\t\t\t\t\t\tEnter new value >>: RM");
		scanf("%f",&new_sale);
		s1.sale[choose_sale-1]=new_sale;
		cls();
		salesstaff01();
	}

	else if(choose_staff==2){
        cls();
        printf("\n\n\n\n\n\n");
        for(i=0;i<=30;i++){
			if(s2.sale[i]!=0){
				printf("\t\t\t\t\t\t\t%d) RM%.2f \n",i+1,s2.sale[i]);
				total_sales[2]+=s2.sale[i];
			}
		}
		printf("\n\t\t\t\t\t\t\tTotal sales of Staff 2 is RM%.2f\n",total_sales[2]);
		printf("\n\t\t\t\t\t\t\tChoose a sale to update value >>:");
		scanf("%d",&choose_sale);
		printf("\t\t\t\t\t\t\tEnter new value >>: RM");
		scanf("%f",&new_sale);
		s2.sale[choose_sale-1]=new_sale;
		cls();
		salesstaff02();
	}

	else if(choose_staff==3){
        cls();
        printf("\n\n\n\n\n\n");
        for(i=0;i<=30;i++){
			if(s3.sale[i]!=0){
				printf("\t\t\t\t\t\t\t%d) RM%.2f \n",i+1,s3.sale[i]);
				total_sales[3]+=s3.sale[i];
			}
		}
		printf("\n\t\t\t\t\t\t\tTotal sales of Staff 3 is RM%.2f\n",total_sales[3]);
		printf("\n\t\t\t\t\t\t\tChoose a sale to update value >>:");
		scanf("%d",&choose_sale);
		printf("\t\t\t\t\t\t\tEnter new value >>: RM");
		scanf("%f",&new_sale);
		s3.sale[choose_sale-1]=new_sale;
		cls();
		salesstaff03();
	}
	else{
		cls();
		admin();
	}
}

void worktime(){		//staff working time function 
	int choices;
	printf("RYZEN HARDWARE\t\t");
	jam();
	
	do{
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t1)Work time for Staff 1\n\t\t\t\t\t\t\t\t2)Work time for Staff 2\n\t\t\t\t\t\t\t\t3)Work time for Staff 3\n\t\t\t\t\t\t\tChoose one option to view (1-3)(0 to return) >>:");
		scanf("%d", &choices);
		if(choices>3 || choices<0){
			printf("\t\t\t\t\t\t\tInvalid Input! Re-enter\n");
			delay(3);
			cls();
		}	
	}while(choices>3 || choices<0);
	cls();
	if(choices==0)
		admin();
	if(choices==1){
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tStaff working time: %.2f minutes",array_time[1]);
	}
	else if(choices==2){
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tStaff working time: %.2f minutes",array_time[2]);
	}
	else if(choices==3){
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tStaff working time: %.2f minutes",array_time[3]);
	}
	delay(3);
	cls();
	worktime();
}

int staff(){			//staff menu
	int choice;
	printf("RYZEN HARDWARE\t\t");
	jam();
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWelcome Staff!\n");
    printf("\t\t\t\t\t\t\t\t 1. Punch In\n\t\t\t\t\t\t\t\t 2. Counter Registry\n\t\t\t\t\t\t\t\t 3. View Stock\n\t\t\t\t\t\t\t\t 4. View Sales\n\t\t\t\t\t\t\t\t");
	printf(" 5. Punch Out\n\t\t\t\t\t\t\t\t 6. View Salary\n\t\t\t\t\t\t\t\t 7. Log Out\n");
    printf("\t\t\t\t\t\t\t>>: ");
    scanf("%d", &choice);

    switch (choice){
    case 1:
        cls();
        punchIn();
        break;
    case 2:
        cls();
        counter();
        break;
    case 3:
        cls();
        view_stock();
        staff();
        break;
    case 4:
        cls();
        viewsalestaff();
        break;
    case 5:
        cls();
        punchOut();
        break;
    case 6:
        cls();
        salary();
        break;
    case 7:
    	if(start==0 && end==0)
    		goto YY;
    	if(end==0){
    		cls();
    		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tPunch out first!");
    		delay(3);
    		cls();
    		staff();
		}
    	start=0, end=0;
    	YY:
        cls();
        for(i=0;i<=3;i++){
        	array_staff[i]=0;
		}
        ret=-1;
        main();
        break;
    default:
    	printf("\n\t\t\t\t\t\t\tInvalid Input! Re-enter");
    	delay(3);
    	cls();
    	staff();
    }
}

int punchIn(){			//punch in function for staff
	char choice;
	printf("RYZEN HARDWARE\t\t");
	jam();
	if(start!=0){
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tYou are already punch in!!!\n");
		delay(4);
		cls();
		staff();
	}	
	do{
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t Punch In now? (Y-YES,N-No) >>: ");
		scanf(" %c",&choice);
		if(choice!='Y' && choice!='y' && choice!='N' && choice!='n'){
			printf("\n\t\t\t\t\t\t\tInvalid Input! Re-enter");
			delay(3);
			cls();
		}		
	}while(choice!='Y' && choice!='y' && choice!='N' && choice!='n');

	if(choice=='Y' || choice=='y'){
		start = time(NULL);
		cls();
		staff();
	}
	else if(choice=='N' || choice=='n'){
	    staff();
	}
}

int punchOut(){			//punch out function for staff
	char choice;
	printf("RYZEN HARDWARE\t\t");
	jam();
	if(start==0){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPunch in first!\n");
		delay(3);
		cls();
		staff();
	}
	do{
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t Punch Out now? (Y-YES,N-No) >>: ");
		scanf(" %c",&choice);
		if(choice!='Y' && choice!='y' && choice!='N' && choice!='n'){
			printf("\n\t\t\t\t\t\t\tInvalid Input! Re-enter");
			delay(3);
			cls();
		}			
	}while(choice!='Y' && choice!='y' && choice!='N' && choice!='n');

	if(choice=='Y' || choice=='y'){
		end = time(NULL);
		workingTime=difftime(end,start);
		workingTime/=60;
		start=0, end=0;
		
		if(array_staff[1]==1){
			array_time[1]=workingTime;
			array_salary[1]=workingTime*0.17;
		}
		else if(array_staff[2]==1){
			array_time[2]=workingTime;
			array_salary[2]=workingTime*0.17;
		}
		else if(array_staff[3]==1){
			array_time[3]=workingTime;
			array_salary[3]=workingTime*0.17;
		}
		
		cls();
		staff();
	}
	else if(choice=='N' || choice=='n'){
        cls();
	    staff();
	}
}

int salary(){			//staff view salary function
	printf("RYZEN HARDWARE\t\t");
	jam();
	for(i=1;i<4;i++){
		if(array_time[i]!=0)
			goto ZZ;
	}
	if(end==0){
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tMust punch out first before viewing salary\n");
		delay(4);
		cls();
		staff();
	}
	
	ZZ:
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tWorking hour is %.2f Minutes",workingTime);
	printf("\n\t\t\t\t\t\t\t\tSalary is RM%.2f ", workingTime*0.17);
	if(array_staff[1]==1){
		printf("\n\t\t\t\t\t\tYour commission is RM%.2f (10%% of total sales)",total_sales[1]*0.1);
	}
	else if(array_staff[2]==1){
		printf("\n\t\t\t\t\t\tYour commission is RM%.2f (10%% of total sales)",total_sales[2]*0.1);
	}
	else if(array_staff[3]==1){
		printf("\n\t\t\t\t\t\tYour commission is RM%.2f (10%% of total sales)",total_sales[3]*0.1);
	}

	delay(5);
	cls();
	staff();


}

void counter(){			//counter registry function
	float sales=0;
	if(start==0){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPunch in first!\n");
		delay(3);
		cls();
		staff();
	}
	for(i=0;i<=20;i++){
		array_itemcall[i]=0;
	}
	for(i=0;i!=-1;){
		cls();
		printf("RYZEN HARDWARE\t\t");
		jam();
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t   List of items\n");
		for(i=1;i<=10;i++){
			printf("\t\t\t\t\t%d) %-30s \t%d) %-30s \n",i,array_item[i],i+10,array_item[i+10]);
		}
		printf("\n");
		for(y=0;y<=20;y++){
			if(array_itemcall[y]==1){
				printf("\t\t\t\t\t\t\t%-20s (RM%5.2f)\tx%02d\n",array_item[y],array_pritem[y],array_quantity[y]);
			}
		}
		do{
			do{
				printf("\n\t\t\t\t\t\tEnter item (-1 to finish || 0 to restart) :>> ");
				scanf("%d",&choice);
				if(choice<-1 || choice>20)
					printf("\t\t\t\t\t\t\tInvalid Input! Re-enter");
			}while(choice<-1 || choice>20);
			if(array_itemcall[choice]==1)
				printf("\n\t\t\t\t\t\tOne item at a time only!");
		}while(array_itemcall[choice]==1);	
		if(choice==-1){
			break;
		}
		else if(choice==0){
			cls();
			counter();
		}
		do{
			printf("\t\t\t\t\t\tEnter quantity of item :>> ");
			scanf("%d",&quantitis);
			if(quantitis<1)
				printf("\t\t\t\t\t\t\t\tInvalid Input! Re-enter\n");
		}while(quantitis<1);
		if(quantitis<=array_qitem[choice]){
			array_itemcall[choice]=1;
			array_quantity[choice]=quantitis;
			array_total[choice]=array_pritem[choice]*quantitis;
			sales+=array_pritem[choice]*quantitis;
			array_qitem[choice]-=quantitis;
			bill(array_item[choice],array_pritem[choice],quantitis);
		}
		else{
			printf("\t\t\t\t\t\t\tQuantity entered exceed the quantity of item.\n");
			delay(2);
		}
	}
	cls();
	receipt(sales);

}

void bill(char name[],float harga, int tis){	//bill function in counter registry
	float final_harga;
	final_harga=tis*harga;
	printf("\t\t\t\t\t\t\t   %s  x%d = RM%.2f \n",name,tis,final_harga);
}

void receipt(float sale){	//receipt for total bill
	int choice_return;
	struct tm *timeinfo;
	printf("RYZEN HARDWARE\t\t");
	jam();
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t___________________________________________________________\n");
	printf("\t\t\t\t\t\t|                                                         |\n");
	printf("\t\t\t\t\t\t| RYZEN HARDWARE.co                                       |\n");
	printf("\t\t\t\t\t\t| 		                           Time:- %.5s   |\n", __TIME__);
	printf("\t\t\t\t\t\t|_________________________________________________________|\n");
	for(y=0;y<=20;y++){
		if(array_itemcall[y]==1){
			printf("\t\t\t\t\t\t| %-20s (RM%5.2f)\tx%03d    RM%7.2f |\n",array_item[y],array_pritem[y],array_quantity[y],array_total[y]);
		}
	}
	printf("\t\t\t\t\t\t|_________________________________________________________|\n");
	printf("\t\t\t\t\t\t|                                                         |\n");
	printf("\t\t\t\t\t\t|                Total bill is RM%7.2f                  |\n",sale);
	printf("\t\t\t\t\t\t|_________________________________________________________|\n");
	printf("\t\t\t\t\t\t|                                                         |\n");
	printf("\t\t\t\t\t\t|             Thank you and have a nice day!              |\n");
	printf("\t\t\t\t\t\t|_________________________________________________________|\n\n");

	if(array_staff[1]==1){
		s1.sale[s_1]=sale;
		s_1++;
	}

	if(array_staff[2]==1){
		s2.sale[s_2]=sale;
		s_2++;
	}

	if(array_staff[3]==1){
		s3.sale[s_3]=sale;
		s_3++;
	}
	for(i=0;i<143;i++)
		printf("-");
	printf("\nPress any key to return...");
	getch();
	cls();
	staff();
}

void viewsalestaff(){		//staff view sales
	int choice_return;
	printf("RYZEN HARDWARE\t\t");
	jam();
	for(i=0;i<=3;i++){
		total_sales[i]=0;
	}
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tYour list of sales:\n");
	if(array_staff[1]==1){
		for(i=0;i<=30;i++){
			if(s1.sale[i]!=0){
				printf("\t\t\t\t\t\t\t%d) RM%.2f \n",i+1,s1.sale[i]);
				total_sales[1]+=s1.sale[i];
			}
		}
		printf("\n\t\t\t\t\t\t\tYour total sales is RM%.2f\n",total_sales[1]);
		printf("\t\t\t\t\t\t\tYour commission is RM%.2f (10%% of total sales)\n",total_sales[1]*0.1);
	}

	else if(array_staff[2]==1){
		for(i=0;i<=30;i++){
			if(s2.sale[i]!=0){
				printf("\t\t\t\t\t\t\t%d) RM%.2f \n",i+1,s2.sale[i]);
				total_sales[2]+=s2.sale[i];
			}
		}
		printf("\n\t\t\t\t\t\t\tYour total sales is RM%.2f\n",total_sales[2]);
		printf("\t\t\t\t\t\t\tYour commission is RM%.2f (10%% of total sales)\n",total_sales[2]*0.1);
	}

	else if(array_staff[3]==1){
		for(i=0;i<=30;i++){
			if(s3.sale[i]!=0){
				printf("\t\t\t\t\t\t\t%d) RM%.2f \n",i+1,s3.sale[i]);
				total_sales[3]+=s3.sale[i];
			}
		}
		printf("\n\t\t\t\t\t\t\tYour total sales is RM%.2f\n",total_sales[3]);
		printf("\t\t\t\t\t\t\tYour commission is RM%.2f (10%% of total sales)\n",total_sales[3]*0.1);
	}
	printf("\n\n\n\n");
	for(i=0;i<143;i++)
		printf("-");
	printf("\nPress any key to return...");
	getch();
	cls();
	staff();
}
