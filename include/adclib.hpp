#pragma once
inline void int_char(int i, char* buffer) {
    int pos = 0;

    if (i == 0) {
        buffer[pos++] = '0';
    }

    while (i > 0) {
        buffer[pos++] = '0' + (i % 10);
        i /= 10;
    }

    for (int j = 0; j < pos / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[pos - 1 - j];
        buffer[pos - 1 - j] = temp;
    }

    buffer[pos] = '\0';
}
inline int char_int(const char* buffer) {
    int result = 0;
    int sign = 1;
    int pos = 0;

    if (buffer[pos] == '-') {
        sign = -1;
        pos++;
    }

    while (buffer[pos] != '\0') {
        int digit = buffer[pos] - '0';
        result = result * 10 + digit;
        pos++;
    }

    return result * sign;
}
