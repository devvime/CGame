#include "shadowmap.h"

static RenderTexture2D shadowMap;

RenderTexture2D LoadShadowmapRenderTexture(int width, int height)
{
    RenderTexture2D target = { 0 };
    target.id = rlLoadFramebuffer();
    target.texture.width = width;
    target.texture.height = height;
    if (target.id > 0)
    {
        rlEnableFramebuffer(target.id);
        target.depth.id = rlLoadTextureDepth(width, height, false);
        target.depth.width = width;
        target.depth.height = height;
        target.depth.format = 19;
        target.depth.mipmaps = 1;
        rlFramebufferAttach(target.id, target.depth.id, RL_ATTACHMENT_DEPTH, RL_ATTACHMENT_TEXTURE2D, 0);
        if (rlFramebufferComplete(target.id)) TRACELOG(LOG_INFO, "FBO: [ID %i] Framebuffer object created successfully", target.id);
        rlDisableFramebuffer();
    }
    else TRACELOG(LOG_WARNING, "FBO: Framebuffer object can not be created");
    return target;
}

void UnloadShadowmapRenderTexture(RenderTexture2D target)
{
    if (target.id > 0)
    {
        rlUnloadFramebuffer(target.id);
    }
}

RenderTexture2D SetShadowMap() {
    shadowMap = LoadShadowmapRenderTexture(SHADOWMAP_RESOLUTION, SHADOWMAP_RESOLUTION);
    return shadowMap;
}

RenderTexture2D GetShadowMap() {
    return shadowMap;
}