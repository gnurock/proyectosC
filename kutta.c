/*
Algoritmo runge kutta
Alumno:Christian Fernandez Robles
Profesor:Dr. Ivvan Valdez Peña
Segundo Semestre de Ing. Computación
*/
//#include <iostream>
#include <math.h>
#include <stdio.h>


double f(double y,double h);

int main(){
    FILE *k1,*k2,*k3,*k4;
    FILE *gnuplot=popen("gnuplot -persist.txt","w");
    k1=fopen("salidak1.txt","w");
    k2=fopen("salidak2.txt","w");
    k3=fopen("salidak3.txt","w");
    k4=fopen("salidak4.txt","w");
    double x,y,z,i,h,y0,y1,x0,k[4]={0};
    int w;
    printf("Introduce el tamano de paso:\n");
    scanf("%lf",&h);
    printf("Introduce el intervalo:\n");
    scanf("%lf",&x);
    scanf("%lf",&i);
    printf("Introduce el valor de y(%f)=:\n",x);
    scanf("%lf",&y1);
    for(w=1;w<=4;w++){
        x=x0;
        y0=y1;
        y=y0;
        for(z=0;z<=i;z=z+h){
            switch(w){
                case 1: k[w]=f(x,y0);
                        y=y+k[w]*h;
                        printf("y=%lf    x=%lf\n",y,x);
                        fprintf(k1,"%lf\t%lf \n",x+h,y);
                        y0=y;
                        x=x+h;
                        break;
                case 2: k[w-1]=f(x,y0);
                        k[w]=f(x+h,y0+(k[w-1]*h));
                        y=y+((k[w-1]+k[w])/2.0)*h;
                        printf("y=%lf    x=%lf\n",y,x);
                        fprintf(k2,"%lf\t%lf \n",x+h,y);
                        y0=y;
                        x=x+h;
                        break;
                case 3: k[0]=f(x,y0);
                        k[1]=f(x+(h/2.0),y0+((k[0]*h)/2.0));
                        k[2]=f(x+h,y0-(k[0]*h)+((k[1]*2.0)*h));
                        y=y+((k[0]+(4.0*k[1])+k[2])/6.0)*h;
                        fprintf(k3,"%lf\t%lf \n",x+h,y);
                        y0=y;
                        x=x+h;
                        break;

                case 4: k[0]=f(x,y0);
                        k[1]=f(x+(h/2.0),y0+((k[0]*h)/2.0));
                        k[2]=f(x+(h/2.0),y0+((k[1]*h)/2.0));
                        k[3]=f(x+h,y0+(k[2]*h));
                        y=y+(((k[0]+(2.0*k[1])+(2.0*k[2])+k[3])/6.0)*h);
                        fprintf(k4,"%lf\t%lf \n",x+h,y);
                        y0=y;
                        x=x+h;
                        break;
                }
            }
        }
    fclose(k1);
    fclose(k2);
    fclose(k3);
    fclose(k4);
        fprintf(gnuplot," plot \"salidak4.txt\" w l ti \"orden4\""
            ", exp(-x**2/2) w l ti \"analitica\"\n");
    /*fprintf(gnuplot," plot \"salidak1.txt\" w l ti \"orden 1\",\"salidak2.txt\" w l ti \"orden2\" "
            ",\"salidak3.txt\" w l ti \"orden3\",\"salidak4.txt\" w l ti \"orden4\""
            ", exp(-a**2/2) w l ti \"analitica\"\n");*/
    pclose(gnuplot);
    return 0;
}

double f(double h,double y){
    float z;
   z=-h*y;
    return z;

}

