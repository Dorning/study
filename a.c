/*******************************************************
*   Simple Student Information Management by Dorning   *
*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N        100
#define LEN_NAME 20
#define LEN_STR  12

struct Stu_info {
	char no    [LEN_STR], 
		 name  [LEN_NAME],
		 date  [LEN_STR], 
		 phone [LEN_STR], 
		 qq    [LEN_STR];
		 
	int  sex, 
		 age;
	/* could use enum in VAR sex */
}	stu[N];

int n=0;

/* basic functions *******************************************************/

int input_bool(void) {
	char z;
	int  flag;
	scanf("%c",&z); while(getchar()!='\n');
	
	if(z=='1' || z=='m' || z=='y')
		flag=1;
	else if(z=='0' || z=='f' || z=='n')
		flag=0;
	else {	
		printf("   Error!Enter Again! >>");
		flag = input_bool();
	}
	return flag;
}

int input_num(int min, int max) {
	int i, z;
	i=scanf("%d",&z); while(getchar()!='\n');
	
	if(!i || z<min || z>max) {	
		printf("   Error!Enter Again! >>");
		z = input_num(min, max);
	}
	return z;
}

char* input_str(void) {
	int i, flag=0;
	char *p, z[LEN_STR]="";
	p = z;
	scanf("%s",&z);
	while(getchar()!='\n') {
		flag=1;
		printf("   OOPS! Data's Too Long!\n");
		while(getchar()!='\n');
	}
	if(flag) {
		printf("   Retry? y/n >>");
		if(input_bool()) p=input_str();
	}
	for(i=0;i<strlen(z);i++) {
		if(z[i]<48 || z[i]>57) {	
			printf("   Error!Enter Again! >>");
			p = input_str();
			break;
		}
	}
	return p;
}

int show(int m) {
					/* [m] in the ARRAY stu[N], 0~(n-1) */
	if(stu[m].no !="" && stu[m].name !="") {
		printf("Student Messages.\n");
		printf("#  No.\t\tName\t\tSex\tAge\tBirthday\t\tphone\t\tqq\t\t\n");
		printf("%d  %s\t%s\t", m+1, stu[m].no, stu[m].name);
		if(stu[m].sex) printf(" Male\t");
		else 		   printf("Female\t");
		printf("%d\t%s\t%s\t%s\t\n",stu[m].age,stu[m].date,
									stu[m].phone,stu[m].qq);
		return 1;
	}
	else {
		printf("Error 404: No Data!\n");
		return 0;
	}
}

int compare_no(char a, char b) {
	int flag;
	
	if(strtol(a, NULL, 0) == strtol(b, NULL, 0)) flag=0;
	if(strtol(a, NULL, 0) <  strtol(b, NULL, 0)) flag=1;
	if(strtol(a, NULL, 0) >  strtol(b, NULL, 0)) flag=-1;
	
	return flag;
}

/*** add a Stu_info data ****************************************/

struct Stu_info add(int m) {
							/* No.m in the queue of new stus, 0~(n-1) */
	struct Stu_info s;
	system("clear");
	printf("#%d Enter Student Informations.\n", m+1);
	
	printf("   Student's No       >>");
	scanf("%s",&s.no); while(getchar()!='\n');
	printf("   Student's Name     >>");
	scanf("%s",&s.name); while(getchar()!='\n');
	
	printf("   Student's Age      >>");
	s.age = input_num(10, 30);
	printf("   Male(m), Female(f) >>");
	s.sex = input_bool();
	
	printf("   Student's Birthday >>");
	scanf("%s",&s.date); while(getchar()!='\n');
	printf("   Student's Phone    >>");
	scanf("%s",&s.phone); while(getchar()!='\n');
	printf("   Student's QQ       >>");
	scanf("%s",&s.qq); while(getchar()!='\n');
	
	return s;
}

/*** functions in the menu ************************************************/

void ins(void) {
	int i, j, k, sn;
	struct Stu_info z;
	system("clear");
	
	printf("Number of Students:");
	sn = input_num(1, N-n-1);
	
	for(i=0;i<sn;i++) {
		z = add(i);
		for(j=0;j<n;j++) {
			if( !compare_no(z.no, stu[j].no) ) {
				printf("Error!\n");
				i--;
				break;
			} 
			else if( compare_no(z.no, stu[j].no)   == 1  && 
					 compare_no(z.no, stu[j+1].no) == -1 ) {
					 
				for(k=n-1;k>j+1;k--)
					stu[k]=stu[k-1];
				stu[j+1]=z;
				n++;
				break;
			}
		}
	}
	
	/* inserting finished. write over to a file. */
	
	system("clear");
	printf("\t\t\t\t# Data Get!");
	printf("\t\t\t\t# Export the data? y/n >>");
	i=input_bool();
	
	if(i) { /* then export the data */
		if(sn==n) {
			/* create a file */
		}
		else if(sn<n) {
			/* update a file */
		}
		else {
			/* error! */
		}
	}
	main();
}

void del(int m) {
	int i;
	for(i=m-1;i<n;i++) {
		stu[i]=stu[i+1];
	}
	main();
}

void ovr(int m) {
	system("clear");
	printf("Enter Corrected Mseeages:\n");
	stu[m]=add(m);
	main();
}

/*
void srch(char s, int a, int f) {
	int i, flag[N]={0};
	if(s!='\0') {
		switch(f)
		
		for(i=0;i<n;i++)
			if(s==stu[i].no)
				flag[i]=1;
	}
	if(s.name!='*') {
		for(i=0;i<n;i++)
			if(s.no==stu[i].no)
				flag[i]=1;
	}
	
	for(i=0;i<n;i++)
		if(flag[i]) show(stu[i]);
	
	main();
}
*/

/*** main function ********************************************************/

int init_info() {
	if(i) {
		
		
		
		return 0;
	}	//import();		/* and you can import data from an existing file */
	else {
		ins(); return 0;			/* then input by hand */
	}
	return 1;
}

int main(void) {
	int i, j=1;
	
	while(j) {
		j=init_info();
	}
	
	system("clear");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t************************************************\n");
	printf("\t\t\t\t*                    Menu                     *\n");
	printf("\t\t\t\t*                #1. add                       *\n");
	printf("\t\t\t\t*                #2. delete                    *\n");
	printf("\t\t\t\t*                #3. write                     *\n");
	printf("\t\t\t\t*                #4. search                    *\n");
	printf("\t\t\t\t*                #5. exit                      *\n");
	printf("\t\t\t\t************************************************\n");
	printf("\t\t\t\t# What would you like to do? >>\n");
	i = input_num(1, 5);
	
	switch(i) {
		case 1 : ins(); break;
		case 2 : del(); break;
		case 3 : ovr(); break;
		case 4 : srch(); break;
		default: printf("\t\t\t\t# Never Mind! \n");
	}
	system("pause");
	exit(0);
}


