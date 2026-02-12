#include<stdio.h>
int main() {
	//int a = 0;
	//int b = 1;
	//int* p = &a;
	//int** pp = &p;
	//printf("%d\n", *p);
	//printf("%d\n", **pp);
	//*pp = &b;
	//printf("%d\n", *p);
	//printf("%d\n", **pp);
	//
	//int arr[] = { 1,2,3,4,5 };
	//int len = sizeof(arr) / sizeof(int);
	////int* g = arr;
	////printf("%p", g);
	//int* g1 = arr;
	///*printf("%d", *(g1 + 3));*/
	//for (int i = 0; i < len; i++) {
	//	printf("%d", *g1);
	//	g1++;
	//}
	////一，不带指针的数组遍历方式
	//int arr_1[5] = {1,2,3,4,5};
	//int arr_2[4] = { 3,2,7,8 };
	//int arr_3[6] = { 5,4,1,7,8,9 };
	//int* arr[3] = { arr_1,arr_2,arr_3 };
	//int len1 = sizeof(arr_1) / sizeof(int);
	//int len2 = sizeof(arr_2) / sizeof(int);
	//int len3 = sizeof(arr_3) / sizeof(int);
	//int arr_len[] = { len1,len2,len3 };
	//for (int j = 0; j < 3; j++) {
	//	for (int i = 0; i < arr_len[j]; i++) {
	//		printf("%d ", arr[j][i]);
	//	}
	//}

	////二，带指针的数组遍历方式（1
	//int arr1[5] = { 1,2,3,4,5 };
	//int arr2[5] = { 11,22,33,44,55 };
	//int arr3[5] = { 111,2222,333,444,555 };
	////  把三个一维数组的内存地址，再放入到二维
	//int* arr[3] = { arr1, arr2, arr3 };
	//int** p = arr;//int*表示存的东西是指针，第二个*表示指向存地址的内存块的指针
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		printf("%d ", *(*p + j));
	//	}
	//	printf("\n");
	//	p++;
	//}

	//二，带指针的数组遍历方式（2
	int arr[3][5] =
	{
		{1,2,3,4,5},
		{11,22,33,44,55},
		{111,222,333,444,555}
	};
	int(*p)[5] = arr;//p是指向含有五个Int元素的指针，*p是解引用表示含五个int元素的数组，但是会被解
	//析为数组的首个元素的地址
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", *(*p + j));
		}
		printf("\n");
		p++;
	}

}