
# Binary Search Tree (BST)

## Overview

Binary Search Tree (BST) is a custom, template-based binary search tree implementation developed from scratch in C++. The project supports dynamic insertion, searching, deletion, tree traversal, and memory management through recursive algorithms.

The implementation uses dynamically allocated tree nodes, each containing a data value, pointers to its left and right children, and a stored height. It also provides utilities for calculating balance factors, constructing trees from sorted arrays, copying trees, and merging tree contents.

---

## Key Features

- **Template-Based Implementation:** Supports different data types through C++ templates.
- **Dynamic Tree Operations:** Supports insertion, searching, and deletion while maintaining binary search tree ordering.
- **Recursive Traversals:** Implements in-order, pre-order, and post-order traversals.
- **Height and Balance Tracking:** Maintains node heights and calculates balance factors for structural analysis.
- **Deep Copy Support:** Implements copy construction and assignment for independent tree copies.
- **Memory Management:** Recursively deallocates dynamically allocated nodes.
- **Sorted Array Construction:** Builds a height-balanced initial tree from sorted input.
- **Tree Visualization:** Provides formatted tree output with node heights and balance factors.

---

## Supported Operations

| Operation | Function | Description |
|-----------|----------|-------------|
| Insert | `insert()` | Inserts an element into the tree |
| Search | `contains()` | Checks whether an element exists |
| Delete | `erase()` | Removes a matching element |
| Clear | `clear_all()` | Deletes all nodes |
| Check Empty | `empty()` | Determines whether the tree is empty |
| In-Order Traversal | `in_order()` | Visits left subtree, root, then right subtree |
| Pre-Order Traversal | `pre_order()` | Visits root, left subtree, then right subtree |
| Post-Order Traversal | `post_order()` | Visits left subtree, right subtree, then root |
| Deep Copy | Copy constructor / `operator=` | Creates an independent copy |
| Combine Trees | `operator+=` | Inserts elements from another tree |
| Tree Construction | Sorted-array constructor | Constructs a tree from sorted input |

---
## Testing

Developed a C++ testing suite using **GoogleTest** to evaluate Binary Search Tree operations and structural correctness.

The test suite includes:

- **Insertion and Searching:** Tests element insertion, duplicate values, and searches for existing and nonexistent elements.
- **Deletion and Memory Management:** Exercises node deletion, tree clearing, and removal of all elements.
- **Tree Traversals:** Validates in-order, pre-order, and post-order traversals against expected results.
- **Tree Copying and Merging:** Tests deep copying and combining independent trees.
- **Sorted-Array Construction:** Tests tree initialization from sorted input.
- **Structural Inspection:** Displays tree structures, node heights, and balance factors for debugging.
--- 

## Technical Implementation

### 1. <ins>Binary Search Tree Structure</ins>

The `BST<T>` class manages the tree through a root pointer and provides an interface for its operations.

Each node is represented by a templated `tree_node<T>` structure containing:

- A stored value.
- Pointers to the left and right child nodes.
- A height value used for structural analysis.

The tree follows the binary search tree property: values smaller than a node are inserted into its left subtree, while values greater than or equal to it are inserted into its right subtree.

### 2. <ins>Recursive Tree Operations</ins>

Insertion, searching, and deletion are implemented using recursive helper functions.

- **Insertion:** Recursively searches for an available child position and allocates a new node.
- **Searching:** Compares the target against the current node and recursively searches the appropriate subtree.
- **Deletion:** Handles node removal, including replacement using the maximum value from the left subtree.

These operations maintain the tree's ordering property without requiring sequential traversal of every node in typical cases.

### 3. <ins>Tree Traversal Algorithms</ins>

The implementation supports three recursive traversal methods:

- **In-order:** Left → Root → Right
- **Pre-order:** Root → Left → Right
- **Post-order:** Left → Right → Root

For a BST containing the values `10`, `5`, `15`, `3`, and `7`, the traversal results are:

```text
In-order:    3, 5, 7, 10, 15
Pre-order:   10, 5, 3, 7, 15
Post-order:  3, 7, 5, 15, 10
```

In-order traversal retrieves the tree's values in sorted order.

### 4. <ins>Height and Balance Factor Tracking</ins>

Each node maintains its height based on the heights of its children.

The balance factor is calculated as:

```text
Balance Factor = Height(Left Subtree) - Height(Right Subtree)
```

The implementation treats null children as having height `-1` and leaf nodes as having height `0`.

Node heights are updated during insertion, and balance factors can be displayed through the debugging visualization.

Although the implementation tracks balance information, it does not perform automatic tree rotations or rebalancing.

### 5. <ins>Dynamic Memory Management</ins>

The implementation manages dynamically allocated nodes using recursive memory operations.

- The destructor releases allocated nodes.
- `clear_all()` recursively deletes the entire tree.
- The copy constructor creates a deep copy of an existing tree.
- The assignment operator handles self-assignment and copies the source tree.

These features demonstrate pointer ownership, object lifecycle management, and the Rule of Three in C++.

---

## Core Components

| File | Responsibility |
|------|----------------|
| `bst.h` | Defines the templated BST class and its public operations |
| `tree_node.h` | Defines tree nodes, child pointers, height calculations, and balance factors |
| `bst_functions.h` | Implements recursive insertion, searching, deletion, copying, traversal, and tree utilities |

---

## Time Complexity

The performance of BST operations depends on the height of the tree.

| Operation | Average Case* | Worst Case |
|-----------|---------------|------------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Traversal | O(n) | O(n) |
| Deep Copy | O(n) | O(n) |

*The logarithmic average-case estimates assume a reasonably distributed tree structure.*

Because the tree does not automatically rebalance itself, inserting values in sorted order can produce a skewed tree, increasing operation time to O(n).

---

## Project Information

**Language:** C++  
**Data Structure:** Binary Search Tree  
**Implementation:** Template-based, pointer-linked nodes  
**Core Concepts:** Recursion, dynamic memory management, tree traversal, object-oriented programming, and algorithm analysis

**Developer:** Queency Tan
