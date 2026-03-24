#include "../include/stdlib.h"
#include "../include/string.h"
#include "../include/video.h"
#include "../include/stdio.h"
#include "../include/keyboard.h"

struct File {
    char name[20];
    char content[1024];
};

struct Directory {
    char name[20];
    struct File files[10];
    int file_count;
};

struct Directory root = {"root", {}, 0};
struct Directory *current_dir = &root;

char* whoami =
"        .\n"
"       ,O,\n"
"      ,OOO,\n"
"'oooooOOOOOooooo'\n"
"  `OOOOOOOOOOO`\n"
"    `OOOOOOO`\n"
"    OOOO'OOOO\n"
"   OOO'   'OOO\n"
"  O'         'O\n"
"\nRetra-Os\n";

void startcalc();
void ls();
void cd(char *name);
void nano();

void main() {
    clear_screen();
    printtext(whoami, 0x04, '#');
    while (1) {
        char buf[20];
        scan(buf, 20);
        if (strcmp(buf, "who") == 0) {
            printtext(whoami, 0x0a, '#');
        } else if (strcmp(buf, "calc") == 0) {
            startcalc();
            printtext("quited from calc\n", 0x04, 0);
        } else if (strcmp(buf, "help") == 0) {
            printtext("commands:\ncalc-->start calc\nwho-->print me :D\nhelp-->print that\nclear-->clear screen\nmeow-->print meow\nls-->list files\ncd-->change directory\nnano-->edit/create file\n", 0x0a, 0);
        } else if (strcmp(buf, "clear") == 0) {
            clear_screen();
        } else if (strcmp(buf, "meow") == 0) {
            printtext("meowmeow\n", 0x04, 0);
        } else if (strcmp(buf, "ls") == 0) {
            ls();
        } else if (strcmp(buf, "cd") == 0) {
            printtext("Enter directory name:\n", 0x0a, 0);
            char dir[20];
            scan(dir, 20);
            cd(dir);
        } else if (strcmp(buf, "nano") == 0) {
            nano();
        } else if (strlen(buf) > 0) {
            printtext("unknown command\n", 0x04, 0);
        }
    }
}

void startcalc() {
    next_line();
    printtext("operand a,b.operation +,-,/,* q-quit from calc write ops with numpad\n", 0x0a, 0);

    int stat = 1;
    while (stat) {
        next_line();
        printtext("a:", 0x0a, 0);

        char ac[10];
        scan(ac, 10);

        int a = atoi(ac);

        printtext("b:", 0x0a, 0);

        char bc[10];
        scan(bc, 10);
        int b = atoi(bc);

        printtext("op:", 0x0a, 0);
        char op[2];
        scan(op, 2);

        switch (op[0]) {
            char res[10];
            case '-':
                itoa((a - b), res);
                printtext(res, 0x0a, 0);
                break;
            case '+':
                itoa((a + b), res);
                printtext(res, 0x0a, 0);
                break;
            case '*':
                itoa((a * b), res);
                printtext(res, 0x0a, 0);
                break;
            case '/':
                if (b != 0) {
                    itoa((a / b), res);
                    printtext(res, 0x0a, 0);
                } else {
                    printtext("Error: Division by zero\n", 0x04, 0);
                }
                break;
            case 'q':
                stat = 0;
                break;
        }
    }
}

void ls() {
    printtext("Files:\n", 0x0a, 0);
    for (int i = 0; i < current_dir->file_count; i++) {
        printtext(current_dir->files[i].name, 0x0a, 0);
        printtext("\n", 0x0a, 0);
    }
}

void cd(char *name) {
    if (strcmp(name, "..") == 0) {
        current_dir = &root; // Возврат в корневую директорию
    } else {
        printtext("cd: Only root directory supported\n", 0x04, 0);
    }
}

void nano() {
    char file_name[20];
    printtext("Enter file name:\n", 0x0a, 0);
    scan(file_name, 20);

    for (int i = 0; i < current_dir->file_count; i++) {
        if (strcmp(current_dir->files[i].name, file_name) == 0) {
            printtext("Editing file...\n", 0x0a, 0);
            char content[1024];
            scan(content, 1024);
            strcpy(current_dir->files[i].content, content);
            return;
        }
    }

    // Если файл не найден, создаём новый
    if (current_dir->file_count < 10) {
        strcpy(current_dir->files[current_dir->file_count].name, file_name);
        printtext("New file. Enter content:\n", 0x0a, 0);
        char content[1024];
        scan(content, 1024);
        strcpy(current_dir->files[current_dir->file_count].content, content);
        current_dir->file_count++;
    } else {
        printtext("Error: Maximum file limit reached\n", 0x04, 0);
    }
}
