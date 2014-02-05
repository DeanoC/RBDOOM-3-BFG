/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.
			  2013 - Deano Calver for Confetti FX for Intel
This file is part of the (modified) Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/
/*
** qqgles3.h
*/

#ifndef _QGLES3_H__
#define _QGLES3_H__


#if !defined( USE_GLES3 )
#error Include "gl.h" with USE_GLES3 for OpenGL ES 3 support
#endif


#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h> // Needed for DXT1/5 extensions
#include <GLES3/gl3ext.h>

typedef void ( *GLExtension_t )( void );

#ifdef __cplusplus
extern "C" {
#endif

	GLExtension_t GLimp_ExtensionPointer( const char* name );

#ifdef __cplusplus
}
#endif

//===========================================================================

extern void (GL_APIENTRY* qglActiveTexture) (GLenum texture);
extern void (GL_APIENTRY* qglAttachShader) (GLuint program, GLuint shader);
extern void (GL_APIENTRY* qglBindAttribLocation) (GLuint program, GLuint index, const GLchar* name);
extern void (GL_APIENTRY* qglBindBuffer) (GLenum target, GLuint buffer);
extern void (GL_APIENTRY* qglBindFramebuffer) (GLenum target, GLuint framebuffer);
extern void (GL_APIENTRY* qglBindRenderbuffer) (GLenum target, GLuint renderbuffer);
extern void (GL_APIENTRY* qglBindTexture) (GLenum target, GLuint texture);
extern void (GL_APIENTRY* qglBlendColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (GL_APIENTRY* qglBlendEquation) (GLenum mode);
extern void (GL_APIENTRY* qglBlendEquationSeparate) (GLenum modeRGB, GLenum modeAlpha);
extern void (GL_APIENTRY* qglBlendFunc) (GLenum sfactor, GLenum dfactor);
extern void (GL_APIENTRY* qglBlendFuncSeparate) (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
extern void (GL_APIENTRY* qglBufferData) (GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
extern void (GL_APIENTRY* qglBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data);
extern GLenum (GL_APIENTRY* qglCheckFramebufferStatus) (GLenum target);
extern void (GL_APIENTRY* qglClear) (GLbitfield mask);
extern void (GL_APIENTRY* qglClearColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (GL_APIENTRY* qglClearDepthf) (GLfloat depth);
extern void (GL_APIENTRY* qglClearStencil) (GLint s);
extern void (GL_APIENTRY* qglColorMask) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void (GL_APIENTRY* qglCompileShader) (GLuint shader);
extern void (GL_APIENTRY* qglCompressedTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
extern void (GL_APIENTRY* qglCompressedTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
extern void (GL_APIENTRY* qglCopyTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void (GL_APIENTRY* qglCopyTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern GLuint (GL_APIENTRY* qglCreateProgram) (void);
extern GLuint (GL_APIENTRY* qglCreateShader) (GLenum type);
extern void (GL_APIENTRY* qglCullFace) (GLenum mode);
extern void (GL_APIENTRY* qglDeleteBuffers) (GLsizei n, const GLuint* buffers);
extern void (GL_APIENTRY* qglDeleteFramebuffers) (GLsizei n, const GLuint* framebuffers);
extern void (GL_APIENTRY* qglDeleteProgram) (GLuint program);
extern void (GL_APIENTRY* qglDeleteRenderbuffers) (GLsizei n, const GLuint* renderbuffers);
extern void (GL_APIENTRY* qglDeleteShader) (GLuint shader);
extern void (GL_APIENTRY* qglDeleteTextures) (GLsizei n, const GLuint* textures);
extern void (GL_APIENTRY* qglDepthFunc) (GLenum func);
extern void (GL_APIENTRY* qglDepthMask) (GLboolean flag);
extern void (GL_APIENTRY* qglDepthRangef) (GLfloat n, GLfloat f);
extern void (GL_APIENTRY* qglDetachShader) (GLuint program, GLuint shader);
extern void (GL_APIENTRY* qglDisable) (GLenum cap);
extern void (GL_APIENTRY* qglDisableVertexAttribArray) (GLuint index);
extern void (GL_APIENTRY* qglDrawArrays) (GLenum mode, GLint first, GLsizei count);
extern void (GL_APIENTRY* qglDrawElements) (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
extern void (GL_APIENTRY* qglEnable) (GLenum cap);
extern void (GL_APIENTRY* qglEnableVertexAttribArray) (GLuint index);
extern void (GL_APIENTRY* qglFinish) (void);
extern void (GL_APIENTRY* qglFlush) (void);
extern void (GL_APIENTRY* qglFramebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void (GL_APIENTRY* qglFramebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (GL_APIENTRY* qglFrontFace) (GLenum mode);
extern void (GL_APIENTRY* qglGenBuffers) (GLsizei n, GLuint* buffers);
extern void (GL_APIENTRY* qglGenerateMipmap) (GLenum target);
extern void (GL_APIENTRY* qglGenFramebuffers) (GLsizei n, GLuint* framebuffers);
extern void (GL_APIENTRY* qglGenRenderbuffers) (GLsizei n, GLuint* renderbuffers);
extern void (GL_APIENTRY* qglGenTextures) (GLsizei n, GLuint* textures);
extern void (GL_APIENTRY* qglGetActiveAttrib) (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
extern void (GL_APIENTRY* qglGetActiveUniform) (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
extern void (GL_APIENTRY* qglGetAttachedShaders) (GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders);
extern int  (GL_APIENTRY* qglGetAttribLocation) (GLuint program, const GLchar* name);
extern void (GL_APIENTRY* qglGetBooleanv) (GLenum pname, GLboolean* params);
extern void (GL_APIENTRY* qglGetBufferParameteriv) (GLenum target, GLenum pname, GLint* params);
extern GLenum (GL_APIENTRY* qglGetError) (void);
extern void (GL_APIENTRY* qglGetFloatv) (GLenum pname, GLfloat* params);
extern void (GL_APIENTRY* qglGetFramebufferAttachmentParameteriv) (GLenum target, GLenum attachment, GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetIntegerv) (GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetProgramiv) (GLuint program, GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetProgramInfoLog) (GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog);
extern void (GL_APIENTRY* qglGetRenderbufferParameteriv) (GLenum target, GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetShaderiv) (GLuint shader, GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetShaderInfoLog) (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog);
extern void (GL_APIENTRY* qglGetShaderPrecisionFormat) (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
extern void (GL_APIENTRY* qglGetShaderSource) (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source);
extern const GLubyte* (GL_APIENTRY* qglGetString) (GLenum name);
extern void (GL_APIENTRY* qglGetTexParameterfv) (GLenum target, GLenum pname, GLfloat* params);
extern void (GL_APIENTRY* qglGetTexParameteriv) (GLenum target, GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetUniformfv) (GLuint program, GLint location, GLfloat* params);
extern void (GL_APIENTRY* qglGetUniformiv) (GLuint program, GLint location, GLint* params);
extern int  (GL_APIENTRY* qglGetUniformLocation) (GLuint program, const GLchar* name);
extern void (GL_APIENTRY* qglGetVertexAttribfv) (GLuint index, GLenum pname, GLfloat* params);
extern void (GL_APIENTRY* qglGetVertexAttribiv) (GLuint index, GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetVertexAttribPointerv) (GLuint index, GLenum pname, GLvoid** pointer);
extern void (GL_APIENTRY* qglHint) (GLenum target, GLenum mode);
extern GLboolean (GL_APIENTRY* qglIsBuffer) (GLuint buffer);
extern GLboolean (GL_APIENTRY* qglIsEnabled) (GLenum cap);
extern GLboolean (GL_APIENTRY* qglIsFramebuffer) (GLuint framebuffer);
extern GLboolean (GL_APIENTRY* qglIsProgram) (GLuint program);
extern GLboolean (GL_APIENTRY* qglIsRenderbuffer) (GLuint renderbuffer);
extern GLboolean (GL_APIENTRY* qglIsShader) (GLuint shader);
extern GLboolean (GL_APIENTRY* qglIsTexture) (GLuint texture);
extern void (GL_APIENTRY* qglLineWidth) (GLfloat width);
extern void (GL_APIENTRY* qglLinkProgram) (GLuint program);
extern void (GL_APIENTRY* qglPixelStorei) (GLenum pname, GLint param);
extern void (GL_APIENTRY* qglPolygonOffset) (GLfloat factor, GLfloat units);
extern void (GL_APIENTRY* qglReadPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
extern void (GL_APIENTRY* qglReleaseShaderCompiler) (void);
extern void (GL_APIENTRY* qglRenderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern void (GL_APIENTRY* qglSampleCoverage) (GLfloat value, GLboolean invert);
extern void (GL_APIENTRY* qglScissor) (GLint x, GLint y, GLsizei width, GLsizei height);
extern void (GL_APIENTRY* qglShaderBinary) (GLsizei n, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
extern void (GL_APIENTRY* qglShaderSource) (GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
extern void (GL_APIENTRY* qglStencilFunc) (GLenum func, GLint ref, GLuint mask);
extern void (GL_APIENTRY* qglStencilFuncSeparate) (GLenum face, GLenum func, GLint ref, GLuint mask);
extern void (GL_APIENTRY* qglStencilMask) (GLuint mask);
extern void (GL_APIENTRY* qglStencilMaskSeparate) (GLenum face, GLuint mask);
extern void (GL_APIENTRY* qglStencilOp) (GLenum fail, GLenum zfail, GLenum zpass);
extern void (GL_APIENTRY* qglStencilOpSeparate) (GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
extern void (GL_APIENTRY* qglTexImage2D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (GL_APIENTRY* qglTexParameterf) (GLenum target, GLenum pname, GLfloat param);
extern void (GL_APIENTRY* qglTexParameterfv) (GLenum target, GLenum pname, const GLfloat* params);
extern void (GL_APIENTRY* qglTexParameteri) (GLenum target, GLenum pname, GLint param);
extern void (GL_APIENTRY* qglTexParameteriv) (GLenum target, GLenum pname, const GLint* params);
extern void (GL_APIENTRY* qglTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
extern void (GL_APIENTRY* qglUniform1f) (GLint location, GLfloat x);
extern void (GL_APIENTRY* qglUniform1fv) (GLint location, GLsizei count, const GLfloat* v);
extern void (GL_APIENTRY* qglUniform1i) (GLint location, GLint x);
extern void (GL_APIENTRY* qglUniform1iv) (GLint location, GLsizei count, const GLint* v);
extern void (GL_APIENTRY* qglUniform2f) (GLint location, GLfloat x, GLfloat y);
extern void (GL_APIENTRY* qglUniform2fv) (GLint location, GLsizei count, const GLfloat* v);
extern void (GL_APIENTRY* qglUniform2i) (GLint location, GLint x, GLint y);
extern void (GL_APIENTRY* qglUniform2iv) (GLint location, GLsizei count, const GLint* v);
extern void (GL_APIENTRY* qglUniform3f) (GLint location, GLfloat x, GLfloat y, GLfloat z);
extern void (GL_APIENTRY* qglUniform3fv) (GLint location, GLsizei count, const GLfloat* v);
extern void (GL_APIENTRY* qglUniform3i) (GLint location, GLint x, GLint y, GLint z);
extern void (GL_APIENTRY* qglUniform3iv) (GLint location, GLsizei count, const GLint* v);
extern void (GL_APIENTRY* qglUniform4f) (GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (GL_APIENTRY* qglUniform4fv) (GLint location, GLsizei count, const GLfloat* v);
extern void (GL_APIENTRY* qglUniform4i) (GLint location, GLint x, GLint y, GLint z, GLint w);
extern void (GL_APIENTRY* qglUniform4iv) (GLint location, GLsizei count, const GLint* v);
extern void (GL_APIENTRY* qglUniformMatrix2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (GL_APIENTRY* qglUniformMatrix3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (GL_APIENTRY* qglUniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (GL_APIENTRY* qglUseProgram) (GLuint program);
extern void (GL_APIENTRY* qglValidateProgram) (GLuint program);
extern void (GL_APIENTRY* qglVertexAttrib1f) (GLuint indx, GLfloat x);
extern void (GL_APIENTRY* qglVertexAttrib1fv) (GLuint indx, const GLfloat* values);
extern void (GL_APIENTRY* qglVertexAttrib2f) (GLuint indx, GLfloat x, GLfloat y);
extern void (GL_APIENTRY* qglVertexAttrib2fv) (GLuint indx, const GLfloat* values);
extern void (GL_APIENTRY* qglVertexAttrib3f) (GLuint indx, GLfloat x, GLfloat y, GLfloat z);
extern void (GL_APIENTRY* qglVertexAttrib3fv) (GLuint indx, const GLfloat* values);
extern void (GL_APIENTRY* qglVertexAttrib4f) (GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (GL_APIENTRY* qglVertexAttrib4fv) (GLuint indx, const GLfloat* values);
extern void (GL_APIENTRY* qglVertexAttribPointer) (GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr);
extern void (GL_APIENTRY* qglViewport) (GLint x, GLint y, GLsizei width, GLsizei height);
extern void (GL_APIENTRY* qglReadBuffer) (GLenum mode);
extern void (GL_APIENTRY* qglDrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices);
extern void (GL_APIENTRY* qglTexImage3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (GL_APIENTRY* qglTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
extern void (GL_APIENTRY* qglCopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (GL_APIENTRY* qglCompressedTexImage3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data);
extern void (GL_APIENTRY* qglCompressedTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
extern void (GL_APIENTRY* qglGenQueries) (GLsizei n, GLuint* ids);
extern void (GL_APIENTRY* qglDeleteQueries) (GLsizei n, const GLuint* ids);
extern GLboolean (GL_APIENTRY* qglIsQuery) (GLuint id);
extern void (GL_APIENTRY* qglBeginQuery) (GLenum target, GLuint id);
extern void (GL_APIENTRY* qglEndQuery) (GLenum target);
extern void (GL_APIENTRY* qglGetQueryiv) (GLenum target, GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetQueryObjectuiv) (GLuint id, GLenum pname, GLuint* params);
extern GLboolean (GL_APIENTRY* qglUnmapBuffer) (GLenum target);
extern void (GL_APIENTRY* qglGetBufferPointerv) (GLenum target, GLenum pname, GLvoid** params);
extern void (GL_APIENTRY* qglDrawBuffers) (GLsizei n, const GLenum* bufs);
extern void (GL_APIENTRY* qglUniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (GL_APIENTRY* qglUniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (GL_APIENTRY* qglUniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (GL_APIENTRY* qglUniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (GL_APIENTRY* qglUniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (GL_APIENTRY* qglUniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (GL_APIENTRY* qglBlitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
extern void (GL_APIENTRY* qglRenderbufferStorageMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern void (GL_APIENTRY* qglFramebufferTextureLayer) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern GLvoid* (GL_APIENTRY* qglMapBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
extern void (GL_APIENTRY* qglFlushMappedBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length);
extern void (GL_APIENTRY* qglBindVertexArray) (GLuint array);
extern void (GL_APIENTRY* qglDeleteVertexArrays) (GLsizei n, const GLuint* arrays);
extern void (GL_APIENTRY* qglGenVertexArrays) (GLsizei n, GLuint* arrays);
extern GLboolean (GL_APIENTRY* qglIsVertexArray) (GLuint array);
extern void (GL_APIENTRY* qglGetIntegeri_v) (GLenum target, GLuint index, GLint* data);
extern void (GL_APIENTRY* qglBeginTransformFeedback) (GLenum primitiveMode);
extern void (GL_APIENTRY* qglEndTransformFeedback) (void);
extern void (GL_APIENTRY* qglBindBufferRange) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (GL_APIENTRY* qglBindBufferBase) (GLenum target, GLuint index, GLuint buffer);
extern void (GL_APIENTRY* qglTransformFeedbackVaryings) (GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
extern void (GL_APIENTRY* qglGetTransformFeedbackVarying) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
extern void (GL_APIENTRY* qglVertexAttribIPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (GL_APIENTRY* qglGetVertexAttribIiv) (GLuint index, GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetVertexAttribIuiv) (GLuint index, GLenum pname, GLuint* params);
extern void (GL_APIENTRY* qglVertexAttribI4i) (GLuint index, GLint x, GLint y, GLint z, GLint w);
extern void (GL_APIENTRY* qglVertexAttribI4ui) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
extern void (GL_APIENTRY* qglVertexAttribI4iv) (GLuint index, const GLint* v);
extern void (GL_APIENTRY* qglVertexAttribI4uiv) (GLuint index, const GLuint* v);
extern void (GL_APIENTRY* qglGetUniformuiv) (GLuint program, GLint location, GLuint* params);
extern GLint (GL_APIENTRY* qglGetFragDataLocation) (GLuint program, const GLchar *name);
extern void (GL_APIENTRY* qglUniform1ui) (GLint location, GLuint v0);
extern void (GL_APIENTRY* qglUniform2ui) (GLint location, GLuint v0, GLuint v1);
extern void (GL_APIENTRY* qglUniform3ui) (GLint location, GLuint v0, GLuint v1, GLuint v2);
extern void (GL_APIENTRY* qglUniform4ui) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern void (GL_APIENTRY* qglUniform1uiv) (GLint location, GLsizei count, const GLuint* value);
extern void (GL_APIENTRY* qglUniform2uiv) (GLint location, GLsizei count, const GLuint* value);
extern void (GL_APIENTRY* qglUniform3uiv) (GLint location, GLsizei count, const GLuint* value);
extern void (GL_APIENTRY* qglUniform4uiv) (GLint location, GLsizei count, const GLuint* value);
extern void (GL_APIENTRY* qglClearBufferiv) (GLenum buffer, GLint drawbuffer, const GLint* value);
extern void (GL_APIENTRY* qglClearBufferuiv) (GLenum buffer, GLint drawbuffer, const GLuint* value);
extern void (GL_APIENTRY* qglClearBufferfv) (GLenum buffer, GLint drawbuffer, const GLfloat* value);
extern void (GL_APIENTRY* qglClearBufferfi) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
extern const GLubyte* (GL_APIENTRY* qglGetStringi) (GLenum name, GLuint index);
extern void (GL_APIENTRY* qglCopyBufferSubData) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
extern void (GL_APIENTRY* qglGetUniformIndices) (GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
extern void (GL_APIENTRY* qglGetActiveUniformsiv) (GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
extern GLuint (GL_APIENTRY* qglGetUniformBlockIndex) (GLuint program, const GLchar* uniformBlockName);
extern void (GL_APIENTRY* qglGetActiveUniformBlockiv) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetActiveUniformBlockName) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
extern void (GL_APIENTRY* qglUniformBlockBinding) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
extern void (GL_APIENTRY* qglDrawArraysInstanced) (GLenum mode, GLint first, GLsizei count, GLsizei instanceCount);
extern void (GL_APIENTRY* qglDrawElementsInstanced) (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instanceCount);
extern GLsync (GL_APIENTRY* qglFenceSync) (GLenum condition, GLbitfield flags);
extern GLboolean (GL_APIENTRY* qglIsSync) (GLsync sync);
extern void (GL_APIENTRY* qglDeleteSync) (GLsync sync);
extern GLenum (GL_APIENTRY* qglClientWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void (GL_APIENTRY* qglWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void (GL_APIENTRY* qglGetInteger64v) (GLenum pname, GLint64* params);
extern void (GL_APIENTRY* qglGetSynciv) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
extern void (GL_APIENTRY* qglGetInteger64i_v) (GLenum target, GLuint index, GLint64* data);
extern void (GL_APIENTRY* qglGetBufferParameteri64v) (GLenum target, GLenum pname, GLint64* params);
extern void (GL_APIENTRY* qglGenSamplers) (GLsizei count, GLuint* samplers);
extern void (GL_APIENTRY* qglDeleteSamplers) (GLsizei count, const GLuint* samplers);
extern GLboolean (GL_APIENTRY* qglIsSampler) (GLuint sampler);
extern void (GL_APIENTRY* qglBindSampler) (GLuint unit, GLuint sampler);
extern void (GL_APIENTRY* qglSamplerParameteri) (GLuint sampler, GLenum pname, GLint param);
extern void (GL_APIENTRY* qglSamplerParameteriv) (GLuint sampler, GLenum pname, const GLint* param);
extern void (GL_APIENTRY* qglSamplerParameterf) (GLuint sampler, GLenum pname, GLfloat param);
extern void (GL_APIENTRY* qglSamplerParameterfv) (GLuint sampler, GLenum pname, const GLfloat* param);
extern void (GL_APIENTRY* qglGetSamplerParameteriv) (GLuint sampler, GLenum pname, GLint* params);
extern void (GL_APIENTRY* qglGetSamplerParameterfv) (GLuint sampler, GLenum pname, GLfloat* params);
extern void (GL_APIENTRY* qglVertexAttribDivisor) (GLuint index, GLuint divisor);
extern void (GL_APIENTRY* qglBindTransformFeedback) (GLenum target, GLuint id);
extern void (GL_APIENTRY* qglDeleteTransformFeedbacks) (GLsizei n, const GLuint* ids);
extern void (GL_APIENTRY* qglGenTransformFeedbacks) (GLsizei n, GLuint* ids);
extern GLboolean (GL_APIENTRY* qglIsTransformFeedback) (GLuint id);
extern void (GL_APIENTRY* qglPauseTransformFeedback) (void);
extern void (GL_APIENTRY* qglResumeTransformFeedback) (void);
extern void (GL_APIENTRY* qglGetProgramBinary) (GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
extern void (GL_APIENTRY* qglProgramBinary) (GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length);
extern void (GL_APIENTRY* qglProgramParameteri) (GLuint program, GLenum pname, GLint value);
extern void (GL_APIENTRY* qglInvalidateFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum* attachments);
extern void (GL_APIENTRY* qglInvalidateSubFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (GL_APIENTRY* qglTexStorage2D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
extern void (GL_APIENTRY* qglTexStorage3D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
extern void (GL_APIENTRY* qglGetInternalformativ) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params);


// emulation helpers
inline void qglDrawBuffer( GLenum buffer) {
	qglDrawBuffers( 1, &buffer );
}
#endif
