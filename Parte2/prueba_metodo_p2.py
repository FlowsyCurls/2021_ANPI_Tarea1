"""
Pregunta 2, Parte 2
"""

from metodos_p2 import *

# Constantes
x0=10                   # Valor inicial
tol=10e-5               # Tolerancia
iterMax=500             # Iteraciones Maximas
beta=10                 # Beta

# Parte 5, pruebas.
f1='cos(x)-x'
f2='sin(x)^2-x^2+1'
# f3='x*e**(x**2)-sin(x)**2+3*cos(x)+5'

def main():
    y1 = newton_H_m1(f2, x0, tol, iterMax)
    y2 = newton_H_m2(f2, x0, tol, iterMax, beta)
    y3 = newton_G_m1(f2, x0, tol, iterMax)
    y4 = newton_G_m2(f2, x0, tol, iterMax)

    print("(Método 1, tabla 1)\n ▶  Newton")
    prt(y1)
    print("(Método 2, tabla 1)\n ▶  Kanwar–Tomar")
    prt(y2)
    print("(Método 1, tabla 2)\n ▶  Halley")
    prt(y3)
    print("(Método 2, tabla 2)\n ▶  Chebyshev")
    prt(y4)


def prt(arry):
    if len(arry) == 3:
        print('     • xk  :',arry[0])
        print('     • k   :',arry[1])
        print('     • err :',arry[2])
        print()

    else:
        print('     • ',arry)


if __name__ == '__main__':
    main()
