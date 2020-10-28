# stack_singly_linkedlist_int API


Sl No | APIs                             | Time | Space | Usage
------|----------------------------------|------|-------|-----------------------------------------------------------------------------------
1     | `void initialize_stack(stack *)` | O(1) | O(1)  | Set the stack top to `NULL`
2     | `bool is_empty_stack(stack *)`   | O(1) | O(1)  | Return `true` when the stack is empty else return `false`
3     | `size_t get_stack_size(stack *)` | O(1) | O(1)  | Return the stack size
4     | `bool push(stack *, int)`        | O(1) | O(1)  | Add an element into the stack. On success, it returns `true` else returns `false`
5     | `bool pop(stack *, int *)`       | O(1) | O(1)  | Remove an element from the top. On success, it returns `true` else returns `false`
6     | `bool peek(stack *, int *)`      | O(1) | O(1)  | Display the stack top. On success, it returns `true` else returns `false`
7     | `void display_stack(stack *)`    | O(n) | O(1)  | Display all stack elements
8     | `void delete_stack(stack *)`     | O(n) | O(1)  | Delete the stack and free up the memory
