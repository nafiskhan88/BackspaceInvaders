#ifndef STORAGE_H
#define STORAGE_H

#include <stdlib.h>
#include <stdint.h>

#define STORAGE_CLOSED 0
#define STORAGE_READ 1
#define STORAGE_WRITE 2
#define STORAGE_FAILED 0xff
#define STORAGE_EOF 0xff

#define MAX_OPEN_FILES 4

void storage_init();
void storage_format();

uint8_t storage_open(const char *name, uint8_t mode);

void storage_write_byte(uint8_t sd, uint8_t value);
void storage_write_word(uint8_t sd, uint16_t value);
void storage_write_dword(uint8_t sd, uint32_t value);
size_t storage_write(uint8_t sd, void* buffer, size_t size); // returns amount of bytes written

uint8_t storage_read_byte(uint8_t sd);
uint16_t storage_read_word(uint8_t sd);
uint32_t storage_read_dword(uint8_t sd);
size_t storage_read(uint8_t sd, void* buffer, size_t size); // returns amount of bytes read

void storage_delete(uint8_t sd);
void storage_close(uint8_t sd);


size_t storage_read(const char *name, void* buffer, size_t size);
size_t storage_write(const char *name, void* buffer, size_t size);
void storage_delete(const char *name);

#endif