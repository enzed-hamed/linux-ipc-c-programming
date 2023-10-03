#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <time.h>


pid_t get_pid ();
void sig_handler_producer (int signum);
int printRandoms (int, int, int);


int main ()
{
	signal(SIGUSR1, sig_handler_producer);

	srand(time(0));

	raise (SIGUSR1);

	while (1)
	{
		printf(".\n");
		fflush(stdin);
		fflush(stdout);
		sleep(1);
	}

	return 0;
}



void sig_handler_producer (int signum)
{
	char ch[40];
	
	strcpy(ch, "\n[+] Producer Takes over !!\n");
	
	for (size_t i=0; ch[i]!='\0'; i++)
	{
		printf("%c", ch[i]);
		usleep(50000);
		fflush(stdin);
		fflush(stdout);
	}

	sleep (printRandoms(1, 3, 1));
	

	system ("rm -f secret.txt");
	FILE *fp;
	fp = fopen("secret.txt", "w");

	char secret_code[6];
	sprintf(secret_code, "%d", printRandoms (10000, 99999, 1));
        fputs(secret_code, fp);

	fclose(fp);

	pid_t pid;
	pid = get_pid ();

	strcpy(ch, "**** Debug info");

	for (size_t i=0; ch[i]!='\0'; i++)
        {
                printf("%c", ch[i]);
                usleep(30000);
                fflush(stdin);
                fflush(stdout);
        }

	strcpy(ch, "\n--> Generated Secret Code:  ");

	for (size_t i=0; ch[i]!='\0'; i++)
        {
                printf("%c", ch[i]);
                usleep(30000);
                fflush(stdin);
                fflush(stdout);
        }

	printf("%s", secret_code);

	strcpy(ch, "\n--> Consumers Process ID:  ");
	for (size_t i=0; ch[i]!='\0'; i++)
        {
                printf("%c", ch[i]);
                usleep(30000);
                fflush(stdin);
                fflush(stdout);
        }

	printf("%d", pid);


	strcpy(ch, "\n***********************************\n\n");
	for (size_t i=0; ch[i]!='\0'; i++)
        {
                printf("%c", ch[i]);
                usleep(15000);
                fflush(stdin);
                fflush(stdout);
        }


	fflush(stdin);
	fflush(stdout);
	usleep(500000);


	kill (pid, SIGUSR1);

}




pid_t get_pid ()
{
	FILE *fp;
	char *command;
	command = malloc(sizeof("pgrep consumer | head -1 "));
	strcpy(command, "pgrep consumer | head -1");

	/* command contains the command string (a character array) */
	/* If you want to read output from command */
	fp = popen(command,"r"); 
	/* read output from command */
	pid_t pid;
	fscanf(fp, "%d", &pid);   /* or other STDIO input functions */
     
	fclose(fp);

	return pid;
}




int printRandoms(int lower, int upper,
                             int count)
{
        int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}
