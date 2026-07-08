#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sony_psn_hooks.h"

#define SONY_NP_STATUS_MGR_OFFSET 0x81A4B00
#define SPOTIFY_TITLE_ID "CUSA01581"

int init_jailbreak_environment() {
    printf("[+] Initializing Prospero kernel hooks...\n");
    
    uint64_t ucred = get_kernel_cred(); 
    if (ucred == 0) {
        printf("[-] Error: Escalated privileges not found.\n");
        return -1;
    }
    printf("[+] Escalated privileges confirmed: ucred=%p\n", (void*)ucred);
    return 0;
}

int hook_spotify_status() {
    printf("[+] Searching for active Spotify process container...\n");
    
    uint32_t pid = find_process_by_title_id(SPOTIFY_TITLE_ID);
    if (pid == 0) {
        printf("[!] Spotify process not found. Retrying layer scan...\n");
        return 1;
    }
    
    printf("[+] Found Spotify process at PID: %d\n", pid);
    printf("[+] Intercepting sceNpSetOnlineStatus presence updates...\n");

    uint8_t patch[] = { 0x48, 0x89, 0xF8, 0x90, 0x90 }; 
    if (patch_memory(SONY_NP_STATUS_MGR_OFFSET, patch, sizeof(patch)) != 0) {
        printf("[-] Error: Failed to patch NpStatusManager memory space.\n");
        printf("[!] Aborting injection daemon to prevent kernel panic.\n");
        return -1;
    }

    printf("[+] Success: Custom status string buffer injected.\n");
    return 0;
}

int main(int argc, char const *argv[]) {
    printf("=== PS5 Spotify Status Integration Workaround ===\n");
    
    if (init_jailbreak_environment() != 0) {
        return -1;
    }

    while(1) {
        int status = hook_spotify_status();
        if (status == -1) {
            printf("[-] De-initializing payload due to memory conflict.\n");
            break;
        }
        sceKernelSleep(5); 
    }

    return 0;
}
