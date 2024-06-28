#ifndef PARADIGMS_PA_4_TEXTEDITOR_H
#define PARADIGMS_PA_4_TEXTEDITOR_H
#include "TextProcessor.h"

class TextEditor{
public:
    void run();

private:
    char*  getTextInput();
    TextProcessor textProcessor = TextProcessor();
    int processFile(bool encode);

};


#endif //PARADIGMS_PA_4_TEXTEDITOR_H
