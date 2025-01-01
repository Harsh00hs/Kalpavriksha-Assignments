#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define nameLength 50
#define userFile "users.txt"

typedef struct{
    int id;
    char name[nameLength];
    int age;
} User;

void createFie(){
    FILE *file = fopen(userFile, "a");
    if(file==NULL){
        printf("Error: cant open file");
        exit(1);
    }
    fclose(file);
}

int getInt(const char *msg) {
    int value;
    printf("%s", msg);
    if (scanf("%d", &value) != 1) {
        printf("Error: Enter Integer only.\n");
        exit(1);
    }
    return value;
}

void getString(const char *msg, char *output, int maxLength) {
    printf("%s", msg);
    getchar();
    if (fgets(output, maxLength, stdin) == NULL) {
        printf("Error: Invalid input.\n");
        exit(1);
    }
    output[strcspn(output, "\n")] = 0; // Remove newlines
}

int uniqueId(int id){
    FILE *file = fopen(userFile, "r");
    if(!file)
        return 1;
    
    User u;
    while(fscanf(file, "%d, %49[^,], %d \n", &u.id, &u.name, &u.age) == 3){
        if (u.id == id) {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}

void add(){
    User u;
    u.id = getInt("Enter User ID: ");

    if(!uniqueId(u.id)){
        printf("Error: User Id already exists.\n");
        return;
    }

    getString("Enter Name: ", u.name, nameLength);
    u.age = getInt("Enter age: ");

    FILE *file= fopen(userFile, "a");
    if(!file){
        printf("Error: Can't open file");
        return;
    }

    fprintf(file, "%d, %s, %d\n", u.id, u.name, u.age);
    fclose(file);
    printf("User added successfully.\n");
}

void delete(){
    int id = getInt("Enter User ID to delete: ");

    FILE *file = fopen(userFile, "r");
    if (!file) {
        printf("No data available for deletion.\n");
        return;
    }

    User user;
    int found = 0;
    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error: Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d, %49[^,], %d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == id) {
            found = 1;
        } else {
            fprintf(tempFile, "%d, %s, %d\n", user.id, user.name, user.age);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(userFile);
        rename("temp.txt", userFile);
        printf("User deleted successfully.\n");
    } else {
        remove("temp.txt");
        printf("User ID not found.\n");
    }
}

void update(){
    int id = getInt("Enter User ID for the update: ");

    FILE *file = fopen(userFile, "r");
    if (!file) {
        printf("No data available for update.\n");
        return;
    }

    User u;
    int found = 0;
    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error: Unable to create temporary file.\n");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d, %49[^,], %d\n", &u.id, u.name, &u.age) == 3) {
        if (u.id == id) {
            found = 1;
            getString("Enter new Name: ", u.name, nameLength);
            u.age = getInt("Enter new Age: ");
        }
        fprintf(tempFile, "%d, %s, %d\n", u.id, u.name, u.age);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(userFile);
        rename("temp.txt", userFile);
        printf("User updated successfully.\n");
    } else {
        remove("temp.txt");
        printf("User ID not found.\n");
    }
}

void display(){
    FILE *file = fopen(userFile, "r");
    if (!file) {
        printf("Nothing found.\n");
        return;
    }

    User u;
    int count = 0;
    while (fscanf(file, "%d, %49[^,], %d\n", &u.id, u.name, &u.age) == 3) {
        printf("ID: %d, Name: %s, Age: %d\n", u.id, u.name, u.age);
        count++;
    }

    if (count == 0) {
        printf("No data available.\n");
    }else{
        printf("\nThese %d users are found here...\n\n", count);
    }

    fclose(file);
}

int main(){
    createFie();
    int ch;
    while(1){
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Display Users\n");
        printf("4. Update User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        ch = getInt("");

        switch(ch){
            case 1:
                add();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                update();
                break;
            case 5:
                printf("\n-----------------Program is Terminated-----------------\n");
                exit(0);
            default:
                printf("Enter something valid to continue: \n");
                exit(1);
        }
    }
    return 0;
}