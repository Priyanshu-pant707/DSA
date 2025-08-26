 # Inversion Count using Brute Force and Merge Sort

📌 Problem Statement
Given an array arr[], we want to count the number of inversions in it.
An inversion is a pair of indices (i, j) such that:

```bash
i < j  and  arr[i] > arr[j]
```
**Example**

Input:
```bash
arr = [2, 3, 8, 6, 1]
```

Inversions:

(2, 1)

(3, 1)

(8, 6)

(8, 1)

(6, 1)

Total = 5 inversions

🛠️ Approaches
1️⃣ Brute Force Solution – O(n²)

We simply check all pairs (i, j):
```cpp
int inversionCountBrute(vector<int> &arr) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

```

`Time Complexity: O(n²)`

`Space Complexity: O(1)`

- Works fine for small arrays but not efficient for large input (like 10⁵ elements).

- Optimized Solution (Merge Sort) – O(n log n)

We use Divide & Conquer with Merge Sort.

While merging two sorted halves, if an element from the right subarray is smaller than the left subarray element, then all remaining elements in the left subarray form inversions.

```cpp
#include <bits/stdc++.h>
using namespace std;
long long cnt = 0;

void merge(vector<int> &arr, int low, int mid, int high) {
    int left = low, right = mid + 1;
    vector<int> ans;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            ans.push_back(arr[left]);
            left++;
        } else {
            ans.push_back(arr[right]);
            cnt += (mid - left + 1);  // Count inversions
            right++;
        }
    }

    while (left <= mid) ans.push_back(arr[left++]);
    while (right <= high) ans.push_back(arr[right++]);

    for (int i = low; i <= high; i++) arr[i] = ans[i - low];
}

void mergesort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int inversionCount(vector<int> &arr) {
    cnt = 0; // reset
    mergesort(arr, 0, arr.size() - 1);
    return cnt;
}

int main() {
    vector<int> arr = {2, 3, 8, 6, 1};
    cout << "Number of inversions: " << inversionCount(arr) << endl;
    return 0;
}
```

`Time Complexity: O(n log n)`

`Space Complexity: O(n) (extra space for merging)`

✅ Suitable for large input arrays.

🔎 Dry Run Example

For arr = [2, 3, 8, 6, 1]

Left half → [2, 3, 8]

Right half → [6, 1]

During merging:

(8, 6) → inversion

(8, 1), (6, 1), (3, 1), (2, 1) → inversions

Total inversions = 5

📊 Complexity Comparison
Approach	Time Complexity	   Space Complexity	     When to Use
Brute Force  	O(n²)	           O(1)         	Small arrays (n ≤ 1000)
Merge Sort	   O(n log n)	       O(n)	       Large arrays (n up to 10⁵ or more)

✅ Output Example

Input:

```bash
arr = [2, 3, 8, 6, 1]
```

Output:

Number of inversions: 5
