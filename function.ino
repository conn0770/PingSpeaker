void playsong() {

  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)




  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = pgm_read_word_near(melody + thisNote + 1);  // calculates the duration of each note
    if (divider > 0) {      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }


    tone(buzzer, pgm_read_word_near(melody + thisNote ), noteDuration * 0.9); // we only play the note for 90% of the duration, leaving 10% as a pause

    delay(noteDuration);
    // Wait for the specief duration before playing the next note.

    noTone(buzzer);    // stop the waveform generation before the next note.
    Serial.print(cm);
    Serial.println("cm");


  }
}
