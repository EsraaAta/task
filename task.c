#include <stdio.h>
#include <string.h>

user information
struct User {
    char username[30];
    char password[30];
};

register a new user
void registerUser(struct User users[], int *count) {
    printf("username: ");
    scanf("%s", users[*count].username);
    printf("password: ");
    scanf("%s", users[*count].password);
    *count += 1;
}

login a user
int loginUser(struct User users[], int count) {
    char username[30];
    char password[30];
    printf("username: ");
    scanf("%s", username);
    printf("password: ");
    scanf("%s", password);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successfully!, %s!\n", users[i].username);
            return 1;
        }
    }
    
    printf("Login failed. \n");
    return 0;
}

int main() {
    struct User users[30]; 
    int count = 0;
    
    int choice;
    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                registerUser(users, &count);
                break;
            case 2:
                if (loginUser(users, count))
                    return 0;
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}
