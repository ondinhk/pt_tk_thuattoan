#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
    char tenDV[20];
    float TL, GT, DG;
    int PA;
} DoVat;

//Doc file
DoVat *ReadFile(float *W, int *n)
{
    FILE *f = fopen("CaiBalo1.INP", "r");
    fscanf(f, "%f", W);
    DoVat *dsdv;
    dsdv = (DoVat *)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f))
    {
        fscanf(f, "%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].tenDV);
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
        dsdv[i].PA = 0;
        i++;
        dsdv = (DoVat *)realloc(dsdv, sizeof(DoVat) * (i + 1));
        printf("a");
    }
    *n = i;
    fclose(f);
    return dsdv;
}
void Swap(DoVat *a, DoVat *b)
{
    DoVat temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//SapXep
void BubbleSort(DoVat *dsdv, int n)
{
    int i, j;
    for (i = 0; i <= n - 2; i++)
    {
        for (j = n - 1; j >= i + 1; j--)
        {
            if (dsdv[j].DG > dsdv[j - 1].DG)
                Swap(&dsdv[j], &dsdv[j - 1]);
        }
    }
}
void InDSDV(DoVat *dsdv, int n, float W)
{
    int i;
    float TongTL = 0.0, TongGT = 0.0;
    printf("\nPhuong an Cai Ba lo 1 dung thuat toan *Tham An* nhu sau:\n");
    printf("---------------------------------------------------------------------\n");
    printf("|STT|	Ten Do Vat	| TrongLuong | Gia Tri | Don Gia | Phuong An| \n");
    printf("---------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("|%2d |%-18s |%12.2f|%9.2f|%9.2f|%9d |\n",
               i + 1, dsdv[i].tenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }
    printf("---------------------------------------------------------------------\n");
    printf("Trong luong cua balo: %.2f \n", W);
    printf("Tong trong luong:%10.2f\n", TongTL);
    printf("Tong gia tri: %14.2f\n", TongGT);
    printf("Phuong an X=(");
    for (i = 0; i < n; i++)
    {
        printf("%d", dsdv[i].PA);
        if (i < n - 1)
        {
            printf(",");
        }
    }
    printf(")");
}
//ThamAn
void Greedy(DoVat *dsdv, int n, float W)
{
    int i;
    for (i = 0; i < n; i++)
    {
        dsdv[i].PA = (W / dsdv[i].TL);
        W = W - dsdv[i].PA * dsdv[i].TL;
    }
}
int main()
{
    int n;
    float W;
    DoVat *dsdv;
    dsdv = ReadFile(&W, &n);
    BubbleSort(dsdv, n);
    Greedy(dsdv, n, W);
    InDSDV(dsdv, n, W);
    free(dsdv);
    return 0;
}
