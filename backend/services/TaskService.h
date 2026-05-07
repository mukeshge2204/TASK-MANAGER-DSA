#pragma once

#include <optional>
#include <string>
#include <vector>

#include "../models/Task.h"

class TaskService {
 public:
  TaskService();

  const std::vector<Task>& getAllTasks() const;
  std::vector<Task> getCompletedTasks() const;
  std::vector<Task> getPendingTasks() const;
  std::optional<Task> getTaskById(int id) const;

  Task addTask(const std::string& title, const std::string& description,
               int priority);
  bool updateTask(int id, const std::string& title,
                  const std::string& description, int priority,
                  TaskStatus status);
  bool deleteTask(int id);
  bool markCompleted(int id);

 private:
  Task* findTask(int id);
  const Task* findTask(int id) const;

  int nextId_;
  std::vector<Task> tasks_;
};
