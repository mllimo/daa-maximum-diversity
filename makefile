debug: CMakeLists.txt
	$(cd build/) cmake -D CMAKE_BUILD_TYPE=Debug $(pwd)

release: CMakeLists.txt
	$(cd build/) cmake -D CMAKE_BUILD_TYPE=Release $($pwd)