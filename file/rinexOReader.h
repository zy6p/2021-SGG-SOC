#pragma once
#include<cstdlib>
#include<cstdio>
#include<cstring>
// 定义常量
#define MAXCHAR 400
#define MAXSATNUM 32
#define LABEL1 "END OF HEADER"
#define LABEL2 "APPROX POSITION XYZ"
#define LABEL3 "TIME OF FIRST OBS"
#define FORMAT1 "%lf %lf %lf"
#define FORMAT2 ">%*d %*d %*d %*d %*d %*lf %*d %hd %*lf\n" // 省略
#define FORMAT3 
#define FORMAT4 "PRN:  %2d\tADR:%16.3lf\tPSR:%16.3lf\n" // 转义字符

// 使用枚举类型
enum NavSys
{
	NON,
	GPS,
	BDS
};

struct obs
{
	NavSys sys;							// 卫星系统
	short PRN;							// 编号
	double psr;							// 单频伪距观测值
	double adr;							// 单频相位观测值
};

// 使用结构体
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

// 使用类
class rinexOReader 
{
public:
	rinexOReader(const char* filename);		// 构造函数
	~rinexOReader();					// 析构函数
public:
	rinexHead head;						// 公开成员变量
	rinexBlock block;
	void readHead() noexcept;           // 字符串操作
	void readBlock() noexcept;          // 格式化读取
	void printObs(FILE*) noexcept;		// 格式化输出
	bool eof() noexcept;				// 封装私有成员变量
private:
	FILE* file;							// 私有成员变量
};