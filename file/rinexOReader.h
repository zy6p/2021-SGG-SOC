#pragma once
#include<cstdlib>
#include<cstdio>
#include<cstring>
// ���峣��
#define MAXCHAR 400
#define MAXSATNUM 32
#define LABEL1 "END OF HEADER"
#define LABEL2 "APPROX POSITION XYZ"
#define LABEL3 "TIME OF FIRST OBS"
#define FORMAT1 "%lf %lf %lf"
#define FORMAT2 ">%*d %*d %*d %*d %*d %*lf %*d %hd %*lf\n" // ʡ��
#define FORMAT3 
#define FORMAT4 "PRN:  %2d\tADR:%16.3lf\tPSR:%16.3lf\n" // ת���ַ�

// ʹ��ö������
enum NavSys
{
	NON,
	GPS,
	BDS
};

struct obs
{
	NavSys sys;							// ����ϵͳ
	short PRN;							// ���
	double psr;							// ��Ƶα��۲�ֵ
	double adr;							// ��Ƶ��λ�۲�ֵ
};

// ʹ�ýṹ��
struct rinexHead
{
	double positon[3];
	short leapsecond;
};

struct rinexBlock
{
	short sat_num;
	obs sat_obs[MAXSATNUM];
};

// ʹ����
class rinexOReader 
{
public:
	rinexOReader(const char* filename);		// ���캯��
	~rinexOReader();					// ��������
public:
	rinexHead head;						// ������Ա����
	rinexBlock block;
	void readHead() noexcept;           // �ַ�������
	void readBlock() noexcept;          // ��ʽ����ȡ
	void printObs(FILE*) noexcept;		// ��ʽ�����
	bool eof() noexcept;				// ��װ˽�г�Ա����
private:
	FILE* file;							// ˽�г�Ա����
};