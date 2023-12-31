#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Data
{
    int heSo;
    int soMu;
} Data;

typedef struct Node
{
    Data data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
    Node *tail;
} List;

void init(List *list) //Tao danh sach rong
{
    list->head = NULL;
    list->tail = NULL;
}

Node *getNode(Data *data) // Tao 1 node
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Loi cap phat");
        return NULL;
    }
    p->data = *data;
    p->next = NULL;
    return p;
}

void Insert(List *list, Node *p) //Chen vao cuoi
{
    if (list->head == NULL)
    {
        list->head = p;
        list->tail = p;
    }
    else
    {
        list->tail->next = p;
        list->tail = p;
    } 
}

void nhapData(Data *data)
{
    printf("Nhap he so: ");
    scanf("%d", &data->heSo);
    printf("Nhap so mu: ");
    scanf("%d", &data->soMu);
}

void inThongTin(List *list)
{
    Node *p;
    p = list->head;
    for (Node *k = list->head; k != NULL; k = k->next)
    {
        printf("%dx^%d ", k->data.heSo, k->data.soMu);
        if (k != list->tail)
        {
            printf("+ ");
        }
        p = p->next;
    }
}

void ATTACH(int heSo, int soMu, List *list) // Them he so va luy thua vao danh sach tong
{
    Data data;
    data.heSo = heSo;
    data.soMu = soMu;
    Insert(list, getNode(&data));
}

void PADD(List *list1, List *list2, List *list3)
{
    Node *p = list1->head;
    Node *q = list2->head;
    while (p != NULL && q != NULL) // Ca 2 da thuc van con phan tu
    {
        if (p->data.soMu == q->data.soMu) 
        // ktra luy thua -> nếu bằng nhau thi cộng hệ số và dịch sang trái 
        {   
            int heSo = p->data.heSo + q->data.heSo;
            if (heSo != 0)
            {
                ATTACH(heSo, p->data.soMu, list3);
            }
            p = p->next;
            q = q->next;
        }
        else
        {
            if (p->data.soMu > q->data.soMu)
            // nếu lũy thừa cua đa thức 1 lớn hơn đa thức 2 thì chèn hệ số và lũy thừa vào đa thức tổng
            {   
                ATTACH(p->data.heSo, p->data.soMu, list3);
                p = p->next;
            }
            else
            {
                ATTACH(q->data.heSo, q->data.soMu, list3);
                q = q->next;
            }
        }
    }
    if (q == NULL)
    {
        while (p != NULL)
        {
            ATTACH(p->data.heSo, p->data.soMu, list3);
            p = p->next;
        }
    }
    if (p == NULL)
    {
        while (q != NULL)
        {
            ATTACH(q->data.heSo, q->data.soMu, list3);
            q = q->next;
        }
    }
}

void nhapDaThuc(List *list){
    Data data;
    int action = 0;
    while (1)
    {
        if (action == 1)
        {
            printf("Nhap du lieu: \n");
            nhapData(&data);
            Insert(list, getNode(&data));
        }
        else if (action == 2)
        {
            break;
        }
        printf("1.Nhap lan luot tung gia tri\n");
        printf("2.Thoat\n");
        scanf("%d", &action);
    }
}

int main()
{
    
    List list1;
    List list2;
    List list3;
    // Khoi tao danh sach da thuc 1
    init(&list1);
    printf("Nhap da thuc 1: \n");
    nhapDaThuc(&list1);
    //Khoi tao danh sach da thuc 2
    printf("Nhap da thuc 2: \n");
    init(&list2);
    nhapDaThuc(&list2);
    //In ra danh sach cac da thuc
    printf("Da thuc 1: \n");
    inThongTin(&list1);
    printf("\n");

    printf("Da thuc 2: \n");
    inThongTin(&list2);
    printf("\n");

    init(&list3);
    PADD(&list1, &list2, &list3);
    printf("Tong 2 da thuc 1 va 2: \n");
    inThongTin(&list3);
}
