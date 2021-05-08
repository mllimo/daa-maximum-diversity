CMAKE_DIR=$(PWD)

debug:
	cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Debug
	make -C build/

release:
	cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Release
	make -C build/

clean:
	make -C build/ clean