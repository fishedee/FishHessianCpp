SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))
OUT = a.out
INC = -I/home/fish/Util/curl/include
LIB = /home/fish/Util/curl/lib/libcurl.a -lz -lrt 
.PHONY:a.out
$(OUT):$(OBJ)
	g++ -o $(OUT) $(OBJ) $(LIB)
%.o:
	g++ -c $< -o $@ $(INC)
ifneq ($(MAKECMDGOALS),clean)
.PHONY:.depend
include .depend
endif
.PHONY:.depend clean
.depend:$(SRC)
	g++ -c -MM $(SRC) $(INC) > .depend
clean:
	-rm *.o $(OUT)
run:
	./a.out

