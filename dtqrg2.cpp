#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct floor {
	//�����ߵ�¥����
	int floor_number;
	//����Ҫ����¥��
	int will_floor;
	//������������¥�� 
	int now_floor;
} array[4];

//����Ŀ¼��ʾ
void directory();

//�˿�ѡ��
int floor_choice();

//�жϵ���
int floor_judge(int now, int future);

//ż�����ҳ������С�ĵ���
int even(int ele[], int future, int now);

//�������ҳ������С�ĵ���
int odd(int ele[], int future, int now);

//���������Ĳ�ֵ
int disparity(int a, int b);

//�ı��������
int floor_run(int i, int now, int will_floor1);

//�������ߺ���
void fresh();

int main() {
	int number = 1;
	while (number == 1) {
		directory();
		number = floor_choice();
	}
}

int floor_choice() {
	//��ǰ¥����
	int floors;
	//�뵽��Ĳ���
	int will_floor;
	int num;
	printf("0���ǵ���һ�㣬����Ϊ20��\t|\n");
	printf("-------------------------------|\n");
	printf("��������Ŀǰ���ڵ�¥������");
	scanf("%d", &floors);
	if (floors > 20)
		floors = 20;
	printf("���������뵽��Ĳ�����");
	scanf("%d", &will_floor);
	if (will_floor > 20)
		will_floor = 20;
	printf("\n");
	num = floor_judge(floors, will_floor);
	return num;
}

int floor_judge(int now, int future) {
	int i, a[3];
	if (now % 2 == 0) {
		a[0] = 0;
		a[1] = 2;
		a[2] = 3;
		//ż������ʹ�õĵ��ݡ�
		i = even(a, future, now);
	} else if (now % 2 == 1) {
		a[0] = 0;
		a[1] = 1;
		a[2] = 3;

		//��������ʹ�õ��ݺš�
		i = odd(a, future, now);
	}
	printf("��ӭ����%d�ŵ���\n", i + 1);
	int num = floor_run(i, now, future);
	return num;

}

//�ҳ�ʹ����������1 ��ż��¥�㿪ʼ�ж�
int even(int ele[], int future, int now) {
	int min = ele[0];
	int k = disparity
		(array[min].now_floor, now);

	if (future % 2 == 0) {
		for (int i = 1; i < 3; i++) {
			if (k > disparity

				(array[ele[i]].now_floor, now)) {
					k = disparity

						(array[ele[i]].now_floor, now);
					min = ele[i];
			}
		}
		return min;
	}
	if (future % 2 == 1) {
		int y = disparity

			(array[3].now_floor, now);
		if (k > y) {
			return 3;

		} else {
			return 0;

		}
	}
}

//�ҳ�ʹ����������2 ������¥�㿪ʼ�ж�
int odd(int ele[], int future, int now) {
	int min = ele[0];
	int k = disparity
		(array[min].now_floor, now);
	if (future % 2 == 1) {
		for (int i = 1; i < 3; i++) {
			if (k > disparity
				(array[ele[i]].now_floor, now)) {
					k = disparity
						(array[ele[i]].now_floor, now);
					min = ele[i];
			}
		}
		return min;
	}
	if (future % 2 == 0) {
		int y = disparity
			(array[3].now_floor, now);
		if (k > y) {
			return 3;
		} else {
			return 0;
		}
	}
}

//��ʾ¥��
void directory() {
	printf("����\t��ǰ¥�� \t״̬\t|\n");
	printf("---------------------------|\n");
	for (int i = 0; i < 4; i++) {
		printf("%d\t", i + 1);
		printf("%d\t\t", array[i].now_floor);
		if (array[i].floor_number > 0)
			printf("����\t|\n");
		else if (array[i].floor_number == 0) {
			printf("-------\t|\n");

		} else {
			printf("--------\t|\n");
		}
		printf("---------------------------|\n");
	}
}

//���
int disparity(int number1, int number2) {
	if (number1 > number2) {
		return number1 - number2;
	} else {
		if (number1 < number2) {
			return number2 - number1;
		}
	}
}

//���е���
int floor_run(int i, int now, int will_floor1) {
	array[i].will_floor = now;
	array[i].floor_number = disparity

		(array[i].now_floor, array[i].will_floor);
	int k = array[i].floor_number;
	if (k == 0) {
		array[i].will_floor = will_floor1;
		array[i].floor_number = disparity

			(array[i].now_floor, array[i].will_floor);
		int k = array[i].floor_number;
	}
	int number = 2;
	while (number == 2) {
		directory();
		fresh();
		printf("���������밴1��ˢ���밴2���˳��밴�����\n");
		scanf("%d", &number);
		if (array[i].floor_number == 0) {
			if (array[i].will_floor == will_floor1)
				array[i].floor_number = 0;
			else {
				array[i].will_floor = will_floor1;
				array[i].floor_number = disparity

					(array[i].now_floor, array[i].will_floor);
			}
		}
	}
	if (number == 1) {
		return 1;
	} else {
		return 0;
	}
}

void fresh() {
	for (int i = 0; i < 4; i++) {
		if (array[i].will_floor > array[i].now_floor) {
			array[i].now_floor++;
			array[i].floor_number--;
		} else if (array[i].will_floor < array[i].now_floor) {
			array[i].now_floor--;
			array[i].floor_number--;
		}
	}
}