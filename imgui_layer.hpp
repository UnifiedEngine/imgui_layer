#ifndef _UNIFIED_MODULES_IMGUI_LAYER_IMGUI_LAYER_HPP
#define _UNIFIED_MODULES_IMGUI_LAYER_IMGUI_LAYER_HPP

# include <unified/application/layer.hpp>

# include <imgui.h>
# include <backends/imgui_impl_glfw.h>
# include <backends/imgui_impl_opengl3.h>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_MODULES_BEGIN_NAMESPACE

class ImGuiLayer : public Layer
{
public:

    static void Create(Application *application);
    static void Destroy();

    virtual void OnPreUpdate() override;
    virtual void OnPostUpdate() override;

};

UNIFIED_MODULES_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif