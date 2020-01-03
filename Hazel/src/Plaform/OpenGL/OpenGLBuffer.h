#pragma once

#include "Hazel/Renderer/Buffer.h"

namespace Hazel {
	class OpenGLVertexBuffer : public VertexBuffer {

	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual void Bind() const override;
		virtual void UnBind() const override;
		virtual const BufferLayout& GetLayout() const override { return m_Layout; };
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }
		virtual ~OpenGLVertexBuffer();

	};

	class OpenGLIndexBuffer : public IndexBuffer {

	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual void Bind() const override;
		virtual void UnBind() const override;
		virtual ~OpenGLIndexBuffer() override;
		virtual uint32_t GetCount() const override {
			return m_Count;
		};


	};
}
