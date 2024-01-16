#include <datatypes/datatypes.h>
#include <glib.h>
#include <string.h>

gint compare_tree_str_keys(gconstpointer a, gconstpointer b, gpointer user_data) {
  UNUSED(user_data);
  return strcmp((const char*)a, (const char*)b);
}