#pragma once
class Location
{
public:
	int Row;	// դ������λ�õ��к�
	int Col;	// դ������λ�õ��к�
	double X;	// դ������λ�õ�x����ֵ����դ������Ͻǵ�ֵ
	double Y;	// դ������λ�õ�y����ֵ����դ������Ͻǵ�ֵ

public:
	Location(void);
	~Location(void);

	Location(int row, int col, double x, double y);
};

