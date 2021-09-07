import sympy as sp

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
    df =  sp.diff(fun)
    x = sp.Symbol('d')

    # Ciclo de iteracion.
    while error>tol and k<iterMax:
        k=k+1                                # Actualizacion del contador.
        n = sp.N(fun.subs(x, xk))               # Numerador, sustiyendo x por xk.
        d = sp.N(df.subs(x, xk))              # Denominador, sustituyendo x por xk.

        # Evaluar que la derivada no se haga cero.
        if d == 0:
            print("✘ Error! Derivada se hace cero:", xk)
            break

        uk = n/d                              # u(x) = f(x) / f’(x) : obtenido del paper.
        xk = xk-(1/(1+beta*uk)) * uk
        error = abs(sp.N(fun.subs(x, xk)))
        er.append(error)
    # graph(k,er)                                 # GRAFICACION.
    return [xk, k, error]






##DEFINICION DE LA FUNCION DE DISTANCIA ENTRE DOS SENSORES
g = '200*acos(d / 20) - d*root(100 - (d**2)/4, 2)'
f = f"log(7 / d , 10)*1600/(16*log(10)) + (d*(6 - d))/ (((({g})**2)*(log(10)**2) / 3200 )*(1/ ({g}) + 1/314.15))"

f_sym = f1 = sp.sympify(f)
x0 = 0.5
tol = 10**-5
iterMax = 100
beta = 0.5
y = newton_H_m2(f_sym, x0,tol, iterMax, beta)
print(f"La aproximacion de la distancia d esta dada por {y[0]} con un error de {y[2]}")