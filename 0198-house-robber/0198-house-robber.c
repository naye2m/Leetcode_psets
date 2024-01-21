int rob(int* nums, int numsSize) {
    int max(int a, int b){
        return a>b? a:b;
    }
    if (numsSize == 0)return 0;
    if (numsSize == 1)return nums[0];
    int* dp = malloc(numsSize * sizeof(int));
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for (int i = 2; i < numsSize; i++){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[numsSize - 1];
    //     Create an array dp of size n to store the maximum amount of money that can be robbed up to each house
    // dp[0] = nums[0]
    // dp[1] = max(nums[0], nums[1])
    // for i from 2 to n-1:
    //     dp[i] = max(dp[i-1], dp[i-2] + nums[i])
    // return dp[n-1]
}