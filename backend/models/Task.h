#pragma once

#include <string>

enum class TaskStatus { Pending, Completed };

struct Task {
  int id;
  std::string title;
  std::string description;
  int priority;
  TaskStatus status;

  Task();
  Task(int id, std::string title, std::string description, int priority,
       TaskStatus status = TaskStatus::Pending);

  bool isCompleted() const;
};
