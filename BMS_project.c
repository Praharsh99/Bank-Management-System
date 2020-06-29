#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <sys/stat.h>
#include <ctype.h>
#include<time.h>

#define Acc_No 1612381550

typedef struct user_account
{

	long int acc_no;
	char *username;
	char *password;
	int d,m,y,dob;
	int age;
	char *phone_no;
	char *gender;
	long int balance;

}user;

struct stat buffer;

user u[100];
int i;

char *newFileName(int num,char *str)
{
	int i,len=0,rem,len1=strlen(str);
	int n=num;

	while(n != 0)
	{
		len++;
		n=n/10;
	}

	char *name=(char *)malloc(sizeof(char)*len*len1);

	for(i=0; i < len; i++)
	{
		rem=num%10;
		num=num/10;
		name[len-(i+1)]=rem+48;
	}

	name[len]='\0';
	strcat(name,str);
	return name;
}

char *merge(char *str1,char *str2)
{
	int len1=strlen(str1),len2=strlen(str2);
	char *name=(char *)malloc(sizeof(char)*(len1+len2));

	for(int i=0; i < len1; i++)
	{
		name[i]=str1[i];
	}

	name[len1]='\0';

	strcat(name,str2);

	return name;
}

void loader()
{
	int i;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading");
	for(i=0; i<10; i++)
	{
		Sleep(200);
		printf("%c",'.');
	}
}

void Details_of_user(long int acc_num)
{
	int count=0;
	FILE *fp;
	char *line=(char *)malloc(sizeof(char)*20);
	char *new_name=newFileName(acc_num,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp=fopen(file_name,"r");

	system("cls");
	printf("\n===============================================================================");
	printf("\n\t                               USER DETAILS                                \n");
	printf("\n===============================================================================");

	while(fgets(line,50,fp) != NULL)
	{
		if(count == 0)
			printf("\n\n\t\tAccount Number : %s",line);
		if(count == 1)
			printf("\n\n\t\tUsername : %s",line);
		if(count == 3)
			printf("\n\n\t\tDate Of Birth : %s",line);
		if(count == 4)
			printf("\n\n\t\tGender : %s",line);
		if(count == 5)
			printf("\n\n\t\tPhone No : %s",line);
		if(count == 6)
			printf("\n\n\t\tAge : %s",line);
		if(count == 7)
			printf("\n\n\t\tBalance : %s",line);


		count++;
	}
	fclose(fp);
	getch();
}


char *Username()
{
	int index,len,count=0;
	char to_clear_buffer;
	char *input=(char *)malloc(sizeof(char)*50);

	scanf("%c", &to_clear_buffer);
	printf("\n\n\t\t\t\t\tUsername : ");
	scanf("%[^\n]",input);
	len=strlen(input);

	for(index=0; index < len; index++)
	{
		if((input[index] >= 'a' && input[index] <= 'z') || (input[index] >= 'A' && input[index] <= 'Z') || (input[index] == ' '))
			count++;
	}

	if(count == len)
		return input;
	else
		return "1234";
}

char *password()
{
	char *input=(char *)malloc(sizeof(char)*256);
	int len;

	printf("\n\n\t\t\t\t\tEnter 8 digit Password : ");
	scanf("%s",input);

	len=strlen(input);
	if(len == 8)
		return input;
	else
		return "1234";
}

int date_of_birth(int *date,int *month,int *year)
{

	printf("\n\n\t\t\t\t\tDate Of Birth --");

	printf("\n\n\t\t\t\t-->\tEnter date : ");
	scanf("%d",date);
	printf("\n\t\t\t\t-->\tEnter month : ");
	scanf("%d",month);
	printf("\n\t\t\t\t-->\tEnter year : ");
	scanf("%d",year);

	if(( *date >= 1 && *date < 32 ) && ( *month >= 1 && *month < 13 ) && ( *year > 0 && *year <= 2018 ))
	{
		if(*month == 4 || *month == 6 || *month == 9 || *month == 11)
		{
			if(*date > 30)
				return -1;

			else
			   return 1;
		}

		else if(*month == 2)
		{
			if(*date > 28)
			{
				if(*year%4 == 0 && *year%100 == 0 && *year%400 == 0)
					return 1;
				else
					return -1;
			}
			else
			   return 1;
		}

		else
			return 1;
	}

	else
		return -1;
}

char *gender()
{
	int len_gender;
	char *input=(char *)malloc(sizeof(char)*256);
	printf("\n\n\t\t\t\t\tGender M/F : ");
	scanf("%s",input);

	len_gender=strlen(input);
	if( ( (strcmp(input,"M") == 0) || (strcmp(input,"F") == 0) || (strcmp(input,"m") == 0) || (strcmp(input,"f") == 0) ) && ( len_gender == 1) )
		return input;
	else
		return "1234";
}

int age()
{
	int num;
	printf("\n\n\t\t\t\t\tEnter Your Age : ");
	scanf("%d",&num);

	if(num >= 18 && num <= 55)
		return num;
	else
		return -1;
}

char *phone_no()
{
	int len_no;
	//char buffer;
	char *number=(char *)malloc(sizeof(char)*50);
	//scanf("%c", &buffer);
	printf("\n\n\t\t\t\t\tContact No. : ");
	scanf("%s",number);

	len_no=strlen(number);
	if( (number[0] >= '7') && (len_no == 10) )
	{
		return number;
	}
	else
		return "1234";
}

int char_to_int(char *string)
{
	int i,len=strlen(string),number=0;

	for(i=0; i < len-1; i++)
	{
		number=number+(string[i]-48);
		number*=10;
	}
	return number/10;
}

char *int_to_char(int src)
{
	char r,*string=(char*)malloc(100*sizeof(char));
	int n=src,j=0,temp=0;

	if(src < 0)
	{
		n=n*-1;
		temp=1;
	}

	if(n == 0)
	{
		string[j++]='0';
	}

	while(n != 0)
	{
		r=n%10;
		string[j++]=(r+48);
		n/=10;
	}

	if(temp == 1)
	{
		string[j++]=45;
	}
	string[j]='\0';
	strrev(string);
	return string;
}

int get_salary(long int acc_num)
{
	int digit;
	digit=acc_num%10;

	if(digit == 1 || digit == 3 || digit == 5)
		return 60000;
	else if(digit == 0 || digit == 2 || digit == 4 || digit == 8)
		return 40000;
	else if(digit == 6 || digit == 7 || digit == 9)
		return 70000;
	else
		return -1;
}

int month_difference(char *date1,char *date2)
{
	int mnth=0,diff,diff_year,len1=strlen(date1),len2=strlen(date2),i,count=0;
	int d1=0,m1=0,y1=0;
	int d2=0,m2=0,y2=0;

	for(i=0; i < len1-1; i++)
	{
		if(date1[i] == '/')
		{
			count++;
			continue;
		}
		if(count == 0)
		{
			d1=d1+(date1[i]-48);
			d1*=10;
		}
		if(count == 1)
		{
			m1=m1+(date1[i]-48);
			m1*=10;
		}
		if(count == 2)
		{
			y1=y1+(date1[i]-48);
			y1*=10;
		}

	}

	count=0;
	for(i=0; i < len2; i++)
	{
		if(date2[i] == '/')
		{
			count++;
			continue;
		}
		if(count == 0)
		{
			d2=d2+(date2[i]-48);
			d2*=10;
		}
		if(count == 1)
		{
			m2=m2+(date2[i]-48);
			m2*=10;
		}
		if(count == 2)
		{
			y2=y2+(date2[i]-48);
			y2*=10;
		}
	}
	d1/=10;m1/=10;y1/=10;d2/=10;m2/=10;y2/=10;

	if(y1 == y2)
	{
		if(m1 <= m2)
		{
			diff=abs(m1-m2);

			if(d1 == d2)
				mnth= diff;

			else if(d1 > d2)
			{
				if(diff == 1)
					mnth=0;
				else
					mnth=diff-1;
			}

			else
				mnth=diff;
		}
	}

	else
	{
		diff_year=abs(y1-y2);

		if(diff_year == 1)
		{
			if(m1 == m2)
			{
				if(d1 == d2)
					mnth=(12-m1)+ m2;
			}
			else
			{
				if(m1 > m2 || m1 < m2)
				{
					if(d1 == d2 || d1 < d2)
						mnth=(12-m1)+ m2;
					else
						mnth=(12-m1)+ (m2-1);
				}
			}
		}

		else
		{
			if(m1 == m2)
			{
				if(d1 == d2)
					mnth=(diff_year*12);
			}
			else
			{
				if(m1 > m2 || m1 < m2)
				{
					if(d1 == d2 || d1 < d2)
						mnth=(12-m1)+ m2+( (diff_year-2) * 12 );
					else
						mnth=(12-m1)+(m2-1)+( (diff_year-2) * 12 );
				}
			}
		}
	}

	return mnth;
}

void create_no_files_file()
{
	char *file_name = "D:\\project_bank\\no_of_files.txt";
	int exist = stat(file_name, &buffer);

	if(exist == -1)
	{
		FILE *f;
		f=fopen("D:\\project_bank\\no_of_files.txt","w");
		fprintf(f, "%d", 0);
		fclose(f);
	}
}

void create_account()
{
	double income;
	int i;
	char buffer;
	FILE *fp,*transaction;
	FILE *f;

	f=fopen("D:\\project_bank\\no_of_files.txt","r");
	if(f != NULL)
	{
		i=fgetc(f)-48;
	}
	u[i].acc_no=Acc_No+i;

	char *new_name=newFileName(u[i].acc_no,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);

	char *new_name_th=newFileName(u[i].acc_no,"_th.txt");
	char *file_name_th=merge("D:\\project_bank\\",new_name_th);

	fp=fopen(file_name,"w");

		printf("\n\n\n\t\t\t\t\t<-------- CREATE ACCOUNT --------> \n");
		printf("\n\t\t\t\t\t--------------------------------\n");
		printf("\t\t\t\t\tYOUR ACCOUNT NUMBER : %ld",u[i].acc_no);
		fprintf(fp,"%ld",u[i].acc_no);
		printf("\n\t\t\t\t\t--------------------------------");

		//------------------------

		u[i].username=Username();

		if(strcmp(u[i].username,"1234") == 0)
		{
			while( strcmp(u[i].username,"1234") == 0 )
			{
				printf("\n\t\t\tERROR : Please Enter Correct Username !!");
				u[i].username=Username();
			}
		}
		else
			fprintf(fp,"\n%s",u[i].username);

		//-------------------------

		u[i].password=password();

		if(strcmp(u[i].password,"1234") == 0)
		{
			while( strcmp(u[i].password,"1234") == 0 )
			{
				printf("\n\t\t\t\tERROR : Please Enter correct Password !!");
				scanf("%c", &buffer);
				u[i].password=password();
			}
			fprintf(fp,"\n%s",u[i].password);
		}
		else
			fprintf(fp,"\n%s",u[i].password);

		//--------------------------

		int d, m, y;

		u[i].dob = date_of_birth(&d,&m,&y);

		if(u[i].dob == -1)
		{
			while(u[i].dob == -1)
			{
				printf("\n\t\t\t\tERROR : Please Enter Valid Date !!");
				scanf("%c", &buffer);
				u[i].dob=date_of_birth(&d,&m,&y);
			}

			u[i].d = d;
			u[i].m = m;
			u[i].y = y;

			fprintf(fp,"\n%d/%d/%d", u[i].d, u[i].m, u[i].y);
		}

		else
		{
			u[i].d = d;
			u[i].m = m;
			u[i].y = y;

			fprintf(fp,"\n%d/%d/%d", u[i].d, u[i].m, u[i].y);
		}

		//---------------------------

		u[i].gender=gender();

		if( strcmp(u[i].gender,"1234") == 0 )
		{
			while( strcmp(u[i].gender,"1234") == 0 )
			{
				printf("\n\t\t\t\tERROR : Please Enter Valid input !!");
				scanf("%c", &buffer);
				u[i].gender=gender();
			}
			fprintf(fp,"\n%s",u[i].gender);
		}
		else
			fprintf(fp,"\n%s",u[i].gender);

		//---------------------------

		u[i].phone_no = phone_no();

		if( strcmp(u[i].phone_no,"1234") == 0 )
		{
			while( strcmp(u[i].phone_no,"1234") == 0 )
			{
				printf("\n\t\t\t\tERROR : Please Enter Valid Number !!");
				scanf("%c", &buffer);
				printf("\n---->%c", buffer);
				getch();
				u[i].phone_no=phone_no();
			}
			fprintf(fp,"\n%s",u[i].phone_no);
		}
		else
			fprintf(fp,"\n%s",u[i].phone_no);

        //--------------------------

		u[i].age = age();

		if(u[i].age == -1)
		{
			while(u[i].age == -1)
			{
				printf("\n\t\t\t\tERROR : Please Enter Correct Age !!");
				scanf("%c", &buffer);
				u[i].age=age();
			}
			fprintf(fp,"\n%d",u[i].age);
		}
		else
			fprintf(fp,"\n%d",u[i].age);

		//---------------------------

		printf("\n\n\t\t\t--->\tDeposited amount 2000/- initially ");
		income=get_salary(u[i].acc_no);
		u[i].balance=income+2000;
		fprintf(fp,"\n%ld",u[i].balance);

				time_t time_at_creation;
				time(&time_at_creation);
				struct tm *info;
				static char date_at_creation[15];
				info=localtime(&time_at_creation);
				sprintf(date_at_creation,"%d/%d/%d",(*info).tm_mday,(*info).tm_mon+1,(*info).tm_year+1900);
				fprintf(fp,"\n%s",date_at_creation);

				printf("\n\n\t\t\tCongrats Your Account Is Successfully Created!!!!");
				transaction=fopen(file_name_th,"r");
				fclose(transaction);
				Sleep(1000);
				loader();
				fclose(fp);
				Details_of_user(u[i].acc_no);

		i+=1;
		fclose(f);

		FILE *f1;
		f1=fopen("D:\\project_bank\\no_of_files.txt","w");
		fprintf(f1,"%d",i);

		fclose(f1);
		getch();
}

int compare_dates(char *date1,char *date2)
{
	int len1=strlen(date1),len2=strlen(date2),i,mnths=0;
	int d1=0,m1=0,y1=0;
	int d2=0,m2=0,y2=0;

	for(i=0; i < len1; i++)
	{
		if(i <= 1)
		{
			d1=d1+(date1[i]-48);
			d1*=10;
		}

		if(i >= 3 && i <= 4)
		{
			m1=m1+(date1[i]-48);
			m1*=10;
		}

		if(i >= 6 && i <= len1-1)
		{
			y1=y1+(date1[i]-48);
			y1*=10;
		}
	}

	for(i=0; i < len2; i++)
	{
		if(i <= 1)
		{
			d2=d2+(date2[i]-48);
			d2*=10;
		}

		if(i >= 3 && i <= 4)
		{
			m2=m2+(date2[i]-48);
			m2*=10;
		}

		if(i >= 6 && i <= len2-1)
		{
			y2=y2+(date2[i]-48);
			y2*=10;
		}
	}
	d1/=10;m1/=10;y1/=10;d2/=10;m2/=10;y2/=10;

	if(abs(m1-m2) >= 1)
		mnths=month_difference(date1,date2);

	return mnths;
}

void edit_balance(long int acc_num)
{
	long int balance;
	int get_date_line=8,count=0,get_balance_line=7,result;
	FILE *edit_file;
	char *new_name=newFileName(u[i].acc_no,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	edit_file=fopen(file_name,"r");
	char *str_date=(char *)malloc(sizeof(char)*25);
	char *str_balance=(char *)malloc(sizeof(char)*25);

	while( fgets(str_date,25,edit_file) != NULL )
	{
		if(count == get_balance_line)
		{
			strcpy(str_balance,str_date);
			count++;
		}

		if(count == get_date_line)
			break;

		else
			count++;
	}

	time_t time_at;
	time(&time_at);
	struct tm *info;
	static char time_now[15];
	info=localtime(&time_at);
	sprintf(time_now,"%d/%d/%d",(*info).tm_mday,(*info).tm_mon+1,(*info).tm_year+1900);

	result=compare_dates(str_date,time_now);

	if(result >= 1)
	{
		int salary;
		salary=get_salary(acc_num);
		balance=char_to_int(str_balance);
		balance=balance+(result*salary);

		FILE *mainfile,*tempfile;
		char *new_name=newFileName(acc_num,".txt");
		char *file_name=merge("D:\\project_bank\\",new_name);
		mainfile=fopen(file_name,"r");
		tempfile=fopen("D:\\project_bank\\temp.txt","w");
		char *edit_line=(char *)malloc(sizeof(char)*25);

		while(fgets(edit_line,25,mainfile) != NULL)
		{
			if(count == get_date_line)
			{
				fprintf(tempfile,"%s",time_now);
				count++;
				break;
			}
			if(count == get_balance_line)
			{
				fprintf(tempfile,"\n%ld",balance);
				count++;
			}
			else
			{
				fprintf(tempfile,"%s",edit_line);
			}
		}

		fclose(mainfile);
		fclose(tempfile);
		remove(file_name);
		rename("D:\\project_bank\\temp.txt",file_name);
	}
}

void Balance_enquiry(long int acc_num)
{
	int count=0,balance_line=7;
	FILE *fp;
	char *new_name=newFileName(acc_num,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp=fopen(file_name,"r");
	char *string=(char *)malloc(sizeof(char)*15);

	printf("\n\n\n\t\tAccount Number : %ld",acc_num);

	while(fgets(string,20,fp) != NULL)
	{
		if(count == balance_line)
		{
			printf("\n\n\t\tBalance : %s",string);
			break;
		}
		else
			count++;
	}

	printf("\n\n\n\tPress Any Key To Go Back ");
	getch();
	fclose(fp);
}

void transaction_history(long int amount,char *type_of_transac,long int acc_num)
{
	FILE *fp;
	char *new_name_th=newFileName(acc_num,"_th.txt");
	char *file_name_th=merge("D:\\project_bank\\",new_name_th);
	fp=fopen(file_name_th,"a");

	time_t t;
	time(&t);
	char *transaction_time=ctime(&t);

	fprintf(fp,"\n%s--%s",type_of_transac,transaction_time);
	fprintf(fp,"%s","<------------------------------>");
	fclose(fp);

}

void withdraw(long int acc_num)
{
	int flag=0,line_to_delete=7,count=0,balance_line=7;
	long int amount,balance=0;
	char *str,*info;
	FILE *fp1,*mainfile,*tempfile;
	char *choice=(char *)malloc(sizeof(char)*25);
	str=(char *)malloc(sizeof(char)*25);
	char *new_name=newFileName(acc_num,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp1=fopen(file_name,"r");

	printf("\n\n\n\n\n\n\t\t\t <>------ WITHDRAW CASH ------<>");
	printf("\n\n\n\n\t\t\tYour Account Number : %ld",acc_num);
	printf("\n\n\n\t\t\tEnter Amount : ");
	scanf("%ld",&amount);

	while(fgets(str,22,fp1) != NULL)
	{
		if(count == balance_line)
			break;
		else
		   count++;
	}

	balance=char_to_int(str);
	if(balance >= amount)
	{
		balance-=amount;
		fclose(fp1);
		mainfile=fopen(file_name,"r");
		tempfile=fopen("D:\\project_bank\\temp.txt","w");
		count=0;

		while(fgets(str,22,mainfile) != NULL)
		{
			if(count == line_to_delete)
			{
				fprintf(tempfile,"%ld",balance);
				count++;
			}

			else
			{
				if( count == (line_to_delete+1) )
					fprintf(tempfile,"\n%s",str);

				else
				{
					fprintf(tempfile,"%s",str);
				}

				count++;
			}

			if(count == 9)
			   break;
		}

		fclose(mainfile);
		fclose(tempfile);
		remove(file_name);
		rename("D:\\project_bank\\temp.txt",file_name);
		printf("\n\n\n\t---->\t  Your Balance Is : %ld",balance);

		info=newFileName(amount,"-- withdraw");
		transaction_history(amount,info,acc_num);
	}

	else
	{
		flag=1;
		printf("\n\n\t Please withdraw Amount Less than Balance !!!");
	}

	if(flag == 1)
	{
		printf("\n\n\t Enter 1 To Try Again Or Any Character To Exit");
		scanf("%s",choice);

		if( strcmp(choice,"1") == 0 )
			withdraw(acc_num);
	}
	getch();
	fclose(fp1);
}

void deposit(long int acc_num)
{
	int flag=0,line_to_delete=7,count=0,balance_line=7;
	long int amount,balance=0;
	char *str,*info;
	FILE *fp2,*mainfile,*tempfile;
	char *choice=(char *)malloc(sizeof(char)*25);
	str=(char *)malloc(sizeof(char)*25);
	char *new_name=newFileName(acc_num,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp2=fopen(file_name,"r");

	printf("\n\n\n\n\n\n\t\t\t <>------ DEPOSIT CASH ------<>");
	printf("\n\n\n\n\t\t\tYour Account Number : %ld",acc_num);
	printf("\n\n\n\t\t\tEnter Amount (1000/- To 50000/-) : ");
	scanf("%ld",&amount);

	while(fgets(str,20,fp2) != NULL)
	{
		if(count == balance_line)
			break;
		else
		   count++;
	}

	balance=char_to_int(str);
	if(amount >= 1000 && amount <= 50000)
	{
		balance+=amount;
		fclose(fp2);
		mainfile=fopen(file_name,"r");
		tempfile=fopen("D:\\project_bank\\temp.txt","w");

		count=0;
		while(fgets(str,25,mainfile) != NULL)
		{
			if(count == line_to_delete)
			{
				fprintf(tempfile,"%ld",balance);
				count++;
			}

			else
			{
				if( count == (line_to_delete+1) )
				{
					fprintf(tempfile,"\n%s",str);
				}
				else
				{
					fprintf(tempfile,"%s",str);
				}

				count++;
			}
			if(count == 9)
			   break;
		}

		fclose(mainfile);
		fclose(tempfile);
		remove(file_name);
		if(rename("D:\\project_bank\\temp.txt",file_name) != 0)
		{
                perror("-->effsrg");
                getch();
		}
		printf("\n\n\n\t---->\t  Your Balance Is : %ld",balance);

		info=newFileName(amount,"-- Deposited");
		transaction_history(amount, info, acc_num);
	}

	else
	{
		flag=1;
		printf("\n\n\t Please deposit Amount within limit !!!");
	}

	if(flag == 1)
	{
		printf("\n\n\t Enter 1 To Try Again Or Any Character To Exit");
		scanf("%s",choice);

		if( strcmp(choice,"1") == 0 )
			deposit(acc_num);
	}

	getch();
	fclose(fp2);
}

void th_fd_n_display(long int acc_num)
{
	int count=0;
	FILE *fp;
	char *new_name=newFileName(acc_num,"_nfd_th.txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp=fopen(file_name,"r");

	if(fp == NULL)
	{
		printf("\n\n\t\tError while opening your account");
		fclose(fp);
	}
	else
	{
		printf("\n\n\t\t <---------------Transaction History--------------> ");

		char *trans_display=(char *)malloc(sizeof(char)*30);
		while( fgets(trans_display,30,fp) != NULL )
		{
			if(count == 4)
				break;
			else
				printf("\n\t\t%s",trans_display);

			count++;
		}
		fclose(fp);
	}
	getch();
}

void th_fd_t_display(long int acc_num)
{
	int count=0;
	FILE *fp;
	char *new_name=newFileName(acc_num,"_tfd_th.txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp=fopen(file_name,"r");

	if(fp == NULL)
	{
		printf("\nError while opening your account\n");
		fclose(fp);
	}
	else
	{
		printf("\n\n\t\t <---------------Transaction History--------------> ");

		char *trans_display=(char *)malloc(sizeof(char)*30);
		while( fgets(trans_display,30,fp) != NULL )
		{
			if(count == 4)
				break;
			else
				printf("\n\t\t%s",trans_display);

			count++;
		}
		fclose(fp);
	}
	getch();
}

void transactionhistory_fd_n(long int amount,long int acc_num)
{
	FILE *normal_fd_transaction;
	char *new_name=newFileName(acc_num,"_nfd_th.txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	normal_fd_transaction=fopen(file_name,"a");

	time_t t;
	time(&t);
	char *s=ctime(&t);
	char type_of_transac[]="Normal fixed deposit";
	fprintf(normal_fd_transaction,"\n%s--%s:%ld",s,type_of_transac,amount);
	fprintf(normal_fd_transaction,"\n%s","<------------------------------------>");
	fclose(normal_fd_transaction);
}

void transactionhistory_fd_t(long int amount,long int acc_num)
{
	FILE *tax_fd_transaction;
	char *new_name=newFileName(acc_num,"_tfd_th.txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	tax_fd_transaction=fopen(file_name,"a");

	time_t t;
	time(&t);
	char *s=ctime(&t);
	char type_of_transac[]="Tax_Saver fixed deposit";
	fprintf(tax_fd_transaction,"%s-%s:%ld\n",s,type_of_transac,amount);
	fprintf(tax_fd_transaction,"\n%s","<------------------------------------->");
	fclose(tax_fd_transaction);
}

void fd_withdraw_n_tenure(long int acc_num,int T,int I)
{
	FILE *fp,*f;
	char *new_name=newFileName(acc_num,"_nfd_th.txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp=fopen(file_name,"r");

	char c;
	int i=1,j=0;
	char string[10];

	fseek(fp,20,SEEK_CUR);
	while( ((c = getc(fp)) != EOF) && i != 5 )
	{
		string[j]=c;
		i++;
		j++;

	}
	string[j]='\0';

	int deposit_year;
	deposit_year=char_to_int(string);
	fclose(fp);

	f=fopen("D:\\project_bank\\help.txt","w");

	time_t t;
	time(&t);
	char *s=ctime(&t);
	fprintf(f,"%s",s);
	fclose(f);

	f=fopen("D:\\project_bank\\help.txt","r");
	char string1[10];
	i=1;
	j=0;

	fseek(f,20,SEEK_CUR);
	while( ((c = fgetc(f)) != EOF) && i!=5 )
	{
		string1[j]=c;
		i++;
		j++;

	}
	string1[j]='\0';

	int present_yr;
	present_yr=char_to_int(string1);
	fclose(f);
	remove("D:\\project_bank\\help.txt");

	if((deposit_year+T)==present_yr)
	{
		FILE *fp;

		char *new_name=newFileName(acc_num,"_nfd.txt");
		char *file_name=merge("D:\\project_bank\\",new_name);
		fp=fopen(file_name,"r");
		char string2[10];

		while((c=getc(fp))!=EOF)
		{
			string2[j]=c;
		}
		string2[j]='\0';

		int wid_amount=char_to_int(string2);
		fclose(fp);

		wid_amount=wid_amount+((wid_amount*I*T)/100);

		printf("\nYour tenure period is completed!");
		printf("\nYou can withdraw %d",wid_amount);
		printf("\nDo you want to withdraw?\nPress '1' for yes.....Press '2' for no.");
		int ch;
		scanf("%d",&ch);

		if (ch == 1)
		{
			printf("\nWithdraw Succesfull....%d",wid_amount);
			remove(file_name);
			printf("\nYour fixed deposit account is closed!");
		}
		else
			printf("\nIt's OK you can withdraw it later! ");
	}
	else
		printf("\nYour tenure period is not yet completed!");

	getch();
}

void fd_withdraw_n(long int acc_num)
{
	FILE *fp;
	char *new_name=newFileName(acc_num,"_nfd.txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp=fopen(file_name,"r");
	char c;
	int i=1;
	int tenure;

	while(((c=fgetc(fp))!=EOF)&&i!=2)
	{
		tenure=c;
		i++;
	}
	int interest;
	tenure=tenure-48;

	if(tenure == 1)
	{
		interest=6;
		fd_withdraw_n_tenure(acc_num,tenure,interest);
	}
	else if(tenure == 2)
	{
		interest=7;
		fd_withdraw_n_tenure(acc_num,tenure,interest);
	}
	fclose(fp);
}

void fd_withdraw_t(long int acc_num)
{
	FILE *fp,*f;
	char *new_name=newFileName(acc_num,"_tfd_th.txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp=fopen(file_name,"r");
	char c;
	int i=1,j=0;
	char string[10];

	fseek(fp,20,SEEK_CUR);
	while(((c=fgetc(fp))!=EOF)&&i!=5)
	{
		string[j]=c;
		i++;
		j++;

	}
	string[j]='\0';

	int deposit_year;
	deposit_year=char_to_int(string);
	fclose(fp);

	f=fopen("D:\\project_bank\\help.txt","w");
	time_t t;
	time(&t);
	char *s=ctime(&t);
	fprintf(f,"%s",s);
	fclose(f);
	f=fopen("D:\\project_bank\\help.txt","r");
	char string1[10];
	i=1;
	j=0;

	fseek(f,20,SEEK_CUR);
	while(((c=fgetc(f))!=EOF)&&i!=5)
	{
		string1[j]=c;
		i++;
		j++;

	}
	string1[j]='\0';

	int present_yr;
	present_yr=char_to_int(string1);
	fclose(f);
	remove("D:\\project_bank\\help.txt");

	if((deposit_year+5)==present_yr)
	{
		FILE *fp;
		char *new_name=newFileName(acc_num,"_tfd.txt");
		char *file_name=merge("D:\\project_bank\\",new_name);
		fp=fopen(file_name,"r");
		char string2[10];

		while((c=fgetc(fp))!=EOF)
		{
			string2[j]=c;
		}
		string2[j]='\0';

		int wid_amount=char_to_int(string2);
		fclose(fp);
		wid_amount=wid_amount+((wid_amount*8*5)/100);
		printf("\n\n\t\tYour tenure period is completed!!");
		printf("\n\n\t\tYou can withdraw %d",wid_amount);
		printf("\n\n\t\tDo you want to withdraw?\nPress '1' for yes.....Press '2' for no.");

		int ch;
		scanf("%d",&ch);

		if(ch == 1)
		{
			printf("\n\n\t\tWithdraw Succesfull....%d",wid_amount);
			remove(file_name);
			printf("\n\n\t\tYour fixed deposit account is closed!");
		}
		else
		   printf("\n\n\t\tIt's OK you can withdraw it later! ");
	}
	else
		printf("\n\n\t\tYour tenure period is not yet completed!");

	getch();
}

void old_fd(long int acc_num)
{
	char *ch=(char *)malloc(sizeof(char)*20);
	int exit_old_fd=0;
	char *select=(char *)malloc(sizeof(char)*10);

	system("cls");
	printf("\n\n\t\t ********** <<<<<  FIXED DEPOSIT ACCOUNT  >>>>> **********");
	printf("\n\n\tDo You Have An Account In Normal Income F.D? (or) Tax Saver F.D?");
	printf("\n\n\t\tPress '1' For Normal Income F.D\n\n\t\tPress '2' For Tax Saver F.D\n\n\t\tPress '3' To Go Back.");
	printf("\n\n\t\tEnter Your Choice : ");
	scanf("%s",select);

	if( (strcmp(select,"1") == 0) )
	{
		FILE *test_file;
		char *new_name=newFileName(acc_num,"_nfd.txt");
		char *file_name=merge("D:\\project_bank\\",new_name);
		test_file=fopen(file_name,"r");

		if(test_file != NULL)
		{
		  y:printf("\n\n\t\t1. Withdraw");
			printf("\n\n\t\t2. Display Transaction History");
			printf("\n\n\t\t3. Go Back");
			printf("\n\n\t\tEnter your choice : ");
			scanf("%s",ch);

			if( ((ch[0]-48) == 1) || ((ch[0]-48) == 2) || ((ch[0]-48) == 3) )
			{
				while(1)
				{
					switch( (ch[0]-48) )
					{
					case 1:fd_withdraw_n(acc_num);
							exit_old_fd=1;
							break;
					case 2:th_fd_n_display(acc_num);
							exit_old_fd=1;
							break;
					case 3:exit_old_fd=1;
							break;
					default:printf("\n\n\t\tIncorect Option!!");
							break;
					}
					if(exit_old_fd == 1)
						   break;
				}
			}
			else
			{
				printf("\n\n\t\tPlease Enter Correct Choice !!");
				Sleep(2000);
				system("cls");
				goto y;
			}
		}
		else
		{
		   printf("\n\n\t  No Account Found In Specified Option, Press Enter ");
		   getch();
		   old_fd(acc_num);
		}
	}

	else if( strcmp(select,"2") == 0 )
	{
		FILE *test_file;
		char *new_name=newFileName(acc_num,"_tfd.txt");
		char *file_name=merge("D:\\project_bank\\",new_name);
		test_file=fopen(file_name,"r");

		if(test_file != NULL)
		{
			z:printf("\n\n\t\t1. Withdraw");
			printf("\n\n\t\t2. Display Transaction History");
			printf("\n\n\t\t3. Go Back");
			printf("\n\n\t\tEnter your choice : ");
			scanf("%s",ch);

			if( ((ch[0]-48) == 1) || ((ch[0]-48) == 2) || ((ch[0]-48) == 3) )
			{
				while(1)
				{
					switch( (ch[0]-48) )
					{
						case 1:fd_withdraw_t(acc_num);
								exit_old_fd=1;
								break;
						case 2:th_fd_t_display(acc_num);
								exit_old_fd=1;
								break;
						case 3:exit_old_fd=1;
								break;
						default:printf("\n\n\t\tIncorect Option!!");
								break;
					}
					if(exit_old_fd == 1)
						   break;
				}
			}
			else
			{
				printf("\n\n\t\tPlease Enter Correct Choice !!");
				Sleep(2000);
				system("cls");
				goto z;
			}
		}
		else
		{
			printf("\n\n\t  No Account Found In Specified Option, Press Enter ");
			getch();
			old_fd(acc_num);
		}
	}
	else if( strcmp(select,"3") == 0 )
			printf("......");
	else
	{
		printf("\n\n\t\tPlease Enter Correct Choice !!");
		Sleep(2000);
		old_fd(acc_num);
	}
}

void Normal_fd(long int acc_num)
{
	int ch;
	FILE *fd_file;

  x:system("cls");
	printf("\n\n\t\t ********** <<<<< NORMAL FIXED DEPOSIT >>>>> **********");
	printf("\n\n\t\t Please Select A Tenure :--");
	printf("\n\n\t\t\tTime Period     Interest Rate");
	printf("\n\t\t\t  1. 1 year      : %d Precent",6);
	printf("\n\t\t\t  2. 2 years     : %d Percent",7);
	printf("\n\n\t\tEnter your choice : ");
	scanf("%d",&ch);

	char *new_name=newFileName(acc_num,"_nfd.txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fd_file=fopen(file_name,"w");

	long int fd_amount;
	printf("\nEnter The Amount You Want To Fixed Deposit(Min 25,000) : ");
	scanf("%ld",&fd_amount);

	if(fd_amount >= 25000)
	{
		if(ch == 1)
		{
			int p=1;
			char i='Y';
			fprintf(fd_file,"%d%c",p,i);
		}

		else if(ch == 2)
		{
			int p=2;
			char i='Y';
			fprintf(fd_file,"%d%c",p,i);
		}
		else
		{
			printf("\n\n\t\tIncorrect choice!!");
			goto x;
		}

		fprintf(fd_file,"%ld",fd_amount);
		printf("\n\n\t\tNow your fixed deposit balance is %ld",fd_amount);
		fclose(fd_file);

		transactionhistory_fd_n(fd_amount,acc_num);
		getch();
	}
	else
	{
		printf("\n\n\t\tPlease Enter Correct Amount!!\n\n\t\tEnter Any Character To Enter Again ");
		getch();
		Normal_fd(acc_num);
	}
}

void TaxSaver_fd(long int acc_num)
{
	system("cls");
	FILE *fp;
	char *new_name=newFileName(acc_num,"_tfd.txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp=fopen(file_name,"w");

	long int f_d;
	printf("\n\n\t\t ********** <<<<< TAX SAVER FIXED DEPOSIT >>>>> **********");
	printf("\n\n\n\tEnter The Amount You Want To Fixed Deposit(min 1,50,000) : ");

	if(f_d  >= 150000 )
	{
		scanf("%ld",&f_d);
		fprintf(fp,"%ld",f_d);
		printf("\n\n\t\t Deposit succesfull!!");
		printf("\nYour principal amount is %ld\nYour interest rate is %d\nTenure period is 5 yrs\nYou can withdraw %ld/- after 5 yrs.",f_d,8,f_d+((f_d*8*5)/100));
		fclose(fp);
		transactionhistory_fd_t(f_d,acc_num);
		getch();
	}
	else
	{
		printf("\n\n\t\t Enter Correct Amount, Press Any Chracter To Enter Again !!");
		getch();
		TaxSaver_fd(acc_num);
	}
}

void new_fd(long int acc_num)
{
	FILE *test_fd_normal,*test_fd_tax;
	char *new_name_1=newFileName(acc_num,"_nfd.txt");
	char *file_name_1=merge("D:\\project_bank\\",new_name_1);
	char *new_name_2=newFileName(acc_num,"_tfd.txt");
	char *file_name_2=merge("D:\\project_bank\\",new_name_2);
	test_fd_normal=fopen(file_name_1,"r");
	test_fd_tax=fopen(file_name_2,"r");

	if( (test_fd_normal != NULL) || (test_fd_tax != NULL) )
	{
		system("cls");
		printf("\n\n\t\t ********** <<<<< FIXED DEPOSIT SCHEMES >>>>> **********");
		printf("\n\n\t You Already Have A Fixed Deposit Account \n\tYou Can Apply For Another Deposit After Completion Of Current Account");
		getch();
	}

	else
	{

		int ch,exit_new_fd=0;

		while(1)
		{
			system("cls");
			printf("\n===============================================================================");
			printf("\n\t\t                          FIXED DEPOSIT SCHEMES                            ");
			printf("\n===============================================================================");
			printf("\n\n\t\t\t\t---> 1. Normal F.D :--");
			printf("\n\n\n  a)You Are Supposed To Deposit A Amount(Min 25,000) For A Fixed Tenure Period.");
			printf("\n\n  b)You Can Withdraw The Interest Amount At The End Of The Tenure Period.");
			printf("\n\n  c)Interest Rates --->");
			printf("\n                     1 Year   : %d percent",6);
			printf("\n                     2 Years  : %d percent",7);
			printf("\n  d)You Can Withdraw (Principal Amount+Interest) You Deposited After The Tenure     Period. ");
			printf("\n\n\t\t\t\t---> 2. Tax Saver F.D :--");
			printf("\n\n\n a)You Are Supposed To Deposit A Amount(Min 1,50,000) For A Fixed Period Of Time   (5 Years)");
			printf("\n\n b)Interest Rates --->");
			printf("\n                     5 Years  : %d percent",8);
			printf("\n\n c)You Can Withdraw (Principal Amount+Interest) After The Fixed Period Of Time.");
			printf("\n\n\t---> 3. Go Back");

			printf("\n\n\t\tEnter your chioce : ");
			scanf("%d",&ch);

			if(ch == 1 || ch == 2 || ch == 3)
			{
				switch(ch)
				{
					case 1:Normal_fd(acc_num);
							exit_new_fd=1;
						break;
					case 2:TaxSaver_fd(acc_num);
							exit_new_fd=1;
						break;
					case 3:exit_new_fd=1;
						break;
					default:printf("\n\n\t\tIncorrect Choice!!");
						break;
				}

				if(exit_new_fd == 1)
				   break;
			}
			else
			   new_fd(acc_num);
		}
	}
}

void f_d(long int acc_num)
{
	int fd_choice,exit_fd=0;

	while(1)
	{
		system("cls");
		printf("\n\n\n\t\t ********** <<<<< FIXED DEPOSIT >>>>> **********");
		printf("\n\n\n\t\t1. Create A Fixed Deposit Account");
		printf("\n\n\t\t2. Already Have An Fixed Deposit Account");
		printf("\n\n\t\t3. Go Back");
		printf("\n\n\t\tEnter Your Choice : ");
		scanf("%d",&fd_choice);

		if(fd_choice == 1 || fd_choice == 2 || fd_choice == 3)
		{
			switch(fd_choice)
			{
				case 1:new_fd(acc_num);
					break;
				case 2:old_fd(acc_num);
					break;
				case 3:exit_fd=1;
					break;
				default:printf("\n\n\t\tNOTE : Incorrect option!!");
					break;
			}
			if(exit_fd == 1)
				break;
		}
		else
		   f_d(acc_num);
	}
}

void delete_account(long int acc_num)
{
	char *choice=(char *)malloc(sizeof(char)*1);

	char *new_name=newFileName(acc_num,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);

	char *new_name_th=newFileName(acc_num,"_th.txt");
	char *file_name_th=merge("D:\\project_bank\\",new_name_th);

	printf("\n\n\n\t\t\t <--------- DELETE ACCOUNT --------->");
	printf("\n\n\t\tNOTE : \tAre You Sure You Want To Delete Your Account ! ");
	printf("\n\t\t\tYour Information Is lost Once Deleted");
	printf("\n\n\n\n\n\t\t\tEnter 1 To Delete, Any Character To Cancel : ");
	scanf("%s",choice);

	if( strcmp(choice,"1") == 0 )
	{
		printf("\n\n\n\t\t\tAccount Deleted");
		remove(file_name);
		remove(file_name_th);
	}
	else
	   printf("\n\n\t\t\tProcess Cancelled");

	getch();
}

void update_Username(long int acc_num)
{
	FILE *mainfile,*tempfile;
	int count=0,line=1;
	char *new_line=(char *)malloc(sizeof(char)*50);
	char *old_line=(char *)malloc(sizeof(char)*50);

	printf("\n\n\n\t\t\t: : : : UPDATE USERNAME : : : :");
	printf("\n\n\n\n\t\tEnter New Username : ");
	scanf("%s",new_line);

	char *new_name=newFileName(acc_num,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);

	mainfile=fopen(file_name,"r");
	tempfile=fopen("D:\\project_bank\\temp.txt","w");

	while( (fgets(old_line,50,mainfile) != NULL) )
	{
		if(count == line)
		{
			fprintf(tempfile,"%s",new_line);
			count++;
		}

		else
		{
			if( count == line+1 )
			{
				fprintf(tempfile,"\n%s",old_line);
			}
			else
			{
				fprintf(tempfile,"%s",old_line);
			}

			count++;
		}
		if(count == 9)
		   break;
	}

	fclose(mainfile);
	fclose(tempfile);
	remove(file_name);
	rename("D:\\project_bank\\temp.txt",file_name);
	printf("\n\n\t\t\tSUCCESS");
	getch();
}

void update_password(long int acc_num)
{
	FILE *mainfile,*tempfile;
	int count=0,line=2,len_code;
	char *new_line=(char *)malloc(sizeof(char)*50);
	char *old_line=(char *)malloc(sizeof(char)*50);

	system("cls");
	printf("\n\n\n\t\t\t: : : : UPDATE PASSWORD : : : :");
	printf("\n\n\n\n\t\tEnter New  8 digit Password : ");
	scanf("%s",new_line);
	len_code=strlen(new_line);

	if(len_code == 8)
	{
		char *new_name=newFileName(acc_num,".txt");
		char *file_name=merge("D:\\project_bank\\",new_name);

		mainfile=fopen(file_name,"r");
		tempfile=fopen("D:\\project_bank\\temp.txt","w");

		while( (fgets(old_line,50,mainfile) != NULL) )
		{
			if(count == line)
			{
				fprintf(tempfile,"%s",new_line);
				count++;
			}

			else
			{
				if( count == line+1 )
				{
					fprintf(tempfile,"\n%s",old_line);
				}
				else
				{
					fprintf(tempfile,"%s",old_line);
				}

				count++;
			}
			if(count == 9)
			   break;
		}

		fclose(mainfile);
		fclose(tempfile);
		remove(file_name);
		rename("D:\\project_bank\\temp.txt",file_name);
		printf("\n\n\t\t\tSUCCESS");
		getch();
	}
	else
	{
		printf("\n\n\n\t\tPlease Enter Correct Size Of Password !!");
		update_password(acc_num);
	}
}

void update_contact(long int acc_num)
{
	FILE *mainfile,*tempfile;
	int count=0,line=5,len_no;
	char *new_line=(char *)malloc(sizeof(char)*20);
	char *old_line=(char *)malloc(sizeof(char)*50);

	system("cls");
	printf("\n\n\n\t\t\t: : : : UPDATE PHONE NUMBER : : : :");
	printf("\n\n\n\n\t\tEnter New Contact Number : ");
	scanf("%s",new_line);
	len_no=strlen(new_line);

	if( (new_line[0] >= '7') && (len_no == 10) )
	{
		char *new_name=newFileName(acc_num,".txt");
		char *file_name=merge("D:\\project_bank\\",new_name);

		mainfile=fopen(file_name,"r");
		tempfile=fopen("D:\\project_bank\\temp.txt","w");

		while( (fgets(old_line,50,mainfile) != NULL) )
		{
			if(count == line)
			{
				fprintf(tempfile,"%s",new_line);
				count++;
			}

			else
			{
				if( count == line+1 )
				{
					fprintf(tempfile,"\n%s",old_line);
				}
				else
				{
					fprintf(tempfile,"%s",old_line);
				}

				count++;
			}
			if(count == 9)
				break;
		}

		fclose(mainfile);
		fclose(tempfile);
		remove(file_name);
		rename("D:\\project_bank\\temp.txt",file_name);
		printf("\n\n\t\t\t SUCCESS !!");
		getch();
	}
	else
	{
		printf("\n\n\n\t\tPlease Enter Correct Number !!");
		update_contact(acc_num);
	}
}

void update_details(long int acc_num)
{
	char *caller=(char *)malloc(sizeof(char)*10);
	int ch;

		printf("\n\n\n\t\t\t <-------- UPDATE DETAILS -------->");
		printf("\n\n\n\t\t1.Update Username");
		printf("\n\n\t\t2.Update Password");
		printf("\n\n\t\t3.Update Contact Number");
		printf("\n\n\n\t---->\tEnter Your Choice : ");
		scanf("%d",&ch);
		system("cls");
		loader();
		system("cls");

		switch(ch)
		{
			case 1:update_Username(acc_num);
				break;
			case 2:update_password(acc_num);
				break;
			case 3:update_contact(acc_num);
				break;
			default:printf("\n\n\t\t Incorrect Choice !!!");
				break;
		}

		printf("\n\n\n\n\t\tDo You Want To Change Something Else ?");
		printf("\n\n\tEnter 1 To Update Again Or Any Character To Go Back : ");
		scanf("%s",caller);

		if( strcmp(caller,"1") == 0 )
		{
			system("cls");
			update_details(acc_num);
		}
}

void loan_sanction(long int acc_num,int type_of_loan)
{
	long int mnth_sal;
	int interest,loan_amount,time_period,check_amount,time_ch,flag,EMI;
	mnth_sal=get_salary(acc_num);
	system("cls");

	if(type_of_loan == 1)
	{
		printf("\n\n\n\t\t ********** <<<<< PERSONAL LOAN >>>>> **********");
		printf("\n\n\n\t(NOTE : Amount Should Be Between 1 Lakh -- 10 Lakhs)");
		printf("\n\n\n\t---->\tEnter Loan Amount : ");
		scanf("%d",&loan_amount);
		printf("\n\t---->\tPlease Re-Enter The Amount : ");
		scanf("%d",&check_amount);

		if( (loan_amount >= 100000 && loan_amount <= 1000000) && (loan_amount == check_amount) )
		{
			system("cls");
			printf("\n\n\n\t\t ********** <<<<< PERSONAL LOAN >>>>> **********");
			printf("\n\n\n\t---->\t Amount Taken On Loan : %d",loan_amount);
			printf("\n\n\t\tRate Of Interest : 20 percent");
			while(1)
			{
				printf("\n\n\t\tTime Period : Choose An Option");
				printf("\n\n\t\t\t1. 8 Years");
				printf("\n\t\t\t2. 10 Years");
				printf("\n\t\t\t3. 12 Years");
				printf("\n\n\t\tChoose Your Option : ");
				scanf("%d",&time_ch);
					switch(time_ch)
					{
						case 1:time_period=8;
								flag=1;
							break;
						case 2:time_period=10;
								flag=1;
							break;
						case 3:time_period=12;
								flag=1;
							break;
						default:printf("Incorrect Choice");
							break;
					}
					if(flag == 1)
						break;
			}

			interest = ((loan_amount*20)/100) * time_period;
			EMI = (loan_amount+interest) / (time_period*12);

			if( EMI <= (mnth_sal/2) )
			{
				FILE *file_loan;
				char *new_name_loan=newFileName(acc_num,"_loan.txt");
				char *file_loan_name=merge("D:\\project_bank\\",new_name_loan);

				file_loan=fopen(file_loan_name,"w");
				fprintf(file_loan,"%s\n","Loan Type : PERSONAL LOAN");
				printf("\n\n\t\tLoan EMI : %d",EMI);
				fprintf(file_loan,"%d\n",EMI);
				printf("\n\n\t\tTotal Interest Payable : %d",interest);
				fprintf(file_loan,"%d\n",interest);
				printf("\n\n\t\tTotal Payment : %d", (interest+loan_amount) );
				fprintf(file_loan,"%d\n",(interest+loan_amount));
				fprintf(file_loan,"%d\n", (time_period * 12) );

				time_t loan_time;
				time(&loan_time);
				struct tm *info;
				info=localtime(&loan_time);
				char *time_loan_start=(char *)malloc(sizeof(char)*12);
				sprintf(time_loan_start,"%d/%d/%d",(*info).tm_mday,(*info).tm_mon+1,(*info).tm_year+1900);
				fprintf(file_loan,"%s\n",time_loan_start);
				fprintf(file_loan,"%d\n",0);
				fprintf(file_loan,"%d\n",0);
				printf("\n\n\t--->NOTE : You Can Check Your Details At User Options");
				fclose(file_loan);
			}
		}

		else
		{
			printf("\n\n\t\tPlease Enter Correct Amount !! \n\t\tPress Any Key To Enter Again");
			getch();
			loan_sanction(acc_num,type_of_loan);
		}
	}

	if(type_of_loan == 2)
	{
		printf("\n\n\n\t\t ********** <<<<< HOME LOAN >>>>> **********");
		printf("\n\n\n\t(NOTE : Amount Should Be Between 10 Lakh -- 25 Lakhs)");
		printf("\n\n\n\t---->\tEnter Loan Amount : ");
		scanf("%d",&loan_amount);
		printf("\n\t---->\tPlease Re-Enter The Amount : ");
		scanf("%d",&check_amount);

		if( (loan_amount >= 1000000 && loan_amount <= 2500000) && (loan_amount == check_amount) )
		{
			system("cls");
			printf("\n\n\n\t\t ********** <<<<< HOME LOAN >>>>> **********");
			printf("\n\n\n\t---->\t Amount Taken On Loan : %d",loan_amount);
			printf("\n\n\t\tRate Of Interest : 9 percent");
			while(1)
			{
				printf("\n\n\t\tTime Period : Choose From Below Options -->");
				printf("\n\n\t\t\t1. 8 Years");
				printf("\n\t\t\t2. 10 Years");
				printf("\n\t\t\t3. 12 Years");
				printf("\n\n\t\tChoose Your Option : ");
				scanf("%d",&time_ch);

				switch(time_ch)
				{
					case 1:time_period=8;
							flag=1;
						break;
					case 2:time_period=10;
							flag=1;
						break;
					case 3:time_period=12;
							flag=1;
						break;
					default:printf("Incorrect Choice");
						break;
				}

				if(flag == 1)
					break;
			}

			interest= (((loan_amount*9)/100)*time_period);
			EMI=(loan_amount+interest)/(time_period*12);

			if( EMI <= (mnth_sal/2) )
			{
				FILE *file_loan;
				char *new_name_loan=newFileName(acc_num,"_loan.txt");
				char *file_loan_name=merge("D:\\project_bank\\",new_name_loan);

				file_loan=fopen(file_loan_name,"w");
				fprintf(file_loan,"%s","Loan Type : HOME LOAN");
				printf("\n\n\t\tLoan EMI : %d",EMI);
				fprintf(file_loan,"\n%d",EMI);
				printf("\n\n\t\tTotal Interest Payable : %d",interest);
				fprintf(file_loan,"\n%d",interest);
				printf("\n\n\t\tTotal Payment : %d", (interest+loan_amount) );
				fprintf(file_loan,"\n%d",(interest+loan_amount));
				fprintf(file_loan,"\n%d", (time_period * 12) );

				time_t loan_time;
				time(&loan_time);
				struct tm *info;
				info=localtime(&loan_time);
				char *time_loan_start=(char *)malloc(sizeof(char)*12);
				sprintf(time_loan_start,"%d/%d/%d",(*info).tm_mday,(*info).tm_mon+1,(*info).tm_year+1900);
				fprintf(file_loan,"\n%s",time_loan_start);
				fprintf(file_loan,"\n%d ",0);
				fprintf(file_loan,"\n%d",0);
				printf("\n\n\t--->NOTE : You Can Check Your Details At User Options");
				fclose(file_loan);
			}

			else
			{
				printf("\n\n\t\tSorry Loan Is Not Approved Since Your Income Is Low,\n\t\tPlease Try Another Time Period For Loan");
				getch();
				loan_sanction(acc_num,type_of_loan);
			}
		}

		else
		{
			printf("Please Enter Correct Amount !! Press Any Key To Enter Again");
			getch();
			loan_sanction(acc_num,type_of_loan);
		}
	}
	getch();
}

void Loan(int check_prev_loan,long int acc_num)
{
	if(check_prev_loan == 1)
	{
		system("cls");
		printf("\n\n\n\t\t ********** <<<<< LOAN OPTIONS >>>>> **********");
		printf("\n\n\t-->> NOTE: YOU HAVE ALREADY TAKEN LOAN");
		printf("\n\n\t\t\t CLEAR PREVIOUS LOAN FOR A NEW LOAN");
		printf("\n\n\t\tEnter Any Chracter To Go Back");
		getch();
	}

	else
	{
		int option,loan_exit;

		while(1)
		{
			system("cls");
			printf("\n\n\n\t\t ********** <<<<< LOAN OPTIONS >>>>> **********");
			printf("\n\n\t\t1. Personal Loan");
			printf("\n\n\t\t2. Home Loan");
			printf("\n\n\t\t3. Go Back");
			printf("\n\n\t\t Enter Your Choice : ");
			scanf("%d",&option);

				switch(option)
				{
					case 1:loan_sanction(acc_num,option);
							loan_exit=1;
						break;
					case 2:loan_sanction(acc_num,option);
							loan_exit=1;
						break;
					case 3:loan_exit=1;
						break;
					default:printf("Incorrect Choice");
						break;
				}
			if(loan_exit == 1)
				break;
		}
	}
}

int check_loan_status(long int acc_num)
{
	FILE *check_file;
	char *new_name_loan=newFileName(acc_num,"_loan.txt");
	char *file_loan_name=merge("D:\\project_bank\\",new_name_loan);

	if( (check_file=fopen(file_loan_name,"r")) != NULL )
	{
		fclose(check_file);
		return 1;
	}
	else
	{
		fclose(check_file);
		return 0;
	}
}

void loan_details(long int acc_num)
{
	int count=0;
	FILE *loan_file;
	printf("\n\n\n\t\t ********** <<<<< LOAN DETAILS >>>>> **********");
	char *new_name_loan=newFileName(acc_num,"_loan.txt");
	char *file_loan_name=merge("D:\\project_bank\\",new_name_loan);
	char *output=(char *)malloc(sizeof(char)*30);
	loan_file=fopen(file_loan_name,"r");

	if(loan_file != NULL)
	{
		while(fgets(output,40,loan_file) != NULL)
		{
			if(count == 0)
				printf("\n\n\t\t%s",output);
			if(count == 1)
				printf("\n\n\t\tEMI Amount : %s",output);
			if(count == 2)
				printf("\n\n\t\tINTEREST : %s",output);
			if(count == 3)
				printf("\n\n\t\tTotal Payable : %s",output);
			if(count == 4)
				printf("\n\n\t\tTime Duration : %s months",output);
			if(count == 5)
				printf("\n\n\t\tTook Loan On : %s",output);
			if(count == 6)
				printf("\n\n\t\tAmount Paid Till Now :%s",output);
			if(count == 7)
				printf("\n\n\t\tNo. of Months Paid : %s months",output);


			count++;
		}
	}

	else
		printf("\n\n\n--->\tNOTE : You Have Cleared Your Loan Or You Did Not Take A Loan\t");

	fclose(loan_file);
	printf("\n\n\t\tEnter Any Key To Go Back ");
	getch();
}

void edit_loan_details(long int acc_num)
{
	system("cls");
	FILE *loan_file;
	struct tm *info;
	printf("\n\n\t\tIn Edit Fun");
	int EMI_line,paid_line,months_paid_line,count=0,total_months_line,loan_amount_line,temp;
	char *string=(char *)malloc(sizeof(char)*30);
	char *str_for_date=(char *)malloc(sizeof(char)*15);
	char *str_for_EMI=(char *)malloc(sizeof(char)*15);
	char *str_for_paid=(char *)malloc(sizeof(char)*15);
	char *str_for_months_paid=(char *)malloc(sizeof(char)*15);
	char *str_for_total_months=(char *)malloc(sizeof(char)*15);
	char *str_for_total_loan=(char *)malloc(sizeof(char)*15);
	char *new_name_loan=newFileName(acc_num,"_loan.txt");
	char *file_loan_name=merge("D:\\project_bank\\",new_name_loan);
	loan_file=fopen(file_loan_name,"r");

	while( fgets(string,30,loan_file) != NULL )
	{
		if(count == 1)
		{
			strcpy(str_for_EMI,string);
			EMI_line=char_to_int(str_for_EMI);
		}

		if(count == 3)
		{
			strcpy(str_for_total_loan,string);
			loan_amount_line=char_to_int(str_for_total_loan);
		}

		if(count == 4)
		{
			strcpy(str_for_total_months,string);
			total_months_line=char_to_int(str_for_total_months);
		}

		if(count == 5)
		{
			strcpy(str_for_date,string);
		}

		if(count == 6)
		{
			strcpy(str_for_paid,string);
			paid_line=char_to_int(str_for_paid);
		}

		if(count == 7)
		{
			strcpy(str_for_months_paid,string);
			months_paid_line=char_to_int(str_for_months_paid);
		}

		if(count == 8)
		   break;

		count++;
	}
	fclose(loan_file);

	if( total_months_line == months_paid_line )
	{
		if( abs(paid_line - loan_amount_line) <= 400 )
			temp=1;
	}

	else
	{
		time_t new_time;
		time(&new_time);
		static char date_instant[15];
		info=localtime(&new_time);
		sprintf(date_instant,"%d/%d/%d",(*info).tm_mday,(*info).tm_mon+1,(*info).tm_year+1900);

		months_paid_line=month_difference(str_for_date,date_instant);

		if(months_paid_line < total_months_line)
			paid_line= ( EMI_line * months_paid_line);

		else if(months_paid_line == total_months_line)
		{
			paid_line=( EMI_line * months_paid_line );

			if( abs( paid_line - loan_amount_line ) <= 400 )
				temp=1;
		}

		else
		{
			paid_line =( EMI_line * total_months_line );
			months_paid_line= total_months_line;
			temp=1;
		}

		FILE *temp_loan_file,*main_loan_file;
		char *print_in_temp=(char *)malloc(sizeof(char)*30);
		main_loan_file=fopen(file_loan_name,"r");
		temp_loan_file=fopen("D:\\project_bank\\temp_loan.txt","w");
		count=0;

		while(fgets(print_in_temp,30,main_loan_file) != NULL)
		{
			if(count == 6)
			{
				str_for_paid=int_to_char(paid_line);
				strcpy(print_in_temp,str_for_paid);
				fprintf(temp_loan_file,"%s",print_in_temp);
			}

			else if(count == 7)
			{
				fprintf(temp_loan_file,"\n%d",months_paid_line);
				break;
			}

			else
				fprintf(temp_loan_file,"%s",print_in_temp);

			count++;
		}

		fclose(main_loan_file);
		fclose(temp_loan_file);
		remove(file_loan_name);
		rename("D:\\project_bank\\temp_loan.txt",file_loan_name);
	}
	if(temp == 1)
	   remove(file_loan_name);
}

void electricity_bill(long int acc_num)
{
	int len_bill_no,len_area_code;
	char *bill_no=(char *)malloc(sizeof(char)*20);
	char *area_code=(char *)malloc(sizeof(char)*20);

	system("cls");
	printf("\n\n\n\t\t ********** <<<<< ELECTRICITY BILL >>>>> **********");
	printf("\n\n\n  -->Enter The BILL Number Printed On Electricity Bill (length 10) : ");
	scanf("%s",bill_no);
	printf("\n\n\n\t\tEnter Your Area Code (length 10) : ");
	scanf("%s",area_code);

	len_bill_no=strlen(bill_no);
	len_area_code=strlen(area_code);

	if(len_bill_no != 10 || len_area_code != 10)
	{
		printf("\n\n\t\tPlease Enter Correct Length Of BILL NUMBER Or AREA CODE");
		electricity_bill(acc_num);
	}
	else
	{
		FILE *mainfile,*tempfile;
		int line_to_delete=7,count=0;
		long int balance;
		char *info;
		char *answer=(char *)malloc(sizeof(char)*15);
		srand(time(0));
		int bill_amount=rand();


		printf("\n\n\t\tThe Amount To Be Paid  : %d",bill_amount);
		printf("\n\n\tDo You Want To Pay The Amount ? Enter ('Y'/'y') To Pay : ");
		scanf("%s",answer);

		if( (strcmp(answer,"y") == 0) || (strcmp(answer,"Y") == 0) )
		{
			int balance_line=7;
			FILE *acc_file;
			char *new_name=newFileName(acc_num,".txt");
			char *file_name=merge("D:\\project_bank\\",new_name);
			char *str=(char *)malloc(sizeof(char)*20);
			acc_file=fopen(file_name,"r");

			while(fgets(str,25,acc_file) != NULL)
			{
				if(count == balance_line)
					break;
				else
					count++;
			}

			balance=char_to_int(str);
			if(balance >= bill_amount)
			{
				balance-=bill_amount;
				fclose(acc_file);
				mainfile=fopen(file_name,"r");
				tempfile=fopen("D:\\project_bank\\temp.txt","w");
				count=0;

				while(fgets(str,25,mainfile) != NULL)
				{
					if(count == line_to_delete)
					{
						fprintf(tempfile,"%ld",balance);
						count++;
					}

					else
					{
						if( count == (line_to_delete+1) )
						{
							fprintf(tempfile,"\n%s",str);
						}
						else
						{
							fprintf(tempfile,"%s",str);
						}
						count++;
					}
					if(count == 9)
					   break;
				}

				fclose(mainfile);
				fclose(tempfile);
				remove(file_name);
				rename("D:\\project_bank\\temp.txt",file_name);
				printf("\n\n\t\tYou SuccessFully Paid the Amount");
				printf("\n\n\t---->\t  Your Balance Is : %ld",balance);

				info=newFileName(bill_amount,"-- Electricity bill");
				transaction_history(bill_amount,info,acc_num);
				getch();
			}
			else
			{
				printf("\n\n\tNOTE : You Can't Pay Phone Bill Since Your Account Balance Is Too Low");
				getch();
			}
		}
		else
		{
			printf("\n\n\t\tProcess Cancelled.....");
			Sleep(2000);
		}
	}
}

void edu_bill(long int acc_num)
{
	long int balance;
	int count=0,balance_line=7,line_to_delete=7;
	FILE *acc_file;
	char *new_name=newFileName(acc_num,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	acc_file=fopen(file_name,"r");
	char *str=(char *)malloc(sizeof(char)*25);
	char *answer=(char *)malloc(sizeof(char)*10);
	char *clg_code=(char *)malloc(sizeof(char)*25);;
	char *roll_no=(char *)malloc(sizeof(char)*25);
	system("cls");
	printf("\n\n\n\t\t ********** <<<<< SCHOOL/COLLEGE FEE >>>>> **********");
	printf("\n\n\n\t\tEnter Institution CODE : ");
	scanf("%s",clg_code);
	printf("\n\n\t\tEnter Roll No.Of Student : ");
	scanf("%s",roll_no);
	srand(time(0));
	int fee_amount=rand();

	while(fgets(str,20,acc_file) != NULL)
	{
		if(count == balance_line)
			break;
		else
			count++;
	}

	balance=char_to_int(str);
	printf("\n\n\t\tThe Amount To Be Paid  : %d",fee_amount);
	printf("\n\n\t\tDo You Want To Pay The Amount ? Enter ('Y'/'y') To Pay : ");
	scanf("%s",answer);

	if( (strcmp(answer,"y") == 0) || (strcmp(answer,"Y") == 0) )
	{
		if(balance >= fee_amount)
		{
			FILE *mainfile,*tempfile;
			char *info=(char *)malloc(sizeof(char)*50);

			balance-=fee_amount;
			fclose(acc_file);
			mainfile=fopen(file_name,"r");
			tempfile=fopen("D:\\project_bank\\temp.txt","w");
			count=0;

			while(fgets(str,25,mainfile) != NULL)
			{
				if(count == line_to_delete)
				{
					fprintf(tempfile,"%ld",balance);
					count++;
				}

				else
				{
					if( count == (line_to_delete+1) )
					{
						fprintf(tempfile,"\n%s",str);
					}
					else
					{
						fprintf(tempfile,"%s",str);
					}
					count++;
				}
				if(count == 9)
				   break;
			}

			fclose(mainfile);
			fclose(tempfile);
			remove(file_name);
			rename("D:\\project_bank\\temp.txt",file_name);
			printf("\n\n\t\tYou SuccessFully Paid The Amount");
			printf("\n\n\t---->\t  Your Balance Is : %ld",balance);

			info=newFileName(fee_amount,"-- Education Fee");
			transaction_history(fee_amount,info,acc_num);
			getch();
		}
		else
		{
			printf("\n\n\tNOTE : You Can't Pay Phone Bill Since Your Account Balance Is Too Low");
			getch();
		}
	}
	else
	{
		printf("\n\n\t\t Process Cancelled");
		Sleep(2000);
	}
}

void phone_bill(long int acc_num)
{
	long int balance;
	int count=0,no_line=5,balance_line=7,line_to_delete=7;
	char *str=(char *)malloc(sizeof(char)*25);
	char *answer=(char *)malloc(sizeof(char)*10);
	char phone_no[25];
	srand(time(0));
	int phone_bill=rand();
	FILE *acc_file;
	char *new_name=newFileName(acc_num,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	char *info=(char *)malloc(sizeof(char)*20);
	acc_file=fopen(file_name,"r");

	system("cls");
	printf("\n===============================================================================");
	printf("\n\t\t                     <<< PHONE BILL >>>                              ");
	printf("\n===============================================================================");

	while(fgets(str,25,acc_file) != NULL)
	{
		if(count == no_line)
			strcpy(phone_no,str);
		if(count == balance_line)
		{
			break;
		}
		else
		   count++;
	}

	balance=char_to_int(str);
	printf("\n\n\t\tYour Phone Number Is : %s",phone_no);
	printf("\n\n\t\tYour Phone Bill Is : %d",phone_bill);
	printf("\n\n\t\tDo You Want To Pay The Amount ? Enter ('Y'/'y') To Pay : ");
	scanf("%s",answer);

	if( (strcmp(answer,"y") == 0) || (strcmp(answer,"Y") == 0) )
	{
		if(balance >= phone_bill)
		{
			FILE *mainfile,*tempfile;

			balance-=phone_bill;
			fclose(acc_file);
			mainfile=fopen(file_name,"r");
			tempfile=fopen("D:\\project_bank\\temp.txt","w");
			count=0;

			while(fgets(str,22,mainfile) != NULL)
			{
				if(count == line_to_delete)
				{
					fprintf(tempfile,"%ld",balance);
					count++;
				}

				else
				{
					if( count == (line_to_delete+1) )
					{
						fprintf(tempfile,"\n%s",str);
					}
					else
					{
						fprintf(tempfile,"%s",str);
					}
					count++;
				}

				if(count == 9)
				   break;
			}

			fclose(mainfile);
			fclose(tempfile);
			remove(file_name);
			rename("D:\\project_bank\\temp.txt",file_name);
			printf("\n\n\t\tYou SuccessFully Paid The Amount");
			printf("\n\n\t---->\t  Your Balance Is : %ld",balance);

			info=newFileName(phone_bill,"-- Education Fee");
			transaction_history(phone_bill,info,acc_num);
			getch();
		}
		else
		{
			printf("\n\n\tNOTE : You Can't Pay Phone Bill Since Your Account Balance Is Too Low");
			getch();
		}
	}

	else
	{
		printf("\n\n\t\t Process Cancelled.....");
		Sleep(2000);
	}
}

void E_payments(long int acc_num)
{
	int e_option,exit_e_payment=0;

	while(1)
	{
		system("cls");
		printf("\n===============================================================================");
		printf("\n\t                          < E-PAYMENTS OPTIONS >                 ");
		printf("\n===============================================================================");
		printf("\n\n\n\t\t1. Electricity Bill");
		printf("\n\n\t\t2. College/School Fee");
		printf("\n\n\t\t3. Phone Bill");
		printf("\n\n\t\t4. Go Back");
		printf("\n\n\t\tEnter Your Choice : ");
		scanf("%d",&e_option);

		switch(e_option)
		{
			case 1:electricity_bill(acc_num);
				break;
			case 2:edu_bill(acc_num);
				break;
			case 3:phone_bill(acc_num);
				break;
			case 4:exit_e_payment=1;
				break;
			default:printf("\n\n\t\tIncorrect Choice");
				break;
		}
		if(exit_e_payment == 1)
			   break;
	}
}

void user_options(long int acc_num)
{
	int ch,loan_taken=0,exit_login=0;
	loan_taken=check_loan_status(acc_num);
	edit_balance(acc_num);

	if(loan_taken == 1)
	{
		edit_loan_details(acc_num);
	}

	while(1)
	{
		system("cls");
		printf("\n===============================================================================");
		printf("\n\t                    << USER OPTIONS >>                      ");
		printf("\n===============================================================================");
		printf("\n\n\n\t\t1. Balance Enquery");
		printf("\n\n\t\t2. Withdraw Cash");
		printf("\n\n\t\t3. Deposit Cash");
		printf("\n\n\t\t4. Fixed Deposit");
		printf("\n\n\t\t5. Details Of Your Account");
		printf("\n\n\t\t6. Delete Account");
		printf("\n\n\t\t7. Update Details");
		printf("\n\n\t\t8. Take A Loan");
		printf("\n\n\t\t9. Loan Details");
		printf("\n\n\t\t10. E-Payments");
		printf("\n\n\t\t11. Go Back");

		printf("\n\n\n\t---->\tEnter your choice : ");
		scanf("%d",&ch);
		system("cls");
		loader();
		system("cls");

		switch(ch)
		{
			case 1:Balance_enquiry(acc_num);
				break;
			case 2:withdraw(acc_num);
				break;
			case 3:deposit(acc_num);
				break;
			case 4:f_d(acc_num);
				break;
			case 5:Details_of_user(acc_num);
				break;
			case 6:delete_account(acc_num);
				break;
			case 7:update_details(acc_num);
				break;
			case 8:Loan(loan_taken,acc_num);
				break;
			case 9:loan_details(acc_num);
				break;
			case 10:E_payments(acc_num);
				break;
			case 11:exit_login=1;
				break;
			default:printf("\nIncorrect Choice");
				break;
		}
		if(exit_login == 1)
			   break;
	}
}

int compare(char *str1,char *str2)
{
	int q,len1=strlen(str1)-1,len2=strlen(str2),count=0;

	if(len1 == len2)
	{
		for(q=0; q < len1; q++)
		{
			if(str1[q] == str2[q])
				count++;
		}

		if(count == len1)
			return 1;
		else
			return 0;
	}
	else
	   return 0;
}

void log_in()
{
	FILE *fp;
	long int input_acc;
	int flag=0,count=0,password_line=2,result;
	char *input_password=(char *)malloc(sizeof(char)*10);
	char *passcode=(char *)malloc(sizeof(char)*10);
	char *choice=(char *)malloc(sizeof(char)*25);;

	system("cls");
	printf("\n===============================================================================");
	printf("\n\t\t                    LOGIN PAGE                                      ");
	printf("\n===============================================================================");
	printf("\n\n\n\n\t\tACCOUNT NUMBER : ");
	scanf("%ld",&input_acc);
	printf("\n\n\t\tPASSWORD : ");
	scanf("%s",input_password);

	char *new_name=newFileName(input_acc,".txt");
	char *file_name=merge("D:\\project_bank\\",new_name);
	fp=fopen(file_name,"r");

	if(fp != NULL)
	{
		while(fgets(passcode,15,fp) != NULL)
		{
			if(count == password_line)
				break;
			else
				count++;
		}

		result=compare(passcode,input_password);
		if( result == 1 )
		{
			loader();
			system("cls");
			fclose(fp);
			user_options(input_acc);
		}

		else
		{
			flag=1;
			printf("\n\n\t\tIncorrect Password");
		}
	}

	else
	{
		flag=1;
		printf("\n\n\t\tPlease Enter a Valid Account Number");
	}

	if(flag == 1)
	{
		printf("\n\n\n\tEnter 1 To Log In Again Or Any Character To Exit : ");
		scanf("%s",choice);

		if( strcmp(choice,"1") == 0 )
			log_in();
	}
	fclose(fp);
}

int main()
{
	int ch;
	system("COLOR 3F");
		loader();
	system("cls");
	system("COLOR 1F");

	create_no_files_file();

	while(1)
	{
		system("cls");
		system("");
		printf("\n=======================================================================================================================");
		printf("\n\t\t\t                          BANK MANAGEMENT SYSTEM                        ");
		printf("\n=======================================================================================================================");
		printf("\n\n\n\n\t\t\t\t\t1. Create Account");
		printf("\n\n\n\t\t\t\t\t2. Log In Account");
		printf("\n\n\n\t\t\t\t\t3. Exit\n");

		printf("\n\n\n\n\t\t\tEnter your choice : ");
		scanf("%d",&ch);
		system("cls");
		loader();
		system("cls");

		switch(ch)
		{
			case 1:create_account();
				break;
			case 2:log_in();
				break;
			case 3:exit(0);
				break;
			default:printf("\nIncorrect Choice");
				break;
		}
	}
	return 0;
}




