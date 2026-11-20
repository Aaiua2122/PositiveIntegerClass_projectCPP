build:
	g++ main.cpp positive_integer.cpp -o program.exe

run: build
	.\program.exe

format:
	clang-format -i --style=Google main.cpp positive_integer.cpp positive_integer.h

clean:
	cmd /c del program.exe