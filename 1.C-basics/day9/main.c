#pragma warning(disable:4996)
#pragma warning(disable:6031)

#include<stdio.h>
#include<string.h>

int main() {
	char str1[20];
	char str2[20];
	int len;
	//scanf("%c", str1);	若采用scanf，空格就相当于一个结束符，识别不了
	gets(str1);
	//fgets(str1, 20, stdin);
	/*
	sizeof()操作符求出的长度包含字符串末尾的结束符 ‘\0’；
	size()函数   只能用在C++中

	length()函数求出的字符串长度不包含字符串末尾结束符’\0’
	length()函数   只能用在C++中

	strlen()函数求出的字符串长度为有效长度，既不包含字符串末尾结束符 ‘\0’；
	strlen()函数   使用范围C/C++
		strlen函数用之前需要先对字符数组定义，
		例如char str[]={“hello world”};或
		char str[]={‘h’,‘e’,‘l’,‘l’,‘o’,’ ‘,‘w’,‘o’,‘r’,‘l’,‘d’,’\0’};
	*/
	len = strlen(str1);
	for (int i = 1; i < len; i++) {
		str2[i] = str1[len - i - 1];	//将1数组的下标存的数据赋值给逆转后2数组的下标
	}
	str2[len] = '\0';	//【在b数组中，数据结束后添加结束符】
	if (strcmp(str1, str2) > 0) {
		printf("1");
	}
	else if (strcmp(str1, str2) < 0) {
		printf("-1");
	}
	else {
		printf("0");
	}
}


