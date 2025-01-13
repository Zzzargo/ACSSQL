#include "task3.h"
#include <stdint.h>

#define NUM_BLOCKS 4  // Change it to whatever you want the number of blocks to be

uint8_t ** split_bytes(uint8_t *students_bytes, size_t num_blocks, size_t students_bytes_len, size_t block_len) {
    uint8_t **blocks = malloc(num_blocks * sizeof(uint8_t *));
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

uint8_t * XOR_bytes(uint8_t *block, uint8_t *key, size_t block_len, size_t key_len) {
    uint8_t *result = malloc(block_len * sizeof(uint8_t));
    for (size_t i = 0; i < block_len; i++) {  // For each byte in the block
        // XOR with the key byte by byte. If the key is shorter than the block, wrap around
        result[i] = block[i] ^ key[i % key_len];  // smOrt
    }
    return result;
}

uint8_t * S_BOX(uint8_t *block, size_t block_len) {
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

    while (students_bytes_len % NUM_BLOCKS != 0) {
        students_bytes_len++;  // Increase the length of the array to make it divisible by num_blocks
    }
    size_t block_len = students_bytes_len / NUM_BLOCKS;  // Get the length of each block
    uint8_t **blocks = split_bytes(students_bytes, NUM_BLOCKS, students_bytes_len, block_len);

    // Convert the key and IV to bytes
    uint8_t *IV_bytes = (uint8_t *)iv;
    uint8_t *key_bytes = (uint8_t *)key;

    // All the preparation is done, now we can start encrypting
    // Allocate memory for the encrypted blocks
    uint8_t **encrypted_blocks = malloc(NUM_BLOCKS * sizeof(uint8_t *));
    for (size_t i = 0; i < NUM_BLOCKS; i++) {
        encrypted_blocks[i] = malloc(block_len * sizeof(uint8_t));
    }

    // XOR the first block with the IV
    uint8_t *xor_result = XOR_bytes(blocks[0], IV_bytes, block_len, iv_len);

    // XOR the result with the key
    xor_result = XOR_bytes(xor_result, key_bytes, block_len, key_len);

    // Rearrange the bytes in the resulted block based on the S-box function
    uint8_t *s_box_result = S_BOX(xor_result, block_len);
    memcpy(encrypted_blocks[0], s_box_result, block_len);  // First block done

    for (size_t i = 1; i < NUM_BLOCKS; i++) {  // For each of the remaining blocks repeat the same steps
        xor_result = XOR_bytes(blocks[i], encrypted_blocks[i - 1], block_len, block_len);
        xor_result = XOR_bytes(xor_result, key_bytes, block_len, key_len);
        s_box_result = S_BOX(xor_result, block_len);
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
