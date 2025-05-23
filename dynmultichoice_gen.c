#include <stdio.h>
#include <string.h>

#define MAX_CHOICES 12
#define MAX_STR 128

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len && str[len - 1] == '\n') str[len - 1] = 0;
}

int main() {
    char scriptName[MAX_STR];
    int numChoices;
    char choices[MAX_CHOICES][MAX_STR];
    char callbacks[MAX_CHOICES][MAX_STR];

    printf("Enter script name: ");
    fgets(scriptName, MAX_STR, stdin);
    trim_newline(scriptName);

    do {
        printf("How many choices? (1-%d): ", MAX_CHOICES);
        scanf("%d", &numChoices);
        getchar(); // Eat newline
        if(numChoices < 1 || numChoices > MAX_CHOICES)
            printf("Invalid. Try again.\n");
    } while(numChoices < 1 || numChoices > MAX_CHOICES);

    for (int i = 0; i < numChoices; i++) {
        printf("Enter text for Choice %d: ", i + 1);
        fgets(choices[i], MAX_STR, stdin);
        trim_newline(choices[i]);
        printf("Enter callback label for Choice %d (e.g. Option%dCallback): ", i + 1, i + 1);
        fgets(callbacks[i], MAX_STR, stdin);
        trim_newline(callbacks[i]);
    }

    printf("\nGenerated Poryscript:\n\n");

    printf("script %s {\n", scriptName);
    printf("    lock\n");
    printf("    faceplayer\n");
    printf("    msgbox(\"Pick an option:\")\n");
    printf("    dynmultichoice(0, 0, FALSE, %d, 1,", numChoices);

    // Print callbacks
    for (int i = 0; i < numChoices; i++) {
        printf(" %s,", callbacks[i]);
    }
    // Print choice texts
    for (int i = 0; i < numChoices; i++) {
        printf(" \"%s\"", choices[i]);
        if (i != numChoices - 1)
            printf(",");
    }
    printf(")\n");
    printf("    closemessage\n");
    printf("    end\n");
    printf("}\n\n");

    // Output callback labels
    for (int i = 0; i < numChoices; i++) {
        printf("%s:\n", callbacks[i]);
        printf("    msgbox(\"You picked %s!\")\n", choices[i]);
        printf("    end\n\n");
    }

    printf("// End of script\n");
    return 0;
}
