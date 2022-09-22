#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int my_atoi(char *s)
{
	int num = 0;
	while (*s != '\0')
	{
		if (!(*s >= '0' && *s <= '9'))
		{
			return num;
		}
		num *= 10;
		num += (*s - 48);
		s++;
	}

	return num;
}


//实现切割函数
/*int cut_word(char *s, char *t[])*/
int cut_word(char *s, char **t)
{
	int count = 0;
	
	t[count++] = s;
	while (*s != '\0')
	{
		if (*s == ',')
		{
			*s = '\0';
			t[count++] = s + 1;
		}
		s++;
	}

	return count;
}

int main(void)
{
	int count = 0, i, j;
	char *t[12];//指针数组
	char buf[128] = "12:12,7:05,23:34,19:17,6:35,12:08,5:43,20:02,19:01,4:38";
	char t_buf[128] = {};
	char *tmp = buf;
	int len = 0;


#if 1
	printf("%s\n", buf);

	count = cut_word(buf, t);
	//while ((t[count++] = strsep(&tmp, ",")) != NULL)
	//	;

	printf("count : %d\n", count);
	for (i = 0; i < count ; i++)
	{
		printf("%s ", t[i]);
	}
	printf("\n");

	//count -= 1;

	for (i = 0; i < count; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (my_atoi(t[i]) > my_atoi(t[j]))
			{
				tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
			else if  (my_atoi(t[i]) == my_atoi(t[j]) && my_atoi(strchr(t[i], ':') + 1) > my_atoi(strchr(t[j], ':') + 1))
			{
				tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			
			}

		}
	}
	for (i = 0; i < count; i++)
	{
		printf("%s ", t[i]);
	}
	printf("\n");

	for (i = 0; i < count; i++)
	{
		strcpy(t_buf + len, t[i]);
		len += strlen(t[i]);
		strcpy(t_buf + len, ",");
		len += 1;

	}
	t_buf[len - 1] = '\0';

	strcpy(buf, t_buf);
	printf("%s\n", buf);
#endif	
	return 0;
}
