#include <stdio.h>
#include <wchar.h>

int lenstr (const wchar_t* ptr);
void addstr (wchar_t* ptr1, int len, const wchar_t* ptr2);
int compstr (const wchar_t* ptr1, const wchar_t* ptr2);

int main()
{

    wchar_t str[] = L"안녕"; // 2바이트 고정
    int n = sizeof(str);   

    
    // 문자열 길이
    wchar_t str2[] = L"동해물과";
    // int n2 = wcslen(str2);
    int n2 = lenstr(str2);


    // 문자열 이어붙이기
    wchar_t str3[100] = L"abc";
    // wcscat_s(str3, 100, L"def");
    addstr(str3, 100, L"def");


    // 문자열 비교
    // int num = wcscmp(L"abcd", L"abcde");
    int num = compstr(L"abcd", L"abbde");


    return 0;
}

int lenstr (const wchar_t* ptr)
{
    int len = 0;
    while (*ptr != 0)
    {
        ++len;
        ++ptr;
    }
    return len;
}

void addstr (wchar_t* ptr1, int len, const wchar_t* ptr2)
{
    int i=0;
    while (0 != *ptr1)
    {
        ++ptr1;
        ++i;
    }

    for (; i < len-1; ++i)
    {
        if (0 != *ptr2)
        {
            *ptr1 = *ptr2;
            ++ptr1;
            ++ptr2;
        }
        else break;
    }
}

int compstr (const wchar_t* ptr1, const wchar_t* ptr2)
{
    int i = 0;
    while (ptr1[i]==ptr2[i] && ptr1[i]!=0 && ptr2[i]!=0) ++i;


    if (ptr1[i] == ptr2[i]) return 0;

    else if (ptr1[i] > ptr2[i]) return 1;

    else if (ptr1[i] < ptr2[i]) return -1;

    else return NULL; //예외발생
}