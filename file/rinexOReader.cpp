#include "rinexOReader.h"

rinexOReader::rinexOReader(const char* filename)
{
	if (fopen_s(&file, filename, "r"))
		abort();

	head = rinexHead{ 0 };
	block = rinexBlock{ 0 };
}

rinexOReader::~rinexOReader()
{
	fclose(file);
}

void rinexOReader::readHead() noexcept
{
	char line[MAXCHAR];
	while (!feof(file))
	{
		fgets(line, MAXCHAR, file);
		if (strstr(line, LABEL1) != NULL)break;
		if (strstr(line, LABEL2) != NULL)sscanf_s(line, FORMAT1, &head.positon[0], &head.positon[1], &head.positon[2]);
		// if (strstr(line, LABEL3) != NULL)sscanf_s(line,,);
	}
}
// [from to]
double str2num(const char* src, size_t from, size_t to) {
	char* save = (char*)malloc(sizeof(char) * (2 + to - from));
	strncpy_s(save, sizeof(char) * (2 + to - from), src + from, to - from + 1);
	double temp = atof(save);
	free(save);
	return temp;
}

void rinexOReader::readBlock() noexcept
{
	char line[MAXCHAR];
	obs* curr = block.sat_obs;
	block.sat_num = 0;
	short i;
	while (!feof(file)) {
		fgets(line, MAXCHAR, file);
		if (strstr(line, ">") != NULL)break;
	}
	sscanf_s(line, FORMAT2, &i);
	for (; i > 0; i--)
	{
		fgets(line, MAXCHAR, file);
		curr->sys = line[0] == 'G' ? GPS : (line[0] == 'C' ? BDS : NON);
		if (curr->sys == NON)continue;
		curr->PRN = (short)str2num(line, 1, 2);
		curr->psr = str2num(line, 3, 16);
		curr->adr = str2num(line, 20, 33);
		block.sat_num++;
		curr++;
	}
}

void rinexOReader::printObs(FILE* f) noexcept
{
	for (short i = 0; i < block.sat_num; i++)
		fprintf_s(f, FORMAT4,
			block.sat_obs[i].PRN, block.sat_obs[i].adr, block.sat_obs[i].psr);
}

bool rinexOReader::eof() noexcept 
{
	return feof(file);
}
