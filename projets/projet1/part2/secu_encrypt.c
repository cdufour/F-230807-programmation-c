/*Exemples d’utilisation de la commande:
secu_crypt -e -k abcde -f file1.png => output: fichier secu_file1.png.enc (fichier crypté)
secu_crypt -d -k abcde -f secu_file1.png.enc => output: fichier secu_file1.png (fichier décrypté)*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define DEBUG 1

typedef enum EXEC_MODE { CRYPT_MODE, DECRYPT_MODE } EXEC_MODE;

// Keys struct and functions
int check_key(char *key, int len); // Check if string key is [a-z]{4, 10}
typedef struct ENC_KEY { int or_pos1; int pos1; int or_pos2; int pos2; int len; EXEC_MODE mode; } ENC_KEY;
ENC_KEY gen_key(char *key, int len, EXEC_MODE mode); // Generate encryption key structure
void print_enc_key(ENC_KEY key); // Print to STDOUT the encryption key
void enc_key_next(ENC_KEY *key); // Progress key to next permutation to make

// File functions
void gen_out_file_name(char *out_file, char *file, int file_name_len, EXEC_MODE opt); // Generate file name depending on EXEC_MODE
int check_file_size(char *file, int min_byte_nb, int max_byte_nb); // Check file size between boundaries
FILE* init_out_file(char *in_file, char *out_file); // Init output file by copying input file first
void permute_file_bytes(FILE *file, int pos1, int pos2); // Permute bytes at pos1 and pos2


//  ------------------------------
//              MAIN
//  ------------------------------
int main(int argc, char *argv[]) {
    // Exec options
    char file_name[40], out_file_name[40], key[10];
    EXEC_MODE mode;

    // Options parsing
    if(strcmp(argv[1], "-e") == 0) mode = CRYPT_MODE;
    if(strcmp(argv[1], "-d") == 0) mode = DECRYPT_MODE;
    if(check_key(argv[3], strlen(argv[3])))
        strcpy(key, argv[3]);
    else {
        fprintf(stderr, "Error: key is invalid");
        return 1;
    }
    strcpy(file_name, argv[5]);

    // Generate key encryption mecanism
    ENC_KEY enc_key = gen_key(key, strlen(key), mode);

    // Generate output file name
    gen_out_file_name(out_file_name, file_name, strlen(file_name), mode);
    #ifdef DEBUG
        printf("DEBUG: %s %s to %s\n", mode == CRYPT_MODE ? "Crypting" : "Decrypting", file_name, out_file_name);
    #endif
    
    // ---------- Starting (de)encryption process ----------
    // Check if file size is between 1KB and 100KB => End program else (Error is written in function)
    if (!check_file_size(file_name, 1000, 1000000))
        return 1;
    
    // Init output file with input file
    FILE *fout_ptr = init_out_file(file_name, out_file_name);
    if (fout_ptr == NULL) return 1;
    
    // Permutate bytes from key
    while (enc_key.len > 0) {
        permute_file_bytes(fout_ptr, enc_key.pos1, enc_key.pos2);
        enc_key_next(&enc_key);
    }
    fclose(fout_ptr);

    #ifdef DEBUG
        puts("DEBUG: Permutations ended successfully.");
    #endif

    return 0;
}

//  ------------------------------
//            FUNCTIONS
//  ------------------------------

// Check if key is [a-z]{4, 10}
int check_key(char *key, int len) {
    if (len < 4 || len > 10) {
        #ifdef DEBUG
            puts("DEBUG: check_key: key is invalid (not len{4, 10})");
        #endif
        return 0;
    } 
    else {
        for (int i = 0; i < len; i++) {
            if (key[i] < 97 || key[i] > 122) {
                #ifdef DEBUG
                    puts("DEBUG: check_key: key is invalid (not [a-z]{4, 10})");
                #endif
                return 0;
            }
        }
    }
    #ifdef DEBUG
        puts("DEBUG: check_key: key is valid");
    #endif
    return 1;
}

// Generate encryption key structure
ENC_KEY gen_key(char *key, int len, EXEC_MODE mode) {
    ENC_KEY k;
    k.pos1 = 0; k.pos2 = 0;
    k.or_pos1 = 0; k.or_pos2 = 0;
    k.len = len;
    k.mode = mode;

    if (len % 2 == 1) len--;
    for (int i = 0; i < len; i++) {
        if (i < len /2)
            k.pos1 += (int) key[i] - 96;
        else 
            k.pos2 += (int) key[i] - 96;
    }
    k.or_pos1 = k.pos1; k.or_pos2 = k.pos2;
    if (mode == DECRYPT_MODE) {
        k.pos1 *= len;
        k.pos2 *= len;      
    }
    #ifdef DEBUG
        printf("DEBUG: Generating key: "); print_enc_key(k);
    #endif
    return k;
}

// Print to STDOUT the encryption key
void print_enc_key(ENC_KEY key) {
    printf("ENC_KEY=(or_pos1=%d pos1=%d or_pos2=%d pos2=%d len=%d)\n", key.or_pos1, key.pos1, key.or_pos2, key.pos2, key.len);
}

// Progress key to next permutation to make
void enc_key_next(ENC_KEY *key) {
    if (key->mode == CRYPT_MODE) {
        key->pos1 += key->or_pos1;
        key->pos2 += key->or_pos2;
    } else {
        key->pos1 -= key->or_pos1;
        key->pos2 -= key->or_pos2;
    }
    key->len--;
    #ifdef DEBUG
        printf("DEBUG: enc_key_next: "); print_enc_key(*key);
    #endif
}

// Generate file name depending on EXEC_MODE
void gen_out_file_name(char *out_file, char *file, int file_name_len, EXEC_MODE opt) {
    strcpy(out_file, file);
    if (opt == CRYPT_MODE) 
        strcat(out_file, ".enc");
    if (opt == DECRYPT_MODE)
        out_file[file_name_len - 4] = '\0';   
    #ifdef DEBUG
        printf("DEBUG: gen_out_file_name: %s\n", out_file);
    #endif
}

// Check file size between boundaries
int check_file_size(char *file, int min_byte_nb, int max_byte_nb) {
    FILE *file_ptr = fopen(file, "r");
    if (!file_ptr) {
        fprintf(stderr, "Error opening file %s\n", file);
        return 0;
    } else {
        fseek(file_ptr, 0L, SEEK_END);
        int file_size = ftell(file_ptr); 
        if (file_size < min_byte_nb || file_size > max_byte_nb) {
            fprintf(stderr, "Error: file must be between 1KB and 100KB (file size: %dKB)\n", file_size/1000);
            return 0;
        }
    }
    fclose(file_ptr);
    return 1;
}

// Init output file by copying input file first
FILE* init_out_file(char *in_file, char *out_file) {
    // Open input file
    FILE *fin_ptr = fopen(in_file, "rb");
    if (fin_ptr == NULL) {
        fprintf(stderr, "Error opening file %s\n", in_file);
        return NULL;
    }
    // Open output file
    FILE *fout_ptr = fopen(out_file, "w+b");
    if (fout_ptr == NULL) {
        fprintf(stderr, "Error opening file %s\n", out_file);
        return NULL;
    }
    // Copy original file
    int c;
    while ((c = fgetc(fin_ptr)) != EOF) {
        fputc(c, fout_ptr);
    }
    #ifdef DEBUG
        printf("DEBUG: File ending byte nb: %d\n", ftell(fin_ptr));
    #endif
    fclose(fin_ptr);
    rewind(fout_ptr);
    return fout_ptr;
}

// Permute bytes at pos1 and pos2
void permute_file_bytes(FILE *file, int pos1, int pos2) {
    rewind(file);
    fseek(file, pos2, SEEK_SET);
    int c2 = fgetc(file);
    fseek(file, pos1, SEEK_SET);
    int c1 = fgetc(file);
    #ifdef DEBUG
        printf("DEBUG: permute bytes %d (=%x) & %d (=%x)\n", pos1, c1, pos2, c2);
    #endif
    fseek(file, -1, SEEK_CUR);
    fputc(c2, file);
    fseek(file, pos2, SEEK_SET);
    fputc(c1, file);
    rewind(file);
}