//  1 : 17 : 49 for finding best path  
char* frequencySort(char* s) {
    int sArrsize = 'z' - '0' + 1 + 1;
    int* list = (int*)calloc(sizeof(int), sArrsize);
    int sl = strlen(s);
    for (int i = 0; i < sl; i++) {
        if (s[i] >= '0' && s[i] <= 'z')
            list[s[i] - '0']++;
        else
            list[sArrsize - 1]++;
    }

    int ckmax = 0;
    int noca = 0; // number of char available
    for (int i = 0; i < sArrsize; i++) {
        // if (list[ixarr] == 0)
        if (!list[i])
            continue;
        if (ckmax < list[i])
            ckmax = list[i];
        noca++;
    }
    if (noca == 1)
        return s;

    char* res = malloc(sizeof(char) * (sl + 1));
    res[sl] = '\0';
    int sti = 0; // string index
    int edited;
    // if (false) {
    if (sl > sArrsize) {
        for (int count = ckmax;
             count > 0 &&
             sti < sl;) // if loop dosent chenge any char so count--
        {
            edited = 1;
            for (int i = 0; i < sArrsize; i++) {
                if (list[i] == count) {
                    list[i] = 0;
                    edited = 0;
                    for (int j = 0; j < count; j++)
                        res[sti++] = (char)i + '0';
                    // break;
                }
            } 
            count -= edited;
            
        }
    } else {
        for (int count = ckmax; count > 0 && sti < sl;) // if loop dosent chenge any char so count--
        {
            edited = 1;
            for (int i = 0; i < sl; i++) {
                if (list[s[i] - '0'] == count) {
                    list[s[i] - '0'] = 0;
                    for (int j = 0; j < count; j++)
                        res[sti++] = (char)s[i];
                    // break;
                }
            } 
            count -= edited;
        }
    }
    // for (int ixinstr = 0; ixinstr < sl; ixinstr++)
    //     while (ckmax > 1)
    //         for (int ixarr = 0; ixarr < sArrsize; ixarr++) {
    //             for (int i = 0; i < sArrsize; i++) {
    //                 if (list[i] == ckmax) ////////after doing work return
    //                 that ->>> list[i] = 0
    //                     for (int j = 0; j; j++) {
    //                     }
    //                 }
    //             else {
    //                 list[ckmax] = 0;
    //             }
    //         }
    // else {
    //     ckmax--;
    // }
    free(list);
    return res;
}