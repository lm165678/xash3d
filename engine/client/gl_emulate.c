#if defined XASH_GLES2_RENDER

#include "common.h"
#include "gl_local.h"

//GLenum curMatrixMode;
//float projMtx[16];
//float modelViewMtx[16];
void pglemuColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) __attribute__((pcs("aapcs")));

void pglemuColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	R_ColorUniform(red,green,blue,alpha);
}
void pglemuColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
	R_ColorUniform((float)red/255.0f,(float)green/255.0f,(float)blue/255.0f,(float)alpha/255.0f);
}
void pglemuColor4ubv (const GLubyte *v)
{
	R_ColorUniform((float)v[0]/255.0f,(float)v[1]/255.0f,(float)v[2]/255.0f,(float)v[3]/255.0f);
}
void pglemuPolygonMode(GLenum face, GLenum mode){}
void pglemuAlphaFunc(GLenum func, GLclampf ref){}
void pglemuShadeModel (GLenum mode){}
void pglemuPointSize (GLfloat size){}
void pglemuMatrixMode (GLenum mode)
{
//	curMatrixMode=mode;
}
void pglemuLoadIdentity (){}
void pglemuOrtho (GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar){}
void pglemuTexEnvi(GLenum target, GLenum pname, GLint param){}
void pglemuLoadMatrixf (const GLfloat *m)
{
/*	if(curMatrixMode==GL_PROJECTION)
		memcpy(projMtx,m,64);
	else
		memcpy(modelViewMtx,m,64);*/
}
void pglemuDepthRange( GLclampd zNear, GLclampd zFar ) __attribute__((pcs("aapcs")));
void pglemuDepthRange( GLclampd zNear, GLclampd zFar )
{
	pglDepthRangef( zNear, zFar );
}

GLenum pglemuGetError()
{
	return GL_NO_ERROR;
}
void (*prealglTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((pcs("aapcs")));
void pemuglTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((pcs("aapcs")));
void pglemuTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	internalformat = format;
	prealglTexImage2D( target, level, internalformat, width, height, border, format, type, pixels );
}


void R_InitGLEmu( void )
{
	pglColor4f = pglemuColor4f;
	pglColor4ub = pglemuColor4ub;
	pglColor4ubv = pglemuColor4ubv;
	pglPolygonMode = pglemuPolygonMode;
	pglAlphaFunc = pglemuAlphaFunc;
	pglShadeModel = pglemuShadeModel;
	pglPointSize = pglemuPointSize;
	pglMatrixMode = pglemuMatrixMode;
	pglLoadIdentity = pglemuLoadIdentity;
	pglOrtho = pglemuOrtho;
	pglTexEnvi = pglemuTexEnvi;
	pglLoadMatrixf = pglemuLoadMatrixf;
	pglDepthRange = pglemuDepthRange;
	pglGetError = pglemuGetError;
	prealglTexImage2D = pglTexImage2D;
	pglTexImage2D = pglemuTexImage2D;
}
/*
void glTexEnvf (GLenum target, GLenum pname, GLfloat param){}
void glColor3f (GLfloat red, GLfloat green, GLfloat blue){}
void glColor3ub (GLubyte red, GLubyte green, GLubyte blue){}
void glBegin(GLenum mode){}
void glTexCoord2f(GLfloat s, GLfloat t){}
void glVertex2f (GLfloat x, GLfloat y){}
void glVertex3f(GLfloat x, GLfloat y, GLfloat z){}
void glVertex3fv(const GLfloat *v){}
void glVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer){}
void glEnd(){}
void glFogf (GLenum pname, GLfloat param){}
void glFogfv (GLenum pname, const GLfloat *params){}
void glFogi (GLenum pname, GLint param){}
void glDepthRange (GLclampf zNear, GLclampf zFar){}
void glClipPlane (GLenum plane, const GLdouble *equation){}
void glDrawBuffer (GLenum mode){}
void glNormal3fv (const GLfloat *v){}
void glDisableClientState(GLenum array){}
void glEnableClientState (GLenum array){}*/

#endif
