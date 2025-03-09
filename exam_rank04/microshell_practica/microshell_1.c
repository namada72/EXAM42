#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int err (char *s, char *av)
{
	while(*s)
		write(2, s++, 1);
	if (av)
	{
		write(2, " ", 1);
		while (*av)
			write(2, av++, 1);
	}
	write(2, "\n", 1);
	return(1);
}
int cd(char **av, int i)
{
	if(i !=2)
	{
		return (err("error: cd: bad arguments", NULL));
	}
	if (chdir(av[1]) == -1)
	{
		return (err("error: cd: cannot change directory to", av[1]));
	}
	return (0);
}

int exec(char **av, char **envp, int i)
{
	int status;
	int fd[2];
	int pipes = (av[i] && !strcmp(av[i], "|"));

	if(pipes && pipe(fd) == -1)
		return (err("error: fatal", NULL));
	int pid = fork();
	if(!pid)
	{
		av[i] = 0;
		if (pipes && (dup2(fd[1], 1) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
			return (err("error: fatal", NULL));
		execve(*av, av, envp);
		return (err("error: cannot execute", *av));
	}
	waitpid(pid, &status, 0);
	if (pipes &&(dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1 ))
		return (err("error: fatal", NULL));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	int status;

	while (*av && *(av +1))
	{
		av++;
		int i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if(strcmp(*av, "cd") ==0)
			status = cd(av, i);
		else if (i)
			status = exec(av, envp, i);
		av +=i;
	}
	return (status);
}
