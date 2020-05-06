#include <unistd.h>
#include <fcntl.h>

int main() {
  char buffer [1];
  int inputFile = open("text.txt", O_RDONLY);
  int outputFile = open("output.txt", O_WRONLY | O_CREAT, 0644);
  int readResult = read(inputFile, buffer, 1);
  while(readResult > 0) {
    write(outputFile, buffer, 1);
    readResult = read(inputFile, buffer, 1);
  }
  close(inputFile);
  close(outputFile);
}
