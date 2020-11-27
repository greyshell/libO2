# sort_int

## Key Features

- Different sorting techniques.
- Supported data type: `int`.

## API Details

Sl No | APIs                                       | Average / Expected Time | Worst Time | Best Time | Space                                  | In-place | Stable
------|--------------------------------------------|-------------------------|------------|-----------|----------------------------------------|----------|-------
1     | `void bubble_sort(int *, size_t)`          | O(n^2)                  | O(n^2)     | O(n)      | O(1)                                   | yes      | yes
2     | `void cocktail_sort(int *, size_t)`        | O(n^2)                  | O(n^2)     | O(n)      | O(1)                                   | yes      | yes
3     | `void counting_sort(int *, int *, size_t)` | O(n)                    | O(n)       | O(n)      | O(n + k), where k is the integer range | no       | yes