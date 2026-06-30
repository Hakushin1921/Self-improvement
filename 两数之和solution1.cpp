#include <cstdlib>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i+1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target){
                int* returnnums = (int*) malloc(sizeof(int) * 2);
                returnnums[0] = i, returnnums[1] = j;
                *returnSize = 2;
                return returnnums;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
