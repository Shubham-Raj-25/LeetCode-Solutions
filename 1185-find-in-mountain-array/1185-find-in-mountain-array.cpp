/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &ma) {
        int left = 0, len = ma.length();
        int right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int midVal = ma.get(mid);
            int midRightVal = ma.get(mid + 1);

            if (midVal < midRightVal)
                left = mid + 1;
            else
                right = mid;
        }
        return left; 
    }

    int binarySearch(int left, int right, int target, MountainArray &ma, bool isIncreasing) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = ma.get(mid);

            if (midVal == target)
                return mid;
            else if (midVal < target) {
                if (isIncreasing)
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if (isIncreasing)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &ma) {
        int peak = findPeak(ma);

        int leftResult = binarySearch(0, peak, target, ma, true);
        if (leftResult != -1)
            return leftResult;

        int rightResult = binarySearch(peak + 1, ma.length() - 1, target, ma, false);
        return rightResult;
    }
};
