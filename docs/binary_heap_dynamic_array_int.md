# binary_heap_dynamic_array_int

## Key Features

- Supported data type: `int`.
- Backed by a dynamic array.

## API Details

Sl No | APIs                                           | Time        | Space | Usage
------|------------------------------------------------|-------------|-------|------------------------------------------------------------------------------------------------------------------------------------
1     | `bool initialize_heap(heap *, size_t, bool)`   | O(1)        | O(1)  | initialize the heap with an array size, for max heap set bool = true
2     | `bool is_empty_heap(heap *)`                   | O(1)        | O(1)  | Return `true` when the heap is empty else return `false`
3     | `bool get_heap_size(heap *, size_t *)`         | O(1)        | O(1)  | Get the heap size. If the heap is empty then it returns `false` else returns `true`
4     | `bool push_heap(heap *, int)`                  | O(log(n))   | O(1)  | Add an element into the heap. On success, it returns `true` else returns `false`
5     | `bool pop_heap(heap *, int *)`                 | O(log(n))   | O(1)  | Remove min / max element from the heap. On success, it returns `true` else returns `false`
6     | `bool peek_heap(heap *, int *)`                | O(1)        | O(1)  | Peek the min / max element from the heap. On success, it returns `true` else returns `false`
7     | `bool build_heap(heap *, bool, int *, size_t)` | O(n)        | O(1)  | Build a heap from an array. On success, it returns `true` else returns `false`. The process rearranges the array elements.
8     | `void display_heap(heap *)`                    | O(n)        | O(1)  | Display all heap elements
9     | `bool delete_heap(heap *)`                     | O(1)        | O(1)  | Delete the heap and free up the memory of the dynamic array
10    | `void heap_sort(int *, size_t, bool)`          | O(n*log(n)) | O(1)  | Sort the array elements, for asc set bool = true