#include <datatypes/datatypes.h>
#include <glib.h>
#include <string.h>
#include "entities/airport_entity.h"
#include "stdio.h"

gint compare_str_keys(gconstpointer a, gconstpointer b, gpointer user_data) {
  UNUSED(user_data);
  return strcmp((const char*)a, (const char*)b);
}

gint compare_long_keys(gconstpointer a, gconstpointer b, gpointer user_data) {
  UNUSED(user_data);

  long r = *(long*)a - *(long*)b;

  return (gint)r;
}

gint compare_airports_by_median_delay(gconstpointer a, gconstpointer b, gpointer user_data) {
  UNUSED(user_data);
  Airport airport_a = *(Airport*)a;
  Airport airport_b = *(Airport*)b;

  long median_delay_a = airport_get_median_delay(airport_a);
  long median_delay_b = airport_get_median_delay(airport_b);

  long r = median_delay_b - median_delay_a;

  if (r != 0)
    return (gint)r;
  else
    return strcmp(airport_get_id(airport_a), airport_get_id(airport_b));
}