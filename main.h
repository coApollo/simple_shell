#ifndef MAIN_H
#define MAIN_H
/* Headers  */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <signal.h>
#include <stdbool.h>

/* macros */
#define EXIT (_strcmp(args[0], "exit") == 0)
#define _ABS_ 1
#define _REL_ 2
#define NULL_FOUND -2
#define CTRL_C_SIGNAL_CODE 130
#define IS_EXEC 1
#define IS_PATH 1
#define NOT_PATH 0
#define ERROR_OCCURRED -1
#define SHLVL_NAME "SHLVL"
#define SHLVL_VAL "1"
#define INVALID 127
#define VALID 0
#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_MODE 0
/**
 * struct list - A node(list) that points to environment variables
 *
 * @name: The variable's name
 * @value: The variable's value
 * @next: The next environment variable
 */
typedef struct list
{
	char *name;
	char *value;
	struct list *next;
} node_t;


/*globlal variables*/
extern char **environ;
extern int _signal_;
extern node_t *head;

/*prototypes*/
int _prompt(char **buf, size_t *bytes_read);
char **_tokenization(char *str, char *del);
int _token_count(char *str, char *del);
int _check_mode(void);
int _check_file(char *path);
int _execute(char **args, int commands_executed
, char *program, char **env);
const char *_strstr(const char *haystack, const char *needle);
void handle_sigint(int _signal_);
void _printenv(void);
char **get_envs(char **env);
char *getenv_path();
int set_envs(const char *name, const char *value, int num);
int check_envs(char *str);
node_t *addnodeend(node_t **head, char *name, char *value);
node_t *find_node(node_t *head, char *name);
void _free_str(char *str);
void _free_(char **args);
void free_list(node_t *head);
int _exit_(char **path, char **env, char *buf);
void _is_exit(char **args, char *buf, char **envpath
, int _signal_, char **env_clone);
int _isenvvarpath(char *env_var);
int _is_rel(char *path);
int _is_exec(char *path);
int _check_path(char *path);
char **_get_paths(node_t *head);
char *_abs_path(char *path, char *command);
void _rel_path(int *file, char **envpath, char **cmnds
, char *buf, int *exit_);
char *_make_path(int argc, ...);
void _putchar(char ch, int file_descriptor);
void print_number(int number);
void _printerror(int commands_executed, int arg_count, ...);
int _atoi(char *str);
void _print_str(char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t num);

#endif
