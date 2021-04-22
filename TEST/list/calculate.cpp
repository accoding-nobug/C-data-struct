#include<stdio.h>
#include<math.h>
#include<complex.h>

typedef long long LL;

int main()
{
	double h = 1.7;
	double G = 6.754e-11;
	double c = 3e8;
	double g = 9.8/2;
	double a = 5*g/c/c/c/c,b=10*g*h/c/c, d = 5*g*h*h-2*c*c*h,e=-c*c*c*c*h*h;
	double p = d/a-b*b/3/a/a,q=2*b*b*b/27/a/a/a-b*d/3/a/a+e/a;
	printf("%lf\n",pow((q/2),2)+pow((p/3),3));
	double judge = pow((q/2),2)+pow((p/3),3);
	double y1=-(q/2)+sqrt(judge),y2=-(q/2)-sqrt(judge);
	printf("%.1000lf\n %.1000lf\n %.1000lf\n %.1000lf\n",a,b,d,e);
	printf("%lf",1.0058197881848374e25/G);
//	37230521791154783000000000000000000.000000
//	3.7e34
//148922088863612300000000000000000000.000000
}
