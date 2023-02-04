""" Rui Yu Lei Wu Código:8978227 
    Solución tarea1 Estructura de datos grupo A

"""



#Enunciado 1
#Que entra: Una matriz de enteros
#Que hace: Revisa la diagonal principal y secundaria 
#Que sale: Retorna una validacion, si ambas diagonales son iguales validacion=True, de otra forma validacion=False
def verificarDiagonales(mat):
    i=0
    validacion=True
    while i<len(mat) and validacion==True:
        if (mat[i][i])==(mat[i][-i-1]):
            i+=1
        else:
            validacion=False
    return validacion

#print(verificarDiagonales(mat = [[11, 23, 76, 34, 11],[14, 30, 92, 30, 101],[12, 45, 58, 92, 22],[74, 56, 49, 56, 100],[99, 5, 28, 47, 99]]))

#Enunciado 2
#Que entra: Una lista de enteros
#Que hace:  Revisa si la lista es capicua(significa que se puede leer de izq a der o de der a izq)
#Que sale:  Si es capicua retorna True, de otra forma retorna False
def esCapicua(lista):
    i=0
    validacion=True
    while i<(len(lista)/2) and validacion==True:
        if lista[i]==lista[-i-1]:
            i+=1
        else: 
            validacion=False
    return validacion
#print(esCapicua([42, 12, 90, 90, 12, 42]))


#Enunciado 3
#Que entra: Entran dos listas de enteros, que pueden tener diferente tamaño
#Que hace: Revisa si un elemento de la listaA esta en la listaB, si no esta la agrega a "lista", si de lo contrario esta el elemento esta en la listaB elimina el elemento de la listaB
#Que sale: Retorna una lista que contendra los elementos de la listaA que no estan en la listaB
def diferenciaListas(listaA,listaB):
    lista=[]
    for i in listaA:
        if i in listaB:
            listaB.remove(i)
        else:
            lista.append(i)
    return lista
listaA = [40, 10, 22, 10, 33, 33]
listaB = [41, 22, 31, 15, 13, 12, 33]
#print(diferenciaListas(listaA,listaB))
#Que hace: El usuario digita el tope de listaA,listaB y el numero de veces que se ejecutara, y ingresa valores enteros de ambas listas, y con la funcion de diferenciaListas retorna la diferencia de ambas listas. Pro ultimo imprime diferencia de las listas que ingreso el usuario 
def leerDatos():
    n=int(input())
    for i in range (n):
        listaA=input().split()
        listaB=input().split()
        listaA=[int(j) for j in listaA]
        listaB=[int(j) for j in listaB]
        listaA.remove(listaA[0])
        listaB.remove(listaB[0])
        lista=(diferenciaListas(listaA,listaB))
        for j in range (len(lista)):
            if j==(len(lista)-1):
                print("%d"%(lista[j]))
            else:
                print("%d, "%(lista[j]),end="")

    
#leerDatos()
#Que entra: entra un valor entero n
#Que hace: Revisa que numeros son primos hasta el valor n, y genera una lista con todos estos; con esta lista de primos que van desde 2 hasta n, genera otra lista con los primos que son suma de primos, por ultimo imprime estas dos listas


#Enunciado 4
def mostrarPrimos(n):
    i=1
    listaPrimos=[]
    listaSumaPrimos=[]
    for j in range(n):
        con=1
        bandera=0
        while con<=i and bandera<3:
            if i%con==0:
                bandera+=1
            con+=1
            suma=0  
        if bandera==2:
            con2=1
            bandera2=0
            listaPrimos.append(i)
            for k in (str(i)):
                suma+=int(k)
            while con2<=suma and bandera2<3:
                if suma%con2==0:
                    bandera2+=1
                con2+=1   
            if bandera2==2:
                listaSumaPrimos.append(i)  
        i+=1
    
    print("Números primos entre 1 y %d"%(n))
    for h in range(len(listaPrimos)):
        if h==(len(listaPrimos)-1):
            print("--> %d"%(listaPrimos[h]))
        else:
            print("--> %d,"%(listaPrimos[h]))
    print("Números entre 1 y %d con suma de dígitos con valor primo:"%(n))
    for m in range(len(listaSumaPrimos)):
        if (m==len(listaSumaPrimos)-1):
            print("%d"%(listaSumaPrimos[m]))
        else:    
            print("%d, "%(listaSumaPrimos[m]),end="")
#mostrarPrimos(100)


#Enunciado 5 
#Que entra: recibe un diccionario y una matriz 
#Que hace: Busca en el diccionario segun las claves ingresadas unos digitos, esto para aumentarlos a una variable llamada "suma" 
#Que sale: Retorna un entero resultado de la suma
def sumarValoresMatriz(disp,mat):
    suma=0
    for contras,numBuscar in mat:
        for j in (disp):
            if contras==j:
                for k in range(len(disp[contras])):
                    if numBuscar==disp[contras][k][0]:
                        suma+=disp[contras][k][1]
    return suma
disp = {0 : [(0, 1), (5, 4), (7, 5)],
1 : [(6, 4), (7, 7)],
2 : [(0, 2), (1, 2), (4, 9), (6, 1)],
4 : [(2, 8), (3, 1), (5, 7)],
6 : [(0, 3), (5, 6), (7, 2)],
7 : [(0, 4), (1, 4), (2, 7)],
8 : [(1, 9), (3, 8), (5, 7), (7, 6)]}
#print(sumarValoresMatriz(disp,[(0, 0), (8, 3), (3, 5), (7, 2), (4, 3), (4,6)]))