#pragma once

// Integer -> character array
inline int ll_char_d(long long input, char* buffer) {
    int pos = 0;
    bool negative = input < 0;

    // Get magnitude without overflowing on LLONG_MIN.
    unsigned long long value =
        negative
        ? 0ULL - static_cast<unsigned long long>(input)
        : static_cast<unsigned long long>(input);

    do {
        buffer[pos++] = '0' + (value % 10);
        value /= 10;
    } while (value != 0);

    if (negative)
        buffer[pos++] = '-';

    for (int i = 0; i < pos / 2; ++i) {
        char temp = buffer[i];
        buffer[i] = buffer[pos - 1 - i];
        buffer[pos - 1 - i] = temp;
    }

    buffer[pos] = '\0';
    return pos;
}

// Boolean -> character array
inline int bool_char_d(bool input, char* buffer) {
    const char* text = input ? "true" : "false";
    int pos = 0;

    while (text[pos] != '\0') {
        buffer[pos] = text[pos];
        ++pos;
    }

    buffer[pos] = '\0';
    return pos;
}

// Character array -> signed integer
inline bool char_int(const char* buffer, long long* result) {
    int pos = 0;
    bool negative = false;

    if (buffer[pos] == '-' || buffer[pos] == '+') {
        negative = buffer[pos] == '-';
        ++pos;
    }

    if (buffer[pos] < '0' || buffer[pos] > '9')
        return false;

    unsigned long long value = 0;
    const unsigned long long limit =
        negative
        ? (1ULL << 63)
        : ((1ULL << 63) - 1);

    while (buffer[pos] != '\0') {
        if (buffer[pos] < '0' || buffer[pos] > '9')
            return false;

        unsigned int digit = buffer[pos] - '0';

        if (value > (limit - digit) / 10)
            return false;

        value = value * 10 + digit;
        ++pos;
    }

    if (negative) {
        if (value == (1ULL << 63))
            *result = static_cast<long long>(-9223372036854775807LL - 1);
        else
            *result = -static_cast<long long>(value);
    } else {
        *result = static_cast<long long>(value);
    }

    return true;
}

// Character array -> Boolean
inline bool char_bool(const char* buffer, bool* result) {
    if (buffer[0] == '1' && buffer[1] == '\0') {
        *result = true;
        return true;
    }

    if (buffer[0] == '0' && buffer[1] == '\0') {
        *result = false;
        return true;
    }

    if (buffer[0] == 't' && buffer[1] == 'r' &&
        buffer[2] == 'u' && buffer[3] == 'e' &&
        buffer[4] == '\0') {
        *result = true;
        return true;
    }

    if (buffer[0] == 'f' && buffer[1] == 'a' &&
        buffer[2] == 'l' && buffer[3] == 's' &&
        buffer[4] == 'e' && buffer[5] == '\0') {
        *result = false;
        return true;
    }

    return false;
}

// Character array -> long double
inline bool char_float_ld(
    const char* buffer, long double* result
) {
    int pos = 0;
    bool negative = false;

    if (buffer[pos] == '-' || buffer[pos] == '+') {
        negative = buffer[pos] == '-';
        ++pos;
    }

    long double value = 0;
    bool has_digit = false;

    while (buffer[pos] >= '0' && buffer[pos] <= '9') {
        value = value * 10 + (buffer[pos] - '0');
        ++pos;
        has_digit = true;
    }

    if (buffer[pos] == '.') {
        ++pos;
        long double place = 0.1L;

        while (buffer[pos] >= '0' && buffer[pos] <= '9') {
            value += (buffer[pos] - '0') * place;
            place *= 0.1L;
            ++pos;
            has_digit = true;
        }
    }

    if (!has_digit || buffer[pos] != '\0')
        return false;

    *result = negative ? -value : value;
    return true;
}

inline bool char_float_d(const char* buffer, double* result) {
    long double value;

    if (!char_float_ld(buffer, &value))
        return false;

    *result = static_cast<double>(value);
    return true;
}

inline bool char_float_f(const char* buffer, float* result) {
    long double value;

    if (!char_float_ld(buffer, &value))
        return false;

    *result = static_cast<float>(value);
    return true;
}
