#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <getopt.h>
#include <stdbool.h>
#define LINE_MAX 1024

// we have defined variable below
char PreemptiveMood='P'; // Preemptive Mod variable that keep A or P

// these definitions are defined for file manipulation
char *inputfile="input.txt";  //input source
void readdata(void); // the function defined function reads data from the input source

// there are three structure is defined for value manupýlation
struct node
{
    int bursttime,arrivaltime,priority,pid;
    struct node *next;
};
struct node * data;

struct result
{
    int pid,waiting,responce;
    struct result *next;
};
struct result * times;

struct tempdata
{
    int pid,waiting;
    struct tempdata *next;
};
struct tempdata *tempwaiting;

// this is main function 
int main(){	

	readdata(); // the function is called for read data from input file
	mainmenu(); // the called function brings menu to screen
	
	
	
	return 0; //this is default integer value of main function
}


void mainmenu(void) // we have created this function for print out main function
{
    
    char choise=' ';
    do
    {   char flag=' ';
        while(flag==' ') // we have use flag here to control while loop
        {
        printf("   Main Menu\n\n");
        printf("   Please, Choose Your Option\n");
        printf("1) Scheduling Method\n");
        if (PreemptiveMood=='A'){
        	printf("2) Preemptive Mode (enable)\n" );        	
        	printf("3) Non-preemptive Mode\n");
		}else{
			printf("2) Preemptive Mode\n" );
        	printf("3) Non-preemptive Mode (enable)\n");
		}
        printf("4) Show Result\n");
        printf("5) End Program\n");
        printf("Option >");
        
        scanf("%c", &choise);
        
        system("cls");
        
        
        if(choise == '1'){        	
			schedulemenu();        	
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

void schedulemenu(void)  // we have created this function for print out main function
{
   
    char choise=' ';
    do
    {   char flag=' ';
        while(flag==' ') // we have use flag here to control while loop
        {
        printf("   Scheduling Method Menu\n\n");
        printf("1) First Come First Served Scheduling\n");
        printf("2) Shortest Job First Scheduling\n");
        printf("3) Priority Scheduling\n");
        printf("4) Round Robin Scheduling\n");
        printf("5) Back to Main Menu\n");
        printf("6) End Program\n");
        printf("Option >");
        
        scanf("%c", &choise);
        
        system("cls");
        
        
        if(choise == '1'){
        	printf("1) First Come First Served Scheduling\n");
            break;
		}if(choise == '2'){
			printf("2) Shortest Job First Scheduling\n");
            break;			
		}if(choise == '3'){
			printf("3) Priority Scheduling\n");
            break;			
		}if(choise == '4'){
			printf("4) Roui	nd Robin Scheduling\n");			
            break;			
		}if(choise == '5'){
			printf("5) Back to Main Menu\n");
			mainmenu(); 			
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

// this function is wrote for that read data from input file
void readdata(void)
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
            // push data to likend list
            //data=insertBack(data,b,a,p,row);
            // print to screen
            printf("%u)    %u              %u             %u\n",row,b,a,p);
            //data=insertBack(data,b,a,p,row);

        }

        fclose(fp);

        printf("   Input file readed succesfully.\n");
        printf("   Processing...\n\n");

    }



}

