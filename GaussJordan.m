

% Computacion 4tosemeste
% Profesor: DR.José Octavio Buenos Aires
% Alumno: Fernandez Robles Christian
% Metodo:Gauss Jordan
clc
fprintf('\n\t\t\tIngrese la matriz de coeficientes  en forma de vector:\n\n')
aa=input('                      ');

fprintf('\n\t\t\tIngrese matriz columna de terminos independientes  en forma de vector:\n\n')
bb=input('                      ');

A=[aa,bb];
fprintf('\n\t\t\t\t\tLa matriz aumentada A|B del sistema es;\n')
A;

[m,n] = size(A);
i = 1;
j = 1;
k = 0;
tol = max([m,n])*eps*norm(A,'inf'); 
while (i <= m) & (j <= n)
   [p,z] = max(abs(A(i:m,j))); z = z+i-1;
   if (p <= tol)
      fprintf(['\n\n\t\t\t\t  Columna ' int2str(j) ' es insignificante'])
      A(i:m,j) = zeros(m-i+1,1)
      j = j + 1;
   else
      if i ~= z
         % intercambio de filas
         fprintf(['\n\n\t\t\t\tCambiar filas ' int2str(i) ' y ' int2str(z) blanks(10)])
         fprintf('\n\n')
         A([i z],:) = A([z i],:)

        
      end
      % reconstruir
      fprintf('\n\n\t\t\t\tEliminando columna %d\n',j)
      fprintf(['\n\t\t\t\ta partir de la referencia en A(' int2str(i) ',' int2str(j) ')' blanks(10)])
      fprintf('\n\n\t\t\t\tA(%d,%d)/%0.5f\n',i,j,A(i,j))
      A(i,j:n) = A(i,j:n)/A(i,j)
     
      fprintf(['\n\n\t\t\t\tEliminando la columna ' int2str(j) blanks(10)])
      fprintf('\n')
A;
      for z = 1:m
         if z ~= i
            fprintf('\n')
            fprintf('\n\n\tFila[%d]=Fila[%d] - (A[%d,%d]/A[%d,%d])*Fila[%d]\n',z,z,z,j,i,j,j)
            A(z,j:n) = A(z,j:n) - A(z,j)*A(i,j:n)
         end
      end
      i = i + 1;
      j = j + 1;
   end
end

   fprintf('\n\n\t\t\tLos valores encontrados son;\n')
      for z = 1:m
            fprintf('\n\n\tx(%d)=%d\n',z,A(z,n))
          
      end

