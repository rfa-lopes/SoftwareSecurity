#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void cpy(char *d, char *s)
{
 while ('\0' != (*d++ = *s++));
}

int check_authentication(char *password) {
            int auth_flag = 0;
            char password_buffer[8]; //  = malloc(strlen(password));

	    cpy(password_buffer, password);

                        if(strcmp(password_buffer, "foo123") == 0)
                                        auth_flag = 1;

                            return auth_flag;
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
                    printf("Usage: %s <password>\n", argv[0]);
    } else
        if(check_authentication(argv[1])) {
                printf("Access Granted.\n");
    } else {
           printf("Access Denied.\n");
    }
}

