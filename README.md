## Tarea Fork  
### Estudiante 1:  
Melissa Millares 201526062  
### Estudiante 2:   
Carlos Felipe Montoya 201535038  
#### Proposito archivos:    
**io.c:** Contiene la implementación del código sin fork()  
**iofork.c** Contiene la implementación del código con el fork()  
**fileutil.c** Contiene las funciones que permiten obtener los archivos de un directorio, el tamaño de un archivo y la cantidad de archivos que hay en un directorio  
**Makefile** Para crear los ejecutables  
**fileutil.h** La llamada de las funciones  
## Pregunta: 
**¿Qué diferencia en tiempo observa en las dos versiones? ¿Se puede afirmar que también un programa intensivo en I/O toma la mitad del tiempo si se divide la ejecución en dos procesos?**  
R/ Para el caso de io y iofork con la carpeta "bin" de Linux tomamos un tiempo de 194 y 123 respectivamente.  
Observamos que no toma la mitad de tiempo pero si mejora en tiempo de ejecución cuándo utilizamos la función fork.  
