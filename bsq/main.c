#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int     chars(char *map_chars, int map)
{
    char    ch;
    read(map, &ch, 1);
    read(map, &map_chars[0], 4);
    map_chars[3] = 0;
    // The size needed for the malloc down there
    return (ch - '0');
}

char     *first_line(int map, int *lenght)
{
    char    ch;
    char    *map_line;
    char    str[100];
    int     i;

    *lenght = 0;
    while (ch != '\n')
    {
        read(map, &ch, 1);
        str[*lenght] = ch;
        *lenght = *lenght + 1;
    }
    map_line = malloc(*lenght);
    i = -1;
    while (++i < *lenght)
        map_line[i] = str[i];
    return (map_line);
}

char    *create_array(int map, char **map_array, char *map_chars, int *lenght)
{
    int     size;
    int     i;

    i = 1;
    size = chars(map_chars, map);

    free(map_array);

    map_array = malloc(size + 1);
    map_array[0] = first_line(map, lenght);
    printf("map_array[0]: %s\n", map_array[0]);

    while (i < size)
    {
        map_array[i] = malloc(*lenght);
        read(map, map_array[i], *lenght);
        i++;
    }
    map_array[i] = NULL;
    return (map_array[0]);
}

int main(int argc, char **argv)
{
    int     map;
    int     i;
    char    **map_array;
    char    *map_chars;
    int     lenght;

    lenght = 0;
    map_chars = malloc(4);
    map_array = malloc(1);
    if (argc < 2)
    {
        write(1, "\n", 1);
        exit(1);
    }
    map = open(argv[1], O_RDONLY);
    map_array[0] = create_array(map, map_array, map_chars, &lenght);
    i = 0;
    printf("map_array[0]: %s\n", map_array[0]);
    printf("Debug:\n\n%d%s\n", lenght, map_chars);
    while (map_array[i] != NULL)
    {
        write(1, map_array[i], lenght);
        i++;
    }
    close(map);
}
