class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = 0;

        while(s <= e)
        {
            mid = s + (e - s)/2;
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
        return -1;
    }
};
