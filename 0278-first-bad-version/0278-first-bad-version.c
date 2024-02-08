//  21 : 42
// 33 : 12 with optimization
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    if(!isBadVersion(n - 1))return n;
    int *ints = malloc(sizeof(int) * 3);
    int *ok = &ints[0];
    int *bad = &ints[1];
    int *m = &ints[2];
    *ok = 0;
    *bad = n-1;

    // while(!(!isBadVersion(*ok) && isBadVersion(*ok+1))){
    while(*bad > *ok){
        *m = ((long)*ok + *bad) >> 1;
        if(isBadVersion(*m))
            *bad = *m ;
        else
            *ok = *m +1 ;
    }
    int res = *bad;
    free(ints);
    return res ;
}