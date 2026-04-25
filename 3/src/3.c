#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void win() {
    char *flag = getenv("FLAG");
    if (flag) {
        printf("%s\n", flag);
    }
}

int vuln() {
    char buf[32];
    unsigned int password = 0;
    
    printf("Enter password: ");
    read(0, buf, 128);
    
    password = atoi(buf);
    
    if ((password ^ 0xdeadbeef) != 0x13371337) {
        printf("Wrong password!\n");
        exit(1);
    }
    
    printf("Access granted!\n");
    return 0;
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    vuln();
    return 0;
}