#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structs here so dispatch.c knows them
struct Report {
    int id;
    char description[100];
    int severity;
    int status;        // 0 = Pending, 1 = In Progress, 2 = Resolved
    int assignedUnit;
    struct Report *prev, *next;
};

struct Unit {
    int id;
    int busy;
    int reportId;
};

struct Log {
    int id;
    char description[100];
    int severity;
    struct Log* next;
};

extern struct Report* head;
extern struct Unit units[3];
extern struct Log* logTop;

void dispatchPolice() {
    struct Report* cur = head;
    struct Report* best = NULL;

    while (cur != NULL) {
        if (cur->status == 0) { // Pending
            if (best == NULL || cur->severity > best->severity) {
                best = cur;
            }
        }
        cur = cur->next;
    }

    if (best == NULL) {
        printf("No pending reports.\n");
        return;
    }

    int unitId = -1;
    for (int i = 0; i < 3; i++) {
        if (units[i].busy == 0) {
            unitId = i;
            break;
        }
    }

    if (unitId == -1) {
        printf("No free units.\n");
        return;
    }

    units[unitId].busy = 1;
    units[unitId].reportId = best->id;
    best->assignedUnit = units[unitId].id;
    best->status = 1;

    printf("Unit %d dispatched to Report %d.\n", units[unitId].id, best->id);
}

void markAsResolved() {
    int id;
    printf("Enter report ID to resolve: ");
    scanf("%d", &id);

    struct Report* cur = head;
    while (cur != NULL && cur->id != id) cur = cur->next;

    if (cur == NULL || cur->status != 1) {
        printf("Report not found or not In Progress.\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (units[i].reportId == id) {
            units[i].busy = 0;
            units[i].reportId = -1;
        }
    }

    cur->status = 2;

    struct Log* log = (struct Log*)malloc(sizeof(struct Log));
    log->id = cur->id;
    strcpy(log->description, cur->description);
    log->severity = cur->severity;
    log->next = logTop;
    logTop = log;

    printf("Report %d resolved and logged.\n", id);
}
