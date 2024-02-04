
bool verify_word(int* target_count, int* str_count) {
    for (int i = 0; i < 256; i++) {
        if (target_count[i] > 0 && str_count[i] < target_count[i]) {
            return false;
        }
    }
    return true;
}

char* minWindow(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    if (m < n) {
        return "";
    }

    int target_count[256] = {0};  // Assuming ASCII characters
    int str_count[256] = {0};

    for (int i = 0; i < n; i++) {
        target_count[t[i]]++;
    }

    int left = 0, right = 0;
    int min_len = INT_MAX;
    int min_left = 0;

    while (right < m) {
        str_count[s[right]]++;

        while (verify_word(target_count, str_count)) {
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_left = left;
            }

            str_count[s[left]]--;
            left++;
        }

        right++;
    }

    if (min_len == INT_MAX) {
        return "";
    }

    char* result = malloc(sizeof(char) * (min_len + 1));
    if (!result) {
        return "malloc unsuccessful";
    }

    strncpy(result, s + min_left, min_len);
    result[min_len] = '\0';

    return result;
}