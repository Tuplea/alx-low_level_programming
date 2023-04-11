#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * Prints an error message to stderr and exits with status code 98
 */
void print_error(char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
 * The main function
 */
int main(int argc, char *argv[])
{
/* Check the command line arguments */
if (argc != 2)
{
	print_error("Usage: elf_header elf_filename");
}

/* Open the ELF file */
int fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
	print_error("Cannot open file");
}

/* Read the ELF header */
Elf64_Ehdr ehdr;
if (read(fd, &ehdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
{
	print_error("Cannot read ELF header");
}

/* Check if it's a valid ELF file */
if (ehdr.e_ident[EI_MAG0] != ELFMAG0 || 
		ehdr.e_ident[EI_MAG1] != ELFMAG1 || 
		ehdr.e_ident[EI_MAG2] != ELFMAG2 || 
		ehdr.e_ident[EI_MAG3] != ELFMAG3)
{
	    print_error("Not an ELF file");
}

/* Print the ELF header information */
printf("Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", ehdr.e_ident[i]);
}
printf("\n");

/* Print the class */
printf("Class:                             %s\n",
	       	ehdr.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");

/* Print the data encoding */
printf("Data:                              %s\n", 
		ehdr.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, 
		little endian" : "2's complement, big endian");

/* Print the ELF version */
printf("Version:                           %d (current)\n", 
		ehdr.e_ident[EI_VERSION]);

/* Print the OS/ABI */
printf("OS/ABI:                            %s\n", 
		ehdr.e_ident[EI_OSABI] == ELFOSABI_SYSV ?
	       	"UNIX System V ABI" : "Other");

/* Print the ABI version */
printf("ABI Version:                       %d\n", 
		ehdr.e_ident[EI_ABIVERSION]);

/* Print the type */
printf("Type:                              %s\n", 
		ehdr.e_type == ET_NONE ? "NONE (No file type)" :
                                                        ehdr.e_type == ET_REL ? 
							"REL (Relocatable file)" :
                                                        ehdr.e_type == ET_EXEC ? "EXEC (Executable file)" :
                                                        ehdr.e_type == ET_DYN ? "DYN (Shared object file)" :
                                                        ehdr.e_type == ET_CORE ? "CORE (Core file)" :
                                                        "Other");

/* Print the entry point address */
printf("Entry point address:               %lx\n", 
		(unsigned long) ehdr.e_entry);

/* Print the start of program headers */
printf("Start of program headers:          %ld (bytes into file)\n",
	       	(long) ehdr.e_phoff);

/* Print the start of section headers */
printf("Start of section headers:          %ld (bytes into file)\n", 
		(long) ehdr.e_shoff);
/* Print the flags
