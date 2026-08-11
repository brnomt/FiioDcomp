/* File.h — file handle typedefs (Debug2.c). */
#ifndef FILE_H
#define FILE_H
#include "typedef.h"
#include "FileInfo.h"
typedef struct { void *pData; } FILE_HANDLE;
#endif

/* ---- file I/O API (audio_file_access.c) ---- */
#ifndef FILE_IO_API
#define FILE_IO_API
API int  FileOpen(void *handle, const char *path, int mode);
API int  FileClose(void *handle);
API int  FileRead(void *handle, void *buf, int size);
API int  FileWrite(void *handle, const void *buf, int size, int param);
API int  FileSeek(void *handle, int offset, int whence);
API int  FileEof(void *handle);
#endif
