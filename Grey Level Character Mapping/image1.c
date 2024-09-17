#include <stdio.h>

/* Map number to character accordingly */
char get_character(int levels, int level) {
	int last = levels - 1;

	if(level > last)
		return -1;

	if(level == 0)
		return '#';
	else if(level == last)
		return ' ';
	else if(level == 1) {
		if(levels == 3)
			return '.';
		else
			return ':';
	}
	else if(level == 2)
		return '.';

	return -1;
}

int main(int argc, char *argv[]) {
	int  grey_levels, level, times, width, height, i, j, k;
	char character;
	int pixels[100][80];

	scanf("%d %d %d", &width, &height, &grey_levels);
 	if(width>=80 || height >=100)
 		return -1;

	/* Store the initial numbers */
 	i=0;
 	j=0;
	while(1) {
		if(scanf("%d %d", &level, &times) == EOF)
			break;

		for(k=0; k<times; k++) {
			pixels[i][j] = level;
			j += 1;
			if(j == width) {
				i += 1;
				j=0;
			}
		}
	}

	/* Print the mapped characters */
	for(i=0; i<height; i++) {
		for(j=0; j<width; j++) {
			character = get_character(grey_levels, pixels[i][j]);
			if(character == -1)
				return -1;
			printf("%c", character);
		}
		printf("\n");
	}

	return 0;
}