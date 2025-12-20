#define all(v)    v.begin(),v.end()

class Solution {
    int ans;
public:
    void mergeSort(vector<int>& nums, int left, int right) {
        int len = right - left + 1;

        if (len == 1) return;

        vector<long long>leftHalf, rightHalf;
        int mid = (right + left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        for (int i = left; i <= mid; i++)
            leftHalf.push_back(nums[i]);

        for (int i = mid + 1; i <= right; i++)
            rightHalf.push_back(nums[i]);


        int i = 0, j = 0, curPos = left;

        while (i < leftHalf.size() && j < rightHalf.size()) {
            if (leftHalf[i] <= rightHalf[j])
                nums[curPos++] = leftHalf[i++];
            else
                nums[curPos++] = rightHalf[j++];
        }

        while (i < leftHalf.size())
            nums[curPos++] = leftHalf[i++];

        while (j < rightHalf.size())
            nums[curPos++] = rightHalf[j++];


        for (auto &it : rightHalf) {
            long long lower = upper_bound(all(leftHalf), it * 2) - leftHalf.begin();
            ans += leftHalf.size() - lower;
        }
    }

    int reversePairs(vector<int>& nums) {
        ans = 0;
        const int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return ans;
    }
};