//primeste ca par in linie de com un fisier, verificam daca fisierul exista si sa afisam continutul acelui fisier, folosim o functie read and write

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        perror("eroare argumente");
        exit(-1);
    }
    struct stat st;
    char eroare[100] = "Fisierul nu exista, se va crea!\n";
    if (stat(argv[1], &st) != 0)
    {
        //cand nu exista`
        int fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, 0777);
        char fisier[4096];
        int bytesread;
        while ((bytesread = read(0, fisier, sizeof(fisier))) > 0) //ce scrii tu in terminal
        {
            write(fd, fisier, bytesread);
        }
        write(1, eroare, strlen(eroare));
    }
    else
    {
        //cand exista
        int fd = open(argv[1], O_RDWR | O_APPEND);
        char fisier[4096];
        int bytesread;
        while ((bytesread = read(fd, fisier, sizeof(fisier))) > 0)
        {
            write(1, fisier, bytesread);//ce scrii in fisier
        }
    }
    return 0;
}
