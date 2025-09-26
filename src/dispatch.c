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
    struct Report *prev,*link;
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
    struct Log* link;
};

extern struct Report* head;
extern struct Unit units[3];
extern struct Log* logtop;

void dispatchpolice() 
{
    struct Report* cur=head;
    struct Report* ptr=NULL;

    while (cur!=NULL)
    {
        if (cur->status==0) 
        {
            if (ptr==NULL || cur->severity > ptr->severity) 
            {
                ptr=cur;
            }
        }
        cur=cur->link;
    }

    if (ptr==NULL) 
    {
        printf("No pending reports.\n");
        return;
    }

    int unitid=-1;
    for (int i=0; i<3; i++) 
    {
        if (units[i].busy==0) 
        {
            unitid=i;
            break;
        }
    }

    if (unitid==-1) 
    {
        printf("No free units.\n");
        return;
    }

    units[unitid].busy=1;
    units[unitid].reportid=ptr->id;
    ptr->assignedUnit=units[unitid].id;
    ptr->status=1;

    printf("Unit %d dispatched to Report %d.\n", units[unitid].id, ptr->id);
}

void markasresolved() 
{
    int id;
    printf("Enter report ID to resolve: ");
    scanf("%d",&id);

    struct Report* cur=head;
    while (cur != NULL && cur->id!=id) 
        cur=cur->link;

    if (cur==NULL || cur->status!=1) 
    {
        printf("Report not found or not In Progress.\n");
        return;
    }

    for (int i=0;i<3;i++) 
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
    log->link=logtop;
    logtop=log;

    printf("Report %d resolved and logged.\n", id);
}
