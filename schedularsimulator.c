#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <getopt.h>
#include <stdbool.h>
#define LINE_MAX 1024

void Menu(void);
void MethodMenu(void);

// we have defined variable below
char PreemptiveMood='P'; // Preemptive Mod variable that keep A or P

// these definitions are defined for file manipulation
char *inputfile="input.txt";  //input source
void ReadingData(void); // the function defined function reading data from the input source

// there are three structure is defined for value manupýlation
struct node
{
    int bursttime,arrivaltime,priority,pid;
    struct node *next;
};
struct node * data;

struct result
{
    int pid,waiting;
    struct result *next;
};
struct result * times;

struct tempdata
{
    int pid,waiting;
    struct tempdata *next;
};
struct tempdata *tempwaiting;


bool is_empty(struct node *data);
struct result * initializeresult(struct result * times);
struct node * createNode(int b,int a,int p, int row);
struct node * insertBack(struct node *data, int b,int a, int p,int row);
struct node * deleteFront(struct node *data);
int sizeofdata (struct node *data);
void display (struct node *data);
void displaytimes (struct result *times);

void firstcomefss(struct node *data,char preemptivemood);

// this is main function 

int main(){	
	
	Menu(); // the called function brings menu to screen
	
	
	
	return 0; //this is default integer value of main function
}


void Menu(void) // we have created this function for print out main function
{
    char choise=' ';
    do
    {   char flag=' ';
        while(flag==' ') // we have use flag here to control while loop
        {
        	
        ReadingData(); // the function is called for reading data from input file

        printf("   Main Menu\n\n");
        printf("   Please, Choose Your Option\n");
        printf("1-) Scheduling Method\n");
        if (PreemptiveMood=='A'){ 			//this function specifies which mode is active
        	printf("2-) Preemptive Mode (enable)\n" );       	
        	printf("3-) Non-preemptive Mode\n");
		}else{
			printf("2-) Preemptive Mode\n" );
        	printf("3-) Non-preemptive Mode (enable)\n");
		}
        printf("4-) Show Result\n");
        printf("5-) End Program\n");
        printf("Option =");
        
        scanf("%c", &choise);
        
        system("cls");
        
        
        if(choise == '1'){        	
			MethodMenu();        	
            break;
		}if(choise == '2'){			
            PreemptiveMood='A';
			printf(" Preemptive Mode is active now. \n");
            printf(" Preemptive Mode Scheduling can be simulate. \n");
            sleep(2);
            break;			
		}if(choise == '3'){
			PreemptiveMood='P';
            printf(" Non-preemptive Mode is active now. \n");
            printf(" Non-preemptive Mode Scheduling can be simulate. \n");
            sleep(2);
            break;			
		}if(choise == '4'){
			printf("4) The Results Are Showing Result\n");
			break;			
		}if(choise == '5'){			
            break;			
		}else{            
            break;
		}		
        scanf("%c", &flag);
        }

    }
    while(choise!='5');
}

void MethodMenu(void)  // we have created this function for print out main function
{
   
    char choise=' ';
    do
    {   char flag=' ';
        while(flag==' ') // we have use flag here to control while loop
        {
        ReadingData(); // the function is called for reading data from input file

        printf("   Scheduling Method Menu\n\n");
        printf("1-) First Come First Served Scheduling\n");
        printf("2-) Shortest Job First Scheduling\n");
        printf("3-) Priority Scheduling\n");
        printf("4-) Round Robin Scheduling\n");
        printf("5-) Back to Main Menu\n");
        printf("6-) End Program\n");
        printf("Option =");
        
        scanf("%c", &choise);
        
        system("cls");
        
        
        if(choise == '1'){
        	printf("1-) First Come First Served Scheduling\n");
            break;
		}if(choise == '2'){
			printf("2-) Shortest Job First Scheduling\n");
            break;			
		}if(choise == '3'){
			printf("3-) Priority Scheduling\n");
            break;			
		}if(choise == '4'){
			printf("4-) Round Robin Scheduling\n");			
            break;			
		}if(choise == '5'){
			printf("5-) Back to Main Menu\n");
			Menu(); 			
            break;			
		}if(choise == '6'){			
			printf("     The CPU Shedule Similator Closed. ");
            break;			
		}else{
            
            break;
		}
		
        scanf("%c", &flag);

        }

    }
    while(choise!='6');
}

// this function is wrote for that reading data from input file
void ReadingData(void)
{
	
	
   FILE *fp;
    char line[LINE_MAX];
    int b,a,p;
    int row =0;

    if ((fp = fopen(inputfile,"r")) == NULL)
    {
        //return;
        printf("Unfortunately, Input file could not found.\n");
        printf("Please, try again carefully...\n");
        exit(0);
    }
    else
    {
        //printf("  Burst Time ~ Arrival Time ~ Priority\n");

        while (fgets(line, LINE_MAX, fp) != NULL)
        {
            row++;
            sscanf(line,"%d:%d:%d\n",&b,&a,&p);
            // push data to linked list
            data=insertBack(data,b,a,p,row);
            // print to screen
            printf("%u)    %u              %u             %u\n",row,b,a,p);

        }

        fclose(fp);

        printf("   Input file readed succesfully.\n\n");
       

    }



}

bool isempty(struct node *data){
    if(data==NULL)
        return true;
    else
        return false;
}

struct result * initializeresult(struct result * times)
{
    times=(struct result*)malloc(sizeof(struct result*));
    times->pid=0;
    times->waiting=0;
    

    return times;
}

struct node * createList(int b,int a,int p,int row)
{
    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->bursttime=b;
    temp->arrivaltime=a;
    temp->priority=p;
    temp->pid=row;
    temp->next=NULL;
    return temp;
}

struct node * insertBack(struct node *data, int b,int a,int p,int row)
{
    struct node * temp = createList(b,a,p,row);
    struct node * datatemp;
    if (data == NULL)
    {
        data = temp;
        return data;
    }
    datatemp=data;
    while(datatemp->next != NULL)
        datatemp=datatemp->next;
    datatemp->next = temp;
    return data;
}

void firstcomefss(struct node *data,char preemptivemood); //fisrt come first served scheduling method
{
	struct *tempdata ;
	struct result *temptimes;
	
	tempdata= data;
	temptimes=times;
	
	int i=1;
    int SIZE = sizeofdata(tempdata);
    
    for(i=1; i<=SIZE; i++){

}
	
}
