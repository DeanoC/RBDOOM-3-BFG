/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").

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
** sdl_qgles3.cpp
**
** This file implements the operating system binding of GLES3 to QGL function
** pointers.
**
*/
#pragma hdrstop
#include "../../idlib/precompiled.h"

#include <float.h>
//#include "win_local.h"
#include "../../renderer/tr_local.h"

void (GL_APIENTRY* qglActiveTexture) (GLenum texture);
void (GL_APIENTRY* qglAttachShader) (GLuint program, GLuint shader);
void (GL_APIENTRY* qglBindAttribLocation) (GLuint program, GLuint index, const GLchar* name);
void (GL_APIENTRY* qglBindBuffer) (GLenum target, GLuint buffer);
void (GL_APIENTRY*qglBindFramebuffer) (GLenum target, GLuint framebuffer);
void (GL_APIENTRY* qglBindRenderbuffer) (GLenum target, GLuint renderbuffer);
void (GL_APIENTRY* qglBindTexture) (GLenum target, GLuint texture);
void (GL_APIENTRY* qglBlendColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void (GL_APIENTRY* qglBlendEquation) (GLenum mode);
void (GL_APIENTRY* qglBlendEquationSeparate) (GLenum modeRGB, GLenum modeAlpha);
void (GL_APIENTRY* qglBlendFunc) (GLenum sfactor, GLenum dfactor);
void (GL_APIENTRY* qglBlendFuncSeparate) (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void (GL_APIENTRY* qglBufferData) (GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
void (GL_APIENTRY* qglBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data);
GLenum (GL_APIENTRY* qglCheckFramebufferStatus) (GLenum target);
void (GL_APIENTRY* qglClear) (GLbitfield mask);
void (GL_APIENTRY* qglClearColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void (GL_APIENTRY* qglClearDepthf) (GLfloat depth);
void (GL_APIENTRY* qglClearStencil) (GLint s);
void (GL_APIENTRY* qglColorMask) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void (GL_APIENTRY* qglCompileShader) (GLuint shader);
void (GL_APIENTRY* qglCompressedTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
void (GL_APIENTRY* qglCompressedTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
void (GL_APIENTRY* qglCopyTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void (GL_APIENTRY* qglCopyTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLuint (GL_APIENTRY* qglCreateProgram) (void);
GLuint (GL_APIENTRY* qglCreateShader) (GLenum type);
void (GL_APIENTRY* qglCullFace) (GLenum mode);
void (GL_APIENTRY* qglDeleteBuffers) (GLsizei n, const GLuint* buffers);
void (GL_APIENTRY* qglDeleteFramebuffers) (GLsizei n, const GLuint* framebuffers);
void (GL_APIENTRY* qglDeleteProgram) (GLuint program);
void (GL_APIENTRY* qglDeleteRenderbuffers) (GLsizei n, const GLuint* renderbuffers);
void (GL_APIENTRY* qglDeleteShader) (GLuint shader);
void (GL_APIENTRY* qglDeleteTextures) (GLsizei n, const GLuint* textures);
void (GL_APIENTRY* qglDepthFunc) (GLenum func);
void (GL_APIENTRY* qglDepthMask) (GLboolean flag);
void (GL_APIENTRY* qglDepthRangef) (GLfloat n, GLfloat f);
void (GL_APIENTRY* qglDetachShader) (GLuint program, GLuint shader);
void (GL_APIENTRY* qglDisable) (GLenum cap);
void (GL_APIENTRY* qglDisableVertexAttribArray) (GLuint index);
void (GL_APIENTRY* qglDrawArrays) (GLenum mode, GLint first, GLsizei count);
void (GL_APIENTRY* qglDrawElements) (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
void (GL_APIENTRY* qglEnable) (GLenum cap);
void (GL_APIENTRY* qglEnableVertexAttribArray) (GLuint index);
void (GL_APIENTRY* qglFinish) (void);
void (GL_APIENTRY* qglFlush) (void);
void (GL_APIENTRY* qglFramebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void (GL_APIENTRY* qglFramebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void (GL_APIENTRY* qglFrontFace) (GLenum mode);
void (GL_APIENTRY* qglGenBuffers) (GLsizei n, GLuint* buffers);
void (GL_APIENTRY* qglGenerateMipmap) (GLenum target);
void (GL_APIENTRY* qglGenFramebuffers) (GLsizei n, GLuint* framebuffers);
void (GL_APIENTRY* qglGenRenderbuffers) (GLsizei n, GLuint* renderbuffers);
void (GL_APIENTRY* qglGenTextures) (GLsizei n, GLuint* textures);
void (GL_APIENTRY* qglGetActiveAttrib) (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
void (GL_APIENTRY* qglGetActiveUniform) (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
void (GL_APIENTRY* qglGetAttachedShaders) (GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders);
int  (GL_APIENTRY* qglGetAttribLocation) (GLuint program, const GLchar* name);
void (GL_APIENTRY* qglGetBooleanv) (GLenum pname, GLboolean* params);
void (GL_APIENTRY* qglGetBufferParameteriv) (GLenum target, GLenum pname, GLint* params);
GLenum (GL_APIENTRY* qglGetError) (void);
void (GL_APIENTRY* qglGetFloatv) (GLenum pname, GLfloat* params);
void (GL_APIENTRY* qglGetFramebufferAttachmentParameteriv) (GLenum target, GLenum attachment, GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetIntegerv) (GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetProgramiv) (GLuint program, GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetProgramInfoLog) (GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog);
void (GL_APIENTRY* qglGetRenderbufferParameteriv) (GLenum target, GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetShaderiv) (GLuint shader, GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetShaderInfoLog) (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog);
void (GL_APIENTRY* qglGetShaderPrecisionFormat) (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
void (GL_APIENTRY* qglGetShaderSource) (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source);
const GLubyte* (GL_APIENTRY* qglGetString) (GLenum name);
void (GL_APIENTRY* qglGetTexParameterfv) (GLenum target, GLenum pname, GLfloat* params);
void (GL_APIENTRY* qglGetTexParameteriv) (GLenum target, GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetUniformfv) (GLuint program, GLint location, GLfloat* params);
void (GL_APIENTRY* qglGetUniformiv) (GLuint program, GLint location, GLint* params);
int  (GL_APIENTRY* qglGetUniformLocation) (GLuint program, const GLchar* name);
void (GL_APIENTRY* qglGetVertexAttribfv) (GLuint index, GLenum pname, GLfloat* params);
void (GL_APIENTRY* qglGetVertexAttribiv) (GLuint index, GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetVertexAttribPointerv) (GLuint index, GLenum pname, GLvoid** pointer);
void (GL_APIENTRY* qglHint) (GLenum target, GLenum mode);
GLboolean (GL_APIENTRY* qglIsBuffer) (GLuint buffer);
GLboolean (GL_APIENTRY* qglIsEnabled) (GLenum cap);
GLboolean (GL_APIENTRY* qglIsFramebuffer) (GLuint framebuffer);
GLboolean (GL_APIENTRY* qglIsProgram) (GLuint program);
GLboolean (GL_APIENTRY* qglIsRenderbuffer) (GLuint renderbuffer);
GLboolean (GL_APIENTRY* qglIsShader) (GLuint shader);
GLboolean (GL_APIENTRY* qglIsTexture) (GLuint texture);
void (GL_APIENTRY* qglLineWidth) (GLfloat width);
void (GL_APIENTRY* qglLinkProgram) (GLuint program);
void (GL_APIENTRY* qglPixelStorei) (GLenum pname, GLint param);
void (GL_APIENTRY* qglPolygonOffset) (GLfloat factor, GLfloat units);
void (GL_APIENTRY* qglReadPixels) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
void (GL_APIENTRY* qglReleaseShaderCompiler) (void);
void (GL_APIENTRY* qglRenderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void (GL_APIENTRY* qglSampleCoverage) (GLfloat value, GLboolean invert);
void (GL_APIENTRY* qglScissor) (GLint x, GLint y, GLsizei width, GLsizei height);
void (GL_APIENTRY* qglShaderBinary) (GLsizei n, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
void (GL_APIENTRY* qglShaderSource) (GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
void (GL_APIENTRY* qglStencilFunc) (GLenum func, GLint ref, GLuint mask);
void (GL_APIENTRY* qglStencilFuncSeparate) (GLenum face, GLenum func, GLint ref, GLuint mask);
void (GL_APIENTRY* qglStencilMask) (GLuint mask);
void (GL_APIENTRY* qglStencilMaskSeparate) (GLenum face, GLuint mask);
void (GL_APIENTRY* qglStencilOp) (GLenum fail, GLenum zfail, GLenum zpass);
void (GL_APIENTRY* qglStencilOpSeparate) (GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
void (GL_APIENTRY* qglTexImage2D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
void (GL_APIENTRY* qglTexParameterf) (GLenum target, GLenum pname, GLfloat param);
void (GL_APIENTRY* qglTexParameterfv) (GLenum target, GLenum pname, const GLfloat* params);
void (GL_APIENTRY* qglTexParameteri) (GLenum target, GLenum pname, GLint param);
void (GL_APIENTRY* qglTexParameteriv) (GLenum target, GLenum pname, const GLint* params);
void (GL_APIENTRY* qglTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
void (GL_APIENTRY* qglUniform1f) (GLint location, GLfloat x);
void (GL_APIENTRY* qglUniform1fv) (GLint location, GLsizei count, const GLfloat* v);
void (GL_APIENTRY* qglUniform1i) (GLint location, GLint x);
void (GL_APIENTRY* qglUniform1iv) (GLint location, GLsizei count, const GLint* v);
void (GL_APIENTRY* qglUniform2f) (GLint location, GLfloat x, GLfloat y);
void (GL_APIENTRY* qglUniform2fv) (GLint location, GLsizei count, const GLfloat* v);
void (GL_APIENTRY* qglUniform2i) (GLint location, GLint x, GLint y);
void (GL_APIENTRY* qglUniform2iv) (GLint location, GLsizei count, const GLint* v);
void (GL_APIENTRY* qglUniform3f) (GLint location, GLfloat x, GLfloat y, GLfloat z);
void (GL_APIENTRY* qglUniform3fv) (GLint location, GLsizei count, const GLfloat* v);
void (GL_APIENTRY* qglUniform3i) (GLint location, GLint x, GLint y, GLint z);
void (GL_APIENTRY* qglUniform3iv) (GLint location, GLsizei count, const GLint* v);
void (GL_APIENTRY* qglUniform4f) (GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void (GL_APIENTRY* qglUniform4fv) (GLint location, GLsizei count, const GLfloat* v);
void (GL_APIENTRY* qglUniform4i) (GLint location, GLint x, GLint y, GLint z, GLint w);
void (GL_APIENTRY* qglUniform4iv) (GLint location, GLsizei count, const GLint* v);
void (GL_APIENTRY* qglUniformMatrix2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void (GL_APIENTRY* qglUniformMatrix3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void (GL_APIENTRY* qglUniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void (GL_APIENTRY* qglUseProgram) (GLuint program);
void (GL_APIENTRY* qglValidateProgram) (GLuint program);
void (GL_APIENTRY* qglVertexAttrib1f) (GLuint indx, GLfloat x);
void (GL_APIENTRY* qglVertexAttrib1fv) (GLuint indx, const GLfloat* values);
void (GL_APIENTRY* qglVertexAttrib2f) (GLuint indx, GLfloat x, GLfloat y);
void (GL_APIENTRY* qglVertexAttrib2fv) (GLuint indx, const GLfloat* values);
void (GL_APIENTRY* qglVertexAttrib3f) (GLuint indx, GLfloat x, GLfloat y, GLfloat z);
void (GL_APIENTRY* qglVertexAttrib3fv) (GLuint indx, const GLfloat* values);
void (GL_APIENTRY* qglVertexAttrib4f) (GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void (GL_APIENTRY* qglVertexAttrib4fv) (GLuint indx, const GLfloat* values);
void (GL_APIENTRY* qglVertexAttribPointer) (GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr);
void (GL_APIENTRY* qglViewport) (GLint x, GLint y, GLsizei width, GLsizei height);
void (GL_APIENTRY* qglReadBuffer) (GLenum mode);
void (GL_APIENTRY* qglDrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices);
void (GL_APIENTRY* qglTexImage3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
void (GL_APIENTRY* qglTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
void (GL_APIENTRY* qglCopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void (GL_APIENTRY* qglCompressedTexImage3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data);
void (GL_APIENTRY* qglCompressedTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
void (GL_APIENTRY* qglGenQueries) (GLsizei n, GLuint* ids);
void (GL_APIENTRY* qglDeleteQueries) (GLsizei n, const GLuint* ids);
GLboolean (GL_APIENTRY* qglIsQuery) (GLuint id);
void (GL_APIENTRY* qglBeginQuery) (GLenum target, GLuint id);
void (GL_APIENTRY* qglEndQuery) (GLenum target);
void (GL_APIENTRY* qglGetQueryiv) (GLenum target, GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetQueryObjectuiv) (GLuint id, GLenum pname, GLuint* params);
GLboolean (GL_APIENTRY* qglUnmapBuffer) (GLenum target);
void (GL_APIENTRY* qglGetBufferPointerv) (GLenum target, GLenum pname, GLvoid** params);
void (GL_APIENTRY* qglDrawBuffers) (GLsizei n, const GLenum* bufs);
void (GL_APIENTRY* qglUniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void (GL_APIENTRY* qglUniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void (GL_APIENTRY* qglUniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void (GL_APIENTRY* qglUniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void (GL_APIENTRY* qglUniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void (GL_APIENTRY* qglUniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
void (GL_APIENTRY* qglBlitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void (GL_APIENTRY* qglRenderbufferStorageMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void (GL_APIENTRY* qglFramebufferTextureLayer) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLvoid* (GL_APIENTRY* qglMapBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
void (GL_APIENTRY* qglFlushMappedBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length);
void (GL_APIENTRY* qglBindVertexArray) (GLuint array);
void (GL_APIENTRY* qglDeleteVertexArrays) (GLsizei n, const GLuint* arrays);
void (GL_APIENTRY* qglGenVertexArrays) (GLsizei n, GLuint* arrays);
GLboolean (GL_APIENTRY* qglIsVertexArray) (GLuint array);
void (GL_APIENTRY* qglGetIntegeri_v) (GLenum target, GLuint index, GLint* data);
void (GL_APIENTRY* qglBeginTransformFeedback) (GLenum primitiveMode);
void (GL_APIENTRY* qglEndTransformFeedback) (void);
void (GL_APIENTRY* qglBindBufferRange) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void (GL_APIENTRY* qglBindBufferBase) (GLenum target, GLuint index, GLuint buffer);
void (GL_APIENTRY* qglTransformFeedbackVaryings) (GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
void (GL_APIENTRY* qglGetTransformFeedbackVarying) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
void (GL_APIENTRY* qglVertexAttribIPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
void (GL_APIENTRY* qglGetVertexAttribIiv) (GLuint index, GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetVertexAttribIuiv) (GLuint index, GLenum pname, GLuint* params);
void (GL_APIENTRY* qglVertexAttribI4i) (GLuint index, GLint x, GLint y, GLint z, GLint w);
void (GL_APIENTRY* qglVertexAttribI4ui) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void (GL_APIENTRY* qglVertexAttribI4iv) (GLuint index, const GLint* v);
void (GL_APIENTRY* qglVertexAttribI4uiv) (GLuint index, const GLuint* v);
void (GL_APIENTRY* qglGetUniformuiv) (GLuint program, GLint location, GLuint* params);
GLint (GL_APIENTRY* qglGetFragDataLocation) (GLuint program, const GLchar *name);
void (GL_APIENTRY* qglUniform1ui) (GLint location, GLuint v0);
void (GL_APIENTRY* qglUniform2ui) (GLint location, GLuint v0, GLuint v1);
void (GL_APIENTRY* qglUniform3ui) (GLint location, GLuint v0, GLuint v1, GLuint v2);
void (GL_APIENTRY* qglUniform4ui) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void (GL_APIENTRY* qglUniform1uiv) (GLint location, GLsizei count, const GLuint* value);
void (GL_APIENTRY* qglUniform2uiv) (GLint location, GLsizei count, const GLuint* value);
void (GL_APIENTRY* qglUniform3uiv) (GLint location, GLsizei count, const GLuint* value);
void (GL_APIENTRY* qglUniform4uiv) (GLint location, GLsizei count, const GLuint* value);
void (GL_APIENTRY* qglClearBufferiv) (GLenum buffer, GLint drawbuffer, const GLint* value);
void (GL_APIENTRY* qglClearBufferuiv) (GLenum buffer, GLint drawbuffer, const GLuint* value);
void (GL_APIENTRY* qglClearBufferfv) (GLenum buffer, GLint drawbuffer, const GLfloat* value);
void (GL_APIENTRY* qglClearBufferfi) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
const GLubyte* (GL_APIENTRY* qglGetStringi) (GLenum name, GLuint index);
void (GL_APIENTRY* qglCopyBufferSubData) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
void (GL_APIENTRY* qglGetUniformIndices) (GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
void (GL_APIENTRY* qglGetActiveUniformsiv) (GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
GLuint (GL_APIENTRY* qglGetUniformBlockIndex) (GLuint program, const GLchar* uniformBlockName);
void (GL_APIENTRY* qglGetActiveUniformBlockiv) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetActiveUniformBlockName) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
void (GL_APIENTRY* qglUniformBlockBinding) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
void (GL_APIENTRY* qglDrawArraysInstanced) (GLenum mode, GLint first, GLsizei count, GLsizei instanceCount);
void (GL_APIENTRY* qglDrawElementsInstanced) (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instanceCount);
GLsync (GL_APIENTRY* qglFenceSync) (GLenum condition, GLbitfield flags);
GLboolean (GL_APIENTRY* qglIsSync) (GLsync sync);
void (GL_APIENTRY* qglDeleteSync) (GLsync sync);
GLenum (GL_APIENTRY* qglClientWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout);
void (GL_APIENTRY* qglWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout);
void (GL_APIENTRY* qglGetInteger64v) (GLenum pname, GLint64* params);
void (GL_APIENTRY* qglGetSynciv) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
void (GL_APIENTRY* qglGetInteger64i_v) (GLenum target, GLuint index, GLint64* data);
void (GL_APIENTRY* qglGetBufferParameteri64v) (GLenum target, GLenum pname, GLint64* params);
void (GL_APIENTRY* qglGenSamplers) (GLsizei count, GLuint* samplers);
void (GL_APIENTRY* qglDeleteSamplers) (GLsizei count, const GLuint* samplers);
GLboolean (GL_APIENTRY* qglIsSampler) (GLuint sampler);
void (GL_APIENTRY* qglBindSampler) (GLuint unit, GLuint sampler);
void (GL_APIENTRY* qglSamplerParameteri) (GLuint sampler, GLenum pname, GLint param);
void (GL_APIENTRY* qglSamplerParameteriv) (GLuint sampler, GLenum pname, const GLint* param);
void (GL_APIENTRY* qglSamplerParameterf) (GLuint sampler, GLenum pname, GLfloat param);
void (GL_APIENTRY* qglSamplerParameterfv) (GLuint sampler, GLenum pname, const GLfloat* param);
void (GL_APIENTRY* qglGetSamplerParameteriv) (GLuint sampler, GLenum pname, GLint* params);
void (GL_APIENTRY* qglGetSamplerParameterfv) (GLuint sampler, GLenum pname, GLfloat* params);
void (GL_APIENTRY* qglVertexAttribDivisor) (GLuint index, GLuint divisor);
void (GL_APIENTRY* qglBindTransformFeedback) (GLenum target, GLuint id);
void (GL_APIENTRY* qglDeleteTransformFeedbacks) (GLsizei n, const GLuint* ids);
void (GL_APIENTRY* qglGenTransformFeedbacks) (GLsizei n, GLuint* ids);
GLboolean (GL_APIENTRY* qglIsTransformFeedback) (GLuint id);
void (GL_APIENTRY* qglPauseTransformFeedback) (void);
void (GL_APIENTRY* qglResumeTransformFeedback) (void);
void (GL_APIENTRY* qglGetProgramBinary) (GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
void (GL_APIENTRY* qglProgramBinary) (GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length);
void (GL_APIENTRY* qglProgramParameteri) (GLuint program, GLenum pname, GLint value);
void (GL_APIENTRY* qglInvalidateFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum* attachments);
void (GL_APIENTRY* qglInvalidateSubFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
void (GL_APIENTRY* qglTexStorage2D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void (GL_APIENTRY* qglTexStorage3D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void (GL_APIENTRY* qglGetInternalformativ) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params);

typedef struct
{
	GLenum	e;
	const char* name;
} glEnumName_t;

#define	QGL_DEF(x) { x, #x },
#define QGL(x) qgl##x = gl##x;
#define QGL_INIT(x) qgl##x = NULL;

glEnumName_t	glEnumNames[] =
{
	QGL_DEF( GL_FALSE )
	QGL_DEF( GL_TRUE )
	
	QGL_DEF( GL_BYTE )
	QGL_DEF( GL_UNSIGNED_BYTE )
	QGL_DEF( GL_SHORT )
	QGL_DEF( GL_UNSIGNED_SHORT )
	QGL_DEF( GL_INT )
	QGL_DEF( GL_UNSIGNED_INT )
	QGL_DEF( GL_FLOAT )
	
	QGL_DEF( GL_TEXTURE_CUBE_MAP )
	QGL_DEF( GL_TEXTURE_3D )
	QGL_DEF( GL_TEXTURE_2D )
	QGL_DEF( GL_BLEND )
	QGL_DEF( GL_DEPTH_TEST )
	QGL_DEF( GL_CULL_FACE )
	QGL_DEF( GL_STENCIL_TEST  )
	QGL_DEF( GL_POLYGON_OFFSET_FILL )
	
	QGL_DEF( GL_TRIANGLES  )
	QGL_DEF( GL_TRIANGLE_STRIP )
	QGL_DEF( GL_TRIANGLE_FAN )
	QGL_DEF( GL_POINTS )
	QGL_DEF( GL_LINES )
	QGL_DEF( GL_LINE_STRIP )
	QGL_DEF( GL_LINE_LOOP )
	
	QGL_DEF( GL_ALWAYS )
	QGL_DEF( GL_NEVER )
	QGL_DEF( GL_LEQUAL )
	QGL_DEF( GL_LESS )
	QGL_DEF( GL_EQUAL )
	QGL_DEF( GL_GREATER )
	QGL_DEF( GL_GEQUAL )
	QGL_DEF( GL_NOTEQUAL )
	
	QGL_DEF( GL_ONE )
	QGL_DEF( GL_ZERO )
	QGL_DEF( GL_SRC_ALPHA )
	QGL_DEF( GL_ONE_MINUS_SRC_ALPHA )
	QGL_DEF( GL_DST_COLOR )
	QGL_DEF( GL_ONE_MINUS_DST_COLOR )
	QGL_DEF( GL_DST_ALPHA )
	
	QGL_DEF( GL_TEXTURE )
	
	/* DrawBufferMode */
	QGL_DEF( GL_NONE )
	QGL_DEF( GL_FRONT )
	QGL_DEF( GL_BACK )
	QGL_DEF( GL_FRONT_AND_BACK )
	
	QGL_DEF( GL_LINE_WIDTH )
	QGL_DEF( GL_CULL_FACE )
	QGL_DEF( GL_CULL_FACE_MODE )
	QGL_DEF( GL_FRONT_FACE )
	QGL_DEF( GL_DEPTH_RANGE )
	QGL_DEF( GL_DEPTH_TEST )
	QGL_DEF( GL_DEPTH_WRITEMASK )
	QGL_DEF( GL_DEPTH_CLEAR_VALUE )
	QGL_DEF( GL_DEPTH_FUNC )
	QGL_DEF( GL_STENCIL_TEST )
	QGL_DEF( GL_STENCIL_CLEAR_VALUE )
	QGL_DEF( GL_STENCIL_FUNC )
	QGL_DEF( GL_STENCIL_VALUE_MASK )
	QGL_DEF( GL_STENCIL_FAIL )
	QGL_DEF( GL_STENCIL_PASS_DEPTH_FAIL )
	QGL_DEF( GL_STENCIL_PASS_DEPTH_PASS )
	QGL_DEF( GL_STENCIL_REF )
	QGL_DEF( GL_STENCIL_WRITEMASK )
	QGL_DEF( GL_VIEWPORT )
	QGL_DEF( GL_DITHER )
	QGL_DEF( GL_BLEND )
	QGL_DEF( GL_READ_BUFFER )
	QGL_DEF( GL_SCISSOR_BOX )
	QGL_DEF( GL_SCISSOR_TEST )
	QGL_DEF( GL_COLOR_CLEAR_VALUE )
	QGL_DEF( GL_COLOR_WRITEMASK )
	QGL_DEF( GL_UNPACK_ROW_LENGTH )
	QGL_DEF( GL_UNPACK_SKIP_ROWS )
	QGL_DEF( GL_UNPACK_SKIP_PIXELS )
	QGL_DEF( GL_UNPACK_ALIGNMENT )
	QGL_DEF( GL_PACK_ROW_LENGTH )
	QGL_DEF( GL_PACK_SKIP_ROWS )
	QGL_DEF( GL_PACK_SKIP_PIXELS )
	QGL_DEF( GL_PACK_ALIGNMENT )
	QGL_DEF( GL_MAX_VIEWPORT_DIMS )
	QGL_DEF( GL_SUBPIXEL_BITS )
	QGL_DEF( GL_RED_BITS )
	QGL_DEF( GL_GREEN_BITS )
	QGL_DEF( GL_BLUE_BITS )
	QGL_DEF( GL_ALPHA_BITS )
	QGL_DEF( GL_DEPTH_BITS )
	QGL_DEF( GL_STENCIL_BITS )
	QGL_DEF( GL_TEXTURE_2D )
	
	/* PixelCopyType */
	QGL_DEF( GL_COLOR )
	QGL_DEF( GL_DEPTH )
	QGL_DEF( GL_STENCIL )
	
	/* PixelFormat */
	QGL_DEF( GL_DEPTH_COMPONENT )
	QGL_DEF( GL_RED )
	QGL_DEF( GL_GREEN )
	QGL_DEF( GL_BLUE )
	QGL_DEF( GL_ALPHA )
	QGL_DEF( GL_RGB )
	QGL_DEF( GL_RGBA )
	QGL_DEF( GL_LUMINANCE )
	QGL_DEF( GL_LUMINANCE_ALPHA )

	/* StencilOp */
	/*      GL_ZERO */
	QGL_DEF( GL_KEEP )
	QGL_DEF( GL_REPLACE )
	QGL_DEF( GL_INCR )
	QGL_DEF( GL_DECR )
	/*      GL_INVERT */
	
	/* StringName */
	QGL_DEF( GL_VENDOR )
	QGL_DEF( GL_RENDERER )
	QGL_DEF( GL_VERSION )
	QGL_DEF( GL_EXTENSIONS )
	
	/* TextureMagFilter */
	QGL_DEF( GL_NEAREST )
	QGL_DEF( GL_LINEAR )
	
	/* TextureMinFilter */
	/*      GL_NEAREST */
	/*      GL_LINEAR */
	QGL_DEF( GL_NEAREST_MIPMAP_NEAREST )
	QGL_DEF( GL_LINEAR_MIPMAP_NEAREST )
	QGL_DEF( GL_NEAREST_MIPMAP_LINEAR )
	QGL_DEF( GL_LINEAR_MIPMAP_LINEAR )
	
	/* TextureParameterName */
	QGL_DEF( GL_TEXTURE_MAG_FILTER )
	QGL_DEF( GL_TEXTURE_MIN_FILTER )
	QGL_DEF( GL_TEXTURE_WRAP_S )
	QGL_DEF( GL_TEXTURE_WRAP_T )
	/*      GL_TEXTURE_BORDER_COLOR */
	/*      GL_TEXTURE_PRIORITY */
	
	/* TextureTarget */
	/*      GL_TEXTURE_1D */
	/*      GL_TEXTURE_2D */
	/*      GL_PROXY_TEXTURE_1D */
	/*      GL_PROXY_TEXTURE_2D */
	
	/* TextureWrapMode */
	QGL_DEF( GL_REPEAT )
	
	/* VertexPointerType */
	/*      GL_SHORT */
	/*      GL_INT */
	/*      GL_FLOAT */
	/*      GL_DOUBLE */
	
	/* ClientAttribMask */
	
	/* polygon_offset */
	QGL_DEF( GL_POLYGON_OFFSET_FACTOR )
	QGL_DEF( GL_POLYGON_OFFSET_UNITS )
	QGL_DEF( GL_POLYGON_OFFSET_FILL )
	
	{
		0, NULL
	}
};

/*
** QGL_Shutdown
**
** Unloads the specified DLL then nulls out all the proc pointers.  This
** is only called during a hard shutdown of the OGL subsystem (e.g. vid_restart).
*/
void QGL_Shutdown( void )
{
	common->Printf( "...shutting down QGL\n" );
	
	QGL( ActiveTexture )
	QGL( AttachShader )
	QGL( BindAttribLocation )
	QGL( BindBuffer )
	QGL( BindFramebuffer )
	QGL( BindRenderbuffer )
	QGL( BindTexture )
	QGL( BlendColor )
	QGL( BlendEquation )
	QGL( BlendEquationSeparate )
	QGL( BlendFunc )
	QGL( BlendFuncSeparate )
	QGL( BufferData )
	QGL( BufferSubData )
	QGL( CheckFramebufferStatus )
	QGL( Clear )
	QGL( ClearColor )
	QGL( ClearDepthf )
	QGL( ClearStencil )
	QGL( ColorMask )
	QGL( CompileShader )
	QGL( CompressedTexImage2D )
	QGL( CompressedTexSubImage2D )
	QGL( CopyTexImage2D )
	QGL( CopyTexSubImage2D )
	QGL( CreateProgram )
	QGL( CreateShader )
	QGL( CullFace )
	QGL( DeleteBuffers )
	QGL( DeleteFramebuffers )
	QGL( DeleteProgram )
	QGL( DeleteRenderbuffers )
	QGL( DeleteShader )
	QGL( DeleteTextures )
	QGL( DepthFunc )
	QGL( DepthMask )
	QGL( DepthRangef )
	QGL( DetachShader )
	QGL( Disable )
	QGL( DisableVertexAttribArray )
	QGL( DrawArrays )
	QGL( DrawElements )
	QGL( Enable )
	QGL( EnableVertexAttribArray )
	QGL( Finish )
	QGL( Flush )
	QGL( FramebufferRenderbuffer )
	QGL( FramebufferTexture2D )
	QGL( FrontFace )
	QGL( GenBuffers )
	QGL( GenerateMipmap )
	QGL( GenFramebuffers )
	QGL( GenRenderbuffers )
	QGL( GenTextures )
	QGL( GetActiveAttrib )
	QGL( GetActiveUniform )
	QGL( GetAttachedShaders )
	QGL( GetAttribLocation )
	QGL( GetBooleanv )
	QGL( GetBufferParameteriv )
	QGL( GetError )
	QGL( GetFloatv )
	QGL( GetFramebufferAttachmentParameteriv )
	QGL( GetIntegerv )
	QGL( GetProgramiv )
	QGL( GetProgramInfoLog )
	QGL( GetRenderbufferParameteriv )
	QGL( GetShaderiv )
	QGL( GetShaderInfoLog )
	QGL( GetShaderPrecisionFormat )
	QGL( GetShaderSource )
	QGL( GetString )
	QGL( GetTexParameterfv )
	QGL( GetTexParameteriv )
	QGL( GetUniformfv )
	QGL( GetUniformiv )
	QGL( GetUniformLocation )
	QGL( GetVertexAttribfv )
	QGL( GetVertexAttribiv )
	QGL( GetVertexAttribPointerv )
	QGL( Hint )
	QGL( IsBuffer )
	QGL( IsEnabled )
	QGL( IsFramebuffer )
	QGL( IsProgram )
	QGL( IsRenderbuffer )
	QGL( IsShader )
	QGL( IsTexture )
	QGL( LineWidth )
	QGL( LinkProgram )
	QGL( PixelStorei )
	QGL( PolygonOffset )
	QGL( ReadPixels )
	QGL( ReleaseShaderCompiler )
	QGL( RenderbufferStorage )
	QGL( SampleCoverage )
	QGL( Scissor )
	QGL( ShaderBinary )
	QGL( ShaderSource )
	QGL( StencilFunc )
	QGL( StencilFuncSeparate )
	QGL( StencilMask )
	QGL( StencilMaskSeparate )
	QGL( StencilOp )
	QGL( StencilOpSeparate )
	QGL( TexImage2D )
	QGL( TexParameterf )
	QGL( TexParameterfv )
	QGL( TexParameteri )
	QGL( TexParameteriv )
	QGL( TexSubImage2D )
	QGL( Uniform1f )
	QGL( Uniform1fv )
	QGL( Uniform1i )
	QGL( Uniform1iv )
	QGL( Uniform2f )
	QGL( Uniform2fv )
	QGL( Uniform2i )
	QGL( Uniform2iv )
	QGL( Uniform3f )
	QGL( Uniform3fv )
	QGL( Uniform3i )
	QGL( Uniform3iv )
	QGL( Uniform4f )
	QGL( Uniform4fv )
	QGL( Uniform4i )
	QGL( Uniform4iv )
	QGL( UniformMatrix2fv )
	QGL( UniformMatrix3fv )
	QGL( UniformMatrix4fv )
	QGL( UseProgram )
	QGL( ValidateProgram )
	QGL( VertexAttrib1f )
	QGL( VertexAttrib1fv )
	QGL( VertexAttrib2f )
	QGL( VertexAttrib2fv )
	QGL( VertexAttrib3f )
	QGL( VertexAttrib3fv )
	QGL( VertexAttrib4f )
	QGL( VertexAttrib4fv )
	QGL( VertexAttribPointer )
	QGL( Viewport )
	QGL( ReadBuffer )
	QGL( DrawRangeElements )
	QGL( TexImage3D )
	QGL( TexSubImage3D )
	QGL( CopyTexSubImage3D )
	QGL( CompressedTexImage3D )
	QGL( CompressedTexSubImage3D )
	QGL( GenQueries )
	QGL( DeleteQueries )
	QGL( IsQuery )
	QGL( BeginQuery )
	QGL( EndQuery )
	QGL( GetQueryiv )
	QGL( GetQueryObjectuiv )
	QGL( UnmapBuffer )
	QGL( GetBufferPointerv )
	QGL( DrawBuffers )
	QGL( UniformMatrix2x3fv )
	QGL( UniformMatrix3x2fv )
	QGL( UniformMatrix2x4fv )
	QGL( UniformMatrix4x2fv )
	QGL( UniformMatrix3x4fv )
	QGL( UniformMatrix4x3fv )
	QGL( BlitFramebuffer )
	QGL( RenderbufferStorageMultisample )
	QGL( FramebufferTextureLayer )
	QGL( MapBufferRange )
	QGL( FlushMappedBufferRange )
	QGL( BindVertexArray )
	QGL( DeleteVertexArrays )
	QGL( GenVertexArrays )
	QGL( IsVertexArray )
	QGL( GetIntegeri_v )
	QGL( BeginTransformFeedback )
	QGL( EndTransformFeedback )
	QGL( BindBufferRange )
	QGL( BindBufferBase )
	QGL( TransformFeedbackVaryings )
	QGL( GetTransformFeedbackVarying )
	QGL( VertexAttribIPointer )
	QGL( GetVertexAttribIiv )
	QGL( GetVertexAttribIuiv )
	QGL( VertexAttribI4i )
	QGL( VertexAttribI4ui )
	QGL( VertexAttribI4iv )
	QGL( VertexAttribI4uiv )
	QGL( GetUniformuiv )
	QGL( GetFragDataLocation )
	QGL( Uniform1ui )
	QGL( Uniform2ui )
	QGL( Uniform3ui )
	QGL( Uniform4ui )
	QGL( Uniform1uiv )
	QGL( Uniform2uiv )
	QGL( Uniform3uiv )
	QGL( Uniform4uiv )
	QGL( ClearBufferiv )
	QGL( ClearBufferuiv )
	QGL( ClearBufferfv )
	QGL( ClearBufferfi )
	QGL( GetStringi )
	QGL( CopyBufferSubData )
	QGL( GetUniformIndices )
	QGL( GetActiveUniformsiv )
	QGL( GetUniformBlockIndex )
	QGL( GetActiveUniformBlockiv )
	QGL( GetActiveUniformBlockName )
	QGL( UniformBlockBinding )
	QGL( DrawArraysInstanced )
	QGL( DrawElementsInstanced )
	QGL( FenceSync )
	QGL( IsSync )
	QGL( DeleteSync )
	QGL( ClientWaitSync )
	QGL( WaitSync )
	QGL( GetInteger64v )
	QGL( GetSynciv )
	QGL( GetInteger64i_v )
	QGL( GetBufferParameteri64v )
	QGL( GenSamplers )
	QGL( DeleteSamplers )
	QGL( IsSampler )
	QGL( BindSampler )
	QGL( SamplerParameteri )
	QGL( SamplerParameteriv )
	QGL( SamplerParameterf )
	QGL( SamplerParameterfv )
	QGL( GetSamplerParameteriv )
	QGL( GetSamplerParameterfv )
	QGL( VertexAttribDivisor )
	QGL( BindTransformFeedback )
	QGL( DeleteTransformFeedbacks )
	QGL( GenTransformFeedbacks )
	QGL( IsTransformFeedback )
	QGL( PauseTransformFeedback )
	QGL( ResumeTransformFeedback )
	QGL( GetProgramBinary )
	QGL( ProgramBinary )
	QGL( ProgramParameteri )
	QGL( InvalidateFramebuffer )
	QGL( InvalidateSubFramebuffer )
	QGL( TexStorage2D )
	QGL( TexStorage3D )
	// missing from Mesa Intel ES3 driver perhaps?
	// doesn't link
	//QGL( GetInternalformativ )
}

/*
** QGL_Init
**
** This is responsible for binding our qgl function pointers to
** the appropriate GL stuff.  In Windows this means doing a
** LoadLibrary and a bunch of calls to GetProcAddress.  On other
** operating systems we need to do the right thing, whatever that
** might be.
*/
bool QGL_Init( const char* dllname )
{
	QGL( ActiveTexture )
	QGL( AttachShader )
	QGL( BindAttribLocation )
	QGL( BindBuffer )
	QGL( BindFramebuffer )
	QGL( BindRenderbuffer )
	QGL( BindTexture )
	QGL( BlendColor )
	QGL( BlendEquation )
	QGL( BlendEquationSeparate )
	QGL( BlendFunc )
	QGL( BlendFuncSeparate )
	QGL( BufferData )
	QGL( BufferSubData )
	QGL( CheckFramebufferStatus )
	QGL( Clear )
	QGL( ClearColor )
	QGL( ClearDepthf )
	QGL( ClearStencil )
	QGL( ColorMask )
	QGL( CompileShader )
	QGL( CompressedTexImage2D )
	QGL( CompressedTexSubImage2D )
	QGL( CopyTexImage2D )
	QGL( CopyTexSubImage2D )
	QGL( CreateProgram )
	QGL( CreateShader )
	QGL( CullFace )
	QGL( DeleteBuffers )
	QGL( DeleteFramebuffers )
	QGL( DeleteProgram )
	QGL( DeleteRenderbuffers )
	QGL( DeleteShader )
	QGL( DeleteTextures )
	QGL( DepthFunc )
	QGL( DepthMask )
	QGL( DepthRangef )
	QGL( DetachShader )
	QGL( Disable )
	QGL( DisableVertexAttribArray )
	QGL( DrawArrays )
	QGL( DrawElements )
	QGL( Enable )
	QGL( EnableVertexAttribArray )
	QGL( Finish )
	QGL( Flush )
	QGL( FramebufferRenderbuffer )
	QGL( FramebufferTexture2D )
	QGL( FrontFace )
	QGL( GenBuffers )
	QGL( GenerateMipmap )
	QGL( GenFramebuffers )
	QGL( GenRenderbuffers )
	QGL( GenTextures )
	QGL( GetActiveAttrib )
	QGL( GetActiveUniform )
	QGL( GetAttachedShaders )
	QGL( GetAttribLocation )
	QGL( GetBooleanv )
	QGL( GetBufferParameteriv )
	QGL( GetError )
	QGL( GetFloatv )
	QGL( GetFramebufferAttachmentParameteriv )
	QGL( GetIntegerv )
	QGL( GetProgramiv )
	QGL( GetProgramInfoLog )
	QGL( GetRenderbufferParameteriv )
	QGL( GetShaderiv )
	QGL( GetShaderInfoLog )
	QGL( GetShaderPrecisionFormat )
	QGL( GetShaderSource )
	QGL( GetString )
	QGL( GetTexParameterfv )
	QGL( GetTexParameteriv )
	QGL( GetUniformfv )
	QGL( GetUniformiv )
	QGL( GetUniformLocation )
	QGL( GetVertexAttribfv )
	QGL( GetVertexAttribiv )
	QGL( GetVertexAttribPointerv )
	QGL( Hint )
	QGL( IsBuffer )
	QGL( IsEnabled )
	QGL( IsFramebuffer )
	QGL( IsProgram )
	QGL( IsRenderbuffer )
	QGL( IsShader )
	QGL( IsTexture )
	QGL( LineWidth )
	QGL( LinkProgram )
	QGL( PixelStorei )
	QGL( PolygonOffset )
	QGL( ReadPixels )
	QGL( ReleaseShaderCompiler )
	QGL( RenderbufferStorage )
	QGL( SampleCoverage )
	QGL( Scissor )
	QGL( ShaderBinary )
	QGL( ShaderSource )
	QGL( StencilFunc )
	QGL( StencilFuncSeparate )
	QGL( StencilMask )
	QGL( StencilMaskSeparate )
	QGL( StencilOp )
	QGL( StencilOpSeparate )
	QGL( TexImage2D )
	QGL( TexParameterf )
	QGL( TexParameterfv )
	QGL( TexParameteri )
	QGL( TexParameteriv )
	QGL( TexSubImage2D )
	QGL( Uniform1f )
	QGL( Uniform1fv )
	QGL( Uniform1i )
	QGL( Uniform1iv )
	QGL( Uniform2f )
	QGL( Uniform2fv )
	QGL( Uniform2i )
	QGL( Uniform2iv )
	QGL( Uniform3f )
	QGL( Uniform3fv )
	QGL( Uniform3i )
	QGL( Uniform3iv )
	QGL( Uniform4f )
	QGL( Uniform4fv )
	QGL( Uniform4i )
	QGL( Uniform4iv )
	QGL( UniformMatrix2fv )
	QGL( UniformMatrix3fv )
	QGL( UniformMatrix4fv )
	QGL( UseProgram )
	QGL( ValidateProgram )
	QGL( VertexAttrib1f )
	QGL( VertexAttrib1fv )
	QGL( VertexAttrib2f )
	QGL( VertexAttrib2fv )
	QGL( VertexAttrib3f )
	QGL( VertexAttrib3fv )
	QGL( VertexAttrib4f )
	QGL( VertexAttrib4fv )
	QGL( VertexAttribPointer )
	QGL( Viewport )
	QGL( ReadBuffer )
	QGL( DrawRangeElements )
	QGL( TexImage3D )
	QGL( TexSubImage3D )
	QGL( CopyTexSubImage3D )
	QGL( CompressedTexImage3D )
	QGL( CompressedTexSubImage3D )
	QGL( GenQueries )
	QGL( DeleteQueries )
	QGL( IsQuery )
	QGL( BeginQuery )
	QGL( EndQuery )
	QGL( GetQueryiv )
	QGL( GetQueryObjectuiv )
	QGL( UnmapBuffer )
	QGL( GetBufferPointerv )
	QGL( DrawBuffers )
	QGL( UniformMatrix2x3fv )
	QGL( UniformMatrix3x2fv )
	QGL( UniformMatrix2x4fv )
	QGL( UniformMatrix4x2fv )
	QGL( UniformMatrix3x4fv )
	QGL( UniformMatrix4x3fv )
	QGL( BlitFramebuffer )
	QGL( RenderbufferStorageMultisample )
	QGL( FramebufferTextureLayer )
	QGL( MapBufferRange )
	QGL( FlushMappedBufferRange )
	QGL( BindVertexArray )
	QGL( DeleteVertexArrays )
	QGL( GenVertexArrays )
	QGL( IsVertexArray )
	QGL( GetIntegeri_v )
	QGL( BeginTransformFeedback )
	QGL( EndTransformFeedback )
	QGL( BindBufferRange )
	QGL( BindBufferBase )
	QGL( TransformFeedbackVaryings )
	QGL( GetTransformFeedbackVarying )
	QGL( VertexAttribIPointer )
	QGL( GetVertexAttribIiv )
	QGL( GetVertexAttribIuiv )
	QGL( VertexAttribI4i )
	QGL( VertexAttribI4ui )
	QGL( VertexAttribI4iv )
	QGL( VertexAttribI4uiv )
	QGL( GetUniformuiv )
	QGL( GetFragDataLocation )
	QGL( Uniform1ui )
	QGL( Uniform2ui )
	QGL( Uniform3ui )
	QGL( Uniform4ui )
	QGL( Uniform1uiv )
	QGL( Uniform2uiv )
	QGL( Uniform3uiv )
	QGL( Uniform4uiv )
	QGL( ClearBufferiv )
	QGL( ClearBufferuiv )
	QGL( ClearBufferfv )
	QGL( ClearBufferfi )
	QGL( GetStringi )
	QGL( CopyBufferSubData )
	QGL( GetUniformIndices )
	QGL( GetActiveUniformsiv )
	QGL( GetUniformBlockIndex )
	QGL( GetActiveUniformBlockiv )
	QGL( GetActiveUniformBlockName )
	QGL( UniformBlockBinding )
	QGL( DrawArraysInstanced )
	QGL( DrawElementsInstanced )
	QGL( FenceSync )
	QGL( IsSync )
	QGL( DeleteSync )
	QGL( ClientWaitSync )
	QGL( WaitSync )
	QGL( GetInteger64v )
	QGL( GetSynciv )
	QGL( GetInteger64i_v )
	QGL( GetBufferParameteri64v )
	QGL( GenSamplers )
	QGL( DeleteSamplers )
	QGL( IsSampler )
	QGL( BindSampler )
	QGL( SamplerParameteri )
	QGL( SamplerParameteriv )
	QGL( SamplerParameterf )
	QGL( SamplerParameterfv )
	QGL( GetSamplerParameteriv )
	QGL( GetSamplerParameterfv )
	QGL( VertexAttribDivisor )
	QGL( BindTransformFeedback )
	QGL( DeleteTransformFeedbacks )
	QGL( GenTransformFeedbacks )
	QGL( IsTransformFeedback )
	QGL( PauseTransformFeedback )
	QGL( ResumeTransformFeedback )
	QGL( GetProgramBinary )
	QGL( ProgramBinary )
	QGL( ProgramParameteri )
	QGL( InvalidateFramebuffer )
	QGL( InvalidateSubFramebuffer )
	QGL( TexStorage2D )
	QGL( TexStorage3D )
	// missing from Mesa Intel ES3 driver perhaps?
	// doesn't link
	//QGL( GetInternalformativ )

	return true;
}
#undef QGL_DEF
#undef QGL_INIT
#undef QGL

/*
==================
GLimp_EnableLogging
==================
*/
void GLimp_EnableLogging( bool enable )
{

}
