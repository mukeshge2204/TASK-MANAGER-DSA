#include "server.h"

#include "services/TaskService.h"

int main() {
  TaskService taskService;
  Server server(taskService);
  server.start(8080);
  return 0;
}
