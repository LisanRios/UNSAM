#!/usr/bin/env python
# coding: utf-8

# __1. Resolver y observar los resultados__

# In[ ]:


a = 3 
b = 2
c = 1
m = 2.5
n = 5.4


# In[ ]:


d = n
d


# In[ ]:


e = 3.7
e


# In[ ]:


d = a
d = a + b
d


# In[ ]:


d = a * b
d


# In[ ]:


d = a / b
d


# In[ ]:


d = b / 4
d


# In[ ]:


d = a // b
d


# In[ ]:


d = a % b
d


# In[ ]:


d = a % n
d


# In[ ]:


e = b / c
e


# In[ ]:


e = a**b
e


# In[ ]:


r = a / 2.0
r


# In[ ]:


s = n // m
s


# In[ ]:


s = 3 + 4 - 1
s


# In[ ]:


s = 3.0 + 4.0 -1
s


# In[ ]:


a = m / 2
a


# In[ ]:


a = m / 2.0
a


# In[ ]:


a+= 5
a


# In[ ]:


s*= 5
s


# __2. Evaluar las siguientes expresiones:__

# In[ ]:


1 / 2 / 4


# In[ ]:


1 / 2.0 / 4.0


# In[ ]:


1 / 2.0 / 4


# In[ ]:


1.0 / 2 / 4


# In[ ]:


4** .5


# In[ ]:


4.0** (1 / 2)


# In[ ]:


4.0** (1 / 2) + 1 / 2


# In[ ]:


4.0** (1.0 / 2) + 1 / 20


# In[ ]:


3e3 / 10


# In[ ]:


10 / 5e-3


# In[ ]:


10 / 5e-3 + 1


# In[ ]:


3 / 2 + 1


# In[ ]:


A = 9
B = 8
C = 2


# In[ ]:


B * A - B * B / 4 * C


# In[ ]:


(A * B) / 3 * 3 


# In[ ]:


(((B + C) / 2 * A + 10) * 3 * B) - 6


# In[ ]:


40/5*5+6/2*3+4-5*2/10


# In[ ]:


500- ((6 -1)*8/4*3+16/(10-2))-5


# In[ ]:


4 / 2 * 3 / 6 + 6 / 2 / 1 / 5 % 2 / 4 * 2


# In[ ]:


14 - (7+4*3-(-2) *2 *2 - 6) + (22+6-5*3) + 3 - (5-3/2)


# In[ ]:


((1580 % 6*2^7) > (7+8*3^4)) > ((15*2) == (60*2/4))


# In[ ]:


not (15 >= 7^2) or (43 - 8 * 2 / 4 != 3 * 2 / 2)


# In[ ]:


(15<=7*3^2 and 8>3 and 15<6) or not (7*3 < 5+12*2 // 3^2)


# In[ ]:


d = 0
e = 1    # 0 (cero) corresponde a falso
x = 2
y = 3


# In[ ]:


a = 5 > 3
a


# In[ ]:


b = (( 4 < 5 ) and ( 2 > 2 ))
b


# In[ ]:


a = not e
a


# In[ ]:


b = ( ( x % 2 == 0 ) or ( x - y < 10 ) )
b


# In[ ]:


c = not ( d and e )
c


# In[ ]:


c = ( d or e )
c


# In[ ]:


c = not ( d and e )
c


# In[ ]:


c = ( not d ) and ( not e )
c


# In[ ]:


c = ( a and ( not a ) )
c


# In[ ]:


c = ( ( ( x <= ( y * 3.2 ) ) and ( y % 2 != 0 ) ) or ( 1 ) )
c


# In[ ]:


True == True != False


# In[ ]:


1 < 2 < 3 < 4 < 5


# In[ ]:


( 1 < 2 < 3 ) and ( 4 < 5 )


# In[ ]:


1 < 2 < 4 < 3 < 5


# In[ ]:


( 1 < 2 < 4 ) and ( 3 < 5 )


# __3. Resolver codificando en Python__ 

# 3.a
# ```
# Un programa en Python puede tener esta estructura:
# 
# """ ESTAS COMILLAS SON PARA PONER
# COMENTARIOS DE MAS DE UNA LINEA"""
# # PARA COMENTARIOS EN UNA LINEA UTILIZAMOS #
# 
# tunombre=input("Ingresa tu nombre:")
# print(f"Hola {tunombre}!!!")
# 
# nombre1=input("ingrese nombre del producto:")
# precio1=int(input("ingrese un precio:"))
# nombre2=input("ingrese nombre del producto:")
# precio2=int(input("ingrese otro precio:"))
# 
# # esta es una constante
# BONIFICACION = 20
# 
# # sumamos los dos precios y su resultado lo guardamos en una variable
# precio_total = precio1 + precio2 
# print(f"El precio total es: {precio_total}")
# print(f"Resultados de la suma de producto {nombre1} y del producto {nombre2}.:")
# 
# # concatenar se puede hacer de esta manera con el signo + y en la variable la propiedad str
# print ("la suma de los dos productos es:" + str(precio_total))
# 
# """ VEMOS EL OPERADOR DE ASIGNACION AQUI ABAJO """
# precio_total += BONIFICACION 
# print ("al precio total le incrementamos su valor que tiene la constante:" + str(precio_total))
# 
# # Prueba el programa guardándolo con un nombre y la extensión .py o .ipynb
# ```

# In[ ]:





# 3.b. Se desea calcular la distancia recorrida (m) por un móvil que tiene velocidad (float) constante (m/s) durante un tiempo (int) t (s), considerar que es un MRU (Movimiento Rectilíneo Uniforme). Se sabe que el cálculo de la velocidad en MRU es por formula: V = D/T, despejando la distancia se tiene: D = V * T

# In[ ]:





# 3.c.  Se necesita obtener el promedio simple de un estudiante a partir de sus tres notas parciales N1, N2 y N3.

# In[ ]:





# 3.d. Desarrolla un algoritmo que permita, dados ciertos centímetros como entrada de tipo flotante, emitir por pantalla su equivalencia en pies (enteros) y en pulgadas (flotante, con 3 decimales).

# In[ ]:





# 3.e. Construye un programa que permita ingresar 2 tiempos, expresados en horas, minutos y segundos, el mismo debe emitir por pantalla la suma de ambos (también en horas, minutos y segundos).

# In[ ]:




