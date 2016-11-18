% Grupo: C-4
% Profesor: José Octavio Buenos Aires
% Metodo:Gauss 
% Alumno:Fernandez Robles Christian

fprintf('\n\t\t\tIngrese la matriz de coeficientes  en forma de vector:\n\n')

a=input('                      ');

fprintf('\n\t\t\tIngrese matriz columna de terminos independientes  en forma de vector:\n\n')

b=input('                      ');


fprintf('\n\t\t\t matriz aumentada A|B del sistema es;\n')
n=length(a);
m=size(a);
r=size(b);
if m(2)==r(1)                      %condicion del sistema a(m*n)y b(n*p)
    z=1;
    while z<=(n-1)
        c=a;                      %matriz almacenada para la interaccion z-1                                      
        if a(z,z)~=0
            i=z+1;
            while i<=n            % reduccion por eliminacion gaussiana
                y=z;
                AB=[a,b] 
     
                fprintf('\n\t\t\tEliminar la columna %d a partir de F(%d)\n',z,z)
                fprintf('\n\t\t\tF(%d)-%.4f/%.4f*F(%d)\n',i,c(i,z),c(z,z),z)
                b(i)=b(i)-((c(i,z)/c(z,z))*b(z));    
         
                while y<=n
                    a(i,y)=a(i,y)-((c(i,z)/c(z,z))*a(z,y));
                    y=y+1;
                end
                i=i+1;
            end
        else
            fprintf('\n\t\t\t\t\tEl sistema es inconsistente')
            z=n+1;
        end
        z=z+1;
        c=a;               %matriz alamcenada para la interaccion z
    end
    AB=[a,b] %Matriz aumentada triangulizada
    i=n;
    while i>=1
        d(1,i)=a(i,i);        %diagonal almacenada
        i=i-1;
    end
    e=any(any(d==0));         
    if e==0                   
        fprintf('\n\t\t\t\t\tLos valores de las incognitas son :\n')
        i=n;
        while i>=1
            y=i+1;
            s=0;
            while y<=n
                s=s+(a(i,y)*x(y));  %calculo del sumatorio de los elementos de una fila
                y=y+1;
            end
            x(i)=(b(i)-s)/a(i,i);   %calculo de las incognitas
            fprintf('\n\t\tx(%d) es igual a',i)
            fprintf('\n\t\tx(%d) = (b(%d)-s)/a(%d,%d)',i,i,i,i)
            fprintf('\n\t\tx(%d) = (%.5f - %.5f)/%.5f',i,b(i),s,a(i,i))
            fprintf('\n\t\tx(%d) = %.5f\n\n',i,x(i))
                if i>1
                   
                end
           i=i-1; 
        end
    else
       fprintf('\n\t\t\t\t\tEl sistema  no tiene solucion o tiene soluciones infinitas')
  
    
   end
else
    fprintf('\n\t\t\t\t\tImposible resolver el sistema ingresado falta argumentos,')
   
end
