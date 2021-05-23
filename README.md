# GNL The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: "static variables"

Function Prototype
int	get_next_line(int fd, char **line);
Compilation
GNL Mandatory Part

Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used as the buffer size for the read calls in your get_next_line.

Make sure that your function behaves well when it reads from a file and when it reads from the standard input.

