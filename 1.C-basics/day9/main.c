#pragma warning(disable:4996)
#pragma warning(disable:6031)

#include<stdio.h>
#include<string.h>

int main() {
	char str1[20];
	char str2[20];
	int len;
	//scanf("%c", str1);	������scanf���ո���൱��һ����������ʶ����
	gets(str1);
	//fgets(str1, 20, stdin);
	/*
	sizeof()����������ĳ��Ȱ����ַ���ĩβ�Ľ����� ��\0����
	size()����   ֻ������C++��

	length()����������ַ������Ȳ������ַ���ĩβ��������\0��
	length()����   ֻ������C++��

	strlen()����������ַ�������Ϊ��Ч���ȣ��Ȳ������ַ���ĩβ������ ��\0����
	strlen()����   ʹ�÷�ΧC/C++
		strlen������֮ǰ��Ҫ�ȶ��ַ����鶨�壬
		����char str[]={��hello world��};��
		char str[]={��h��,��e��,��l��,��l��,��o��,�� ��,��w��,��o��,��r��,��l��,��d��,��\0��};
	*/
	len = strlen(str1);
	for (int i = 1; i < len; i++) {
		str2[i] = str1[len - i - 1];	//��1������±������ݸ�ֵ����ת��2������±�
	}
	str2[len] = '\0';	//����b�����У����ݽ�������ӽ�������
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


