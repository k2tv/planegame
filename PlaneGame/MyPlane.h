#pragma once
#include "GameObject.h"

class CMyPlane :public CGameObject
{
public:
	CMyPlane(void);
	~CMyPlane(void);

	BOOL Draw(CDC* pDC,BOOL bPause);

	static BOOL LoadImage();

	void SetHorMotion(int nMotion)
	{
		m_nHorMotion = nMotion;
	}
	int GetHorMotion() const
	{
		return m_nHorMotion;
	}

	void SetVerMotion(int nMotion)
	{
		m_nVerMotion = nMotion;
	}
	int GetVerMotion() const
	{
		return m_nVerMotion;
	}

	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+PLANE_WIDTH,m_ptPos.y+PLANE_HEIGHT));
	}

	//是否可以开火发射导弹
	BOOL Fired();

public:
	static const int PLANE_WIDTH=100;
	static const int PLANE_HEIGHT=120;
private:
	
	static CImageList m_Images;
	int    m_nHorMotion;//飞机水平运行方向0->静止，1->右 -1->左
	int    m_nVerMotion;//飞机垂直运行方向0->静止，1->上 -1->下
	int    m_nWait;//发射延时
};
