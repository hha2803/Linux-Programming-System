
LIB_NAME := math

CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc
SRC_DIR := $(CUR_DIR)/src
OBJ_DIR := $(CUR_DIR)/obj
LIB_DIR := $(CUR_DIR)/lib
LIB_STATIC_DIR := $(LIB_DIR)/static
LIB_SHARED_DIR := $(LIB_DIR)/shared

create_obj:
#create_obj_staticlib
	gcc -c $(CUR_DIR)/main.c -o $(OBJ_DIR)/main_st.o -I $(INC_DIR)
	gcc -c $(SRC_DIR)/math.c -o $(OBJ_DIR)/math_st.o -I $(INC_DIR)
	gcc -c $(SRC_DIR)/version.c -o $(OBJ_DIR)/version_st.o -I $(INC_DIR)
#create_obj_sharedlib
	gcc -c -fPIC $(CUR_DIR)/main.c -o $(OBJ_DIR)/main_sh.o -I $(INC_DIR)
	gcc -c -fPIC $(SRC_DIR)/math.c -o $(OBJ_DIR)/math_sh.o -I $(INC_DIR)
	gcc -c -fPIC $(SRC_DIR)/version.c -o $(OBJ_DIR)/version_sh.o -I $(INC_DIR)

create_static_lib:
	ar rcs $(OBJ_DIR)/lib$(LIB_NAME).a $(OBJ_DIR)/math_st.o $(OBJ_DIR)/version_st.o

create_shared_lib:
	gcc -shared $(OBJ_DIR)/version_sh.o $(OBJ_DIR)/math_sh.o -o $(LIB_SHARED_DIR)/lib$(LIB_NAME).so

install:
	sudo cp -f $(LIB_SHARED_DIR)/lib$(LIB_NAME).so /usr/lib

linking:
#link statically 
	gcc $(OBJ_DIR)/main_st.o -L$(LIB_STATIC_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/use-static-library
#link dynamically with the shared library
	gcc $(OBJ_DIR)/main_sh.o -L$(LIB_SHARED_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/use-shared-library

all: create_obj create_static_lib create_shared_lib install linking
clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(OBJ_DIR)/*.a
	rm -rf $(LIB_SHARED_DIR)/*.so
	rm -rf $(BIN_DIR)/*