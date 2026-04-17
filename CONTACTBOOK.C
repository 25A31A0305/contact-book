#include <stdio.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[15];
};

struct contact c[100];
int count = 0;

// Add Contact
void addContact() {
    printf("Enter Name: ");
    scanf("%s", c[count].name);
    
    printf("Enter Phone Number: ");
    scanf("%s", c[count].phone);
    
    count++;
    printf("Contact Added Successfully!\n");
}

// View Contacts
void viewContacts() {
    if(count == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\nContact List:\n");
    for(int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i+1, c[i].name, c[i].phone);
    }
}

// Search Contact
void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(c[i].name, name) == 0) {
            printf("Found! Name: %s, Phone: %s\n", c[i].name, c[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Main Function
int main() {
    int choice;

    while(1) {
        printf("\n--- Contact Book ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}