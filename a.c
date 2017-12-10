#include<stdio.h>
#include<stdlib.h>
#define N 100

struct Std {
	char no[12], name[20], date[12], phone[12], qq[12];
	int sex, age;
} st[N];

int n=0;

/*** return a Std data *******************************************************/

int ipbl(void) {
	int z;
	scanf("%d",&z); while(getchar()!='\n');
	
	if(z!=0 || z!=1) {	
		printf("   Error!Enter Again:");
		z = ipbl();
	}
	return z;
}

int ipd(void) {
	int a, z;
	a=scanf("%d",&z); while(getchar()!='\n');
	
	if(!a || z<0 || z>=N) {	
		printf("   Error!Enter Again:");
		z = ipd();
	}
	return z;
}

struct Std add(int m) {
	struct Std s;
	int ipd(void), ipbl(void);
	system("clear");
	printf("#%d Enter Messages.  (Male=1,Female=0)\n", m+1);
	
	printf("   Student's No      : ");
	scanf("%s",&s.no); while(getchar()!='\n');
	printf("   Student's Name    : ");
	scanf("%s",&s.name); while(getchar()!='\n');
	
	printf("   Student's Age     : ");
	s.age = ipd();
	printf("   Student's Sex     : ");
	s.sex = ipbl();
	
	printf("   Student's Birthday: ");
	scanf("%s",&s.date); while(getchar()!='\n');
	printf("   Student's Phone   : ");
	scanf("%s",&s.phone); while(getchar()!='\n');
	printf("   Student's QQ      : ");
	scanf("%s",&s.qq); while(getchar()!='\n');
	
	return s;
}

/*** add del ins sch ********************************************************/

void put(int m) {
	if(1) {
		printf("Student Messages.\n");
		printf("#  No.\t\tName\t\tSex\tAge\tBirthday\t\tphone\t\tqq\t\t\n");
		printf("%d  %s\t%s\t", i+1, st[m].no, st[m].name);
		if(st[m].sex) printf("Male\t");
		else 		  printf("Female\t");
		printf("%d\t%s\t%s\t%s\t\n",st[m].age,st[m].date,st[m].phone,st[m].qq);
	}
	else printf("Error 404: No Data!");
}

void ins(void) {
	int i, j, k, sn;
	struct Std z;
	printf("Number of Students:");
	sn = ipd();
	
	for(i=0;i<sn;i++) {
		z = add(i);
		for(j=0;j<n;j++) {
			if(z.no==st[j].no) {
				i--;
				printf("Error!\n");
				continue;
			} 
			if(z.no>st[j].no && z.no<st[j+1].no) {
				for(k=n-1;k>j+1;k--)
					st[k]=st[k-1];
				st[j+1]=z;
				n++;
			}
		}
	}		
}

void del(int m) {
	int i;
	for(i=m;i<=n;i++) {
		st[i]=st[i+1];
	}
}

void srch(char s, int a, int f) {
	int i, flag[N]={0};
	if(s!='\0') {
		switch(f)
		
		for(i=0;i<n;i++)
			if(s==st[i].no)
				flag[i]=1;
	}
	if(s.name!='*') {
		for(i=0;i<n;i++)
			if(s.no==st[i].no)
				flag[i]=1;
	}
	
	for(i=0;i<n;i++)
		if(flag[i]) put(st[i]);
	
}

/************************************************************/

int main(void) {
	int i, j, k, n;
	
	printf("Enter Number of Students:");
	n = ipd();
	system("clear");
	
	
	
	for(i=0;i<n;i++) s[i]=add(i);
	
}











