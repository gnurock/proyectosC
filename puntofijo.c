/*
Algoritmo de punto_fijo
Christian Fernandez Robles
Computacin tercer semestre
 * 
 * 
 */


#include <stdio.h>
#include <math.h>
int main(int argc, char **argv)
{

	float Eap,xr,xranterior,xi/*, g=9.81,ca=0.25,t=4,v=36*/;
	  FILE *fp;
	  int i=1;
	  Eap=100;
	  xi=-200;
	  xranterior=0;
	  fp = fopen("puntofijo.txt", "w"); 
	  fprintf(fp,"# \t xr \t\t Eap\n");
	  while(Eap>0.0000000005){
		   xr=(xi-2.71934054)*(-xi-0.9193405);
		  //xr=xi-(cos(xi)-log(-xi));
		 //xr=-(xi*xi); 
		//xr=xi-(((sqrt((g*xi)/ca))*tanh((sqrt((g*ca)/xi))*t))-v);
         Eap=(((xr-xranterior)/xr)*100);
         if(Eap<0){			  
			  Eap=Eap*-1;
			
			  }
         fprintf(fp,"%d) %.10f\t%.10f\n",i,xr,Eap);
         
		 xranterior=xr;
         xi=xr; 
         i++;
   }
   fclose(fp);
   printf("ver el archivo puntofijo.txt");
	return 0;
}

