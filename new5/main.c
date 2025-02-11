#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[31];
    char address[51];
    char phone[11];
    int age;
}Contact;

Contact CreateContactToRepair(){
    Contact newContacts;

    printf("Enter the datà for the newContact!\n");
    printf("Name: ");
    fgets(newContacts.name, sizeof(newContacts.name), stdin);
    printf("Address: ");
    fgets(newContacts.address, sizeof(newContacts.address), stdin);
    printf("Phone: ");
    scanf("%11s", newContacts.phone);
    printf("Age: ");
    scanf("%d", &newContacts.age);
    getchar();

    return newContacts;
}

void ContactRepair(Contact *contacts, int size, int index1, Contact newContact){
    if(index1 < 0 || index1 > size){
        printf("The index is out of bound!\n");
        exit(5);
    }
    contacts[index1] = newContact;
    printf("The contact with index %d is repaired!\n", index1);
}

Contact* CompareByNameAndPhone(Contact *contacts, int *size, char name1[], char phone1[]){
    int flag = 0;
    for(int i = 0; i< *size; i++){
        if(strcmp(contacts[i].name, name1) == 0 && strcmp(contacts[i].phone, phone1) == 0){
            for(int j = i; j < *size - 1; j++){
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
            flag = 1;
            break;
        }
    }
    if(flag){
        if(*size > 0){
            Contact *newContacts = (Contact*)realloc(contacts, sizeof(Contact) * (*size));
            if(newContacts == NULL){
                printf("The memory is not allocated successfully!\n");
                return NULL;
            }
            return newContacts;
        }
        else{
            free(contacts);
            return NULL;
        }
    }
    return contacts;
}

int AgeBarier(Contact *contacts, int size, int min1, int max1){
    FILE *fp = fopen("envelops.txt", "a");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(6);
    }

    int flag = 0;
    for(int i = 0; i < size; i++){
        if(contacts[i].age > min1 && contacts[i].age < max1){
            fprintf(fp, "Name: %s\n", contacts[i].name);
            fprintf(fp, "Address: %s\n", contacts[i].address);
            flag = 1;
        }
    }
    if(flag){
        return 0;
    }
    else{
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
    if(fread(&n, sizeof(int), 1, fp) != 1){
        printf("The number of contacts is not found in the file!\n");
        exit(2);
    }

    Contact *contacts = (Contact*)malloc(sizeof(Contact) * n);
    if(contacts == NULL){
        printf("The memory is not allocated successfully!\n");
        exit(3);
    }

    if(fread(contacts, sizeof(Contact), n, fp) != n){
        printf("The contacts are not found in the file!\n");
        exit(4);
    }

    int index;
    printf("Enter an index from 0 to %d: ", n - 1);
    scanf("%d", &index);

    Contact newContacts = CreateContactToRepair();

    ContactRepair(contacts, n, index, newContacts);

    printf("The contacts after the repair!\n");
    for(int i = 0; i < n; i++){
        printf("%s - %s - %s - %d", contacts[i].name, contacts[i].address, contacts[i].phone, contacts[i].age);
    }

    char CompareName[31];
    printf("Enter a name to compare: ");
    fgets(CompareName, sizeof(CompareName), stdin);
    char ComparePhone[11];
    printf("Enter a phone to compare: ");
    scanf("%11s", ComparePhone);
    getchar();

    contacts = CompareByNameAndPhone(contacts, &n, CompareName, ComparePhone);
    if(contacts != NULL){
        printf("The contacts list is updated!\n");
    }
    else{
        printf("The contacts list is not updated!\n");
    }

    int min;
    printf("Enter the minimum age to participate: ");
    scanf("%d", &min);
    int max;
    printf("Enter the maximum age to participate: ");
    scanf("%d", &max);

    int num  = AgeBarier(contacts, n, min, max);
    if(num == 0){
        printf("The contacts are invited!\n");
    }
    else{
        printf("There arent any coincidences!\n");
    }

    fclose(fp);

    free(contacts);

    return 0;
}
