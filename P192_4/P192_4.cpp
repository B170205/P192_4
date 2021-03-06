// P192_4.cpp: 定义控制台应用程序的入口点。
//

#include "stdio.h"
#include "string.h"
//该函数实现课程信息输入，每门课长度不超过10
void input_course(char c[][10], int n)
{
	int i;
	printf("请输入课程信息：\n");
	for (i = 0; i < n; i++)
		scanf("%s", c[i]);

}
//该函数实现课程学生信息输入，不能出现字符
void input_stuNo(int a[], int n)
{
	int i;
	printf("请输入学号信息：\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

}
//该函数实现课程成绩输入，n个学生，5门课
void input_score(double score[][5], int n)
{
	int i, j;
	printf("请输入成绩信息：\n");
	for (i = 0; i < n; i++)
		for(j=0;j<5;j++)
			scanf("%lf", &score[i][j]);//因为疏忽，格式符写成了%d
}
//该函数实现平均成绩的计算，需要传入成绩数组，学号数组，学生人数，平均值数组（用来记录每个学生的平均成绩）
void cal_score_aver(double score[][5], double aver[], int a[], int n)
{
	int i, j;
	double sum ;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < 5; j++)
			sum += score[i][j];
		aver[i] = sum / 5;
		printf("%d同学 5门课平均成绩为 %f\n", a[i], aver[i]);
	}
	
}
//该函数实现课程平均成绩的计算。按列计算，一共5门课
void cal_course5_aver(double score[][5], char c[][10],int n)
{
	int i, j;
	double sum;
	for (i = 0; i < 5; i++)
	{
		sum = 0;
		for (j = 0; j <n; j++)
			sum += score[j][i];
		printf("第%d课 %s 平均成绩为 %f\n", i+1, c[i],sum/n);
	}
		
}
void find_stu_below2(double score[][5], int a[],int n)
{
	int i, j,k;
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < 5; j++)
			if (score[i][j] < 60) k++;
		if (k == 2)
			printf("%d student 两门课不及格\n", i);
	}
}
//该函数打印每门课超过85分的学生
void find_stu_excellent(double score[][5], double ave[],int a[],int n)
{
	int i, j,k;
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < 5; j++)
			if (score[i][j] > 85) k++;
		if (k == 5)
			printf("%d student 五门课优秀\n", i);
	}

}

int main()
{
	int num[5];
	double aver[5];
	double score[5][5];
	char course[5][10];
	input_course(course, 5);
	input_stuNo(num, 5);
	input_score(score, 5);
	cal_score_aver(score,aver,num,5);
	cal_course5_aver(score, course,5);
	find_stu_below2(score,num, 5);
	find_stu_excellent(score,aver,num, 5);
	

	
		
	return 0;
}

