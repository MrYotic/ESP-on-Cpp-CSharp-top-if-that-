#include <Windows.h>

#include "GL.h"
#include "Detours.h"

#include "Color.h"
#include "Radius.h"
#include "Position.h"

typedef void(__stdcall* T_glEnable)(GLenum);
typedef void(__stdcall* T_glDisable)(GLenum);

typedef BOOL(__stdcall* T_SwapBuffers)(HDC);
typedef void(__stdcall* T_glScalef)(float, float, float);
typedef void(__stdcall* T_glTranslatef)(float, float, float);
typedef void(__stdcall* T_glOrtho)(double, double, double, double, double, double);