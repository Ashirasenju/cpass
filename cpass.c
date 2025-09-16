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



int main()
{
  int number_of_try = 0;
  char userpassword[64];
  printf("Password : ");
  if (fgets(userpassword, sizeof(userpassword), stdin) != NULL){
    userpassword[strcspn(userpassword, "\n")] = '\0';
  }
  bool unlock_status = password_check(userpassword,"5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8");

  if(number_of_try >= 3){
    return 0;
  }

  if(unlock_status) {
    printf("\nWelcome");
  } else{
    printf("\nWrong. Only two tries left");
    number_of_try++;
  }

  return 0;
  




}
