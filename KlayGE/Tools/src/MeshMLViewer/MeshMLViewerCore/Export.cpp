#include <KlayGE/KlayGE.hpp>
#include "MeshMLViewerCore.hpp"

#ifdef KLAYGE_COMPILER_MSVC
#define APIENTRY __stdcall
#else
#define APIENTRY
#endif

using namespace KlayGE;

extern "C"
{
	__declspec(dllexport) void* APIENTRY Create(void* native_wnd)
	{
		Context::Instance().LoadCfg("KlayGE.cfg");

		ContextCfg cfg = Context::Instance().Config();
		cfg.deferred_rendering = true;
		Context::Instance().Config(cfg);

		MeshMLViewerCore* core = new MeshMLViewerCore(native_wnd);
		core->Create();
		return core;
	}

	__declspec(dllexport) void APIENTRY Destroy(MeshMLViewerCore* core)
	{
		core->Destroy();
		delete core;
	}

	__declspec(dllexport) void APIENTRY Refresh(MeshMLViewerCore* core)
	{
		core->Refresh();
	}

	__declspec(dllexport) void APIENTRY Resize(MeshMLViewerCore* core, uint32_t width, uint32_t height)
	{
		core->Resize(width, height);
	}

	__declspec(dllexport) void APIENTRY OpenModel(MeshMLViewerCore* core, char const * name)
	{
		core->OpenModel(name);
	}

	__declspec(dllexport) void APIENTRY SaveModel(MeshMLViewerCore* core, char const * name)
	{
		core->SaveAsModel(name);
	}

	__declspec(dllexport) unsigned int APIENTRY NumFrames(MeshMLViewerCore* core)
	{
		return core->NumFrames();
	}

	__declspec(dllexport) void APIENTRY CurrFrame(MeshMLViewerCore* core, float frame)
	{
		core->CurrFrame(frame);
	}

	__declspec(dllexport) float APIENTRY ModelFrameRate(MeshMLViewerCore* core)
	{
		return core->ModelFrameRate();
	}

	__declspec(dllexport) void APIENTRY SkinningOn(MeshMLViewerCore* core, int on)
	{
		core->SkinningOn(on ? true : false);
	}

	__declspec(dllexport) void APIENTRY SmoothMeshOn(MeshMLViewerCore* core, int on)
	{
		core->SmoothMeshOn(on ? true : false);
	}

	__declspec(dllexport) void APIENTRY FPSCameraOn(MeshMLViewerCore* core, int on)
	{
		core->FPSCameraOn(on ? true : false);
	}

	__declspec(dllexport) void APIENTRY LineModeOn(MeshMLViewerCore* core, int on)
	{
		core->LineModeOn(on ? true : false);
	}

	__declspec(dllexport) void APIENTRY Visualize(MeshMLViewerCore* core, int index)
	{
		core->Visualize(index);
	}

	__declspec(dllexport) void APIENTRY MouseMove(MeshMLViewerCore* core, int x, int y, uint32_t button)
	{
		core->MouseMove(x, y, button);
	}

	__declspec(dllexport) void APIENTRY MouseUp(MeshMLViewerCore* core, int x, int y, uint32_t button)
	{
		core->MouseUp(x, y, button);
	}

	__declspec(dllexport) void APIENTRY MouseDown(MeshMLViewerCore* core, int x, int y, uint32_t button)
	{
		core->MouseDown(x, y, button);
	}

	__declspec(dllexport) void APIENTRY KeyPress(MeshMLViewerCore* core, int key)
	{
		core->KeyPress(key);
	}

	__declspec(dllexport) uint32_t APIENTRY NumMeshes(MeshMLViewerCore* core)
	{
		return core->NumMeshes();
	}

	__declspec(dllexport) wchar_t const * APIENTRY MeshName(MeshMLViewerCore* core, uint32_t index)
	{
		return core->MeshName(index).c_str();
	}

	__declspec(dllexport) uint32_t APIENTRY NumVertexStreams(MeshMLViewerCore* core, uint32_t mesh_id)
	{
		return core->NumVertexStreams(mesh_id);
	}

	__declspec(dllexport) uint32_t APIENTRY NumVertexStreamUsages(MeshMLViewerCore* core, uint32_t mesh_id, uint32_t stream_index)
	{
		return core->NumVertexStreamUsages(mesh_id, stream_index);
	}

	__declspec(dllexport) uint32_t APIENTRY VertexStreamUsage(MeshMLViewerCore* core, uint32_t mesh_id, uint32_t stream_index, uint32_t usage_index)
	{
		return core->VertexStreamUsage(mesh_id, stream_index, usage_index);
	}

	__declspec(dllexport) uint32_t APIENTRY MaterialID(MeshMLViewerCore* core, uint32_t mesh_id)
	{
		return core->MaterialID(mesh_id);
	}

	__declspec(dllexport) float const * APIENTRY AmbientMaterial(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return &core->AmbientMaterial(mtl_id).x();
	}

	__declspec(dllexport) float const * APIENTRY DiffuseMaterial(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return &core->DiffuseMaterial(mtl_id).x();
	}

	__declspec(dllexport) float const * APIENTRY SpecularMaterial(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return &core->SpecularMaterial(mtl_id).x();
	}

	__declspec(dllexport) float APIENTRY ShininessMaterial(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return core->ShininessMaterial(mtl_id);
	}

	__declspec(dllexport) float const * APIENTRY EmitMaterial(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return &core->EmitMaterial(mtl_id).x();
	}

	__declspec(dllexport) float APIENTRY OpacityMaterial(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return core->OpacityMaterial(mtl_id);
	}

	__declspec(dllexport) char const * APIENTRY DiffuseTexture(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return core->DiffuseTexture(mtl_id).c_str();
	}

	__declspec(dllexport) char const * APIENTRY SpecularTexture(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return core->SpecularTexture(mtl_id).c_str();
	}

	__declspec(dllexport) char const * APIENTRY ShininessTexture(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return core->ShininessTexture(mtl_id).c_str();
	}

	__declspec(dllexport) char const * APIENTRY NormalTexture(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return core->NormalTexture(mtl_id).c_str();
	}

	__declspec(dllexport) char const * APIENTRY HeightTexture(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return core->HeightTexture(mtl_id).c_str();
	}

	__declspec(dllexport) char const * APIENTRY EmitTexture(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return core->EmitTexture(mtl_id).c_str();
	}

	__declspec(dllexport) char const * APIENTRY OpacityTexture(MeshMLViewerCore* core, uint32_t mtl_id)
	{
		return core->OpacityTexture(mtl_id).c_str();
	}

	__declspec(dllexport) uint32_t APIENTRY SelectedMesh(MeshMLViewerCore* core)
	{
		return core->SelectedMesh();
	}

	__declspec(dllexport) void APIENTRY SelectMesh(MeshMLViewerCore* core, uint32_t mesh_id)
	{
		return core->SelectMesh(mesh_id);
	}
}
