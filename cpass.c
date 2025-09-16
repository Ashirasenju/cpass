#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>


struct logs
{
  char date[10];
  char hour[9];
  char message[256];
};


struct key
{
  char nom[32];
  char description[256];
  char key[64];
};




struct loaded_db
{
  char hashed_key[64];
  struct logs log;
  struct key Keys[256];
};

struct loaded_db parser(const char *path) {
  FILE* db;

  db = fopen(path, "r");
    if (db == NULL) {
        printf("The path of the file is broken. Please go into your .config and set it right.");
        return;
  }

  // Since the good function are only avaliable for the goats (Linux,Unix) i am forced to use the STD C and fgetc 
  // So this part will focus to read line by line the file db.lck

    size_t size = 64;
    size_t len = 0;
    char *buffer = malloc(size);

    int c;
    while ((c = fgetc(db)) != EOF && c != '\n') {
        buffer[len++] = (char)c;
        if (len == size) {
            size *= 2;
            buffer = realloc(buffer, size);
            if (!buffer) return;
        }
    }
    if (len == 0 && c == EOF) {
        free(buffer);
        return;
    }
    buffer[len] = '\0';

    // the first line is in buffer
    // now let's parse
    

    return parsed;
}

void test_parsing_steps(char *name, char *date, char *key, struct loaded_db parsed) {
    printf("\n=== Test parsing step by step ===\n");

    printf("Step 1: name parsed: '%s'\n", name);
    printf("Step 2: date parsed: '%s'\n", date);
    printf("Step 3: key parsed: '%s'\n", key);

    printf("Step 4: key copied into parsed.hashed_key: '%s'\n", parsed.hashed_key);
    printf("=== End of test ===\n\n");
}




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




  bool isLogin = false;
  int number_of_try = 0;
  while (!isLogin && number_of_try < 3) {
        char userpassword[64];
        printf("Password : ");
        if (fgets(userpassword, sizeof(userpassword), stdin) != NULL){
          userpassword[strcspn(userpassword, "\n")] = '\0';
        }
        bool unlock_status = password_check(userpassword,"5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8");



        if(unlock_status) {
          printf("\nWelcome\n");
          break;
        } else{
          if (number_of_try < 2) {
          number_of_try++;
          printf("\nWrong. Only %d tries left \n",3-number_of_try);
        }

          else {
            number_of_try++;
          }
        }

        
  }

  if (number_of_try >= 3){
     printf("You have tried to many times. Please restart the app and try again.\n");


  }
    char filename[] = "db.lck";
    struct loaded_db db = parser(filename);

    printf("Hashed key from parser: ");
    for (int i = 0; i < 64 && db.hashed_key[i] != '\0'; i++) {
        printf("%c", db.hashed_key[i]);  // caractères ASCII si c'est du texte
    }
    printf("\n");







}
