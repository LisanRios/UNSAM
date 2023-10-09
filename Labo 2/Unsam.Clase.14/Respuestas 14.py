
#3.b. Se desea calcular la distancia recorrida (m) por un móvil que tiene velocidad (float) constante (m/s) durante un tiempo (int) t (s), 
#considerar que es un MRU (Movimiento Rectilíneo Uniforme). Se sabe que el cálculo de la velocidad en MRU es por formula: V = D/T, 
#despejando la distancia se tiene: D = V * T
#In[ ]:

#velocidad = float(input("Ingresa la velocidad del móvil en m/s: "))
#tiempo = int(input("Ingresa el tiempo en segundos: "))
#
#distancia = velocidad * tiempo
#
#print("La distancia recorrida es: ", distancia, "m")

#---------------------------------------------------------------------------------------------------------

#3.c.  Se necesita obtener el promedio simple de un estudiante a partir de sus tres notas parciales N1, N2 y N3.
#In[ ]:

#nota1=float(input("Ingresa la primera nota: "))
#
#nota2=float(input("Ingresa la segunda nota: "))
#
#nota3=float(input("Ingresa la tercera nota: "))
#
#promedio=(nota1+nota2+nota3)/3
#
#print("El promedio es: ", promedio)


#--------------------------------------------------------------------------------------------------------------------------------------------#
# 3.d. Desarrolla un algoritmo que permita, dados ciertos centímetros como entrada de tipo flotante, 
# emitir por pantalla su equivalencia en pies (enteros) y en pulgadas (flotante, con 3 decimales).
# In[ ]:

#medida_centimetros = float(input("Ingresa la medida en centímetros: "))
#
#medida_pulgadas = medida_centimetros / 2.54
#medida_pies = int(medida_pulgadas / 12)
#
#pulgadas_restantes = medida_pulgadas % 12
#
#print("Pies:", medida_pies)
#print("Pulgadas:", round(pulgadas_restantes, 3))

#--------------------------------------------------------------------------------------------------------------------------------------------#
# 3.e. Construye un programa que permita ingresar 2 tiempos, expresados en horas, minutos y segundos, 
# el mismo debe emitir por pantalla la suma de ambos (también en horas, minutos y segundos).
# In[ ]:

hora1 = int(input("Ingresa la hora 1: "))
minutos1 = int(input("Ingresa los minutos 1: "))
segundos1 = int(input("Ingresa los segundos 1: "))

hora2 = int(input("Ingresa la hora 2: "))
minutos2 = int(input("Ingresa los minutos 2: "))
segundos2 = int(input("Ingresa los segundos 2: "))

tiempo_total_segundos = (hora1 * 3600 + minutos1 * 60 + segundos1) + (hora2 * 3600 + minutos2 * 60 + segundos2)

horas = tiempo_total_segundos // 3600
minutos = (tiempo_total_segundos % 3600) // 60
segundos = tiempo_total_segundos % 60

print("La suma de los tiempos es:", horas, "° ", minutos, "' ", segundos, '"')

