#include"rinexOReader.h"

int main() {
	const char* filename = "7190.21O";
	rinexOReader rinex(filename);
	rinex.readHead();
	while (!rinex.eof())
	{
		rinex.readBlock();
		rinex.printObs(stderr);
	}
	return 0;
}