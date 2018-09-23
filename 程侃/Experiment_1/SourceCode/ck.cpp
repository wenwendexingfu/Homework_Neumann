/*************************************************
** 源文件   : score.c
** 功能说明 : Function Definations
** 创建时间 : 2018-9-2/17:35
/**************************************************/

/*----------------头文件--------------*/

#include "score.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/*----------------函数定义-------------*/

//1.读取学生基本数据
int SS;
void readData(SS stu[], int N)
{

	printf("请按照如下格式输入学生信息：学号,姓名,平时成绩,期末成绩\n");

	for (int i=0;i<N;i++)
	{
		printf("第%d个学生:", i+1);
		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------成绩录入完毕!--------\n");



}

SS *readDataFromFile(int *N)
{

	printf("\n\n------第一步: 从文件读取学生的成绩信息--------\n\n");

	SS *stu;// 开辟新空间,存取文件中的每个学生信息

	FILE *fp=NULL;
	int count=0;
	int index=0;

	fp=fopen("data.txt","r");

	//1.获取学生数目
	if (fp!=NULL)
	{
		fscanf(fp,"%d",&count);
		*N=count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("学生数目为:%d\n",count);
	getchar();


	//2.给所有学生分配存储空间
	stu = (SS*)malloc(count *sizeof(SS));


	//3.读取每条学生的信息
	while ((!feof(fp))&&(index<count))
	{

		//读入文件数据到内存	
		fscanf(fp,"%s%s%f%f\n",(stu[index].number),(stu[index].name),&stu[index].dailyScore,&stu[index].finalScore);

		//输出原始学生信息
		printf("*学号：%s 姓名:%s 平时成绩：%4.2f分	期末成绩:%4.2f分\n",(stu[index].number),(stu[index].name),stu[index].dailyScore,stu[index].finalScore);

		index++;


	}

	fclose(fp);

	return stu;
}

//2.计算N个学生各自的总评成绩
void calcuScore(SS stu[],int N)
{


	printf("\n\n------第二步: 计算每个学生的总评成绩--------\n\n");

	for (int i=0; i<N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.8*stu[i].finalScore;
		printf("* 学号：%s	姓名:%s	 总成绩:%4.2f分\n",(stu[i].number),(stu[i].name),stu[i].generalScore);

	}
}


//3.根据总评成绩排名
int cmpBigtoSmall(const void *a,const void *b)
{
	SS *aa=(SS *)(a);
	SS *bb=(SS *)(b);



	if ((*aa).generalScore<(*bb).generalScore) 
		return 1;

	else if ((*aa).generalScore>(*bb).generalScore)  
		return -1;

	else
		return 0;

}

void sortScore(SS stu[],int N);
{

	qsort(&(stu[0]),N,sizeof(stu[0]),cmpBigtoSmall);

}


//4.按照一定的格式输出N个学生的信息
void printOut(SS stu[],int N);
{


	printf("\n------第三步: 根据总成绩输出学生排名信息!------\n\n");

	for (int i=0; i<N;i++)
	{

		printf("第%d名信息 学号：%s	姓名:%s	总成绩:%4.2f分\n", i+1,&(stu[i].number[0]),&(stu[i].name[0]),stu[i].generalScore);
	}


}
//计算平均值、方差、标准差
    void main()
	{
    int a[N],n,i;

    float aver,s;

    float sum=0,e=0;

    printf("请输入样本量：");

    scanf("%d",&n);

    printf("请输入%d个样本：",n);

    for(i=0;i<n;i++)

	{
    scanf("%d",&a[i]);

    sum+=a[i];


	}
    aver=sum/n;

    for(i=0;i<n;i++)

    e+=(a[i]-aver)*(a[i]-aver);

    e/=n-1;

    s=sqrt(e);

    printf("平均数为：%.2f,方差为：%.2f,标准差为：%.2f\n",aver,e,s); 

	} 

	//根据学号查询成绩
   void search(Stu s[], int n,char *id);

   {
    int i;

    for(i=0; i<n; i++)

    if(strcmp(s[i].id,id)==0)

	{
    printf("%s %s %d %d %d\n",s[i].id,s[i].name, s[i].score[0],s[i].score[1],s[i].score[2]);

    return;
	}
	else
    printf("没找到相应记录\n");
   }