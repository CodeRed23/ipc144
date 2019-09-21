#include <stdio.h>

int main(void) {

	char first[31];
	char middle[7];
	char last[31];

	scanf("%30[^\n]\n(%6[^\n]|\n)%30[^\n]\n", first, middle, last);

	printf("%s-%s-%s\n", first, middle, last);

	return 0;

}
