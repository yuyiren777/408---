#include <stdio.h>
#include <stdbool.h>  // 包含bool类型的头文件

// 定义静态顺序表的常量和结构
#define MAX_LEN 10
typedef int element;

// 定义顺序表结构
typedef struct {
    element elem[MAX_LEN];  // 静态数组，存储数据元素
    int length;             // 当前有效元素个数
} Linklist;


/*
 * 函数：init_list
 * 功能：初始化顺序表
 * 参数：L - 指向顺序表的指针
 * 说明：将顺序表的长度初始化为0，表示空表
 */
void init_list(Linklist* L) {
    if (L == NULL) {
        printf("错误：传入的顺序表指针为空！\n");
        return;
    }
    L->length = 0;
    printf("顺序表初始化成功！最大容量为%d\n", MAX_LEN);
}

/*
 * 函数：add_tail
 * 功能：在顺序表尾部插入元素
 * 参数：L - 指向顺序表的指针
 *       val - 要插入的值
 * 返回值：0-成功，1-失败
 */
int add_tail(Linklist* L, int val) {
    // 参数检查
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return 1;
    }

    // 检查顺序表是否已满
    if (L->length >= MAX_LEN) {
        printf("顺序表已满（当前容量：%d/%d），无法添加新元素！\n", L->length, MAX_LEN);
        return 1;
    }

    // 在尾部插入元素
    L->elem[L->length] = val;
    L->length++;

    printf("元素 %d 已成功添加到顺序表末尾（当前位置：%d）\n", val, L->length);
    return 0;
}

/*
 * 函数：add_byadress
 * 功能：在指定位置插入元素
 * 参数：L - 指向顺序表的指针
 *       address - 要插入的位置（从1开始计数）
 *       val - 要插入的值
 * 返回值：0-成功，1-失败
 */
int add_byadress(Linklist* L, int address, int val) {
    // 参数检查
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return 1;
    }

    // 检查插入位置是否合法
    if (address < 1 || address > L->length + 1) {
        printf("插入位置 %d 不合法！有效范围为：1 到 %d\n",
            address, L->length + 1);
        return 1;
    }

    // 检查顺序表是否已满
    if (L->length >= MAX_LEN) {
        printf("顺序表已满（当前容量：%d/%d），无法添加新元素！\n",
            L->length, MAX_LEN);
        return 1;
    }

    // 移动元素，为新元素腾出位置
    for (int j = L->length; j >= address; j--) {
        L->elem[j] = L->elem[j - 1];
    }

    // 插入新元素
    L->elem[address - 1] = val;
    L->length++;

    printf("元素 %d 已成功插入到位置 %d\n", val, address);
    return 0;
}

/*
 * 函数：search_pos
 * 功能：按位置查找元素
 * 参数：L - 指向顺序表的指针
 *       pos - 要查找的位置（从1开始计数）
 * 返回值：找到的元素值，如果位置不合法返回-1
 */
int search_pos(Linklist* L, int pos) {
    // 参数检查
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return -1;
    }

    // 检查位置是否合法
    if (pos < 1 || pos > L->length) {
        printf("查找位置 %d 不合法！顺序表当前长度为：%d\n", pos, L->length);
        return -1;
    }

    int ele = L->elem[pos - 1];
    printf("在位置 %d 查找到元素：%d\n", pos, ele);
    return ele;
}

/*
 * 函数：search_ele
 * 功能：按元素值查找位置
 * 参数：L - 指向顺序表的指针
 *       ele - 要查找的元素值
 * 返回值：找到的位置（从1开始计数），如果未找到返回0
 */
int search_ele(Linklist* L, int ele) {
    // 参数检查
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return 0;
    }

    // 遍历查找
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == ele) {
            printf("元素 %d 在顺序表中的位置是：%d\n", ele, i + 1);
            return i + 1;
        }
    }

    printf("未在顺序表中找到元素：%d\n", ele);
    return 0;  // 未找到
}

/*
 * 函数：change_ele
 * 功能：修改指定位置的元素
 * 参数：L - 指向顺序表的指针
 *       pos - 要修改的位置（从1开始计数）
 *       val - 新的元素值
 * 返回值：true-成功，false-失败
 */
bool change_ele(Linklist* L, int pos, int val) {
    // 参数检查
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return false;
    }

    // 检查位置是否合法
    if (pos < 1 || pos > L->length) {
        printf("修改位置 %d 不合法！顺序表当前长度为：%d\n", pos, L->length);
        return false;
    }

    int old_val = L->elem[pos - 1];  // 保存旧值用于显示
    L->elem[pos - 1] = val;

    printf("位置 %d 的元素已从 %d 修改为 %d\n", pos, old_val, val);
    return true;
}

/*
 * 函数：delete_pos
 * 功能：删除指定位置的元素
 * 参数：L - 指向顺序表的指针
 *       pos - 要删除的位置（从1开始计数）
 * 返回值：true-成功，false-失败
 */
bool delete_pos(Linklist* L, int pos) {
    // 参数检查
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return false;
    }

    // 检查位置是否合法
    if (pos < 1 || pos > L->length) {
        printf("删除位置 %d 不合法！顺序表当前长度为：%d\n", pos, L->length);
        return false;
    }

    int deleted_val = L->elem[pos - 1];  // 保存被删除的值用于显示

    // 移动元素，覆盖要删除的位置
    for (int i = pos; i < L->length; i++) {
        L->elem[i - 1] = L->elem[i];
    }

    L->length--;
    printf("位置 %d 的元素 %d 已被成功删除\n", pos, deleted_val);
    return true;
}

/*
 * 函数：delete_ele
 * 功能：删除指定的元素值（只删除第一个匹配项）
 * 参数：L - 指向顺序表的指针
 *       val - 要删除的元素值
 * 返回值：true-成功，false-失败
 */
bool delete_ele(Linklist* L, int val) {
    // 参数检查
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return false;
    }

    // 遍历查找要删除的元素
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == val) {
            int delete_pos = i + 1;  // 记录删除位置用于显示

            // 移动元素，覆盖要删除的位置
            for (int j = i; j < L->length - 1; j++) {
                L->elem[j] = L->elem[j + 1];
            }

            L->length--;
            printf("元素 %d 在位置 %d 已被成功删除\n", val, delete_pos);
            return true;
        }
    }

    printf("未找到元素 %d，删除失败\n", val);
    return false;  // 未找到
}

/*
 * 函数：get_length
 * 功能：获取顺序表当前长度
 * 参数：L - 指向顺序表的指针
 * 返回值：顺序表当前长度
 */
int get_length(Linklist* L) {
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return 0;
    }
    return L->length;
}

/*
 * 函数：is_full
 * 功能：判断顺序表是否已满
 * 参数：L - 指向顺序表的指针
 * 返回值：true-已满，false-未满
 */
bool is_full(Linklist* L) {
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return true;
    }
    return L->length >= MAX_LEN;
}

/*
 * 函数：is_empty
 * 功能：判断顺序表是否为空
 * 参数：L - 指向顺序表的指针
 * 返回值：true-为空，false-不为空
 */
bool is_empty(Linklist* L) {
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return true;
    }
    return L->length == 0;
}

/*
 * 函数：print_list
 * 功能：打印顺序表所有元素
 * 参数：L - 指向顺序表的指针
 */
void print_list(Linklist* L) {
    if (L == NULL) {
        printf("错误：顺序表指针为空！\n");
        return;
    }

    printf("顺序表信息：\n");
    printf("  当前容量：%d/%d\n", L->length, MAX_LEN);

    if (L->length == 0) {
        printf("  顺序表为空\n");
        return;
    }

    printf("  元素列表：[");
    for (int i = 0; i < L->length; i++) {
        printf("%d", L->elem[i]);
        if (i < L->length - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // 显示元素位置索引
    printf("  位置索引： ");
    for (int i = 0; i < L->length; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");
}

/*
 * 函数：show_menu
 * 功能：显示操作菜单
 */
void show_menu() {
    printf("\n===== 顺序表操作菜单 =====\n");
    printf("1. 显示顺序表\n");
    printf("2. 在末尾添加元素\n");
    printf("3. 在指定位置插入元素\n");
    printf("4. 按位置查找元素\n");
    printf("5. 按元素值查找位置\n");
    printf("6. 修改指定位置的元素\n");
    printf("7. 删除指定位置的元素\n");
    printf("8. 删除指定元素值\n");
    printf("9. 获取顺序表长度\n");
    printf("10. 判断顺序表是否为空/满\n");
    printf("0. 退出程序\n");
    printf("===========================\n");
    printf("请选择操作（0-10）：");
}

int main() {
    Linklist L;
    int choice, value, position;

    printf("======= 顺序表演示程序 =======\n");
    printf("顺序表最大容量：%d\n", MAX_LEN);

    // 初始化顺序表
    init_list(&L);

    // 预添加一些示例数据
    int nums[] = { 3, 4, 5, 6, 7 };
    int n = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < n; i++) {
        add_tail(&L, nums[i]);
    }

    printf("\n已添加初始元素：3, 4, 5, 6, 7\n");
    print_list(&L);

    // 演示各种操作
    printf("\n=== 开始演示顺序表操作 ===\n");

    // 演示1：在指定位置插入元素
    printf("\n1. 在位置3插入元素99：\n");
    add_byadress(&L, 3, 99);
    print_list(&L);

    // 演示2：按位置查找
    printf("\n2. 查找位置1的元素：\n");
    int found_ele = search_pos(&L, 1);
    if (found_ele != -1) {
        printf("   查找到的数字是：%d\n", found_ele);
    }

    // 演示3：按元素查找位置
    printf("\n3. 查找元素99的位置：\n");
    int found_pos = search_ele(&L, 99);
    if (found_pos != 0) {
        printf("   要查找的数字在第 %d 位\n", found_pos);
    }

    // 演示4：修改指定位置的元素
    printf("\n4. 将位置3的元素修改为100：\n");
    change_ele(&L, 3, 100);
    print_list(&L);

    // 演示5：按位置删除元素
    printf("\n5. 删除位置3的元素：\n");
    delete_pos(&L, 3);
    print_list(&L);

    // 演示6：按元素值删除
    printf("\n6. 删除元素7：\n");
    delete_ele(&L, 7);
    print_list(&L);

    // 演示7：获取顺序表信息
    printf("\n7. 获取顺序表状态：\n");
    printf("   当前长度：%d\n", get_length(&L));
    printf("   是否为空：%s\n", is_empty(&L) ? "是" : "否");
    printf("   是否已满：%s\n", is_full(&L) ? "是" : "否");

    printf("\n=== 演示结束 ===\n");
    printf("\n最终顺序表状态：\n");
    print_list(&L);

    return 0;
}