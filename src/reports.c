#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Report {
    int id;
    char description[100];
    int severity;
    int status;       // 0=Pending, 1=In Progress, 2=Resolved
    int assignedUnit;
    struct Report* prev;
    struct Report* next;
};

struct Report* head = NULL;
struct Report* tail = NULL;
int nextId = 1;

// Add new report
void addReport() {
    struct Report* newNode = (struct Report*)malloc(sizeof(struct Report));
    newNode->id = nextId++;

    printf("Enter description: ");
    getchar(); // clear leftover newline
    fgets(newNode->description, 100, stdin);
    newNode->description[strcspn(newNode->description, "\n")] = '\0';

    printf("Enter severity (1-5): ");
    scanf("%d", &newNode->severity);

    newNode->status = 0; // Pending
    newNode->assignedUnit = -1;
    newNode->prev = tail;
    newNode->next = NULL;

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    printf("Report %d added.\n", newNode->id);
}

// Delete report
void deleteReport() {
    int id;
    printf("Enter report ID to delete: ");
    scanf("%d", &id);

    struct Report* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            if (temp->status == 1) {
                printf("Cannot delete. Report is In Progress.\n");
                return;
            }
            if (temp->prev != NULL) temp->prev->next = temp->next;
            else head = temp->next;

            if (temp->next != NULL) temp->next->prev = temp->prev;
            else tail = temp->prev;

            free(temp);
            printf("Report %d deleted.\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("Report %d not found.\n", id);
}

// Show all pending / in progress
void displayPendingReports() {
    struct Report* temp = head;
    printf("\n--- Pending / In Progress Reports ---\n");
    while (temp != NULL) {
        if (temp->status != 2) {
            printf("ID:%d | Sev:%d | Status:%s | Desc:%s\n",
                   temp->id, temp->severity,
                   (temp->status == 0) ? "Pending" : "In Progress",
                   temp->description);
        }
        temp = temp->next;
    }
}
