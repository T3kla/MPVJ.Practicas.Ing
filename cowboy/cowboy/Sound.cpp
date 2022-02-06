#include "Sound.h"

#include <Windows.h>

#include "Game.h"
#include "bass.h"

Sound Sound::Instance;

void Sound::PlayMusic()
{
    BASS_Init(-1, 44100, 0, 0, 0);
    HSTREAM AudioChannel = BASS_StreamCreateFile(false, "../resources/Music.wav", 0, 0, 0);
    // Create a Audio Stream from a File.
    BASS_ChannelPlay(AudioChannel, true);
    BASS_ChannelIsActive(AudioChannel);

    // PlaySoundA("../resources/Music.wav", nullptr, SND_ASYNC | SND_NOSTOP);
}

void Sound::PlayPlayerShoot()
{
    PlaySound(L"../resources/PlayerShoot.wav", nullptr, SND_ASYNC);
}

void Sound::PlayPlayerDeath()
{
    PlaySound(L"../resources/PlayerDeath.wav", nullptr, SND_ASYNC);
}

void Sound::PlayEnemyDeath()
{
    PlaySound(L"../resources/EnemyDeath.wav", nullptr, SND_ASYNC);
}
