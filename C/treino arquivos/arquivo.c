#include <stdio.h>

int main(void) {
  FILE *fp;
  fp = fopen("arquivoo.txt", "w");
  char ch;
  
  if (fp != NULL) {  // Check if file is opened successfully
    fprintf(fp, "Hello, this is a test!\n");
    fputs("Hello, this is a test!\n", fp);

    fseek(fp, -50, SEEK_END);  // Move pointer 50 bytes from the end
    while ((ch = fgetc(fp)) != EOF) { // Read and print from the current position to the end
      putchar(ch);
    }

    fclose(fp);  // Close the file after use
  } else {
    printf("Failed to open the file.\n");
  }

  return 0;
}
