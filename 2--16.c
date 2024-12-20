#include<stdio.h>

// 函数用于将十进制数转换为对应的十六进制字符
char toHexDigit(int value) {
    if (value >= 0 && value <= 9) {
        return (char)('0' + value);
    } else if (value >= 10 && value <= 15) {
        return (char)('A' + (value - 10));
    }
    return '?'; // 非法输入
}

int main() {
    int n, i;
    int ary[100]; // 存储二进制数
    char hex[100];
    printf("你想输入几位二进制数？");
    scanf("%d", &n);
    printf("请键入二进制数：(1 or 0)\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
        // 输入验证
        if (ary[i] != 0 && ary[i] != 1) {
            printf("输入错误，请输入0或1。\n");
            return 1;
        }
    }

    int m=0;
    // 处理二进制到十六进制的转换
    for(i=0;i<n;i+=4,m++)
    {
        int sum=0;
        if(n-i>=4)
        {
            sum=ary[i]+ary[i+1]*2+ary[i+2]*4+ary[i+3]*8;
        }
        else if(n-i==3)
        {
            sum=ary[i]+ary[i+1]*2+ary[i+2]*4;
        }
        else if(n-i==2)
        {
            sum=ary[i]+ary[i+1]*2;
        }
        else if(n-i==1)
        {
            sum=ary[i];
        }
        hex[m]=toHexDigit(sum);
    }
    while(hex[m-1]!='\0')//反序输出
    {
        printf("%c",hex[m-1]);
        m--;
    }

    return 0;
}
