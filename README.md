# Temperatura

En el archivo Temperatura.c se encuentran las funciones especificas del proyecto.

Consigna:
 Un sistema distribuído tiene sensores de temperatura en distintos puntos de una ciudad. 
 La estructura de datos de cada medición es la siguiente: 
Cada punto de medición es programado para sensar en distintos minutos de cada día (de 0 a 1440) y deja las lecturas en un pila (TDA Stack). 
Al finalizar el día un proceso crea una lista dinámica enlazada, donde cada elemento es una pila de lecturas del sensor. 
Otro proceso requiere recibir como datos de entrada todas las lectura en una queue (TDA Queue), cuyo elemento es la lectura (reading) 
y deben estar ordenadas por minuto de la medición. 

Elaborar una función  (y todas las que sean necesarias) que reciba como entrada el puntero a la cabecera de la lista de pilas de lecturas
y devuelva como salida una queue con todas las mediciones ordenadas. 
Para ello: 
Construir un TDA, básico para las lecturas: crear, borrar, obtener minuto, obtener temperatura y comparar. 
Hacer una función que simule la creación de la pila con distintas lecturas (reading), tomando minutos y temperaturas en forma aleatoria pero coherentes: 
Los minutos deben ser entre 0 y 1440 y 
las temperaturas entre -10 y 40 grados.
Hacer una función que simule el proceso de ensamblado de varias pilas en una lista dinámica enlazada SLL.
Hacer la función solicitada separando el problema en 2 partes:
Utilizar la librería de árboles binarios de búsqueda (desarrollada en el TP5), cuyo elemento del árbol será la estructura “reading” para insertar todas las lecturas en el árbol ordenando por minutos, en caso de que haya 2 lecturas en el mismo minuto desempatan por temperatura quedando primero la menor, si coinciden en minuto y temperatura se ignora y no se agrega al árbol. 
Crear la Queue recorriendo el árbol in-orden.
Para finalizar, hacer una función de testing que lea la queue y verifique que todos los elementos están ordenados. 

