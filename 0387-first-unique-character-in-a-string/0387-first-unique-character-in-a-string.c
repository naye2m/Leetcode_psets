
// Solved in 6min 40sec
int firstUniqChar(char* s) {
    short* cs = calloc(sizeof(short), 26);

    int cl = strlen(s);
    // finding all single chars
    for (int i = 0; i < cl; i++) {
        int cp = s[i] - 'a';
        if (cs[cp] < 2)
            cs[cp]++;
    }
    for (int i = 0; i < cl; i++) {
        int cp = s[i] - 'a';
        if (cs[cp] == 1)
            return i;
    }
    return -1;
}