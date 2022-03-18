#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct
{
    char tenDV[20];
    float TL, GT, DG;
    int PA, SL;
} DoVat;

DoVat *ReadFile(float *W, int *n)
{
    int i = 0;
    FILE *p = fopen("CaiBalo2.inp", "r");
    fscanf(p, "%d", W);
    DoVat *dsdv;
    dsdv = (DoVat *)malloc(sizeof(DoVat));
    while (!feof(p))
    {
        fscanf(p, "%f%f%d%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL, &dsdv[i].tenDV);
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
        dsdv[i].PA = 0;
        i++;
        dsdv = (DoVat *)realloc(dsdv, sizeof(DoVat) * (i + 1));
    }
    *n = i;
    fclose(p);
    return dsdv;
}
void inDS(DoVat *dsdv, int n, float W)
{
	float TongGT=0.0,TongTL=0.0;
    printf("Phuong an:\n");
    printf("|---|-----------------|----------|----------|----------|---------|-----------|\n");
    printf("|STT|   Ten Do Vat    | Tr.luong | Gia Tri  | So Luong | Don Gia | Phuong An |\n");
    printf("|---|-----------------|----------|----------|----------|---------|-----------|\n");
	for(int i=0;i<n;i++)
	{
		printf("|%2d |%-17s|%10.2f|%10.2f|%10d|%9.2f|%11d|\n",i+1,dsdv[i].tenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].SL,dsdv[i].DG,dsdv[i].PA);
		TongGT+=dsdv[i].GT*dsdv[i].PA;
		TongTL+=dsdv[i].TL*dsdv[i].PA;
	}
	printf("|---|-----------------|----------|----------|----------|---------|-----------|\n");
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
