#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>

const char* APP_TITLE = "solitaire [http://rubyquiz.com/quiz1.html]";
const char* PROMPT_PLAINTEXT = "Enter your plaintext:";
const char* LABEL_PLAINTEXT = "PLAINTEXT:";
const char* LABEL_PREPAREDTEXT = "PREPARED-TEXT:";
const char PADDING_CHAR = 'X';

const int INPUT_BUFFER_SIZE = 100;
const int SEGMENT_SIZE = 5;

int main(int argc, char* argv[]) {

    char plaintext[INPUT_BUFFER_SIZE] = {'\0'};
    char preparedtext[INPUT_BUFFER_SIZE] = {'\0'};
    // char cipherkey[INPUT_BUFFER_SIZE] = {'\0'};
    // char ciphertext[INPUT_BUFFER_SIZE] = {'\0'};

    printf("%s\n", APP_TITLE);

    printf("%s ", PROMPT_PLAINTEXT);

    if (fgets(plaintext, INPUT_BUFFER_SIZE, stdin) != NULL)
    {
        size_t max_i = strlen(plaintext) < (size_t)INPUT_BUFFER_SIZE ? strlen(plaintext) : (size_t)INPUT_BUFFER_SIZE;
        int j = 0;
        int k = 0;
        
        for (size_t i = 0; i < max_i; i++) {
            if (plaintext[i] == '\n') {
                plaintext[i] = '\0';
            }

            if (isalpha(plaintext[i])) {
                preparedtext[j] = toupper(plaintext[i]);
                j++;
                k++;

                if (k % SEGMENT_SIZE == 0) {
                    k = 0;
                    preparedtext[j] = ' ';
                    j++;
                }
            }
        }

        if (k > 0) {
            for (int i = k; i < SEGMENT_SIZE; i++) {
                preparedtext[j] = PADDING_CHAR;
                j++;
            }
        }

        preparedtext[j] = '\0';

        printf("%s %s\n", LABEL_PLAINTEXT, plaintext);
        printf("%s %s\n", LABEL_PREPAREDTEXT, preparedtext);

        int ALPHA_OFFSET = (int)'Z' - 26;

        for (size_t i = 0; i < strlen(preparedtext); i++) {
            if (preparedtext[i] == ' ') {
                printf(" . ");
            } else {
                int x = (int)preparedtext[i];
                x -= ALPHA_OFFSET;
                printf("%d ", x);
            }
        }
        printf("\n");
    }

    return EXIT_SUCCESS;

}
