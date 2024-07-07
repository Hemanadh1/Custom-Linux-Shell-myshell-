#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<sys/stat.h>
void mv(char sourcefile[], char destfile[]);
void cp(char sourcefile[], char destfile[]);
void grep(char pattern[],char filename[]);
void grep_H(char pattern[],char filename[]);
void grep_n(char pattern[],char filename[]);
void grep_c(char pattern[],char filename[]);
void grep_v(char pattern[],char filename[]);