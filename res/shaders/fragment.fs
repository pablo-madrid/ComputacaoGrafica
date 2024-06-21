#version 330 core

out vec4 FragColor;
in vec3 newColor;

uniform vec3 lightColor = vec3(1.0,1.0,1.0); //luz branca
uniform float ambientIntensity = .3; //coeficiente da luz

/*Pegando a intensidade da luz branca
Misturando a cor do objeto com a luz ambiente*/

void main()
{
  vec3 ambient = ambientIntensity * lightColor;

  FragColor = vec4(ambient * newColor, 1.0);
}