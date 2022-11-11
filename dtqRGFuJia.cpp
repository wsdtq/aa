#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

//使用typedef的好处如果int想改成float 直接改即可后面用的都是 ElemType
typedef int ElemType;

//静态分配  动态分配
typedef struct {
	ElemType data[MaxSize];//定义的数组用来存元素
	int length;//当前顺序表中有多少个元素
} SqList;

//i代表插入的位置，从1开始，e要插入的元素
bool ListInsert(SqList &L, int i, ElemType e) {

	if (i < 1 || i > L.length + 1)//判断要插入的位置是否合法<1 >4  可以放到第三个元素后面 这时候第三个元素挪到后面 但是第一个元素只能放到1上面
	{
		return false;
	}
	if (L.length >= MaxSize)//超出空间了  MaxSize是数组长度  L.len是线性表长度
	{
		return false;
	}
	//移动顺序表中的元素 依次往后移
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//数组下标从零开始 插入第一个位置，访问的下标为0
	L.length++;
	return true;//插入成功
}

//删除使用元素e的引用的目的是拿出对应的值
bool ListDelete(SqList &L, int i, ElemType &e) {
	if (i < 1 || i > L.length)//判断删除位置是否合法
	{
		return false;
	}
	//顺序表内没有元素 无需删除
	if (L.length == 0) {
		return false;
	}
	e = L.data[i - 1];//获取顺序表中对应元素 赋值给e
	for (int j = i; j < L.length; j++)//从i的位置依次把元素往前覆盖
		L.data[j - 1] = L.data[j];
	L.length--;//删除一个元素 顺序表长度减一
	return true;
}

//查找成功 返回位置 位置从1开始 查找失败返回0
int LocateElem(SqList L, ElemType e) {
	int i;
	for (i = 0; i < L.length; i++)//遍历顺序表
		if (L.data[i] == e)
			return i + 1;//加1就是元素在顺序表中的位置
	return 0;//0=false
}

//打印顺序表
void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%4d", L.data[i]);//要求所有元素打印到一排
	}
	printf("\n");
}

int main() {
	SqList L;//顺序表的名称
	bool ret;//查看返回值  bool只有c++有 c语言想用要引用
	ElemType del;//用来存储要删除的元素
	//先手动在顺序表中前3个元素赋值
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;//总计3个元素
	//插入操作  往第二个位置插入60这个元素
	ret = ListInsert(L, 2, 60);
	if (ret) {
		printf("插入成功\n");
		PrintList(L);
	} else {
		printf("插入失败\n");
	}
	//删除操作 删除第一个未知的元素
	ret = ListDelete(L, 1, del);
	if (ret) {
		printf("删除成功\n");
		printf("删除元素值为 %d\n", del);//删除的值放到del里面并打印出来
		PrintList(L);
	} else {
		printf("删除失败\n");
	}
	//找某元素在不在
	ret = LocateElem(L, 60);
	if (ret) {
		printf("查找成功\n");
		printf("元素位置为 %d\n", ret);
	} else {
		printf("查找失败\n");
	}
}

