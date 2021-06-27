/*
	Œ´q•ö‰ó‚Ì•úËü‚Ì‹­‚³‚ÌŒvZ
*/

#include <conio.h>
#include <stdio.h>
#include <math.h>

#define		N0		87.62
#define		M		0.001
#define		T1		2.4528e+05
#define		T2		64

double	calc_lamda(double t);

void	main(void)
{
	double		oya[20],musume[20];				/* ŒvZŒ‹‰Ê */
	static		int	t[20] = { 0, 1, 10, 20, 30, 40, 50, 60, 70, 80,
				 			90,100,110,120,140,160,180,-1};
	double		n10;
	double		lamda1,lamda2;
	double		ntemp;
	double		tsec;
	int i;
	
	n10 = (double)6.0225e+23 * M / N0;
	lamda1 = calc_lamda(T1);
	lamda2 = calc_lamda(T2);
	ntemp = fabs((lamda1 * lamda2) / (lamda1 - lamda2)) * n10;
	
	printf("n10 = %e\n",n10);
	printf("lamda1 = %e  : lamda2 = %e\n",lamda1,lamda2);
	printf("ntemp = %e\n",ntemp);
	
	for(i=0; i<20; i++) {
		if(t[i] < 0) break;
		tsec = (double)((unsigned long)t[i] * 3600 * 24);
		oya[i] = lamda1 * n10 * exp(-lamda1*tsec);
		musume[i] = fabs(ntemp * (exp(-lamda1*tsec)-exp(-lamda2*tsec)));
		printf("%5dday\t%3.3e\t%3.3e\n",t[i],oya[i],musume[i]);
	}
}

double	calc_lamda(double t)
{
	return	0.693 / (t*3600);
}
