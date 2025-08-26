

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> ans;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            ans.push_back(arr[left]);
            left++;
        }
        else
        {
            ans.push_back(arr[right]);
            cnt += mid - left + 1;
            right++;
        }
    }

    while (left <= mid)
    {
        ans.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        ans.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = ans[i - low];
    }
}
void mergesort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int inversionCount(vector<int> &arr)
{
    // Code Here
    int n = arr.size();

    mergesort(arr, 0, n - 1);

    return cnt;
}

int main()
{
    vector<int> arr = {2, 3, 8, 6, 1};
    int result = inversionCount(arr);
    cout << "Number of inversions: " << result << endl;
    return 0;
}