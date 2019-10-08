#pragma once
#include "SceneBaseClass.h"
#include "CShaderManager.h"
#include "CTexture.h"
#include "CTimer.h"
#include "CTexto.h"
#include "CCamera.h"
#include "CModel_3DS.h"
#include <vector>

class Vec3
{
public:
	double x;
	double y;
	double z;

	Vec3()
	{

	}

	Vec3(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
};

class CScene1 : public CSceneBaseClass
{
public:
	CScene1();
	~CScene1(void);

	virtual void MouseMove(void);					// Tratamento de movimento do mouse
	virtual void KeyPressed(void);					// Tratamento de teclas pressionadas
	virtual void KeyDownPressed(WPARAM	wParam);	// Tratamento de teclas pressionadas
	virtual int DrawGLScene(void);					// Função que desenha a cena

	void Draw3DSGrid(float width, float length);
	void DrawAxis();

	void DrawObjectWithDisplayList();
	Vec3 CalculateQuadNormalVector(Vec3 v1, Vec3 v2, Vec3 v3, Vec3 v4);
	Vec3 CalculateTriangleNormalVector(Vec3 v1, Vec3 v2, Vec3 v3);	


	void DrawCube(float pX = 0.0f, float pY = 0.0f, float pZ = 0.0f,
		float rX = 0.0f, float rY = 0.0f, float rZ = 0.0f, float angle = 0.0f,
		float sX = 1.0f, float sY = 1.0f, float sZ = 1.0f,
	    int texID = -1);

	void DrawCylinder(int numMajor, int numMinor, float height, float radius, int multiX, int multiY);

	void DrawTower(int x, int z);
	void DrawSideWall(int x, int z);
	void DrawFrontWall();

	void DrawGarden();
	void DrawTrees();
	void BuildTree(float fPosX, float fPosY, float fPosZ, float fScaleX, float fScaleY, float fScaleZ);

	//void CreateSkyBox(float x, float y, float z, float width, float height, float length);

private:

	bool	keys[256];		// Array usado para rotinas do teclado
	bool	active;			// Window Active Flag Set To TRUE By Default
	bool	fullscreen;		// Exibir janela em modo fullscreem (TRUE) ou em janela (FALSE)	

	CCamera* pCamera;	// Gerencia câmera OpenGL
	float fDeltaY;				// Rotação da câmera OpenGL no eixo Y
	float fDeltaX;				// Rotação da câmera OpenGL no eixo X

	CTexto* pTexto;			// Objeto que gerencia texto	
	CTimer* pTimer;			// Objeto que gerencia o timer
	CTexture* pTexture;		// Objeto que gerencia o mapeamento de texturas

	int		iFPS;			// FPS and FPS Counter
	int		iFrames;		// FPS and FPS Counter
	DWORD	ulLastFPS;		// FPS and FPS Counter
	char	szTitle[256];	// FPS and FPS Counter


	bool bIsWireframe;	// Modos Wireframe/Solid
	bool bIsCameraFPS;	// Ativa modo de camera First Person Shooter (true) ou Third Person Shooter (false)

	float fRenderPosY;
	float fTimerPosY;
	float fPosX;
	float fPosY;
	float fPosZ;
	float fMovementFactor;

	float fRotX;
	float fRotY;
	float fRotZ;
	float fAngle;

	float fDistance;

	// Define os componentes para a fonte de luz (Point Light)
	GLfloat LightAmbient[4];
	GLfloat LightDiffuse[4];
	GLfloat LightSpecular[4];
	GLfloat LightPosition[4];

	// Define o material para reflexão do objeto
	// O material é aplicado na superfície do objeto, e define quanto
	// o objeto irá absorver ou refletir da luz
	GLfloat MatAmbient[4];
	GLfloat MatDiffuse[4];
	GLfloat MatSpecular[4];

	// Cria um ID para um objeto DisplayList
	GLuint objectDisplayListID;

};

