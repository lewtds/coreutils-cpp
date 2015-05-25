all: test

cmake:
	mkdir -p build
	cd build && cmake ..

build: cmake
	cd build && make

test: build
	cd build && ./_test

clean:
	cd build && make clean

.PHONY: all build cmake test
