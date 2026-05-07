#include "TaskService.h"

#include <algorithm>

TaskService::TaskService() : nextId_(1) {}

const std::vector<Task>& TaskService::getAllTasks() const { return tasks_; }

std::vector<Task> TaskService::getCompletedTasks() const {
  std::vector<Task> results;
  for (const auto& task : tasks_) {
    if (task.isCompleted()) {
      results.push_back(task);
    }
  }
  return results;
}

std::vector<Task> TaskService::getPendingTasks() const {
  std::vector<Task> results;
  for (const auto& task : tasks_) {
    if (!task.isCompleted()) {
      results.push_back(task);
    }
  }
  return results;
}

std::vector<Task> TaskService::getTasksByPriority() const {
  std::vector<Task> results = tasks_;
  std::sort(results.begin(), results.end(),
            [](const Task& left, const Task& right) {
              if (left.priority == right.priority) {
                return left.id < right.id;
              }
              return left.priority > right.priority;
            });
  return results;
}

std::optional<Task> TaskService::getTaskById(int id) const {
  const Task* task = findTask(id);
  if (!task) {
    return std::nullopt;
  }
  return *task;
}

Task TaskService::addTask(const std::string& title,
                          const std::string& description, int priority) {
  Task task(nextId_++, title, description, priority, TaskStatus::Pending);
  tasks_.push_back(task);
  return task;
}

bool TaskService::updateTask(int id, const std::string& title,
                             const std::string& description, int priority,
                             TaskStatus status) {
  Task* task = findTask(id);
  if (!task) {
    return false;
  }
  task->title = title;
  task->description = description;
  task->priority = priority;
  task->status = status;
  return true;
}

bool TaskService::deleteTask(int id) {
  auto prevSize = tasks_.size();
  tasks_.erase(
      std::remove_if(tasks_.begin(), tasks_.end(),
                     [id](const Task& task) { return task.id == id; }),
      tasks_.end());
  return tasks_.size() != prevSize;
}

bool TaskService::markCompleted(int id) {
  Task* task = findTask(id);
  if (!task) {
    return false;
  }
  task->status = TaskStatus::Completed;
  return true;
}

Task* TaskService::findTask(int id) {
  for (auto& task : tasks_) {
    if (task.id == id) {
      return &task;
    }
  }
  return nullptr;
}

const Task* TaskService::findTask(int id) const {
  for (const auto& task : tasks_) {
    if (task.id == id) {
      return &task;
    }
  }
  return nullptr;
}
