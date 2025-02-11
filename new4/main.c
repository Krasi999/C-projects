#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[31];
    char address[51];
    char phone[11];
    int age;
}Contact;


void updateContact(Contact* contacts, int size, int index, Contact newContact) {
    if (index < 0 || index >= size) {
        printf("Error: Index out of bounds.\n");
        return;
    }
    contacts[index] = newContact;
    printf("Contact at index %d updated successfully.\n", index);
}

Contact* CompareByNameAndPhone(Contact *contacts, int *size, char name1[], char phone1[]) {
    int flag = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(contacts[i].name, name1) == 0 && strcmp(contacts[i].phone, phone1) == 0) {
            for (int j = i; j < *size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
            flag = 1;
            break;
        }
    }

     if (flag) {
        if (*size > 0) {
            Contact *newContacts = realloc(contacts, sizeof(Contact) * (*size));
            if (newContacts == NULL) {
                printf("The memory is not allocated successfully!\n");
                return NULL;
            }
            return newContacts;
        }
        else {
            free(contacts);
            return NULL;
        }
    }

    return contacts;
}

int MinMaxFunction(Contact *contacts, int size, int min, int max){
    FILE *fp = fopen("envelops.txt", "a");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(1);
    }
    int flag = 0;
    for(int i = 0; i<size; i++){
        if(contacts[i].age > min && contacts[i].age < max){
            fprintf(fp, "Name: %s\n",contacts[i].name);
            fprintf(fp, "Addres: %s\n", contacts[i].address);
            flag = 1;
        }
    }
    if(flag){
        return 0;
    }else{
        return 1;
    }

    fclose(fp);
}

int main()
{
    FILE *fp = fopen("contacts.bin", "rb");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(1);
    }

    int n;
    if (fread(&n, sizeof(int), 1, fp) != 1) {
        printf("Error reading number of contacts from file!\n");
        exit(2);
    }

    Contact *contacts = (Contact*)malloc(sizeof(Contact)*n);
    if(contacts == NULL){
        printf("The memory is not allocated successfully!\n");
        exit(3);
    }
    if (fread(contacts, sizeof(Contact), n, fp) != n) {
        printf("Error reading contacts from file!\n");
        exit(4);
    }

    int index;
    printf("Enter the index of the contact to update (0 to %d): ", n - 1);
    scanf("%d", &index);
    getchar();

    Contact newContact;

    printf("Enter new details for contact %d:\n", index + 1);
    printf("Name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    printf("Address: ");
    fgets(newContact.address, sizeof(newContact.address), stdin);
    printf("Phone: ");
    scanf("%11s", newContact.phone);
    printf("Age: ");
    scanf("%d", &newContact.age);
    getchar();

    updateContact(contacts, n, index, newContact);

    printf("Updated contact:\n");
    printf("Name: %s, Address: %s, Phone: %s, Age: %d\n",
           contacts[index].name, contacts[index].address, contacts[index].phone, contacts[index].age);

    char CompareName[31];
    printf("Enter a name to compare: ");
    fgets(CompareName, sizeof(CompareName), stdin);
    char ComparePhone;
    printf("Enter a phone to compare: ");
    scanf("%11s", ComparePhone);
    getchar();

    contacts = CompareByNameAndPhone(contacts, &n, CompareName, ComparePhone);

    if (contacts != NULL) {
        printf("Updated contact list:\n");
        for (int i = 0; i < n; i++) {
            printf("Name: %s, Phone: %s, Age: %d\n", contacts[i].name, contacts[i].phone, contacts[i].age);
        }
    }
    else{
        printf("Error updating contact list.\n");
    }

    int Min1;
    printf("Enter a minimum age to participate: ");
    scanf("%d", &Min1);
    int Max1;
    printf("Enter a maximum age to participate: ");
    scanf("%d", &Max1);
    getchar();

    int num = MinMaxFunction(contacts, n, Min1, Max1);
    if(num == 0){
        printf("The guests are invited!\n");
    }
    else{
        printf("There arent any coincidences!\n");
    }

    fclose(fp);

    free(contacts);

    return 0;
}
