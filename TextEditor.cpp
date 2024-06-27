#include "TextEditor.h"
#include <cstring>
#include <cstdio>
#include "iostream"
#include "TextProcessor.h"

char* TextEditor::getTextInput() {
    int size = 10;
    char* text = new char[size * sizeof(char)];
    char symbol;
    symbol = getchar();
    int index = 0;
    while(symbol != '\n') {
        if(index > size / sizeof(char) - 1) {
            size = size * 2;
            char *new_text = new char[size];
            strcpy(new_text, text);
            text = new_text;
        }
        text[index] = symbol;
        index++;
        symbol = getchar();
    }
    text[index] = '\0';
    return text;
}
char* TextEditor:: processFile(bool encode)
{
    std:: cout <<"enter input file";
    char* inputFilePath = getTextInput();
    std:: cout <<"\n enter output file";
    char* outputFilePath = getTextInput();
    std:: cout <<"\n enter key";
    int key = scanf("%d");
    textProcessor.encryptText(outputFilePath, inputFilePath, key, encode);

}
void TextEditor:: run() {
    while(true) {
        fflush(stdin);
        setbuf(stdout, 0);
        std::cout << "\nChoose action  1 - encrypt, 2 - decrypt\n";
        int choice;
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                processFile(true);
                break;
            case 2:
                processFile(false);
                break;
            default:
                std::cout << "enter proper command";
        }
    }
}