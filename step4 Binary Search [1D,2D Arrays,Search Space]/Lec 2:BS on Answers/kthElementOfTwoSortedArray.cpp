class Solution {
  public:
    /*
        Approach:
        - We need to find the k-th smallest element in the merged array of two sorted arrays.
        - Instead of merging (O(n1+n2)), we use Binary Search on the smaller array.
        - Partition both arrays such that left half contains k elements.
        - Use conditions:
            - If l1 <= r2 and l2 <= r1 → correct partition found → answer is max(l1, l2).
            - Else adjust search boundaries.
        - Always binary search on smaller array to optimize.

        Time Complexity: O(log(min(n1, n2)))  
            → Binary search happens on the smaller array only.  
        Space Complexity: O(1)  
            → Only constant space is used.
    */
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n1=a.size();
        int n2=b.size();

        // Ensure binary search is always on the smaller array
        if(n1>n2) return kthElement(b,a,k);

        int left=k; // total elements needed in left half
        int low=max(0,k-n2);   // at least this many from a
        int high=min(k,n1);    // at most this many from a

        while(low<=high){
            int mid1=low+(high-low)/2;  // partition for array a
            int mid2=left-mid1;         // partition for array b

            // Boundaries: l1, l2 = left part max; r1, r2 = right part min
            int l1=(mid1-1>=0)?a[mid1-1]:INT_MIN;
            int l2=(mid2-1>=0)?b[mid2-1]:INT_MIN;
            int r1=(mid1<n1)?a[mid1]:INT_MAX;
            int r2=(mid2<n2)?b[mid2]:INT_MAX;

            // Correct partition condition
            if(l1<=r2 && l2<=r1){
                return max(l1,l2); // k-th element will be max of left part
            }
            else if(l1>r2){
                // too many elements taken from a → shrink
                high=mid1-1;
            }
            else {
                // too few elements taken from a → expand
                low=mid1+1;
            }
        }
        return 0; // should not reach here
    }
};
