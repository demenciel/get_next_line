# get_next_line
Cette fonction a comme objectif de pouvoir lire une ligne d'un fichier donné. Des appels successifs permet de lire l'intégralité du fichier.
La fonction doit retourner la ligne lue suivis du retour à la ligne la terminant.
La fonction doit pouvoir lire jusqu'à BUFFER_SIZE.
À chaque nouvelle ligne la fonction doit retourner la ligne précèdente. \n


La fonction est protoypée de la façon suivante : char *get_next_line(int fd);
fd : le fichier descripteur pris en paramètre. \n

Il est possible de se servir des fonctions (read, malloc et free) \n

La fonction read() est protoypée de la façon suivante : ssize_t read(int fd, void *buff, size_t nbyte);
fd      : le fichier descripteur pris en paramètre.
*buff   : un pointeur vers ou les données lues seront stockées.
n_byte  : taille maximale à lire.

