#include <stdio.h>
#include <math.h>

int main(){

	double x[50],ave_x=0,sum_x=0;
	double d[50],dd[50],sum_dd=0,ip=0;
	int n,i;

	printf("なんこの要素を調べた？？\n");
	scanf("%d",&n);

	for(i=0;i<n;i++){

		printf("x[%d] = ",i);
		scanf("%lf",&x[i]);
		sum_x += x[i];		

	}

	ave_x = sum_x/n;

	for(i=0;i<n;i++){
		d[i] = x[i] - ave_x;
		dd[i] = pow(d[i],2);
		sum_dd += dd[i];
	}

	ip=0.6745*sqrt(sum_dd/(n*(n-1)));
	printf("\nx\t\td\t\td^2\n");
	for(i=0;i<n;i++){
		printf("\n%f\t%f\t%f\n",x[i],d[i],dd[i]);
	}
	puts("");

	printf("平均値は\nave_x = %f\n\n",ave_x);
	
	printf("残差の2乗の和\nd^2 = %f\n\n",sum_dd);

	printf("イプシロンの値は、\nイプシロン = %f\n\n",ip);

	printf("測定結果は、確率誤差を含めると\n\nave_x ± イプシロン = %.3f ± %.3f\n\n",ave_x,ip);

	return 0;

}
