/* Word count using Glib.
References: https://gist.github.com/bert/265933/fa2a0771d5b7d8920a538504676aa4a3916c861c

Author: Shruti Iyer (shrutiyer)
*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

void print_hash_table(gpointer key, gpointer value, gpointer user_data) {
    char *key_str = key;
    printf("%s: %i\n", key_str, GPOINTER_TO_INT(value));
}

int main(int argc, char** argv) {
    FILE *file;
    char word[1024];
    GHashTable *hash = g_hash_table_new(g_str_hash, g_str_equal);

    file = fopen("sherlock.txt", "r");
    if (!file) {
        exit(1);
    }

    while (fscanf (file, "%1023s", word) != EOF) {
        int new_value = GPOINTER_TO_INT(g_hash_table_lookup(hash, word)) + 1;
        g_hash_table_insert (hash, g_strdup(word), GINT_TO_POINTER(new_value));
    }

    g_hash_table_foreach(hash, print_hash_table, NULL);
    return 0;
}
