#include <iostream>
#include "Utility.h"
#include "Processing.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout<<"\nInitalizing...\n";
	
	// 处理输入参数

	// 示例
	argv[1] = "E:/data/samplegroup/geo.asc#E:/data/samplegroup/slope.asc#E:/data/samplegroup/planc.asc";	// 输入的环境因子图层
	argv[2] = "category?boolean#category?gower#category?gower";												// 环境因子计算类型
	argv[3] = "ID";																							// 样点ID在输入表格中的表头名称
	argv[4] = "shali";																						// 样点目标属性变量在输入表格中的表头名称
	argv[5] = "0.95";																						// 环境相似度阈值
	argv[6] = "10";																							// 土壤属性宽度阈值
	argv[7] = "E:/data/samplegroup/samples.csv";															// 输入的样点数据（包含ID，x，y，土壤属性）
	argv[8] = "E:/data/samplegroup/result.csv";																// 输出样点可信度结果文件
	//string params = "";

	/*if(argc != 9)
	{
		cout<<"输入参数有误！\n";
		return 999;
	}*/
	char *str_inputEnvLayerFilenames = argv[1];
	char *str_cate_calMethod = argv[2];
	char *str_idName = argv[3];
	char *str_targetVName = argv[4];
	char *str_threshold_envSimi = argv[5];
	char *str_threshold_targetVDist = argv[6];
	char *str_samplesCSV = argv[7];
	char *str_resultCSV = argv[8];

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