#include "myheader.h"
void grep(char pattern[], char filename[])
{
    char line[1024];
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: could not open file ");
    }
    while (fgets(line, 1024, file))
    {
        if (strstr(line, pattern))
        {
            printf("%s", line);
        }
    }
    fclose(file);
}
void grep_H(char pattern[], char filename[])
{
    char line[1024];
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: could not open file ");
    }
    while (fgets(line, 1024, file))
    {
        if (strstr(line, pattern))
        {
            printf("%s     %s", filename, line);
        }
    }
    fclose(file);
}
void grep_n(char pattern[], char filename[])
{
    char line[1024];
    int count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: could not open file ");
    }
    while (fgets(line, 1024, file))
    {
        count++;
        if (strstr(line, pattern))
        {
            printf("%d:    %s", count, line);
        }
    }
    fclose(file);
}
void grep_c(char pattern[], char filename[])
{
    char line[1024];
    int count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: could not open file ");
    }
    while (fgets(line, 1024, file))
    {
        if (strstr(line, pattern))
        {
            count++;
        }
    }
    printf("%d\n", count);
    fclose(file);
}
void grep_v(char pattern[], char filename[])
{
    char line[1024];
    int count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: could not open file ");
    }
    while (fgets(line, 1024, file))
    {
        if (!strstr(line, pattern))
        {
            printf("%s", line);
        }
    }
    fclose(file);
}