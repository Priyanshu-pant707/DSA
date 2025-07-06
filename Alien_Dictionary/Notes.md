# 👽 Alien Dictionary – Full Solution with Code & Explanation

## 🧾 Problem Statement

You are given a list of words sorted lexicographically from an alien dictionary.  
Determine the order of characters in the alien language.

---

## 🚀 Approach (Topological Sort – Kahn’s Algorithm)

### 🔹 Step-by-step Logic:

1. **Track Characters**:
   - Use a boolean array `exists[26]` to mark which lowercase characters appear.

2. **Build the Graph**:
   - Compare each pair of adjacent words.
   - Find the first mismatched character.
   - Add an edge from the first word’s char to the second.
   - If word1 is longer and is a prefix of word2 → invalid → return `""`.

3. **Topological Sorting (BFS - Kahn’s Algorithm)**:
   - Add all characters with `inDegree = 0` to the queue.
   - Pop from queue, append to result, and update in-degrees.
   - If in-degree never reaches 0 for some characters → cycle → return `""`.

---

## 📦 Data Structures Used:

- `vector<vector<int>> graph(26)` → Adjacency list
- `vector<int> inDegree(26)` → In-degree count
- `vector<bool> exists(26)` → Marks if character is in any word

---

## ⏱️ Time Complexity:

Let:
- `N` = Number of words
- `L` = Average length of a word
- `C` = Number of unique characters (≤ 26)

### 🔹 Complexity:
- Graph Building: `O(N × L)`
- Topological Sort: `O(C + E)` → bounded by 26

### ✅ Total:
O(N × L + C + E) ≈ O(N × L)