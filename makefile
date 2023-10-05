# environment variables
INCLUDE_PATH = ./lib/include
SRC_PATH = ./lib/src
OBJ_PATH = ./lib/obj
API_NAME = tuxlls

tuxlls.o: $(INCLUDE_PATH)/$(API_NAME).h $(SRC_PATH)/$(API_NAME).c
	gcc -c $(SRC_PATH)/$(API_NAME).c -o $(OBJ_PATH)/$(API_NAME).o

clean:
	rm -rf ./lib/obj/*.o