#include "server.h"

#include <iostream>

#include "utils/Helpers.h"

Server::Server(TaskService& taskService)
    : taskService_(taskService), running_(false) {}

void Server::start(int port) {
  running_ = true;
  std::cout << "Server starting on port " << port << std::endl;
}

void Server::stop() {
  running_ = false;
  std::cout << "Server stopped" << std::endl;
}

Response Server::handleRequest(const Request& request) {
  if (request.method == "GET") {
    if (request.path == "/tasks") {
      return respondJson(200, "Fetched tasks",
                         Helpers::tasksToJson(taskService_.getAllTasks()));
    }
    if (request.path == "/tasks/completed") {
      return respondJson(
          200, "Fetched completed tasks",
          Helpers::tasksToJson(taskService_.getCompletedTasks()));
    }
    if (request.path == "/tasks/pending") {
      return respondJson(
          200, "Fetched pending tasks",
          Helpers::tasksToJson(taskService_.getPendingTasks()));
    }
    if (request.path == "/tasks/priority") {
      return respondJson(
          200, "Fetched priority tasks",
          Helpers::tasksToJson(taskService_.getTasksByPriority()));
    }
  }

  if (request.method == "POST" && request.path == "/tasks/add") {
    return respondNotImplemented("Add task endpoint pending Phase 3/4");
  }
  if (request.method == "POST" && request.path == "/tasks/undo") {
    return respondNotImplemented("Undo endpoint pending Phase 3/4");
  }
  if (request.method == "PUT" && request.path == "/tasks/update") {
    return respondNotImplemented("Update endpoint pending Phase 3/4");
  }
  if (request.method == "DELETE" && request.path == "/tasks/delete") {
    return respondNotImplemented("Delete endpoint pending Phase 3/4");
  }

  return respondNotFound();
}

Response Server::respondJson(int status, const std::string& message,
                             const std::string& dataJson) const {
  std::string body = "{\"success\":" +
                     std::string(status >= 200 && status < 300 ? "true"
                                                              : "false") +
                     ",\"message\":\"" + Helpers::escapeJson(message) +
                     "\",\"data\":" + dataJson + "}";
  return {status, "application/json", body};
}

Response Server::respondNotImplemented(const std::string& message) const {
  return respondJson(501, message, "[]");
}

Response Server::respondNotFound() const {
  return respondJson(404, "Endpoint not found", "[]");
}
