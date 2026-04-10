#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

enum STATES {
    NORMAL,
    IN_QUOTE,
    ESCAPE
};

// function prototype
std::vector<std::string> tokenize(const std::string& input);

#endif

