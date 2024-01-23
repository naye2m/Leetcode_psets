/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int* returnArr = malloc(sizeof(int) * (*returnSize));
    
    int xorSum = 0;
    for (int i = 0; i < numsSize; i++) {
        xorSum ^= (i + 1) ^ nums[i];
    }

    // Find the rightmost set bit in xorSum
    int mask = 1;
    while ((xorSum & mask) == 0) {
        mask <<= 1;
    }

    int num1 = 0, num2 = 0;
    for (int i = 1; i <= numsSize; i++) {
        if (i & mask) {
            num1 ^= i;
        } else {
            num2 ^= i;
        }

        if (nums[i - 1] & mask) {
            num1 ^= nums[i - 1];
        } else {
            num2 ^= nums[i - 1];
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == num1) {
            returnArr[0] = num1;
            returnArr[1] = num2;
            return returnArr;
        } else if (nums[i] == num2) {
            returnArr[0] = num2;
            returnArr[1] = num1;
            return returnArr;
        }
    }

    // If no error is found, return a dummy array
    returnArr[0] = 0;
    returnArr[1] = 0;
    return returnArr;
}
