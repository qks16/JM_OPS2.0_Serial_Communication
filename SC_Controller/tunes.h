int NOTE_DUR = 60;

int speaker = 7;

void play(int note, int dur) {
  tone(speaker, note);
  delay(dur * NOTE_DUR);
  noTone(speaker);
  delay(dur * NOTE_DUR/3);
}

playgoodtone(){
  play(NOTE_C6, 2);
  play(NOTE_E6, 2);
  play(NOTE_F6, 2);
  play(NOTE_G6, 3);
}

playbadtone(){
  play(NOTE_F4, 2);
  play(NOTE_F3, 8);
}