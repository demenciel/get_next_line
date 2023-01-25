# get_next_line

## char *get_next_line(int fd);

### #define BUFFER_SIZE;

### static char *saved; // garde en mémoire les lignes lues

### char buf[BUFFER_SIZE + 1]; // array temporaire pour le string lu d’une

### grosseur de BUFFER_SIZE.

**get_next_line** va lire **fd** jusqu’à la grosseur **BUFFER_SIZE** passé en paramètre, et déterminer si le string **saved** donnée par la fonction est bien une ligne (se termine par \n). Si la **saved** n’est pas une ligne, la fonction s’exécutera de nouveau. 

**saved** gardera en mémoire les données lues jusqu’à la fin du programme.

**buf** est un array temporaire pour stocker la chaine lue de la grosseur de **BUFFER_SIZE**. buf sera joint à **saved** string.

