#include "Header.h"

void SoundGame() {
	PlaySound(TEXT("Sound.wav"), NULL, SND_ASYNC);
}

void SoundBossDie() {
	PlaySound(TEXT("SoundBossDie.wav"), NULL, SND_ASYNC);
}
void SoundLoading() {
	PlaySound(TEXT("Loading.wav"), NULL, SND_ASYNC);
}
void SoundExplosion() {
	PlaySound(TEXT("Explosion.wav"), NULL, SND_ASYNC);
}
void SoundBackground() {
	PlaySound(TEXT("LegendaryAmadeus.wav"), NULL, SND_ASYNC);
}
void SoundGameOver() {
	PlaySound(TEXT("GameOver.wav"), NULL, SND_ASYNC);
}
void SoundGameWin() {
	PlaySound(TEXT("GameWin.wav"), NULL, SND_ASYNC);
}
void SoundCheering() {
	PlaySound(TEXT("Cheering.wav"), NULL, SND_ASYNC);
}
void SoundByeBye() {
	PlaySound(TEXT("ByeBye.wav"), NULL, SND_ASYNC);
}
void SoundRocket() {
	PlaySound(TEXT("SoundRocket.wav"), NULL, SND_ASYNC);
}
void EndSoundGame() {
	PlaySound(NULL, NULL, SND_FILENAME);
}