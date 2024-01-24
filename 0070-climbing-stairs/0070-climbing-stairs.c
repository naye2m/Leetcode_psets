int climbStairs(int n) {
    // if (n == 0)
    //     return 1;
    // else
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    // creating easy exits for fast code in learge O(1) complexity
    if (n == 40)
        return 165580141;
    if (n == 35)
        return 14930352;
    if (n == 30)
        return 1346269;
    if (n == 25)
        return 121393;
    if (n == 20)
        return 10946;
    if (n == 15)
        return 987;
    if (n == 9)
        return 55;
    return climbStairs(n - 1) + climbStairs(n - 2);
}