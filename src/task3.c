#include "task3.h"
#include <stdint.h>

#define NUM_BLOCKS 4

// #define DEBUG

/*
    For the first test I will consider:
    Students: ID: 0 NAME: Lupu Stefan YEAR: 3 STATUS: b GPA: 5.31
    IV: "aa"
    KEY: "pclp1"
*/

size_t block_len;  // I need it accessible globally

uint8_t ** split_bytes(uint8_t *students_bytes, size_t num_blocks, size_t students_bytes_len) {
    uint8_t **blocks = malloc(num_blocks * sizeof(uint8_t *));
    while (students_bytes_len % num_blocks != 0) {
        students_bytes_len++;  // Increase the length of the array to make it divisible by num_blocks
    }
    block_len = students_bytes_len / num_blocks;

    #ifdef DEBUG
        printf("Length of a block: %ld\n", block_len);
    #endif

    for (size_t i = 0; i < num_blocks; i++) {  // For each block
        blocks[i] = malloc(block_len * sizeof(uint8_t));
        for (size_t j = 0; j < block_len; j++) {
            if (i * block_len + j < students_bytes_len) {
                blocks[i][j] = students_bytes[i * block_len + j];  // Copy the bytes from the array
            } else {
                blocks[i][j] = 0x00;  // Pad the block with zeros if not filled and no more bytes are available
            }
        }
    }
    return blocks;
}

uint8_t * XOR_bytes(uint8_t *block, uint8_t *key, size_t key_len) {
    uint8_t *result = malloc(block_len * sizeof(uint8_t));
    for (size_t i = 0; i < block_len; i++) {  // For each byte in the block
        // XOR with the key byte by byte. If the key is shorter than the block, wrap around
        result[i] = block[i] ^ key[i % key_len];  // smOrt
    }
    return result;
}

uint8_t * S_BOX(uint8_t *block) {
    uint8_t *result = malloc(block_len * sizeof(uint8_t));
    for (size_t i = 0; i < block_len; i++) {  // For each byte in the block
        result[i] = block[(i * (block_len - 1) + 2) % block_len];  // Apply the S-box function
    }
    return result;
}
void cripteaza_studenti(secretariat *secretariat, void *key, size_t key_len,
void *iv, size_t iv_len, char *cale_output) {
    uint8_t *students_bytes = (uint8_t *)secretariat->studenti;
    size_t students_bytes_len = secretariat->nr_studenti * sizeof(student);

    #ifdef DEBUG
        printf("Number of bytes in the vector: %ld\n", students_bytes_len);
    #endif

    uint8_t **blocks = split_bytes(students_bytes, NUM_BLOCKS, students_bytes_len);

    #ifdef DEBUG
        /*
            Blocks should be:
            Block 0: 0x00 0x00 0x00 0x00 0x4C 0x75 0x70 0x75 0x20 0x53 0x74 0x65 0x66 0x61
            Block 1: 0x6E 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
            Block 2: 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
            Block 3: 0x00 0x00 0x03 0x00 0x00 0x00 0x62 0x85 0xEB 0xA9 0x40 0x00 0x00 0x00
        */
        printf("INITIAL BLOCKS:\n");
        for (size_t i = 0; i < NUM_BLOCKS; i++) {
            printf("Block %zu: ", i);
            for (size_t j = 0; j < block_len; j++) {
                printf("0x%02X ", blocks[i][j]);
            }
            printf("\n");
        }
    #endif

    uint8_t *IV_bytes = (uint8_t *)iv;

    #ifdef DEBUG
        printf("IV: %s\nIV bytes: ", (char *)iv);
        for (size_t i = 0; i < iv_len; i++) {
            printf("0x%02X ", IV_bytes[i]);
        }
        printf("\n");
    #endif

    uint8_t *key_bytes = (uint8_t *)key;

    #ifdef DEBUG
        printf("Key: %s\nKey bytes: ", (char *)key);
        for (size_t i = 0; i < key_len; i++) {
            printf("0x%02X ", key_bytes[i]);
        }
        printf("\n");
    #endif

    // All the preparation is done, now we can start encrypting
    // Allocate memory for the encrypted blocks
    uint8_t **encrypted_blocks = malloc(NUM_BLOCKS * sizeof(uint8_t *));
    for (size_t i = 0; i < NUM_BLOCKS; i++) {
        encrypted_blocks[i] = malloc(block_len * sizeof(uint8_t));
    }

    // XOR the first block with the IV
    uint8_t *xor_result = XOR_bytes(blocks[0], IV_bytes, iv_len);

    /*
        0x00 0x00 0x00 0x00 0x4C 0x75 0x70 0x75 0x20 0x53 0x74 0x65 0x66 0x61
        0x61 0x61 0x61 0x61 0x61 0x61 0x61 0x61 0x61 0x61 0x61 0x61 0x61 0x61
        ---------------------------------------------------------------------
        0x61 0x61 0x61 0x61 0x2D 0x14 0x11 0x14 0x41 0x32 0x15 0x04 0x07 0x00
    */

    // XOR the result with the key
    xor_result = XOR_bytes(xor_result, key_bytes, key_len);

    /*
        0x61 0x61 0x61 0x61 0x2D 0x14 0x11 0x14 0x41 0x32 0x15 0x04 0x07 0x00
        0x70 0x63 0x6C 0x70 0x31 0x70 0x63 0x6C 0x70 0x31 0x70 0x63 0x6C 0x70
        ---------------------------------------------------------------------
        0x11 0x02 0x0D 0x11 0x1C 0x64 0x72 0x78 0x31 0x03 0x65 0x67 0x6B 0x70
    */

    #ifdef DEBUG
        printf("First block after XOR with IV and key: ");
        for (size_t i = 0; i < block_len; i++) {
            printf("0x%02X ", encrypted_blocks[0][i]);
        }
        printf("\n");
    #endif

    // Rearrange the bytes in the resulted block based on the S-box function
    uint8_t *s_box_result = S_BOX(xor_result);
    memcpy(encrypted_blocks[0], s_box_result, block_len);  // First block done

    for (size_t i = 1; i < NUM_BLOCKS; i++) {  // For each of the remaining blocks repeat the same steps
        xor_result = XOR_bytes(blocks[i], encrypted_blocks[i - 1], block_len);
        xor_result = XOR_bytes(xor_result, key_bytes, key_len);
        s_box_result = S_BOX(xor_result);
        memcpy(encrypted_blocks[i], s_box_result, block_len);
    }

    // Free memory
    free(xor_result);
    free(s_box_result);
    for (size_t i = 0; i < NUM_BLOCKS; i++) {
        free(blocks[i]);
    }
    free(blocks);  // Initial blocks

    // Write the encrypted blocks to the output file
    FILE *output_file = fopen(cale_output, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < NUM_BLOCKS; i++) {
        fwrite(encrypted_blocks[i], sizeof(uint8_t), block_len, output_file);
    }
    fclose(output_file);
}
