// Usando na GameplayScene

static Level level;

static void Init(void)
{
    level = LoadLevel("level.json");
}

static void Draw(void)
{
    BeginMode3D(camera);

    DrawLevel(&level);

    EndMode3D();
}

static void Unload(void)
{
    UnloadLevel(&level);
}