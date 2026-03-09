#include "shader.h"
#include "shadowmap.h"

static Shader shadowShader;
static Camera3D lightCamera = {0};
int lightVPLoc;
int shadowMapLoc;

Shader SetShader() {
    shadowShader = LoadShader("resources/shaders/shadowmap.vs", "resources/shaders/shadowmap.fs");
    shadowShader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shadowShader, "viewPos");

    Vector3 lightDir = Vector3Normalize((Vector3){ 1, -5, -1 });
    Color lightColor = WHITE;
    Vector4 lightColorNormalized = ColorNormalize(lightColor);
    int lightDirLoc = GetShaderLocation(shadowShader, "lightDir");
    int lightColLoc = GetShaderLocation(shadowShader, "lightColor");
    SetShaderValue(shadowShader, lightDirLoc, &lightDir, SHADER_UNIFORM_VEC3);
    SetShaderValue(shadowShader, lightColLoc, &lightColorNormalized, SHADER_UNIFORM_VEC4);
    int ambientLoc = GetShaderLocation(shadowShader, "ambient");
    float ambient[4] = {0.1f, 0.1f, 0.1f, 1.0f};
    SetShaderValue(shadowShader, ambientLoc, ambient, SHADER_UNIFORM_VEC4);
    lightVPLoc = GetShaderLocation(shadowShader, "lightVP");
    shadowMapLoc = GetShaderLocation(shadowShader, "shadowMap");
    int shadowMapResolution = SHADOWMAP_RESOLUTION;
    SetShaderValue(shadowShader, GetShaderLocation(shadowShader, "shadowMapResolution"), &shadowMapResolution, SHADER_UNIFORM_INT);

    lightCamera.position = Vector3Scale(lightDir, -15);
    lightCamera.target = Vector3Zero();
    lightCamera.projection = CAMERA_ORTHOGRAPHIC;
    lightCamera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    lightCamera.fovy = 50;
    
    return shadowShader;
}

Camera3D GetLightCamera() {
    return lightCamera;
}

int GetLightVPLoc() {
    return lightVPLoc;
}

int GetShadowMapLoc() {
    return shadowMapLoc;
}

Shader GetShader() {
    return shadowShader;
}