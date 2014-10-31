/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/
class Solution {
  public:
    int findMin(vector<int>& num) {
        return findMinRecursion(num, 0, num.size() - 1);
    }

    int findMinRecursion(vector<int>& num, int low, int high) {
        if (high < low) {
            return num[0];
        }
        if (high == low) {
            return num[low];
        }
        // Find mid
        int mid = low + (high - low) / 2; /*(low + high)/2;*/

        // Check if element (mid+1) is minimum element. Consider
        // the cases like {3, 4, 5, 1, 2}
        if (mid < high && num[mid + 1] < num[mid]) {
            return num[mid + 1];
        }

        // Check if mid itself is minimum element
        if (mid > low && num[mid] < num[mid - 1]) {
            return num[mid];
        }

        // Decide whether we need to go to left half or right half
        return min(findMinRecursion(num, low, mid - 1), findMinRecursion(num, mid + 1, high));
    }
};
