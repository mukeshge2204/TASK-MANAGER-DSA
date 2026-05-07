#include "Helpers.h"

#include <sstream>

namespace Helpers {
std::string statusToString(TaskStatus status) {
  switch (status) {
    case TaskStatus::Pending:
      return "pending";
    case TaskStatus::Completed:
      return "completed";
  }
  return "pending";
}

std::string escapeJson(const std::string& input) {
  std::ostringstream escaped;
  for (char ch : input) {
    switch (ch) {
      case '\\':
        escaped << "\\\\";
        break;
      case '"':
        escaped << "\\\"";
        break;
      case '\n':
        escaped << "\\n";
        break;
      case '\r':
        escaped << "\\r";
        break;
      case '\t':
        escaped << "\\t";
        break;
      default:
        escaped << ch;
        break;
    }
  }
  return escaped.str();
}

std::string taskToJson(const Task& task) {
  std::ostringstream json;
  json << "{";
  json << "\"id\":" << task.id << ",";
  json << "\"title\":\"" << escapeJson(task.title) << "\",";
  json << "\"description\":\"" << escapeJson(task.description) << "\",";
  json << "\"priority\":" << task.priority << ",";
  json << "\"status\":\"" << statusToString(task.status) << "\"";
  json << "}";
  return json.str();
}

std::string tasksToJson(const std::vector<Task>& tasks) {
  std::ostringstream json;
  json << "[";
  for (size_t i = 0; i < tasks.size(); ++i) {
    if (i > 0) {
      json << ",";
    }
    json << taskToJson(tasks[i]);
  }
  json << "]";
  return json.str();
}
}  // namespace Helpers
