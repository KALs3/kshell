#ifndef BUILTINS_H
#define BUILTINS_H

#include <string>
#include <vector>

// Returns true if command is a built-in and was handled
// Returns false if command should go through fork/exec
bool handle_builtin(const std::vector<std::string>& tokens);

#endif