#include<stdio.h>
#include<string.h>
int main() {
    char *exp_type = " ";
    if(strcmp(exp_type," ")==0) {
        strcpy(exp_type, "sankhya");
    }
    printf("%s\n", exp_type);
    return 0;
}
