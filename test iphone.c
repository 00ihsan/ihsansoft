#include <stdio.h>

int main()
{
	printf("Hello there! I wrote this on an iPhone in Linux");
	printf("Whats your name? ");
	char name[100] ={"0"};
	scanf("%s", name);
	printf("And your age is? ");
	int age = 0;
	scanf("%d", &age);
	printf("Hello %s!\nYour age is %d right?", name, age);
	if (age > 18)
	{
		printf("You can drink beer if you'd want to!");
	}
	else
	{
		printf("No beer for you!");
	}
	return 0;
}
