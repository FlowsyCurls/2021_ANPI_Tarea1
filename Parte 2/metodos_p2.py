"""
Implementación del método de Newton-Raphson
"""

from math import *
from sympy import *
import numpy as np
from matplotlib import pyplot as plt

"""
Pregunta 2, Parte 1
"""

"""
Función para calcular derivadas usando las librerias de sympy y numpy
"""
#----Primera Derivada-----#
def derivate(func, z):
    x = Symbol('x')
    y = sympify(func)
    y_dx = y.diff(x)
    f = lambdify(x, y_dx, 'numpy')
    return f


#-----Segunda Derivada-----#
def derivate2(func, z):
    x = Symbol('x')
    y = sympify(func)
    y_dx = y.diff(x,x)
    f = lambdify(x, y_dx, 'numpy')
    return f


def evaluate(func,symbol,value):
    x = Symbol(symbol)
    y = sympify(func)
    f = lambdify(x, y, 'numpy')
    return f(value)


def graph(k,er):
    plt.rcParams.update({'font.size': 14})
    ejex=np.arange(1,k+1,1)
    fig, graf=plt.subplots()
    graf.plot(ejex,er,'b',marker='o',markerfacecolor='red',markersize=10)
    plt.show()
    graf.set_xlabel('Iteraciones ($k$)')
    graf.set_ylabel('$|f(x_k)|$')
    graf.set_title('Metodo de Newton-Rapshon (Iteraciones vrs Error)');
    graf.grid(True)


# ● ● ● ● ● H1 ● ● ● ● ● #
# Newton
#: H(u) = 1
"""
Entradas: 
    • fun     : Función
    • x0      : Valor inicial
    • tol     : Valor de tolerancia
    • iterMax : Iteraciones máximas
Salidas:
    • xk      : Aproximación
    • k       : Número de iteraciones
    • error   : valor del error.
"""
def newton_H_m1(fun,x0,tol,iterMax):

    # Condiciones iniciales
    k=0                                         # Contador para la sumatoria.
    xk=x0                                       # Variable iterada.
    er=[]                                       # Array de error.
    error=tol+1                                 # Definir el error.
    df =  derivate(fun, xk)

    # Ciclo de iteracion.
    while error>tol and k<iterMax:
        k=k+1                                   # Actualizacion del contador.
        n = evaluate(fun,'x',xk)                # Numerador, sustiyendo x por xk.
        d = df(xk)                              # Denominador, sustituyendo x por xk.

        # Evaluar que la derivada no se haga cero.
        if d == 0:
            print("✘ Error! Derivada se hace cero:", d)
            break

        uk = n/d                                # u(x) = f(x) / f’(x) : obtenido del paper.
        xk = xk - 1*uk
        error = abs(evaluate(fun,'x',xk))
        er.append(error)
    # graph(k,er)                                 # GRAFICACION.
    return [xk, k, error]



# ● ● ● ● ● H2 ● ● ● ● ● #
# Método Kanwar–Tomar
#: H(u) = 1/1+βu
"""
Entradas: 
    • fun     : Función
    • x0      : Valor inicial
    • tol     : Valor de tolerancia
    • iterMax : Iteraciones máximas
    • beta    : Beta
Salidas:
    • xk      : Aproximación
    • k       : Número de iteraciones
    • error   : valor del error.
"""
def newton_H_m2(fun,x0,tol,iterMax, beta):

    # Condiciones iniciales y constantes.
    k=0                                         # Contador para la sumatoria.
    xk=x0                                       # Variable iterada.
    er=[]                                       # Array de error.
    error=tol+1                                 # Definir el error.
    df =  derivate(fun, xk)

    # Ciclo de iteracion.
    while error>tol and k<iterMax:
        k=k+1                                   # Actualizacion del contador.
        n = evaluate(fun,'x',xk)                # Numerador, sustiyendo x por xk.
        d = df(xk)                              # Denominador, sustituyendo x por xk.

        # Evaluar que la derivada no se haga cero.
        if d == 0:
            print("✘ Error! Derivada se hace cero:", xk)
            break

        uk = n/d                                # u(x) = f(x) / f’(x) : obtenido del paper.
        xk = xk-(1/(1+beta*uk)) * uk
        error = abs(evaluate(fun,'x',xk))
        er.append(error)
    # graph(k,er)                                 # GRAFICACION.
    return [xk, k, error]





# ● ● ● ● ● G1 ● ● ● ● ● #
# Método Halley
#: H(u) = 2/2-w
"""
Entradas: 
    • fun     : Función
    • x0      : Valor inicial
    • tol     : Valor de tolerancia
    • iterMax : Iteraciones máximas
Salidas:
    • xk      : Aproximación
    • k       : Número de iteraciones
    • error   : valor del error.
"""
def newton_G_m1(fun,x0,tol,iterMax):

    # Condiciones iniciales y constantes.
    k=0                                         # Contador para la sumatoria.
    xk=x0                                       # Variable iterada.
    er=[]                                       # Array de error.
    error=tol+1                                 # Definir el error.
    deriv1 = derivate(fun, xk)
    deriv2 = derivate2(fun, xk)

    # Ciclo de iteracion.
    while error>tol and k<iterMax:
        k=k+1                                   # Actualizacion del contador.

        f = evaluate(fun,'x',xk)                # Funcion evaluada con x = xk.
        df1 = deriv1(xk)                        # Primera derivada evaluada con x = xk.
        df2 = deriv2(xk)                        # Primera derivada evaluada con x = xk.

        # Evaluar que la derivada no se haga cero.
        if df1 == 0:
            print("✘ Error! Derivada se hace cero:", xk)
            break

        w = (f*df2)/df1**2                      # w(x) = f(x)*f’’(x)/f’(x)^2 : obtenido del paper.
        xk = xk - (2/(2-w)) * f/df1

        error = abs(evaluate(fun,'x',xk))
        er.append(error)

    # graph(k,er)                                 # GRAFICACION.
    return [xk, k, error]



# ● ● ● ● ● G2 ● ● ● ● ● #
# Método Chebyshev
#: H(u) = 1+w/2
"""
Entradas: 
    • fun     : Función
    • x0      : Valor inicial
    • tol     : Valor de tolerancia
    • iterMax : Iteraciones máximas
Salidas:
    • xk      : Aproximación
    • k       : Número de iteraciones
    • error   : valor del error.
"""
def newton_G_m2(fun,x0,tol,iterMax):

    # Condiciones iniciales y constantes.
    k=0                                         # Contador para la sumatoria.
    xk=x0                                       # Variable iterada.
    er=[]                                       # Array de error.
    error=tol+1                                 # Definir el error.
    deriv1 = derivate(fun, xk)
    deriv2 = derivate2(fun, xk)

    # Ciclo de iteracion.
    while error>tol and k<iterMax:
        k=k+1                                   # Actualizacion del contador.

        f = evaluate(fun,'x',xk)                # Funcion evaluada con x = xk.
        df1 = deriv1(xk)                        # Primera derivada evaluada con x = xk.
        df2 = deriv2(xk)                        # Segunda derivada evaluada con x = xk.

        # Evaluar que la derivada no se haga cero.
        if df1 == 0:
            print("✘ Error! Derivada se hace cero:", xk)
            break

        w = (f*df2)/df1**2                      # w(x) = f(x)*f’’(x)/f’(x)^2 : obtenido del paper.
        xk = xk - (1+w/2) * f/df1

        error = abs(evaluate(fun,'x',xk))
        er.append(error)

    # graph(k,er)                                 # GRAFICACION.
    return [xk, k, error]