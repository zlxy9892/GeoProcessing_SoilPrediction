#include <iostream>
#include "Utility.h"
#include "Processing.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout<<"\nInitalizing...\n";
	
	// �����������

	// ʾ��
	argv[1] = "E:/data/samplegroup/geo.asc#E:/data/samplegroup/slope.asc#E:/data/samplegroup/planc.asc";	// ����Ļ�������ͼ��
	argv[2] = "category?boolean#category?gower#category?gower";												// �������Ӽ�������
	argv[3] = "ID";																							// ����ID���������еı�ͷ����
	argv[4] = "shali";																						// ����Ŀ�����Ա������������еı�ͷ����
	argv[5] = "0.95";																						// �������ƶ���ֵ
	argv[6] = "10";																							// �������Կ����ֵ
	argv[7] = "E:/data/samplegroup/samples.csv";															// ������������ݣ�����ID��x��y���������ԣ�
	argv[8] = "E:/data/samplegroup/result.csv";																// ���������ŶȽ���ļ�
	//string params = "";

	/*if(argc != 9)
	{
		cout<<"�����������\n";
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