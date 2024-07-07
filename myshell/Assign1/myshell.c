#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<readline/readline.h>
#include<readline/history.h>
int main() {
	char* line;
	char hostname[1000];
	char cwd[1000];
	char* user_name;
	char a[]="@";
	char b[]=":";

	while(1) {
		char* user_name =getlogin();
		gethostname(hostname,1000);
		getcwd(cwd,1000);
	strcat(user_name,a);
	strcat(user_name,cwd);
	strcat(user_name,":");
	line=readline(user_name);
	if (strlen(line) > 0)
    {
      add_history(line);
    if (strcmp(line, "help") == 0)system("bash -c help");
    else if (strcmp(line, "exit") == 0)
    {
      printf("exiting my shell\n");
      break;
    }
	else {system(line);}
    }
	   }
	return 0;
}
