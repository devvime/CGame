#version 330

in vec3 fragNormal;

uniform vec3 lightDir;
uniform vec4 colDiffuse;

out vec4 finalColor;

void main()
{
    float diff = max(dot(normalize(fragNormal), -normalize(lightDir)), 0.2);

    finalColor = vec4(colDiffuse.rgb * diff, colDiffuse.a);
}