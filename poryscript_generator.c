#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 256
#define MAX_MSGS 20
#define MAX_CHOICES 10
#define MAX_MOVES 20
#define MAX_FLAGS 10
#define MAX_SOUNDS 5
#define MAX_LABELS 5
#define MAX_SUBSCRIPTS 5
#define MAX_COND_BLOCKS 5
#define MAX_BLOCK_LINES 10

void trim_newline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

void get_input(const char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin)) {
        trim_newline(buffer);
    } else {
        buffer[0] = '\0';
    }
}

int get_yes_no(const char *prompt) {
    char response[MAX_STR];
    while (1) {
        get_input(prompt, response, MAX_STR);
        if (strcmp(response, "yes") == 0) return 1;
        if (strcmp(response, "no") == 0) return 0;
        printf("Please enter 'yes' or 'no'.\n");
    }
}

void get_multiple_inputs(const char *prompt, char array[][MAX_STR], int *count, int max_count) {
    char input[MAX_STR];
    *count = 0;
    while (*count < max_count) {
        printf("%s (%d/%d, leave blank to finish): ", prompt, *count + 1, max_count);
        fgets(input, MAX_STR, stdin);
        trim_newline(input);
        if (strlen(input) == 0) break;
        strcpy(array[*count], input);
        (*count)++;
    }
}

void format_dialogue(const char *input, char *output) {
    int len = strlen(input);
    int out_i = 0;
    output[out_i++] = '"';
    for (int i = 0; i < len && out_i < MAX_STR - 3; i++) {
        if (input[i] == '"') {
            output[out_i++] = '\\';
            output[out_i++] = '"';
        } else if (input[i] == '{' && strncmp(&input[i], "{PLAYER}", 8) == 0) {
            strncpy(&output[out_i], "{PLAYER}", 8);
            out_i += 8;
            i += 7;
        } else {
            output[out_i++] = input[i];
            if (i > 40 && input[i] == ' ') {
                output[out_i++] = '\\';
                output[out_i++] = 'n';
            }
        }
    }
    output[out_i++] = '"';
    output[out_i] = '\0';
}

void print_templates() {
    printf("\n=== Script Template Presets ===\n");
    printf("0 = Custom (build your own)\n");
    printf("1 = NPC Chat\n");
    printf("2 = Gym Leader Badge Check\n");
    printf("3 = Give Item Once\n");
    printf("4 = Wild Pokémon Battle\n");
    printf("5 = One-Time Event\n");
    printf("6 = Loop-based Retry Event\n");
}

int choose_template() {
    print_templates();
    char input[MAX_STR];
    int t;
    while (1) {
        get_input("Choose a template (0-6): ", input, MAX_STR);
        t = atoi(input);
        if (t >= 0 && t <= 6) return t;
        printf("Invalid template. Try again.\n");
    }
}

void apply_template(int type,
                    char *scriptName,
                    int *useLock, int *useFaceplayer, int *useReleaseall,
                    char conditionFlags[][MAX_STR], int *condCount,
                    char *setFlag, char *callScript,
                    char messages[][MAX_STR], int *msgCount,
                    char *wildBattle,
                    char labels[][MAX_STR], int *labelCount) {
    switch (type) {
        case 1:
            strcpy(scriptName, "NPC_Talk");
            *useLock = *useFaceplayer = 1;
            *msgCount = 1;
            strcpy(messages[0], "Welcome, {PLAYER}!");
            break;
        case 2:
            strcpy(scriptName, "GymLeader_Check");
            *useLock = *useFaceplayer = 1;
            *condCount = 1;
            strcpy(conditionFlags[0], "FLAG_BADGE06_GET");
            strcpy(callScript, "GymVerifyIntro");
            *msgCount = 1;
            strcpy(messages[0], "Only true Gym Winners pass!");
            break;
        case 3:
            strcpy(scriptName, "GiveMysticWater");
            *condCount = 1;
            strcpy(conditionFlags[0], "FLAG_GOT_MYSTIC_WATER");
            strcpy(setFlag, "FLAG_GOT_MYSTIC_WATER");
            *msgCount = 2;
            strcpy(messages[0], "You obtained a Mystic Water!");
            strcpy(messages[1], "{PLAYER} puts it in the bag.");
            break;
        case 4:
            strcpy(scriptName, "BattleEvent");
            *useLock = *useFaceplayer = 1;
            *msgCount = 1;
            strcpy(messages[0], "Prepare for battle!");
            strcpy(wildBattle, "TRAINER_TEAM_MAGMA_MAXIE");
            break;
        case 5:
            strcpy(scriptName, "Event_OnlyOnce");
            *condCount = 1;
            strcpy(conditionFlags[0], "FLAG_SECRET_EVENT_DONE");
            strcpy(setFlag, "FLAG_SECRET_EVENT_DONE");
            *msgCount = 1;
            strcpy(messages[0], "This happens once.");
            break;
        case 6:
            strcpy(scriptName, "RetryLoopEvent");
            *msgCount = 2;
            *labelCount = 1;
            strcpy(labels[0], "RetryLoop");
            strcpy(messages[0], "Try again?");
            strcpy(messages[1], "Not quite.");
            break;
        default:
            break;
    }
}

int show_main_menu() {
    printf("\n=== Poryscript Generator ===\n");
    printf("1. Create New Script\n");
    printf("2. View Template Presets\n");
    printf("3. Exit\n");
    char input[MAX_STR];
    get_input("Select an option: ", input, MAX_STR);
    return atoi(input);
}

void generate_new_script();

int main() {
    int running = 1;
    while (running) {
        int choice = show_main_menu();
        switch (choice) {
            case 1:
                generate_new_script();
                break;
            case 2:
                print_templates();
                break;
            case 3:
                printf("Exiting. Goodbye!\n");
                running = 0;
                break;
            default:
                printf("Invalid choice. Please enter 1-3.\n");
        }
    }
    return 0;
}

void generate_new_script() {
    char scriptName[MAX_STR];
    char setFlag[MAX_STR] = "", callScript[MAX_STR] = "", gotoScript[MAX_STR] = "", wildBattle[MAX_STR] = "";
    char conditionFlags[MAX_FLAGS][MAX_STR];
    char messages[MAX_MSGS][MAX_STR], choices[MAX_CHOICES][MAX_STR];
    char movements[MAX_MOVES][MAX_STR], soundNames[MAX_SOUNDS][MAX_STR], cryMons[MAX_SOUNDS][MAX_STR];
    char labels[MAX_LABELS][MAX_STR], subScripts[MAX_SUBSCRIPTS][MAX_STR];
    char ifFlags[MAX_COND_BLOCKS][MAX_STR], ifMessages[MAX_BLOCK_LINES][MAX_STR], elseMessages[MAX_BLOCK_LINES][MAX_STR];

    int condCount = 0, msgCount = 0, choiceCount = 0, moveCount = 0;
    int soundCount = 0, cryCount = 0, labelCount = 0, subCount = 0;
    int ifCount = 0, ifMsgCount = 0, elseMsgCount = 0;
    int useLock = 0, useFaceplayer = 0, useReleaseall = 0;

    // Template selection
    int templateType = choose_template();
    apply_template(templateType, scriptName, &useLock, &useFaceplayer, &useReleaseall,
                   conditionFlags, &condCount, setFlag, callScript,
                   messages, &msgCount, wildBattle, labels, &labelCount);

    // User customization
    get_input("Enter script name (overwrite if using template): ", scriptName, MAX_STR);
    useLock = get_yes_no("Use lock? (yes/no): ");
    useFaceplayer = get_yes_no("Use faceplayer? (yes/no): ");
    useReleaseall = get_yes_no("Use releaseall? (yes/no): ");
    get_input("Flag to set (leave blank): ", setFlag, MAX_STR);
    get_input("Script to call (leave blank): ", callScript, MAX_STR);
    get_input("Goto label/script (leave blank): ", gotoScript, MAX_STR);
    get_input("Wild battle (leave blank): ", wildBattle, MAX_STR);

    get_multiple_inputs("Enter condition flag(s) to check", conditionFlags, &condCount, MAX_FLAGS);
    get_multiple_inputs("Enter label names", labels, &labelCount, MAX_LABELS);
    get_multiple_inputs("Enter reusable sub-scripts to call", subScripts, &subCount, MAX_SUBSCRIPTS);
    get_multiple_inputs("Enter movement labels", movements, &moveCount, MAX_MOVES);
    get_multiple_inputs("Enter sound effect names", soundNames, &soundCount, MAX_SOUNDS);
    get_multiple_inputs("Enter Pokémon cries", cryMons, &cryCount, MAX_SOUNDS);
    get_multiple_inputs("Enter message boxes", messages, &msgCount, MAX_MSGS);
    get_multiple_inputs("Enter multichoice options", choices, &choiceCount, MAX_CHOICES);

    if (get_yes_no("Add an if/else block? (yes/no): ")) {
        get_multiple_inputs("Enter flag(s) for IF check", ifFlags, &ifCount, MAX_COND_BLOCKS);
        get_multiple_inputs("Enter msgbox(es) for IF", ifMessages, &ifMsgCount, MAX_BLOCK_LINES);
        if (get_yes_no("Add ELSE block? (yes/no): ")) {
            get_multiple_inputs("Enter msgbox(es) for ELSE", elseMessages, &elseMsgCount, MAX_BLOCK_LINES);
        }
    }

    char outputFile[MAX_STR];
    get_input("Enter output filename (.pory): ", outputFile, MAX_STR);
    if (strlen(outputFile) == 0) strcpy(outputFile, "generated_script.pory");

    FILE *file = fopen(outputFile, "w");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    fprintf(file, "script %s {\n", scriptName);
    if (useLock) fprintf(file, "    lock\n");
    if (useFaceplayer) fprintf(file, "    faceplayer\n");

    for (int i = 0; i < condCount; i++) {
        fprintf(file, "    if (!flag(%s)) {\n        // condition block\n    }\n", conditionFlags[i]);
    }

    if (strlen(setFlag) > 0) fprintf(file, "    setflag(%s)\n", setFlag);
    if (strlen(callScript) > 0) fprintf(file, "    call(%s)\n", callScript);

    for (int i = 0; i < labelCount; i++) {
        fprintf(file, "label %s\n", labels[i]);
    }

    for (int i = 0; i < subCount; i++) {
        fprintf(file, "    call(%s)\n", subScripts[i]);
    }

    for (int i = 0; i < msgCount; i++) {
        char formatted[MAX_STR];
        format_dialogue(messages[i], formatted);
        fprintf(file, "    msgbox(%s)\n", formatted);
    }

    // === DYNAMIC MULTICHOICE INJECTION ===
    if (choiceCount > 0) {
        int left = 0, top = 0, ignoreBPress = 0, maxBeforeScroll = 4, initialSelected = 0;
        char callbacks[MAX_CHOICES][MAX_STR] = {""};
        char input[MAX_STR];

        printf("Set custom left position? (default 0): ");
        fgets(input, MAX_STR, stdin); trim_newline(input);
        if (strlen(input) > 0) left = atoi(input);

        printf("Set custom top position? (default 0): ");
        fgets(input, MAX_STR, stdin); trim_newline(input);
        if (strlen(input) > 0) top = atoi(input);

        ignoreBPress = get_yes_no("Ignore B press? (yes/no): ");

        printf("Set max options before scroll? (default 4): ");
        fgets(input, MAX_STR, stdin); trim_newline(input);
        if (strlen(input) > 0) maxBeforeScroll = atoi(input);

        printf("Set initial selected? (default 0): ");
        fgets(input, MAX_STR, stdin); trim_newline(input);
        if (strlen(input) > 0) initialSelected = atoi(input);

        for (int i = 0; i < choiceCount; i++) {
            printf("Enter callback for choice %d (leave blank for none): ", i + 1);
            fgets(callbacks[i], MAX_STR, stdin);
            trim_newline(callbacks[i]);
        }

        fprintf(file, "    dynmultichoice(%d, %d, %d, %d, %d, {", left, top, ignoreBPress, maxBeforeScroll, initialSelected);
        for (int i = 0; i < choiceCount; i++) {
            if (strlen(callbacks[i]) > 0)
                fprintf(file, "%s", callbacks[i]);
            else
                fprintf(file, "NULL");
            if (i < choiceCount - 1)
                fprintf(file, ", ");
        }
        fprintf(file, "}, ");
        for (int i = 0; i < choiceCount; i++) {
            fprintf(file, "\"%s\"", choices[i]);
            if (i < choiceCount - 1)
                fprintf(file, ", ");
        }
        fprintf(file, ")\n");
    }
    // === END DYNAMIC MULTICHOICE INJECTION ===

    for (int i = 0; i < soundCount; i++) {
        fprintf(file, "    sound(%s)\n", soundNames[i]);
    }

    for (int i = 0; i < cryCount; i++) {
        fprintf(file, "    cry(%s)\n", cryMons[i]);
    }

    if (strlen(wildBattle) > 0) {
        fprintf(file, "    trainerbattle(%s)\n", wildBattle);
    }

    for (int i = 0; i < moveCount; i++) {
        fprintf(file, "    applymovement(player, %s)\n", movements[i]);
    }

    if (strlen(gotoScript) > 0) {
        fprintf(file, "    goto(%s)\n", gotoScript);
    }

    if (useReleaseall) {
        fprintf(file, "    releaseall\n");
    }

    if (ifCount > 0) {
        fprintf(file, "\n    // Conditional Branch Block\n");
        fprintf(file, "    if (flag(%s)) {\n", ifFlags[0]);
        for (int i = 0; i < ifMsgCount; i++) {
            char formatted[MAX_STR];
            format_dialogue(ifMessages[i], formatted);
            fprintf(file, "        msgbox(%s)\n", formatted);
        }
        if (elseMsgCount > 0) {
            fprintf(file, "    } else {\n");
            for (int i = 0; i < elseMsgCount; i++) {
                char formatted[MAX_STR];
                format_dialogue(elseMessages[i], formatted);
                fprintf(file, "        msgbox(%s)\n", formatted);
            }
        }
        fprintf(file, "    }\n");
    }

    fprintf(file, "    end\n}\n");
    fclose(file);

    printf("✅ Script written to '%s'\n", outputFile);
}
