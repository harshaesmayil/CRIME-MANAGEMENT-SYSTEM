#include <stdio.h>
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

struct Unit 
{
    int id;
    int busy;
    int reportid;
};

struct Unit units[3];

void initunits() {
    for (int i=0; i<3; i++) 
    {
        units[i].id=i+1;
        units[i].busy=0;
        units[i].reportid=-1;
    }
}

void showunitstatus() 
{
    printf("\n--- Units ---\n");
    for (int i=0; i<3; i++) 
    {
        printf("Unit %d: %s (Report %s)\n", units[i].id, units[i].busy ? "Busy" : "Free", (units[i].reportid == -1) ? "None" : "Assigned");
    }
}

void showstatistics() 
{
    extern struct Report* head;
    int total=0, pending=0, inprog=0, resolved=0, busy=0;
    struct Report* cur=head;

    while (cur!=NULL) 
    {
        total++;
        if (cur->status==0) pending++;
        else if (cur->status==1) inprog++;
        else resolved++;
        cur=cur->next;
    }

    for (int i=0; i<3; i++) 
    {
        if (units[i].busy!=0) busy++;
    }

    printf("\n--- Statistics ---\n");
    printf("Total:%d | Pending:%d | In Progress:%d | Resolved:%d\n", total, pending, inprog, resolved);
    printf("Busy Units: %d / 3\n", busy);
}
