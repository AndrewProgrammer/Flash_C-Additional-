#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main (int argc, char **argv)
{
	char *myText[] {
			"Lorem ipsum dolor sit amet, consectetuer adipiscing elit. \n",
			"Maecenas porttitor congue massa.",
			"Fusce posuere, magna sed pulvinar ultricies, purus lectus malesuada libero, sit amet commodo magna eros quis urna.",
			"Nunc viverra imperdiet enim. Fusce est. Vivamus a tellus.",
			"Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.",
			"Proin pharetra nonummy pede.",
			"Mauris et orci."
	};


	FILE *fMyFile = fopen ("lorem.txt", "w"); // ���� ����� ���, �� ����� ������. ���� �� ����������, �� ���������� ����� �������.

	if (!fMyFile)
	{
		perror ("Error while opening file: ");
		return EXIT_FAILURE;
	}

	int stringsCount = sizeof (myText) / sizeof (char *);
	for (int i = 0; i < stringsCount; i++)
	{
		// ������� fputs ���������� ������ � ����.
		// ���� ��� ������ �� ���� ������ ������������ ��������������� ��������.
		if (fputs (myText[i], fMyFile) < 0)
		{
			printf ("Error during writing!");
			perror ("Error text: ");
			fclose (fMyFile); // �� �������� ������� ���� ����� ������� �� ���������
			return EXIT_FAILURE;
		}
		
	}


	fclose (fMyFile);
	printf ("File had been successfully written!\n");

	return EXIT_SUCCESS;
}