#include <stdio.h>
#include <stdlib.h>

void addreport();
void deletereport();
void displaypendingreports();
void dispatchpolice();
void markasresolved();
void initunits();
void showunitstatus();
void showstatistics();
void showlog();

int main() 
{
    initunits();
    int choice;

    while (1) 
    {
        printf("\n CRIME REPORTING AND RESPONSE SYSTEM \n");
        printf("1. Add Report\n2. Delete Report\n3. View Pending\n4. Dispatch\n");
        printf("5. Mark Resolved\n6. Show Units\n7. Show Log\n8. Show Stats\n9. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: addreport(); break;
            case 2: deletereport(); break;
            case 3: displaypendingreports(); break;
            case 4: dispatchpolice(); break;
            case 5: markasresolved(); break;
            case 6: showunitstatus(); break;
            case 7: showlog(); break;
            case 8: showstatistics(); break;
            case 9: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
