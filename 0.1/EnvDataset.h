// �������ݼ�
#pragma once

#include <vector>
#include "EnvLayer.h"
#include "EnvUnit.h"
#include "BasicSetting.h"
#include "Location.h"

using namespace std;

class EnvDataset
{
public:
	vector<EnvLayer *> Layers;
	vector<EnvUnit *> EnvUnits;
	BasicSetting *Setting;
	int CalArea;

public:
	EnvDataset(void);
	~EnvDataset(void);

	void AddLayer(EnvLayer *layer);
	void ReadinLayers(vector<string> envLayerFilenames, vector<string> calMethods);
	void RefreshEnvUnits();
	void RefreshSetting();
	void RefreshCalArea();
	void RefreshAll();
	EnvUnit* GetEnvUnit(int row, int col);
	EnvUnit* GetEnvUnit(double x, double y);

};

