#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	char number[20];  //学生学号
	char name[20];  //学生姓名
	int common_score;  //学生平时成绩
	int experiment_score;  //学生实验成绩
	int final_score;  //期末成绩
	float score;  //最终成绩
	int ranking;  //名次
}Student;


Student* readDataFromFile(int *N)
{
		printf("\n\n*******第一步: 从文件读取学生的成绩信息********\n\n");
		Student *stu;//定义一个Student类型的指针

		FILE *fp=NULL;  //指向为空
		fp=fopen("data.txt","r");//只读

		int count=0;      //1用来存学生数目
		int index=0;

		if(fp!=NULL)
		{
			fscanf(fp,"%3d",&count);
			*N=count;
		}
		else
		{
			printf("无法打开此文件");
			exit(0);
		}
		getchar();
		printf("学生的数目为:%3d",count);
		getchar();
		//给所有学生分配存储空间;
		stu=(Student*)malloc(count*sizeof(Student));

		//读取每条学生的信息
		while((!feof(fp))&&(index<count))
		{
			//读入文件
			fscanf(fp,"%s%s %d %d %d\n",(stu[index].number),(stu[index].name),&stu[index].common_score,&stu[index].experiment_score,&stu[index].final_score);
			//输出学生信息
			printf("*%s   平时成绩：%d  实验成绩：%d   期末成绩：%d",(stu[index].number),stu[index].common_score,stu[index].experiment_score,stu[index].final_score);
			printf("\n");
			index++;
		}
			


		fclose(fp);

     	return stu;//返回开辟的首地址
}


//2、计算各个学生的最终成绩
void count_score(Student stu[],int N)
{
		printf("\n*******第二步: 计算每个学生的总评成绩*******\n");
		for(int j=0;j<N;j++)
		{
			stu[j].score=0.2*stu[j].common_score+0.2*stu[j].experiment_score+0.6*stu[j].final_score;
			printf("*%s      期末成绩:%f\n",stu[j].number,stu[j].score);
		}
}

//3、根据最终成绩排名
int  cmpBigtoSmall(const void *a, const void *b)
{

	Student *aa = (Student *)(a);
	Student *bb = (Student *)(b);



	if ((*aa).score < (*bb).score)  return 1;

	else if ((*aa).score > (*bb).score)  return -1;

	else
		return 0;

}
void sort_score(Student stu[], int N)
{
	printf("\n*******第三步：根据最终成绩排名******\n");

	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

}
//4、输出学生信息
void printmassage(Student stu[], int N)
{
		printf("\n******第四步: 根据总成绩输出学生排名信息*******\n");
		for(int k=0;k<N;k++)
		{
			printf("第%3d名信息    %s    总成绩:%4.2f分\n",k+1,stu[k].number, stu[k].score);
		}
}
//5、计算学生成绩的均值和方差
void ave_fangcha(Student stu[], int N)
{
	printf("\n*******第五步: 计算均值和方差*********\n");
	
	double Averg,s;
	Averg=1.0*(stu[0].score+stu[1].score+stu[2].score+stu[3].score+stu[4].score+stu[5].score)/N;
	s=1.0*(pow(stu[0].score-Averg,2)+pow(stu[1].score-Averg,2)+pow(stu[2].score-Averg,2)+pow(stu[3].score-Averg,2)+pow(stu[4].score-Averg,2)+pow(stu[5].score-Averg,2))/N;
	printf("均值为：%lf  方差为：%lf",Averg,s);
}

main()
{
	printf("******************************\n");
	printf("      学生成绩管理分析系统       \n");
	printf("            REN            \n");
	printf("******************************\n\n");


	int N=0;

	Student *stu=NULL;

	stu=readDataFromFile(&N);
	count_score(stu,N);
	sort_score(stu,N);
	printmassage(stu,N);
	ave_fangcha(stu,N);

	free(stu);

	printf("\n");
	system("pause");
}