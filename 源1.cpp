#include"标头.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void visit(ElemType e);
int main()
{
    int a;
    DuLinkedList head,p1;
    head = NULL;

    do
    {
        printf("请输入您要选择的功能：\n");
        printf("1-创建空链表 2-销毁链表 3-在指定节点前插入数据 4-在指定节点后插入数据 5-删除指定节点后第一个数据 6-打印链表 7-退出程序\n");
        scanf_s("%d", &a);
        switch (a)
        {
        case 1://创建空链表
        {
            if (InitList_DuL(&head))
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
            DestroyList_DuL(&head);
            printf("链表销毁成功\n");
            break;
        }
        case 3://在指定节点前插入数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("请输入数据：");
                    scanf_s("%d", &newNode->data);
                    printf("请输入你需要在第几个节点前插入数据\n");
                    int site,num=0;
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
                    if (InsertBeforeList_DuL(p1, newNode))
                    {
                        printf("数据插入成功\n");
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                else
                {
                    printf("数据插入失败\n");
                }
            }
            break;
        }
        case 4://在指定节点后插入数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
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
                    if (InsertAfterList_DuL(p1, newNode))
                    {
                        printf("数据插入成功\n");
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                else
                {
                    printf("数据插入失败\n");
                }
            }
            break;
        }
        case 5://删除指定节点后第一个数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                printf("你想删除哪个节点后第一个节点的数据：");
                int site, num = 0;
                ElemType e=0;
                scanf_s("%d", &site);
                p1 = head;
                while (p1 != NULL) {
                    p1 = p1->next;
                    num++;
                }
                p1 = head;
                if (num < site) { printf("你输入的节点位置大于链表长度,无法删除\n"); break; }
                for (int i = 1; i < site; i++) {
                    p1 = p1->next;
                }
                if (DeleteList_DuL(p1, &e))
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
        case 6://遍历链表，打印数据
        {
            TraverseList_DuL(head,visit);
            break;
        }
        case 7://退出程序 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("请重新输入数字!(1-7)\n");
            break;
        }
        }
        system("pause");
        printf("\n");
    } while (a!= 7);

    return 0;
}
