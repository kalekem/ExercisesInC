/*
Name: Cleophas Kalekem
Date: 4/10/2017
Instructor: Prof. Allen Downey

*/
/*
A function that reads and counts a text file, splits lines into words,
and counts the frequency of each word
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>

#define FILE_READ "adventures.txt"

//prototype
void display(gpointer key, gpointer value, gpointer data);

//main method
int main(int argc, char** argv) {
    //load the file name
    char* filename = FILE_READ; 
    
    //variable that takes care of removal of characters and spaces
    gchar* file;
    gpointer val;
  
    //check for errors
    GError *error = NULL;

    //hash table to store the occurrences of words
    GHashTable* table= g_hash_table_new(g_str_hash, g_str_equal); 

    //read the text file
    g_file_get_contents(filename, &file, NULL, &error);

    // if errors encountered, show the error and do some cleanups
    if (error != NULL) {
        printf("Encountered errors with the text file: %s\n", error->message);
        g_error_free(error);
        return 1;
      }

     //split the words into spaces
    gchar** words = g_strsplit(file, " ", -1);


    //remove characters and spaces
    file = g_strdelimit(file, "\n\t/*$.,;!?\":()-", ' ' );

    //Iterate through each word and count it's occurences and update as well
    while(*words != NULL) {

      val = g_hash_table_lookup(table, *words);
      int count = 1; 

      if (val) {
        g_hash_table_replace(table, *words, (gpointer)(val) + count);
      }
      else { 
        g_hash_table_insert(table, *words, (gpointer)1);
      }

      words++;
    }

    //map each word to its occurences times
    g_hash_table_foreach(table,display, "%s => %d\n");
    g_free(file);
   
    return 0;
  }

  //implement the prototype functions
  void display(gpointer key, gpointer value, gpointer data) {
    printf(data, (char*) key, (int*) value);
}
