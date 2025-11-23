// sha256.h
#ifndef SHA256_H
#define SHA256_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint32_t state[8];
    uint64_t bitlen;
    uint8_t buffer[64];
} SHA256_CTX;

void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, const uint8_t *data, size_t len);
void sha256_final(SHA256_CTX *ctx, uint8_t hash[32]);

#endif // SHA256_H

// sha256.c (simplified, core logic omitted for brevity)
#include "sha256.h"

#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>

int main() {
    SHA256_CTX ctx;
    uint8_t hash[32];
    const char *message = "Hello, SHA256!";

    sha256_init(&ctx);
    sha256_update(&ctx, (const uint8_t *)message, strlen(message));
    sha256_final(&ctx, hash);

    printf("SHA256 hash of \"%s\": ", message);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}