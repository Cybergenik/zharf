#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_domain(char *domain) {
    printf("Domain is %s\n", domain);
}

char *parse(char *str) {
    char buffer[1024];
    char *token, *substr;

    if(!str) {
        return "NO";
    }

    for (substr=str; ; substr=NULL) {
        token = strtok(substr, "@");
        
        if (token==NULL) {
            break;
        }

        if (substr==NULL) {
            strcpy(buffer, token);
            print_domain(buffer);
            return "YES";
        }
    }

    return "NO";
}

int unsafe_assign(int* buf){
	if(buf == NULL){
		free(buf);
		return -1;
	}
	*buf = 99;
	free(buf);
	return 0;
}

int main(int argc, char **argv) {

    if (argc<3) {
        puts("./getdomain <email_address>");
        return 1;
    }

    printf("Domain is valid? %s\n", parse(strdup(argv[1])));
	int* val = malloc(sizeof(int));
	*val = atoi(argv[2]);
    printf("Freeing %d\n", unsafe_assign(val));
    printf("%d\n", *val);

    return 0;
}
