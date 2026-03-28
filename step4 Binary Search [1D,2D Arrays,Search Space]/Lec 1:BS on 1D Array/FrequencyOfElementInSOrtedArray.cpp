class Solution {
  public:
    // Recursive Binary Search Based Approach
    int countNumber(vector<int> &arr, int target, int low, int high, int cnt) {
        if (low > high) return 0;
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            cnt += 1;
            // count occurrences on both sides
            cnt = countNumber(arr, target, low, mid - 1, 0) + cnt;
            cnt = countNumber(arr, target, mid + 1, high, 0) + cnt;
        }
        else if (arr[mid] > target) {
            cnt = countNumber(arr, target, low, mid - 1, 0) + cnt;
        }
        else {
            cnt = countNumber(arr, target, mid + 1, high, 0) + cnt;
        }
        return cnt;
    }

    int countFreq(vector<int>& arr, int target) {
        return countNumber(arr, target, 0, arr.size() - 1, 0);
    }
};

/*
--------------------------------------
📌 Current Approach (Recursive Binary Search):
- Uses recursion to find `target` and expands left + right to count all occurrences.
- Time Complexity: O(n) in worst case (if all elements are the same).
- Space Complexity: O(log n) recursion stack (due to recursive calls).

--------------------------------------
📌 Iterative / Optimal Approach (Double Binary Search - "dd approach"):
- Find the first occurrence of `target` using binary search.
- Find the last occurrence of `target` using binary search.
- Count = (last - first + 1) if found, else 0.
- Time Complexity: O(log n)   ✅
- Space Complexity: O(1)      ✅

Example Code for DD Approach:

int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1; // search left
        }
        else if (arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return ans;
}

int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1; // search right
        }
        else if (arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return ans;
}

int countFreq(vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    if (first == -1) return 0; // not found
    int last = lastOccurrence(arr, target);
    return last - first + 1;
}
*/
