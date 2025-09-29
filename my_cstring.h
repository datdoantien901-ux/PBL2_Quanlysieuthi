#ifndef MY_CSTRING_H
#define MY_CSTRING_H

// Hàm tính độ dài chuỗi
int my_strlen(const char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

// Hàm copy chuỗi src -> dest
char* my_strcpy(char* dest, const char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
    return dest;
}
#endif