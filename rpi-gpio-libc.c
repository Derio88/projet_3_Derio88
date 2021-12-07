#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void main(int argc, char *argv[])
{
	char path[40];
	char c[10];
	int ecriture;
	int lecture;
	int pin = atoi(argv[1]);
	int fd;
	
	sprintf(path, "/sys/class/gpio/gpio%d/",pin);
	fd = open(path, O_RDONLY);
	printf("Verifie si le fichier gpio %d est existant.\n", pin);
	if(fd < 0)
	{
		printf("Creation du fichier");
		sprintf(path, "/sys/class/gpio/export");
		printf("Le chemin d'ouverture : %s\n", path);
		fd = open(path, O_WRONLY);
		if (fd < 0) 
		{ 
			perror("r1"); exit(1); 
			
		} 
		printf("ouverture reussi\n");
		
		ecriture = write(fd, argv[1] , strlen(argv[1]));
	
	if (ecriture < 0) 
	{ 
		printf("ecriture echec. Retourne : %d\n", ecriture);
		perror("r1"); exit(1); 
	} 
	printf("ecriture reussi. Retourne : %d\n", ecriture);
	close(fd);
	}
	
	sprintf(path, "/sys/class/gpio/gpio%d/direction",pin);
	printf("Chemin pour la direction : %s\n",path);
	fd = open(path, O_RDWR);
	if (fd < 0) 
	{ 
		perror("r1"); exit(1); 
	} 
	printf("ouverture reussi\n");
	ecriture = write(fd, "out", strlen("out"));
	if (ecriture < 0) 
	{ 
		perror("r1"); exit(1); 
	} 
	printf("ecriture reussi. Retourne : %d\n", ecriture);
	
	close(fd);
	
	sprintf(path, "/sys/class/gpio/gpio%d/value",pin);
	printf("Changement de la valeur s'il a lieu\n");
        fd = open(path, O_RDWR);
		if (fd < 0) 
		{ 
			perror("r1"); exit(1); 
		} 
		printf("ouverture reussi\n");
	switch (argv[2][1])
    {
    case 'n':
        
		ecriture = write(fd, "1", strlen("1"));
		if (ecriture < 0) 
		{ 
			perror("r1"); exit(1); 
		} 
		printf("ecriture reussi.Led allume. Retourne : %d\n", ecriture);
        break;

    case 'f':
        ecriture = write(fd, "0", strlen("0"));
		if (ecriture < 0) 
		{ 
			perror("r1"); exit(1); 
		} 
		printf("ecriture reussi. Led eteinte. Retourne : %d\n", ecriture);
        break;

    default:
        break;
    }
	
	close(fd);
}	

