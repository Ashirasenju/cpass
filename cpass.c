#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>


struct logs
{
  char date;
  char hour;
  char message;
};


struct key
{
  char nom;
  char description;
  char key;
};




struct loaded_db
{
  char hashed_key;
  struct logs log;
  struct key Keys[256];
};





void sha256_string(const char *input, unsigned char output[32]) {
    SHA256((unsigned char*)input, strlen(input), output);

    
}


void structbuilder(const char *input){


}


bool password_check(const char *input, const char *key){

  char hash_hex[65];
  unsigned char output[32];
  sha256_string(input,output);
  for (int i = 0; i < 32; i++) {
        sprintf(hash_hex + (i * 2), "%02x", output[i]);
  }
    hash_hex[64] = '\0'; 



  return strcmp(key, hash_hex) == 0;
}



void main()
{
   char password[] = "helloworld";
    char key[] = "936a185caaa266bb9cbe981e9e05cb78cd732b0b3280b944412bb6f8f8f07af";
  // printf("%d\n", password_check(password,key));


  unsigned char hash[32];
  SHA256((unsigned char*)password, strlen(password), hash);


  



  printf(" \n %d \n ",password_check(password,key));

}
