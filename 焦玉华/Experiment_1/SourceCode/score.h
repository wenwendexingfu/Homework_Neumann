#ifndef __SCORE_H__
#define __SCORE_H__

#include<iostream>
#include<string>
using namespace std;
struct SD
{
	char name[20];//名字
	char number[20];//学号
	float dailyscore;//平时成绩
	float finalscore;//期末成绩
	float text;//实验成绩
	float generalscore;//总评成绩
	int rank;//名次
};
SD* readdatafromfile(int n);//文件读取
void calcuscore(SD stu[], int n);//计算学生的总评成绩
void sortscore(SD stu[], int n);//根据成绩排名
void printout(SD stu[], int n);//按格式输出学生的信息
void putintoExcel(SD stu[], int n);//写入Excel表格
void serch(SD stu[],int n);
void calculate(SD stu[], int n);
#endif