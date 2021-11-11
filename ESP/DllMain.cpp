#include "DllMain.h"
void RainbowUI();

int qTemp = 0;
float byYotic[3] = { 255, 0, 0 };

Position chest, entity, largeChest, enderFrame;

bool sChest = false, sPlayer = false, sEnderFrame = false, sNickname = false,
sInventory = false,
active = true,
aChest = true, aChestTracer = false,
aDChest = true, aDChestTracer = true,
aPlayer = true, aPlayerTracer = true,
aEnderFrame = true, aEnderFrameTracer = true;

T_glEnable pglEnable = nullptr, pglDisable = nullptr;

T_glOrtho pglOrtho = nullptr;
T_glScalef pglScalef = nullptr;
T_SwapBuffers pSwapBuffers = nullptr;
T_glTranslatef pglTranslatef = nullptr;

void draw(Position& position, Radius radius, Color boxColor, bool drawLine, bool LGBT, bool tPolygons, bool sLine)
{
	for (int i = 0; i < position.modelview.size(); i += 16)
	{
        if(LGBT){
			RainbowUI();
			boxColor = Color(byYotic[0], byYotic[1], byYotic[2]);
		}
                
		if (sEnderFrame) byYotic[0] = byYotic[1] = byYotic[2] = 1.0F;

		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(position.projection.data() + i);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(position.modelview.data() + i);

		if (sLine)
		{
			glLineWidth(1.0F);
			glColor4f(boxColor.red, boxColor.green, boxColor.blue, 0.15F);
		}
		else 
		{
			glLineWidth(2.0F);
			glColor4f(boxColor.red, boxColor.green, boxColor.blue, 1.0F);
		}

		glBegin(GL_LINES);


		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);

		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glEnd();

		glColor4f(boxColor.red, boxColor.green, boxColor.blue, 0.2F);

		if (tPolygons) 
		{
			glBegin(GL_POLYGON);
			glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
			glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
			glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
			glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
			glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
			glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
			glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
			glEnd();
		}		

		if (!drawLine) continue;

		glLoadIdentity();

		glColor4f(boxColor.red, boxColor.green, boxColor.blue, 0.2F);

		glBegin(GL_LINES);
		glVertex3f(0, 0, -0.1F);
		glVertex3f((position.modelview.data() + i)[12], (position.modelview.data() + i)[13], (position.modelview.data() + i)[14]);
		glEnd();
	}

	position.projection.clear();
	position.modelview.clear();
}

void savePosition(Position& position, float offsetX, float offsetY, float offsetZ)
{
	float projection[16]{};
	glGetFloatv(GL_PROJECTION_MATRIX, projection);

	float modelview[16]{};
	glGetFloatv(GL_MODELVIEW_MATRIX, modelview);

	// Position adjustment (Taken from the source code of the GLM library)
	float m3[4]{};

	for (int i = 0; i < 4; ++i)
	{
		m3[i] = modelview[i] * offsetX
				+ modelview[i + 4] * offsetY
				+ modelview[i + 8] * offsetZ
				+ modelview[i + 12];
	}

	memcpy(modelview + 12, m3, sizeof(m3));

	position.projection.insert(position.projection.end(), begin(projection), end(projection));
	position.modelview.insert(position.modelview.end(), begin(modelview), end(modelview));
}


BOOL __stdcall mySwapBuffers(HDC hDC)
{
	sInventory = false;
	return pSwapBuffers(hDC);
}


void RainbowUI()
{
	if (qTemp == 0) if (byYotic[1] < 1) byYotic[1] += .001; else qTemp += 1;
	if (qTemp == 1) if (byYotic[0] > 0)byYotic[0] = byYotic[0] - .001; else qTemp += 1;
	if (qTemp == 2) if (byYotic[2] < 1) byYotic[2] += .001; else qTemp += 1;
	if (qTemp == 3) if (byYotic[1] > 0) byYotic[1] = byYotic[1] - .001; else qTemp += 1;
	if (qTemp == 4) if (byYotic[0] < 1) byYotic[0] += .001; else qTemp += 1;
	else if (byYotic[2] > 0) byYotic[2] = byYotic[2] - .001;	else qTemp = 0;
}

void __stdcall myglOrtho(double left, double right, double bottom, double top, double zNear, double zFar)
{
		sInventory = true;

		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glPushMatrix();

		glDisable(GL_TEXTURE_2D);
		glDisable(GL_CULL_FACE);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);

		glEnable(GL_LINE_SMOOTH);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		if (GetAsyncKeyState(0x52)) aPlayer = aChest = aDChest = !aPlayer;

		//if (aEnderFrame) draw(chest, Radius(1.0F, 1.0F, 1.0F), Color(0, 1, 0), aEnderFrameTracer, true, true, false);
		if (aChest) draw(chest, Radius(1.0F, 1.0F, 1.0F), Color(byYotic[0], byYotic[1], byYotic[2]), aChestTracer, true, false, false);
		if (aDChest) draw(largeChest, Radius(2.0F, 1.0F, 1.0F), Color(byYotic[0], byYotic[1], byYotic[2]), aDChestTracer, true, true, false);
		if (aPlayer) draw(entity, Radius(0.8F, 2.0F, 0.8F), Color(byYotic[0], byYotic[1], byYotic[2]), aPlayerTracer, true, false, true);

		glPopAttrib();
		glPopMatrix();

	pglOrtho(left, right, bottom, top, zNear, zFar);
}

void __stdcall myglTranslatef(float x, float y, float z)
{
	pglTranslatef(x, y, z);

	if (sInventory)
	{
		return;
	}

	// Chest
	if (x == 0.5 and y == 0.4375 and z == 0.9375)
	{
		savePosition(chest, 0.0F, 0.0625F, -0.4375F);
	}

	// Large chest
	if (x == 1 and y == 0.4375 and z == 0.9375)
	{
		savePosition(largeChest, 0.0F, 0.0625F, -0.4375F);
	}

}

void __stdcall myglScalef(float x, float y, float z)
{
	pglScalef(x, y, z);

	if (sInventory)
	{
		return;
	}

	// Any chest (don't ask me pls XD)
	if (x == 1 and y == -1 and z == -1)
	{
		// Crutch
		sChest = true;


		glEnable(GL_POLYGON_OFFSET_FILL);
		//glPolygonOffset(1, -1100000);
	}

	// Entity
	if (x == 0.9375 and y == 0.9375 and z == 0.9375)
	{
		// Crutch
		sPlayer = true;

		glEnable(GL_POLYGON_OFFSET_FILL);
		//glPolygonOffset(1, -1100000);

		savePosition(entity, 0.0F, -1.0F, 0.0F);
	}

	//EnderFrame
	if (x == 0.625 and y == 0.625 and z == 0.625)
	{
		sEnderFrame = true;

		glEnable(GL_POLYGON_OFFSET_FILL);
		//glPolygonOffset(1, -1100000);

		savePosition(chest, 0.0F, 0.0625F, -0.4375F);
	}

	// Nickname
	if (x == -0.026666669175028801 and y == -0.026666669175028801 and z == 0.026666669175028801)
	{
		// Crutch
		sNickname = true;

		glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(0, -1100000);

		float modelview[16]{};
		glGetFloatv(GL_MODELVIEW_MATRIX, modelview);

		float distance = sqrtf
		(
			modelview[12] * modelview[12] + 
			modelview[13] * modelview[13] +
			modelview[14] * modelview[14]
		);

		distance = distance / 4;

		if (distance > 5)
		{
			distance = 5;
		}

		glTranslatef(0, distance / 5, 0);

		if (distance > 1)
		{
			pglScalef(distance, distance, distance);
		}
	}
}

void __stdcall myglEnable(unsigned int cap)
{
	pglEnable(cap);

	if (cap == GL_LIGHTING and sNickname)
	{
		glDisable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(1, 1100000);

		sNickname = false;
	}

	pglEnable(cap);
}

void __stdcall myglDisable(unsigned int cap)
{
	pglDisable(cap);

	if (cap == 0x0000803A)
	{
		if (sChest or sPlayer)
		{
			if (sChest)
			{
				sChest = false;
			}

			if (sPlayer)
			{
				sPlayer = false;
			}

			glDisable(GL_POLYGON_OFFSET_FILL);
			glPolygonOffset(1, 1100000);
		}
	}
}

BOOL __stdcall DllMain(HINSTANCE handle, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
		{
			// Getting OpenGL32.dll handle
			HMODULE handle = GetModuleHandleW(L"OpenGL32.dll");

			if (!handle)
			{
				return FALSE;
			}

			// Getting pointers to the desired functions
			pglEnable = reinterpret_cast<T_glEnable>(GetProcAddress(handle, "glEnable"));
			pglDisable = reinterpret_cast<T_glDisable>(GetProcAddress(handle, "glDisable"));

			pSwapBuffers = reinterpret_cast<T_SwapBuffers>(GetProcAddress(handle, "wglSwapBuffers"));
			pglOrtho = reinterpret_cast<T_glOrtho>(GetProcAddress(handle, "glOrtho"));
			pglScalef = reinterpret_cast<T_glScalef>(GetProcAddress(handle, "glScalef"));
			pglTranslatef = reinterpret_cast<T_glTranslatef>(GetProcAddress(handle, "glTranslatef"));

			// Installing function interceptors
			DetourRestoreAfterWith();
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			DetourAttach(reinterpret_cast<void**>(&pglEnable), myglEnable);
			DetourAttach(reinterpret_cast<void**>(&pglDisable), myglDisable);
			DetourAttach(reinterpret_cast<void**>(&pglOrtho), myglOrtho);
			DetourAttach(reinterpret_cast<void**>(&pSwapBuffers), mySwapBuffers);
			DetourAttach(reinterpret_cast<void**>(&pglTranslatef), myglTranslatef);
			DetourAttach(reinterpret_cast<void**>(&pglScalef), myglScalef);
			return DetourTransactionCommit() == NO_ERROR;
		}

		break;

		case DLL_PROCESS_DETACH:
		{
			// Removing the function interceptors
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			DetourDetach(reinterpret_cast<void**>(&pglEnable), myglEnable);
			DetourDetach(reinterpret_cast<void**>(&pglDisable), myglDisable);
			DetourDetach(reinterpret_cast<void**>(&pglOrtho), myglOrtho);
			DetourDetach(reinterpret_cast<void**>(&pSwapBuffers), mySwapBuffers);
			DetourDetach(reinterpret_cast<void**>(&pglTranslatef), myglTranslatef);
			DetourDetach(reinterpret_cast<void**>(&pglScalef), myglScalef);
			return DetourTransactionCommit() == NO_ERROR;
		}
	}

	return TRUE;
}