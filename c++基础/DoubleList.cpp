#include <iostream>
#include <unistd.h>
namespace Double_list
{

};
using namespace std;
using namespace Double_list;
typedef struct double_list_t
{
    int data;
    struct double_list_t *next;
    struct double_list_t *pre;
} node_t;

// 创建节点,并初始化
node_t *create_node();

// 查找节点
node_t *find(int data, node_t *head);

// 插入节点
node_t *inser_head_node(node_t *pre);

// 删除节点
node_t *rm_node(node_t *head);

// 遍历节点
void print_list(node_t *head);

node_t *create_node()
{
    node_t *new_node = new node_t;
    new_node->data = -1;
    new_node->next = new_node;
    new_node->pre = new_node;
    return new_node;
}

node_t *inser_head_node(node_t *pre)
{
    if (pre == NULL)
    {
        cout << "链表不存在" << endl;
        return NULL;
    }
    node_t *new_node = create_node();
    cout << "请输入插入节点数据" << endl;
    cin >> new_node->data;

    new_node->next = pre->next;
    new_node->pre = pre;
    pre->next->pre = new_node;
    pre->next = new_node;

    cout << "插入成功" << endl;
    return new_node;
}

node_t *rm_node(node_t *head)
{
    if (head == NULL)
    {
        cout << "链表不存在" << endl;
        return NULL;
    }
    int data;
    cout << "输入删除节点数据" << endl;
    cin >> data;
    if (head->next == head)
    {
        cout << "链表为空" << endl;
        return NULL;
    }
    else
    {
        node_t *rmnode = find(data, head);
        if (rmnode == NULL)
        {
            cout << "删除节点数据有误" << endl;
            return NULL;
        }

        rmnode->pre->next = rmnode->next;
        rmnode->next->pre = rmnode->pre;
        rmnode->next = NULL;
        rmnode->pre = NULL;
        delete rmnode;
        cout << "删除节点数据成功" << endl;
    }
}

node_t *find(int data, node_t *head)
{
    if (head == NULL)
    {
        cout << "链表不存在" << endl;
    }

    node_t *temp = head->next;
    while (1)
    {
        if (temp->next == temp || temp->data == -1)
        {

            break;
        }
        if (temp->data == data)
        {
            cout << "找到了" << endl;
            return temp;
        }
        temp = temp->next;
    }
    cout << "没找到" << endl;
    return NULL;
}

// 遍历节点
void print_list(node_t *head)
{
    if (head == NULL)
    {
        cout << "链表不存在" << endl;
    }
    node_t *temp = head->next;
    while (1)
    {
        if (temp->next == temp || temp->data == -1)
        {
            break;
        }
        cout << "节点数据：" << temp->data << endl;
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    node_t *list_head = create_node();
    list_head->data = -1;
    while (1)
    {
        system("clear");
        cout << "请选择操作" << endl;
        cout << "1、插入节点" << endl;
        cout << "2、删除节点" << endl;
        cout << "3、查找节点" << endl;
        cout << "4、遍历节点" << endl;
        cout << "5、推出" << endl;
        int op;
        cin >> op;

        switch (op)
        {
        case 1:
            inser_head_node(list_head);
            sleep(2);
            break;
        case 2:
            rm_node(list_head);
            sleep(2);
            break;
        case 3:
            int data;
            cout << "输入查找节点数据" << endl;
            cin >> data;
            find(data, list_head);
            sleep(2);
            break;
        case 4:
            print_list(list_head);
            sleep(2);
            break;
        case 5:
            return 0;

        default:
            break;
        }
    }

    return 0;
}
