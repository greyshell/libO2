# stack_singly_linkedlist_int API

APIs                             | Time | Space | Usage
---------------------------------|------|-------|-----------------------------------------------------------------------------------
`void initialize_stack(stack *)` | O(1) | O(1)  | Set the stack top to `NULL`
`bool is_empty_stack(stack *)`   | O(1) | O(1)  | Return `true` when the stack is empty else return `false`
`size_t get_stack_size(stack *)` | O(1) | O(1)  | Return the stack size
`bool push(stack *, int)`        | O(1) | O(1)  | Add an element into the stack. On success, it returns `true` else returns `false`
`bool pop(stack *, int *)`       | O(1) | O(1)  | Remove an element from the top. On success, it returns `true` else returns `false`
`bool peek(stack *, int *)`      | O(1) | O(1)  | Display the stack top. On success, it returns `true` else returns `false`
`void display_stack(stack *)`    | O(n) | O(1)  | Display all stack elements
`void delete_stack(stack *)`     | O(n) | O(1)  | Delete the stack and free up the memory

