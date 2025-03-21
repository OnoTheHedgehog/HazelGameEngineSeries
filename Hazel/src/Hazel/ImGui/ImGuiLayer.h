#pragma once

#include "Hazel/Core/Layer.h"
#include <Hazel/Events/KeyEvent.h>
#include <Hazel/Events/MouseEvent.h>
#include <Hazel/Events/ApplicationEvent.h>

namespace Hazel {
	
	class ImGuiLayer : public Layer
	{
	private:
		float m_Time = 0.0f;
	public:
		ImGuiLayer();
		~ImGuiLayer();
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		//virtual void OnImGuiRender() override;


		void Begin();
		void End();
	};


}

