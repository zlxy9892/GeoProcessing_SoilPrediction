#include <iostream>
#include "Utility.h"
#include "Processing.h"

using namespace std;

int main(int argc, char *argv[])
{
	// 初始化环境因子数据
	GDALAllRegister();
	EnvDataset *envDataset = new EnvDataset();
	envDataset->Layers.push_back(new EnvLayer(0, "bedrock", "E:/data/samplegroup/geo.asc", DataTypeEnum::BOOLEAN));
	envDataset->Layers.push_back(new EnvLayer(1, "slope", "E:/data/samplegroup/slope.asc", DataTypeEnum::BOOLEAN));
	envDataset->Layers.push_back(new EnvLayer(2, "planc", "E:/data/samplegroup/planc.asc", DataTypeEnum::BOOLEAN));

	// 设定相关参数
	string targetVName = "shali";									// 土壤属性值
	string idName = "ID";											// 若是样点，记录样点的ID号
	string inputSamplesCSV = "E:/data/samplegroup/samples.csv";		// 输入样点CSV文件

	// 读取样点信息
	vector<EnvUnit *> samples = Utility::ReadCSV(inputSamplesCSV, envDataset, targetVName, idName);

	// 开始进行样点甄别的计算
	Processing *processing = new Processing(envDataset, samples);
	processing->MyMethod();			// 开始进行自定义方法


	//system("pause");
	return 0;
}