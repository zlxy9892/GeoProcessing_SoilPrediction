#include <iostream>
#include "Utility.h"
#include "Processing.h"

using namespace std;

int main(int argc, char *argv[])
{
	// ��ʼ��������������
	GDALAllRegister();
	EnvDataset *envDataset = new EnvDataset();
	envDataset->Layers.push_back(new EnvLayer(0, "bedrock", "E:/data/samplegroup/geo.asc", DataTypeEnum::BOOLEAN));
	envDataset->Layers.push_back(new EnvLayer(1, "slope", "E:/data/samplegroup/slope.asc", DataTypeEnum::BOOLEAN));
	envDataset->Layers.push_back(new EnvLayer(2, "planc", "E:/data/samplegroup/planc.asc", DataTypeEnum::BOOLEAN));

	// �趨��ز���
	string targetVName = "shali";									// ��������ֵ
	string idName = "ID";											// �������㣬��¼�����ID��
	string inputSamplesCSV = "E:/data/samplegroup/samples.csv";		// ��������CSV�ļ�

	// ��ȡ������Ϣ
	vector<EnvUnit *> samples = Utility::ReadCSV(inputSamplesCSV, envDataset, targetVName, idName);

	// ��ʼ�����������ļ���
	Processing *processing = new Processing(envDataset, samples);
	processing->MyMethod();			// ��ʼ�����Զ��巽��


	//system("pause");
	return 0;
}