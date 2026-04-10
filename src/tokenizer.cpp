#include "tokenizer.h"

std::vector<std::string> tokenize(const std::string& input) {
    STATES currentState = NORMAL;
    STATES previousState = NORMAL;
    std::string tempString;
    std::vector<std::string> tempArray;

    for (char ch : input) {
        switch (currentState) {
            case NORMAL:
             if (ch == ' ') {
                    if (!tempString.empty()) {
                        tempArray.push_back(tempString);
                        tempString.clear();
                    }
                    break;
                } else if (ch == '"') {
                    previousState = NORMAL;
                    currentState = IN_QUOTE;
                    break;
                } else if (ch == '\\') {
                    previousState = NORMAL;
                    currentState = ESCAPE;
                    break;
                } else {
                    tempString.push_back(ch);
                }
                break;

            case IN_QUOTE:
                if (ch == '"') {
                    currentState = NORMAL;
                } else if (ch == '\\') {
                    previousState = IN_QUOTE;
                    currentState = ESCAPE;
                } else {
                    tempString.push_back(ch);
                }
                break;

            case ESCAPE:
                tempString.push_back(ch);
                currentState = previousState;
                break;
        }
    }

    if (!tempString.empty()) {
        tempArray.push_back(tempString);
    }

    return tempArray;
}