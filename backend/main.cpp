#include "server.h"

#include <iostream>
#include <string>

#include "services/TaskService.h"

int main() {
  TaskService taskService;
  Server server(taskService);
  server.start(8080);
  std::cout << "Press Enter to stop the server." << std::endl;
  std::string input;
  std::getline(std::cin, input);
  server.stop();
  return 0;
}
