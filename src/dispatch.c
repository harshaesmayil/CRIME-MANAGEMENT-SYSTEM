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

struct Unit 
{
    int id;
    int busy;
    int reportid;
};

struct Log 
{
    int id;
    char description[100];
    int severity;
    struct Log* next;
};

extern struct Report* head;
extern struct Unit units[3];
extern struct Log* logtop;

void dispatchpolice() 
{
    struct Report* cur=head;
    struct Report* best=NULL;

    while (cur!=NULL) {
        if (cur->status==0) { // Pending
            if (best==NULL || cur->severity > best->severity) 
            {
                best=cur;
            }
        }
        cur=cur->next;
    }

    if (best==NULL) {
        printf("No pending reports.\n");
        return;
    }

    int unitid=-1;
    for (int i=0; i<3; i++) {
        if (units[i].busy==0) {
            unitid=i;
            break;
        }
    }

    if (unitid==-1) {
        printf("No free units.\n");
        return;
    }

    units[unitid].busy=1;
    units[unitid].reportid=best->id;
    best->assignedUnit=units[unitid].id;
    best->status=1;

    printf("Unit %d dispatched to Report %d.\n", units[unitid].id, best->id);
}

void markasresolved() 
{
    int id;
    printf("Enter report ID to resolve: ");
    scanf("%d", &id);

    struct Report* cur=head;
    while (cur != NULL && cur->id!=id) 
        cur=cur->next;

    if (cur==NULL || cur->status!=1) 
    {
        printf("Report not found or not In Progress.\n");
        return;
    }

    for (int i=0; i<3; i++) 
    {
        if (units[i].reportid==id) 
        {
            units[i].busy=0;
            units[i].reportid=-1;
        }
    }

    cur->status=2;

    struct Log* log=(struct Log*)malloc(sizeof(struct Log));
    log->id=cur->id;
    strcpy(log->description, cur->description);
    log->severity=cur->severity;
    log->next=logtop;
    logtop=log;

    printf("Report %d resolved and logged.\n", id);
}
