/** @file fileio.h
 * @brief ANSI FILE* clone API declarations.
 */
#ifndef INCLUDED_fileio_h
#define INCLUDED_fileio_h

#ifndef INCLUDED_sys_types_h
#include <sys/types.h>          /* size_t */
#define INCLUDED_sys_types_h
#endif

struct stat;

/** A mirror of the ANSI FILE struct, but it works for any
 * file descriptor. FileBufs are allocated when a file is opened with
 * fbopen, and they are freed when the file is closed using fbclose.
 * (Some OSes limit the range of file descriptors in a FILE*, for
 * example to fit in "char".)
 */
typedef struct FileBuf FBFILE;

/*
 * open a file and return a FBFILE*, see fopen(3)
 */
extern FBFILE *fbopen(const char *filename, const char *mode);
/*
 * close a file opened with fbopen, see fclose(3)
 */
extern void fbclose(FBFILE * fb);
/*
 * return the next character from the file, EOF on end of file
 * see fgetc(3)
 */
extern int fbgetc(FBFILE * fb);
/*
 * return next string in a file up to and including the newline character
 * see fgets(3)
 */
extern char *fbgets(char *buf, size_t len, FBFILE * fb);
/*
 * write a null terminated string to a file, see fputs(3)
 */
extern int fbputs(const char *str, FBFILE * fb);
/*
 * return the status of the file associated with fb, see fstat(3)
 */
extern int fbstat(struct stat *sb, FBFILE * fb);

#endif /* INCLUDED_fileio_h */
