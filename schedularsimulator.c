#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <getopt.h>
#include <stdbool.h>
#define LINE_MAX 1024

// we have defined variable below
char preemptivemood='P'; // Preemptive Mod variable that keep A or P


// this is main function 
int main(){	

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
        printf("2) Preemptive Mode\n");
        printf("3) Non-preemptive Mode\n");
        printf("4) Show Result\n");
        printf("5) End Program\n");
        printf("Option >");
        
        scanf("%c", &choise);
        
        system("cls");
        
        
        if(choise == '1'){
        	
			schedulemenu();        	
            break;
		}if(choise == '2'){
			
            printf(" Preemptive Mode is active now. \n");
            printf(" Preemptive Mode Scheduling can be simulate. \n");
            break;			
		}if(choise == '3'){
			
            printf(" Non-preemptive Mode is active now. \n");
            printf(" Non-preemptive Mode Scheduling can be simulate. \n");
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

