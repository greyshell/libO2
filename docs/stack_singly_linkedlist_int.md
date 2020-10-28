# stack_singly_linkedlist_int API

APIs                           | Usage
-------------------------------|-----------------------------------------------------------------------------------
void initialize_stack(stack *) | Set the stack top to `NULL`
bool is_empty_stack(stack *)   | Return `true` when the stack is empty else return `false`
size_t get_stack_size(stack *) | Return the stack size
bool push(stack *, int)        | Add an element into the stack. On success, it returns `true` else returns `false`
bool pop(stack *, int *)       | Remove an element from the top. On success, it returns `true` else returns `false`
bool peek(stack *, int *)      | Display the stack top. On success, it returns `true` else returns `false`
void display_stack(stack *)    | Display all stack elements
void delete_stack(stack *)     | Delete the stack and free up the memory

