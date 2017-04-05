#include "fileutil.h"

int main(int argc, char** argv) {
	char ** listaArchivos;
	char * ruta;
	pid_t pid;
	ruta = (char *)malloc (50 * sizeof(char *));
	ruta = argv[1];
	int numberFiles = getNumberFiles(ruta), totalSizeFather = 0, totalSizeSon = 0, mitad, fd[2]; 
	listaArchivos = (char **)malloc(numberFiles * sizeof( char *));
	for(int i = 0; i < numberFiles; i++)
		listaArchivos[i] = (char *)malloc(50 * sizeof (char *));
	
	listaArchivos = obtenerListArchivos(ruta);
	
	mitad = numberFiles/2;
	pipe(fd);
	pid = fork();
	if (pid == 0){
		for (int i = 0; i < mitad; i++){
			totalSizeFather += getSizeFile(listaArchivos[i]);
		}
		read(fd[0],&totalSizeSon,sizeof(totalSizeSon));
		
		printf("Estudiante 1: 201526062\n");
		printf("Estudiante 2: 201535038\n");
		printf("Total archivos: %d\n", numberFiles);
		printf("Total bytes: %d\n", totalSizeFather + totalSizeSon);
	}else{
		for (int i = mitad; i < numberFiles; i++){
			totalSizeSon += getSizeFile(listaArchivos[i]);
		}
		write(fd[1],&totalSizeSon,sizeof(totalSizeSon));
	}
	
	
	
    return 0;
}
