#include "builtins.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <climits>

bool handle_builtin(const std::vector<std::string>& tokens) {
    if (tokens.empty()) {
        return true;  // Nothing to do
    }
    
    // exit
    if (tokens[0] == "exit") {
        return false;  // Signal to main loop to break
        // We'll handle the actual break in main
    }
    
    // cd
    if (tokens[0] == "cd") {
        if (tokens.size() < 2) {
            const char* home = getenv("HOME");
            if (home && chdir(home) != 0) {
                perror("cd");
            }
        } else {
            if (chdir(tokens[1].c_str()) != 0) {
                perror("cd");
            }
        }
        return true;  // Handled
    }
    
    // pwd
    if (tokens[0] == "pwd") {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != nullptr) {
            std::cout << cwd << "\n";
        } else {
            perror("pwd");
        }
        return true;  // Handled
    }
    
    return false;  // Not a built-in
}