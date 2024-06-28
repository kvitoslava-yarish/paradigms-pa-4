#include "TextEditor.h"
#include <cstring>
#include <cstdio>
#include "iostream"
#include "TextProcessor.h"
#include <sstream>
#include <string>
#include <limits>

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
int TextEditor::processFile(bool encode) {
    std::string input;
    std::cout << "Enter input file: ";
    char* inputFilePath = getTextInput();

    std::cout << "Enter output file: ";
    char* outputFilePath = getTextInput();

    int key;
    std::cout << "Enter key: ";
    std::cin >> key;

    if (std::cin.fail()) {
        std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input for key. Please enter an integer." << std::endl;
        delete[] inputFilePath, outputFilePath;
        return -1;
    }

    textProcessor.encryptText(inputFilePath, outputFilePath, key, encode);

    delete inputFilePath;
    delete outputFilePath;
    return 0;
}
void TextEditor:: run() {
    while(true) {
        fflush(stdin);
        setbuf(stdout, 0);
        std::cout << "\nChoose action  1 - encrypt, 2 - decrypt, 3 -exit \n";
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
            case 3:
                exit(0);
            default:
                std::cout << "enter proper command";
        }
    }
}