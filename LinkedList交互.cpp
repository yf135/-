#include"LinkedList.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void visit(ElemType e);
int main()
{
    int a;
    LinkedList head = NULL,p1;

    do
    {

        printf("请输入您要选择的功能：\n");
        printf("1-创建空链表 2-销毁链表 3-在指定节点后插入数据 4-删除指定节点后第一个数据 5-打印链表 6-查找数据 7-查找数据 8-判断链表是否成环 9-反转链表中的偶数结点 10-查找中间结点 11-退出程序\n");
        scanf_s("%d", &a);
        switch (a)
        {
        case 1://创建空链表
        {
            if (InitList(&head))
            {
                printf("空链表创建成功\n");
            }
            else
            {
                printf("空链表创建失败\n");
            }
            break;
        }
        case 2://销毁链表
        {
            DestroyList(&head);
            printf("链表销毁完成\n");
            break;
        }
        case 3://在指定节点后插入数据
        {
            if (head == NULL)
            {
                printf("链表为空， 请先创建链表\n");
            }
            else
            {
                LinkedList newNode;
                InitList(&newNode);
                printf("请输入数据：");
                scanf_s("%d", &newNode->data);
                printf("请输入你需要在第几个节点后插入数据\n");
                int site, num = 0;
                scanf_s("%d", &site);
                p1 = head;
                while (p1 != NULL) {
                    p1 = p1->next;
                    num++;
                }
                p1 = head;
                if (num < site) { printf("你输入的节点位置大于链表长度,无法插入\n"); break; }
                for (int i = 1; i < site; i++) {
                    p1 = p1->next;
                }
                if (InsertList(p1, newNode))
                {
                    printf("数据插入成功\n");
                }
                else
                {
                    printf("数据插入失败\n");
                }
            }
            break;
        }
        case 4://删除指定节点后第一个数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                printf("你想删除哪个节点后第一个节点的数据：");
                int site, num = 0;
                int e = 0;
                scanf_s("%d", &site);
                p1 = head;
                while (p1 != NULL) {
                    p1 = p1->next;
                    num++;
                }
                num--;
                p1 = head;
                if (num <= site) { 
                    printf("你输入的节点位置大于等于链表长度,无法删除\n"); 
                    break; 
                }
                for (int i = 1; i < site; i++) {
                    p1 = p1->next;
                }
                if (DeleteList(p1, &e))
                {
                    printf("节点删除成功\n");
                    printf("删除的节点数据为%d\n", e);

                }
                else
                {
                    printf("节点删除失败\n");
                }
            }
            break;
        }
        case 5://打印链表
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表不存在或者只存在一个空的头结点\n");
            }
            else
            {
                TraverseList(head,visit);
            }
            break;
        }
        case 6://查找数据
        {   int data;
            printf("请输入你要查找的数据：");
            scanf_s("%d", &data);
            if (SearchList(head, data))
            {
                printf("该数存在\n");
            }
            else
            {
                printf("该数不存在\n");
            }
            break;
        }
        case 7://反转链表
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空或者链表只含有两个结点\n");
                printf("链表反转失败\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("链表反转成功\n");
                }
                else
                {
                    printf("链表反转失败\n");
                }

            }
            break;
        }
        case 8://判断链表是否成环
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空\n");
            }
            else
            {
                if (IsLoopList(head))
                {
                    printf("链表成环\n");
                }
                else
                {
                    printf("链表没有成环\n");
                }
            }
            break;
        }
        case 9://反转链表中的偶数结点
        {
            break;
        }
        case 10://查找中间结点
        {
            if (head == NULL || head->next == NULL)
            {
                printf("这是空链表\n");
            }
            else
            {              
                printf("链表中间储存的值为%d\n", (FindMidNode(&head))->data);
            }
            break;
        }
        case 11://退出程序
        {

            DestroyList(&head);
            break;
        }
        default:
        {
            printf("请重新输入数字！(1-11)\n");
            break;
        }
        }
        system("pause");
        printf("\n");
    } while (a!= 11);

    return 0;
}