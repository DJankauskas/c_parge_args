#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char **line(char *parse_args);

void remove_newline(char *str);

int main() {
    printf("Enter program and arguments: ");
    char user_args[1000];
    fgets(user_args, sizeof user_args, stdin);
    printf("\n");
    remove_newline(user_args);
    char **parsed_args = line(user_args);
    execvp(parsed_args[0], parsed_args);
    free(parsed_args);
}

char **line(char *parse_args) {
    char **line = calloc(6, sizeof(char*));
    int line_pos = 0;

    do {
        line[line_pos++] = strsep(&parse_args, " ");
    }
    while(parse_args != NULL && line_pos < 6);
    return line;
}

void remove_newline(char *str) {
    for(size_t i = 0; str[i] != '\0'; i++) {
        if(str[i] == '\n') {
            str[i] = '\0';
            return;
        }
    }
}