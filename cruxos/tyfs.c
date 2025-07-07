#include "bios1.h"

#define DIR_ENTRY_LEN 32  /* Max file name length in bytes.           */
#define FS_SIGLEN 4              /* Signature length.                        */

struct fs_header_t
{
  unsigned char signature[FS_SIGLEN];     /* The file system signature.              */
  unsigned short total_number_of_sectors; /* Number of 512-byte disk blocks.         */
  unsigned short number_of_boot_sectors;  /* Sectors reserved for boot code.         */
  unsigned short number_of_file_entries;  /* Maximum number of files in the disk.    */
  unsigned short max_file_size;           /* Maximum size of a file in blocks.       */
  unsigned int unused_space;              /* Remaining space less than max_file_size.*/
} __attribute__((packed)) fs_header;      /* Disable alignment to preserve offsets.  */

extern char _DIR_ADDR[];

void load_dir();

void f_list() {
    char *directories = _DIR_ADDR;
    struct fs_header_t *header = 0x7c00;

    load_dir();

    for (int i = 0; i < header->number_of_file_entries; i++) {
        char *dir = directories+(i*DIR_ENTRY_LEN);
        if (*dir) {
            kwrite(dir);
            kwrite("\n");
        }
    }
}
