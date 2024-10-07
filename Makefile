CC = g++

CFLAGS = -fsanitize=address

SOURCES_DIR = Sources
SOURCES = $(wildcard $(SOURCES_DIR)/*.cpp)   ##   * -- каждый, % -- любой
OBJECTS = $(SOURCES:.cpp =.o)

EXECUTABLE = Stack

all: build

build: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -I Headers $(CFLAGS) -o $(EXECUTABLE)

%.o: %.cpp   ##в отличии от wildcard'a строит не горизонтальный список элементов, а вертикальный список вызовов компилятора для каждого сипипишника и ошника
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	rm -rf $(SOURCES_DIR)/*.o Stack


# $@ $< $^
