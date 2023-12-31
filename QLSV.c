#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char hoTen[30];
    int tuoi;
    double diemTB;
} SinhVien;

void nhapSinhVien(SinhVien *sv)
{
    printf("Nhap ho ten: ");
    gets(sv->hoTen);
    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);
    printf("Nhap diem trung binh: ");
    scanf("%lf", &sv->diemTB);
}

typedef struct Tnode
{
    SinhVien data;
    struct Tnode *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} DSLK;

void khoiTaoDSLK(DSLK *pList)
{
    pList->head = NULL;
    pList->tail = NULL;
}

Node *taoNodeMoi(SinhVien *sv)
{
    Node *N = (Node*)malloc(sizeof(Node));
    strcpy(N->data.hoTen, sv->hoTen);
    N->data.tuoi = sv->tuoi;
    N->data.diemTB = sv->diemTB;
    N->next = NULL;
    return N;
}

void themVaoCuoiDSLK(DSLK *pList, Node *pNode)
{
    if(pList->head == NULL)
    {
        pList->head = pNode;
        pList->tail = pNode;
    }
    else
    {
        pList->tail->next = pNode;
        pList->tail = pNode;
    }
}

void themVaoGiuaDSLK(DSLK *pList, Node *pNode, char key[])
{
    Node *tmp = pList->head;
    while(strcmp(tmp->data.hoTen, key) != 0 && tmp != NULL)
    {
        tmp = tmp->next;
    }
    if(strcmp(tmp->data.hoTen, key) == 0 && tmp != NULL)
    {
        if(tmp->next == NULL)
            themVaoCuoiDSLK(pList, pNode);
        else
        {
            pNode->next = tmp->next;
            tmp->next = pNode;
        }
    }
}

Node *NodeLT;

Node *timKiemNode(DSLK *pList, char key[])
{
    NodeLT = NULL;
    Node *tmp = pList->head;
    while(tmp != NULL)
    {
        if(strcmp(tmp->data.hoTen, key) == 0)
            return tmp;
        NodeLT = tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void xoaPTkhoiDSLK(DSLK *pList, char key[])
{
    Node *tmp = timKiemNode(pList, key);
    if(tmp != NULL)
    {
        if(tmp == pList->head)
        {
            pList->head = tmp->next;
            if(pList->head == NULL)
                pList->tail == NULL;
        }
        else if(tmp == pList->tail)
        {
            pList->tail = NodeLT;
            NodeLT->next = NULL;
        }
        else
        {
            NodeLT->next = tmp->next;
        }
    }
    free(tmp);
}

void suaPTtrongDSLK(DSLK *pList, SinhVien *sv)
{
    Node *tmp = timKiemNode(pList, sv->hoTen);
    if(tmp != NULL)
    {
        tmp->data.tuoi = sv->tuoi;
        tmp->data.diemTB = sv->diemTB;
    }
    else
    {
        printf("Khong tim thay thong tin sinh vien can sua!!!\n");
    }
}

void taoDanhSach(DSLK *pList)
{
    int T, t;
    printf("Nhap so sinh vien muon them: ");
    scanf("%d", &T);
    for(t = 0; t < T; t++)
    {
        printf("Nhap thong tin sinh vien thu %d:\n", t + 1);
        fflush(stdin);
        SinhVien sv;
        nhapSinhVien(&sv);
        themVaoCuoiDSLK(pList, taoNodeMoi(&sv));
    }
}

void themSinhVien(DSLK *pList)
{
    SinhVien sv;
    printf("Nhap thong tin sinh vien muon them:\n");
    fflush(stdin);
    nhapSinhVien(&sv);
    printf("Them vao sau sinh vien co ma sinh vien la: ");
    fflush(stdin);
    char key[10];
    gets(key);
    themVaoGiuaDSLK(pList, taoNodeMoi(&sv), key);
}

void xoaMotSinhVien(DSLK *pList)
{
    char key[10];
    fflush(stdin);
    printf("Nhap ma sinh vien cua sinh vien muon xoa: ");
    gets(key);
    xoaPTkhoiDSLK(pList, key);
}

void suaMotSinhVien(DSLK *pList)
{
    SinhVien sv;
    fflush(stdin);
    printf("Nhap ho ten cua sinh vien can sua:: ");
    gets(sv.hoTen);
    printf("Nhap tuoi cua sinh vien can sua: ");
    scanf("%d", &sv.tuoi);
    printf("Nhap diem trung binh cua sinh vien can sua: ");
    scanf("%lf", &sv.diemTB);
    suaPTtrongDSLK(pList, &sv);
}

void sapXepSinhVien(DSLK *pList)
{
    Node *i, *j;
    for(i = pList->head; i != pList->tail->next; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->data.diemTB > j->data.diemTB)
            {
                SinhVien tam = i->data;
                i->data = j->data;
                j->data = tam;
            }
        }
    }
}

void inDanhSach(DSLK *pList)
{
    printf("\t\tDANH SACH SINH VIEN\n");
    char a[] = "STT", b[] = "Ho Ten", c[] = "Tuoi", d[] = "Diem TB";
    printf("%s%15s%20s%15s\n", a, b, c, d);
    int i = 1;
    Node *tmp = pList->head;
    while(tmp != pList->tail->next)
    {
        printf("%d%15s%20d%15.2f\n", i, tmp->data.hoTen, tmp->data.tuoi, tmp->data.diemTB);
        tmp = tmp->next;
        i++;
    }
    printf("\n");
}

int menu()
{
    printf("MENU:\n");
    printf("1. Tao Danh Sach Sinh Vien\n");
    printf("2. In Danh Sach Sinh Vien\n");
    printf("3. Them Mot Sinh Vien\n");
    printf("4. Xoa Mot Sinh Vien\n");
    printf("5. Sua Mot Sinh Vien\n");
    printf("6. Sap Xep Danh Sach Sinh Vien\n");
    printf("7. Ket thuc\n");
    printf("Hay nhap su lua chon cua ban: ");
    int n;
    scanf("%d", &n);
    return n;
}

int main()
{
    DSLK *pList = (DSLK*)malloc(sizeof(DSLK));
    khoiTaoDSLK(pList);
    int so;
    while(1)
    {
        so = menu();
        switch(so)
        {
        case 1:
            taoDanhSach(pList);
            break;
        case 2:
            inDanhSach(pList);
            break;
        case 3:
            themSinhVien(pList);
            inDanhSach(pList);
            break;
        case 4:
            xoaMotSinhVien(pList);
            inDanhSach(pList);
            break;
        case 5:
            suaMotSinhVien(pList);
            inDanhSach(pList);
            break;
        case 6:
            sapXepSinhVien(pList);
            inDanhSach(pList);
            break;
        case 7:
            printf("Hoan Tat!!!\n");
            exit(0);
        default:
            printf("Lua chon cua ban khong hop le, lam on hay nhap lai!!!\n");
        }
    }
}
