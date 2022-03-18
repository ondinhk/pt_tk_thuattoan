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
void Swap(DoVat &a, DoVat &b)
{
	DoVat temp;
	temp=a;
	a=b;
	b=temp;
}
void BubbleSort(DoVat *dsdv, int n)
{
	for(int i=0;i<=n-2;i++)
	{
		for(int j=n-1;j>=i+1;j--)
		{
			if(dsdv[j].DG > dsdv[j-1].DG)
				Swap(dsdv[j],dsdv[j-1]);
		}
	}	
}
void inDS(DoVat *dsdv, int n, float W)
{
	float TongGT=0;
	float TongTL=0;
	printf("Phuong an trien khai:\n");
	printf("|STT|	Ten Do Vat	| Tr.luong | Gia tri  | Don Gia  | Phuong An|\n");
	for(int i=0;i<n;i++)
	{
		printf("|%3d|%-19s|%10.2f|%10.2f|%10.2f|%10d|\n",i+1,dsdv[i].tenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].PA);
		TongGT+=dsdv[i].PA*dsdv[i].GT;
		TongTL+=dsdv[i].PA*dsdv[i].TL;
	}
	printf("Tong TL: %f",TongTL);
	printf("\nTong GT: %f",TongGT);
}
void Greedy(DoVat *dsdv, int n, int W)
{
	for(int i=0;i<n;i++)
	{
		dsdv[i].PA=W/dsdv[i].TL;
		W=W-(dsdv[i].PA*dsdv[i].TL);
	}
}
int main()
{
	float W;
	int n;
	DoVat *dsdv;
	dsdv=ReadFile(&W,&n);
	BubbleSort(dsdv,n);
	Greedy(dsdv,n,W);
	inDS(dsdv,n,W);
	
	return 0;
}
