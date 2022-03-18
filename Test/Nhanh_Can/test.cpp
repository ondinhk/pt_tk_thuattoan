#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct{
	char tenDV[20];
	float TL,GT,DG;
	int PA;
}DoVat;
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
void inDS(DoVat *dsdv, int n, float W)
{
	printf("Phuong an trien khai:\n");
	printf("|STT|	Ten Do Vat	| Tr.luong | Gia tri | Don Gia | Phuong An|\n");
	for(int i=0;i<n;i++)
	{
		printf("|%d|%14s|%10.2f|%10.ff|%10.2f|%10d|\n",i+1,dsdv[i].tenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].PA);
	}
}
int main()
{
	float W;
	int n;
	DoVat *dsdv;
	dsdv=ReadFile(&W,&n);
	inDS(dsdv,n,W);
	return 0;
}
