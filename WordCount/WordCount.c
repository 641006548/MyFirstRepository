#include<stdio.h>
#include<string.h>

void countWord(FILE* fp, char path[]);
void countChar(FILE* fp, char path[]);

int main(int args, char* argv[])
{
	if (args < 3)
	{
		printf("�������������������������ִ�б���������ԣ�����ʾ��\"WordCount.exe -c test.txt\"");
		return 0;
	}
	else if (args > 3)
	{
		printf("����������࣡�����ԣ�����ʾ��\"WordCount.exe -c test.txt\"");
		return 0;
	}
	FILE* fp;
	errno_t err;

	if (!(err = fopen_s(&fp, argv[2], "r")))
	{
		if (strcmp(argv[1], "-c") == 0)
		{
			countChar(fp, argv[2]);
		}
		else if (strcmp(argv[1], "-w") == 0)
		{
			countWord(fp, argv[2]);
		}
		else
		{
			printf("���Ʋ������������ԣ�");
		}
	}
	else
	{
		printf("�ļ���ʧ�ܣ�\n");
		return 0;
	}
	return 0;
}

void countWord(FILE* fp, char path[])
{
	char tmp;
	char endFlag; //�����ж��ļ����һ���ַ��Ƿ�Ϊ���ʷָ��������ⵥ���������
	int countNum = 0;
	while (1)
	{
		tmp = fgetc(fp);
		if (tmp != EOF)
		{
			if (tmp == ',' || tmp == '\n' || tmp == ' ')
			{
				countNum++;
			}
		}
		else
		{
			if (endFlag != ',' && endFlag != '\n' && endFlag != ' ')  //���ⵥ���������
			{
				countNum++;
			}
			printf("\n��������%d\n", countNum);
			break;
		}
		endFlag = tmp;
	}
}

void countChar(FILE* fp, char path[])
{
	char tmp;
	int countNum = 0;
	while (1)
	{
		tmp = fgetc(fp);
		if (tmp != EOF)
		{
			countNum++;
		}
		else
		{
			printf("\n�ַ�����%d\n", countNum);
			break;
		}
	}
}