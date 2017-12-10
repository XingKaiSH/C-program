/* 请在 Visual C++ 6.0 环境下运行 */
/*   Turbo C 2.0 环境下无法运行   */
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "windows.h"
#define  Limit 10

/* 函数声明 */
void gotoxy(int x,int y);
void    sign();
void  finish();
void   input();
void  output();
void process();
void    sort();
void  demand();
void     del();
void  search();
void   sheet();
void    menu();
int    query();
float average(int x);
/* 函数声明 */

struct singer			//结构体
{
	int   age;		//年龄
	char  ID[15];		//编号
	char  name[15];		//姓名
	char  sex [15];		//性别
	char  tel[15];		//电话
	float score[5];		//评分
}player[Limit];




int Num=0;
void main()//main函数
{
	char option;
	sign();
	while(1)
	{
		menu();
		do
		{option=getch(),fflush(stdin);}
		while(option!='1'&&option!='2'&&option!='3'&&option!='0');
		if(option=='0')
		{break;}
		else switch(option)
		{
			case '1':
			{input();break;}
			case '2':
			{process();break;}
			case '3':
			{search();break;}
		}
	}
	finish();
}



void sign()//署名
{
	system("mode con cols=40 lines=10");
	gotoxy(4,1);
	printf("本程序为 《歌手比赛成绩管理系统》");
	gotoxy(7,3);
	printf("制作人：测控1703班-王思衡");
	gotoxy(9,5);
	printf("制作日期：2017年12月");
	gotoxy(11,8);
	printf("按任意键进入程序");
	gotoxy(27,8);
	getch(),fflush(stdin);
}

void finish()//结束框
{
	system("cls");
	system("mode con cols=40 lines=20");
	gotoxy(13,1);
	printf("感谢您的使用！\n\n");
	printf("         __..._.-. \n");
	printf("        /.-.   '-.) \n");
	printf("        \\',       \\ \n");
	printf("         |       o'--D\n");
	printf("         \\      /    |\n");
	printf("          ;._  _\\ '-/\n");
	printf("        .'    __ `\\`.-'-. .-'-.\n");
	printf("      .'    .'  '.|'     '     ',\n");
	printf("     /      \\     '._,          |\n");
	printf("    ;        '-._     \\         /\n");
	printf("   (|           /'-.__/       .'\n");
	printf("    \\  __     ,'     '-.   .-'\n");
	printf("     `/  `\\.-'|         '.'\n");
	printf("      |    |  '-.\n");
	printf("      |    '-.   )\n");
	printf("      \\       )-'\n");
	printf("       '-----' ");
	gotoxy(27,1);
	Sleep(3000);
}

void input()//输入数据
{
	int i,k;
	char j;
	system("cls");
	gotoxy(25,2);
	printf("您已选择：录入数据");
	gotoxy(19,7);
	printf("按‘1’清空全部数据并重新录入 ");
	gotoxy(19,10);
	printf("按‘2’可添加一名新的歌手信息 ");
	gotoxy(19,17);
	printf("按‘0’即可返回主菜单     ");
	gotoxy(0,0);
	while(1)
	{
		do
		{j=getch(),fflush(stdin);}
		while(j!='1'&&j!='2'&&j!='0');
		switch(j)
		{
			case '1':
			{
				system("cls");
				printf("\n              ◆请输入要录入的人数(大于0,小于等于%d)   ",Limit);
				scanf("%d",&Num),fflush(stdin);
				while(1)
				{
					if(Num>Limit||Num<=0)
					{
						printf("\n                输入数据不合法，请重新输入!   ");
						scanf("%d",&Num),fflush(stdin);
					}
					else
					{break;}
				}
				sheet();
				for(i=0;i<Num;i++)
				{
					gotoxy(2,i*2+3);
					scanf("%s",player[i].ID),fflush(stdin);
					gotoxy(13,i*2+3);
					scanf("%s",player[i].name),fflush(stdin);
					gotoxy(26,i*2+3);
					scanf("%s",player[i].sex),fflush(stdin);
					gotoxy(34,i*2+3);
					scanf("%d",&player[i].age),fflush(stdin);
					gotoxy(42,i*2+3);
					scanf("%s",player[i].tel),fflush(stdin);
					for(k=0;k<5;k++)
					{
						gotoxy(68+7*k,i*2+3);
						scanf("%f",&player[i].score[k]),fflush(stdin);
					}
					gotoxy(106,i*2+3);
					printf("%.1f",average(i));
				}
				gotoxy(34,26);
				printf("恭喜！录入完成！请按任意键返回主菜单   ");
				getch(),fflush(stdin);
				system("cls");
				break;
			}
			case '2':
			{
				system("cls");
				if(Num>=Limit)
				{
					gotoxy(17,6);
					printf("歌手信息已满%d条，无法继续录入   ",Limit);
					gotoxy(19,10);
					printf("请按任意键返回主菜单   ");
					getch(),fflush(stdin);
					break;
				}
				printf("\n请输入歌手编号:          ");
				scanf("%s",player[Num].ID),fflush(stdin);
				printf("\n请输入歌手姓名:          ");
				scanf("%s",player[Num].name),fflush(stdin);
				printf("\n请输入歌手性别:          ");
				scanf("%s",player[Num].sex),fflush(stdin);
				printf("\n请输入歌手年龄:          ");
				scanf("%d",&player[Num].age),fflush(stdin);
				printf("\n请输入歌手电话号码:      ");
				scanf("%s",player[Num].tel),fflush(stdin);
				printf("\n");
				for(i=0;i<5;i++)
				{
					printf("请输入歌手评委 %d 评分:   ",i+1);
					scanf("%f",&player[Num].score[i]),fflush(stdin);
				}
				printf("\n\n恭喜！录入完成！请按任意键返回主菜单 ");
				Num+=1;
				gotoxy(0,0);
				getch(),fflush(stdin);
				break;
			}
			case '0':
			{break;}
		}
		break;
	}
}

void output()//输出数据
{
	int i,j;
	sheet();
	for(i=0;i<Num;i++)
	{
		gotoxy(2,i*2+3);
		printf("%s",player[i].ID);
		gotoxy(13,i*2+3);
		printf("%s",player[i].name);
		gotoxy(26,i*2+3);
		printf("%s",player[i].sex);
		gotoxy(34,i*2+3);
		printf("%d",player[i].age);
		gotoxy(42,i*2+3);
		printf("%s",player[i].tel);
		for(j=0;j<5;j++)
		{
			gotoxy(68+7*j,i*2+3);
			printf("%.1f",player[i].score[j]);
		}
		gotoxy(106,i*2+3);
		printf("%.1f",average(i));
	}
}

void process()//数据处理
{
	char j;
	output();
	gotoxy(17,27);
	printf("<   1.数据排序           2.数据修改          3.数据删除          0.结束浏览   >");
	gotoxy(43,25);
	printf("按对应数字键执行对应操作");
	do
	{j=getch(),fflush(stdin);}
	while(j!='1'&&j!='2'&& j!='3'&&j!='0');
	switch(j)
	{
		case '1':
		{sort();break;}
		case '2':
		{demand();break;}
		case '3':
		{del();break;}
		case '0':
		{break;}
	}
}

void sort()//数据排序
{
	int i,j;
	struct singer vocalist;
	for(i=0;i<Num-1;i++)
	{
		for(j=0;j<Num-1-i;j++)
		{
			if(average(j)>average(j+1))
			{
				vocalist=player[j];
				player[j]=player[j+1];
				player[j+1]=vocalist;
			}
		}
	}
	process();
}

void demand()//数据修改
{
	int i;
	system("cls");
	output();
	gotoxy(45,25);
	printf("请输入待修改的歌手姓名   ");
	i=query();
	if(i==-1)
	{
		gotoxy(45,27);
		printf("查无此人，按任意键退出");
		getch(),fflush(stdin);
	}
	else
	{
		gotoxy(35,27);
		printf("您希望修改%s的电话号码，请输入修改后的电话号码：   ",player[i].name);
		scanf("%s",player[i].tel);
		gotoxy(45,31);
		printf("修改成功！按任意键返回");
		getch(),fflush(stdin);
	}	
		process();
}

void del()//数据删除
{
	int i,k;
	char j;
	system("cls");
	output();
	gotoxy(45,25);
	printf("请输入待删除信息的歌手姓名   ");
	i=query();
	if(i==-1)
	{
		gotoxy(47,27);
		printf("查无此人，按任意键退出");
		getch(),fflush(stdin);
	}
	else
	{
		gotoxy(40,27);
		printf("您希望删除%s的所有信息，是否确认?(Y/N)：   ",player[i].name);
		do
		{j=getch(),fflush(stdin);}
		while(j!='Y'&&j!='y'&&j!='N'&&j!='n');
		if(j=='Y'||j=='y')
		{
			for(i;i<Num;i++)
			{
				for(k=0;k<=15;k++)
				{
				player[i].ID[k]=player[i+1].ID[k];
				player[i].name[k]=player[i+1].name[k];
				player[i].sex[k]=player[i+1].sex[k];
				player[i].tel[k]=player[i+1].tel[k];
				}
				player[i].age=player[i+1].age;
				for(k=0;k<5;k++)
				{
				player[i].score[k]=player[i+1].score[k];
				}
			}
			Num-=1;
			gotoxy(45,31);
			printf("删除成功！按任意键返回");
			getch(),fflush(stdin);
		}
	}
	process();
}

void search()//数据查询
{
	int i;
	system("cls");
	gotoxy(20,8);
	printf("请输入待查询的歌手姓名   ");
	i=query();
	if(i==-1)
	{
		gotoxy(20,12);
		printf("查无此人，按任意键退出");
		getch(),fflush(stdin);
	}
	else
	{
		system("cls");
		printf("以下为该歌手的全部信息\n\n");
		printf("编号:        %s\n\n",player[i].ID);
		printf("姓名:        %s\n\n",player[i].name);
		printf("性别:        %s\n\n",player[i].sex);
		printf("年龄:        %d\n\n",player[i].age);
		printf("电话号码:    %s\n\n",player[i].tel);
		printf("评委评分:\n");
		printf("︿\n");
		printf("①:          %.1f\n",player[i].score[0]);
		printf("②:          %.1f\n",player[i].score[1]);
		printf("③:          %.1f\n",player[i].score[2]);
		printf("④:          %.1f\n",player[i].score[3]);
		printf("⑤:          %.1f\n",player[i].score[4]);
		printf("﹀\n");
		printf("平均成绩：   %.1f          请按‘Enter’键退出   ",average(i));
		getchar(),fflush(stdin);
	}
}

void sheet()//打印表格
{
	int i;
	system("mode con cols=117 lines=33");
	system("cls");
	printf("┏----------------------------------------------------------------------------------------------------------------┓\n");
	printf("┃  编号   |    姓名    | 性别 | 年龄 |     电话号码     |  评分：<  ①  |  ②  |  ③  |  ④  |  ⑤  > | 平均成绩 ┃\n");
	for(i=0;i<Num;i++)
	{
	printf("┃----------------------------------------------------------------------------------------------------------------┃\n");
	printf("┃         |            |      |      |                  |        <      |      |      |      |      > |          ┃\n");
	}
	printf("┗----------------------------------------------------------------------------------------------------------------┛\n");
}

void menu()//打印菜单
{
	system("mode con cols=70 lines=22");
	printf("          **************************************************\n");
	printf("          *                                  ___   ___     *\n");
	printf("          *                  ◆ 菜单 ◆     ( @ \\Y/ @ )    *\n");
	printf("          *                                  \\__+|+__/     *\n");
	printf("          *                                   {_/ \\_}      *\n");
	printf("          *                  1.录入数据                    *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                  2.显示数据                    *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                  3.查找数据                    *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *                                                *\n");
	printf("          *       ____()()   0.退出程序                    *\n");
	printf("          *      /      @@                                 *\n");
	printf("          *`~~~~~\\_;m__m._>o                               *\n");
	printf("          **************************************************\n");
	printf("\n             注：排序、修改、删除功能集成在显示数据功能内   ");
	gotoxy(13,20);
}

void gotoxy(int x,int y)//光标移动
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

int query()//姓名检索
{
	char name[15];
	int i;
	gets(name),fflush(stdin);
	for(i=0;i<Num;i++)
	{
		if(strcmp(name,player[i].name)==0)
		{return i;}
	}
	return -1;
}

float average(int x)//求平均成绩
{
	int i=0;
	float add=0,max=player[x].score[0],min=player[x].score[0];
	for(i=0;i<5;i++)
	{
		add+=player[x].score[i];
		if(player[x].score[i]>max)
		{max=player[x].score[i];}
		if(player[x].score[i]<min)
		{min=player[x].score[i];}
	}
	return (add-max-min)/3;
}

