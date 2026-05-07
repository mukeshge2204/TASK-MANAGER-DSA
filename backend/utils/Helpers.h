#pragma once

#include <string>
#include <vector>

#include "../models/Task.h"

namespace Helpers {
std::string statusToString(TaskStatus status);
std::string escapeJson(const std::string& input);
std::string taskToJson(const Task& task);
std::string tasksToJson(const std::vector<Task>& tasks);
}  // namespace Helpers
