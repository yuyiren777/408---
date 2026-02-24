#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // 使用bool类型需要引入此头文件

#define MAX_LEN 100

//定义栈的结构体
typedef struct {
	int data[MAX_LEN];
	int top;
}stack;
//初始化栈
void init_stack(stack* s) {
	s->top = -1;
}
//判断栈是否为空
bool is_null(stack* s) {
	return s->top == -1;
}
//判断栈是否已满
bool is_full(stack* s) {
	return s->top + 1 == MAX_LEN;
}
//入栈操作
int push_in(stack* s, int elem) {
	if (is_full(s)) {
		printf("栈已满，无法放入\n");
		return 0;
	}
	s->data[++s->top] = elem;
	printf("已经将元素%d放入\n", elem);
	return 1;
}
//出栈操作
int pop_out(stack* s, int* value) {
	if (is_null(s)) {
		printf("栈已空\n");
		return 0;
	}
	*value = s->data[s->top--];
	return 1;
}
//获取栈顶元素
int get_top(stack* s, int* top) {
	if (is_null(s)) {
		printf("栈已空\n");
		return 0;
	}
	*top = s->data[s->top];
	return 1;
}
//得知当前栈中元素的个数
int num_of_stack(stack* s) {
	return s->top + 1;
}
//清空栈
void delete_stack(stack* s) {
	s->top = -1;
	printf("栈已经清空\n");
}
//遍历栈
void print_(stack* s) {
	if (is_null(s)) {
		printf("栈已经空\n");
		return;
	}
	for (int i = s->top; i >= 0; i--) {
		printf(" %d\n", s->data[i]);
	}
}

int main() {
	stack s;
	int value;
	init_stack(&s);

	//往栈中压入数据
	push_in(&s, 10);
	push_in(&s, 20);
	push_in(&s, 30);
	printf("入栈10、20、30后，栈大小：%d\n", num_of_stack(&s));
	print_(&s);
	//获取栈顶元素
	if (get_top(&s, &value)) {
		printf("栈顶元素是%d\n", value);
	}
	//出栈
	if (pop_out(&s, &value)) {
		printf("%d已经出栈\n", value);
	}
	print_(&s);
	//清空栈
	delete_stack(&s);
	return 0;
}