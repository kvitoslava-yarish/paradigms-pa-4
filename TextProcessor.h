#ifndef PARADIGMS_PA_4_TEXTPROCESSOR_H
#define PARADIGMS_PA_4_TEXTPROCESSOR_H
#include "CaesarCipher.h"


class TextProcessor {
public:
    int encryptText(char* outputFilePath, char* inputFilePath, int key, bool encrypt);
private:
    CaesarCipher dll = CaesarCipher();
    char* encodeLine(char* line, int key);
    char* decodeLine(char* line, int key);
    int lineToFile(char* line, char* filePath);
};


#endif //PARADIGMS_PA_4_TEXTPROCESSOR_H
