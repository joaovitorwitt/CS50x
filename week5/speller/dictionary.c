// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Global variables
unsigned int number_words;
unsigned int hash_value;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    hash_value = hash(word);

    node *cursor = table[hash_value];

    while (cursor != 0)
    {
        // check for case insensitive
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }

        cursor = cursor -> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // get words and return the index that represents the location on the hash table

    int length = strlen(word);

    long total = 0;

    for (int i = 0; i < length; i++)
    {
        total += tolower(word[i]);
    }

    // get the summation of each character and get the remainder based on N
    // the value that we get from this operation is the place that the words goes in the hash table
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // open file
    FILE *file = fopen(dictionary, "r");

    // return false if file cant be opened
    if (file == NULL)
    {
        printf("Something went wrong\n");
        return false;
    }

    char word[LENGTH + 1];

    // Read words from the file one at a time
    while (fscanf(file, "%s", word) != EOF)
    {
        // allocate memory for node
        node *n = malloc(sizeof(node));

        // check for errors when allocating memory
        if (n == NULL)
        {
            printf("Could not allocate memory\n");
            return false;
        }

        // copy strings
        // Hash word to get the hash value
        // Insert node into hash table at that location
        // update number of words variable
        strcpy(n -> word, word);
        hash_value = hash(word);
        n -> next = table[hash_value];
        table[hash_value] = n;
        number_words++;

    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (number_words > 0)
    {
        return number_words;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor -> next;
            free(temp);
        }

        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }

    return false;
}
