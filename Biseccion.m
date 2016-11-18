% Autor: Christian Fernandez Robles
% Materia: Metodo Numerico
% Carrera: Ingeneria en computacion 4to semestre
% Profesor: José Octavio Buenos Aires
% Universidad del Papaloapan campus Loma Bonita

clear
clc
xi=input('masa inicial:');
xf=input('masa final:');
error=100;
datos(2,7)=0;
g=9.81;
ca=0.25;
vel=36;
t=4;
xr=(xf+xi)/2;
xt=0;
i=1;
while(error>0.002)
    fxi=((sqrt((g*xi)/ca))*tanh((sqrt((g*ca)/xi))*t))-vel;
    fxr=((sqrt((g*xr)/ca))*tanh((sqrt((g*ca)/xr))*t))-vel;
    mult=fxi*fxr;
    error=abs(((xr-xt)/xr)*100);
    datos(i,1)=xi;
    datos(i,2)=xf;
    datos(i,3)=xr;
    datos(i,4)=fxi;
    datos(i,5)=fxr;    
    datos(i,6)=mult;
    datos(i,7)=error;
    if(mult>0)
        xi=xr;
    end
    if(mult<0)
        xf=xr;
    end
    i=i+1;
    xt=xr;
    xr=(xf+xi)/2;
end
GuardarArchivo('BiseccionMetodoNum.txt',datos);
