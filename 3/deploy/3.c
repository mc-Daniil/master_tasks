#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void win() {
    char *flag = getenv("FLAG");
    if (flag) {
        printf("%s\n", flag);
    }
}

int vuln() {
    char buf[32];
    
    printf("Enter password: ");
    read(0, buf, 128);
    
    if ((buf[0] ^ 0x32) != 0x32 || (buf[1] ^ 0x42) != 0x35 || 
        (buf[2] ^ 0x52) != 0x2c || (buf[3] ^ 0x62) != 0x63) {
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