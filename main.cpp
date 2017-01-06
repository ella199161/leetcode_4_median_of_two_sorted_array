class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lln=nums1.size();
        int llm=nums2.size();
        int n_m=lln+llm;
        int med=0,k;
        if ((n_m)%2==0)
        {
           double res=(findK( nums1, nums2,0, 0,n_m/2)+findK( nums1, nums2,0, 0,n_m/2+1))/2;
            return  res;
         }
        else
        {
        double res=(findK( nums1, nums2,0, 0,n_m/2+1));
        return res;
        }
    }
    double findK(vector<int>& nums1, vector<int>& nums2,int a, int b,int k) {
    if (a>=nums1.size()) return nums2[b+k-1];
    if (b>=nums2.size()) return nums1[a+k-1];
    if (k==1) return min(nums1[a],nums2[b]);
    int med1=a+k/2-1>=nums1.size()? INT_MAX: nums1[a+k/2-1];
    int med2=b+k/2-1>=nums2.size()? INT_MAX: nums2[b+k/2-1];
    if (med1<med2)
    {
        return findK(nums1,nums2,a+k/2,b,k-k/2);
    }
    else
    {
        return findK(nums1,nums2,a,b+k/2,k-k/2);
    }
    }

};
