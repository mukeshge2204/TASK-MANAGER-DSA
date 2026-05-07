# DSA Explanation (Phase 1 Design)

## Array
- Used as baseline in-memory task container.
- Demonstrates static vs dynamic array tradeoff.
- Dynamic resize strategy supports scalable inserts.

## Singly Linked List
- Used for lightweight dynamic task stream operations.
- Efficient insertion at beginning/end with simple pointers.

## Doubly Linked List
- Used for task history navigation with previous/next moves.
- Enables richer timeline-like browsing.

## Circular Linked List
- Used for recurring tasks and reminder cycles.
- Tail links back to head to model repetition.

## Stack
- Used for undo operations (LIFO): newest action rolled back first.
- Supports push/pop/peek for action history.

## Queue
- Used for pending task scheduling (FIFO).
- Earlier queued tasks get processed first.

## AVL Tree
- Used for priority index and fast ordered retrieval.
- Keeps height balanced with rotations:
  - LL: right rotation
  - RR: left rotation
  - LR: left rotate child, then right rotate root
  - RL: right rotate child, then left rotate root
- Guarantees O(log n) search/insert/delete.

## Morris Traversal
- Used for in-order reporting with O(1) auxiliary space.
- Temporary threads to predecessor avoid recursion/stack.
- Thread is created, node visited, thread removed, traversal continues.
