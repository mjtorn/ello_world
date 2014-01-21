E_INCLUDE = /home/mjt/e18/include/
INCLUDE_FLAGS = -I$(E_INCLUDE)/ecore-1 -I$(E_INCLUDE)/ecore-con-1 -I$(E_INCLUDE)/ecore-evas-1 -I$(E_INCLUDE)/ecore-file-1 \
							 	-I$(E_INCLUDE)/ecore-imf-1 -I$(E_INCLUDE)/ecore-input-1 -I$(E_INCLUDE)/edje-1 \
								-I$(E_INCLUDE)/eet-1 -I$(E_INCLUDE)/efl-1 -I$(E_INCLUDE)/efreet-1 -I$(E_INCLUDE)/eina-1 -I$(E_INCLUDE)/eina-1/eina \
							 	-I$(E_INCLUDE)/eldbus-1 -I$(E_INCLUDE)/elementary-1 -I$(E_INCLUDE)/eo-1 -I$(E_INCLUDE)/ethumb-1 \
							 	-I$(E_INCLUDE)/ethumb-client-1 -I$(E_INCLUDE)/evas-1

E_LIB = /home/mjt/e18/lib/
LIB_FLAGS = -L$(E_LIB) -lecore -lelementary -levas

CFLAGS = -Wall -Wextra -Wno-unused-parameter -Werror $(INCLUDE_FLAGS) $(LIB_FLAGS)

all:
	$(CC) $(CFLAGS) -o hello hello.c

