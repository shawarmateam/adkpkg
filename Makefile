all: build

build:
	mkdir -p ./bin
	gcc ./src/main.c -o ./bin/adkpkg

run: build
	./bin/adkpkg

install: build
	cp ./bin/adkpkg /usr/bin/

clean:
	rm -rf bin/
	rm -f /usr/bin/adkpkg
