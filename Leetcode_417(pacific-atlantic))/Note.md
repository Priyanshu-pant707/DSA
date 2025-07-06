# 🌊 Pacific Atlantic Water Flow – BFS Approach

## 🧾 Problem Statement

Given an `m x n` matrix of non-negative integers `heights`, representing the height of each cell, water can flow:

- from a cell to another **adjacent cell** (up, down, left, or right),
- only if the **next cell’s height is less than or equal to** the current cell’s height (i.e., water flows downhill or stays at the same level).

Return a list of all grid coordinates where water can flow to **both the Pacific and Atlantic oceans**.

- The **Pacific Ocean** touches the **top and left** edges.
- The **Atlantic Ocean** touches the **bottom and right** edges.

---

## 🚀 Approach (BFS from Ocean Edges)

### 🔹 Key Idea:
Instead of simulating flow from each cell to the oceans (which is costly), **we reverse the problem**:

- Perform **BFS from all cells adjacent to the Pacific Ocean**.
- Perform **BFS from all cells adjacent to the Atlantic Ocean**.
- Any cell **reachable by both BFS traversals** can flow to both oceans.

---

## 🧠 Algorithm Steps:

1. **Initialization**:
   - Create two `visited` matrices: `pac` and `alt` for Pacific and Atlantic reachability.
   - Initialize two queues: `qpac` and `qalt` with border cells touching the Pacific and Atlantic respectively.

2. **BFS Traversal**:
   - For both Pacific and Atlantic:
     - Start BFS from their respective borders.
     - Only move to a neighboring cell if it is **unvisited** and has a **height ≥ current cell's height** (valid reverse flow).

3. **Final Result**:
   - Iterate over each cell in the grid.
   - If a cell is visited in both `pac` and `alt`, add it to the result.

---

## 🧪 Example

### 🔹 Input:
```cpp
heights = {
  {1, 2, 2, 3, 5},
  {3, 2, 3, 4, 4},
  {2, 4, 5, 3, 1},
  {6, 7, 1, 4, 5},
  {5, 1, 1, 2, 4}
}
```


| Type      | Complexity |
| --------- | ---------- |
| **Time**  | `O(m × n)` |
| **Space** | `O(m × n)` |
