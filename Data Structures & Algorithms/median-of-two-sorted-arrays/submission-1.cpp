class Solution 
{
    public:
        // two pointers algorithm
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
        {   
            if(nums1.size() == 0 && nums2.size() == 0)
            {
                return -0.5;
            }
            vector<int> res;
            int i1 = 0;
            int i2 = 0;
            while(i1 < nums1.size() && i2 < nums2.size())
            {
                if(nums1[i1] <= nums2[i2])
                {
                    res.push_back(nums1[i1]);
                    i1++;
                }
                else
                {
                    res.push_back(nums2[i2]);
                    i2++;
                }
            }
            while(i1 < nums1.size())
            {
                res.push_back(nums1[i1]);
                i1++;
            }
            while(i2 < nums2.size())
            {
                res.push_back(nums2[i2]);
                i2++;
            }
            if(res.size() % 2 == 0)
            {
                return (res[res.size() / 2 - 1] + res[res.size() / 2]) / 2.0;
            }
            return res[res.size() / 2];
        }
};
