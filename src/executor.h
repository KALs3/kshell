#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <string>
#include <vector>

// Execute external command via fork/exec
void execute_external(const std::vector<std::string>& tokens);

#endif