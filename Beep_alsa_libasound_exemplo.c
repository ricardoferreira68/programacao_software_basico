#include <alsa/asoundlib.h>
#include <math.h>

#define RATE 44100 // PCM rate [Hz]
#define FREQ 440 // Tone frequence [Hz]
#define DURATION 0.01 // Tone duration [s]

void info_format(snd_pcm_format_t format);

int main(void)
{
    snd_pcm_t *handle;
    unsigned char buffer[RATE * DURATION];
    for (int i = 0; i < sizeof(buffer); i++)
        buffer[i] = 0xFF * sin(2 * M_PI * FREQ * i / RATE);
    snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0 /* blocked mode */);
    snd_pcm_set_params(handle, SND_PCM_FORMAT_U8, SND_PCM_ACCESS_RW_INTERLEAVED, 1 /* channels */, RATE /* rate [Hz] */, 1 /* soft resample */, 500000 /* latency [us] */);
    snd_pcm_writei(handle, buffer, sizeof(buffer));
    snd_pcm_close(handle);
    return 0;
}
