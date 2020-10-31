# queue_singly_linkedlist_int

## Key Features

- Singly linked list based `queue` implementation.
- Supported data type: `int`.

## API Details

Sl No | APIs                                 | Time | Space | Usage
------|--------------------------------------|------|-------|---------------------------------------------------------------------------------
1     | `void initialize_queue(queue *)`     | O(1) | O(1)  | Set front and rear to `NULL`
2     | `bool is_empty_queue(queue *)`       | O(1) | O(1)  | Return `true` when the queue is empty else return `false`
3     | `size_t get_queue_size(queue *)`     | O(1) | O(1)  | Return the queue size
4     | `bool enque(queue *, int)`           | O(1) | O(1)  | Add an element at rear. On success, it returns `true` else returns `false`
5     | `bool dequeue(queue *, int *)`       | O(1) | O(1)  | Remove an element from front. On success, it returns `true` else returns `false`
6     | `bool peek_at_front(queue *, int *)` | O(1) | O(1)  | Display the element at front. On success, it returns `true` else returns `false`
7     | `bool peek_at_rear(queue *, int *)`  | O(1) | O(1)  | Display the element at rear. On success, it returns `true` else returns `false`
8     | `void display_queue(queue *)`        | O(n) | O(1)  | Display all queue elements
9     | `void delete_queue(queue *)`         | O(n) | O(1)  | Delete the queue and free up the memory