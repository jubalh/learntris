#include <stdio.h>

#define COLS 10
#define ROWS 22

char matrix[ROWS][COLS];

typedef enum action {
	ACTION_NONE,
	ACTION_P,
} action;

void
init_matrix()
{
	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++) {
			matrix[i][j] = '.';
		}
	}
}

void
print_matrix()
{
	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++) {
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}
}

action read_user_input()
{
	int ret;
	char c;

	ret = scanf("%c", &c);
	if (ret == 1)
	{
		if (c == 'p')
			return ACTION_P;
	}
	return ACTION_NONE;
}

int
main(int argc, char const* argv[])
{
	action user_action;

	init_matrix();
	user_action = read_user_input();
	switch (user_action) {
	case ACTION_P:
		print_matrix();
		break;
	case ACTION_NONE:
	default:
		break;
	}

	return 0;
}
