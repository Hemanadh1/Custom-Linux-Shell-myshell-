#include "myheader.h"
struct fileprop
{
  char file_name[1024];
  double file_size;
  int links;
  char ownerid[1024];
  char userid[1024];
};
void sort(struct fileprop arr[], int count)
{
  struct fileprop temp;
  for (int i = 0; i < count; i++)
  {
    for (int j = i + 1; j < count; j++)
    {
      if (strcmp(arr[i].file_name, arr[j].file_name) > 0)
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
void bubblesort(struct fileprop arr[], int count)
{
  struct fileprop temp;
  for (int i = 0; i < count; i++)
  {
    for (int j = i + 1; j < count; j++)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
}
void ls_U(struct fileprop arr[])
{
  DIR *dir;
  struct dirent *ent;
  dir = opendir(".");
  if (dir == NULL)
  {
    printf("Failed to open directory.\n");
  }
  while ((ent = readdir(dir)) != NULL)
  {
    if (ent->d_name[0] == '.')
    {
      continue;
    }
    printf("%s ", ent->d_name);
  }
  puts("");
}
void ls_l(struct fileprop arr[])
{
  DIR *dir;
  int i = 0;
  int j = 0;
  int count = 0;
  struct dirent *ent;
  struct stat file_stat;
  struct group *gr;
  struct passwd *pw;
  char time_str[500];
  dir = opendir(".");
  if (dir == NULL)
  {
    printf("Failed to open directory.\n");
  }
  while ((ent = readdir(dir)) != NULL)
  {
    if (ent->d_name[0] != '.')
    {
      strcpy(arr[i].file_name, ent->d_name);
      i++;
      count++;
    }
  }
  sort(arr, count);
  dir = opendir(".");
  struct dirent *e;
  while ((e = readdir(dir)) != NULL)
  {
    if (stat(arr[j].file_name, &file_stat) != -1)
    {
      printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
      printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
      printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
      printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
      printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
      printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
      printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
      printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
      printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
      printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
      printf(" %ld", file_stat.st_nlink);
      pw = getpwuid(file_stat.st_uid);
      printf(" %s", pw->pw_name);
      gr = getgrgid(file_stat.st_gid);
      printf(" %s", gr->gr_name);
      printf(" %10ld", file_stat.st_size);
      strftime(time_str, sizeof(time_str), "%b %d %H:%M", localtime(&file_stat.st_mtime));
      printf(" %s", time_str);
      printf(" %s\n", arr[j].file_name);
    }
    j++;
  }
}
void ls(struct fileprop arr[])
{
  int i = 0;
  int count;
  DIR *dir;
  struct dirent *ent;
  dir = opendir(".");
  if (dir == NULL)
  {
    printf("Failed to open directory.\n");
  }
  while ((ent = readdir(dir)) != NULL)
  {
    if (ent->d_name[0] != '.')
    {
      strcpy(arr[i].file_name, ent->d_name);
      i++;
      count++;
    }
  }
  sort(arr, count);
  for (int j = 0; j < count; j++)
  {
    printf("%s ", arr[j].file_name);
  }
  puts("");
}
void ls_a(struct fileprop arr[])
{
  int i = 0;
  int count;
  DIR *dir;
  struct dirent *ent;
  dir = opendir(".");
  if (dir == NULL)
  {
    printf("Failed to open directory.\n");
  }
  while ((ent = readdir(dir)) != NULL)
  {
    strcpy(arr[i].file_name, ent->d_name);
    i++;
    count++;
  }
  sort(arr, count);
  for (int j = 0; j < count; j++)
  {
    printf("%s ", arr[j].file_name);
  }
  puts("");
}
void ls_S(struct fileprop arr[])
{

  int count = 0;
  int i = 0;
  DIR *dir;
  struct dirent *ent;
  dir = opendir(".");
  if (dir == NULL)
  {
    printf("Failed to open directory.\n");
  }
  while ((ent = readdir(dir)) != NULL)
  {
    struct stat file_stat;
    if (ent->d_name[0] == '.')
    {
      continue;
    }
    strcpy(arr[i].file_name, ent->d_name);
    i++;
    count++;
    if (stat(arr[i].file_name, &file_stat) != -1)
    {
      arr[i].file_size = file_stat.st_size;
      bubblesort(arr, count);
    }
  }
  for (int j = 0; j < count; j++)
  {
    printf("%s ", arr[j].file_name);
  }
  puts("");
}

int main()
{
  while (1)
  {
    char hostname[1000];
    char cwd[1000];
    char a[] = "@";
    char b[] = ":";
    struct fileprop arr[1024];
    char *line;
    char *user_name = getlogin();
    gethostname(hostname, 1000);
    getcwd(cwd, 1000);
    strcat(user_name, a);
    strcat(user_name, hostname);
    strcat(user_name, b);
    strcat(user_name, cwd);
    strcat(user_name, "$");
    line = readline(user_name);
    if (strlen(line) > 0)
    {
      add_history(line);
    if (strcmp(line, "help") == 0)system("bash -c help");
    else if (strcmp(line, "exit") == 0)
    {
      printf("exiting my shell\n");
      break;
    }
    }
    char *store[100] = {"hi"};
    int t = 0;
    int p = 0;
    char sourcefile[1000];
    char destfile[1000];
    char input[1000];
    char pattern[1024];
    char filename[1024];
    struct stat file_stat;
    char c;
    char *token = strtok(line, " ");
    while (token != NULL)
    {
      store[t] = token;
      t++;
      token = strtok(NULL, " ");
    }
    if (!strcmp(store[0], "ls"))
    {
      if (t == 1)
      {
        ls(arr);
      }
     else if (t == 2)
      {
        if (strcmp(store[1], "-l") == 0)
        {
          ls_l(arr);
        }
        if (strcmp(store[1], "-U") == 0)
        {
          ls_U(arr);
        }
        if (strcmp(store[1], "-S") == 0)
        {
          ls_S(arr);
        }
        if (strcmp(store[1], "-a") == 0)
        {
          ls_a(arr);
        }
      }
    }
     else if (!strcmp(store[0], "cp"))
    {
      if (t == 3)
      {
        strcpy(sourcefile, store[1]);
        strcpy(destfile, store[2]);
        if (stat(destfile, &file_stat) != -1)
        {
          c = (S_ISDIR(file_stat.st_mode) ? 'd' : '-');
          if (c == 'd')
          {
            strcat(destfile, "/");
            strcat(destfile, sourcefile);
            cp(sourcefile, destfile);
          }
        }
          else
          {
            cp(sourcefile, destfile);
          }
      }
      if (t == 4 && strcmp(store[1], "-v") == 0)
      {
        strcpy(sourcefile, store[2]);
        strcpy(destfile, store[3]);
        if (stat(destfile, &file_stat) != -1)
        {
          c = (S_ISDIR(file_stat.st_mode) ? 'd' : '-');
          if (c == 'd')
          {
            strcat(destfile, "/");
            strcat(destfile, sourcefile);
            cp(sourcefile, destfile);
            printf("'%s' -> '%s'\n", sourcefile, destfile);
          }
        }
          else
          {
            cp(sourcefile, destfile);
            printf("'%s' -> '%s'\n", sourcefile, destfile);
          }
        }
      if (t == 4 && strcmp(store[1], "-i") == 0)
      {
        strcpy(sourcefile, store[2]);
        strcpy(destfile, store[3]);
        DIR *dir;
        struct dirent *ent;
        dir = opendir(".");
        if (dir == NULL)
        {
          printf("Failed to open directory.\n");
        }
        while ((ent = readdir(dir)) != NULL)
        {
          if (strcmp(ent->d_name, destfile) == 0)
          {
            p++;
          }
        }
        if (p == 1)
        {
          printf("cp: overwrite '%s'?", destfile);
          scanf("%s", input);
          if (strcmp(input, "y") == 0)
          {
            cp(sourcefile, destfile);
          }
        }
        else
        {
          cp(sourcefile, destfile);
        }
      }
      if (t == 4 && strcmp(store[1], "-n") == 0)
      {
        strcpy(sourcefile, store[2]);
       
        strcpy(destfile, store[3]);
        DIR *dir;
        struct dirent *ent;
        dir = opendir(".");
        if (dir == NULL)
        {
          printf("Failed to open directory.\n");
        }
        while ((ent = readdir(dir)) != NULL)
        {
          if (strcmp(ent->d_name, destfile) == 0)
          {
            p++;
          }
        }
        if (p == 0)
        {
          cp(sourcefile, destfile);
        }
      }
      if (t == 4 && strcmp(store[1], "-f") == 0)
      {
        strcpy(sourcefile, store[2]);
        strcpy(destfile, store[3]);
        DIR *dir;
        struct dirent *ent;
        dir = opendir(".");
        if (dir == NULL)
        {
          printf("Failed to open directory.\n");
        }
        while ((ent = readdir(dir)) != NULL)
        {
          if (strcmp(ent->d_name, destfile) == 0)
          {
            p++;
          }
        }
        if (p == 0)
        {
          cp(sourcefile, destfile);
        }
        else
        {
          remove(destfile);
          cp(sourcefile, destfile);
        }
      }
    }
   else if (!strcmp(store[0], "mv"))
    {
      if (t == 3)
      {
        strcpy(sourcefile, store[1]);
        strcpy(destfile, store[2]);
        if (stat(destfile, &file_stat) != -1)
        {
          c = (S_ISDIR(file_stat.st_mode) ? 'd' : '-');
          if (c == 'd')
          {
            strcat(destfile, "/");
            strcat(destfile, sourcefile);
            mv(sourcefile, destfile);
          }
        }
          else
          {
            mv(sourcefile, destfile);
          }
      }
      if (t == 4 && strcmp(store[1], "-v") == 0)
      {
        strcpy(sourcefile, store[2]);
        strcpy(destfile, store[3]);
        if (stat(destfile, &file_stat) != -1)
        {
          c = (S_ISDIR(file_stat.st_mode) ? 'd' : '-');
          if (c == 'd')
          {
            strcat(destfile, "/");
            strcat(destfile, sourcefile);
            mv(sourcefile, destfile);
            printf("'%s' -> '%s'\n", sourcefile, destfile);
          }
        }
          else
          {
            mv(sourcefile, destfile);
            printf("'%s' -> '%s'\n", sourcefile, destfile);
          }
      }
      if (t == 4 && strcmp(store[1], "-i") == 0)
      {
        strcpy(sourcefile, store[2]);
        strcpy(destfile, store[3]);
        DIR *dir;
        struct dirent *ent;
        dir = opendir(".");
        if (dir == NULL)
        {
          printf("Failed to open directory.\n");
        }
        while ((ent = readdir(dir)) != NULL)
        {
          if (strcmp(ent->d_name, destfile) == 0)
          {
            p++;
          }
        }
        if (p == 1)
        {
          printf("mv: overwrite '%s'?", destfile);
          scanf("%s", input);
          if (strcmp(input, "y") == 0)
          {
            mv(sourcefile, destfile);
          }
        }
        else
        {
          mv(sourcefile, destfile);
        }
      }
      if (t == 4 && strcmp(store[1], "-n") == 0)
      {
        strcpy(sourcefile, store[2]);
        strcpy(destfile, store[3]);
        DIR *dir;
        struct dirent *ent;
        dir = opendir(".");
        if (dir == NULL)
        {
          printf("Failed to open directory.\n");
        }
        while ((ent = readdir(dir)) != NULL)
        {
          if (strcmp(ent->d_name, destfile) == 0)
          {
            p++;
          }
        }
        if (p == 0)
        {
          mv(sourcefile, destfile);
        }
      }
      if (t == 4 && strcmp(store[1], "-f") == 0)
      {
        strcpy(sourcefile, store[2]);
        strcpy(destfile, store[3]);
        DIR *dir;
        struct dirent *ent;
        dir = opendir(".");
        if (dir == NULL)
        {
          printf("Failed to open directory.\n");
        }
        while ((ent = readdir(dir)) != NULL)
        {
          if (strcmp(ent->d_name, destfile) == 0)
          {
            p++;
          }
        }
        if (p == 0)
        {
          mv(sourcefile, destfile);
        }
        else
        {
          remove(destfile);
          mv(sourcefile, destfile);
        }
      }
    }
   else if (!strcmp(store[0], "grep"))
    {
      if (t == 3)
      {
        strcpy(pattern, store[1]);
        strcpy(filename, store[2]);
        grep(pattern, filename);
      }
      if (t == 4 && strcmp(store[1], "-H") == 0)
      {
        strcpy(pattern, store[2]);
        strcpy(filename, store[3]);
        grep_H(pattern, filename);
      }
      if (t == 4 && strcmp(store[1], "-n") == 0)
      {
        strcpy(pattern, store[2]);
        strcpy(filename, store[3]);
        grep_n(pattern, filename);
      }
      if (t == 4 && strcmp(store[1], "-c") == 0)
      {
        strcpy(pattern, store[2]);
        strcpy(filename, store[3]);
        grep_c(pattern, filename);
      }
      if (t == 4 && strcmp(store[1], "-v") == 0)
      {
        strcpy(pattern, store[2]);
        strcpy(filename, store[3]);
        grep_v(pattern, filename);
      }
    }
  }
}

