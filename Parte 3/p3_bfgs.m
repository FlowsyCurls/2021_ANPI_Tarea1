function p3_bfgs()
  clc; clear; 
  %Se escogio la funcion Sphere Function como funcion de prueba
  f= " x1^2 + x2^2 + x3^2 + x4^2 + x5^2";
  x0 = 1; %Valor inicial
  tol=10^-5; %Tolerancia
  iterMax=1000; %Numero de iteraciones maximas
  
  %Se inicializa el vector x0 con numeros random
  x0 = [];
  for i=1:5
    x0 = [x0 randi(10)];
  endfor
  
  
  [xk iter error]= bfgs(f, x0, tol, iterMax)
  
end


function [xk iter error] = bfgs(f_str, x0,  tol, iterMax)
    %
    % FUncion que aproxima el minimo de una funcion dada utilizando el metodo 
    % BFGS
    %
    % Sintaxis:  [xk k error]= bgs(f_str, tol, iterMax)
    % 
    % Parametros Iniciales: 
    %            f_str = una  cadena de caracteres (string) que representa a la funcion f
    %            tol = un numero positivo que representa a la tolerancia para el criterio |f(xk)|<tol
    %            iterMax = cantidad de iteraciones maximas
    %            
    % Parametros de Salida:                           
    %            xk = aproximacion del cero de la funcion f
    %            iter = numero de iteraciones realizados
    %            error =  |g(xk)|
    %
    %
    %%%% Se debe instalar el paquete Symbolic
    %%%% Paso 1: Descargar el archivo symbolic-win-py-bundle-2.9.0.tar.gz
    %%%%         de la pagina https://github.com/cbm755/octsympy/releases
    %%%% Paso 2: Escribir en la Venta de Comandos de Octave la instruccion
    %%%%         pkg install symbolic-win-py-bundle-2.9.0.tar.gz  
    
    %%% Cargar el paquete symbolic
    warning('off', 'all');
    pkg load symbolic
    syms x1 x2 x3 x4 x5;
    v_sym = [x1 , x2, x3 ,x4, x5];
    f= matlabFunction(sym(f_str));
    n = length(x0);

    
    %Se declaran las constantes
    sigma1 = 0.4;
    rho = 0.8;
    alpha = 0.7;
    epsilon = 0.2;
    lambda = 1;
    
    

    
    
    Bk = eye(n,n); %Se inicializa la matrix Bk como una matriz identidad 
    
    
    %Se calcula el gradiente
    g = gradient(sym(f_str), v_sym);
    g_n = matlabFunction(g);
    gk = g_n(x0(1), x0(2), x0(3), x0(4), x0(5));
    
    
    %Se inicializa el vector xk
    xk = transpose(x0);
    
    
    iter = 1;
    err = [];
    
    
    while (iter <= iterMax)
      
      
      %Se calcula el valor de pk
      pk = inv(Bk)*-gk;
      
      
      i = 0;
      for (k=0:iterMax)
        %Se calcula el nuevo valor de lambda
        lambda = rho^i;
        f_izq = f(xk(1)+lambda*pk(1), xk(2)+lambda*pk(2), xk(3)+lambda*pk(3), xk(4)+lambda*pk(4), xk(5)+lambda*pk(5));
        f_der = f(xk(1), xk(2), xk(3), xk(4), xk(5)) + sigma1*lambda*transpose(gk)*pk;
        i = i+1;
        
        %Se detiene cuando se cumple la condición f(xk + lambda*pk) <= f(xk) + sigma*lambda*gk'*pk
        if (f_izq <= f_der) 
          break;
        endif
        
        
      endfor
      
         
    
      xk_1 = xk;
      xk = xk + lambda*pk; %Se calcula el nuevo valor de xk
     
      gk_1 = gk;  
      gk = g_n(xk(1), xk(2), xk(3), xk(4), xk(5)); %Se calcula el nuevo valor de gk
    
    
      %Se calcula los valores de sk, yk y sus respectivas transpuestas
      sk = xk - xk_1;
      yk = gk - gk_1;
      
      yk_t = transpose(yk);
      sk_t = transpose(sk);

      
      
      %Se calcula la condiciones que debe cumplirse para actualizar Bk 
      izq = (yk_t * sk) / norm(sk)^2;
      der = alpha*(norm(gk))^epsilon;
      
      if (izq >= der) %Se verifica la condicion de actualizacion de Bk
        Bk = Bk - (Bk*sk*sk_t*Bk)/(sk_t*Bk*sk) + (yk*yk_t)/(yk_t*sk); %Se actualiza Bk
      endif
    
    
    
      %Se calcula el error como la norma del gradiente evaluado en xk 
      error = norm(gk);
      err = [err error];
    
    
      %Se verifica el punto de parada donde el error debe ser menor que la tolerancia
      if (error < tol)  
             break;
      endif
       
      iter += 1;
       
 
  endwhile
  
  %Graficacion
  plot(0:length(err)-1,err,'g','LineWidth',2)
  title('Metodo BFGS: Iteraciones vrs Error Relativo')
  xlabel('Iteraciones (iter)')
  ylabel('Error Relativo (|g(xk)|)')
    
end
  