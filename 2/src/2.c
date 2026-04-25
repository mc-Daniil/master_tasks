#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Auth {
    char name[16];
    char password[16];
    void (*action)();
} user;

void secret_func() {
    if (strcmp(user.name, "admin") == 0 && strcmp(user.password, "qwert") == 0) {
        char *flag = getenv("FLAG");
        if (flag) {
            printf("%s\n", flag);
        }
    }
}

void greet() {
    printf("Hello, %s", user.name);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    strcpy(user.password, "passs");
    user.action = greet;

    printf("Enter name: ");
    read(0, user.name, 64);

    user.action();

    return 0;
}