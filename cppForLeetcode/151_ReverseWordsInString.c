#include <stdio.h>
#include <string.h>

char * swap(char *s, char *tempStart, char *tempend)
{
    char tempchar = '\0';
    while(tempStart < tempend)
    {
        tempchar = *tempStart;
        *tempStart = *tempend;
        *tempend = tempchar;

    
        tempStart ++;
        tempend --;
    }
    return s;
}
void reverseWords(char *s) {
    char *start = s;
    char *end = NULL;
    char *temp = start;
    char tempchar = '\0';
    char *wordStart = NULL;
    char *wordEnd = NULL;
    while (*start == ' ') start ++;
    
    if (strlen(start) == 1)
    {
        return ;
    }
    while (*temp != '\0') temp ++;
    end = temp - 1;
    while (*end == ' ') end--;

    s = swap(s, start, end);

    temp = start;

    wordStart = s;
    while(temp <= end)
    {

    // printf("%s\n", s);
        if (*temp != ' ')
        {
            wordStart = temp;
            temp ++;
            while (*temp != ' ' && temp <= end)
            {
                temp ++;
            }

            wordEnd = temp - 1;
            s = swap(s, wordStart, wordEnd);
        }
        temp++;
    }

    temp = s;
    while (temp <= end)
    {
        if (*temp != ' ')
        {
            while (*temp != ' ')
            {
                *s = *temp;
                temp ++;
                s++;
            }
            *s = ' ';
            s ++;
        }

        temp ++;
    }
    *(s - 1) = '\0';
    while (*end == ' ' && end >= start) end--;
    *(end + 1) = '\0';
}

main(void)
{
    char  s[] = "the sky is blue";
    reverseWords(s);
    printf("%s\n", s);
    
    char s1[] = " ";
    reverseWords(s1);
    printf("==%s==\n", s1);

    char s3[] = "hello worl";
    reverseWords(s3);
    printf("==%s==\n", s3);

    char s2[] = "  the   sky     is blue  ";
    reverseWords(s2);
    printf("==%s==\n", s2);
}