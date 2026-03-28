class Solution {
  public:
    /*
        Approach:
        - Use Binary Search on partition index of the smaller array.
        - At every step, divide arrays into left-half and right-half.
        - Ensure all elements in left-half <= all elements in right-half.
        - If partition is correct:
            - If total size is odd → median = max(left parts).
            - If total size is even → median = (max(left parts) + min(right parts)) / 2.
        - Else adjust binary search boundaries accordingly.

        Time Complexity: O(log(min(n1, n2))) 
            → because binary search runs on the smaller array.
        Space Complexity: O(1) 
            → only constant variables used.
    */
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Ensure binary search happens on the smaller array
        int n1=a.size();
        int n2=b.size();
        if(n1>n2) return medianOf2(b,a);

        int low=0;
        int high=n1;
        int left=(n1+n2+1)/2;   // elements required in left partition

        while(low<=high){
            int mid1=low+(high-low)/2;   // cut index for first array
            int mid2=left-mid1;          // cut index for second array

            // boundary conditions for left and right values
            int l1=(mid1-1>=0)?a[mid1-1]:INT_MIN;
            int l2=(mid2-1>=0)?b[mid2-1]:INT_MIN;
            int r1=(mid1<n1)?a[mid1]:INT_MAX;
            int r2=(mid2<n2)?b[mid2]:INT_MAX;

            // valid partition found
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==1){
                    return max(l1,l2);   // odd case → median = max of lefts
                }
                else {
                    return ((double)(max(l1,l2)+min(r1,r2)))/2.0; // even case
                }
            }
            else if(l1>r2){
                // too many elements taken from first array → move left
                high=mid1-1;
            }
            else {
                // too few elements taken from first array → move right
                low=mid1+1;
            }
        }
        return 0; // should never reach here
    }
};
