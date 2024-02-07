// 2 : 14 without debuging time
// 6 : 24 with debuging time \U0001f494 division
int percentageLetter(char* s, char letter) {
    int sl = strlen(s);
    int count = 0;
    for (int i = 0; i < sl; i++)
        if (s[i] == letter)
            count++;
    if (!count)
        return 0;
    return (count * 100) / sl;
}