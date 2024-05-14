#include <stdio.h>
#include <string.h>

void string(char *ptr, char *str2) {
    if (strcmp(ptr, str2) > 0) {
        printf("A ordem alfabetica e primeiro essa: %s\n", str2);
        printf("depois essa: %s\n", ptr);
    } else {
        printf("A ordem alfabetica e primeiro essa: %s\n", ptr);
        printf("depois essa: %s\n", str2);
    }
}

int main() {
    char str1[100], str2[100];

    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; 

    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; 

    string(str1, str2);

    return 0;
}


