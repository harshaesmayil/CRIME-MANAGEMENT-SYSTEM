#include <stdio.h>
#include <stdlib.h>

// Prototypes
void addReport();
void deleteReport();
void displayPendingReports();
void dispatchPolice();
void markAsResolved();
void initUnits();
void showUnitStatus();
void showStatistics();
void showLog();

int main() {
    initUnits();
    int choice;

    while (1) {
        printf("\n CRIME REPORTING AND RESPONSE SYSTEM \n");
        printf("1. Add Report\n2. Delete Report\n3. View Pending\n4. Dispatch\n");
        printf("5. Mark Resolved\n6. Show Units\n7. Show Log\n8. Show Stats\n9. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addReport(); break;
            case 2: deleteReport(); break;
            case 3: displayPendingReports(); break;
            case 4: dispatchPolice(); break;
            case 5: markAsResolved(); break;
            case 6: showUnitStatus(); break;
            case 7: showLog(); break;
            case 8: showStatistics(); break;
            case 9: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
