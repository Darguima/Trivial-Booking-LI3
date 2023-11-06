typedef enum {
  PLACEHOLDER
} sex;

typedef enum {
  PLACEHOLDER
} pay_method ;

typedef enum {
  PLACEHOLDER
} account_status ;

typedef struct usersSchema
{
  int id;
  char *name;
  char *email;
  int phone_number; // verify if the size of an int is sufficient for phone number
  int birth_date; // verify if dates are stored as numeric timestamp
  sex sex;
  int passport;
  int country_code;
  char *address;
  int account_creation; // verify how should the date be stored
  pay_method pay_method;
  account_status account_status;
} UsersSchema;

typedef struct flightsSchema
{
  int id;
} FlightsSchema;

typedef struct passengersSchema
{
  int id;
} PassengersSchema;

typedef struct reservationsSchema
{
  int id;
} ReservationsSchema;