#include "myheader.h"
void mv(char sourcefile[], char destfile[])
{
    FILE *src_file = fopen(sourcefile, "rb");
    if(src_file==NULL) { 
    printf("source file doesn't exit\n");
    return;
  }
    FILE *dest_file = fopen(destfile, "wb");
    char string[1024];
    size_t bytes_read;
    while ((bytes_read = fread(string, 1, sizeof(string), src_file)) > 0)
    {
        fwrite(string, 1, bytes_read, dest_file);
    }
    fclose(src_file);
    fclose(dest_file);
    remove(sourcefile);
}