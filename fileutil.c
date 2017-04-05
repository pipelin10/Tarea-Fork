/*
 * Carlos Felipe Montoya Rincon
 * 1535038
 * Leer archivos
 * */
#include "fileutil.h"

char ** obtenerListArchivos(char * ruta){
	char ** listArchivos;
	DIR *rutaDirectorio;
	struct dirent *aux;
	rutaDirectorio = opendir(ruta);
	int numFiles = getNumberFiles(ruta);
	listArchivos = (char **)malloc(numFiles * sizeof( char *));
	int iterador = 0;
	for(int i = 0; i < numFiles; i++)
		listArchivos[i] = (char *)malloc(50 * sizeof(char *));
		
	
	
	if (rutaDirectorio) {
		while (aux = readdir(rutaDirectorio), aux != NULL) {
			if (aux->d_type != DT_DIR) {
				strcpy(listArchivos[iterador],ruta);
				strcat(listArchivos[iterador],"/");
				strcat(listArchivos[iterador],aux->d_name);
				iterador++;
            }
        }
    }else
		printf("Error\n");
      
    closedir(rutaDirectorio);
    return listArchivos;
}

int getSizeFile(char * fileName){
    
    FILE *archivo;
    int count = 0;

    // de bytes del archivo
    archivo = fopen(fileName,"r");
    if (archivo == NULL) {
        printf("ERROR\n");
        return -1;
    }
    while (fgetc(archivo) != EOF) {
        count++;
    }
    fclose(archivo);
    return count;
}

int getNumberFiles(char * ruta){
	DIR *rutaDirectorio;
	int numberFiles = 0;
	struct dirent *aux;
	rutaDirectorio = opendir(ruta);
	
	if (rutaDirectorio) {
		while (aux = readdir(rutaDirectorio), aux != NULL) {
			if (aux->d_type != DT_DIR) {
				numberFiles++;
            }
        }
    }else
		printf("Error\n");
      
    closedir(rutaDirectorio);
    return numberFiles++;
}




