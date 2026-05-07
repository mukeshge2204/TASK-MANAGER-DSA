# Phase 1: Architecture & Design (No Implementation Code)

## 1) Project Architecture

The system follows a layered design:

- **Presentation layer (frontend)**: HTML/CSS/JS views and fetch-based API calls.
- **Application layer (backend/services)**: task workflows and business rules.
- **DSA layer (backend/data_structures)**: manual implementations of all required structures.
- **Model layer (backend/models)**: core entity definitions (Task).
- **Storage layer (backend/storage + data/tasks.json)**: file persistence.
- **Utility layer (backend/utils)**: helpers and reusable low-level operations.

## 2) Industry-level Folder Structure

```text
task-manager/
├── backend/
│   ├── main.cpp
│   ├── server.cpp
│   ├── server.h
│   ├── models/
│   │   ├── Task.h
│   │   └── Task.cpp
│   ├── data_structures/
│   │   ├── Array.h/.cpp
│   │   ├── SinglyLinkedList.h/.cpp
│   │   ├── DoublyLinkedList.h/.cpp
│   │   ├── CircularLinkedList.h/.cpp
│   │   ├── Stack.h/.cpp
│   │   ├── Queue.h/.cpp
│   │   ├── AVLTree.h/.cpp
│   │   └── MorrisTraversal.h/.cpp
│   ├── services/
│   │   ├── TaskService.h
│   │   └── TaskService.cpp
│   ├── storage/
│   │   ├── FileHandler.h
│   │   └── FileHandler.cpp
│   └── utils/
│       ├── Helpers.h
│       └── Helpers.cpp
├── frontend/
│   ├── index.html
│   ├── style.css
│   ├── app.js
│   ├── components/
│   │   ├── taskCard.js
│   │   ├── taskForm.js
│   │   └── dashboard.js
│   └── assets/
├── data/
│   └── tasks.json
├── docs/
│   ├── architecture.md
│   ├── api-documentation.md
│   ├── dsa-explanation.md
│   └── setup-guide.md
└── README.md
```

## 3) Data Flow Diagram

```text
[User]
  -> [Frontend UI]
  -> fetch() HTTP request
  -> [C++ HTTP Server]
  -> [TaskService]
  -> [DSA Modules: Array/Lists/Stack/Queue/AVL/Morris]
  -> [FileHandler]
  -> [tasks.json]

Read Flow:
[tasks.json] -> [FileHandler] -> [TaskService] -> [Server JSON response] -> [Frontend render]
```

## 4) High-level System Design

- **Server** exposes REST-style endpoints.
- **TaskService** orchestrates all operations (add/update/delete/undo/search/sort/report).
- **Data structures** are used as specialized engines for specific workflows.
- **FileHandler** performs persistence load/save.
- **Frontend** stays minimal, clean, and API-driven.

## 5) Feature ↔ Data Structure Mapping

| Feature | Primary Data Structure | Why |
|---|---|---|
| Store all tasks | Dynamic Array | Fast indexing and compact storage |
| Fast dynamic inserts/traversal | Singly Linked List | Low-overhead node chaining |
| Task history navigation | Doubly Linked List | Previous/next bidirectional movement |
| Recurring tasks rotation | Circular Linked List | Natural cycle behavior |
| Undo operations | Stack | LIFO rollback |
| Pending scheduling | Queue | FIFO processing order |
| Priority dashboard/search | AVL Tree | Balanced BST, O(log n) ops |
| Report traversal | Morris Traversal | O(1) extra space in-order traversal |

## 6) Backend ↔ Frontend Communication Flow

1. Frontend action (e.g., submit Add Task form).
2. `fetch('/tasks/add', { method: 'POST', ... })`.
3. Server parses request and delegates to `TaskService`.
4. `TaskService` updates DSA modules + persists via `FileHandler`.
5. Server responds JSON status/data.
6. Frontend updates UI components and statistics.

## 7) Time Complexity Table

| Structure / Operation | Average Time |
|---|---|
| Array insert (end, amortized) | O(1) |
| Array insert/delete (middle) | O(n) |
| Array search | O(n) |
| Singly list insert/delete at head | O(1) |
| Singly list search/traverse | O(n) |
| Doubly list insert/delete (known node) | O(1) |
| Doubly list traversal/search | O(n) |
| Circular list cycle traversal | O(n) |
| Stack push/pop/peek | O(1) |
| Queue enqueue/dequeue/front/rear | O(1) |
| AVL insert/delete/search | O(log n) |
| Morris traversal | O(n) |

## 8) Memory Complexity Table

| Structure | Memory |
|---|---|
| Dynamic Array | O(n) |
| Singly Linked List | O(n) nodes + single pointer overhead |
| Doubly Linked List | O(n) nodes + two-pointer overhead |
| Circular Linked List | O(n) |
| Stack | O(n) |
| Queue | O(n) |
| AVL Tree | O(n) |
| Morris Traversal | O(1) extra auxiliary space |

## 9) Folder Responsibility Summary

- `backend/models`: domain entities.
- `backend/data_structures`: manual DS implementations.
- `backend/services`: orchestration/business logic.
- `backend/storage`: serialization and persistence.
- `frontend/components`: modular rendering logic.
- `docs`: architecture/API/DSA/setup references.
