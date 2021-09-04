#ifndef FUN_TRAS_H
#define FUN_TRAS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>


/**
 * Parte 1: Librería FunTras(C++)
 * 
 * Se debe instalar la biblioteca boot
 * Paso 1: Ejecutar los siguientes comandos ->  sudo apt-get updade
 *                                              sudo apt-get install libboost-all-dev
 * 
 */



using namespace boost::multiprecision;
cpp_dec_float_50 tol = 0.00000001;
int iterMax = 5000;

/**
* Implementacion de la funcion factorial
* 
* Paramatros de entrada 
*          - x : argumento de la funcion. Numero del factorial que se desea calcular 
* 
* Parametros de salida:
*          - res : resultado final. 
*
*/


cpp_dec_float_50 factorial(int x)
{
    
    int temp = 1; 
    cpp_dec_float_50 res = 1.;

    if (x < 0) //En caso de que el argumento sea menor que cero, no existe un factorial 
    {
        std::cout << "Argumento invalido para calcular el factorial" << "\n";
    }

    else if (x == 0) //Verfica que el caso especial de factorial de 0, retorna 1
    {
        return 1;
    }

    else {

        //Calculo del factorial
         for(int i = 1; i <= x; ++i) 
        {
            res *= i; 
        }

        return res; 



    }


}



// --------------------------- funcion x^-1 -----------------------------------------

cpp_dec_float_50 div_ta(cpp_dec_float_50 a)
{
    cpp_dec_float_50 eps = 2.2204E-16;
    cpp_dec_float_50 x0;

    cpp_dec_float_50 fac20 = factorial(20);
    cpp_dec_float_50 fac40 = factorial(40);
    cpp_dec_float_50 fac60 = factorial(60);
    cpp_dec_float_50 fac80 = factorial(80);
    cpp_dec_float_50 fac100 = factorial(100);


    if (0 < a <= fac20)
    {
        x0 = pow(eps, 2);
    }

    if (fac20 < a <= fac40)
    {
        x0 = pow(eps, 4);
    }

    if (fac40 < a <= fac60)
    {
        x0 = pow(eps, 8);
    }

    if (fac60 < a <= fac80)
    {
        x0  = pow(eps, 11);
    }

    if (fac80 < a <= fac80)
    {
        x0 = pow(eps, 15);
    }


    cpp_dec_float_50 x1, error = tol + 1;
    int k = 0; 

 
    while(error > tol && k <= iterMax){
        x1 = x0*(2-a*x0); 
        error = abs((x1 - x0)/x1); 
        x0 = x1;
        k++; 
    }



    return x1;
}





// -------------------------- exponencial base e -------------------------------------


/**
* Aproximacion de la funciones exponencial de base e 
* 
* Paramatros de entrada 
*          - x : argumento de la funcion cos
* 
* Parametros de salida:
*          - sk1 : resultado final. 
*/

cpp_dec_float_50 exp_t(cpp_dec_float_50 x)
{


    int n = 2;
    cpp_dec_float_50 sk = 1; //Se define el valor inicial de sk
    cpp_dec_float_50 sk1 = sk + x; //Se define el valor inicial de sk+1
    int k = 1;
    cpp_dec_float_50 error = tol + 1;
    
    while (error >= tol && k <= iterMax )
    {
        sk = sk1;

        cpp_dec_float_50 fact = factorial(n);
        cpp_dec_float_50 d = div_ta(fact); 

        sk1 += pow(x, n) * d; //Se calcula el nuevo valor de sk1

        error = fabs(sk1 - sk);
        n++;
    }

    return sk1;   
}



//------------------------------- funcion sin(x) ------------------------------------


/**
* Aproximacion de la funcion sen(x)
* 
* Paramatros de entrada 
*          - x : argumento de la funcion cos
* 
* Parametros de salida:
*          - sk1 : resultado final. 
*/


cpp_dec_float_50 sin_t(cpp_dec_float_50 x)
{


    int n  = 0;
    cpp_dec_float_50 sk = 0; //Se define el valor inicial de sk
    cpp_dec_float_50 sk1 =0; //Se define el valor inicial de sk+1
    int k = 1;
    cpp_dec_float_50 error = tol + 1;


   
    while (error >= tol && k <= iterMax)
    {
        sk = sk1; //Se asgina el nuevo valor de sk 
        int arg = 2*n + 1;

        cpp_dec_float_50 fact = factorial(arg);
        cpp_dec_float_50 d = div_ta(fact);

        sk1 += pow(-1,n)*(pow(x, arg) * d);//Se calcula el nuevo valor de sk1
        error = fabs(sk1 - sk); //Se calcula el error
        k++;
        n++;
    }

    return sk1;   
}



//------------------------------- funcion cos(x) ------------------------------------



/**
* Aproximacion de la funcion cos(x)
* 
* Paramatros de entrada 
*          - x : argumento de la funcion cos
* 
* Parametros de salida:
*          - sk1 : resultado final. 
*/



cpp_dec_float_50 cos_t(cpp_dec_float_50 x)
{


    int n = 0;
    cpp_dec_float_50 sk = 0; //Se define el valor inicial de sk
    cpp_dec_float_50 sk1 = 0; //Se define el valor inicial de sk+1
    int k = 1;
    cpp_dec_float_50 error = tol + 1;


    while (error >= tol && k <= iterMax)
    {
        sk = sk1; //Se asigna el nuevo valor de sk
        int arg = 2*n;

        cpp_dec_float_50 fact = factorial(arg);
        cpp_dec_float_50 d = div_ta(fact);

        sk1 += pow(-1,n)*(pow(x, arg) * d); //Se calcula el nuevo valor de xk1
        error = fabs(sk1 - sk);
        k++;
        n++;
    }


    return sk1;  

}


//------------------------------- funcion tan(x) ------------------------------------


/**
* aproximacion de la funcion tangente. Se reescribe la funcion en terminos 
* de senos y cosenos y se utilizan las funciones anteriormente implementadas
* 
* Paramatros de entrada 
*          - x : argumento de la funcion tangente
* 
* 
* 
*/

cpp_dec_float_50 tan_t(cpp_dec_float_50 x)
{

    cpp_dec_float_50 cos = cos_t(x); //Se calcula el valor de cos(x) 
    cpp_dec_float_50 d = div_ta(cos); //Se calcula su inverso 

    return sin_t(x) * d; // Multiplica por el sen(x) obteniendo el valor de la tangente. 

}




//------------------------------- funcion ln(x) ------------------------------------

/**
* Aproximacion de la funcion logaritmo natural.
* 
* Paramatros de entrada 
*          - a : argumento de la funcion logaritmo, debe estrictamente mayor que cero 
* 
* Parametros de salida:
*          - sk1 : resultado final.
* 
* 
*/


cpp_dec_float_50 ln_t(cpp_dec_float_50 x)
{


    if (x<=0) //Verifica dominio de la funcion logaritmo
    {
        printf("Argument invalido, el numero debe ser mayor que 0");
        return NULL;

    }

    int n = 0;
    cpp_dec_float_50 sk = 0; //Se define el valor inicial de sk
    cpp_dec_float_50 sk1 = 0; //Se define el valor inicial de sk+1
    int k = 1;
    cpp_dec_float_50 error = tol + 1;


    
    while (error >= tol && k <= iterMax)//Parametros de parada 
    {
        sk = sk1;

        cpp_dec_float_50 d1 = div_ta(x + 1);
        cpp_dec_float_50 d2 = div_ta(2.*n + 1);

        sk1 += (2.*(x-1) * d1)*((d2)* pow(((x-1) * d1), 2*n)); //Aproximacion del nuevo sk1
        error = fabs(sk1 - sk); //Calculo del error
        n++; //aumenta el exponente

    }

    return sk1;  
}






//------------------------------- funcion log(x) ------------------------------------



/**
* aproximacion de la funcion logaritmo utilizado la base dada por el usuario. Se reescribe 
* la expresion en terminos de logaritmo natual para utilizar la funcion anteriormente 
* implementada. 
* 
* Paramatros de entrada 
*          - x : argumento de la funcion logaritmo, debe estrictamente mayor que cero 
*          - a : base la funcion logaritmo
* 
*/


cpp_dec_float_50 log_t(cpp_dec_float_50 x, cpp_dec_float_50 a)
{

    if (x <= 0) //Se verifica que x sea estrictamente mayor que cero para que cumpla el dominio de la funcion 
    {
        printf("%s", "Invalid argument, x must be greater than 0");
        return NULL;
    }

    if (a <= 0) //Se verifica que a, que representa la base,  sea estrictamente mayor que cero 
    {
        printf("%s", "Invalid argument, a must be greater than 0");
        return NULL;

    }

    cpp_dec_float_50 ln = ln_t(a);
    cpp_dec_float_50 d = div_ta(ln);

    return ln_t(x) * d; //Se reescribe la expresion de logaritmo en terminos de logaritmo natual y se 
                            //utiliza la funcion anteriormente implementada 
}





//------------------------------- funcion exponencial base a ------------------------------------

/**
* aproximacion de la funcion exponencial utilizado la base dada por el usuario. Se reescribe 
* la expresion en terminos de una funcion exponencial de base e para utilizar la funcion anteriormente 
* implementada. 
* 
* Paramatros de entrada 
*          - x : argumento de la funcion logaritmo, debe estrictamente mayor que cero 
*          - a : base la funcion logaritmo
* 
*/

cpp_dec_float_50 power_t(cpp_dec_float_50 x, cpp_dec_float_50 a)
{

    if (a <= 0){
        std::cout << "Base de la exponencial incorrecta, debe ser mayor que 0";
        return NULL; 
        
    }


    cpp_dec_float_50 m = ln_t(a);
    cpp_dec_float_50 exp = exp_t(m*x);
    return exp;
 
}




//------------------------------- funcion asin(x) -------------------------------------------


/**
* aproximacion de la funcion  utilizado la base dada por el usuario. Se reescribe 
* la expresion en terminos de logaritmo natual para utilizar la funcion anteriormente 
* implementada. 
* 
* Paramatros de entrada 
*          - a : argumento de la funcion logaritmo, debe estrictamente mayor que cero 
* 
*/

cpp_dec_float_50 asin_t(cpp_dec_float_50 x)
{

    int k = 0;
    cpp_dec_float_50 error = tol + 1;
    cpp_dec_float_50 Sk = 0, Sk0 = 0;;
    int n = 0;

    while (error > tol && k < iterMax)
    {


        cpp_dec_float_50 fac = factorial(n);
        cpp_dec_float_50 k = pow(4, n)*pow(fac, 2)*(2*n +1);
        cpp_dec_float_50 d = div_ta(k);

        Sk += (factorial(2*n) * d)*pow(x, 2*n + 1); //Calculo del sk de la serie
        
        n++; 
        k++;
        error = fabs(Sk - Sk0); //Se calcula el error
        Sk0 = Sk; //Se calcula el nuevo valor de sk0 

    }
    return Sk;
}




//--------------------------- funcion raiz indice a ---------------------------------------



/**
* Funcion utilizada para aproximar una raiz con indice p.  
* 
* El criterio de la funcion es :
*                                      x^p - a 
*
* donde
*            p es el indice de la raiz 
*            a es el argumento de la raiz
*
*/

cpp_dec_float_50 f(cpp_dec_float_50 x, int p, cpp_dec_float_50 a)
{

 
    return pow(x, p) - a;

}


/**
* Derivada de la funcion utilizada para aproximar una raiz con indice p.  
* 
* El criterio de la derivada de la funcion es :
*                                                   p*x^(p-1) 
*
* donde
*            p es el indice de la raiz 
*            a es el argumento de la raiz
*
*/

cpp_dec_float_50 derivate_f(cpp_dec_float_50 x, int p)
{

    return p* pow(x, p - 1);

}



/**
* aproximacion de la funcion raiz con un indice dada por el usuario. Se utiliza el metodo 
* metodo Newton-Rapshon para aproximar el cero de la funcion g(x) = x^p - a
* 
* Parametros de entrada 
*          - x : argumento de la funcion raiz, debe estrictamente mayor que cero 
*          - a : indice de la funcion raiz
* 
*Parametro de salida
*          - xk : aproximación de la función 
*/

cpp_dec_float_50 root_t(cpp_dec_float_50 x, int a)
{

   
    if (x < 0) //Se valida el dominio de la funcion 
    {
        printf("El argumento de la raiz debe ser mayor o igual que cero");
        return NULL;
    }
    if (a <= 0) //Se valida el indice raiz se encuentre dentro de los valores esperados
    {
        printf("El indice debe ser mayor que cero");
        return NULL;
    }


    cpp_dec_float_50 error = tol + 1;
    int k = 1;
    cpp_dec_float_50 xk = x/2.; //Se asigna el valor inicial 

    while(error > tol && k < iterMax) //Se verifica el punto parada
    {


        cpp_dec_float_50 n = f(xk, a, x); //Se calcula el numerador de la fraccion que forma para del calculo del nuevo xk segun el metodo Newton-Rapshon, se evalua la funcion en xk
        cpp_dec_float_50 diff = derivate_f(xk, a); //Se se evalua la derivada funcion en xk
        cpp_dec_float_50 x0 = xk; //Se asigna el nuevo valor para el xk anterior
        cpp_dec_float_50 d = div_ta(diff);
        xk = xk - n * d; //Se calcula el nuevo valor de xk


        error = abs((xk - x0) / xk); //Se calcula el error 
        k++;

    }

    return xk;

}




//----------------------------- funcion raiz cuadrada --------------------------------------


/**
* Aproximacion de la funcion raiz con cuadrada. Se utiliza la funcion 
* implementada para calcular una raiz de indice a. 
* 
* Paramatros de entrada 
*          - x : argumento de la funcion raiz, debe estrictamente mayor que cero 
*          - a : indice de la funcion raiz
* 
*/

cpp_dec_float_50 sqrt_t(int x)
{

    return root_t(x, 2);
    
}





//------------------------------- aproximacion de pi ------------------------------------

cpp_dec_float_50 pi()
{

    /**
    * aproximacion de pi utilizado la serie de Leibniz.
    * 
    * 
    */

    int n = 0;
    cpp_dec_float_50 sk = 0; //Se define el valor inicial de sk
    cpp_dec_float_50 sk1 = 0; //Se define el valor inicial de sk+1
    int k = 1;
    cpp_dec_float_50 error = tol + 1;
    
    while (error >= tol && k <= iterMax)
    {
        sk = sk1;

        cpp_dec_float_50 d =  div_ta(2.*n + 1);

        sk1 += pow(-1, n) * d; //Se calcula el nuevo valor de sk1
        error = fabs(sk1 - sk); //Se calcula el valor del error
        n++;
        k++;

    }
    return 4*sk1;  //Se multiplica el sk1 final debido a que la serie converge en pi/4. 

}



#endif 