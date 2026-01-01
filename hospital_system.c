#include <stdio.h>
#include <stdlib.h>

struct patient {
    int id;
    char name[30];
    int age;
    char disease[30];
};

void addPatient() {
    struct patient p;
    FILE *fp = fopen("patients.dat", "ab");

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Name: ");
    scanf("%s", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Disease: ");
    scanf("%s", p.disease);

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("\nPatient record added successfully!\n");
}

void viewPatients() {
    struct patient p;
    FILE *fp = fopen("patients.dat", "rb");

    printf("\n--- Patient Records ---\n");
    while (fread(&p, sizeof(p), 1, fp)) {
        printf("\nID: %d\nName: %s\nAge: %d\nDisease: %s\n",
               p.id, p.name, p.age, p.disease);
    }
    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
