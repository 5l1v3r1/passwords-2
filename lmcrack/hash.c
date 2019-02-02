
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <openssl/des.h>

void DES_str_to_key (char str[], uint8_t key[]) {
    int i;

    key[0] = str[0] >> 1;
    key[1] = ((str[0] & 0x01) << 6) | (str[1] >> 2);
    key[2] = ((str[1] & 0x03) << 5) | (str[2] >> 3);
    key[3] = ((str[2] & 0x07) << 4) | (str[3] >> 4);
    key[4] = ((str[3] & 0x0F) << 3) | (str[4] >> 5);
    key[5] = ((str[4] & 0x1F) << 2) | (str[5] >> 6);
    key[6] = ((str[5] & 0x3F) << 1) | (str[6] >> 7);
    key[7] = str[6] & 0x7F;

    for (i = 0;i < 8;i++) {
      key[i] = (key[i] << 1);
    }
    DES_set_odd_parity ((DES_cblock*)key);
}

char* lmhash(char *pwd) {
    DES_cblock       key1, key2;
    DES_key_schedule ks1, ks2;
    const char       ptext[]="KGS!@#$%";
    static char      hash[64], lm_pwd[16];
    uint8_t          ctext[16];
    size_t           i, pwd_len = strlen(pwd);
    
    // 1. zero-initialize local buffer
    memset(lm_pwd, 0, sizeof(lm_pwd));
    
    // 2. convert password to uppercase (restricted to 14 characters)
    for(i=0; i<pwd_len && i<14; i++) {
      lm_pwd[i] = toupper((int)pwd[i]);
    }
    
    // 3. create two DES keys
    DES_str_to_key(&lm_pwd[0], (uint8_t*)&key1);
    DES_str_to_key(&lm_pwd[7], (uint8_t*)&key2);
    DES_set_key(&key1, &ks1);
    DES_set_key(&key2, &ks2);
    
    // 4. encrypt plaintext
    DES_ecb_encrypt((const_DES_cblock*)ptext, 
      (DES_cblock*)&ctext[0], &ks1, DES_ENCRYPT);

    DES_ecb_encrypt((const_DES_cblock*)ptext, 
      (DES_cblock*)&ctext[8], &ks2, DES_ENCRYPT);
      
    // 5. convert ciphertext to string
    for(i=0; i<16; i++) {
      snprintf(&hash[i*2], 3, "%02X", ctext[i]);
    }
    return hash;
}


int main(int argc, char *argv[]) {
    if (argc!=2) {
      printf("usage: lmhash <password>\n");
      return 0;
    }
    
    printf("LM Hash: %s\n", lmhash(argv[1]));
    return 0;
}
