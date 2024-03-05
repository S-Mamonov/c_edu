#include <stdio.h>
#include <string.h>

/*
здесь функция сравнения с сигнатурой:
int match_ab(const char a, const char b);
*/
int match_ab(const char a, const char b){
    if ((a >= '0') && (a <= '9') && b == ' ')
        return 1;
    return a < b;
}

void sort_string(char *str, size_t max_len, int (*foo)(char, char))
{
    // здесь продолжайте функцию
    char temp;
    for (int i = 1; i < max_len; i++){
        for (int j = i; j < max_len; j++){
            if (foo(str[j], str[i-1])){
                temp = str[i-1];
                str[i-1] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    // здесь продолжайте программу
    sort_string(str, strlen(str), match_ab);
    puts(str);

    return 0;
}
