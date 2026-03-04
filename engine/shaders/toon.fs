#version 330

in vec3 fragNormal;
in vec3 fragPosition;

out vec4 finalColor;

uniform vec3 lightDir;
uniform vec4 colDiffuse;

void main()
{
    vec3 normal = normalize(fragNormal);
    float intensity = dot(normal, normalize(-lightDir));

    float levels = 4.0;
    float toon = floor(intensity * levels) / levels;

    vec3 color = colDiffuse.rgb * toon;

    finalColor = vec4(color, colDiffuse.a);
}