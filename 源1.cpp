#include"��ͷ.h"
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
        printf("��������Ҫѡ��Ĺ��ܣ�\n");
        printf("1-���������� 2-�������� 3-��ָ���ڵ�ǰ�������� 4-��ָ���ڵ��������� 5-ɾ��ָ���ڵ���һ������ 6-��ӡ���� 7-�˳�����\n");
        scanf_s("%d", &a);
        switch (a)
        {
        case 1://����������
        {
            if (InitList_DuL(&head))
            {
                printf("���������ɹ�\n");
            }
            else
            {
                printf("��������ʧ��\n");
            }
            break;
        }
        case 2://��������
        {
            DestroyList_DuL(&head);
            printf("�������ٳɹ�\n");
            break;
        }
        case 3://��ָ���ڵ�ǰ��������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("���������ݣ�");
                    scanf_s("%d", &newNode->data);
                    printf("����������Ҫ�ڵڼ����ڵ�ǰ��������\n");
                    int site,num=0;
                    scanf_s("%d", &site);
                    p1 = head;
                    while (p1 != NULL) {
                        p1 = p1->next;
                        num++;
                    }
                    p1 = head;
                    if (num < site) { printf("������Ľڵ�λ�ô���������,�޷�����\n"); break; }
                    for (int i = 1; i < site; i++) {
                        p1 = p1->next;
                    }
                    if (InsertBeforeList_DuL(p1, newNode))
                    {
                        printf("���ݲ���ɹ�\n");
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        }
        case 4://��ָ���ڵ���������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("���������ݣ�");
                    scanf_s("%d", &newNode->data);
                    printf("����������Ҫ�ڵڼ����ڵ���������\n");
                    int site, num = 0;
                    scanf_s("%d", &site);
                    p1 = head;
                    while (p1 != NULL) {
                        p1 = p1->next;
                        num++;
                    }
                    p1 = head;
                    if (num < site) { printf("������Ľڵ�λ�ô���������,�޷�����\n"); break; }
                    for (int i = 1; i < site; i++) {
                        p1 = p1->next;
                    }
                    if (InsertAfterList_DuL(p1, newNode))
                    {
                        printf("���ݲ���ɹ�\n");
                    }
                    else
                    {
                        printf("���ݲ���ʧ��\n");
                    }
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        }
        case 5://ɾ��ָ���ڵ���һ������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                printf("����ɾ���ĸ��ڵ���һ���ڵ�����ݣ�");
                int site, num = 0;
                ElemType e=0;
                scanf_s("%d", &site);
                p1 = head;
                while (p1 != NULL) {
                    p1 = p1->next;
                    num++;
                }
                p1 = head;
                if (num < site) { printf("������Ľڵ�λ�ô���������,�޷�ɾ��\n"); break; }
                for (int i = 1; i < site; i++) {
                    p1 = p1->next;
                }
                if (DeleteList_DuL(p1, &e))
                {
                    printf("�ڵ�ɾ���ɹ�\n");
                    printf("ɾ���Ľڵ�����Ϊ%d\n", e);

                }
                else
                {
                    printf("�ڵ�ɾ��ʧ��\n");
                }
            }
            break;
        }
        case 6://����������ӡ����
        {
            TraverseList_DuL(head,visit);
            break;
        }
        case 7://�˳����� 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("��������������!(1-7)\n");
            break;
        }
        }
        system("pause");
        printf("\n");
    } while (a!= 7);

    return 0;
}
