#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

//ʹ��typedef�ĺô����int��ĳ�float ֱ�Ӹļ��ɺ����õĶ��� ElemType
typedef int ElemType;

//��̬����  ��̬����
typedef struct {
	ElemType data[MaxSize];//���������������Ԫ��
	int length;//��ǰ˳������ж��ٸ�Ԫ��
} SqList;

//i��������λ�ã���1��ʼ��eҪ�����Ԫ��
bool ListInsert(SqList &L, int i, ElemType e) {

	if (i < 1 || i > L.length + 1)//�ж�Ҫ�����λ���Ƿ�Ϸ�<1 >4  ���Էŵ�������Ԫ�غ��� ��ʱ�������Ԫ��Ų������ ���ǵ�һ��Ԫ��ֻ�ܷŵ�1����
	{
		return false;
	}
	if (L.length >= MaxSize)//�����ռ���  MaxSize�����鳤��  L.len�����Ա���
	{
		return false;
	}
	//�ƶ�˳����е�Ԫ�� ����������
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;//�����±���㿪ʼ �����һ��λ�ã����ʵ��±�Ϊ0
	L.length++;
	return true;//����ɹ�
}

//ɾ��ʹ��Ԫ��e�����õ�Ŀ�����ó���Ӧ��ֵ
bool ListDelete(SqList &L, int i, ElemType &e) {
	if (i < 1 || i > L.length)//�ж�ɾ��λ���Ƿ�Ϸ�
	{
		return false;
	}
	//˳�����û��Ԫ�� ����ɾ��
	if (L.length == 0) {
		return false;
	}
	e = L.data[i - 1];//��ȡ˳����ж�ӦԪ�� ��ֵ��e
	for (int j = i; j < L.length; j++)//��i��λ�����ΰ�Ԫ����ǰ����
		L.data[j - 1] = L.data[j];
	L.length--;//ɾ��һ��Ԫ�� ˳����ȼ�һ
	return true;
}

//���ҳɹ� ����λ�� λ�ô�1��ʼ ����ʧ�ܷ���0
int LocateElem(SqList L, ElemType e) {
	int i;
	for (i = 0; i < L.length; i++)//����˳���
		if (L.data[i] == e)
			return i + 1;//��1����Ԫ����˳����е�λ��
	return 0;//0=false
}

//��ӡ˳���
void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%4d", L.data[i]);//Ҫ������Ԫ�ش�ӡ��һ��
	}
	printf("\n");
}

int main() {
	SqList L;//˳��������
	bool ret;//�鿴����ֵ  boolֻ��c++�� c��������Ҫ����
	ElemType del;//�����洢Ҫɾ����Ԫ��
	//���ֶ���˳�����ǰ3��Ԫ�ظ�ֵ
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;//�ܼ�3��Ԫ��
	//�������  ���ڶ���λ�ò���60���Ԫ��
	ret = ListInsert(L, 2, 60);
	if (ret) {
		printf("����ɹ�\n");
		PrintList(L);
	} else {
		printf("����ʧ��\n");
	}
	//ɾ������ ɾ����һ��δ֪��Ԫ��
	ret = ListDelete(L, 1, del);
	if (ret) {
		printf("ɾ���ɹ�\n");
		printf("ɾ��Ԫ��ֵΪ %d\n", del);//ɾ����ֵ�ŵ�del���沢��ӡ����
		PrintList(L);
	} else {
		printf("ɾ��ʧ��\n");
	}
	//��ĳԪ���ڲ���
	ret = LocateElem(L, 60);
	if (ret) {
		printf("���ҳɹ�\n");
		printf("Ԫ��λ��Ϊ %d\n", ret);
	} else {
		printf("����ʧ��\n");
	}
}

