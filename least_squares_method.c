#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	double x[50],xx[50];
	double y[20],xy[50];
	double a,b,ax_b[50],y_ax_b[50],y_ax_b_2[50];
	double sigma_y=0,sigma_x=0,sigma_xx=0,sigma_xy=0,sum_xx=0;
	double zansa_y_2=0,ip_a=0,ip_b=0,miss_y_2;
	int i,t;

	printf("いくつの要素をしらべた？\n");
	scanf("%d",&t);
	printf("xの値\n");
	for(i=0;i<t;i++){
		printf("x[%d] = ",i);
		scanf("%lf",&x[i]);
	}
	printf("yの値\n");
	for(i=0;i<t;i++){
		printf("y[%d] = ",i);
		scanf("%lf",&y[i]);
	}
	
	for(i=0;i<t;i++){
		sigma_x += x[i];
		sigma_y += y[i];
		xy[i] = x[i]*y[i];
		xx[i] = pow(x[i],2);
	}

	sigma_xx = pow(sigma_x,2);

	for(i=0;i<t;i++){
		sigma_xy += xy[i];
		sum_xx += xx[i];
	}

	a = (t*sigma_xy-sigma_x*sigma_y)/(t*sum_xx-sigma_xx);

	b = (sum_xx*sigma_y-sigma_x*sigma_xy)/(t*sum_xx-sigma_xx);

	for(i=0;i<t;i++){
		ax_b[i] = a*x[i]+b;
		y_ax_b[i] = y[i]-(ax_b[i]);
		y_ax_b_2[i] = pow(y_ax_b[i],2);
		zansa_y_2 += y_ax_b_2[i];
	}

	miss_y_2 = (zansa_y_2)/(t-2);

	ip_a = 0.6745*sqrt(miss_y_2*t/(t*sum_xx-sigma_xx));

	ip_b = 0.6745*sqrt(miss_y_2*sum_xx/(t*sum_xx-sigma_xx));

	printf("\nx\t\ty\t\txx\t\txy\t\tax+b\t\ty-(ax+b)\t(y-(ax+b))^2\n");

	for(i=0;i<t;i++){
	printf("%f\t%f\t%f\t%f\t%f\t%f\t%f\n",x[i],y[i],xx[i],xy[i],ax_b[i],y_ax_b[i],y_ax_b_2[i]);
	}
	puts("");

	printf("%f\t%f\t%f\t%f\t\t\t\t\t%f\n",sigma_x,sigma_y,sum_xx,sigma_xy,zansa_y_2);

	printf("%f\n\n\n",sigma_xx);

	printf("a,bの値は\na = %f\nb = %f\n\n\n",a,b);

	printf("yの平均2乗誤差の値の値は\nσy^2 = %f\n",miss_y_2);

	printf("これより、\n\nイプシロンa = %f\nイプシロンb = %f\n\n",ip_a,ip_b);
	//変更する場合以下を変えてください
	printf("よって確率誤差を含めると、\n\na = %.4f±%.4f\nb = %.4f±%.4f\n\n",a,ip_a,b,ip_b);

	return 0;

}
