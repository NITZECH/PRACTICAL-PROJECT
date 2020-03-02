
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
void menu(void);
void password(void);
void namefun(void);
void searchfun(void);
void listfun(void);
void modifyfun(void);
void deletefun(void);
void exitfun(void);
void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int main(){
	system("color B");
	password();
	getch();	
}

void namefun(){
	system("cls");
	gotoxy(31,4);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB NEW SECTION \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
	FILE *fptr;
	char fname[100];
	char lname[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	fptr=fopen("ebraj.txt","ab+");
	if(fptr==NULL){
		printf("Failed to create the required file.");
	}
	else{
		gotoxy(31,6);
		printf("\xB2\xB2 First Name:\t");
		gotoxy(52,6);
		gets(fname);
		gotoxy(31,7);
		printf("\xB2\xB2 Last Name:\t");
		gotoxy(52,7);
		gets(lname);
		gotoxy(31,8);
		printf("\xB2\xB2 Address:\t");
		gotoxy(52,8);
		gets(address);
		gotoxy(31,9);
		printf("\xB2\xB2 Gender:\t");
		gotoxy(52,9);
		gets(gender);
		gotoxy(31,10);
		printf("\xB2\xB2 Gmail:\t");
		gotoxy(52,10);
		gets(gmail);
		gotoxy(31,11);
		printf("\xB2\xB2 Phone Number:\t");
		gotoxy(52,11);
		scanf("%lf",&phone);
		fprintf(fptr,"%s %s %s %s %s %.0lf\n",fname,lname,address,gender,gmail,phone);
		gotoxy(31,14);
		printf("Data recorded successfully.");
		getch();
	}
	fclose(fptr);
	system("cls");
	char ch;
	gotoxy(31,4);
	printf("Press y for menu option:");
	Sleep(1000);
	fflush(stdin);
	while((ch=getch())=='y'){
		menu();
	}
}
void searchfun(){
	FILE *fptr;
	int flag=0;
	int res;
	char fname[100];
	char lname[100];
	char address[100];
	char gmail[100];
	char fname1[100];
	char lname1[100];
	double phone;
	char gender[8];
	char name1[100];
	int res1;
	system("cls");
	fflush(stdin);
	gotoxy(18,2);
	printf("\xDB\xDB\xDB Enter the first name of the person you want to see the detail:: ");
	gets(fname1);
	fptr=fopen("ebraj.txt","r");
	while(fscanf(fptr,"%s %s %s %s %s %lf\n",fname,lname,address,gender,gmail,&phone)!=EOF){
		res=strcmp(fname,fname1);
		if(res==0){
			gotoxy(18,3);
			printf("\xDB\xDB\xDB Enter the last name of the person you want to see the detail:: ");
			gets(lname1);
			res1=strcmp(lname,lname1);
			if(res1==0){
				gotoxy(39,5);
				printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Record Found \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
				gotoxy(31,6);
				printf("----------------------------------------");
				gotoxy(31,7);
				printf("\xB3\xB2\xB2\xB2 First Name:\t%s",fname);
				gotoxy(31,8);
				printf("\xB3\xB2\xB2\xB2 Last Name:\t%s",lname);
				gotoxy(31,9);
				printf("\xB3\xB2\xB2\xB2 Address:\t%s",address);
				gotoxy(31,10);
				printf("\xB3\xB2\xB2\xB2 Gender:\t%s",gender);
				gotoxy(31,11);
				printf("\xB3\xB2\xB2\xB2 Gmail:\t%s",gmail);
				gotoxy(31,12);
				printf("\xB3\xB2\xB2\xB2 Phone Number:\t%.0lf",phone);
				gotoxy(31,13);
				printf("----------------------------------------");
				flag=1;
				Sleep(1000);
				gotoxy(18,16);
				printf("Enter y for menu option.");
				while(getch()=='y'){
					menu();
	}
	}
}
	if(flag==0){
		system("cls");
		gotoxy(42,4);
		printf("\xB2\xB2\xB2 No record found.");
		gotoxy(20,6);
		printf("::Enter a to enter file again or y key to open menu section:");
		char z=getch();
		if(z=='a'){
			system("cls");
			searchfun();	
			}else if(z=='y'){
				menu();
			}
		}
	
	}
	gotoxy(31,4);
	printf("No record saved.Press y for menu.");
	if(getch()=='y'){
		menu();
		system("cls");
	}
	fclose(fptr);
}

void listfun(){
		FILE *fptr;
	char fname[100],lname[100],address[100],gmail[100],gender[8];
	double phone;
	int f;
	fptr=fopen("ebraj.txt","r");
	system("cls");
	gotoxy(31,2);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB LIST SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
	printf("\n");
	while(fscanf(fptr,"%s %s %s %s %s %lf",fname,lname,address,gender,gmail,&phone)!=EOF){
		
			printf("------------------------------------------\n");
		printf("\xB2\xB2 First Name:%s\n",fname);
		printf("\xB2\xB2 Last Name:%s\n",lname);
		printf("\xB2\xB2 Address:%s\n",address);
		printf("\xB2\xB2 Gender:%s\n",gender);
		printf("\xB2\xB2 Gmail:%s\n",gmail);
		printf("\xB2\xB2 Phone:%.0lf\n",phone);
			f=1;
				printf("------------------------------------------");
				printf("\n\n");
		}
		Sleep(1000);
		printf("Enter y for menu section:");
		while(getch()=='y'){
			menu();
		}
			fclose(fptr);
			}
void modifyfun(){
	FILE *fptr,*fptr1;
	char fname[100],lname[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8],gender1[8];
	char lname1[100],fname1[100];
	int res,f=0,res1;
	double phone,phone1;
	fptr=fopen("ebraj.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	gotoxy(31,4);
	printf("\xDB\xDB\xDB Enter the first name you want to modify:");
	gets(fname1);
	while(fscanf(fptr,"%s %s %s %s %s %lf\n",fname,lname,address,gender,gmail,&phone)!=EOF){
		res=strcmp(fname,fname1);
		if(res==0){
			gotoxy(31,6);
			printf("\xDB\xDB\xDB Enter the last name of the person:");
			gets(lname1);
			system("cls");
			res1=strcmp(lname,lname1);
			if(res1==0){
				gotoxy(31,4);
				printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MODIFY SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
				gotoxy(31,6);
				printf("\xB2\xB2 Enter the new address:");
				scanf("%s",address1);
				gotoxy(31,7);
				printf("\xB2\xB2 Enter the gender:");
				scanf("%s",gender1);
				gotoxy(31,8);
				printf("\xB2\xB2 Enter the new gmail:");
				scanf("%s",gmail1);
				gotoxy(31,9);
				printf("\xB2\xB2 Enter the new phone number:");
				scanf("%lf",&phone1);
				fprintf(fptr1,"%s %s %s %s %s %.0lf\n",fname1,lname1,address1,gender1,gmail1,phone1);
				f=1;
				gotoxy(31,12);
				printf("Record Modified Successfully.");
		}else{
			fprintf(fptr1,"%s %s %s %s %s %.0lf\n",fname,lname,address,gender,gmail,phone);
		}
			}
			else{
			fprintf(fptr1,"%s %s %s %s %s %.0lf\n",fname,lname,address,gender,gmail,phone);
		}
			
	}
	if(f==0){
		gotoxy(31,4);
		system("cls");
		gotoxy(31,8);
		printf("\t\tRecord Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("ebraj.txt","w");
	fclose(fptr);
	fptr=fopen("ebraj.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %s %lf\n",fname,lname,address,gender,gmail,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %s %.0lf\n",fname,lname,address,gender,gmail,phone);
		
	}
	
	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	gotoxy(28,14);
	printf("Press y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	}
}

void deletefun(){
		FILE *fptr,*fptr1;
	char fname[100],lname[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8],gender1[8];
	char lname1[100],fname1[100];
	int res,f=0,res1;
	double phone,phone1;
	fptr=fopen("ebraj.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	gotoxy(31,4);
	printf("\xDB\xDB\xDB Enter the first name you want to modify:");
	gets(fname1);
	while(fscanf(fptr,"%s %s %s %s %s %lf\n",fname,lname,address,gender,gmail,&phone)!=EOF){
		res=strcmp(fname,fname1);
		if(res==0){
			gotoxy(31,6);
			printf("\xDB\xDB\xDB Enter the last name:");
			gets(lname1);
			system("cls");
			res1=strcmp(lname,lname1);
			if(res1==0){
				
				f=1;
				gotoxy(31,6);
				printf("Record Deleted Successfully.");
		}else{
			fprintf(fptr1,"%s %s %s %s %s %.0lf\n",fname,lname,address,gender,gmail,phone);
		}
			}else{
			fprintf(fptr1,"%s %s %s %s %s %.0lf\n",fname,lname,address,gender,gmail,phone);
		}		
	}
	if(f==0){
		gotoxy(31,6);
		printf("Record Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("ebraj.txt","w");
	fclose(fptr);
	fptr=fopen("ebraj.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %s %lf\n",fname,lname,address,gender,gmail,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %s %.0lf\n",fname,lname,address,gender,gmail,phone);	
	}
	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	gotoxy(31,8);
	printf("Press y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	}
}
void exitfun(){
	system("cls");
	fflush(stdin);
	gotoxy(31,4);
	printf("\xDB\xDB\xDB\xDB TEAM MEMBERS \xDB\xDB\xDB\xDB");
	gotoxy(31,6);
	printf("\xDB EBRAJ GURUNG.");
	gotoxy(31,8);
	printf("\xDB BEEKASH BASAULA.");
	gotoxy(31,10);
	printf("\xDB SAMUNDRA POUDEL.");
	gotoxy(31,12);
	printf("\xDB SAGAR DHAKAL.");
}
void password(void){
	char passwords[20]={"ebrajdon"};
	gotoxy(22,2);
	int j;
	int z;
	char name[40]="AUTHORIZED PERSON ONLY";
	z=strlen(name);
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	for(j=0;j<=z;j++){
		Sleep(60);
		printf(" %c",name[j]);
	}
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	gotoxy(30,4);
	printf("Password:");
	char ch,pass[20];
	char w='*';
	int i=0;
	while(ch!=13){
		ch=getch();
		if(ch!=13 && ch!=8){
			printf("%c",w);
			pass[i]=ch;
			i++;
		}
			}
	pass[i]='\0';
	if(strcmp(pass,passwords)==0){
		gotoxy(30,6);
		printf("CORRECT PASSWORD.");
		Sleep(1000);
		menu();
	}
	else{
		gotoxy(30,6);
		printf("You entered the wrong password.");
		Sleep(700);
		system("cls");
		password();
}	
}
	
void menu(){
	system("cls");
	gotoxy(30,1);
	printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PHONEBOOK DIRECTORY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");
	gotoxy(31,4);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 1.Add New");
	gotoxy(31,7);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 2.Search");
	gotoxy(31,10);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 3.List");
	gotoxy(31,13);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 4.Modify");
	gotoxy(31,16);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 5.Delete");
	gotoxy(31,19);
	printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 6.Exit");
	switch(getch()){
		case '1':
			namefun();
			break;
		case '2':
			searchfun();
			break;
		case '3':
			listfun();
			break;
		case '4':
			modifyfun();
			break;
		case '5':
			deletefun();
			break;
		case '6':
			exitfun();
			break;
		default:
			system("cls");
			gotoxy(50,12);
			printf("\aInvalid Enter.");
			Sleep(1000);
			system("cls");
			menu();
}
}


