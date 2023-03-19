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

        printf("��������Ҫѡ��Ĺ��ܣ�\n");
        printf("1-���������� 2-�������� 3-��ָ���ڵ��������� 4-ɾ��ָ���ڵ���һ������ 5-��ӡ���� 6-�������� 7-�������� 8-�ж������Ƿ�ɻ� 9-��ת�����е�ż����� 10-�����м��� 11-�˳�����\n");
        scanf_s("%d", &a);
        switch (a)
        {
        case 1://����������
        {
            if (InitList(&head))
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
            DestroyList(&head);
            printf("�����������\n");
            break;
        }
        case 3://��ָ���ڵ���������
        {
            if (head == NULL)
            {
                printf("����Ϊ�գ� ���ȴ�������\n");
            }
            else
            {
                LinkedList newNode;
                InitList(&newNode);
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
                if (InsertList(p1, newNode))
                {
                    printf("���ݲ���ɹ�\n");
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        }
        case 4://ɾ��ָ���ڵ���һ������
        {
            if (head == NULL)
            {
                printf("����δ���������ȴ�������\n");
            }
            else
            {
                printf("����ɾ���ĸ��ڵ���һ���ڵ�����ݣ�");
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
                    printf("������Ľڵ�λ�ô��ڵ���������,�޷�ɾ��\n"); 
                    break; 
                }
                for (int i = 1; i < site; i++) {
                    p1 = p1->next;
                }
                if (DeleteList(p1, &e))
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
        case 5://��ӡ����
        {
            if (head == NULL || head->next == NULL)
            {
                printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
            }
            else
            {
                TraverseList(head,visit);
            }
            break;
        }
        case 6://��������
        {   int data;
            printf("��������Ҫ���ҵ����ݣ�");
            scanf_s("%d", &data);
            if (SearchList(head, data))
            {
                printf("��������\n");
            }
            else
            {
                printf("����������\n");
            }
            break;
        }
        case 7://��ת����
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ�ջ�������ֻ�����������\n");
                printf("����תʧ��\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("����ת�ɹ�\n");
                }
                else
                {
                    printf("����תʧ��\n");
                }

            }
            break;
        }
        case 8://�ж������Ƿ�ɻ�
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ��\n");
            }
            else
            {
                if (IsLoopList(head))
                {
                    printf("����ɻ�\n");
                }
                else
                {
                    printf("����û�гɻ�\n");
                }
            }
            break;
        }
        case 9://��ת�����е�ż�����
        {
            break;
        }
        case 10://�����м���
        {
            if (head == NULL || head->next == NULL)
            {
                printf("���ǿ�����\n");
            }
            else
            {              
                printf("�����м䴢���ֵΪ%d\n", (FindMidNode(&head))->data);
            }
            break;
        }
        case 11://�˳�����
        {

            DestroyList(&head);
            break;
        }
        default:
        {
            printf("�������������֣�(1-11)\n");
            break;
        }
        }
        system("pause");
        printf("\n");
    } while (a!= 11);

    return 0;
}