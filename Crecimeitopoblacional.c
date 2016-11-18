//#include <iostream>
/*Analsis de crecimiento poblacional
usando el algoritmo Runge Kutta
Alumno: Christian Fernandez Robles
*/

#include <math.h>
#include <stdio.h>


double f(double x,double y);
double Pt(double t,double y);
double gama,tetha;

int main(){
    FILE *kutta4;
    FILE *gnuplot=popen("gnuplot -persist.txt","w");
    kutta4=fopen("kutta.txt","w");
    
    
    double y,z,h,y0,y1,t,t2,k[4]={0};
    
    
    printf("INTRODUCE UNA TASA DE  NATALIDAD ");
    scanf("%lf",&gama);
      printf("INTRODUCE UNA TASA DE  MORTALIDAD ");
     scanf("%lf",&tetha);
    printf("Introduce el tamanio de paso:\n");
    scanf("%lf",&h);
    printf("INTRODUCE EL TIEMPO INICIAL:\n");
    scanf("%lf",&t);
    printf("INTRODUCE EL TIEMPO FINAL:\n");
    scanf("%lf",&t2);
  
    printf("Introduce el valor de y(%f)=:\n",t);
    scanf("%lf",&y1);
   
        
        y0=y1;
        y=y0;
        for(z=0;z<=t2;z=z+h){
			
       
                 k[0]=Pt(t,y0);
                  k[1]=Pt(t+(h/2.0),y0+((k[0]*h)/2.0));
                        k[2]=Pt(t+(h/2.0),y0+((k[1]*h)/2.0));
                        k[3]=Pt(t+h,y0+(k[2]*h));
                        y=y+(((k[0]+(2.0*k[1])+(2.0*k[2])+k[3])/6.0)*h);
                 
                        printf("y=%lf    x=%lf\n",y,t);
                        fprintf(kutta4,"%lf\t%lf \n",t+h,y);
                        y0=y;
                        t=t+h;    
               
            }
                     
        
    fclose(kutta4);

        fprintf(gnuplot," plot \"kutta.txt\" w l ti \"orden4\"\n");
         
    /*fprintf(gnuplot," plot \"salidak1.txt\" w l ti \"orden 1\",\"salidak2.txt\" w l ti \"orden2\" "
            ",\"salidak3.txt\" w l ti \"orden3\",\"salidak4.txt\" w l ti \"orden4\""
            ", exp(-a**2/2) w l ti \"analitica\"\n");*/
    pclose(gnuplot);
    return 0;
}


double f(double t,double y){
    float z;
    z=gama*y - (tetha*(y*y));
    return z;

}

double Pt(double t,double y){
    double z;
    z=gama*y - (tetha*(y*y));
    return z;

}


/*double analitica(double t, double y,double y1){
	double analitica;
	double e;
	e=pow(2.71,-gama*t);
		analitica=	gama/(tetha+((gama/y1)-tetha)*e);
		return  analitica;
}*/



