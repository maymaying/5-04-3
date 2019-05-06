#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


/*
//调整数组使奇数全部都位于偶数前面
void Swap_arr(int *arr, int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		while (left<right && arr[left] % 2 == 1)
		{
			left++;
		}
		while (left < right && arr[right] % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
void show(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);//*(arr+i)  []自带解引用
	}
	printf("\n");
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(arr)/sizeof(arr[0]);	
	show(arr,len);
	Swap_arr(arr,len);
	show(arr,len);
	system("pause");
	return 0;
}
*/


/*
//杨氏矩阵 有一个二维数组.数组的每行从左到右是递增的，每列从上到下是递增的.在这样的数组中查找一个数字是否存在
void find(int arr[3][3], int *px, int * py, int key)
{
	int x = 0;
	int y = *py - 1;
	while ((x< *px) && (y >= 0))
	{
		if (arr[x][y] == key)
		{
			*px = x;
			*py = y;
			return;
		}
		else if (arr[x][y] < key)
		{
			x++;
		}
		else//arr[x][y] > key
		{
			y--;
		}
	}
	*px = -1;
	*py = -1;
}
int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int x = 3;
	int y = 3;
	find(arr,&x,&y,6);
	if(x != -1 && y != -1)
	{
		printf("找到了,下标为：%d,%d\n",x,y);
	}
	else
	{
		printf("没有找到\n");
	}
	system("pause");
	return 0;
}
*/


/*
//打印二维数组
//void print_Arrs(int arr[3][3],int row,int col)
//{}
//void print_Arrs(int (*arr)[3],int row,int col)
//{}
void print_Arrs(int *arr, int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//printf("%d ",arr[i][j]);error
			printf("%d ", arr[i*col + j]);
		}
		printf("\n");
	}
}
int main()
{
	//int (*arr)[3]数组指针      int *arr[3]指针数组
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print_Arrs((int*)arr, 3, 3);//强转陈  int*
	system("pause");
	return 0;
}
*/


/*
//实现一个函数，可以左旋字符串中的k个字符。 ABCD左旋一个字符得到BCDA   ABCD左旋两个字符得到CDAB
//暴力解法
void left_move(char *str, int k)
{
	if (k < 0 || k > strlen(str))
	{
		printf("k值不合法\n");
		return;
	}
	while (k != 0)
	{
		char *cur = str;
		char tmp = *cur;
		while (*(cur + 1) != '\0')
		{
			*cur = *(cur + 1);
			cur++;
		}
		*cur = tmp;
		k--;
	}
}


void Reverse(char *left, char *right)
{
	assert(left != NULL && right != NULL);//断言
	while (left<right)//逆置
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char *str, int k)
{
	int len = strlen(str);
	if (k < 0 || k > strlen(str))
	{
		printf("k值不合法\n");
		return;
	}
	Reverse(str, str + k - 1);
	Reverse(str + k, str + len - 1);
	Reverse(str, str + len - 1);
}
int main()
{
	char str[] = "abcdef";
	printf("%s\n", str);
	left_move(str,3);
	printf("%s\n",str);
	system("pause");
	return 0;
}
*/



/*
//判断一个字符串是否为另外一个字符串旋转之后的字符串。 
//例如：给定s1 = AABCD和s2 = BCDAA，返回1   给定s1 = abcd和s2 = ACBD，返回0

void Reverse(char *left, char *right)
{
	assert(left != NULL && right != NULL);//断言
	while (left<right)//逆置
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char *str, int k)
{
	int len = strlen(str);
	if (k < 0 || k > strlen(str))
	{
		printf("k值不合法\n");
		return;
	}
	Reverse(str, str + k - 1);
	Reverse(str + k, str + len - 1);
	Reverse(str, str + len - 1);
}
int is_left_move(char *arr, const char *p)
{
	int i = 0;
	if (strlen(arr) != strlen(p))
	{
		return 0;
	}
	for (i = 1; i <= strlen(arr); i++)
	{
		left_move(arr, 1);
		//bcdefa
		if (strcmp(arr, p) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char str[] = "abcdef";
	char str2[] = "cdefab";
	if (is_left_move(str, str2) == 1)
	{
		printf("str2是str1旋转后的\n");
	}
	else
	{
		printf("str2不是str1旋转后的\n");
	}
	system("pause");
	return 0;
}
*/



/*
char *strncat(char *strDest,const char *strSource,size_t count );
将strSource的count个字符，拼接到strDest

char *strcat(char *strDestination,const char *strSource);

strcat(str,str2);--->把strSource拼接到strDestination
*/


/*
int is_left_move(char *arr, const char *p)
{
	if (strlen(arr) != strlen(p))
	{
		return 0;
	}
	strncat(arr, arr, strlen(arr));
	printf("%s\n", arr);

	//strstr查找字符串
	//char *strstr(const char *str,const char *strSearch);
	//在str里边，查找字符串strSearch。
	
	if (strstr(arr, p) == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{

	char str[] = "abcdef";
	char str2[] = "cdefab";
	if (is_left_move(str, str2) == 1)
	{
		printf("str2是str1旋转后的\n");
	}
	else
	{
		printf("str2不是str1旋转后的\n");
	}
	system("pause");
	return 0;
}

//int main()
//{
//
//	char str[20] = "abcdef";
//	char str2[] = "cdefab";
//	char *p = strcat(str, str2,3);
//	//printf("%s\n", p);
//	printf("%s\n", str);
//	//printf("%s\n", strcat(str, str2));
//	system("pause");
//	return 0;
//}
*/


