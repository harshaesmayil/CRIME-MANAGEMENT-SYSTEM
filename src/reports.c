#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Report 
{
    int id;
    char description[100];
    int severity;
    int status;
    int assignedunit;
    struct Report* prev;
    struct Report* next;
};

struct Report* head=NULL;
struct Report* tail=NULL;
int nextid=1;

void addreport()
{
    struct Report* newnode=(struct Report*)malloc(sizeof(struct Report));
    newnode->id=nextid++;

    printf("Enter description: ");
    getchar();
    fgets(newnode->description, 100, stdin);
    newnode->description[strcspn(newnode->description, "\n")] = '\0';

    printf("Enter severity ( 1 - 5 ( 5 being the greatest priority ) ): ");
    scanf("%d", &newnode->severity);

    newnode->status=0;
    newnode->assignedunit=-1;
    newnode->prev=tail;
    newnode->next=NULL;

    if (tail==NULL) 
    {
        head=tail=newnode;
    } 
    else 
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }

    printf("Report %d added.\n", newnode->id);
}

void deletereport() 
{
    int id;
    printf("Enter report ID to delete: ");
    scanf("%d", &id);

    struct Report* temp=head;
    while (temp!=NULL) {
        if (temp->id==id) {
            if (temp->status==1) 
            {
                printf("Cannot delete. Report is In Progress.\n");
                return;
            }
            if (temp->prev!=NULL) 
                temp->prev->next=temp->next;
            else 
                head=temp->next;

            if (temp->next!=NULL) 
                temp->next->prev=temp->prev;
            else 
                tail=temp->prev;

            free(temp);
            printf("Report %d deleted.\n", id);
            return;
        }
        temp=temp->next;
    }
    printf("Report %d not found.\n", id);
}

void displaypendingreports() 
{
    struct Report* temp=head;
    printf("\n--- Pending / In Progress Reports ---\n");
    while (temp!=NULL) 
    {
        if (temp->status!=2) {
            printf("ID:%d | Sev:%d | Status:%s | Desc:%s\n",
                   temp->id, temp->severity,
                   (temp->status==0) ? "Pending" : "In Progress",
                   temp->description);
        }
        temp=temp->next;
    }
}
