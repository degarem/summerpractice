#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

//���� ��� ��� ������ ���� ����� ���� ������ ������
//������, ����������, ����������, ����������, ������������, ����������, �����������, ����������, ������������, ������������,
//��������, ��������, �����, ���������, ����������, ����������, �������������, ���������
//���,  ������, ������, ���������, �������, ��������, �������, ���������, ���������
//������/��/�
//�������/���������


char map[6][10][15] = {
	{ "����", "��a", "���", "������", "�*���", "�i���", "�i�", "�i�i�", "���*���" },
{ "������", "�����������", "����������", "����������", "������������", "�*���������", "�i���������", "�i��������", "�i�i��������", "����*��������" },
{ "��������", "��������", "�����", "�*��������", "�i�������", "�i������", "�i�i������", "���*������" },
{ "���", "��i��i", "������", "���������", "�*������", "�i�����", "�i����", "�i�i����", "���*�����" },
{ "�����", "������", "�����i" },
{ "���������", "�������", "��������" }
};

int main()
{
	setlocale(LC_CTYPE, "ukr");

	int number = 0;
	scanf("%d", &number);

	printf("%d\n", number);

	if (number < 0)
	{
		printf("����� ");
		number *= -1;
	}

	while (number > 0)
	{
		int o = 0, d = 0, s = 0, buffer = number; //������, ��������, �����

		if (number >= 1000000)
			number /= 1000000;
		else if (number >= 1000)
			number /= 1000;

		if (number >= 100)
		{
			s = number / 100;
			number %= 100;
		}
		if (number >= 10)
		{
			d = number / 10;
			number %= 10;
		}
		o = number;

		if (buffer >= 1000000)
		{
			int offset = 0;

			if (s > 0)
				printf("%s ", map[3][s - 1]);
			if (d > 0)
			{
				if (d > 1)
				{
					printf("%s ", map[2][d - 2]);
				}
				else
				{
					printf("%s ", map[1][o]);
					o = 0;
					offset = 0;
				}
			}
			if (o > 0)
			{
				printf("%s ", map[0][o - 1]);
				if (o == 1)
					offset = 1;
				else if (o > 1 && o <= 4)
					offset = 2;//"�����", "������", "������"
			}
			printf("%s ", map[5][offset]);
		}
		else if (buffer >= 1000)
		{
			int offset = 0;

			if (s > 0)
				printf("%s ", map[3][s - 1]);
			if (d > 0)
			{
				if (d > 1)
				{
					printf("%s ", map[2][d - 2]);
				}
				else
				{
					printf("%s ", map[1][o]);
					o = 0;
					offset = 0;
				}
			}
			if (o > 0)
			{
				printf("%s ", map[0][o - 1]);
				if (o == 1)
					offset = 1;
				else if (o > 1 && o <= 4)
					offset = 2;//"�����", "������", "������"
			}
			printf("%s ", map[4][offset]);
		}
		else
		{
			if (s > 0)
				printf("%s ", map[3][s - 1]);
			if (d > 0)
			{
				if (d > 1)
					printf("%s ", map[2][d - 2]);
				else
				{
					printf("%s ", map[1][o]);
					o = 0;
				}
			}
			if (o > 0)
				printf("%s ", map[0][o - 1]);
		}

		if (buffer >= 1000000)
			buffer %= 1000000;
		else if (buffer >= 1000)
			buffer %= 1000;
		else
			buffer = 0;

		number = buffer;
	}

	putchar('\n');

	//system("pause");
	getchar();
	getchar();
	return 111;
}