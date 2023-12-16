all:
	g++ -Os -fno-exceptions -fno-rtti -s -g0 -flto -falign-functions=1 -falign-jumps=1 -falign-loops=1 main.cpp -o output/tsker -O3
	./output/tsker