%Profesor: Jose Octavio Vazquez Buenos Aires
%Fernandez Robles Christian 
%MULLER
%c-4
clear
clc
syms x;



fprintf('\t DR.JOSE OCTAVIO VAZQUEZ BUENOS AIRES \n');
fprintf('\t metodo de muller \n');
ea=1;

disp('f(x)=x*exp(x)-cos(x)+4*x^3-12');
fprintf('\n');
x0=0;
x1=1;
x2=2;
fx=x*exp(x)-cos(x)+4*x^3-12;
it=0;
fprintf('________________________________________________\n');
fprintf('|it \t    |     xr \t     |     eap \t       |\n');
fprintf('------------------------------------------------\n');
while(ea>0.0002)
x=x0;
fx0=eval(fx);
x=x1;
fx1=eval(fx);
x=x2;
fx2=eval(fx);
ho=x1-x0;
h1=x2-x1;
ht=ho+h1;
fxox1=(fx1-fx0)/(ho);
fx1x2=(fx2-fx1)/(h1);
a=(fx1x2-fxox1)/ht;
b=a*h1+fx1x2;
c=fx2;
pos=abs(b+sqrt(b^2-4*a*c));

neg=abs(b-sqrt(b^2-4*a*c));

if(pos>neg)
x3=x2-((2*c)/pos);

else
x3= x2-((2*c)/neg);

end
xr=x3;
ea=abs((xr-x2)/x3);

it=it+1;
eap=(ea*100);
fprintf('|%2d\t         |%4.10f\t |   %4.10f |\n',it,xr,eap);
fprintf('----------------------------------------------- \n');
x0=x1;
x1=x2;
x2=xr;

end

