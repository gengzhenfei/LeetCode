#include <vector>
#include <iostream>
using namespace std;

class L088MergeSortedArray
{
private:
    /* data */
public:
    L088MergeSortedArray(/* args */);
    ~L088MergeSortedArray();

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> res;
        int mi = 0, ni = 0;
        while (m > mi && n > ni) {
            if (nums1[mi] > nums2[ni]) {
                res.push_back(nums2[ni++]);
            } else {
                res.push_back(nums1[mi++]);
            }
        }
        while (m > mi) { res.push_back(nums1[mi++]); }
        while (n > ni) { res.push_back(nums2[ni++]); }

        nums1 = res;
    }

    /**
     * 原地插入
     */
    void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int mi = 0, ni = 0;
        while (m > mi && n > ni) {
            if (nums1[mi] > nums2[ni]) {
                nums1.insert(nums1.begin() + mi++, nums2[ni++]);
                m++; // nums1 中相对元素个数m自增
                nums1.pop_back(); // nums1 中删除末尾元素0
            } else {
                mi++;
            }
        }
        while (n > ni) {
            nums1.insert(nums1.begin() + mi++, nums2[ni++]);
            nums1.pop_back();
        }
    }
};

L088MergeSortedArray::L088MergeSortedArray(/* args */) {}

L088MergeSortedArray::~L088MergeSortedArray() {}
