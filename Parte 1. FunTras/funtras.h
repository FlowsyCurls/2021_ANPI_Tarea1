#ifndef FUN_TRAS_H
#define FUN_TRAS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

double tol = 0.00000001;
int iterMax = 5000;


long long factorial(int x)
{
    int temp = 1; 
    long long res = 1;

    if (x == 0)
    {
        return 1; 
    }

    while(temp <= x)
    {
        res = res * temp;
        temp++;

    }

    return res;

}



// -------------------------- exponencial base e ---------------------------------

double exp_t(double x)
{

    /**
    * Aproximacion de la funciones exponencial de base e 
    * 
    * Paramatros de entrada 
    *          - x : argumento de la funcion cos
    * 
    * Parametros de salida:
    *          - sk1 : resultado final. 
    */


    int n = 2;
    long double sk = 1; //Se define el valor inicial de sk
    long double sk1 = sk + x; //Se define el valor inicial de sk+1
    int k = 1;

    
    while (fabsl(sk1 - sk) >= tol && k <= iterMax )
    {
        sk = sk1;
        sk1 += pow(x, n) / factorial(n); //Se calcula el nuevo valor de sk1
        n++;
    }

    return sk1;   
}



//------------------------------- funcion seno(x) ------------------------------------

double sin_t(double x)
{

    /**
    * Aproximacion de la funcion sen
    * 
    * Paramatros de entrada 
    *          - x : argumento de la funcion cos
    * 
    * Parametros de salida:
    *          - sk1 : resultado final. 
    */

    int n = 2;
    double sk = x; //Se define el valor inicial de sk
    double sk1 = -1*(pow(x, 3) / factorial(3)) + sk; //Se define el valor inicial de sk+1
    int k = 1;
    
    while (fabsl(sk1 - sk) >= tol && k <= iterMax)
    {
        sk = sk1;
        int arg = 2*n + 1;
        sk1 += pow(-1,n)*(pow(x, arg) / factorial(arg));//Se calcula el nuevo valor de sk1
        n++;
    }

    return sk1;   
}



//------------------------------- funcion cos(x) ------------------------------------

double cos_t(double x)
{

    /**
    * Aproximacion de la funcion cos
    * 
    * Paramatros de entrada 
    *          - x : argumento de la funcion cos
    * 
    * Parametros de salida:
    *          - sk1 : resultado final. 
    */

    int n = 2;
    double sk = 1; //Se define el valor inicial de sk
    double sk1 = -1*(pow(x, 2) / factorial(2)) + sk; //Se define el valor inicial de sk+1
    int k = 1;
    
    while (fabsl(sk1 - sk) >= tol && k <= iterMax)
    {
        sk = sk1;
        int arg = 2*n;
        sk1 += pow(-1,n)*(pow(x, arg) / factorial(arg));
        n++;
    }

    return sk1;  

}


//------------------------------- funcion tan(x) ------------------------------------

double tan_t(double x)
{
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

    return sin_t(x)/cos_t(x);

}




//------------------------------- funcion ln(x) ------------------------------------

double sk_In(double x, int n)
{

    /**
     * aproximacion del s_k+1 para la funcion logaritmo natural 
     */
    double res = (2.*(x-1)/(x+1))*(1./(2*n+1)* pow(((x-1)/(x+1)), 2*n));
    return res;
}


double ln_t(double x)
{

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

    if (x<=0) //Verifica dominio de la funcion logaritmo
    {
        printf("Argument invalido, el numero debe ser mayor que 0");
        return NULL;

    }

    int n = 2;
    double sk = sk_In(x, 0); //Se define el valor inicial de sk
    double sk1 = sk_In(x, 1) + sk; //Se define el valor inicial de sk+1
    int k = 1;
    
    while (fabsl(sk1 - sk) >= tol && k <= iterMax)//Parametros de parada 
    {
        sk = sk1;
        sk1 += sk_In(x, n); //aproximacion del nuevo sk1
        n++; //aumenta el exponente
    }

    return sk1;  
}




//------------------------------- funcion log(x) ------------------------------------

double log_t(int x, int a)
{

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




//------------------------------- funcion asin(x) ------------------------------------

double asin_t(double x)
{
    /**
    * aproximacion de la funcion  utilizado la base dada por el usuario. Se reescribe 
    * la expresion en terminos de logaritmo natual para utilizar la funcion anteriormente 
    * implementada. 
    * 
    * Paramatros de entrada 
    *          - a : argumento de la funcion logaritmo, debe estrictamente mayor que cero 
    * 
    */
    return 1./sin_t(x);
}



//------------------------------- funcion exponencial base a ------------------------------------

double power_t(double x, double a)
{

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

    double m = ln_t(a);
    double exp = exp_t(m*x);
    return exp;
 
}


//------------------------------- aproximacion de pi ------------------------------------

double pi()
{

    /**
    * aproximacion de pi utilizado la serie de Leibniz.
    * 
    * 
    */

    int n = 2;
    double sk = 1; //Se define el valor inicial de sk
    double sk1 = -1./3 + sk; //Se define el valor inicial de sk+1
    int k = 1;
    
    while (fabsl(sk1 - sk) >= tol && k <= iterMax)
    {
        sk = sk1;
        sk1 += pow(-1, n)/(2.*n + 1); //Se calcula el nuevo valor de sk1
        n++;
        k++;

    }
    return 4*sk1;  //Se multiplica el sk1 final debido a que la serie converge en pi/4. 

}



#endif 