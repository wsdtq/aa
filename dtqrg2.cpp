#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
struct elevator
{
	//������������¥�� 
	int present;

	//����Ҫ����¥��
	int aim;

	//�����ߵ�¥����
	int move;
}lift[4];

	//����Ŀ¼��ʾ
void show(); 

//�˿�ѡ��
int elevator_choice();

//�жϵ���
int elevator_panduan(int now, int future);

//ż�����ҳ������С�ĵ���
int Short1(int ele[], int fu, int nw);

//�������ҳ������С�ĵ���
int Short2(int ele[], int fu, int nw);

//���������Ĳ�ֵ
int Diff(int a, int b);

//�ı��������
int elevator_run(int i, int now, int aim1);

//�������ߺ���
void shuaxin();

void main()
{

	int num = 1;
	while (num == 1)
	{
		show();
		num=elevator_choice();
	}
}
int elevator_choice()
{
	//��ǰ¥����
	int floors;

	//�뵽��Ĳ���
	int aim;
	int num;
	printf("0���ǵ���һ�㣬����Ϊ20��\t|\n");
	printf("********************************|\n");
	printf("��������Ŀǰ���ڵ�¥������");
	scanf_s("%d", &floors);
	if (floors > 20)
		floors = 20;
	printf("���������뵽��Ĳ�����");
	scanf_s("%d", &aim);
	if (aim > 20)
		aim = 20;
	printf("\n");
	num=elevator_panduan(floors, aim);
	return num;
}
int elevator_panduan(int now, int future)
{
	int i, a[3];
	if (now % 2 == 0)
	{
		a[0] = 0; a[1] = 2; a[2] = 3;

		//ż������ʹ�õĵ��ݡ�
		i = Short1(a, future, now);
	}
	else if (now % 2 == 1)
	{
		a[0] = 0; a[1] = 1; a[2] = 3;

		//��������ʹ�õ��ݺš�
		i = Short2(a, future, now);
	}
	printf("��ӭ����%d�ŵ���\n", i + 1);
	int num=elevator_run(i, now, future);
	return num;

}

//�ҳ�ʹ����������1 ��ż��¥�㿪ʼ�ж�
int Short1(int ele[], int fu, int nw)
{

	int min = ele[0];

	int k = Diff(lift[min].present, nw);

	if (fu % 2 == 0)
	{
		for (int i = 1; i < 3; i++)
		{
			if (k > Diff(lift[ele[i]].present, nw))
			{
				k = Diff(lift[ele[i]].present, nw);
				min = ele[i];
			}
		}
		return min;
	}
	if (fu % 2 == 1)
	{
		int y = Diff(lift[3].present, nw);
		if (k > y)
		{
			return 3;

		}
		else
		{
			return 0;

		}
	}
}

//�ҳ�ʹ����������2 ������¥�㿪ʼ�ж�
int Short2(int ele[], int fu, int nw)
{
	int min = ele[0];
	int k = Diff(lift[min].present, nw);
	if (fu % 2 == 1)
	{
		for (int i = 1; i < 3; i++)
		{
			if (k > Diff(lift[ele[i]].present, nw))
			{
				k = Diff(lift[ele[i]].present, nw);
				min = ele[i];
			}
		}
		return min;
	}
	if (fu % 2 == 0)
	{
		int y = Diff(lift[3].present, nw);
		if (k > y)
		{
			return 3;
		}
		else
		{
			return 0;
		}
	}
}

//��ʾ¥��
void show()
{
	system("cls");
	printf("����\t��ǰ¥�� \t״̬\t|\n");
	printf("********************************|\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d\t",i+1);
		printf("%d\t\t", lift[i].present);
		if (lift[i].move>0)
			printf("����\t|\n");
		else if (lift[i].move == 0)
			printf("--\t|\n");
		else printf("--\t|\n");
		printf("********************************|\n");
	}
}

//���
int Diff(int a, int b)
{
	if (a > b)
	{
		return a - b;
	}
	else
	{
		if (a < b)
		{
			return b - a;
		}
	}
}

//���е���
int elevator_run(int i, int now, int aim1)  
{
	lift[i].aim = now;
	lift[i].move = Diff(lift[i].present, lift[i].aim);
	int k = lift[i].move;
	if (k == 0)
	{
		lift[i].aim = aim1;
		lift[i].move = Diff(lift[i].present, lift[i].aim);
		int k = lift[i].move;
	}
	int m = 2;
	while (m == 2)
	{
		show();
		shuaxin();
		printf("���������밴1��ˢ���밴2���˳��밴�����\n");
		scanf_s("%d", &m);

		if (lift[i].move == 0)
		{
			if (lift[i].aim == aim1)
				lift[i].move = 0;
			else
			{
				lift[i].aim = aim1;
				lift[i].move = Diff(lift[i].present, lift[i].aim);
			}
		}
	}
	if (m == 1)
		return 1;
	else
		return 0;
}
void shuaxin()
{
	for (int y = 0; y < 4; y++)
	{
		if (lift[y].aim > lift[y].present)
		{
			lift[y].present++;
			lift[y].move--;
		}
		else if (lift[y].aim < lift[y].present)
		{
			lift[y].present--;
			lift[y].move--;
		}
	}
}