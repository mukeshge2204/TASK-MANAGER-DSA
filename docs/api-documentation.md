# API Documentation (Design-Phase Contract)

## Base Concept
REST-style HTTP API consumed by frontend `fetch()`.

## Endpoints

### GET
- `/tasks` — all tasks
- `/tasks/completed` — completed tasks
- `/tasks/pending` — pending tasks
- `/tasks/priority` — priority-ordered tasks (AVL-backed)

### POST
- `/tasks/add` — add a task
- `/tasks/undo` — undo latest reversible action (Stack-backed)

### PUT
- `/tasks/update` — update task details/status

### DELETE
- `/tasks/delete` — delete a task

## Response Shape (planned)

```json
{
  "success": true,
  "message": "Operation status",
  "data": []
}
```
