#include <iostream>
#include <string>
#include <vector>
#include "tokenizer.h"
#include "builtins.h"
#include "executor.h"
#include <unistd.h>
#include <climits>

void print_prompt() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::cout << "KShell:" << cwd << "> ";
    } else {
        std::cout << "KShell> ";
    }
}

int main() {
    std::string input;
    
    while (true) {
        print_prompt();
        
        if (!std::getline(std::cin, input)) {
            std::cout << "\n";
            break;
        }
        
        std::vector<std::string> tokens = tokenize(input);
        
        if (tokens.empty()) {
            continue;
        }
        
        // Handle exit specially (needs to break the main loop)
        if (tokens[0] == "exit") {
            break;
        }
        
        // Try built-ins first
        if (handle_builtin(tokens)) {
            continue;  // Built-in handled it
        }
        
        // Not a built-in, execute externally
        execute_external(tokens);
    }
    
    std::cout << "Goodbye!\n";
    return 0;
}