/*
 * Student Information Register
 * Team 2 Implementation
 * Approach: Typedef struct, modular routines, clean formatting
 */
#include <stdio.h>
#include <string.h>

#define LIMIT 60

typedef struct {
    int id;
    char fullName[60];
    char dept[30];
    double score;
} StudentEntry;

StudentEntry roster[LIMIT];
int totalStudents = 0;

void insertStudent(void) {
    if (totalStudents >= LIMIT) {
        printf("[Error] Storage full.\n");
        return;
    }
    StudentEntry *s = &roster[totalStudents];
    printf("\n[+] Enter Student ID: ");
    scanf("%d", &s->id);
    getchar();
    printf("[+] Student Name: ");
    fgets(s->fullName, sizeof(s->fullName), stdin);
    s->fullName[strcspn(s->fullName, "\r\n")] = '\0';
    printf("[+] Department: ");
    fgets(s->dept, sizeof(s->dept), stdin);
    s->dept[strcspn(s->dept, "\r\n")] = '\0';
    printf("[+] Total Marks: ");
    scanf("%lf", &s->score);
    totalStudents++;
    printf("[*] Student enrolled successfully.\n");
}

void listStudents(void) {
    if (totalStudents == 0) {
        printf("\n[!] No records found.\n");
        return;
    }
    printf("\n=== ACTIVE ENROLLMENTS ===\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("#%02d | ID: %-5d | Name: %-20s | Dept: %-10s | Score: %.2f\n",
               i + 1, roster[i].id, roster[i].fullName, roster[i].dept, roster[i].score);
    }
}

void locateStudent(void) {
    int targetId;
    printf("\nTarget ID to query: ");
    scanf("%d", &targetId);
    for (int i = 0; i < totalStudents; i++) {
        if (roster[i].id == targetId) {
            printf("[Match] Name: %s, Dept: %s, Score: %.2f\n",
                   roster[i].fullName, roster[i].dept, roster[i].score);
            return;
        }
    }
    printf("[-] ID not present.\n");
}

int main(void) {
    int opt;
    do {
        printf("\n[STUDENT REGISTRY T2]\n1. Enroll\n2. View List\n3. Query ID\n4. Quit\nAction: ");
        if (scanf("%d", &opt) != 1) break;
        switch (opt) {
            case 1: insertStudent(); break;
            case 2: listStudents(); break;
            case 3: locateStudent(); break;
            case 4: printf("Exiting system.\n"); break;
            default: printf("Unknown command.\n");
        }
    } while (opt != 4);
    return 0;
}
