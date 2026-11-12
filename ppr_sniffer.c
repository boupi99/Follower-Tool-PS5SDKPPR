#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
// WICHTIG: Diese Header kommen aus dem ps5-payload-sdk!
#include <ps5/kernel.h>
#include <ps5/payload.h>

typedef int (*ioctl_hook_t)(int fd, unsigned long request, void *arg);
static ioctl_hook_t original_ioctl = NULL;

int my_ioctl_hook(int fd, unsigned long request, void *arg) {
    uint32_t group = (request >> 8) & 0xFF;
    
    if (group == 0x32) {
        printf("[PPRMAP01] Abgefangen! FD: %d, Request: 0x%lx\n", fd, request);
        if (arg != NULL) {
            printf("  -> Arg-Pointer: %p\n", arg);
        }
    }

    if (original_ioctl) {
        return original_ioctl(fd, request, arg);
    }
    return -1;
}

int main() {
    printf("[*] PPR Sniffer Payload gestartet (FW 13.60)\n");
    printf("[*] Warte auf PPR-Mounts (ioctl group 0x32)...\n");
    
    while(1) {
        // Endlosschleife, um das Payload aktiv zu halten
    }
    return 0;
}
