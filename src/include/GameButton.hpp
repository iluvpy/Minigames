#pragma once

#include "GUIImage.hpp"
#include "GUIButton.hpp"
#include "GUIRect.hpp"
#include "Renderer.hpp"
#include "InputHandler.hpp"
#include "Utils.hpp"

class GameButton {
public:

	void Init(Renderer *renderer, int x, int y, const std::string& img_path, int outlineWidth, const Color& backgroundColor, const Color& outlineColor);
	void Update(InputHandler *input);
	void Draw();
	const GUIButton& GetButton();
private:
	Renderer *m_renderer;
	GUIButton m_button;
	GUIImage m_image;
	GUIRect m_outlineRect;
	Color m_outlineColor;
	Color m_backgroundColor;
};