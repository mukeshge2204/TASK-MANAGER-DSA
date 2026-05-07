#pragma once

#include <string>

#include "services/TaskService.h"

struct Request {
  std::string method;
  std::string path;
  std::string body;
};

struct Response {
  int status;
  std::string contentType;
  std::string body;
};

class Server {
 public:
  explicit Server(TaskService& taskService);

  void start(int port);
  void stop();

  Response handleRequest(const Request& request);

 private:
  Response respondJson(int status, const std::string& message,
                       const std::string& dataJson) const;
  Response respondNotImplemented(const std::string& message) const;
  Response respondNotFound() const;

  TaskService& taskService_;
  bool running_;
};
