Notion = https://www.notion.so/get_next_line-2422a9b63e9e46bc85f824a96c5c4f6f;

## char *get_next_line(int fd);

### #define BUFFER_SIZE;

### static char *saved; // garde en mémoire les lignes lues

### char buf[BUFFER_SIZE + 1]; // array temporaire pour le string lu d’une

### grosseur de BUFFER_SIZE.

**get_next_line** va lire **fd** jusqu’à la grosseur **BUFFER_SIZE** passé en paramètre, et déterminer si le string **saved** donnée par la fonction est bien une ligne (se termine par \n). Si la **saved** n’est pas une ligne, la fonction s’exécutera de nouveau. 

**saved** gardera en mémoire les données lues jusqu’à la fin du programme.

**buf** est un array temporaire pour stocker la chaine lue de la grosseur de **BUFFER_SIZE**. buf sera joint à **saved** string.

## Étape à suivre :

![https://velog.velcdn.com/images%2Fljiwoo59%2Fpost%2Fe1bf1799-8b15-426a-9055-2909b3687c0c%2Fgnl-3.png](https://velog.velcdn.com/images%2Fljiwoo59%2Fpost%2Fe1bf1799-8b15-426a-9055-2909b3687c0c%2Fgnl-3.png)

 

```c
char	*get_next_line(int fd)
{
	static char *saved;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saved = read_saved(fd, saved);
	if (!saved)
		return (NULL);
	line = get_line(saved);
	saved = read_new_saved(saved);
	return (line);
}
```

### **char *read_saved(int fd, char *saved) :**

- Créer une variable **char *buf** qui aura la grosseur du **BUFFER_SIZE**
- Créer une boucle qui continuera tant que \n n’est pas trouvé dans **saved**.
    - Aller lire dans le **fd. read(fd, buf, BUFFER_SIZE)**
        - **Fd** : file descriptor
        - **buf** : le pointeur vers lequel est stocké ce qui est lu.
        - **BUFFER_SIZE** : La taille à lire.
    - Mettre un ‘\0’ à chaque valeur de buf[bytes_read];
    - Se servant de **strjoin**(**saved**, **buf**), retourne une nouvelle string qui contiendra les valeurs de **saved**(le contenu lu stocké en mémoire) et de **buf**(le array temporaire pour stocker le contenu lu.)
- Ensuite libère la mémoire utilisée par **buf**.
- Retourne un pointeur sur l’emplacement de **saved**(saved aura un pointeur ou l’emplacement de ou read() est rendue)

### **char *get_line(char *saved) :**

- Faire une boucle pour faire monter un compteur qui aura pour but d’aider à allouer la mémoire nécessaire pour la nouvelle string à retourner.
- Allouer la mémoire à la nouvelle string et remettre le compteur à zéro.
- Créer une boucle avec conditions : (**saved**[i] ≠ ‘\n’ && **saved**[i]) et transférer **saved**[i] dans la nouvelle string.
- Retourne la nouvelle string. La string qui sera ce que retourne get_next_line.

### **char *read_new_saved(char *saved) :**

- Créer une boucle qui s’incrémentera jusqu’à la fin de **saved && saved ≠ ‘\n’.**
- Allouer la mémoire pour la nouvelle string qui sera le nouvel emplacement de **saved**. La mémoire aura la taille **ft_strlen(saved)** - i + 1.
- Ensuite faire le transfert de **saved** → nouvelle string.
- Libérer l’espace de **saved**
- Retourner la nouvelle string.
