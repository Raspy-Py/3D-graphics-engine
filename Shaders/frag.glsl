#version 330 core

struct Material
{
  sampler2D diffuse;
  sampler2D specular;
  sampler2D emission;
  float shininess;
};

struct Light
{
  float constant;
  float linear;
  float quadratic;
  vec3 position;
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};

struct FlashLight
{
  vec3 position;
  vec3 direction;
  float cutoff;
};

out vec4 FragColor;

in vec3 fNormal;
in vec2 fTexCoords;
in vec3 FragPos;

uniform Material material;
uniform Light light[3];
uniform FlashLight flashlight;
uniform vec3 cameraPos;
uniform bool isFloor;

float lenth(vec3 a)
{
  return sqrt( a.x * a.x + a.y * a.y + a.z * a.z);
}

void main()
{
  vec3 g_result = vec3(0.0f, 0.0f, 0.0f);
  for(int i = 0; i < 3; i++)
  {
    float d = lenth(light[i].position - FragPos);
    float F = 1.0f / (light[i].constant + d * (light[i].linear + d * light[i].quadratic));
    if (F < 1e-3) F = 0.0f;
    // ambient
    vec3 ambient = light[i].ambient * texture(material.diffuse, fTexCoords).rgb;

    // diffuse
    vec3 norm = normalize(fNormal);
    vec3 lightDir = normalize(light[i].position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light[i].diffuse * diff * texture(material.diffuse, fTexCoords).rgb;

    // specular
    vec3 viewDir = normalize(cameraPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light[i].specular * spec * texture(material.specular, fTexCoords).rgb;

    vec3 result = ambient + diffuse;

    if (!isFloor) result += specular;// + texture(material.emission, fTexCoords).rgb;

    result *= F;
    g_result += result;
}
    float theta = dot(normalize(cameraPos - FragPos), normalize(-flashlight.direction));

    if(theta > flashlight.cutoff)
    {
      g_result = g_result * 1.1f;
    }
    float gamma = 2.2;
    FragColor = vec4(pow(g_result.rgb, vec3(1.0/gamma)), 1.0f);
    //FragColor = vec4(result, 1.0f);

}
