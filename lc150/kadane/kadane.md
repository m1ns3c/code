# Kadane

Kadane 是卡内基梅隆大学的教授，这个算法是为了解决最大子序列的和（maximum subarray）提出的。

```python
def max_subarray(A):
    max_ending_here = max_so_far = A[0]
    for x in A[1:]:
        max_ending_here = max(x, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far
```
