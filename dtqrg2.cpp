#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct floor {
	//电梯走的楼层数
	int floor_number;
	//电梯要到的楼层
	int will_floor;
	//电梯现在所在楼层 
	int now_floor;
} array[4];

//电梯目录显示
void directory();

//乘客选择
int floor_choice();

//判断电梯
int floor_judge(int now, int future);

//偶数层找出相差最小的电梯
int even(int ele[], int future, int now);

//奇数层找出相差最小的电梯
int odd(int ele[], int future, int now);

//求两个数的差值
int disparity(int a, int b);

//改变电梯运行
int floor_run(int i, int now, int will_floor1);

//电梯行走函数
void fresh();

int main() {
	int number = 1;
	while (number == 1) {
		directory();
		number = floor_choice();
	}
}

int floor_choice() {
	//当前楼层数
	int floors;
	//想到达的层数
	int will_floor;
	int num;
	printf("0层是地下一层，顶层为20层\t|\n");
	printf("-------------------------------|\n");
	printf("请输入你目前所在的楼层数：");
	scanf("%d", &floors);
	if (floors > 20)
		floors = 20;
	printf("请输入你想到达的层数：");
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
		//偶数返回使用的电梯。
		i = even(a, future, now);
	} else if (now % 2 == 1) {
		a[0] = 0;
		a[1] = 1;
		a[2] = 3;

		//奇数返回使用电梯号。
		i = odd(a, future, now);
	}
	printf("欢迎乘坐%d号电梯\n", i + 1);
	int num = floor_run(i, now, future);
	return num;

}

//找出使用哪辆电梯1 从偶数楼层开始判断
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

//找出使用哪辆电梯2 从奇数楼层开始判断
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

//显示楼层
void directory() {
	printf("电梯\t当前楼层 \t状态\t|\n");
	printf("---------------------------|\n");
	for (int i = 0; i < 4; i++) {
		printf("%d\t", i + 1);
		printf("%d\t\t", array[i].now_floor);
		if (array[i].floor_number > 0)
			printf("上行\t|\n");
		else if (array[i].floor_number == 0) {
			printf("-------\t|\n");

		} else {
			printf("--------\t|\n");
		}
		printf("---------------------------|\n");
	}
}

//求差
int disparity(int number1, int number2) {
	if (number1 > number2) {
		return number1 - number2;
	} else {
		if (number1 < number2) {
			return number2 - number1;
		}
	}
}

//运行电梯
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
		printf("乘坐电梯请按1，刷新请按2，退出请按任意键\n");
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