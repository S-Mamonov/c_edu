#include <stdio.h>
#include <string.h>

#define s21_NULL (void*)0

typedef unsigned long s21_size_t;

void* s21_memchr(const void* str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strchr(const char* str, int c);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
s21_size_t s21_strcspn(const char* str1, const char* str2);

s21_size_t s21_strlen(const char* str);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strrchr(const char* str, int c);
char* s21_strstr(const char* haystack, const char* needle);
char* s21_strtok(char* str, const char* delim);


int main()
{
    #ifdef __linux__
        puts("it's a linux, baby!");
    #endif // __linux__


    char str []="Kope";
    char sep []="Kop";

    printf ("+++%d+++\n", s21_strncmp(str, sep, 6));
    printf ("---%ld---\n", s21_strlen(sep));

    return 0;
}

void* s21_memchr(const void* str, int c, s21_size_t n){
    void* res = s21_NULL;
    const char* ptr = str;

    for (s21_size_t i = 0; i < n; i++){
        if(ptr[i] == c){
            res = (void*)(ptr + i);
            break;
        }
    }
    return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n){
    const char* ptr1 = str1;
    const char* ptr2 = str2;
    int res = 0;

    for (s21_size_t i = 0; i < n; i++){
        if(ptr1[i] != ptr2[i]){
            res = ptr1[i] - ptr2[i];
            break;
        }
    }
    return res;
}

void* s21_memcpy(void* dest, const void* src, s21_size_t n){
    char* ptr_dst = dest;
    const char* ptr_src = src;

    for(s21_size_t i = 0; i < n; i++){
        ptr_dst[i] = ptr_src[i];
    }
    return dest;
}

void* s21_memset(void* str, int c, s21_size_t n){
    char* ptr = str;

    for (s21_size_t i = 0; i < n; i++)
        ptr[i] = c;

    return str;
}

char* s21_strncat(char* dest, const char* src, s21_size_t n){
    char* ptr = s21_strchr(dest, '\0');
    s21_size_t cnt = 0;

    while(cnt < n && src[cnt]){
        ptr[cnt] = src[cnt];
        cnt++;
    }
    ptr[cnt] = '\0';

    return dest;
}

char* s21_strchr(const char* str, int c){
    s21_size_t len = s21_strlen(str);
    s21_size_t cnt = 0;
    int flag = 0;

    while(cnt < len + 1){
        if (str[cnt] == c){
            flag = 1;
            break;
        }
        cnt++;
    }
    return flag ? (char*)(str + cnt) : s21_NULL;
}

s21_size_t s21_strlen(const char* str){
    s21_size_t cnt;

    for (cnt = 0; str[cnt]; cnt++);

    return cnt;
}

int s21_strncmp(const char* str1, const char* str2, s21_size_t n){
    n = (s21_strlen(str1) < s21_strlen(str2) ? s21_strlen(str1) : s21_strlen(str1)) + 1;
    return s21_memcmp(str1, str2, n);
}

char* s21_strncpy(char* dest, const char* src, s21_size_t n){
    s21_size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    if (src[i] == '\0'){
        for (; i < n; i++)
            dest[i] = '\0';
    }
    return dest;
}

s21_size_t s21_strcspn(const char* str1, const char* str2){
    int flag = 1;
    s21_size_t cnt;

    for (cnt = 0; flag && cnt < s21_strlen(str1); cnt++)
        for (s21_size_t j = 0; j < s21_strlen(str2); j++)
            if (str1[cnt] == str2[j]){
                flag = 0;
                cnt--;
                break;
            }

    return cnt;
}

char* s21_strpbrk(const char* str1, const char* str2){
    char* res = s21_NULL;
    int flag = 1;

    for (s21_size_t i = 0; flag && i < s21_strlen(str1); i++)
        for (s21_size_t j = 0; j < s21_strlen(str2); j++)
            if (str1[i] == str2[j]){
                res = (char*)(str1 + i);
                flag = 0;
                break;
            }
    return res;
}

char* s21_strrchr(const char* str, int c){
    int len = s21_strlen(str);
    int flag = 0;

    while(len > -1){
        if (str[len] == c){
            flag = 1;
            break;
        }
        len--;
    }
    return flag ? (char*)(str + len) : s21_NULL;
}

char* s21_strstr(const char* haystack, const char* needle){
    char* res = s21_NULL;
    char* ptr;
    int flag = 1;

    if (s21_strlen(needle) == 0)
        flag = 0;

    while(flag && (ptr = s21_strchr(haystack, *needle)) != s21_NULL){
        if (s21_strncmp(ptr, needle, s21_strlen(needle)) == 0){
            res = ptr;
            break;
        }
        haystack++;
    }
    return flag ? res : (char*)haystack;
}

//char* s21_strtok(char* str, const char* delim){
//
//}
