#include "hzpch.h"

#include "RenderCommand.h"

#include "Plaform/OpenGL/OpenGLRendererAPI.h"

namespace Hazel {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}