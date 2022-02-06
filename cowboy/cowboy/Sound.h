#pragma once

class Sound
{
  private:
    Sound(){};
    static Sound Instance;

  public:
    Sound(const Sound &) = delete;

    static void PlayMusic();
    static void PlayPlayerShoot();
    static void PlayPlayerDeath();
    static void PlayEnemyDeath();
};
