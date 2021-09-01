#ifndef FUN_TRAS_H
#define FUN_TRAS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

double tol = 0.00000001;
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
double factorial(int x)
{
    
    int temp = 1; 
    double res = 1.;

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

double div_ta(double a)
{
    double eps = 2.2204E-16;
    double x0;

    double fac0 = 1;
    double fac20 = factorial(20);
    double fac40 = factorial(40);
    double fac60 = factorial(60);
    double fac80 = factorial(80);
    double fac100 = factorial(100);


    if (fac0 < a <= fac20)
    {
        x0 = pow(eps, 2);
        std::cout << x0 << '\n';
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


    double x1, error = tol + 1;
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

double exp_t(double x)
{


    int n = 2;
    long double sk = 1; //Se define el valor inicial de sk
    long double sk1 = sk + x; //Se define el valor inicial de sk+1
    int k = 1;
    double error = tol + 1;
    
    while (error >= tol && k <= iterMax )
    {
        sk = sk1;
        sk1 += pow(x, n) / factorial(n); //Se calcula el nuevo valor de sk1
        error = fabsl(sk1 - sk);
        n++;
    }

    return sk1;   
}



//------------------------------- funcion sin(x) ------------------------------------



/**
* Aproximacion de la funcion sen
* 
* Paramatros de entrada 
*          - x : argumento de la funcion cos
* 
* Parametros de salida:
*          - sk1 : resultado final. 
*/


double sin_t(double x)
{


    double n  = 0;
    double sk = 0; //Se define el valor inicial de sk
    double sk1 =0; //Se define el valor inicial de sk+1
    int k = 1;
    double error = tol + 1;


   
    while (error >= tol && k <= iterMax)
    {
        sk = sk1;
        int arg = 2*n + 1;
        sk1 += pow(-1,n)*(pow(x, arg) / factorial(arg));//Se calcula el nuevo valor de sk1
        error = fabsl(sk1 - sk);
        k++;
        n++;
    }

    return sk1;   
}



//------------------------------- funcion cos(x) ------------------------------------



/**
* Aproximacion de la funcion cos
* 
* Paramatros de entrada 
*          - x : argumento de la funcion cos
* 
* Parametros de salida:
*          - sk1 : resultado final. 
*/



double cos_t(double x)
{


    int n = 0;
    double sk = 0; //Se define el valor inicial de sk
    double sk1 = 0; //Se define el valor inicial de sk+1
    int k = 1;
    double error = tol + 1;


    while (error >= tol && k <= iterMax)
    {
        sk = sk1;
        int arg = 2*n;
        sk1 += pow(-1,n)*(pow(x, arg) / factorial(arg));
        error = fabsl(sk1 - sk);
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

double tan_t(double x)
{

    return sin_t(x)/cos_t(x);

}




//------------------------------- funcion ln(x) ------------------------------------

/**
* aproximacion de la funcion logaritmo natural. Mediante la utilizacion de una serie.
* 
* Paramatros de entrada 
*          - a : argumento de la funcion logaritmo, debe estrictamente mayor que cero 
* 
* Parametros de salida:
*          - sk1 : resultado final.
* 
* 
*/


double ln_t(double x)
{


    if (x<=0) //Verifica dominio de la funcion logaritmo
    {
        printf("Argument invalido, el numero debe ser mayor que 0");
        return NULL;

    }

    int n = 0;
    double sk = 0; //Se define el valor inicial de sk
    double sk1 = 0; //Se define el valor inicial de sk+1
    int k = 1;
    double error = tol + 1;


    
    while (error >= tol && k <= iterMax)//Parametros de parada 
    {
        sk = sk1;
        sk1 += (2.*(x-1)/(x+1))*(1./(2*n+1)* pow(((x-1)/(x+1)), 2*n)); //aproximacion del nuevo sk1
        error = fabsl(sk1 - sk);
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


double log_t(double x, double a)
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

    return ln_t(x)/ln_t(a); //Se reescribe la expresion de logaritmo en terminos de logaritmo natual y se 
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

double power_t(double x, double a)
{


    double m = ln_t(a);
    double exp = exp_t(m*x);
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

double asin_t(double x)
{

    int k = 0;
    double error = tol + 1;
    double Sk = 0, Sk0 = 0;;
    int n = 0;

    while (error > tol && k < iterMax)
    {
        double fac = factorial(n);
        Sk += (factorial(2*n)/(pow(4, n)*pow(fac, 2)*(2*n +1)))*pow(x, 2*n + 1); //Calculo del sk de la serie
        n++;
        k++;
        error = fabs(Sk - Sk0); //Se calcula el error
        Sk0 = Sk; 

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

double f(double x, int p, double a)
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

double derivate_f(double x, int p)
{

    return p* pow(x, p - 1);

}



/**
* aproximacion de la funcion raiz con un indice dada por el usuario. Se utiliza el metodo 
* metodo Newton-Rapshon para aproximar el cero de la funcion g(x) = x^p - a
* 
* Paramatros de entrada 
*          - x : argumento de la funcion raiz, debe estrictamente mayor que cero 
*          - a : indice de la funcion raiz
* 
*/

double root_t(double x, int a)
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


    double error = tol + 1;
    int k = 1;
    double xk = x/2.; //Se asigna el valor inicial 

    while(error > tol && k < iterMax) //Se verifica el punto parada
    {


        double n = f(xk, a, x); //Se calcula el numerador de la fraccion que forma para del calculo del nuevo xk segun el metodo Newton-Rapshon, se evalua la funcion en xk
        double d = derivate_f(xk, a); //Se calcula el denomiador de la fraccion que forma para del calculo del nuevo xk segun el metodo Newton-Rapshon, se evalua la derivada funcion en xk
        double x0 = xk; //Se asigna el nuevo valor para el xk anterior
        xk = xk - n/d; //Se calcula el nuevo valor de xk
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

double sqrt_t(int x)
{

    return root_t(x, 2);
    
}





//------------------------------- aproximacion de pi ------------------------------------

double pi()
{

    /**
    * aproximacion de pi utilizado la serie de Leibniz.
    * 
    * 
    */

    int n = 0;
    double sk = 0; //Se define el valor inicial de sk
    double sk1 = 0; //Se define el valor inicial de sk+1
    int k = 1;
    double error = tol + 1;
    
    while (error >= tol && k <= iterMax)
    {
        sk = sk1;
        sk1 += pow(-1, n)/(2.*n + 1); //Se calcula el nuevo valor de sk1
        error = fabsl(sk1 - sk);
        n++;
        k++;

    }
    return 4*sk1;  //Se multiplica el sk1 final debido a que la serie converge en pi/4. 

}



#endif 