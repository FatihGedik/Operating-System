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
char *inputfile="input.txt";//input source
char *outputfile= NULL;  
void ReadingData(void); // the function defined function reading data from the input source
void DataOutput(void); // the function defined function output data from the out source
// there are three structure is defined for value manupýlation
struct node
{
    int bursttime,arrivaltime,priority,Pno;
    struct node *next;
};
struct node * header;

struct result
{
    int Pno,waiting,prebursttime;
    struct result *next;
};
struct result * times;

struct headertemp
{
    int Pno,waiting;
    struct headertemp *next;
};
struct headertemp *tempwaiting;


int is_empty(struct node *header);

struct node * createList(int b,int a,int p, int row);
struct node * insertBack(struct node *header, int b,int a, int p,int row);
struct node * deleteFront(struct node *header);
int sizeofdata (struct node *header);
void display (struct node *header);
void sortarrival(struct node *data);
struct result * initializeresult(struct result * times);

void firstcomefss(struct node *header,char preemptivemood);

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
        printf("Input file could not found.\n");
        printf("Please, try again...\n");
        exit(0);
    }
    else
    {

        while (fgets(line, LINE_MAX, fp) != NULL)
        {
            row++;
            sscanf(line,"%d:%d:%d\n",&b,&a,&p);
            // push data to linked list
            header=insertBack(header,b,a,p,row);
            // print to screen
            printf("%u)    %u              %u             %u\n",row,b,a,p);

        }

        fclose(fp);

        printf("   Input file readed succesfully.\n\n");
       

    }



}

void DataOutput(void){
	
	FILE *fp;
	char line[LINE_MAX];
	
	 if ((fp = fopen(outputfile,"r")) == NULL)
    {
        //return;
        printf("Input file could not found.\n");
        printf("Please, try again...\n");
        exit(0);
    }
    else
    {

         // print to the screen
        while (fgets(line, LINE_MAX, fp) != NULL)
        {
            // print line
            printf("%s",line);

        }

        fclose(fp);

        printf("\n Output file readed succesfully.\n");
        

    }
    
   }

int is_empty(struct node *header){
    if(header==NULL)
        return 1;
    else
        return 0;
}



struct node * createList(int b,int a,int p,int row)
{
    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->bursttime=b;
    temp->arrivaltime=a;
    temp->priority=p;
    temp->Pno=row;
    temp->next=NULL;
    return temp;
}

struct node * insertBack(struct node *header, int b,int a,int p,int row)
{
    struct node * temp = createList(b,a,p,row);
    struct node * headertemp;
    if (header == NULL)
    {
        header = temp;
        return header;
    }
    headertemp=header;
    while(headertemp->next != NULL)
        headertemp=headertemp->next;
    headertemp->next = temp;
    return header;
}

void display(struct node *header)
{
    int cnt=1;
    if (header == NULL)
        printf("List is empty\n");
    }

//the functioýn is wrote for initialize the result stack

struct result * initializeresult(struct result * times)
{
    times=(struct result*)malloc(sizeof(struct result*));
    times->Pno=0;
    times->waiting=0;
    times->prebursttime=0;

    return times;
}

/*void firstcomefss(struct node *header,char preemptivemood); //fisrt come first served scheduling method
{

	times=initializeresult(times);
		
	struct *headertemp ;
	struct result *temptimes;
	
	headertemp= header;

	
	int i=1;
    int SIZE = sizeofdata(headertemp);
    
   
   
    

}*/
	

