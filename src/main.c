#include <stdio.h>
#include <stdlib.h>

#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main()
{
    char str1[100] = "Hello";
    char str2[] = " World";
    char copy[100];
    char limited[100];

    printf("--- Testing String Functions ---\n");

    printf("Length of str1: %d\n", mystrlen(str1));

    mystrcpy(copy, str1);
    printf("Copied string: %s\n", copy);

    mystrncpy(limited, str1, 3);
    printf("First 3 characters: %s\n", limited);

    mystrcat(str1, str2);
    printf("After concatenation: %s\n", str1);


    printf("\n--- Testing File Functions ---\n");

    FILE *file = fopen("test.txt", "r");

    if (file == NULL)
    {
        printf("Could not open test.txt\n");
        return 1;
    }

    int lines;
    int words;
    int chars;

    if (wordCount(file, &lines, &words, &chars) == 0)
    {
        printf("Lines: %d\n", lines);
        printf("Words: %d\n", words);
        printf("Characters: %d\n", chars);
    }

    fclose(file);


    file = fopen("test.txt", "r");

    if (file == NULL)
    {
        printf("Could not open test.txt\n");
        return 1;
    }

    char **matches;

    int count = mygrep(file, "Linux", &matches);

    if (count >= 0)
    {
        printf("\nLines containing 'Linux':\n");

        for (int i = 0; i < count; i++)
        {
            printf("%s", matches[i]);
            free(matches[i]);
        }

        free(matches);
    }

    fclose(file);

    return 0;
}
