#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
#include <fcntl.h>


int flag;

struct twodir
{
char dname[10],fname[100][10];
int fcnt;
};

 struct
{
char dname[10],fname[10][10];
int fcnt;
}dir1;

struct hierarchial
{
	char dirname[100][100];
	struct twodir dname[10][10];
	int ct;
};

struct da
{
	struct hierarchial hr[10];
int dct;
	 
}da1;

int dcnt=0;

void twolevel(struct twodir dir[10])
{
int i,ch,k;
char f[30], d[30];
while(1)
{
printf("\n\n 1. Create Directory\t 2. Create File\t ");
printf("\n 3. Search File \t \t 4. Display \t 5. Exit \t Enter your choice -- ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\n Enter name of directory -- ");
scanf("%s", dir[dcnt].dname);
dir[dcnt].fcnt=0;
dcnt++;
printf("Directory created");
break;
case 2: printf("\n Enter name of the directory -- ");
scanf("%s",d);
for(i=0;i<dcnt;i++)
if(strcmp(d,dir[i].dname)==0)
{
printf("Enter name of the file -- ");
scanf("%s",dir[i].fname[dir[i].fcnt]);
dir[i].fcnt++;
printf("File created");
break;
}
if(i==dcnt)
printf("Directory %s not found",d);
break;
case 3: printf("\nEnter name of the directory -- ");
scanf("%s",d);
for(i=0;i<dcnt;i++)
{

if(strcmp(d,dir[i].dname)==0)
{
printf("Enter the name of the file -- ");
scanf("%s",f);
for(k=0;k<dir[i].fcnt;k++)
{
if(strcmp(f, dir[i].fname[k])==0)
{
printf("File %s is found ",f);
goto jmp1;
}
}
printf("File %s not found",f);
goto jmp1;
}
}
printf("Directory %s not found",d);
jmp1: break;
case 4: if(dcnt==0)
printf("\nNo Directory's ");
else
{
printf("\nDirectory\tFiles");
for(i=0;i<dcnt;i++)
{
printf("\n%s\t\t",dir[i].dname);
for(k=0;k<dir[i].fcnt;k++)
printf("\t%s",dir[i].fname[k]);
}
}
break;
default:goto end;
}
}
end:;
}

void hier(struct hierarchial dir2)
{
int i,ch,dcnt,k;
char f[30], d[30];

printf("\n Enter name of the directory -- ");
scanf("%s",d);

//twolevel(dir2.dname[i]);




while(1)
{
printf("\n\n 1. Create Directory\t 2. Go to directory\t ");
printf("\t 3. Display \t 4. Exit \t Enter your choice -- ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\n Enter name of directory -- ");
scanf("%s", dir2.dname[dir2.ct]);
dir2.ct++;
printf("Directory created");
break;

case 2:
printf("\n Enter name of the directory -- ");
scanf("%s",d);
for(i=0;i<dir2.ct;i++)
if(strcmp(d,dir2.dname[i])==0)
twolevel(dir2.dname[i]);

break;
case 3:
	for(i=0;i < dir2.ct;i++)
	printf("%s \n",dir2.dname[i]);
	break;
case 4:goto end;
}}
end:;
}

 void singlelevel()
{
int i,ch;
char f[30];
dir1.fcnt = 0;
printf("\nEnter name of directory -- ");
scanf("%s", dir1.dname);
while(1)
{
printf("\n\n 1. Create File\t2. Search File \n 3. Display Files\t4. Exit\nEnter your choice -- ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\n Enter the name of the file -- ");
scanf("%s",f);
	int flag=0;
	for(i=0;i<dir1.fcnt;i++)
	{
	//printf("%d",strcmp(dir1.fname[i],dir1.fname[dir1.fcnt]));
	if(strcmp(dir1.fname[i],f)==0)
	{
	flag=1;
	printf("File %s is already found ",f);
	break;
	}
}
	

	if(flag==0)
	{
	printf("File created\n");			
	strcpy(dir1.fname[dir1.fcnt++],f);	
	}
	
	
		

	break;
case 2:  printf("\n Enter the name of the file -- ");
scanf("%s",f);
for(i=0;i<dir1.fcnt;i++)
{
if(strcmp(f, dir1.fname[i])==0)
{
printf("File %s is found ", f);
break;
}
}
if(i==dir1.fcnt)
printf("File %s not found",f);
break;
case 3: if(dir1.fcnt==0)
printf("\n Directory Empty");
else
{
printf("\n The Files are -- ");
for(i=0;i<dir1.fcnt;i++)
printf("\t%s",dir1.fname[i]);
}
break;
default: goto end;
}
}
end:;
}


void dag()
{
int i=0,j,k,ch;
da1.dct=0;
char d[20];
while(1){
printf("\n%d Enter \n1- Create a New Directory \n2-To go to a Directory \n3-Create link \n 4- Exit ",i);
scanf("%d",&ch);
switch(ch)
{
case 1:
 
	printf("\n Enter the name Of the directory  \n ");
	scanf("%s",da1.hr[i].dirname);
	for(j=0;j<i;j++)
	if(strcmp(da1.hr[i].dirname,da1.hr[i].dirname)==0)
		printf("\n Directory ALready Exists \n ");
	else
	{	printf("\n Directory Created \n ");
		da1.dct++;
	}
	break;
	
case 2: 
printf("\n Enter name of the directory -- ");
fflush(stdin);
scanf("%s",d);
for(j=0;j<=da1.dct;j++)
if(strcmp(d,da1.hr[j].dirname)==0)
hier(da1.hr[j]);
break;

case 3:
	printf("\n Enter the link Number ");
	scanf("%d",&k);
	printf("\n Enter the Destination Directory name ");
	scanf("%s",d);
	for(j=0;j<=da1.dct;j++)
	if(strcmp(d,da1.hr[j].dirname)==0)
	hier(da1.hr[j]);
	break;
case 4: goto end;
}
i++;
}

end : ;


	
}



int main()
{struct twodir dir[10];
struct hierarchial dir2;
int ch;
ch=1;
while(ch!=5)
{
printf("\n Enter the Choice \n 1- Single-level \n 2-Two-level \n 3-Hierarchial \n 4- DAG \n");
scanf("%d",&ch);
dir2.ct=0;
//da1.cnt=0;
switch(ch)
{
case 1: singlelevel();break;
case 2:twolevel(dir);break;
case 3: hier(dir2);break;
case 4:dag();break;
}
}
return 0;
}
