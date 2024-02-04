// Compeletly own creation

bool validate_r(char** board, int row, bool* tmpcker) {

    for (int i = 0; i < 10; i++)
        tmpcker[i] = 1;
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == '.')
            continue;
        int x = board[row][i] - '1';
        if (x < 0 || x > 8)
            return false;
        if (!tmpcker[x])
            return false;
        tmpcker[x] = 0;
    }
    return true;
}
bool validate_c(char** board, int column, bool* tmpcker) {

    for (int i = 0; i < 10; i++)
        tmpcker[i] = 1;
    for (int i = 0; i < 9; i++) {
        if (board[i][column] == '.')
            continue;
        int x = board[i][column] - '1';
        if (x < 0 || x > 8)
            return false;
        if (!tmpcker[x])
            return false;
        tmpcker[x] = 0;
    }
    return true;
}

bool validate_g(char** board, int grid, bool* tmpcker) {

    for (int i = 0; i < 10; i++)
        tmpcker[i] = 1;
    int supX = (grid / 3) * 3;
    int supY = (grid % 3) * 3;
    for (int i = 0; i < 9; i++) {

        int dx = supX + ((int)i / 3);
        int dy = supY + ((int)i % 3);
        if (board[dx][dy] == '.')
            continue;
        int x = board[dx][dy] - '1';
        if (x < 0 || x > 8)
            return false;
        if (!tmpcker[x])
            return false;
        tmpcker[x] = 0;
    }
    return true;
}
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int* tmpCk = malloc(sizeof(int) * 10);
    // for (int i = 0; i < 9; i++) tmpck[i] = true;
    for (int i = 0; i < 9; i++) {
        if (!(validate_r(board, i, tmpCk) && validate_c(board, i, tmpCk) &&
              validate_g(board, i, tmpCk))) {
            free(tmpCk);
            return false;
        }
        // return 'g';
    }
    return true;
}
