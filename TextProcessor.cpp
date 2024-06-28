#include <iostream>
#include <cstring>
#include <fstream>
#include "TextProcessor.h"
#include "CaesarCipher.h"

//int TextProcessor:: encryptText(char* outputFilePath, char* inputFilePath, int key, bool encode)
//{
//
//    FILE* file = fopen(inputFilePath, "r");
//    if (!file) {
//        std::cout << "Not able to open the file.\n";
//        return -1;
//    }
//    int line_size = 100;
//    char *line = new char[line_size];
//    char chunk[100];
//    if (line == nullptr) {
//        std::cout << "Unable to allocate memory for the line buffer";
//    }
//
//    while (fgets(chunk, sizeof(chunk), file)) {
//        if (line_size  < sizeof(chunk)) {
//            line_size *= 2;
//            char *temp = new char[line_size];
//            if (temp == nullptr) {
//                std::cout << "Unable to reallocate memory for the line buffer";
//                delete[] line;
//            }
//            line = temp;
//        }
//        strcpy(line, chunk);
//        if (line[strlen(line) - 1] == '\n') {
//            line[strlen(line) - 1] = '\0';
//            std::cout<< line;
//            char* codedLine = (encode) ? encodeLine(line, key) : decodeLine(line, key);
//            lineToFile(codedLine, outputFilePath);
//        }
//    }
//    if (strlen(line) > 0) {
//        std::cout<< line;
//        char* codedLine = (encode) ? encodeLine(line, key) : decodeLine(line, key);
//        lineToFile(codedLine, outputFilePath);
//
//    }
//    delete[] line;
//    fclose(file);
//}
int TextProcessor::encryptText( char* inputFilePath, char* outputFilePath, int key, bool encode) {
    std::ifstream file(inputFilePath);
    if (!file) {
        std::cerr << "Not able to open the file.\n";
        return -1;
    }

    char line[200];
    while (file.getline(line, 200)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        char* codedLine = (encode)? encodeLine(line, key) : decodeLine(line, key);
        lineToFile(codedLine, outputFilePath);
        delete[] codedLine;
    }
    file.close();
    return 0;
}

char* TextProcessor :: encodeLine(char* line, int key)
{
    encrypt_ptr_t encryptFunc = dll.getEncryptFunc();
    return encryptFunc(line, key);
}

char* TextProcessor :: decodeLine(char* line, int key)
{
    decrypt_ptr_t decryptFunc = dll.getDecryptFunc();
    return decryptFunc(line, key);
}

int TextProcessor:: lineToFile(char* line, char* filePath) {
    std::ofstream outputFile(filePath, std::ios::app);  // Open file in append mode
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return -1;
    }
    outputFile << line << std::endl;
    outputFile.close();
    return 0;
}