#include <vector>
// 暴力解法
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //暴力解法
        int sz1 = nums1.size(), sz2 = nums2.size();
        int idx = 0, s1 = 0, s2=0;
        std::vector<int> tmp;
        tmp.resize(sz1 + sz2);
        while(s1 < sz1 && s2 < sz2) {
            tmp[idx++] = nums1[s1] < nums2[s2] ? nums1[s1++] : nums2[s2++];
        }
        while(s1 < sz1) {
            tmp[idx++] = nums1[s1++];
        }
        while(s2 < sz2) {
            tmp[idx++] = nums2[s2++];
        }
        // 得到排序
        bool odd = (sz1 + sz2) % 2 == 0;
        int mid1 = (sz1 + sz2) / 2;
        int mid2 = -1;
        if (odd) {
            mid2 = mid1 - 1;
            return (double)(double(tmp[mid1]) + double(tmp[mid2]))/2;
        } else {
            return (double)(tmp[mid1]);
        }
    }
};
// 优秀解法
// 此处的核心问题是
// 1. 递归的条件, 我们自己写的代码，出现了第0小的问题，并且没分析好退出条件
//    * 退出条件1，某个数组被抛弃完了
//    * 退出条件2, 要找第1个最小值了，（1不能再除了），就需要直接进行比较（为什么不能处理第0个最小值?)
//              * 因为1/2 = 0; 此时还是在直接比较start1 start2, 会让代码处理非常麻烦
class Solution {
public:
    static int findNthNumber(vector<int>& n1, int start1,  vector<int>& n2, int start2, int p) {
        // 此假设一定有一个会迭代到比p小
        if(n1.size() <= start1) {
            return n2[start2 + p - 1];
        } else if(n2.size() <= start2) {
            return n1[start1 + p - 1];
        }
        if (p == 1) {
            return std::min(n1[start1], n2[start2]);
        }
        int mid = p / 2; // 各自取一半
        int x, y;
        if (n1.size() - start1 < mid) { // == ?
            x = n1[n1.size() - 1];
        } else {
            x = n1[start1 + mid - 1];
        }
        if(n2.size() - start2  < mid) {
            y = n2[n2.size() -1];
        } else {
            y = n2[start2 + mid - 1];
        }

        if (x <= y) {
            if(n1.size() <= start1 + mid) {
            p -= (n1.size() - start1);
            start1 = n1.size(); // over
            } else {
                start1 += mid ;
                p -= (mid);
            }
        } else {
            if(n2.size() <= start2 + mid) {
            p -= (n2.size() - start2);
            start2 = n2.size(); // over
            } else {
                start2 += mid;
                p -= (mid);
            }
        }
        return findNthNumber(n1, start1, n2, start2, p);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz = (nums1.size() + nums2.size());
        // p != 0;
        int mid1 = (sz + 1)/ 2;
        int mid2 = (sz + 2) / 2 ;
        return (findNthNumber(nums1, 0, nums2, 0, mid1) + findNthNumber(nums1, 0, nums2, 0, mid2)) * 0.5;
    }
};