#include "imgui_layer.hpp"

#include <unified/application/application.hpp>

#include <glfw/glfw3.h>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_MODULES_BEGIN_NAMESPACE

void ImGuiLayer::Create(Application *application) {
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(application->get_native_window()), true);
	ImGui_ImplOpenGL3_Init("#version 330 core");
}

void ImGuiLayer::Destroy() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiLayer::OnPreUpdate() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void ImGuiLayer::OnPostUpdate() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

UNIFIED_END_NAMESPACE
UNIFIED_MODULES_END_NAMESPACE