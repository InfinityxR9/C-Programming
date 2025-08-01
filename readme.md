# C Programming Repository

This repository contains a collection of C programs for learning and experimenting with fundamental programming concepts, as well as a comprehensive set of Data Structures and Algorithms (DSA) implementations.

---

## 📁 Folder Structure

- **C-Programming (root)**
  - General C programs demonstrating basic syntax, input/output, and simple logic.
  - Example files:
    - `sorting.c` – Measures and reports the performance of a simple sorting algorithm on large arrays.
    - `readme.md` – (You are here!)
    - `.gitignore` – Ignores executables and logs.

- **DSA/**
  - Contains a wide range of data structures and algorithms implemented in C.
  - Each `.c` file is self-contained and demonstrates a specific concept or algorithm.
  - `todo.txt` – Contains notes and future problem ideas (e.g., Maximum Subarray Problem).

---

## 📚 Key DSA Implementations (Detailed)

### Arrays & ADT
- [`ADT_Arrays.c`](DSA/ADT_Arrays.c): Abstract Data Type for dynamic arrays with insert, append, and delete operations.

### Sorting Algorithms
- [`Bubble_Sort.c`](DSA/Bubble_Sort.c): Standard and adaptive bubble sort.
- [`Insertion_sort.c`](DSA/Insertion_sort.c): Insertion sort implementation.
- [`Selection_sort.c`](DSA/Selection_sort.c): Selection sort implementation.
- [`Quick_sort.c`](DSA/Quick_sort.c): Quick sort algorithm with partition logic.
- [`Count_sort.c`](DSA/Count_sort.c): Counting sort for non-negative integers.
- [`custom_Sort.c`](DSA/custom_Sort.c): Sorts using a BST (tree sort).
- [`insertion_sort_using_binary_search.c`](DSA/insertion_sort_using_binary_search.c): Insertion sort optimized with binary search for position.
- Performance tracking for sorting:
  - [`Sort_Tracker_Bubble_Sort.c`](DSA/Sort_Tracker_Bubble_Sort.c)
  - [`Sort_Tracker_Insertion_Sort.c`](DSA/Sort_Tracker_Insertion_Sort.c)
  - [`Sort_Tracker_Selection_Sort.c`](DSA/Sort_Tracker_Selection_Sort.c)

### Searching Algorithms
- [`Linear_and_Binary_Search.c`](DSA/Linear_and_Binary_Search.c): Linear and binary search on arrays.
- [`search_BST.c`](DSA/search_BST.c): Recursive and iterative search in BST.

### Stacks
- [`Stack_Arrays.c`](DSA/Stack_Arrays.c): Stack implementation using arrays.
- [`Stack_Linked_List.c`](DSA/Stack_Linked_List.c): Stack implementation using linked lists.
- [`Parenthesis_matching_stack.c`](DSA/Parenthesis_matching_stack.c): Parenthesis matching using stack.
- [`infix_to_postfix_stack.c`](DSA/infix_to_postfix_stack.c): Infix to postfix expression conversion.

### Queues
- [`Queue_Arrays.c`](DSA/Queue_Arrays.c): Linear queue using arrays.
- [`Circular_Queue_Arrays.c`](DSA/Circular_Queue_Arrays.c): Circular queue using arrays.
- [`Double_Ended_Queue.c`](DSA/Double_Ended_Queue.c): Double-ended queue (deque) using arrays.
- [`Queue_Linked_Lists.c`](DSA/Queue_Linked_Lists.c): Queue implementation using linked lists.

### Linked Lists
- [`Linked_Lists.c`](DSA/Linked_Lists.c): Singly linked list with insert, delete, and search operations.

### Trees
- [`Binary_trees.c`](DSA/Binary_trees.c): Binary tree creation, traversal (in-order, pre-order, post-order), and node linking.
- [`Check_BST.c`](DSA/Check_BST.c): Checks if a binary tree is a valid Binary Search Tree (BST) using in-order traversal.
- [`insert_BST.c`](DSA/insert_BST.c): Iterative insertion of nodes into a BST, maintaining BST properties.
- [`delete_BST.c`](DSA/delete_BST.c): Deletion of nodes from a BST, handling all cases.
- [`Invert_Binary_Tree.c`](DSA/Invert_Binary_Tree.c): Recursive and iterative inversion (mirroring) of a binary tree.
- [`AVL_Trees_Rotations.c`](DSA/AVL_Trees_Rotations.c): AVL tree insertion and balancing with rotations.
- [`Level_order_traversal.c`](DSA/Level_order_traversal.c): Iterative level-order traversal using a queue.

---

## 🏁 Getting Started

To compile and run any C file:

```sh
gcc filename.c -o filename.exe
./filename.exe
```

For DSA files, navigate to the `DSA` folder and compile as above.

---

## 📝 Notes

- `todo.txt` contains notes and future problem ideas (e.g., Maximum Subarray Problem).
- All code is written for educational purposes and may include print statements for demonstration.

---

## 👤 Author

- **Aryan Sisodiya**
- [GitHub: InfinityxR9](https://github.com/InfinityxR9)

## Happy Coding!