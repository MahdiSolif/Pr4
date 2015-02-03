#include<conio.h>
#include<stdio.h>
int AddSt();
int SearchSt();
int SearchPr();
int AddPr();
int exit();
int ftolist_student();
int ftolist_proff();
int main()
{
    int c,h,x,f,p,choice,choice2=0;
    char s[2];
    struct student{
    char name[20];
    char lname[30];
    char Ncode[10];
    char dob[10];
    char address[150];
    char average[5];
    char Fname[20];
    char gender[6];
    char kind[40];
    char course[50];
    long int phone;
    long int mobile;
    };
    struct proff{
    char name[20];
    char lname[30];
    char Ncode[10];
    char dob[10];
    char address[150];
    char average[5];
    char Fname[20];
    char gender[6];
    char kind[40];
    char course[40];
    long int phone;
    long int mobile;
    };
    ///////////////////////////////////////////////////////////////////////////////////////////////
    struct node_student {
        struct student data;
        struct node_student *next;
    }*head_student= NULL;
    struct node_proff {
        struct proff data;
        struct node_proff *next;
    }*head1_proff= NULL;
    ///////////////////////////////////////////////////////////////////////////////////////////////
        int ftolist_student() {
        int i=0;
        int j=0;
        FILE *x;
        x=fopen("student.txt","a+b");
        struct student k;
        struct node_student *p;
        head_student=(struct node_student *)malloc(sizeof(struct node_student));
        p=head_student;
        while(!feof(x)) {
            fread(&k,sizeof(k),1,x);
            i++;
        }
        rewind(x);
        fread(&k,sizeof(k),1,x);
        p->data=k;
        p->next=NULL;
        for(j=0; j<i-2; j++) {
            struct node_student *q=(struct node_student *)malloc(sizeof(struct node_student));
            fread(&k,sizeof(k),1,x);
            q->data=k;
            q->next=NULL;
            p->next=q;
            p=q;
        }
        fclose(x);
        return head_student;
        getch();
    }
    ///////////////////////////////////////////////////////////////////////////////////////////
       int ftolist_proff() {
        int i=0;
        int j=0;
        FILE *x;
        x=fopen("proff.txt","a+b");
        struct proff k;
        struct node_proff *p;
        head1_proff=(struct node_proff *)malloc(sizeof(struct node_proff));
        p=head1_proff;
        while(!feof(x)) {
            fread(&k,sizeof(k),1,x);
            i++;
        }
        rewind(x);
        fread(&k,sizeof(k),1,x);
        p->data=k;
        p->next=NULL;
        for(j=0; j<i-2; j++) {
            struct node_proff *q=(struct node_proff *)malloc(sizeof(struct node_proff));
            fread(&k,sizeof(k),1,x);
            q->data=k;
            q->next=NULL;
            p->next=q;
            p=q;
        }
        fclose(x);
        return head1_proff;
        getch();
    }
    //////////////////////////////////////////////////////////////////////////////////
    int AddSt(){
        system("cls");
        struct student B1;
        gets(s);
        puts("Please Enter The name of the student :");
        gets(B1.name);
        puts("Enter the Lastname of the student :");
        gets(B1.lname);
        puts("Enter The Address of the student :");
        gets(B1.address);
        puts("Enter The date of birth :");
        gets(B1.dob);
        puts("Enter the national code of the student :");
        gets(B1.Ncode);
        puts("Enter the kind of acceptance :");
        gets(B1.kind);
        puts("Enter the course of the student :");
        gets(B1.course);
        puts("Enter the father's name of student :");
        gets(B1.Fname);
        puts("Enter the gender of the student :");
        gets(B1.gender);
        puts("Enter the phone number of the student :");
        scanf("%d",&B1.phone);
        puts("Enter the mobile number of the student :");
        scanf("%d",&B1.mobile);
        gets(s);
        struct node_student *n=ftolist_student();
        int c=0;
        while(n!=NULL) {
            if(strcmp(B1.Ncode,n->data.Ncode)==0) {
                printf("*************************************************************************\n");
                printf("ERROR\n");
                printf("The student national Code is Duplicated, Please Try a New One\n");
                printf("*************************************************************************\n");
                c=1;
            }
            n=n->next;
        }
        if(c==0) {
            FILE * fp;
            fp=fopen("student.txt","a+b");
            fwrite(&B1,sizeof(B1),1,fp);
            fclose(fp);
            puts("Adding Done");
        }
        puts("Press Any key To Continue");
        getch();
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////
    int AddPr(){
        system("cls");
        struct proff P1;
        gets(s);
        puts("Please Enter The name of the proffessor :");
        gets(P1.name);
        puts("Enter the Lastname of the proffessor :");
        gets(P1.lname);
        puts("Enter The Address of the proffessor :");
        gets(P1.address);
        puts("Enter The date of birth :");
        gets(P1.dob);
        puts("Enter the national code of the proffessor :");
        gets(P1.Ncode);
        puts("Enter the kind of acceptance :");
        gets(P1.kind);
        puts("Enter the course of the proffessor : \n");
        gets(P1.course);
        puts("Enter the father's name of proffessor :");
        gets(P1.Fname);
        puts("Enter the gender of the proffessor :");
        gets(P1.gender);
        puts("Enter the phone number of the proffessor :");
        scanf("%d",&P1.phone);
        puts("Enter the mobile number of the proffessor :");
        scanf("%d",&P1.mobile);
        gets(s);
        struct node_proff *n=ftolist_proff();
        int c=0;
        while(n!=NULL) {
            if(strcmp(P1.Ncode,n->data.Ncode)==0) {
                printf("*************************************************************************\n");
                printf("ERROR\n");
                printf("The proffessor national Code is Duplicated, Please Try a New One\n");
                printf("*************************************************************************\n");
                c=1;
            }
            n=n->next;
        }
        if(c==0) {
            FILE * fp;
            fp=fopen("proff.txt","a+b");
            fwrite(&P1,sizeof(P1),1,fp);
            fclose(fp);
            puts("Adding Done");
        }
        puts("Press Any key To Continue");
        getch();
        return 0;
    }

    ////////////////////////////////////////////////////////////////////
    int SearchSt() {
        system("cls");
        char key[40];
        puts("1- Searching by name");
        puts("2- Searching by lastname");
        puts("3- Searching by National Code");
        printf("Enter your Choice please: ");
        scanf("%d",&choice);
        switch(choice) {
        case 1: {
            system("cls");
            printf("Enter Student's Name To Search: ");
            scanf("%s",&key);
            struct node_student *head=ftolist_student();
            printf("********************************************************************************");
            printf("Name       Lastname        N-Code        Date_Of_Birth        Course       Phone");
            printf("********************************************************************************");
            while(head!=NULL) {
                if(strcmp(key,head->data.name)==0) {
                    printf("%s       %s        %s        %s        %s        %d \n",head->data.name,head->data.lname,head->data.Ncode,head->data.dob,head->data.course,head->data.phone);
                }
                head=head->next;
            }
            printf("********************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;
        case 2: {
            system("cls");
            printf("Enter Student's Lastname To Search: ");
            scanf("%s",&key);
            struct node_student *head=ftolist_student();
            printf("********************************************************************************");
            printf("Name       Lastname        N-Code        Date_Of_Birth        Course       Phone");
            printf("********************************************************************************");
            while(head!=NULL) {
                if(strcmp(key,head->data.lname)==0) {
                    printf("%s       %s        %s        %s        %s       %d \n",head->data.name,head->data.lname,head->data.Ncode,head->data.dob,head->data.course,head->data.phone);
                }
                head=head->next;
            }
            printf("********************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;
        case 3: {
            system("cls");
            printf("Enter  Student's National code to Search: ");
            scanf("%s",&key);
            struct node_student *head=ftolist_student();
            printf("********************************************************************************");
            printf("Name       Lastname        N-Code        Date_Of_Birth        Course       Phone");
            printf("********************************************************************************");
            while(head!=NULL) {
                if(strcmp(key,head->data.Ncode)==0) {
                    printf("%s       %s        %s        %s        %s        %d \n",head->data.name,head->data.lname,head->data.Ncode,head->data.dob,head->data.course,head->data.phone);
                }
                head=head->next;
            }
            printf("********************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;
        }
        getch();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////
        int SearchPr() {
        system("cls");
        char key[40];
        puts("1- Searching by name");
        puts("2- Searching by lastname");
        puts("3- Searching by National Code");
        printf("Enter your Choice please: ");
        scanf("%d",&choice);
        switch(choice) {
        case 1: {
            system("cls");
            printf("Enter Proffessor's Name To Search: ");
            scanf("%s",&key);
            struct node_proff *head1=ftolist_proff();
            printf("********************************************************************************");
            printf("Name       Lastname        N-Code        Date_Of_Birth        Course       Phone");
            printf("********************************************************************************");
            while(head1!=NULL) {
                if(strcmp(key,head1->data.name)==0) {
                    printf("%s       %s        %s        %s        %s         %d \n",head1->data.name,head1->data.lname,head1->data.Ncode,head1->data.dob,head1->data.course,head1->data.phone);
                }
                head1=head1->next;
            }
            printf("********************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;
        case 2: {
            system("cls");
            printf("Enter Proffessor's Lastname To Search: ");
            scanf("%s",&key);
            struct node_proff *head1=ftolist_proff();
            printf("********************************************************************************");
            printf("Name       Lastname        N-Code        Date_Of_Birth        Course       Phone");
            printf("********************************************************************************");
            while(head1!=NULL) {
                if(strcmp(key,head1->data.lname)==0) {
                    printf("%s       %s        %s        %s        %s        %d \n",head1->data.name,head1->data.lname,head1->data.Ncode,head1->data.dob,head1->data.course,head1->data.phone);
                }
                head1=head1->next;
            }
            printf("********************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;
        case 3: {
            system("cls");
            printf("Enter  proffessor's National code to Search: ");
            scanf("%s",&key);
            struct node_proff *head1=ftolist_proff();
            printf("********************************************************************************");
            printf("Name       Lastname        N-Code        Date_Of_Birth        Course       Phone");
            printf("********************************************************************************");
            while(head1!=NULL) {
                if(strcmp(key,head1->data.Ncode)==0) {
                    printf("%s       %s        %s        %s        %s        %d \n",head1->data.name,head1->data.lname,head1->data.Ncode,head1->data.dob,head1->data.course,head1->data.phone);
                }
                head1=head1->next;
            }
            printf("********************************************************************************");
            puts("Press Any key To Continue:");
        }
        break;
        }
        getch();
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    while(1){
        system("cls");
        puts("1.Official  2.Students  3.Proffessors  4.Exit");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                puts("1.Add new Student   2.Add new Proffessor  3.Search \n");
                printf("Enter Your Choice: ");
                scanf("%d",&choice);
                switch(choice) {
                    case 1:
                        AddSt();
                        break;
                    case 2:
                        AddPr();
                        break;
                        case 3:
                            puts("1.Search Proffessor  2.Search Student \n");
                            printf("Enter Your Choice : ");
                            scanf("%d",&choice2);
                            switch(choice2){
                                case 1:
                                    SearchPr();
                                    break;
                                case 2:
                                    SearchSt();
                                    break;
                            }
                }
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;

        }
    }
}
