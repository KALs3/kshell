#include "executor.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

void execute_external(const std::vector<std::string>& tokens) {
    // Convert to C-style argv
    std::vector<const char*> args;
    for (const auto& token : tokens) {
        args.push_back(token.c_str());
    }
    args.push_back(nullptr);
    
    pid_t pid = fork();
    
    if (pid == -1) {
        perror("fork");
        return;
    }
    
    if (pid == 0) {
        // Child process
        execvp(args[0], const_cast<char* const*>(args.data()));
        perror("execvp");
        exit(1);
    }
    
    // Parent process
    int status;
    waitpid(pid, &status, 0);
}