//
// Created by kvita on 26.06.2024.
//
#pragma once
#ifndef PARADIGMS_PA_4_TEXTPROCESSOR_H
#define PARADIGMS_PA_4_TEXTPROCESSOR_H


class TextProcessor {
public:
    int encryptText(char* outputFilePath, char* inputFilePath, int key);
    int decryptText(char* outputFilePath, char* inputFilePath, int key);
};


#endif //PARADIGMS_PA_4_TEXTPROCESSOR_H
