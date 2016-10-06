/*
 *Filename:regex.c
 *
 *Decription:simple regex match char like '*' and '?' in the string text,example:“J* Smi??” can match “John Smith”
 *
 *Author:rutk1t0r
 *
 *Date:2016.10.05
 *
 *GPL
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan(const char* pszText, const char* pszName)
{
    int flag=0;//下一次匹配的起始位置。
    int i=0;
    int j=0;
    while(i<strlen(pszText)||j<strlen(pszName))
    {
        if(i>=strlen(pszText))
        {
            printf("匹配失败\n");
            return;
        }
        if(j>=strlen(pszName))
        {
            printf("匹配成功\n");
            j=0;
            return;
        }
        if(pszText[i]==pszName[j]||pszName[j]=='?')
        {
            //如果相等或者pszName中是通配符‘？’时，都认为是匹配成功,继续匹配；            
            i++;    
            j++;
              
            continue;
        }
        if(pszName[j]=='*')
        {
            j++;//跳过‘*’，继续匹配直到下一个字符匹配上为止
            while(pszText[i++] != pszName[j] && i<strlen(pszText));
                {
                    j++;//找到匹配的字符之后，j也向后移动一位。
                }
            continue;
        }
        j=0;//匹配失败，子串重新开始匹配。
        flag++;
        i=flag;//匹配失败，目标串返回flag指定的位置。
    }
    //用于两个字符串都恰好匹配完的情况！
    printf("匹配成功！\n");
      
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Please input like %s Text Regex\n", argv[0]);
        return 1;
    }
    else
    {
        printf("Text is %s\n", argv[1]);
        printf("Regex is %s\n", argv[2]);
        scan(argv[1], argv[2]);
    }
    return 0;
}