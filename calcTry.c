#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define END '#'

char qeueu[5];
char result[50];
int count = 0;
int rcount = 0;
char msg[50];
void switching(char temp)
{
	char tmp;
	switch(temp)
	{
		case ADD:
		{
		if(count != 0 && qeueu[count-1] == DIV)
		{
		result[rcount] = qeueu[count-1];qeueu[count-1] = temp;rcount++;break;
		}
		else if(count != 0 && qeueu[count-1] == MUL)
		{
		result[rcount] = qeueu[count-1];qeueu[count-1] = temp;rcount++;break;
		}
		else if(count != 0 && qeueu[count-1] == ADD)
		{
		result[rcount] = temp;rcount++;break;
		}
		else if(count != 0 && qeueu[count-1] == SUB)
		{
		result[rcount] = qeueu[count-1];qeueu[count-1] = temp;rcount++;break;
		}
		else if(count == 0)
		{
		qeueu[count] = temp;count++;break;
		}
		}
		case SUB:
		{
		if(count != 0 && qeueu[count-1] == SUB)
		{
		result[rcount] = temp;rcount++;break;
		}
		else if(count != 0 && qeueu[count-1] == ADD)
		{
		result[rcount] = qeueu[count-1];qeueu[count-1] = temp;rcount++;break;
		}
		else if(count != 0 && qeueu[count-1] == MUL)
		{
		result[rcount] = qeueu[count-1];qeueu[count-1] = temp;rcount++;break;
		}
		else if(count != 0 && qeueu[count-1] == DIV)
		{
		result[rcount] = qeueu[count-1];qeueu[count-1] = temp;rcount++;break;
		}
		else if(count == 0)
		{
		qeueu[count] = temp;count++;break;
		}
		}
		case MUL:
		{
		if(count != 0 && qeueu[count-1] == MUL)
		{
		result[rcount] = temp;rcount++;break;
		}
		else if(count != 0 && qeueu[count-1] == DIV)
		{
		result[rcount] = qeueu[count-1];qeueu[count-1] = temp;rcount++;break;
		}
		else if(count != 0 && qeueu[count-1] == ADD)
		{
		qeueu[count] = temp;count++;break;
		}
		else if(count != 0 && qeueu[count-1] == SUB)
		{
		qeueu[count] = temp;count++;break;
		}
		else if(count == 0)
		{
		qeueu[count] = temp;count++;break;
		}
		}
		case DIV:
		{
		if(count != 0 && qeueu[count-1] == DIV)
		{
		result[rcount] = temp;rcount++;break;
		}
		else if(count != 0 && qeueu[count-1] == MUL)
		{
		result[rcount] = qeueu[count-1];qeueu[count-1] = temp;rcount++;break;
		}
		else if(count != 0 && qeueu[count-1] == ADD)
		{
		qeueu[count] = temp;count++;break;
		}
		else if(count != 0 && qeueu[count-1] == SUB)
		{
		qeueu[count] = temp;count++;break;
		}
		else if(count == 0)
		{
		qeueu[count] = temp;count++;break;
		}
		}
		default:result[rcount] = temp;rcount++;break;

	}



}
void pop()
{
	int i;
	count--;
	for(i = 0;i<=sizeof(qeueu);i++)
	{
		if(qeueu[count] != DIV && qeueu[count] != MUL && qeueu[count] != SUB && qeueu[count] != ADD)
		{
		break;
		}
		else
		{
		result[rcount] = qeueu[count];
		rcount++;count--;
		}
	}
}
int calc(char rsl[])
{
	int i, tres;
	int k =0;
	int j = 0;
	int res = 0;
	int tnum[10];
	int tmp;
	char rslt[30];
	strcpy(rslt, rsl);
	for(i = 0;i<sizeof(rslt);i++)
	{
		if(rslt[i] == NULL)
		{
		break;
		}
		else
		{
			switch(rslt[i])
			{
			case ADD:
			{
			if(j == 0)
			{
			perror("An operation without operands! ADD");
			break;
			}
			else if(j > 1)
			{
			tnum[j-2] += tnum[j-1];
			j--;
			break;
			}
			}
			case SUB:
			{
			if(j == 0)
			{
			perror("An operation without operands SUB");
			break;
			}
			else if(j > 0)
			{
			tnum[j-2] -= tnum[j-1];
			j--;
			break;
			}
			}
			case MUL:
			{
			if(j == 0)
			{
			perror("An operation without operands! MUL");
			break;
			}
			else if(j > 1)
			{
			tnum[j-2] *= tnum[j-1];
			j--;
			break;
			}
			}
			case DIV:
			{
			if(j == 0)
			{
			perror("An operation without operands!!! DIV");
			break;
			}
			else if(j > 1)
			{
			tnum[j-2] /= tnum[j-1];
			j--;
			break;
			}
			}
			default:
			{
			switch(rslt[i])
			{
			case '0':
			{
			tnum[j] = 0;
			j++;
			break;
			}
			case '1':
			{
			tnum[j] = 1;j++;
			break;
			}
			case '2':
			{
			tnum[j] = 2;j++;
			break;
			}
			case '3':
			{
			tnum[j] = 3;j++;
			break;
			}
			case '4':
			{
			tnum[j] = 4;j++;
			break;
			}
			case '5':
			{
			tnum[j] = 5;j++;
			break;
			}
			case '6':
			{
			tnum[j] = 6;j++;
			break;
			}
			case '7':
			{
			tnum[j] = 7;j++;
			break;
			}
			case '8':
			{
			tnum[j] = 8;j++;
			break;
			}
			case '9':
			{
			tnum[j] = 9;j++;
			break;
			}
			}
			break;
			}
			}
		}
	}
	printf("Result: %d\n", tnum[0]);
	return tnum[0];
}
int main()
{
	int flag = 1;
	int i;
	int k = 0;
	char tmsg;
	char rmsg[30];
	char temp;
	char tmp;
	char buff[50];
	char res[50];
	int pipefd[2];
	int pipeid = pipe(pipefd);
	int pid = fork();
	if(pipeid == -1)
	{
	perror("pipe failed");
	return 1;
	}
	if(pid == -1)
	{
	perror("fork failed");
	return 1;
	}
	else if(pid > 0)
	{
	FILE *fp;
	close(pipefd[1]);
	wait(NULL);
	printf("Parent starts!");
	while(read(pipefd[0], &tmsg, 1) > 0)
	{
	rmsg[k] = tmsg;
	k++;
	}
	//calc(rmsg);
	fp = fopen("tmp/test.txt", "w+");
	fprintf(fp,"Your result: %d", calc(rmsg));
	fclose(fp);
	}
	else if(pid == 0)
	{
	printf("Child starts!");
	printf("Input:");
	scanf("%s", buff);
	printf("Your input is: %s\n", buff);
	strcat(buff, "#");

		for(i = 0;i<sizeof(buff); i++)
		{
			temp = buff[i];
		if(temp != END)
		{
			switching(temp);
		}
		else if(temp == END)
		{
		pop();
		strcpy(msg, result);
		close(pipefd[0]);
		write(pipefd[1], &msg, strlen(msg));
		printf("Your input after Shunting Yard: %s\n", result);
		}
	}
}
	return 0;
}
