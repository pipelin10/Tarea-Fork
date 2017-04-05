#include "fileutil.h"

int main(int argc, char** argv) {
	char ** listaArchivos;
	char * ruta;
	
	ruta = (char *)malloc (50 * sizeof(char *));
	ruta = argv[1];
	int numberFiles = getNumberFiles(ruta), totalSize = 0; 
	listaArchivos = (char **)malloc(numberFiles * sizeof( char *));
	for(int i = 0; i < numberFiles; i++)
		listaArchivos[i] = (char *)malloc(50 * sizeof (char *));
	
	listaArchivos = obtenerListArchivos(ruta);
	
	for (int i = 0; i < numberFiles; i++){
		totalSize += getSizeFile(listaArchivos[i]);
	}
	
	printf("Estudiante 1: 201526062\n");
	printf("Estudiante 2: 201535038\n");
	printf("Total archivos: %d\n", numberFiles);
	printf("Total bytes: %d\n", totalSize);
	
    return 0;
}
