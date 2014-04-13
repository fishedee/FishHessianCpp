SRC = $(wildcard fish/*.java)
OBJ = $(patsubst %.java,%.class,$(SRC))
$(OBJ):$(SRC)
	javac $(SRC) -Xlint
clean:
	-rm fish/*.class
run:
	java fish.ClientTest 
