给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
 

示例 1：

```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
```

示例 2：

```
输入：nums = []
输出：[]
```

示例 3：

```
输入：nums = [0]
输出：[]
```
 

提示：

- 0 <= nums.length <= 3000
- -105 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

<br/>
<br/>

**解题思路：**
- 暴力法搜索为 O(N^3)时间复杂度，可通过双指针动态消去无效解来优化效率。
- 双指针法铺垫： 先将给定 nums 排序，复杂度为 O(NlogN)O(NlogN)。
- 双指针法思路： 固定 33 个指针中最左（最小）数字的指针 k，双指针 i，j 分设在数组索引 (k, len(nums))(k,len(nums)) 两端，通过双指针交替向中间移动，记录对于每个固定指针 k 的所有满足 nums[k] + nums[i] + nums[j] == 0 的 i,j 组合：
  1. 当 nums[k] > 0 时直接break跳出：因为 nums[j] >= nums[i] >= nums[k] > 0，即 33 个数字都大于 00 ，在此固定指针 k 之后不可能再找到结果了。
  2. 当 k > 0且nums[k] == nums[k - 1]时即跳过此元素nums[k]：因为已经将 nums[k - 1] 的所有组合加入到结果中，本次双指针搜索只会得到重复组合。
  3. i，j 分设在数组索引 (k, len(nums))(k,len(nums)) 两端，当i < j时循环计算s = nums[k] + nums[i] + nums[j]，并按照以下规则执行双指针移动：

  - 当s < 0时，i += 1并跳过所有重复的nums[i]；
  - 当s > 0时，j -= 1并跳过所有重复的nums[j]；
  - 当s == 0时，记录组合[k, i, j]至res，执行i += 1和j -= 1并跳过所有重复的nums[i]和nums[j]，防止记录到重复组合。

复杂度分析：

- 时间复杂度 O(N^2)：其中固定指针k循环复杂度 O(N)O(N)，双指针 i，j 复杂度 O(N)O(N)。
- 空间复杂度 O(1)O(1)：指针使用常数大小的额外空间。

作者：jyd
链接：https://leetcode-cn.com/problems/3sum/solution/3sumpai-xu-shuang-zhi-zhen-yi-dong-by-jyd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。