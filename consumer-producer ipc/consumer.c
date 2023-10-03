#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <time.h>


pid_t get_pid ();
void sig_handler_consumer (int signum);
size_t printRandoms (int, int, int);


int main ()
{
	signal(SIGUSR1, sig_handler_consumer);

	srand(time(0));

	while (1)
	{
		printf("\n[-] Waiting ...");
		sleep(1);
	}

	return 0;
}


void sig_handler_consumer (int signum)
{
	printf("\n\n--------------------------------------------------");
	printf("\n\n[+] Consumer takes over!! Wait to check the code...");
	fflush(stdin);
	fflush(stdout);
	sleep (printRandoms(3, 7, 1));

	FILE *fp;
	fp = fopen("secret.txt", "r");
	
	printf("\n--> Secret code is :  ");
	char c; 
	int count = 0;
	while((c = fgetc(fp)) != EOF)
	{
		if(c == ' ' || c == '\n')
		{
			printf("\n");
			++count;
		}
		else
		{
			printf("%c", c);
		}
	}

	fclose(fp);
	sleep(1);

	printf("\n\n---------------------------------------------------");
	fflush(stdout);
	fflush(stdin);

	pid_t pid;
	pid = get_pid ();

	kill (pid,SIGUSR1);

}




pid_t get_pid ()
{
	FILE *fp;
	char *command;
	command = malloc(sizeof("pgrep producer | head -1 "));
	strcpy(command, "pgrep producer | head -1");

	/* command contains the command string (a character array) */
	/* If you want to read output from command */
	fp = popen(command,"r"); 
	/* read output from command */
	pid_t pid;
	fscanf(fp, "%d", &pid);   /* or other STDIO input functions */
     
	fclose(fp);

	return pid;
}




size_t printRandoms(int lower, int upper,
                             int count)
{
        size_t num = (rand() % (upper - lower + 1)) + lower;
	return num;
}
