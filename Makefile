all: build

build:
	mkdir -p ./bin
	gcc ./src/main.c -o ./bin/adkpkg

run: build
	./bin/adkpkg
