#include "Task.h"

#include <utility>

Task::Task() : id(0), priority(0), status(TaskStatus::Pending) {}

Task::Task(int id, std::string title, std::string description, int priority,
           TaskStatus status)
    : id(id),
      title(std::move(title)),
      description(std::move(description)),
      priority(priority),
      status(status) {}

bool Task::isCompleted() const { return status == TaskStatus::Completed; }
