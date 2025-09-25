#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Report 
{
    int id;
    char description[100];
    int severity;
    int status;
    int assignedUnit;
    struct Report *prev, *next;
};
extern struct Report* head;

struct Log 
{
    int id;
    char description[100];
    int severity;
    struct Log* next;
};

struct Log* logtop=NULL;

void showlog() 
{
    struct Log* cur=logtop;
    if (cur==NULL) 
    {
        printf("\nLog is empty.\n");
        return;
    }
    printf("\n--- Dispatch Log ---\n");
    while (cur!=NULL) 
    {
        printf("Report %d | Sev:%d | %s | Status: Resolved\n", cur->id, cur->severity, cur->description);
        cur=cur->next;
    }
}
