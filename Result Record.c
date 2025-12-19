#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Limitnations On The Number Of People
#define LECTURE 100
#define STUDENT 5000

//Define A Structure To Accommodate User
typedef struct
{
    char l_id[50];
    char l_password[50];
} Lecture;

typedef struct
{
    char s_id[50];
    char s_password[50];
} Student;

struct student
{
	int s_id;
	char name[100];
	float mark;
	char subject[50];
	char grade[30];
}stud;

//Defining A Global Array
Lecture list[LECTURE];
Student rank[STUDENT];

//Function For Register & Login
int menu();
void registerLecture();
void registerStudent();
void writeToFile();
void writeFile();
int exist();
int check();
Lecture lecturelogin();
Student studentlogin();

//Function For Main Program
void lec();
void std();
int empty();
void insert();
void disp();
void search_lec();
void search_std();
void deletefile();
void update();
int avls_id(int s_id);
char* mark_grade(float mark);

//Create A File
char* filename = "l_login.txt";
char* fn = "s_login.txt";

//Turn The Page To Register & Login Pages
int main()
{
	system("cls");
    Lecture test[LECTURE];
    FILE *fp = fopen(filename,"r");
    int i=0;
    Lecture l;
    if(NULL == fp)
    {
        printf("FILE NOT FOUND");
        return -1;
    }
    for(i=0; i<LECTURE; i++)
    {
        char lname[50];
        char lpassword[50];
        fscanf(fp,"%s%s",lname,lpassword);

        strcpy(list[i].l_id , lname);
        strcpy(list[i].l_password , lpassword);   	 
    }
    
    Student mark[STUDENT];
    FILE *fo = fopen(fn,"r");
    int n=0;
    Student s;
    if(NULL == fo)
    {
        printf("FILE NOT FOUND");
        return -1;
    }
    for(n=0; n<STUDENT; n++)
    {
        char sname[50];
        char spassword[50];
        fscanf(fo,"%s%s",sname,spassword);

        strcpy(rank[n].s_id , sname);
        strcpy(rank[n].s_password , spassword);   	 
    }
    
    int choice = menu();
    if(1 == choice)
    {
    	system("cls");
        registerLecture();
    }
    else if(2 == choice)
    {
        system("cls");
        registerStudent();
    }
    else if(3 == choice)
    {
    	system("cls");
        l=lecturelogin();
        if(1 == exist(l))
        {
        }
        else
        {
        	while(1!=exist(l))
        	{
        		system("cls");
            	printf("\nWRONG USER OR PASS");
            	printf("\nRewrite again\n");
            	getch();
            	fflush(stdin);
            	l=lecturelogin();
        	}
        }
    }
    else if(4 == choice)
    {
    	system("cls");
        s=studentlogin();
        if(1 == check(s))
        {
        }
        else
        {
            while(1!=check(s))
        	{
        		system("cls");
            	printf("\nWRONG USER OR PASS");
            	printf("\nRewrite again\n");
            	fflush(stdin);
            	getch();
            	s=studentlogin();
        	}
        }
    }
	else
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\nn\n\n\n\n\t\t\t\t\t\t  See you again !!!\n\n\n\n\n\n\n\n\n\n\n\n");
		exit(0);
	}   
}

//Display The Page of Register & Login For Lecture & Student
int menu()
{
    int choice;
    printf("\n**************************************************************");
	printf("\n        WELCOME TO MULTIMEDIA UNIVERSITY RESULT RECORD        ");
	printf("\n**************************************************************");
    printf("\n> Enter '1' for REGISTER (Lecture) <");
	printf("\n> Enter '2' for REGISTER (Student) <");
	printf("\n> Enter '3' for LOGIN    (Lecture) <");
	printf("\n> Enter '4' for LOGIN    (Student) <");
	printf("\n> Enter '5' for EXIT               <");
	printf("\n\nPlease Enter Your Choice : ");
	scanf("%d",&choice);
	return choice;
}

//Register Page For Lecture
void registerLecture()
{
    char l_id[50];
    char l_password[50];
    Lecture lecture;
    int i;

	printf("\n\tWELCOME TO LECTURE REGISTER ZONE");
	printf("\n*************************************************");
    printf("\nEnter your ID       : ");
    scanf("%s",l_id);
    strcpy(lecture.l_id , l_id);

    for(i=0; i<LECTURE; i++)
    {
        if(0==strcmp(list[i].l_id ,l_id))
        {
            printf("USER ALREADY EXIST");
            return;
        }
    }

    printf("\nEnter your password : ");
    scanf("%s",l_password);
    strcpy(lecture.l_password , l_password);
    writeToFile(lecture);
    printf("\nRegister successful");
    exit(0);
}

//Register Page For Student
void registerStudent()
{
    char s_id[50];
    char s_password[50];
    Student student;
    int i;

	printf("\n\tWELCOME TO STUDENT REGISTER ZONE");
	printf("\n*************************************************");
    printf("\nEnter your User Name  : ");
    scanf("%s",s_id);
    strcpy(student.s_id , s_id);

    for(i=0; i<STUDENT; i++)
    {
        if(0==strcmp(rank[i].s_id ,s_id))
        {
            printf("USER ALREADY EXIST");
            return;
        }
    }

    printf("\nEnter your password   : ");
    scanf("%s",s_password);
    strcpy(student.s_password , s_password);
    writeFile(student);
    printf("\nRegister successful");
    exit(0);
}

//Write The Lecture Information In TXT File, One User Per Line 
void writeToFile(Lecture l)
{
    FILE *fw = fopen(filename,"a+");
    fprintf(fw,l.l_id);
    fprintf(fw,"\t");
    fprintf(fw,l.l_password);
    fprintf(fw,"\n");
}

//Determine If The Lecture Exists
int exist(Lecture l)
{
    int i;
    for(i=0; i<LECTURE; i++)
    {
        if(0==strcmp(list[i].l_id ,l.l_id) && 0==strcmp(list[i].l_password ,l.l_password))
        {
        	lec();
            return 1;
        }
    }
    return -1;
}

//Write The Student Information In TXT File, One User Per Line
void writeFile(Student s)
{
    FILE *fc = fopen(fn,"a+");
    fprintf(fc,s.s_id);
    fprintf(fc,"\t");
    fprintf(fc,s.s_password);
    fprintf(fc,"\n");
}

//Determine If The Student Exists
int check(Student s)
{
    int i;
    for(i=0; i<STUDENT; i++)
    {
        if(0==strcmp(rank[i].s_id ,s.s_id) && 0==strcmp(rank[i].s_password ,s.s_password))
        {
        	std();
            return 1;
        }
    }
    return -1;
}

//Login Page For Lecture
Lecture lecturelogin()
{
	system("cls");
    char l_id[50];
    char l_password[50];
    int i;
    Lecture lg;	
    
    printf("\n\tWELCOME TO LECTURE LOGIN ZONE");
	printf("\n*************************************************");
    printf("\nEnter Lecture ID : ");
    scanf("%s",l_id);
    strcpy(lg.l_id , l_id);
    printf("\nEnter password   : ");
    scanf("%s",l_password); 
    strcpy(lg.l_password,l_password);
    return lg;
}

//Login Page For Student
Student studentlogin()
{
	system("cls");
    char s_id[50];
    char s_password[50];
    int i;
    Student st;
    
    printf("\n\tWELCOME TO STUDENT LOGIN ZONE");
	printf("\n*************************************************");
    printf("\nEnter User Name  :");
    scanf("%s",s_id);
    strcpy(st.s_id , s_id);
    printf("\nEnter password   :");
    scanf("%s",s_password);
    strcpy(st.s_password,s_password);
    return st;
}

//Display Lecture Result Record Page (After Login)
void lec()
{
	system("cls");
	int c, emp;
	char l_id;
	
	printf("\n**************************************************************");
	printf("\n                WELCOME TO RESULT RECORD PAGE                 ");
	printf("\n**************************************************************");
	printf("\n> Enter '1' for INSERT A RECORD    <");
	printf("\n> Enter '2' for DELETE A RECORD    <");
	printf("\n> Enter '3' for SEARCH A RECORD    <");
	printf("\n> Enter '4' for UPDATE A RECORD    <");
	printf("\n> Enter '5' for DISPLAY ALL RECORD <");
	printf("\n> Enter '6' for LOGOUT             <");
	printf("\n\nWelcome Lecture");
	printf("\nPlease Enter Your Choice : ");
	scanf("%d",&c);
	
	switch (c)
	{
		case 1:
			insert();
			break;
   			
		case 2:
			deletefile();
			break;
			
		case 3:
			search_lec();
			break;
			
		case 4:
			update();
			break;
			
		case 5:
			emp = empty();
			if (emp == 0)
			{
				printf("\nThe file is EMPTY\n");
				getch();
				lec();
				
			}
			else
			{
				disp();
			}
			break;
				
		case 6:
			system("cls");
			main();
			break;
			
		default:
			lec();
			break;
	}
}

//Display Student View Result Page (After Login)
void std()
{
	system("cls");
	int c;
	
    printf("\n************************************************************");
	printf("\n                WELCOME TO VIEW RESULT PAGE                 ");
	printf("\n************************************************************");
	printf("\n> Enter '1' for SEARCH A RECORD    <");
	printf("\n> Enter '2' for LOGOUT             <");
	printf("\n\nPlease Enter Your Choice : ");
	scanf("%d",&c);
	switch (c)
	{
		case 1:
			search_std();
			break;
   			
		case 2:
			main();
			break;
	}
}

//Function To Check The File Is Empty Or Not
int empty()
{
	int c = 0;
	FILE *fp;
	fp = fopen("Record", "r");
	while (fread(&stud, sizeof(stud), 1, fp))
	c = 1;
	fclose(fp);
	return c;
}

//Function To Insert Records To The File
void insert()
{
	FILE *fp;
	fp = fopen("Record", "a");
	printf("Enter Student ID   : ");
	scanf("%d", &stud.s_id);
	fflush(stdin);
	printf("Enter Student Name : ");
	gets(stud.name);
	fflush(stdin);
	printf("Enter Subject Code : ");
	gets(stud.subject);
	printf("Enter the mark     : ");
	scanf("%f", &stud.mark);
	fwrite(&stud, sizeof(stud), 1, fp);
	fclose(fp);
	lec();
}

//Function To Display Records
void disp()
{
	FILE *fp1;
	fp1 = fopen("Record", "r");
	while (fread(&stud, sizeof(stud), 1, fp1))
		{
			if (fp1)
			{
    			printf("\nStudent ID   = %d", stud.s_id);
    			printf("\nName         = %s", stud.name);
    			printf("\nSubject Code = %s", stud.subject);
    			printf("\nMark         = %.2f", stud.mark);
    			strcpy(stud.grade,mark_grade(stud.mark));
    			printf("\nGrade        = %s\n", stud.grade);
			}
		}
	fclose(fp1);
	getch();
	lec();
}

//Function To Search The Result Record (For Lecture)
void search_lec()
{
	FILE *fp2;
	int r, s, s_id;
	printf("\nEnter the Student ID you want to search  :");
	scanf("%d", &r);
	s_id = avls_id(r);
	if (s_id == 0)
	{
		printf("Student ID %d is not available in the file\n",r);	
	}
	else
	{
		fp2 = fopen("Record", "r");
		while (fread(&stud, sizeof(stud), 1, fp2))
		{
			s = stud.s_id;
			if (s == r)
			{
    			printf("\nStudent ID   = %d", stud.s_id);
    			printf("\nName         = %s", stud.name);
    			printf("\nSubject Code = %s", stud.subject);
    			printf("\nMark         = %.2f", stud.mark);
    			strcpy(stud.grade,mark_grade(stud.mark));
    			printf("\nGrade        = %s\n", stud.grade);
			}
		}
		fclose(fp2);
		getch();
	}
	lec();
}

//Function To Search The Result Record (For Student)
void search_std()
{
	FILE *fp2;
	int r, s, s_id, t=0;
	float avr, tmark=0;
	printf("\nEnter the Student ID you want to search  :");
	scanf("%d", &r);
	s_id = avls_id(r);
	if (s_id == 0)
	{
		printf("Student ID %d is not available in the file\n",r);	
	}
	else
	{
		fp2 = fopen("Record", "r");
		while (fread(&stud, sizeof(stud), 1, fp2))
		{
			s = stud.s_id;
			if (s == r)
			{
    			printf("\nStudent ID   = %d", stud.s_id);
    			printf("\nName         = %s", stud.name);
    			printf("\nSubject Code = %s", stud.subject);
    			printf("\nMark         = %.2f", stud.mark);
    			strcpy(stud.grade,mark_grade(stud.mark));
    			printf("\nGrade        = %s\n", stud.grade);
    			tmark += stud.mark;
    			t++;
			}
			avr = tmark / t;
		}
		printf("\nYour average mark is : %.2f",avr);
		fclose(fp2);
		getch();
	}
	std();
}

//Function To Delete A Record
void deletefile()
{
	FILE *fpo;
	FILE *fpt;
	int r, s;
	printf("Enter Student ID no you want to delete : ");
	scanf("%d", &r);
	if (avls_id(r) == 0)
	{
		printf("Student ID %d is not available in the file\n", r);
	}
 	else
	{
		fpo = fopen("Record", "r");
		fpt = fopen("TempFile", "w");
		while (fread(&stud, sizeof(stud), 1, fpo))
		{
			s = stud.s_id;
			if (s != r)
			fwrite(&stud, sizeof(stud), 1, fpt);
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("Record", "w");
		fpt = fopen("TempFile", "r");
		while (fread(&stud, sizeof(stud), 1, fpt))
		{
			fwrite(&stud, sizeof(stud), 1, fpo);
			
			system("cls");
			printf("\n RECORD DELETED \n");
			fclose(fpo);
			fclose(fpt);	
		}
	}
	lec();
}

//Function To Update The Record
void update()
{
	int s_id;
	FILE *fpt;
	FILE *fpo;
	int s, r, ch;
	printf("Enter Student ID to update : ");
	scanf("%d", &r);
	s_id = avls_id(r);
	if (s_id == 0)
	{
		printf("%d is not Available in the file", r);
	}
	else
	{
		fpo = fopen("Record", "r");
		fpt = fopen("TempFile", "w");
		while (fread(&stud, sizeof(stud), 1, fpo))
		{
			s = stud.s_id;
			if (s != r)
			{
				fwrite(&stud, sizeof(stud), 1, fpt);	
			}
			else
			{
    			printf("\n >1. Update Name of  %d", r);
    			printf("\n >2. Update Mark of  %d", r);
    			printf("\n >3. Update Subject Code of  %d", r);
    			printf("\nEnter your choice: ");
    			scanf("%d", &ch);
    			switch (ch)
    			{
    				case 1:
    					fflush(stdin);
    					printf("Enter Name        : ");
    					gets(stud.name);
    					break;
    					
    				case 2:
    					printf("Enter Mark         : ");
    					scanf("%f", &stud.mark);
    					break;
    					
    				case 3:
    					printf("Enter Subject Code : ");
    					scanf("%f", &stud.subject);
    					break;
    					
    				default:
    					printf("Invalid Selection");
    					break;
    			}
    			fwrite(&stud, sizeof(stud), 1, fpt);
			}
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("Record", "w");
		fpt = fopen("TempFile", "r");
		while (fread(&stud, sizeof(stud), 1, fpt))
		{
			fwrite(&stud, sizeof(stud), 1, fpo);
		}
		fclose(fpo);
		fclose(fpt);
		printf("RECORD UPDATED");
	}
	lec();
}

//Function To Check Student ID Is Avaliable 
int avls_id(int s_id)
{
	FILE *fp;
	int c = 0;
	fp = fopen("Record", "r");
	while (!feof(fp))
	{
		fread(&stud, sizeof(stud), 1, fp);
		if (s_id == stud.s_id)
		{
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

//Function Of Display The Grade Of Mark ( In Funtion disp() )
char* mark_grade(float mark)
{
	static char grade[30]; 
	
	if(mark >= 0 && mark < 40)
	{
		strcpy(grade,"F (Re-attempt)");
	}
	else if(mark >= 40 && mark < 50)
	{
		strcpy(grade,"D (Supplementary exam)");
	}
	else if(mark >= 50 && mark < 56)
	{
		strcpy(grade,"D+ (Supplementary exam)");
	}
	else if(mark >= 56 && mark < 60)
	{
		strcpy(grade,"C- (Average)");
	}
	else if(mark >= 60 && mark < 65)
	{
		strcpy(grade,"C (Average)");
	}
	else if(mark >= 65 && mark < 68)
	{
		strcpy(grade,"C+ (Average)");
	}
	else if(mark >= 68 && mark < 72)
	{
		strcpy(grade,"B- (Good)");
	}
	else if(mark >= 72 && mark < 76)
	{
		strcpy(grade,"B (Good)");
	}
	else if(mark >= 76 && mark < 80)
	{
		strcpy(grade,"B+ (Good)");
	}
	else if(mark >= 80 && mark < 86)
	{
		strcpy(grade,"A- (Excellent)");
	}
	else if(mark >= 86 && mark < 90)
	{
		strcpy(grade,"A (Excellent)");
	}
	else if(mark >= 90 && mark <= 100)
	{
		strcpy(grade,"A+ (Excellent)");
	}
	return grade;
}
