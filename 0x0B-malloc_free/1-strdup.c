#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* _strdup(const char* str) {
    size_t length;
    char* duplicate;

    if (str == NULL) {
        return (NULL); /* Return NULL if str is NULL */
    }

    /* Get the length of the string */
    length = strlen(str);

    /* Allocate memory for the duplicated string */
    duplicate = (char*) malloc((length + 1) * sizeof(char));

    if (duplicate != NULL) {
        strcpy(duplicate, str); /* Copy the string into the newly allocated memory */
    }

    return (duplicate);
}

int main(void) {
    const char* original = "ALX SE";
    char* duplicate = _strdup(original);

    if (duplicate != NULL) {
        printf("%s\n", duplicate);
        free(duplicate); /* Free the dynamically allocated memory */
    } else {
        printf("Failed to duplicate the string or str was NULL.\n");
    }

    return (0);
}

